#include <TCPKernel.h>
#include "packdef.h"
#include <stdio.h>
#include <sys/time.h>
using namespace std;

////注册
//#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
//#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
////登录
//#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
//#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)

static const ProtocolMap m_ProtocolMapEntries[] =
{
    {DEF_PACK_REGISTER_RQ , &TcpKernel::RegisterRq},
    {DEF_PACK_LOGIN_RQ , &TcpKernel::LoginRq},
    {DEF_PACK_SET_USER_INFO , &TcpKernel::SetUserInfoRq},
    {DEF_PACK_ADD_FRIEND_RQ , &TcpKernel::AddFriendRq},
    {DEF_PACK_ADD_FRIEND_RS , &TcpKernel::AddFriendRs},
    {DEF_PACK_OFFLINRE_RQ , &TcpKernel::OfflineRq},
    {DEF_PACK_CHAT_RQ , &TcpKernel::ChatRq},
    {DEF_PACK_CREATEROOM_RQ , &TcpKernel::CreateRoomRq},
    {DEF_PACK_JOINROOM_RQ , &TcpKernel::JoinRoomRq},
    {DEF_PACK_LEAVEROOM_RQ , &TcpKernel::LeaveRoomRq},
    {DEF_PACK_VIDEO_FRAME , &TcpKernel::VideoFram},
    {DEF_PACK_SET_UPLOAD_RQ , &TcpKernel::SendFileRq},
    {DEF_PACK_SET_UPLOAD_RS , &TcpKernel::SendFileRs},
    {DEF_PACK_SET_FILEBLOCK_RQ , &TcpKernel::FileBlockRq},
};
#define RootPath   "/home/colin/Video/"


TcpKernel* TcpKernel::m_pStaticThis = NULL;

int TcpKernel::Open()
{
    m_sql = new CMysql;
    m_tcp = new TcpNet(this);
    m_tcp->SetpThis(m_tcp);
    m_pStaticThis = this;
    pthread_mutex_init(&m_tcp->alock,NULL);
    pthread_mutex_init(&m_tcp->rlock,NULL);
    if(  !m_sql->ConnectMysql("localhost","root","zhangyan","wechat")  )
    {
        printf("Conncet Mysql Failed...\n");
        return FALSE;
    }
    else
    {
        printf("MySql Connect Success...\n");
    }
    if( !m_tcp->InitNetWork()  )
    {
        printf("InitNetWork Failed...\n");
        return FALSE;
    }
    else
    {
        printf("Init Net Success...\n");
    }

    return TRUE;
}


void TcpKernel::Close()
{
    m_sql->DisConnect();
    m_tcp->UnInitNetWork();
}


void TcpKernel::DealData(int clientfd,char *szbuf,int nlen)
{
    PackType *pType = (PackType*)szbuf;
    int i = 0;
    while(1)
    {
        if(*pType == m_ProtocolMapEntries[i].m_type)
        {
            PFUN fun= m_ProtocolMapEntries[i].m_pfun;
            (this->*fun)(clientfd,szbuf,nlen);
        }
        else if(m_ProtocolMapEntries[i].m_type == 0 &&
                m_ProtocolMapEntries[i].m_pfun == 0)
            return;
        ++i;
    }
    return;
}


//注册
void TcpKernel::RegisterRq(int clientfd,char* szbuf,int nlen)
{
    printf("clientfd:%d RegisterRq\n", clientfd);

    STRU_REGISTER_RQ * rq = (STRU_REGISTER_RQ *)szbuf;
    STRU_REGISTER_RS rs;
    // select the user
    char sqlStr[1024] = {0};
    sprintf(sqlStr,"select tel from t_user where tel = '%s';",rq->m_szUser);
    list<string> reList;
    if(!m_sql->SelectMysql(sqlStr,1,reList))
    {
        printf("SelectMysql is error : %s \n....",sqlStr);
        return;
    }
    if(reList.size() == 0)
    {
        // no user
        rs.m_lResult = register_sucess;
        // write
        sprintf(sqlStr,
  "insert into t_user(tel,password,name,icon,feeling)values('%s','%s','%s','%d','%s')",
                rq->m_szUser,
                rq->m_szPassword,
                rq->m_szUser,
                1,
                "11111");

        if(!m_sql->UpdataMysql(sqlStr))
        {
            printf("UpdataMysql is false...");
            return;
        }
    }
    else
    {
        rs.m_lResult = userid_is_exist;
    }
    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}
//登录
void TcpKernel::LoginRq(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d LoginRq\n", clientfd);

    STRU_LOGIN_RQ * rq = (STRU_LOGIN_RQ *)szbuf;
    STRU_LOGIN_RS rs;
    // select the user
    char sqlStr[1024] = "";
    sprintf(sqlStr,"select password, id from t_user where tel = '%s';",rq->m_szUser);
    list<string> reList;
    if(!m_sql->SelectMysql(sqlStr,2,reList))
    {
        printf("SelectMysql is error : %s \n....",sqlStr);
        return;
    }
    if(reList.size() > 0)
    {
        // users exist
        if(strcmp(reList.front().c_str() , rq->m_szPassword) ==0)
        {
            rs.m_lResult = login_sucess;
            reList.pop_front();
            int id = atoi(reList.front().c_str());
            rs.m_UserID = id;

            
            m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
            
            // id -- fd 映射 map 覆盖之后 先登录的强制下线
            UserInfo* user = NULL;
            if( m_mapUserIDToUserInfo.find( id ) != m_mapUserIDToUserInfo.end() )
            {
                //之前有
                user = m_mapUserIDToUserInfo[id];
                if( user->m_fd != clientfd )
                {
                    //强制下线

                }
            }
            else
            {
                user = new UserInfo;
                m_mapUserIDToUserInfo[ id ] = user;
            }
            user->m_id = id;
            user->m_fd = clientfd;
            user->m_state = 1;

            // 从数据库获取用户信息
            GetUserInfoFromMysql( user );

            // 自己的信息 好友列表
            UserGetUserList( user->m_id );

            return;
        }
        else
        {

            rs.m_lResult = password_error;
        }
    }
    else
    {
        // no users
        rs.m_lResult = userid_no_exist;
    }
    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}

// 查表给user赋值
void TcpKernel::GetUserInfoFromMysql(UserInfo *user)
{
    if( !user ) return;
    if( user->m_id == 0 ) return;

    //查sql
    char sql[1024] = "";
    sprintf( sql , "select name , icon , feeling from t_user where id = %d;", user->m_id);
    list<string> res;
    if( !m_sql->SelectMysql(sql , 3, res ))
    {
        printf( "SelectMysql error:%s\n",sql);
        return;
    }
    if( res.size() == 3)
    {
       strcpy( user->m_userName , res.front().c_str());
       res.pop_front();
       user->m_iconID = atoi(res.front().c_str() );
       res.pop_front();
       strcpy( user->m_feeling , res.front().c_str());
       res.pop_front();
    }
}

//设置用户信息
void TcpKernel::SetUserInfoRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d SetUserInfoRq\n", clientfd);
    //拆包
    STRU_SET_USER_INFO * rq = (STRU_SET_USER_INFO *)szbuf;
    // 看map 取出来 更新  更新mysql
    if(m_mapUserIDToUserInfo.find(rq->m_UserID) == m_mapUserIDToUserInfo.end() ) return;
     UserInfo * user = m_mapUserIDToUserInfo[rq->m_UserID];
     strcpy( user->m_userName , rq->m_name );
     user->m_iconID = rq->m_iconid ;
     strcpy( user->m_feeling , rq->m_feeling );

     //更新mysql
     char sql[1024] = "";
     sprintf(sql , "update t_user set name = '%s' , icon = %d , feeling = '%s' where id = %d;"
             , rq->m_name , rq->m_iconid , rq->m_feeling , rq->m_UserID );
     m_sql->UpdataMysql( sql );

    // 获取好友列表函数 同步状态
    UserGetUserList( rq->m_UserID );
}

//身份为id的用户 获取自己的信息  获取所有好友的信息  在线的好友获取这个人的信息
void TcpKernel::UserGetUserList(int id)
{
    //没找到 这个人不在线
    if( m_mapUserIDToUserInfo.find(id) == m_mapUserIDToUserInfo.end() ) return;

    UserInfo * loginer = m_mapUserIDToUserInfo[id];

    //获取自己的信息
    STRU_FRIEND_INFO loginrq;
    loginrq.m_state = 1;
    loginrq.m_iconID = loginer->m_iconID;
    strcpy( loginrq.m_szName , loginer->m_userName );
    strcpy( loginrq.m_feeling , loginer->m_feeling);
    loginrq.m_userID = loginer->m_id;

    m_tcp->SendData( loginer->m_fd , (char*)&loginrq , sizeof(loginrq ));

    //获取所有好友的信息  在线的好友获取这个人的信息
    // idA  idB   2  3    3  2

    // 查mysql 获取好友id
    char sql[1024] = "";
    sprintf( sql , "select idA from t_friend where idB = %d;" , id); // 查登录人的所有好友id
    list<string> res;
    if( !m_sql->SelectMysql(sql , 1, res ))
    {
        printf("SelectMysql error:%s\n", sql);
        return;
    }

    // 遍历链表 拿到好友每个人id
    while( res.size() > 0 )
    {
        int friendid = atoi(res.front().c_str());
        res.pop_front();

       // 好友的信息 的包的封装  获取好友的信息( name ...)  ( 在线 userInfo  不在线mysql 获取)
        STRU_FRIEND_INFO friendrq;
        friendrq.m_userID = friendid;
    //        friendrq.m_state;
    //        friendrq.m_iconID;
    //        friendrq.m_szName;
    //        friendrq.m_feeling;

        //在不在先
        if( m_mapUserIDToUserInfo.find(friendid ) != m_mapUserIDToUserInfo.end() )
        {
            // 在线
            // 在线的好友 -- 会发送该登录人的信息 给在线的好友
            friendrq.m_state = 1;
            UserInfo * friender = m_mapUserIDToUserInfo[friendid];
            friendrq.m_iconID = friender->m_iconID;
            strcpy( friendrq.m_szName , friender->m_userName) ;
            strcpy(friendrq.m_feeling , friender->m_feeling );
            //会发送该登录人的信息 给在线的好友 -- 上线提示
            m_tcp->SendData( friender->m_fd , (char*)&loginrq , sizeof(loginrq) );
        }
        else
        {
            //不在线
            friendrq.m_state = 0;

            UserInfo friender;
            friender.m_id = friendid;

            GetUserInfoFromMysql( &friender ); //完成 name ... 赋值

            friendrq.m_iconID = friender.m_iconID;
            strcpy( friendrq.m_szName , friender.m_userName) ;
            strcpy(friendrq.m_feeling , friender.m_feeling );
        }
        // 所有好友的信息发送给登录的人
        m_tcp->SendData( loginer->m_fd , (char*)&friendrq , sizeof(friendrq) );
    }
}
// add friend rq
void TcpKernel::AddFriendRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d AddFriendRq\n", clientfd);
    //拆包
    STRU_ADD_FRIEND_RQ * rq = (STRU_ADD_FRIEND_RQ *)szbuf;
    // 根据name  找id
    char sql[1024]="";
    sprintf(sql , "select id from t_user where name = '%s';", rq->m_szAddFriendName );
    list<string> res;
    if( !m_sql->SelectMysql(sql,1,res ))
    {
        printf("SelectMysql error:%s\n", sql);
        return;
    }
    STRU_ADD_FRIEND_RS rs;
    rs.m_friendID = 0;
    rs.m_userID = rq->m_userID;
    //strcpy(rs.szAddFriendName,rq->m_szAddFriendName);
    strcpy( rs.szAddFriendName ,rq->m_szAddFriendName );
    // 看是否在线 和存在   在线  转发  不在线 返回结果  不存在返回结果
    if( res.size() > 0 )
    {
        int id = atoi( res.front().c_str());

        if( m_mapUserIDToUserInfo.find(id) != m_mapUserIDToUserInfo.end() )
        {
             //在线  转发
             UserInfo* user = m_mapUserIDToUserInfo[id];
             m_tcp->SendData( user->m_fd , szbuf , nlen );
             return;
        }
        else
        {
            //不在线 返回结果
            rs.m_result = user_is_offline;
        }
    }
    else
    {
        //不存在返回结果
        rs.m_result = userid_no_exist;
    }
    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );

}
// add friend rs
void TcpKernel::AddFriendRs(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d AddFriendRs\n", clientfd);

        //拆包
        STRU_ADD_FRIEND_RS * rs = (STRU_ADD_FRIEND_RS *)szbuf;
        //如果同意 写数据库  获取好友列表
        if( rs->m_result == add_success )
        {
            char sql[1024] = "";
            //A B   ,  B A
            sprintf( sql , "insert into t_friend values ( %d , %d );",rs->m_userID , rs->m_friendID);
            m_sql->UpdataMysql( sql );


            sprintf( sql , "insert into t_friend values ( %d , %d );", rs->m_friendID ,rs->m_userID );
            m_sql->UpdataMysql( sql );

            //获取好友列表
            UserGetUserList( rs->m_friendID );
        }
        //转发
        SendMsgToID( rs->m_userID ,  szbuf,  nlen);
}


// zhuan fa
void TcpKernel::SendMsgToID(int id, char *szbuf, int nlen)
{
    printf("clientfd:%d SendMsgToID", id);
    //
    if( m_mapUserIDToUserInfo.find(id) != m_mapUserIDToUserInfo.end() )
    {
        UserInfo *info = m_mapUserIDToUserInfo[id];

        m_tcp->SendData( info->m_fd , szbuf, nlen);
    }
}

// offline rq
void TcpKernel::OfflineRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d OfflineRq\n", clientfd);
    STRU_OFFLINE_RQ *rq =(STRU_OFFLINE_RQ *) szbuf;
    char buf[1024] = "";
    sprintf(buf,"select idB from t_friend where idA = '%d';",rq->m_userID);
    list<string> lst;
    m_sql->SelectMysql(buf,1,lst);
    //jie chu ying she guan xi
    if(m_mapUserIDToUserInfo.find(rq->m_userID)!=m_mapUserIDToUserInfo.end())
    {
        m_mapUserIDToUserInfo.erase(rq->m_userID);
    }
    //

    // send offlinerq for others
    while(lst.size() > 0)
    {
        int id = atoi(lst.front().c_str());
        lst.pop_front();
        STRU_OFFLINE_RS rs;
        rs.m_userID = rq->m_userID;

        this->SendMsgToID(id,(char*)&rs,sizeof(rs));
    }
}

// liao tian qing qiu
void TcpKernel::ChatRq(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d ChatRq\n", clientfd);
     STRU_CHAT_RQ *rq = (STRU_CHAT_RQ *)szbuf;

     // online
     if(m_mapUserIDToUserInfo.find(rq->m_friendID)!=m_mapUserIDToUserInfo.end())
     {
         // zhuan fa
         SendMsgToID(rq->m_friendID,szbuf,nlen);
     }
     else
     {
         // offline
         STRU_CHAT_RS rs;
         rs.m_result = user_is_offline;
         rs.m_friendID = rq->m_friendID;
         rs.m_userID = rq->m_userID;

         //SendMsgToID(rq->m_friendID,szbuf,nlen);
         m_tcp->SendData(clientfd , (char*)&rs , sizeof(rs));
     }
}
// create room
void TcpKernel::CreateRoomRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d CreateRoomRq\n", clientfd);
    STRU_CREATEROOM_RQ *rq  =(STRU_CREATEROOM_RQ *)szbuf;
    // no found
    if(m_mapUserIDToUserInfo.find(rq->m_UserID)==m_mapUserIDToUserInfo.end())
    {
        return;
    }
    UserInfo* info = m_mapUserIDToUserInfo[rq->m_UserID];



    // 随机roomid 判定是否重复
    int roomid;
    do
    {
        roomid = rand()%100000000;
    }while(roomid == 0|| m_mapRoomIDToUserList.find(roomid) != m_mapRoomIDToUserList.end());
    //add in map
    info->m_roomID = roomid;
    list<UserInfo*> lst ;
    lst.push_back(info);

    m_mapRoomIDToUserList[roomid] = lst;
    //recv
    STRU_CREATEROOM_RS rs;
    rs.m_RoomId = roomid;
    rs.m_lResult = create_success;

    m_tcp->SendData(clientfd , (char*)&rs,sizeof(rs));

}
// join room
void TcpKernel::JoinRoomRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d JoinRoomRq\n", clientfd);
    // decode
    STRU_JOINROOM_RQ *rq = (STRU_JOINROOM_RQ *)szbuf;
    STRU_JOINROOM_RS rs;
    // no the user
    if(m_mapUserIDToUserInfo.find(rq->m_UserID) == m_mapUserIDToUserInfo.end())
    {
        printf("no this VIP...\n");
        rs.m_RoomID = 0;
        rs.m_lResult = 0;
        m_tcp->SendData(clientfd,(char *)&rs,sizeof(rs));
        return;
    }

    //no the room
    if(m_mapRoomIDToUserList.find(rq->m_RoomID) == m_mapRoomIDToUserList.end())
    {
        printf("no this room...\n");
        rs.m_RoomID = rq->m_RoomID;
        rs.m_lResult = 0;
        m_tcp->SendData(clientfd,(char *)&rs,sizeof(rs));
        return;
    }

    //
    UserInfo *joiner = m_mapUserIDToUserInfo[rq->m_UserID];
    // select list
    list<UserInfo *> lst = m_mapRoomIDToUserList[rq->m_RoomID];


    STRU_ROOM_MEMBER_RQ joinrq;
    joinrq.m_UserID = rq->m_UserID;
    strcpy(joinrq.m_szUser , joiner->m_userName);
    //
    rs.m_RoomID = rq->m_RoomID;
    rs.m_lResult = 1;
    m_tcp->SendData(clientfd,(char *)&rs,sizeof(rs));
    //add member
    for(list<UserInfo*>::iterator ite = lst.begin() ; ite!=lst.end() ; ++ite)
    {
        UserInfo *inner = *ite;
        STRU_ROOM_MEMBER_RQ innerrq;
        innerrq.m_UserID = inner->m_id;     //
        strcpy(innerrq.m_szUser , inner->m_userName);

        // join to send all member
        m_tcp->SendData(inner->m_fd , (char*)&joinrq , sizeof(joinrq));

        // member to joiner
        m_tcp->SendData(joiner->m_fd , (char*)&innerrq , sizeof(innerrq));
    }
    // add to list   updata map
    lst.push_back(joiner);
    m_mapRoomIDToUserList[rq->m_RoomID] = lst;
    //m_tcp->SendData(clientfd,(char *)&rs,sizeof(rs));
}

void TcpKernel::LeaveRoomRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d LeaveRoomRq\n", clientfd);
    STRU_LEAVEROOM_RQ *rq = ( STRU_LEAVEROOM_RQ *)szbuf;
    //rq->m_RoomId;
    //rq->m_nUserId;
    if(m_mapRoomIDToUserList.find(rq->m_RoomId) == m_mapRoomIDToUserList.end())
    {
        return;
    }
    if(m_mapUserIDToUserInfo.find(rq->m_nUserId) == m_mapUserIDToUserInfo.end())
    {
        return;
    }
    STRU_LEAVEROOM_RS rs;
    // get user info
    UserInfo *leaverInfo = m_mapUserIDToUserInfo[rq->m_nUserId];
    // get the user list
    list<UserInfo*> lst = m_mapRoomIDToUserList[rq->m_RoomId];
    rs.m_UserID = leaverInfo->m_id;
    strcpy(rs.szUserName,leaverInfo->m_userName);
    for(list<UserInfo*>::iterator ite = lst.begin();ite != lst.end();)
    {
        UserInfo *innerInfo = *ite;
        if(innerInfo->m_id != leaverInfo->m_id)
        {
            // leaverInfo = innerInfo
            m_tcp->SendData(innerInfo->m_fd,(char*)&rs,sizeof(rs));
            ++ite;
        }
        else
        {
            ite = lst.erase(ite);
        }
    }
    m_mapRoomIDToUserList[rq->m_RoomId] = lst;
    if(lst.size() == 0)
    {
        m_mapRoomIDToUserList.erase(rq->m_RoomId);
    }
}
// deal videofram
void TcpKernel::VideoFram(int clientfd, char *szbuf, int nlen)
{
    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    printf("clientfd:%d VideoFram\n", clientfd);

    //
    char *tmp = szbuf;
    int type = *(int*)tmp;
    tmp += sizeof(int);
    int userId = *(int*)tmp;
    tmp += sizeof(int);
    int roomId = *(int*)tmp;
    tmp += sizeof(int);
    //find the room
    if(m_mapRoomIDToUserList.find(roomId) == m_mapRoomIDToUserList.end())
    {
        return;
    }
    list<UserInfo*> lst = m_mapRoomIDToUserList[roomId];
    for(list<UserInfo*>::iterator ite = lst.begin();ite!=lst.end();++ite)
    {
        UserInfo *user = *ite;
        if(user->m_id != userId)
        {
            SendMsgToID(user->m_id , szbuf , nlen);
        }
    }
}

//sendfile
void TcpKernel::SendFileRq(int clientfd, char *szbuf, int nlen)
{
        printf("clientfd:%d UploadRq\n", clientfd);
    //m_friendId  m_nFileSize
        STRU_UPLOAD_RQ *rq = (STRU_UPLOAD_RQ *)szbuf;
        cout << "the receive MD5 = " << rq->m_szFileMD5 << endl;
        cout << "the receive m_szFileName = " << rq->m_szFileName << endl;
        cout << "the receive m_UserId = " << rq->m_UserId << endl;
        cout << "the receive m_friendId = " << rq->m_friendId << endl;
        //cout << "the receive m_nFileSize = " << rq->m_nFileSize << endl;
        if( m_mapUserIDToUserInfo.find( rq->m_friendId) != m_mapUserIDToUserInfo.end() )
        {
            this->SendMsgToID( rq->m_friendId , szbuf , nlen );

            FileInfo * info = new FileInfo;
            strcpy( info->fileMD5 , rq->m_szFileMD5 );
            strcpy( info->fileName , rq->m_szFileName );
            sprintf( info->filePath , "/home/colin/tempForFile/%s", rq->m_szFileName );
            info->filePos = 0;
            info->fileSize = rq->m_nFileSize;
            info->pFile = NULL;

            info->userID = rq->m_UserId;
            info->friendID = rq->m_friendId;

            string strMD5 = info->fileMD5;
            m_mapMD5ToFileInfo[ strMD5 ] = info;
        }
        else
        {
            STRU_UPLOAD_RS rs ;
            rs.m_friendId = rq->m_friendId;
            rs.m_nResult = 0;
            strcpy( rs.m_szFileMD5 , rq->m_szFileMD5 );
            rs.m_UserId = rq->m_UserId;
            m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs));
        }
}
// sendfile step;
void *TcpKernel::FileBlockSendThread(void *arg)
{
    printf("FileBlockSendThread\n");

    FileInfo * pInfo = (FileInfo *)arg;


    pInfo->pFile = fopen(pInfo->filePath , "r");
    pInfo->filePos = 0;

    if( pInfo->pFile )
    {
        while(1)
        {
            STRU_FILEBLOCK_RQ rq;
            rq.m_friendId = pInfo->friendID;
            rq.m_nUserId = pInfo->userID;
            strcpy( rq.m_szFileMD5 , pInfo->fileMD5 );
            rq.m_nBlockLen = fread ( rq.m_szFileContent , 1, MAX_CONTENT_LEN, pInfo->pFile);

            pInfo->filePos += rq.m_nBlockLen;

            TcpKernel::m_pStaticThis->SendMsgToID( pInfo->friendID , (char*)&rq , sizeof(rq) );

            if( pInfo->filePos >= pInfo->fileSize )
            {
                break;
            }
        }
        fclose(pInfo->pFile);
    }
    delete pInfo;
}

// file
void TcpKernel::FileBlockRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d FileBlockRq\n", clientfd);

    STRU_FILEBLOCK_RQ *rq = (STRU_FILEBLOCK_RQ *)szbuf;
    string strMD5 = rq->m_szFileMD5;
    if(m_mapMD5ToFileInfo.find(strMD5) != m_mapMD5ToFileInfo.end())
    {
        FileInfo *info = m_mapMD5ToFileInfo[strMD5];
        int res = fwrite(rq->m_szFileContent , 1 , rq->m_nBlockLen , info->pFile);
        info->filePos += res;
        if(info->filePos >= info->fileSize)
        {
            fclose(info->pFile);
            info->pFile = NULL;
            // create thread
            pthread_t tid;
            int err = 0;
            //err = pthread_create(&tid,NULL, FileBlockSendThread ,(void*)info);
            if((err = pthread_create(&tid,NULL, FileBlockSendThread ,(void*)info)) > 0)
            {
                printf("create FileBlockSendThread error:%s\n",strerror(err));
                return ;
            }
        }
    }
}

void TcpKernel::SendFileRs(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d UploadRs\n", clientfd);
    STRU_UPLOAD_RS * rs = (STRU_UPLOAD_RS* )szbuf;

       string strMD5 =  rs->m_szFileMD5;
       if( m_mapMD5ToFileInfo.find( strMD5 ) != m_mapMD5ToFileInfo.end() )
       {
           if( rs->m_nResult == 0 )
           { 
               m_mapMD5ToFileInfo.erase( strMD5 );
           }
           else
           {
               FileInfo* info = m_mapMD5ToFileInfo[ strMD5 ];
               info->pFile = fopen( info->filePath ,"w");
           }
       }

       SendMsgToID(rs->m_UserId , szbuf, nlen);
}























