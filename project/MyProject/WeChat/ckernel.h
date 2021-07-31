#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include <QCloseEvent>
#include<wechatdialog.h>
#include"qmytcpclient.h"
#include "ui_roomdialog.h"
#include"Packdef.h"
#include"logindialog.h"
#include"setuserdialog.h"
#include "chatdialog.h"
#include "roomdialog.h"
#include <QMap>
#include "video_read.h"
#include "screen_read.h"
#include "encoder.h"
#include "decoder.h"
class CKernel;
typedef void (CKernel::*PFUN)(char* buf, int nlen);


class CKernel : public QObject
{
    Q_OBJECT
public:
    static CKernel* GetInstance()
    {
        static CKernel kernel;
        return &kernel;
    }

    void DestroyInstance();
private:
    explicit CKernel(QObject *parent = 0);
    ~CKernel(){}
    CKernel(const CKernel & kernel ){}

    void setNetPackMap();
signals:

public slots:

private slots:
    void slot_quit();
    void slot_dealData(char *buf, int nlen);

    void slot_dealLoginRs(char *buf, int nlen);
    void slot_dealRegisterRs(char *buf, int nlen);
    void slot_dealFriendInfoRq(char *buf, int nlen);
    void slot_addFriendRq(char *buf, int nlen);
    void slot_addFriendRs(char *buf, int nlen);
    void slot_dealChatRq(char *buf, int nlen);
    void slot_dealChatRs(char *buf, int nlen);
    void slot_RegisterCommit(QString tel,QString password);
    void slot_offLineRs(char *buf, int nlen);
    void slot_offlineRq();
    void slot_LoginCommit(QString tel,QString password);
    void slot_systemSet();

    void slot_userSetCommit( int iconid , QString name , QString feeling );

    void initConfig();
    void slot_addFriend();

    void slot_createRoom();
    void slot_joinRoom(int);
    void slot_leaveRoom(int);


    void closeEvent(QCloseEvent *event);

    void slot_sendMessageRq(int,QString);
    void slot_UserItemClicked();


    void slot_createRoomRs(char *buf, int nlen);
    void slot_joinRoomRs(char *buf, int nlen);

    void slot_videoFormClicked(int);

    void slot_RoomMember(char *buf, int nlen);

    void slot_leaveRoomRs(char *buf, int nlen);

    void slot_sendVideoFrame(QImage&);
    void slot_refreshImage( int id  , QImage& img );
    void slot_VideoFrame(char *buf, int nlen);

    void slot_senfFile(int id, QString path);
    void slot_SendFileRs(char *buf, int nlen);//slot_SendFileRq
    void slot_SendFileRq(char *buf, int nlen);

    void slot_sendScreenFrame(QImage& img);
    void slot_fileAccept();
    void slot_fileReject();
private:
    WeChatDialog * m_weChat;
    LoginDialog *m_loginDialog;
    QMyTcpClient * m_tcpClient;
    SetUserDialog *m_setUserDialog;

    ChatDialog *m_chatDlog;
    // 用户自己的ID
    int m_id;
    QString m_serverIP;
    QMap< int , UserItem * > m_mapUserIDToUserItem;
    QMap< int , ChatDialog*> m_mapIDToChatdlg;
    QMap< int , VideoForm*> m_mapIDtoVideoForm;
    QMap< QString , FileInfo*> m_mapIDtoFileInfo;
    QMap< QString , FileItem*> m_mapIDtoFileItem;

    PFUN m_NetPackMap[ DEF_PACK_COUNT]; //协议映射数组

    RoomDialog *m_roomDlg;

    int m_roomid;

    Video_Read *m_pVideoRead;
    Screen_Read *m_pScreenRead;
    encoder *m_encoder;
};

#endif // CKERNEL_H
