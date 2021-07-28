#include "encoder.h"
#include <QDebug>
#include <QString>

encoder::encoder(QObject *parent) : QObject(parent)
{

}

void encoder::enCoder()
{
    QImage *image = m_sr->GetImage();
    qDebug()<<"get image size ="<<image->size();
    SwsContext *swsCon;
    // 转yuv格式
    swsCon = sws_getContext(1920,1080,AV_PIX_FMT_RGB24,1600,900,
                            AV_PIX_FMT_YUV420P,1,NULL,NULL,NULL);



}
