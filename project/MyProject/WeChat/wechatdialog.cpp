#include "wechatdialog.h"
#include "ui_wechatdialog.h"
#include "Packdef.h"
#include <qDebug>
#include <QMessageBox>
#include <QInputDialog>
WeChatDialog::WeChatDialog(QWidget *parent) :
    QDialog(parent),m_roomId(0),
    ui(new Ui::WeChatDialog)
{
    ui->setupUi(this);

    m_mainLayout = new QVBoxLayout; //子控件跟随父控件回收, 不需要单独回收

    m_mainLayout->setContentsMargins( 0,0,0,0); // 左上右下
    m_mainLayout->setSpacing( 2 );

    ui->wdg_userList->setLayout( m_mainLayout );

   // m_mainLayout->addWidget();

    m_mainMenu = new QMenu(this);
    m_mainMenu->addAction("添加好友");
    m_mainMenu->addSeparator(); //分隔
    m_mainMenu->addAction("创建房间");
    m_mainMenu->addAction("加入房间");
    m_mainMenu->addSeparator(); //分隔
    m_mainMenu->addAction("系统设置");


    connect( m_mainMenu ,SIGNAL(triggered(QAction*))
             , this, SLOT(slot_dealMenu(QAction*)) );
}

WeChatDialog::~WeChatDialog()
{
    qDebug()<<__func__;
    delete ui;
}

//关闭时间发送close信号
void WeChatDialog::closeEvent(QCloseEvent *event)
{
    qDebug()<<__func__;
    Q_EMIT SIG_offLine();
    Q_EMIT SIG_close();
}

void WeChatDialog::slot_setInfo(int id, QString name, int iconid, QString feeling)
{
    //先设置属性
    m_id = id;
    m_name = name;
    m_iconid = iconid;
    m_feeling = feeling;
    //设置ui
    ui->pb_icon->setIcon( QIcon( QString(":/tx/%1.png").arg(m_iconid) ) );
    ui->lb_name->setText( m_name);
    ui->lb_feeling->setText( m_feeling );
}

void WeChatDialog::slot_addUserItem( QWidget *item  )
{
    m_mainLayout->addWidget( item );
    //m_mainLayout->insertWidget( 0 ,);
}

void WeChatDialog::slot_removeUserItem( QWidget *item )
{
    m_mainLayout->removeWidget( item );
}

//处理菜单
void WeChatDialog::slot_dealMenu(QAction *action)
{
    if( action->text() == "添加好友")
    {
        Q_EMIT SIG_addFriend();
    }
    if( action->text() == "创建房间")
    {
        if(m_roomId != 0)
        {
            QMessageBox::about(this,"提示","已将在房间里面了");
            return;
        }
        Q_EMIT SIG_createRoom();
    }
    if( action->text() == "加入房间")
    {
        if(m_roomId != 0)
        {
            QMessageBox::about(this,"提示","已将在房间里面了");
            return;
        }
        // 房间号
        QString strRoom = QInputDialog::getText( this , "加入房间" , "输入房间号");
        QRegExp reg("[0-9]{1,10}");
        bool res = reg.exactMatch( strRoom );
        if( res )
        {
            // 更新房间号
            m_roomId = strRoom.toInt();
            //加入房间信号
            Q_EMIT SIG_joinRoom(m_roomId);
        }else
        {
            QMessageBox::about(this, "提示" , "房间号非法\n输入8位以内的数字");
        }
    }
    if( action->text() == "系统设置")
    {
        Q_EMIT SIG_systemSet();
    }
}

void WeChatDialog::on_pb_menu_clicked()
{
    // 向上弹出菜单
    QPoint p;
    p.setX( QCursor::pos().x() );
    p.setY( QCursor::pos().y() - m_mainMenu->sizeHint().height() ); //sizeHint() 最终尺寸
    //弹出菜单
    if( m_mainMenu )
    {
        m_mainMenu->exec( p );
    }
}

//关闭
void WeChatDialog::on_pb_close_clicked()
{
    if(QMessageBox::question(this,"提示","是否退出程序") == QMessageBox::Yes)
    {
        // 发送离线请求
        Q_EMIT SIG_offLine();
        this->close();
    }
}



















