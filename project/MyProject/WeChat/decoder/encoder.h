#ifndef ENCODER_H
#define ENCODER_H
//编码
#include "libavcodec/avcodec.h"
//音视频编码器的库 。
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
//包含了所有的普通音视格式的解析器和产生器的库。
#include <QObject>
#include"screen_read.h"


class encoder : public QObject
{
    Q_OBJECT
public:
    explicit encoder(QObject *parent = 0);

signals:

public slots:
public:
    void enCoder();
    Screen_Read *m_sr;

};

#endif // ENCODER_H
