#include "roomdialog.h"
#include "ui_roomdialog.h"
#include <QMessageBox>
#include <IMToolBox.h>
RoomDialog::RoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomDialog)
{

    ui->setupUi(this);

    m_videoList = new IMToolList(QString("房间成员"));

    ui->wdg_friendList->addItem(m_videoList);

}

RoomDialog::~RoomDialog()
{
    delete ui;
}

// 离开房间
void RoomDialog::on_pu_leaveroom_clicked()
{
    if(m_roomid == 0)
    {
        QMessageBox::about(this,"提示","还没有进入房间！");
        return;
    }
    else
    {
        if(QMessageBox::question(this,"提示","是否推出房间") == QMessageBox::Yes)
        {
            Q_EMIT SIG_leaveRoom(m_roomid);
            clear();
        }
        else
        {
            return;
        }
    }
}

void RoomDialog::slot_setInfo(int id)
{
    m_roomid = id;

    ui->lb_roomName->setText(QString("房间号:[%1]").arg(m_roomid));
}

void RoomDialog::clear()
{
    ui->lb_roomName->setText(QString("房间号：---"));
    ui->pb_openSound->setText("打开音频设备");
    ui->pb_openVideo->setText("打开视频设备");
    ui->cb_photo->setCurrentIndex(0);

    m_roomid = 0;
}
// 打开视频设备
void RoomDialog::on_pb_openVideo_clicked()
{
    if(ui->pb_openVideo->text() == "打开视频设备")
    {
        Q_EMIT SIG_openVideo();
        ui->pb_openVideo->setText("关闭视频设备");
    }
    else
    {
        Q_EMIT SIG_closeVideo();
         ui->pb_openVideo->setText("打开视频设备");
    }
}
// 打开音频设备
void RoomDialog::on_pb_openSound_clicked()
{
    if(ui->pb_openSound->text() == "打开音频设备")
    {
        Q_EMIT SIG_openSound();
        ui->pb_openSound->setText("关闭音频设备");
    }
    else
    {
        Q_EMIT SIG_closeSound();
        ui->pb_openSound->setText("打开音频设备");
    }
}

void RoomDialog::on_cb_photo_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "无滤镜")
    {

    }
    else if(arg1 == "兔子耳朵")
    {

    }
    else if(arg1 == "圣诞帽子")
    {

    }
}

void RoomDialog::on_pb_close_clicked()
{
    on_pu_leaveroom_clicked();
}

void RoomDialog::slot_addVideoform(VideoForm *video)
{
    m_videoList->addItem(video);
}

void RoomDialog::slot_removeVideoform(VideoForm *video)
{
    m_videoList->removeItem(video);
}

Ui::RoomDialog *RoomDialog::getUi() const
{
    return ui;
}


// 设置放大图的ID
void RoomDialog::slot_setBigImageID(int id , QString name)
{
    ui->widget->setInfo(id , name);
}

//获取放大图的id
int RoomDialog::slot_getBigImageID()
{
    return ui->widget->m_id;
}










