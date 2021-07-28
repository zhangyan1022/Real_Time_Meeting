#ifndef FRAME_H
#define FRAME_H

#include <QThread>
#include <QObject>
// 编码线程  读取桌面视频的数据
class frame:public QThread
{
    Q_OBJECT
public:
    explicit frame(QObject *parent = 0);
public:
    frame();
public:
    void run();
};




#endif // FRAME_H
