#ifndef FILEITEM_H
#define FILEITEM_H

#include <QWidget>
#include<QTimer>
#include<QTime>

namespace Ui {
class FileItem;
}

enum FileTransmitState
{
    waitRs,//等待客户确认
    emiting,//正在发送
    transmitFinish,//传输成功
    acceptOrReject,//同意或拒绝
    waitServer,//等待服务器传输
    continueTransmit//继续传输--断点续传 todo
};


//设计思路: 文件请求过来, 先写文件信息成员, 并保存在Fileinfo结构体中,
//同意接收, 发信号, 根据成员取得文件所有信息

class FileItem : public QWidget
{
    Q_OBJECT

public:
    explicit FileItem(QWidget *parent = 0);
    ~FileItem();
signals:
    void SIG_fileAccept();
    void SIG_fileReject();
public slots:
    void slot_setInfo(QString fileMD5 ,
                       QString fileName ,
                       QString filePath,
                       qint64 fileSize);

    static QString fileSizeToMB( qint64 byte );

    void slot_checkIsTransmit();

    void slot_setState( int state);

    void slot_setFileProcess(qint64 cur );

    void setFileTip();
private slots:
    void on_pb_recv_clicked();

    void on_pb_reject_clicked();

private:
    Ui::FileItem *ui;
public:
    QTimer * m_timer;
    QString m_fileMD5;
    QString m_fileName;
    QString m_filePath;
    int64_t m_fileSize;
    int64_t m_filePos;
    QTime m_startTime;
    QTime m_lastTime;
    bool m_isStart;
};

#endif // FILEITEM_H
