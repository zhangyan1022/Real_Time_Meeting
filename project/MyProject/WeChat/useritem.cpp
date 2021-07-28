#include "useritem.h"
#include "ui_useritem.h"
#include<QBitmap>
UserItem::UserItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserItem) ,m_id(0),m_iconid(0)
{
    ui->setupUi(this);
}

UserItem::~UserItem()
{
    delete ui;
}

//单击头像
void UserItem::on_pb_icon_clicked()
{
    Q_EMIT SIG_itemClicked();
}

//双击鼠标
void UserItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->accept();

    Q_EMIT SIG_itemClicked();
}

//设置用户信息
void UserItem::slot_setInfo(int id, QString name, int state, int iconid, QString feeling)
{
    // 属性
    m_id = id;
    m_name = name;
    m_state = state;
    m_iconid = iconid;
    m_feeling = feeling;

    // ui
    ui->lb_name ->setText( m_name );
    ui->lb_feeling->setText( m_feeling );


    //在线是彩色的 不在线是黑白的
    if( m_state )
    {
        ui->pb_icon->setIcon( QIcon( QString(":/tx/%1.png").arg(m_iconid) ));
    }
    else
    {
        QBitmap bt;
        bt.load( QString(":/tx/%1.png").arg(m_iconid) );
        ui->pb_icon->setIcon( bt );
    }

    this->repaint(); // 触发重绘事件  为了让彩色变黑白

}
