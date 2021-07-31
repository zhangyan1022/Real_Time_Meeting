#include "encoder.h"
#include <QDebug>
#include <QString>

#define __STDC_CONSTANT_MACROS

encoder::encoder(QObject *parent) : QObject(parent)
{
    connect(m_sr , SIGNAL(SIG_sendScreenFrame(QImage&)) , this , SLOT(slot_MyEnCoder(QImage *img)));
}
/*
int encoder::Temp()
{
    QByteArray ba;
    char* buf = new char[ba.size() ];
    char* tmp = buf;
    while(m_sr->GetImage())
    {
        QImage *img = m_sr->GetImage();
        // 接收屏幕图片
        QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
        img->save( &qbuf , "JPEG" );  //将图片的数据写入
        memcpy( tmp , ba.data() , ba.size() );
    }
    //char* tmp = buf;
    //*(int*)tmp = type;  //*(int*) 按照四个字节去写
    //tmp += sizeof(int);
    //*(int*)tmp = userId;  //*(int*) 按照四个字节去写
    //tmp += sizeof(int);
    //*(int*)tmp = roomId;  //*(int*) 按照四个字节去写
    //tmp += sizeof(int);
    //memcpy( tmp , ba.data() , ba.size() );


    AVFormatContext *pFormatCtx; //格式上下文结构体
    int i, videoindex;
    AVCodecContext *pCodecCtx; //codec上下文
    AVCodec *pCodec;    //codec
    AVFrame *pFrame;    //Frame结构体
    AVFrame *pFrameYUV; //Frame结构体

    uint8_t *out_buffer;
    AVPacket *packet;   //packet结构体
    int y_size,y_size_align;
    //====================================================================================//
    int ret, got_picture;
    unsigned int frame_num = 0;

    struct SwsContext *img_convert_ctx; //图像格式转化上下文

    //====================================================================================//
    //char filepath[]="MP4_test.es";             //input

    FILE *fp_frame = fopen("output.yuv","wb+");  //output
    FILE *fp_yuv=fopen("output_sws.yuv","wb+");
    //====================================================================================//
    av_register_all();                         //ffmpeg flow 0,注册codec
    //avformat_network_init();                 //如要打开网络流，必须运行此函数 //暂时不调用
    pFormatCtx = avformat_alloc_context();     //格式上下文结构体指针开空间

    if(avformat_open_input(&pFormatCtx,tmp,NULL,NULL)!=0)
    {
        //打开多媒体文件
        printf("Couldn't open input stream.\n");
        return -1;
    }
    if(avformat_find_stream_info(pFormatCtx,NULL)<0)
    {
        //读取音视频数据相关信息，参数0：上下文结构体指针，参数1：option
        printf("Couldn't find stream information.\n");
        return -1;
    }
    videoindex=-1;
    for(i=0; i<pFormatCtx->nb_streams; i++)  // 遍历多媒体文件中的每一个流，判断是否为视频。
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoindex=i;
            break;
        }  //上面获取视频流可以替换成av_find_best_stream函数

    if(videoindex==-1)
    {
        printf("Didn't find a video stream.\n");
        return -1;
    }

    enum AVMediaType type = AVMEDIA_TYPE_VIDEO;

    ret = av_find_best_stream(pFormatCtx, type, -1, -1, NULL, 0);

    if (ret < 0)
    {
        fprintf(stderr, "Could not find %s stream in input file '%s'\n",
        av_get_media_type_string(type), buf);
        avformat_close_input(&pFormatCtx);
    }
    pCodecCtx=pFormatCtx->streams[videoindex]->codec; //codec上下文指定到格式上下文中的codec
    pCodec=avcodec_find_decoder(pCodecCtx->codec_id); //找到一个codec，必须先调用av_register_all（）

    if(pCodec==NULL)
    {
        printf("Codec not found.\n");
        return -1;
    }
    if(avcodec_open2(pCodecCtx, pCodec,NULL)<0)
    { //初始化一个视音频编解码器的AVCodecContext
        printf("Could not open codec.\n");
        return -1;
    }
    pFrame=av_frame_alloc();  //原始帧
    pFrameYUV=av_frame_alloc();//YUV帧

    out_buffer=(uint8_t *)av_malloc(
                avpicture_get_size(AV_PIX_FMT_YUV420P,
                pCodecCtx->width, pCodecCtx->height)); //宏AV_PIX_FMT_YUV420P 代替宏PIX_FMT_YUV420P
    avpicture_fill((AVPicture *)pFrameYUV, out_buffer,
                   AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height);  //将pFrameYUV和out_buffer联系起来（pFrame指向一段内存）；宏AV_PIX_FMT_YUV420P 代替宏PIX_FMT_YUV420P
    packet=(AVPacket *)av_malloc(sizeof(AVPacket)); //开空间
    //Output Info-----------------------------
    printf("--------------- File Information ----------------\n");
    av_dump_format(pFormatCtx,0,buf,0);//调试函数，输出文件的音、视频流的基本信息
    printf("-------------------------------------------------\n");
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
        pCodecCtx->width,
        pCodecCtx->height, AV_PIX_FMT_YUV420P,
         SWS_BICUBIC, NULL, NULL, NULL); //初始化SWS，图片格式装换上下文//经过验证，输出YUV不需要格式转换，但需要调整尺寸

    while(av_read_frame(pFormatCtx, packet)>=0)
    {       //读取码流中的音频若干帧或者视频一帧,作为packet
        if(packet->stream_index==videoindex)
        {          //如果是视频
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet); //解码一帧视频数据。输入一个压缩编码的结构体AVPacket，输出一个解码后的结构体AVFrame
            if(ret < 0)
            {
                printf("Decode Error.\n");
                return -1;
            }
            if(got_picture)
            {
                sws_scale(img_convert_ctx, (const uint8_t* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                    pFrameYUV->data, pFrameYUV->linesize);     //将输出结果转化成YUV，输出YUV不需要格式转换,但是需要调整尺寸，pFrame中的图像数据的对齐方式可能是按64对齐的。

                y_size=pCodecCtx->width*pCodecCtx->height;
                //y_size_align=pCodecCtx->width*pCodecCtx->height;
                y_size_align=((pCodecCtx->width+63)/64*64)*pCodecCtx->height;

                fwrite(pFrame->data[0],1,y_size,fp_frame);    //Y
                fwrite(pFrame->data[1],1,y_size/4,fp_frame);  //U
                fwrite(pFrame->data[2],1,y_size/4,fp_frame);  //V


                fwrite(pFrame->data[0],1,y_size_align,fp_frame);    //Y
                fwrite(pFrame->data[1],1,y_size_align/4,fp_frame);  //U
                fwrite(pFrame->data[2],1,y_size_align/4,fp_frame);  //V


                //fwrite(pFrameYUV->data[0],1,y_size,fp_yuv);    //Y
                //fwrite(pFrameYUV->data[1],1,y_size/4,fp_yuv);  //U
                //fwrite(pFrameYUV->data[2],1,y_size/4,fp_yuv);  //V
                //printf("Succeed to decode 1 frame!\n");
                frame_num++;
            }
        }
    }
}
*/

void encoder::slot_MyEnCoder(QImage *img)
{
    char* tmp = new char;
    QImage *image = img;
    qDebug()<<"get image size =" << image->size();
    QByteArray ba(tmp);
    image->loadFromData(ba);
    // 将读取到的数据放在m_RgbBuf中
    m_RgbBuf = (unsigned char*)tmp;
}

//================================================================================================//
unsigned char clip_value(unsigned char x,unsigned char min_val,unsigned char max_val){
    if(x>max_val){
        return max_val;
    }else if(x<min_val){
        return min_val;
    }else{
        return x;
    }
}

//RGB 转 YUV420
bool encoder::RGB24_TO_YUV420(unsigned char *RgbBuf,int w,int h,unsigned char *yuvBuf)
{
    unsigned char*ptrY, *ptrU, *ptrV, *ptrRGB;
    memset(yuvBuf,0,w*h*3/2);
    ptrY = yuvBuf;
    ptrU = yuvBuf + w*h;
    ptrV = ptrU + (w*h*1/4);
    unsigned char y, u, v, r, g, b;
    for (int j = 0; j<h;j++){
        ptrRGB = RgbBuf + w*j*3 ;
        for (int i = 0;i<w;i++){

            r = *(ptrRGB++);
            g = *(ptrRGB++);
            b = *(ptrRGB++);
            y = (unsigned char)( ( 66 * r + 129 * g +  25 * b + 128) >> 8) + 16  ;
            u = (unsigned char)( ( -38 * r -  74 * g + 112 * b + 128) >> 8) + 128 ;
            v = (unsigned char)( ( 112 * r -  94 * g -  18 * b + 128) >> 8) + 128 ;
            *(ptrY++) = clip_value(y,0,255);
            if (j%2==0&&i%2 ==0){
                *(ptrU++) =clip_value(u,0,255);
            }
            else{
                if (i%2==0){
                *(ptrV++) =clip_value(v,0,255);
                }
            }
        }
    }
    return true;
}

// 保存yuv格式  将yuv保存到文件中
int encoder::simplest_rgb24_to_yuv420(char *url_in, int w, int h,int num,char *url_out)
{
    FILE *fp1=fopen(url_out,"wb+");

    unsigned char *pic_rgb24=(unsigned char *)url_in;
    unsigned char *pic_yuv420=(unsigned char *)malloc(w*h*3/2);

    for(int i=0;i<num;i++)
    {
        // fread(pic_rgb24,1,w*h*3,fp);
        RGB24_TO_YUV420(pic_rgb24,w,h,pic_yuv420);
        fwrite(pic_yuv420,1,w*h*3/2,fp1);
    }

    //free(pic_rgb24);
    free(pic_yuv420);
    //fclose(fp);
    fclose(fp1);
    return 0;
}
// ======================================雷博士CSDN 原文解析========================================//

typedef struct RTP_FIXED_HEADER{
    /* byte 0 */
    unsigned char csrc_len:4;       /* expect 0 */
    unsigned char extension:1;      /* expect 1 */
    unsigned char padding:1;        /* expect 0 */
    unsigned char version:2;        /* expect 2 */
    /* byte 1 */
    unsigned char payload:7;
    unsigned char marker:1;        /* expect 1 */
    /* bytes 2, 3 */
    unsigned short seq_no;
    /* bytes 4-7 */
    unsigned  long timestamp;
    /* bytes 8-11 */
    unsigned long ssrc;            /* stream number is used here. */
} RTP_FIXED_HEADER;

typedef struct MPEGTS_FIXED_HEADER
{
    unsigned sync_byte: 8;
    unsigned transport_error_indicator: 1;
    unsigned payload_unit_start_indicator: 1;
    unsigned transport_priority: 1;
    unsigned PID: 13;
    unsigned scrambling_control: 2;
    unsigned adaptation_field_exist: 2;
    unsigned continuity_counter: 4;
} MPEGTS_FIXED_HEADER;

// 封装成rtp
int encoder::simplest_rtp_parser(int port)
{
    WSADATA wsaData;
    WORD sockVersion = MAKEWORD(2,2);
    int cnt=0;

    //FILE *myout=fopen("output_log.txt","wb+");
    FILE *myout=stdout;

    FILE *fp1=fopen("output_dump.ts","wb+");

    if(WSAStartup(sockVersion, &wsaData) != 0)
    {
        return 0;
    }

    SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(serSocket == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(port);
    serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
    // 绑定端口号
    if(bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("bind error !");
        closesocket(serSocket);
        return 0;
    }

    sockaddr_in remoteAddr;
    int nAddrLen = sizeof(remoteAddr);

    // 推流
    int parse_rtp=1;
    int parse_mpegts=1;

    printf("Listening on port %d\n",port);

    char recvData[10000];
    while (1)
    {

        int pktsize = recvfrom(serSocket, recvData, 10000, 0, (sockaddr *)&remoteAddr, &nAddrLen);
        if (pktsize > 0)
        {
            //printf("Addr:%s\r\n",inet_ntoa(remoteAddr.sin_addr));
            //printf("packet size:%d\r\n",pktsize);
            //Parse RTP
            //
            if(parse_rtp!=0)
            {
                char payload_str[10]={0};
                RTP_FIXED_HEADER rtp_header;
                int rtp_header_size=sizeof(RTP_FIXED_HEADER);
                //RTP Header
                memcpy((void *)&rtp_header,recvData,rtp_header_size);

                //RFC3551
                char payload=rtp_header.payload;
                switch(payload)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18: sprintf(payload_str,"Audio");break;
                case 31: sprintf(payload_str,"H.261");break;
                case 32: sprintf(payload_str,"MPV");break;
                case 33: sprintf(payload_str,"MP2T");break;
                case 34: sprintf(payload_str,"H.263");break;
                case 96: sprintf(payload_str,"H.264");break;
                default:sprintf(payload_str,"other");break;
                }

                unsigned int timestamp=ntohl(rtp_header.timestamp);
                unsigned int seq_no=ntohs(rtp_header.seq_no);

                fprintf(myout,"[RTP Pkt] %5d| %5s| %10u| %5d| %5d|\n",cnt,payload_str,timestamp,seq_no,pktsize);

                //RTP Data
                char *rtp_data=recvData+rtp_header_size;
                int rtp_data_size=pktsize-rtp_header_size;
                fwrite(rtp_data,rtp_data_size,1,fp1);

                //Parse MPEGTS
                if(parse_mpegts!=0&&payload==33)
                {
                    MPEGTS_FIXED_HEADER mpegts_header;
                    for(int i=0;i<rtp_data_size;i=i+188)
                    {
                        if(rtp_data[i]!=0x47)
                            break;
                        //MPEGTS Header
                        //memcpy((void *)&mpegts_header,rtp_data+i,sizeof(MPEGTS_FIXED_HEADER));
                        fprintf(myout,"   [MPEGTS Pkt]\n");
                    }
                }

            }
            else
            {
                fprintf(myout,"[UDP Pkt] %5d| %5d|\n",cnt,pktsize);
                fwrite(recvData,pktsize,1,fp1);
            }
            cnt++;
        }
    }
    m_rtpData = rtp_data;
    closesocket(serSocket);
    // 获取封装的  serSocket

    m_socket = serSocket;
    WSACleanup();
    fclose(fp1);

    return 0;
}

// yuv转h264
typedef enum {
    NALU_TYPE_SLICE    = 1,
    NALU_TYPE_DPA      = 2,
    NALU_TYPE_DPB      = 3,
    NALU_TYPE_DPC      = 4,
    NALU_TYPE_IDR      = 5,
    NALU_TYPE_SEI      = 6,
    NALU_TYPE_SPS      = 7,
    NALU_TYPE_PPS      = 8,
    NALU_TYPE_AUD      = 9,
    NALU_TYPE_EOSEQ    = 10,
    NALU_TYPE_EOSTREAM = 11,
    NALU_TYPE_FILL     = 12,
} NaluType;

typedef enum {
    NALU_PRIORITY_DISPOSABLE = 0,
    NALU_PRIRITY_LOW         = 1,
    NALU_PRIORITY_HIGH       = 2,
    NALU_PRIORITY_HIGHEST    = 3
} NaluPriority;


typedef struct
{
    int startcodeprefix_len;      //! 4 for parameter sets and first slice in picture, 3 for everything else (suggested)
    unsigned len;                 //! Length of the NAL unit (Excluding the start code, which does not belong to the NALU)
    unsigned max_size;            //! Nal Unit Buffer size
    int forbidden_bit;            //! should be always FALSE
    int nal_reference_idc;        //! NALU_PRIORITY_xxxx
    int nal_unit_type;            //! NALU_TYPE_xxxx
    char *buf;                    //! contains the first byte followed by the EBSP
} NALU_t;

FILE *h264bitstream = NULL;                //!< the bit stream file

int info2=0, info3=0;

static int FindStartCode2 (unsigned char *Buf){
    if(Buf[0]!=0 || Buf[1]!=0 || Buf[2] !=1) return 0; //0x000001?
    else return 1;
}

static int FindStartCode3 (unsigned char *Buf){
    if(Buf[0]!=0 || Buf[1]!=0 || Buf[2] !=0 || Buf[3] !=1) return 0;//0x00000001?
    else return 1;
}


int GetAnnexbNALU (NALU_t *nalu){
    int pos = 0;
    int StartCodeFound, rewind;
    unsigned char *Buf;

    if ((Buf = (unsigned char*)calloc (nalu->max_size , sizeof(char))) == NULL)
        printf ("GetAnnexbNALU: Could not allocate Buf memory\n");

    nalu->startcodeprefix_len=3;

    if (3 != fread (Buf, 1, 3, h264bitstream)){
        free(Buf);
        return 0;
    }
    info2 = FindStartCode2 (Buf);
    if(info2 != 1) {
        if(1 != fread(Buf+3, 1, 1, h264bitstream)){
            free(Buf);
            return 0;
        }
        info3 = FindStartCode3 (Buf);
        if (info3 != 1){
            free(Buf);
            return -1;
        }
        else {
            pos = 4;
            nalu->startcodeprefix_len = 4;
        }
    }
    else{
        nalu->startcodeprefix_len = 3;
        pos = 3;
    }
    StartCodeFound = 0;
    info2 = 0;
    info3 = 0;

    while (!StartCodeFound){
        if (feof (h264bitstream)){
            nalu->len = (pos-1)-nalu->startcodeprefix_len;
            memcpy (nalu->buf, &Buf[nalu->startcodeprefix_len], nalu->len);
            nalu->forbidden_bit = nalu->buf[0] & 0x80; //1 bit
            nalu->nal_reference_idc = nalu->buf[0] & 0x60; // 2 bit
            nalu->nal_unit_type = (nalu->buf[0]) & 0x1f;// 5 bit
            free(Buf);
            return pos-1;
        }
        Buf[pos++] = fgetc (h264bitstream);
        info3 = FindStartCode3(&Buf[pos-4]);
        if(info3 != 1)
            info2 = FindStartCode2(&Buf[pos-3]);
        StartCodeFound = (info2 == 1 || info3 == 1);
    }
    // Here, we have found another start code (and read length of startcode bytes more than we should
    // have.  Hence, go back in the file
    rewind = (info3 == 1)? -4 : -3;

    if (0 != fseek (h264bitstream, rewind, SEEK_CUR)){
        free(Buf);
        printf("GetAnnexbNALU: Cannot fseek in the bit stream file");
    }

    // Here the Start code, the complete NALU, and the next start code is in the Buf.
    // The size of Buf is pos, pos+rewind are the number of bytes excluding the next
    // start code, and (pos+rewind)-startcodeprefix_len is the size of the NALU excluding the start code

    nalu->len = (pos+rewind)-nalu->startcodeprefix_len;
    memcpy (nalu->buf, &Buf[nalu->startcodeprefix_len], nalu->len);//
    nalu->forbidden_bit = nalu->buf[0] & 0x80; //1 bit
    nalu->nal_reference_idc = nalu->buf[0] & 0x60; // 2 bit
    nalu->nal_unit_type = (nalu->buf[0]) & 0x1f;// 5 bit
    free(Buf);

    return (pos+rewind);
}
// 读取yuv文件 转换为h264主函数
int encoder::simplest_h264_parser(char *url)
{

    NALU_t *n;
    int buffersize=100000;

    //FILE *myout=fopen("output_log.txt","wb+");
    FILE *myout=stdout;
    //读取yuv文件
    h264bitstream=fopen(url, "rb+");
    if (h264bitstream==NULL){
        printf("Open file error\n");
        return 0;
    }

    n = (NALU_t*)calloc (1, sizeof (NALU_t));
    if (n == NULL){
        printf("Alloc NALU Error\n");
        return 0;
    }

    n->max_size=buffersize;
    n->buf = (char*)calloc (buffersize, sizeof (char));
    if (n->buf == NULL){
        free (n);
        printf ("AllocNALU: n->buf");
        return 0;
    }

    int data_offset=0;
    int nal_num=0;
    printf("-----+-------- NALU Table ------+---------+\n");
    printf(" NUM |    POS  |    IDC |  TYPE |   LEN   |\n");
    printf("-----+---------+--------+-------+---------+\n");

    while(!feof(h264bitstream))
    {
        int data_lenth;
        data_lenth=GetAnnexbNALU(n);

        char type_str[20]={0};
        switch(n->nal_unit_type){
            case NALU_TYPE_SLICE:sprintf(type_str,"SLICE");break;
            case NALU_TYPE_DPA:sprintf(type_str,"DPA");break;
            case NALU_TYPE_DPB:sprintf(type_str,"DPB");break;
            case NALU_TYPE_DPC:sprintf(type_str,"DPC");break;
            case NALU_TYPE_IDR:sprintf(type_str,"IDR");break;
            case NALU_TYPE_SEI:sprintf(type_str,"SEI");break;
            case NALU_TYPE_SPS:sprintf(type_str,"SPS");break;
            case NALU_TYPE_PPS:sprintf(type_str,"PPS");break;
            case NALU_TYPE_AUD:sprintf(type_str,"AUD");break;
            case NALU_TYPE_EOSEQ:sprintf(type_str,"EOSEQ");break;
            case NALU_TYPE_EOSTREAM:sprintf(type_str,"EOSTREAM");break;
            case NALU_TYPE_FILL:sprintf(type_str,"FILL");break;
        }
        char idc_str[20]={0};
        switch(n->nal_reference_idc>>5){
            case NALU_PRIORITY_DISPOSABLE:sprintf(idc_str,"DISPOS");break;
            case NALU_PRIRITY_LOW:sprintf(idc_str,"LOW");break;
            case NALU_PRIORITY_HIGH:sprintf(idc_str,"HIGH");break;
            case NALU_PRIORITY_HIGHEST:sprintf(idc_str,"HIGHEST");break;
        }

        fprintf(myout,"%5d| %8d| %7s| %6s| %8d|\n",nal_num,data_offset,idc_str,type_str,n->len);

        data_offset=data_offset+data_lenth;

        nal_num++;
    }

    //Free
    if (n){
        if (n->buf){
            free(n->buf);
            n->buf=NULL;
        }
        free (n);
    }
    return 0;
}
