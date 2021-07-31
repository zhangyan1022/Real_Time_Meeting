#ifndef ENCODER_H
#define ENCODER_H
//编码
extern "C"
{
#include "libavcodec/avcodec.h"
//音视频编码器的库 。
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
//包含了所有的普通音视格式的解析器和产生器的库。
#include <QObject>
#include"screen_read.h"
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>

}

class encoder : public QObject
{
    Q_OBJECT
public:
    explicit encoder(QObject *parent = 0);
public:
    bool RGB24_TO_YUV420(unsigned char *RgbBuf,int w,int h,unsigned char *yuvBuf);

    int simplest_rgb24_to_yuv420(char *url_in, int w, int h,int num,char *url_out);


    int simplest_rtp_parser(int port);

    int simplest_h264_parser(char *url);

signals:

public slots:
    int Temp();
    void slot_MyEnCoder(QImage *);
public:

    Screen_Read *m_sr;
    unsigned char * m_RgbBuf;
    unsigned char *m_yuvBuf;
    SOCKET *m_socket;
    char *m_rtpData;
};

#endif // ENCODER_H
