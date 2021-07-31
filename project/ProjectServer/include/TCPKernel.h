#ifndef _TCPKERNEL_H
#define _TCPKERNEL_H



#include "TCPNet.h"
#include "Mysql.h"

class TcpKernel;
typedef void (TcpKernel::*PFUN)(int,char*,int nlen);

typedef struct
{
    PackType m_type;
    PFUN m_pfun;
} ProtocolMap;



class TcpKernel:public IKernel
{
public:
    int Open();
    void Close();
    void DealData(int,char*,int);

    //注册
    void RegisterRq(int,char*,int);
    //登录
    void LoginRq(int,char*,int);

    void SetUserInfoRq(int clientfd, char *szbuf, int nlen);

    void GetUserInfoFromMysql( UserInfo* user );

    void UserGetUserList( int id );

    void AddFriendRq(int clientfd , char*szbuf,int nlen);

    void AddFriendRs(int clientfd , char*szbuf,int nlen);

    void SendMsgToID(int id, char *szbuf, int nlen);

    void OfflineRq(int clientfd, char *szbuf, int nlen);

    void ChatRq(int clientfd, char *szbuf, int nlen);

    void CreateRoomRq(int clientfd, char *szbuf, int nlen);

    void JoinRoomRq(int clientfd, char *szbuf, int nlen);

    void LeaveRoomRq(int clientfd, char *szbuf, int nlen);

    void VideoFram(int clientfd, char *szbuf, int nlen);

    void SendFileRq(int clientfd, char *szbuf, int nlen);

    void FileBlockRq(int clientfd, char *szbuf, int nlen);

    void SendFileRs(int clientfd, char *szbuf, int nlen);

    static void *FileBlockSendThread(void *arg);

 private:
    CMysql * m_sql;
    TcpNet * m_tcp;
    map< int , UserInfo*> m_mapUserIDToUserInfo;

    map< int , list<UserInfo*> >  m_mapRoomIDToUserList;
    map< string , FileInfo* >  m_mapMD5ToFileInfo;

    static TcpKernel* m_pStaticThis;
};






////读取上传的视频流信息
//void UpLoadVideoInfoRq(int,char*);
//void UpLoadVideoStreamRq(int,char*);
//void GetVideoRq(int,char*);
//char* GetVideoPath(char*);
//void QuitRq(int,char*);
//void PraiseVideoRq(int,char*);
//void GetAuthorInfoRq(int,char*);
#endif
