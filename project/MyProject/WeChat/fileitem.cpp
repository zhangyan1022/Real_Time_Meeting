#include "fileitem.h"
#include "ui_fileitem.h"
#include"QDebug"

FileItem::FileItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileItem) ,m_isStart(false)
{
    ui->setupUi(this);

    m_timer = new QTimer;
    connect( m_timer , SIGNAL(timeout()) , this , SLOT(slot_checkIsTransmit() ) );

    m_startTime = QTime::currentTime();
    m_lastTime = QTime::currentTime();

    m_timer->start( 1000 );
}

FileItem::~FileItem()
{
    delete ui;
    if( m_timer )
    {
        m_timer->stop();
        delete m_timer;
    }
}

void FileItem::slot_setInfo(QString fileMD5, QString fileName,
                            QString filePath, qint64 fileSize)
{
    m_fileMD5 = fileMD5;
    m_fileName = fileName;
    m_filePath = filePath;
    m_filePos = 0;
    m_fileSize = fileSize;

    ui->lb_fileName->setText( m_fileName );
    setFileTip();
}

//字节转化为kb Mb等
QString FileItem::fileSizeToMB(qint64 nSize)
{
    int nFlag = 0 ;
    //    int High = 0 ;
    int low = 0;
    QString str;
    while( nSize / 1024 > 0)
    {
        low = nSize % 1024;
        nSize = nSize /1024;
        nFlag++;
    }
    switch( nFlag )
    {
    case 0:
        str = QString("%1B").arg(nSize );
        break;
    case 1:
        str = QString("%1").arg(low*1000/1024/10);
        str = QString(".%1KB").arg(str , 2 , QChar('0'));
        str = QString("%1").arg(nSize )+str;
        break;
    case 2:
        str = QString("%1").arg(low*1000/1024/10);
        str = QString(".%1MB").arg(str , 2 , QChar('0'));
        str = QString("%1").arg(nSize ) + str;
        break;
    case 3:
        str = QString("%1").arg(low*1000/1024/10);
        str = QString(".%1GB").arg(str , 2 , QChar('0'));
        str = QString("%1").arg(nSize ) + str;
        break;
    default: str = QString("文件过大");break;
    }
    return str;
}

//定时器检测文件是否正在传输
void FileItem::slot_checkIsTransmit()
{
    if( m_lastTime.secsTo(QTime::currentTime() ) > 60 )
    {
        slot_setState( continueTransmit );
    }
}

//设置分页
void FileItem::slot_setState(int state)
{
    ui->stackedWidget->setCurrentIndex( state );
}



//更新进度
void FileItem::slot_setFileProcess(qint64 cur )
{

    qDebug() << __func__ ;

    if( !m_isStart )
    {
        m_isStart = true;
        m_startTime = QTime::currentTime();
    }
    m_lastTime = QTime::currentTime();

    slot_setState( emiting );

    int percent = cur*100 / m_fileSize ;

    m_filePos = cur;

    ui->pgb_fileProcess->setValue(percent);

    this->setFileTip();

    if( percent == 100 )
    {
        slot_setState( transmitFinish );
        m_timer->stop();
    }
}

void FileItem::setFileTip()
{
    qint64 speed =  m_filePos;
    int msec = m_startTime.msecsTo( QTime::currentTime() );
    if( msec != 0 )
        speed = speed*1000/ msec;
    else
        speed = 0;

    QString strSpeed = fileSizeToMB( speed );

    QString tip = QString("文件名:%1  大小:%2\n存储位置:%3\n开始时间:%4\n速度:%5/s\n")
            .arg(m_fileName).arg(fileSizeToMB(m_fileSize))
            .arg(m_filePath).arg(m_startTime.toString("hh:mm:ss")).arg(strSpeed);

    this->setToolTip( tip );
}

#include<QFileDialog>
//同意接收
void FileItem::on_pb_recv_clicked()
{

    QString path =  QFileDialog::getSaveFileName( this , "保存", m_fileName );
    QString tmpPath = path;

    if( tmpPath.remove(" ").isEmpty() ) return;


    m_filePath = path;

    qDebug() << m_filePath;
    Q_EMIT SIG_fileAccept();

    slot_setState( waitServer );
}


//拒绝接收文件
void FileItem::on_pb_reject_clicked()
{
    Q_EMIT SIG_fileReject();
    this->hide();
}
