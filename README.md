# Real_Time_Meeting*项目功能介绍

> >项目功能：
> >登录注册功能 ，添加/删除好友功能，自定义头像功能，文件、消息发送功能，好友上线/下线提醒功能，会议房间的创
> >建/加入/退出功能，检测异地登录功能，实时会议功能； 

*项目所用技术

> > 应用技术：
> > 客户端：Qt，TCP/IP，MD5加密算法，ffmpeg编码与解码，多线程，单例模式，select模型，中介者模式；
> > 服务端：线程池，epoll模型，TCP/IP，mysql数据库，单例模式，心跳机制，中介者模式。  

*文件说明

> > MyProject/wechat为客户端
> >
> > ProjectServer为服务端

*使用方式

> > 1、客户端支持在windows平台下使用，使用时需要将.user文件删除，在QT GW项目下使用；
> >
> > 2、在编译之后，需要使用Qt 5.14.2 (MinGW 7.3.0 64-bit)进行库封装。点击编译完成的项目文件.exe格式文件即可运行；
> >
> > 3、服务端在linux系统下进行，需要准备的工具：Mysql数据库、Qt编译器、32linux系统；

*主要函数介绍

> > ```c++
> > //发送登录请求
> > void CKernel::slot_LoginCommit(QString tel, QString password);
> > //登录回复处理
> > void CKernel::slot_dealLoginRs(char *buf, int nlen);
> > //发送注册请求
> > void CKernel::slot_RegisterCommit(QString tel, QString password);
> > //注册回复处理
> > void CKernel::slot_dealRegisterRs(char *buf, int nlen);
> > //添加好友
> > void CKernel::slot_addFriend();
> > // 添加好友请求
> > void CKernel::slot_addFriendRq(char *buf, int nlen);
> > // 添加好友回复
> > void CKernel::slot_addFriendRs(char *buf, int nlen);
> > // 处理聊天请求
> > void CKernel::slot_dealChatRq(char *buf, int nlen);
> > // 处理聊天回复
> > void CKernel::slot_dealChatRs(char *buf, int nlen);
> > //用户设置信息
> > void CKernel::slot_userSetCommit(int iconid, QString name, QString feeling);
> > //处理好友信息 -- 包括自己
> > void CKernel::slot_dealFriendInfoRq(char *buf, int nlen);
> > // 创建房间请求
> > void CKernel::slot_createRoom();
> > // 创建房间回复 （接收到了这个包怎样操作）
> > void CKernel::slot_createRoomRs(char *buf, int nlen);
> > // 房间内好友列表
> > void CKernel::slot_RoomMember(char *buf, int nlen);
> > // 加入房间请求
> > void CKernel::slot_joinRoom(int roomid);
> > // 加入房间回复
> > void CKernel::slot_joinRoomRs(char *buf, int nlen);
> > // 离开房间请求
> > void CKernel::slot_leaveRoom(int id);
> > // 离开房间回复
> > void CKernel::slot_leaveRoomRs(char *buf, int nlen);
> > // 发送文件请求
> > void CKernel::slot_senfFile(int id , QString path);
> > // 发送文件回复
> > void CKernel::slot_SendFileRs(char *buf, int nlen);
> > // 文件回复接收
> > void CKernel::slot_SendFileRq(char *buf, int nlen);
> > // 发送视频流
> > void CKernel::slot_sendVideoFrame(QImage & img);
> > // 接收视频流
> > void CKernel::slot_VideoFrame(char *buf, int nlen);
> > ```

*技术交流

> > 由于只对主线程进行了epoll，子线程没有eventloop方式所以支持的在线用户不是很多。在服务器端想要模仿陈硕大神的muduo，希望下载者有思路可以和作者交流。邮箱zy13252523396@163.com

