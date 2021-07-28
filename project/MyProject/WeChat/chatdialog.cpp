#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QTime>
#include <QFileDialog>
#include <QDebug>
ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}
void ChatDialog::SetInfo(int id,QString name)
{
    m_id = id;
    m_name = name;

    ui->lb_name->setText(QString("与[%1]的聊天").arg(m_name));
}

void ChatDialog::on_pb_send_clicked()
{
    QString content =ui->te_send->toPlainText();
    if(content.isEmpty())
    {
        return;
    }
    content = ui->te_send->toHtml();
    // 粘贴到聊天区
    ui->tb_chat->append(QString("[我]%1").arg(QTime::currentTime().toString("hh:mm:ss")));
    ui->tb_chat->append(content);

    ui->te_send->clear();

    Q_EMIT SIG_SendChatMessage(m_id,content);

}

//接收聊天内容
void ChatDialog::slot_recvChatMsg(QString content)
{
    ui->tb_chat->append( QString("[ %1 ] %2").arg(m_name).arg(QTime::currentTime().toString("hh:mm:ss")) );
    ui->tb_chat->append( content );
}

//显示离线
void ChatDialog::slot_showOffline()
{
    ui->tb_chat->append( QString("用户[ %1 ]已离线").arg(m_name) );
}

//发送文件
void ChatDialog::on_pu_tool5_clicked()
{
    QString strPath = QFileDialog::getOpenFileName(this,"打开");
    if(!strPath.remove(" ").isEmpty())
    {
        qDebug()<<strPath;
    }

    Q_EMIT SIG_SendFile(m_id,strPath);
}

void ChatDialog::slot_addFileItem(FileItem *item)
{
    qDebug()<<__func__;
    m_fileLayout->addWidget( item );
}














