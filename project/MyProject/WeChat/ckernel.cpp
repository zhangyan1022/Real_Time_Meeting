#include "ckernel.h"
#include"QDebug"
#include"QCryptographicHash"
#include "ui_chatdialog.h"
#include "ui_logindialog.h"
#include"useritem.h"
#include "notify.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QFileInfo>
#include <qsettings.h>
#include <QInputDialog>
#include <QBuffer>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QByteArray>
#include <QTime>
#include "fileitem.h"
#define MD5_KEY "1234"
static QByteArray GetMD5( QString val)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString tmp = QString( "%1_%2").arg(val).arg(MD5_KEY);

    hash.addData( tmp.toStdString().c_str() , strlen(tmp.toStdString().c_str()) );
    QByteArray  result = hash.result();
    return result.toHex();
}

#define NetPackMap( a )   m_NetPackMap[ (a) - DEF_PACK_BASE ]

CKernel::CKernel(QObject *parent) : QObject(parent),m_id(0),m_roomid(0)
{
    setNetPackMap();
    m_roomDlg = new RoomDialog;
    m_weChat = new WeChatDialog;
    connect( m_weChat , SIGNAL(SIG_close()) , this , SLOT(slot_quit()) );
    //m_weChat->show();
    connect( m_weChat , SIGNAL( SIG_systemSet() ) , this , SLOT( slot_systemSet() ) );
    // meun
    connect(m_weChat,SIGNAL(SIG_addFriend()),this,SLOT(slot_addFriend()));
    connect(m_weChat,SIGNAL(SIG_createRoom()),this,SLOT(slot_createRoom()));
    connect(m_weChat,SIGNAL(SIG_joinRoom(int)),this,SLOT(slot_joinRoom(int)));
    connect(m_roomDlg,SIGNAL(SIG_leaveRoom(int)),this,SLOT(slot_leaveRoom(int)));

    connect(m_weChat,SIGNAL(SIG_offLine()),this,SLOT(slot_offlineRq()));
    m_loginDialog = new LoginDialog;
    connect( m_loginDialog , SIGNAL(SIG_RegisterCommit(QString,QString))
             , this , SLOT(slot_RegisterCommit(QString,QString)) );
    connect( m_loginDialog , SIGNAL(SIG_LoginCommit(QString,QString))
             , this , SLOT(slot_LoginCommit(QString,QString)) );
    connect( m_loginDialog , SIGNAL(SIG_close()), this , SLOT(slot_quit()) );

    m_loginDialog->show();

    m_serverIP = "192.168.179.128";

    initConfig();
    m_tcpClient = new QMyTcpClient;
    // 设置端口号
    m_tcpClient->setIpAndPort((char *)m_serverIP.toStdString().c_str() , 8000 );
    connect( m_tcpClient , SIGNAL(SIG_ReadyData(char*,int))
             , this , SLOT( slot_dealData(char*,int))  );
    m_setUserDialog = new SetUserDialog;
    connect( m_setUserDialog , SIGNAL(SIG_setCommit(int,QString,QString))
             , this ,SLOT( slot_userSetCommit(int,QString,QString)) );



    //视频
    m_pVideoRead = new Video_Read;

    //打开视频
    connect( m_roomDlg , SIGNAL(SIG_openVideo()) , m_pVideoRead ,SLOT(slot_openVideo()) );
    // 关闭视频
    connect( m_roomDlg , SIGNAL(SIG_closeVideo())
            ,m_pVideoRead , SLOT( slot_closeVideo()) );
    //发送视频帧
    connect( m_pVideoRead , SIGNAL(SIG_sendVideoFrame(QImage&))
                              , this ,SLOT(slot_sendVideoFrame(QImage&)) );
    //m_chatDlog = new ChatDialog;
    // 桌面
    m_pScreenRead = new Screen_Read;

    connect(m_roomDlg , SIGNAL(SIG_openSound()) , m_pScreenRead , SLOT(slot_openScreen()));
    connect(m_roomDlg , SIGNAL(SIG_closeSound()) , m_pScreenRead , SLOT(slot_closeScreen()));
    connect( m_pScreenRead , SIGNAL(SIG_sendScreenFrame(QImage&))
                              , this ,SLOT(slot_sendVideoFrame(QImage&)));

}

void CKernel::slot_systemSet()
{
    m_setUserDialog->show();
}

void CKernel::setNetPackMap()
{
    //清空数组
    memset(m_NetPackMap , 0 , sizeof(m_NetPackMap));

    // m_NetPackMap[ DEF_PACK_LOGIN_RS - DEF_PACK_BASE ] = &CKernel::slot_dealLoginRs;
    NetPackMap( DEF_PACK_REGISTER_RS)  = &CKernel::slot_dealRegisterRs;
    NetPackMap( DEF_PACK_LOGIN_RS)     = &CKernel::slot_dealLoginRs;

    // 好友信息处理
    NetPackMap( DEF_PACK_FRIEND_INFO)  = &CKernel::slot_dealFriendInfoRq;

    // 添加好友回复和请求
    NetPackMap( DEF_PACK_ADD_FRIEND_RQ )  = &CKernel::slot_addFriendRq;
    NetPackMap( DEF_PACK_ADD_FRIEND_RS )  = &CKernel::slot_addFriendRs;

    // 下线
    //NetPackMap( DEF_PACK_ADD_FRIEND_RS )  = &CKernel::slot_dealChatRq;
    // 处理聊天请求
    NetPackMap( DEF_PACK_CHAT_RQ )  = &CKernel::slot_dealChatRq;

    // 下线请求 下线请求
    NetPackMap( DEF_PACK_OFFLINRE_RS )  = &CKernel::slot_offLineRs;

    // 加入房间 加入房间回复
    NetPackMap( DEF_PACK_CREATEROOM_RS )  = &CKernel::slot_createRoomRs;
    NetPackMap( DEF_PACK_JOINROOM_RS )  = &CKernel::slot_joinRoomRs;

    // 离开房间处理
    NetPackMap( DEF_PACK_LEAVEROOM_RS )  = &CKernel::slot_leaveRoomRs;

    // 房间内的好友列表
    NetPackMap( DEF_PACK_ROOM_MEMBER )  = &CKernel::slot_RoomMember;
    NetPackMap( DEF_PACK_VIDEO_FRAME )  = &CKernel::slot_VideoFrame;

    //文件
    NetPackMap( DEF_PACK_SET_UPLOAD_RS )  = &CKernel::slot_SendFileRs;
    NetPackMap( DEF_PACK_SET_UPLOAD_RQ )  = &CKernel::slot_SendFileRq;
}
void CKernel::slot_quit()
{
    DestroyInstance();
}

void CKernel::DestroyInstance()
{
    qDebug()<< __func__;

    if( m_loginDialog )
    {
        m_loginDialog->hide();
        delete m_loginDialog;
        m_loginDialog = NULL;
    }
    if( m_setUserDialog )
    {
        m_setUserDialog->hide();
        delete m_setUserDialog;
        m_setUserDialog = NULL;
    }
    if( m_weChat )
    {
        m_weChat->hide();
        delete m_weChat;
        m_weChat = NULL;
    }

    if( m_tcpClient )
    {
        delete m_tcpClient;
        m_tcpClient = NULL;
    }
    if(m_pVideoRead)
    {
        delete m_pVideoRead;
        m_pVideoRead = NULL;
    }
    if(m_pScreenRead)
    {
        delete m_pScreenRead;
        m_pScreenRead = NULL;
    }

}

// 处理包的信息
void CKernel::slot_dealData(char* buf,int nlen)
{
    //PackType int
    int type = *(int*)buf;
    if( type >= DEF_PACK_BASE && type <  DEF_PACK_BASE +DEF_PACK_COUNT)
    {
        PFUN fun = m_NetPackMap[ type - DEF_PACK_BASE ];
        if( fun )
        {
            (this->*fun)(buf, nlen);
        }
    }
    delete[] buf;
}

//登录回复处理
void CKernel::slot_dealLoginRs(char *buf, int nlen)
{
    //拆包
    STRU_LOGIN_RS * rs = (STRU_LOGIN_RS *)buf;
    switch(rs->m_lResult)//根据结果 显示
    {
        case userid_no_exist:
            QMessageBox::about( m_loginDialog , "提示","用户不存在, 登录失败" );
        break;
        case password_error:
            QMessageBox::about( m_loginDialog , "提示","密码错误" );
        break;
        case login_sucess:
            m_loginDialog->hide();
            m_weChat->show();
            m_id = rs->m_UserID;

        break;
    }
}

//注册回复处理
void CKernel::slot_dealRegisterRs(char *buf, int nlen)
{
    //拆包
    STRU_REGISTER_RS * rs = (STRU_REGISTER_RS *)buf;
    switch(rs->m_lResult)//根据结果 显示
    {
        case userid_is_exist:
            QMessageBox::about( m_loginDialog , "提示","用户已存在, 注册失败" );
        break;
    case register_sucess:
            QMessageBox::about( m_loginDialog , "提示","注册成功" );
            m_loginDialog->getUi()->tw_page->setCurrentIndex( 0 );
        break;
    }
}

//处理好友信息 -- 包括自己
void CKernel::slot_dealFriendInfoRq(char *buf, int nlen)
{
    //拆包
    STRU_FRIEND_INFO *rq = (STRU_FRIEND_INFO *)buf;

    // 判断是不是自己
    if( rq->m_userID == m_id)
    {
        // 修改自己的信息
        std::string strName = rq->m_szName;
        std::string strFeeling = rq->m_feeling;
        m_weChat->slot_setInfo( rq->m_userID
                    , QString::fromStdString(strName) ,rq->m_iconID
                                , QString::fromStdString(strFeeling) );
        return;
    }
    // 好友信息
    // 首先有没有好友  --> map查找 m_mapUserIDToUserItem
    if( m_mapUserIDToUserItem.find( rq->m_userID ) != m_mapUserIDToUserItem.end() )
    {
        //有好友--更新状态 信息  ...
        UserItem * item = m_mapUserIDToUserItem[rq->m_userID];
        if( item->m_state == 0 && rq->m_state ==1)
        {

            //上线提示
            Notify *notify = new Notify;
            notify->setMsg(rq->m_szName,rq->m_userID,QString("[%1]上线了").arg(rq->m_szName));
            // 点击查看可以蹦出来
            notify->showAsQQ();
        }
        item->slot_setInfo( rq->m_userID,rq->m_szName
                            , rq->m_state , rq->m_iconID , rq->m_feeling);

    }
    else
    {
        //没有这个  添加到控件  并且到map
        UserItem * item = new UserItem;
        item->slot_setInfo( rq->m_userID,rq->m_szName
                            , rq->m_state , rq->m_iconID , rq->m_feeling);


        connect(item , SIGNAL(SIG_itemClicked()) , this ,SLOT(slot_UserItemClicked()));
        //把用户的聊天窗口全创建出来
        //聊天窗口 -- connect
        m_mapUserIDToUserItem[rq->m_userID] = item;
        //ui显示
        m_weChat->slot_addUserItem( item );

        //创建聊天的窗口
        ChatDialog * chat = new ChatDialog;
        chat->SetInfo(rq->m_userID ,rq->m_szName);
        connect( chat , SIGNAL(SIG_SendChatMessage(int,QString)) ,
                this , SLOT( slot_sendMessageRq(int,QString) ) );
        connect( chat , SIGNAL(SIG_SendFile(int, QString ))
                 ,this ,SLOT(slot_senfFile(int, QString)));
        m_mapIDToChatdlg[ rq->m_userID ] = chat;
    }
}
// 添加好友请求
void CKernel::slot_addFriendRq(char *buf, int nlen)
{
    STRU_ADD_FRIEND_RQ *rq = (STRU_ADD_FRIEND_RQ *)buf;
    QString str = QString("[%1]请求你添加好友，是否同意？").arg(rq->m_szUserName);
    STRU_ADD_FRIEND_RS rs;
    rs.m_friendID = m_id;
    rs.m_userID = rq->m_userID;
    strcpy(rs.szAddFriendName,rq->m_szAddFriendName);
    // 如果点击同一
    if(QMessageBox::question(m_weChat,"添加好友",str) == QMessageBox::Yes)
    {
        rs.m_result = add_success;
    }
    else
    {
        rs.m_result = user_refused;
    }


    m_tcpClient->SendData((char*)&rs,sizeof(rs));
}
// 添加好友回复
void CKernel::slot_addFriendRs(char *buf, int nlen)
{
    // 拆包
    STRU_ADD_FRIEND_RS *rs = (STRU_ADD_FRIEND_RS *)buf;
    // 拒绝
    if(rs->m_result == user_refused)
    {
        QMessageBox::about(m_weChat,"提示",QString("用户[%1]拒绝添加").arg(rs->szAddFriendName));
        return ;
    }
    // 添加好友成功
    if(rs->m_result == add_success)
    {
        QMessageBox::about(m_weChat,"提示",QString("添加好友[%1]成功").arg(rs->szAddFriendName));
        return;
    }
    // 没有这个好友
    if(rs->m_result == userid_no_exist)
    {
        QMessageBox::about(m_weChat,"提示",QString("用户[%1]不存在").arg(rs->szAddFriendName));
        return;
    }
    // 不在线
    if(rs->m_result == user_is_offline)
    {
        QMessageBox::about(m_weChat,"提示",QString("用户[%1]不在线").arg(rs->szAddFriendName));
        return;
    }
}
// 处理聊天请求
void CKernel::slot_dealChatRq(char *buf, int nlen)
{
    qDebug()<<__func__;
    STRU_CHAT_RQ *rq = (STRU_CHAT_RQ *)buf;

    // 遍历找到谁发的
    if(m_mapIDToChatdlg.find(rq->m_userID)!=m_mapIDToChatdlg.end())
    {
        // 创建聊天窗口
        ChatDialog *chat = m_mapIDToChatdlg[rq->m_userID];
        // 教习粘贴过来
        std::string strContent = rq->m_ChatContent;

        chat->slot_recvChatMsg(QString::fromStdString(strContent));

        //提示
        Notify *nf = new Notify;
        nf->setMsg( QString("friend") , rq->m_friendID , QString("[ %1 ]\发来一条消息").arg(rq->m_friendID));
        nf->showAsQQ();
    }

}

// 处理聊天回复
void CKernel::slot_dealChatRs(char *buf, int nlen)
{
    qDebug()<<__func__;
    STRU_CHAT_RS *rs = (STRU_CHAT_RS *)buf;
    // 对方rq->m_friendID
    //如果离线
    if(rs->m_result == user_is_offline)
    {
        if(m_mapIDToChatdlg.find(rs->m_friendID)!=m_mapIDToChatdlg.end())
        {
            // 创建聊天窗口
            ChatDialog *chat = m_mapIDToChatdlg[rs->m_friendID];
            // 对方离线
            chat->slot_showOffline();
        }
    }
}

//发送注册请求
void CKernel::slot_RegisterCommit(QString tel, QString password)
{
    STRU_REGISTER_RQ rq;

    strcpy(  rq.m_szUser , tel.toStdString().c_str() );
    QByteArray array = GetMD5( password );
    memcpy( rq.m_szPassword , array.data() , array.size() );

    qDebug() << rq.m_szPassword ;
    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//发送登录请求
void CKernel::slot_LoginCommit(QString tel, QString password)
{
    STRU_LOGIN_RQ rq;

    strcpy(  rq.m_szUser , tel.toStdString().c_str() );
    QByteArray array = GetMD5( password );
    memcpy( rq.m_szPassword , array.data() , array.size() );

    qDebug() << rq.m_szPassword ;
    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}


//用户设置信息
void CKernel::slot_userSetCommit(int iconid, QString name, QString feeling)
{
    //提交请求包
    STRU_SET_USER_INFO rq;
    std::string strName = name.toStdString();
    std::string strFeeling = feeling.toStdString();

    rq.m_iconid = iconid ;
    rq.m_UserID = m_id;
    strcpy( rq.m_name , strName.c_str() );
    strcpy( rq.m_feeling , strFeeling.c_str() );

    m_tcpClient->SendData( (char*)&rq, sizeof(rq));
    //setdialog 隐藏
    m_setUserDialog->hide();
}

void CKernel::initConfig()
{
    // 路径
    QString path = QCoreApplication::applicationDirPath()+"/config.ini";
    // 查看是否有这个文件
    QFileInfo info(path);
    if(info.exists())
    {
        // 有这个文件
        QSettings setting(path,QSettings::IniFormat,NULL);
        setting.beginGroup("Net");
        // 泛型变量
        QVariant ip = setting.value("IP");
        setting.endGroup();
        QString strIP = ip.toString();
        qDebug() << strIP;
        if(!strIP.isEmpty())
        {
            m_serverIP = strIP;
        }
    }
    else
    {
        // 没有这个文件
        QSettings setting(path,QSettings::IniFormat,NULL);
        setting.beginGroup("Net");
        setting.setValue("IP",m_serverIP);
        setting.endGroup();
    }
}


//添加好友
void CKernel::slot_addFriend()
{
    QString strName = QInputDialog::getText(m_weChat,"添加好友","请输入好友的昵称");
    // 如果名字为空 或者名字过长
    if(strName.isEmpty() || strName.length()>20)
    {
        QMessageBox::about(m_weChat,"提示","输入昵称非法");
        return ;
    }
    // 名字等于自己的名字
    if(strName == m_weChat->m_name)
    {
        QMessageBox::about(m_weChat,"提示","不能添加自己为好友");
        return ;
    }

    // 如果已经是好友了
    for(auto ite = m_mapUserIDToUserItem.begin();ite != m_mapUserIDToUserItem.end();ite++)
    {
        UserItem *item = *ite;
        if(item->m_name == strName)
        {
            QMessageBox::about(m_weChat,"提示","你们已经是好友了");
            return ;
        }
    }
    // 成功
    // 发包
    STRU_ADD_FRIEND_RQ safRQ;
    safRQ.m_userID = m_id;
    std::string sName = m_weChat->m_name.toStdString();
    strcpy(safRQ.m_szUserName , sName.c_str());

    sName = strName.toStdString();
    strcpy(safRQ.m_szAddFriendName , sName.c_str());


    m_tcpClient->SendData((char *)&safRQ , sizeof(safRQ));
}
// 创建房间
void CKernel::slot_createRoom()
{
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
// 加入房间
void CKernel::slot_joinRoom(int roomid)
{
    STRU_JOINROOM_RQ rq;
    rq.m_RoomID = roomid;
    rq.m_UserID = m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
// 离开房间
void CKernel::slot_leaveRoom(int id)
{
    m_roomid = 0;
    // 将房间数设置为0
    m_weChat->m_roomId = m_roomid;
    STRU_LEAVEROOM_RQ rq;
    rq.m_RoomId = id;
    rq.m_nUserId = m_id;
    m_tcpClient->SendData((char*)&rq,sizeof(rq));
    // 回收显示 / 从控件中移除
    for(auto ite = m_mapIDtoVideoForm.begin();ite != m_mapIDtoVideoForm.end();ite++)
    {
        VideoForm *form = *ite;
        m_roomDlg->slot_removeVideoform(form);
        //m_mapIDtoVideoForm.erase(ite);
        delete form;
        form = NULL;
    }
    m_mapIDtoVideoForm.clear();
    // 关闭界面
    m_roomDlg->close();
    // 关闭视频 音频设备

}

// 下线 TODO:
void CKernel::slot_offLineRs(char *buf, int nlen)
{
    qDebug()<<__func__;
    STRU_OFFLINE_RS *rs = (STRU_OFFLINE_RS *)buf;
    if( m_mapUserIDToUserItem.find( rs->m_userID ) != m_mapUserIDToUserItem.end() )
    {

        UserItem* item =   m_mapUserIDToUserItem[rs->m_userID];
        item->slot_setInfo( item->m_id , item->m_name, 0 ,item->m_iconid);

        //发送离线通知
        Notify *nf = new Notify;
        nf->setMsg( item->m_name , item->m_id , QString("[ %1 ]下线了").arg(item->m_name));
        nf->showAsQQ();
    }
}

void CKernel::closeEvent(QCloseEvent *event)
{
    // 回收资源
    //this->slot_dealData();

    event->accept();
}

// 发送聊天请求 向id的好友发送聊天请求
void CKernel::slot_sendMessageRq(int id, QString content)
{
    STRU_CHAT_RQ rq;
    rq.m_userID = m_id;
    rq.m_friendID = id;
    std::string strContent = content.toStdString();
    strcpy_s(rq.m_ChatContent ,MAX_CONTENT_LEN , strContent.c_str());

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//双击用户响应
void CKernel::slot_UserItemClicked()
{
    qDebug()<<__func__;

    UserItem *item = (UserItem *) QObject::sender();

    //聊天窗口显示
    if(m_mapIDToChatdlg.find( item->m_id ) != m_mapIDToChatdlg.end()  )
    {
        ChatDialog *chat = m_mapIDToChatdlg[ item->m_id];
        //chat->hide();
        chat->show();
    }
}
// 创建房间回复 （接收到了这个包怎样操作）
void CKernel::slot_createRoomRs(char *buf, int nlen)
{
    STRU_CREATEROOM_RS *rs = (STRU_CREATEROOM_RS*)buf;
    if(rs->m_lResult == create_success)
    {
        m_roomid = rs->m_RoomId;
        // 设置ui
        m_roomDlg->slot_setInfo(rs->m_RoomId);
        // 显示
        m_roomDlg->show();

        // 添加对自己的video的显示
        if(m_mapIDtoVideoForm.find(m_id) == m_mapIDtoVideoForm.end())
        {
            VideoForm* form = new VideoForm;
            form->setInfo(m_id , m_weChat->m_name);
            connect(form, SIGNAL(SIG_itemClicked(int)),this,SLOT(slot_videoFormClicked(int)));

            m_roomDlg->slot_addVideoform(form);
            // 加入到链表中
            m_mapIDtoVideoForm[m_id] = form;
        }
        // 音频和视频的添加
    }
}

//加入房间回复
void CKernel::slot_joinRoomRs(char *buf, int nlen)
{
    STRU_JOINROOM_RS *rs = (STRU_JOINROOM_RS *)buf;
    if(rs->m_lResult == 0)
    {
        m_weChat->m_roomId = 0;
        QMessageBox::about(m_weChat,"提示","没有这个房间");
        // 将房间ID重新设置为0
        return;
    }
    m_roomid = rs->m_RoomID;
    // 设置ui
    m_roomDlg->slot_setInfo(rs->m_RoomID);

    // 显示
    m_roomDlg->show();
    // 添加对自己的video的显示
    if(m_mapIDtoVideoForm.find(m_id) == m_mapIDtoVideoForm.end())
    {
        VideoForm* form = new VideoForm;
        form->setInfo(m_id , m_weChat->m_name);
        connect(form, SIGNAL(SIG_itemClicked(int)),this,SLOT(slot_videoFormClicked(int)));
        m_roomDlg->slot_addVideoform(form);
        // 加入到链表中
        m_mapIDtoVideoForm[m_id] = form;
        //发送加入通知
        Notify *nf = new Notify;
        nf->setMsg( form->m_name , form->m_id , QString("[ %1 ]加入了房间").arg(form->m_name));
        nf->showAsQQ();
    }
    // 音频和视频的添加


}

// 右侧略缩图被点击
void CKernel::slot_videoFormClicked(int)
{
    VideoForm *form = (VideoForm*)QObject::sender();

    m_roomDlg->slot_setBigImageID(this->m_id , form->m_name);

}

// 房间内好友列表
void CKernel::slot_RoomMember(char *buf, int nlen)
{
    //拆包
    STRU_ROOM_MEMBER_RQ *rq = (STRU_ROOM_MEMBER_RQ *)buf;
    if(m_mapIDtoVideoForm.find(rq->m_UserID) == m_mapIDtoVideoForm.end())
    {
        VideoForm* form = new VideoForm;
        form->setInfo(rq->m_UserID , rq->m_szUser );
        connect( form , SIGNAL(SIG_itemClicked(int)) ,
                this , SLOT(slot_videoFormClicked(int)));
        //connect( item , &VideoItem::SIG_itemClicked , this , SLOT() );
        m_roomDlg->slot_addVideoform(form);
        m_mapIDtoVideoForm[ rq->m_UserID ] = form;
    }
}
// 离开房间
void CKernel::slot_leaveRoomRs(char *buf, int nlen)
{
    qDebug()<<__func__;
    STRU_LEAVEROOM_RS *rs = (STRU_LEAVEROOM_RS*)buf;

    // 查看map中有没有这个人
    auto ite = m_mapIDtoVideoForm.find(rs->m_UserID);
    if(ite!=m_mapIDtoVideoForm.end())
    {
        //有这个人
        VideoForm *form = *ite;
        m_roomDlg->slot_removeVideoform(form);
        // map中回收
        m_mapIDtoVideoForm.erase(ite);
        m_roomDlg->repaint();
        if(m_pScreenRead)
        {
            delete m_pScreenRead;
            m_pScreenRead = NULL;
        }
        if(m_pVideoRead)
        {
            delete m_pVideoRead;
            m_pVideoRead = NULL;
        }
        delete form;
        form = NULL;
    }
}

void CKernel::slot_sendVideoFrame(QImage & img)
{
    //刷新ui
    slot_refreshImage( this->m_id ,img );

    //将image图片转换成 缓冲区
    QByteArray ba;
    QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
    img.save( &qbuf , "JPEG" );  //将图片的数据写入 ba

    //发送到服务器
    //ba.size();
    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    char* buf = new char[ 12 + ba.size() ];
    char* tmp = buf;
    int type = DEF_PACK_VIDEO_FRAME;
    int userId = m_id ;
    int roomId = m_roomid ;

    *(int*)tmp = type;  //*(int*) 按照四个字节去写
    tmp += sizeof(int);
    *(int*)tmp = userId;  //*(int*) 按照四个字节去写
    tmp += sizeof(int);
    *(int*)tmp = roomId;  //*(int*) 按照四个字节去写
    tmp += sizeof(int);

    memcpy( tmp , ba.data() , ba.size() );

    m_tcpClient->SendData(buf , (12+ ba.size()) );
    delete[] buf;
}
//刷新界面图片显示
void CKernel::slot_refreshImage( int id  , QImage& img )
{
    //更新大图
    if( m_roomDlg->getUi()->widget->m_id == id )
        m_roomDlg->getUi()->widget->slot_setOneImage(img);

    //更新小图
    if( m_mapIDtoVideoForm.find( id ) != m_mapIDtoVideoForm.end() )
    {
        VideoForm* item = m_mapIDtoVideoForm[id];
        item->slot_setOneImage(img );
    }
}

void CKernel::slot_VideoFrame(char *buf, int nlen)
{
    // buf --> QImage
    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    char* tmp = buf;
    int type = *(int*)tmp;
    tmp += sizeof(int);
    int userid= *(int*)tmp;
    tmp += sizeof(int);
    int roomid= *(int*)tmp;
    tmp += sizeof(int);

    QByteArray ba( tmp , nlen -12 );
    QImage img;
    img.loadFromData( ba );

    this->slot_refreshImage( userid , img );
}
//发送文件
void CKernel::slot_senfFile(int id , QString path)
{
    qDebug()<<__func__;
    QFileInfo fileInfo(path);
    QByteArray resMD5 = GetMD5(fileInfo.fileName() + QTime::currentTime().toString("hhmmss"));

    // 取到文件的地址
    std::string strFileName = fileInfo.fileName().toStdString();

    STRU_UPLOAD_RQ rq;
    //给谁发的
    rq.m_friendId = id;
    //rq.m_nFileSize = fileInfo.size();
    //strcpy(rq.m_szFileMD5 , "1122334455");
    memcpy(rq.m_szFileMD5 , resMD5.data() , resMD5.size());
    strcpy_s(rq.m_szFileName , MAX_PATH ,strFileName.c_str());
    // 谁发送的
    rq.m_UserId = m_id;

    qDebug() << "the file name is :"  << rq.m_szFileName;
    qDebug() << "the send MD5 is :" << rq.m_szFileMD5;

    // 发送
    m_tcpClient->SendData((char *)&rq, sizeof(rq));

    // 将发送的文件放在map中
    std::string strMD5 = rq.m_szFileMD5;
    QString MD5 = QString::fromStdString(strMD5);
    FileInfo *pInfo = new FileInfo;
    pInfo->fileName = fileInfo.fileName();
    pInfo->filePath = path;
    pInfo->fileMD5 = MD5;
    pInfo->filePos = 0;
    pInfo->fileSize = rq.m_nFileSize;
    pInfo->pFile = NULL;
    // 装入map中
    m_mapIDtoFileInfo[MD5] = pInfo;
}

// 发送文件回复
void CKernel::slot_SendFileRs(char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_UPLOAD_RS *rs = (STRU_UPLOAD_RS *)buf;
    qDebug() << "the receive MD5 is :"<<rs->m_szFileMD5;
    if(rs->m_nResult == 0)
    {
        // 回复给对方 拒绝find
        if(m_mapIDToChatdlg.find(rs->m_friendId) != m_mapIDToChatdlg.end())
        {
            ChatDialog *chat = m_mapIDToChatdlg[rs->m_friendId];
            chat->slot_recvChatMsg("对方拒绝就收文件,去死吧！");
            return;
        }
    }

    // 重新解码
    std::string strMD5 = rs->m_szFileMD5;
    QString MD5 = QString::fromStdString(strMD5);
    if(m_mapIDtoFileInfo.find(MD5) != m_mapIDtoFileInfo.end())
    {
        // 有这个文件
        FileInfo *info = m_mapIDtoFileInfo[MD5];
        // 创建一个新的文件码,并且配置路径
        info->pFile = new QFile(info->filePath);
        if(info->pFile->open(QIODevice::ReadOnly))
        {
            // 开始接收文件
            while(1)
            {
                qDebug()<< "DEF_PACK_SET_FILEBLOCK_RQ";
                qDebug()<< "start receive the file...";
                STRU_FILEBLOCK_RQ rq;
                rq.m_nUserId = m_id;
                rq.m_friendId = rs->m_friendId;
                // 返回读取的字节数
                int res = info->pFile->read(rq.m_szFileContent , MAX_CONTENT_LEN);
                strcpy_s(rq.m_szFileMD5 , MAX_PATH , rs->m_szFileMD5);

                // 文件指针向后移动
                info->filePos += res;
                rq.m_nBlockLen = res;

                m_tcpClient->SendData((char*)&rq , sizeof(rq));

                // 如果走到的末尾
                if(info->filePos >= info->fileSize)
                {
                    // 关闭文件
                    info->pFile->close();
                    // 移除map中
                    m_mapIDtoFileInfo.remove(MD5);
                    delete info;
                    info = NULL;
                    QMessageBox::about(m_chatDlog,"提示", "发送完成");
                    break;
                }

            }
        }
    }
}

// 回复接收
void CKernel::slot_SendFileRq(char *buf, int nlen)
{
    STRU_UPLOAD_RQ * rq = (STRU_UPLOAD_RQ * ) buf;

    FileInfo* info = new FileInfo;
    info->fileMD5 = QString::fromStdString( rq->m_szFileMD5 );
    info->fileName = QString::fromStdString( rq->m_szFileName );
    info->filePos = 0;
    info->fileSize = rq->m_nFileSize;
    info->pFile = NULL;
    info->userID = rq->m_UserId;
    info->friendID = rq->m_friendId;

    m_mapIDtoFileInfo[ info->fileMD5  ] = info ;

    FileItem* item = new FileItem;
    item->slot_setInfo( info->fileMD5 , info->fileName , "" , info->fileSize);
    item->slot_setState( acceptOrReject );

    connect( item , SIGNAL(SIG_fileAccept()) , this , SLOT(slot_fileAccept() ) );
    connect( item , SIGNAL(SIG_fileReject()) , this , SLOT(slot_fileReject() ) );

    m_mapIDtoFileItem[item->m_fileMD5] = item;

    if( m_mapIDToChatdlg.find( rq->m_UserId ) != m_mapIDToChatdlg.end() )
    {
        ChatDialog * chat = m_mapIDToChatdlg[rq->m_UserId];

        chat->slot_addFileItem( item );
        chat->showNormal();
    }
}

void CKernel::slot_sendScreenFrame(QImage &img)
{

}

// 发送离线请求
void CKernel::slot_offlineRq()
{
    qDebug()<<__func__;
    if(QMessageBox::question( m_weChat, "提示", "是否退出程序") == QMessageBox::Yes)
    {
         // 发送离线请求
        STRU_OFFLINE_RQ rq;
        rq.m_userID = m_id;
        m_tcpClient->SendData( (char*)&rq , sizeof(rq));
    }
}


//同意文件传输
void CKernel::slot_fileAccept()
{
    FileItem * item = (FileItem*)QObject::sender();

    if( !item) return;

    if( m_mapIDtoFileInfo.find( item->m_fileMD5 ) != m_mapIDtoFileInfo.end() )
    {
        FileInfo* info = m_mapIDtoFileInfo[item->m_fileMD5 ];
        info->filePath = item->m_filePath;

        STRU_UPLOAD_RS rs;
        rs.m_friendId = info->friendID;
        rs.m_nResult = 1;
        strcpy( rs.m_szFileMD5 , info->fileMD5.toStdString().c_str() );
        rs.m_UserId = info->userID;

        info->pFile = new QFile( info->filePath );

        if( !info->pFile->open( QIODevice::WriteOnly ) )
        {
            rs.m_nResult = 0;
        }
        m_tcpClient->SendData( (char*)&rs, sizeof(rs) );
    }
}
//拒绝文件传输
void CKernel::slot_fileReject()
{
    FileItem * item = (FileItem*)QObject::sender();

    if( !item) return;

    if( m_mapIDtoFileInfo.find( item->m_fileMD5 ) != m_mapIDtoFileInfo.end() )
    {
        FileInfo* info = m_mapIDtoFileInfo[item->m_fileMD5 ];
        info->filePath = item->m_filePath;

        STRU_UPLOAD_RS rs;
        rs.m_friendId = info->friendID;
        rs.m_nResult = 0;
        strcpy( rs.m_szFileMD5 , info->fileMD5.toStdString().c_str() );
        rs.m_UserId = info->userID;

        m_tcpClient->SendData( (char*)&rs, sizeof(rs) );
    }
}














