#include "videoform.h"
#include "ui_videoform.h"
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QDebug>
VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm)
{
    ui->setupUi(this);
}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::setInfo(int id, QString name)
{
    m_id = id;
    m_name = name;

    ui->lb_name->setText(QString("用户：%1").arg(m_name));
}

void VideoForm::paintEvent(QPaintEvent *event)
{
    qDebug()<<"paintEvent";
    //画黑背景
    QPainter  painter( this );
    painter.setBrush(Qt::white);
    painter.drawRect( 0,0, this->width() , this->height());

    //画图片
    if( m_image.size().height()<= 0  ) return;

    // 加载图片用 QImage , 画图使用QPixmap
    // 图片缩放  scaled
    QPixmap  pixmap =  QPixmap::fromImage(
                m_image.scaled( this->size() , Qt::KeepAspectRatio ,Qt::FastTransformation)
                );

    //画的位置
    int x = this->width() - pixmap.width();
    int y = this->height() - pixmap.height() - ui->lb_name->height();
    x = x /2;
    y = ui->lb_name->height() + y/2;

    painter.drawPixmap(QPoint(x,y) , pixmap);
}

// 设置图片
void VideoForm::slot_setOneImage(QImage image)
{
    m_image = image;
    //重绘
    this->repaint();//调用重绘-->到绘图事件
}
void VideoForm::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT SIG_itemClicked(m_id);
}
