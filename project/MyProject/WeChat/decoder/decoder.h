#ifndef DECODER_H
#define DECODER_H

//解码
#include "libavcodec/avcodec.h"
//音视频编码器的库 。
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
//包含了所有的普通音视格式的解析器和产生器的库。
class decoder
{
public:
    decoder();
    sws_getContext();
public:
    AVFrame *fram;
};

#endif // DECODER_H
