#include "setuserdialog.h"
#include "ui_setuserdialog.h"
#include"QIcon"

SetUserDialog::SetUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetUserDialog)
{
    ui->setupUi(this);

    ui->cbx_icon->setIconSize( QSize(50,50) );

    for( int i = 0 ; i < 15 ; i++)
    {
        QString strPath = QString(":/tx/%1.png").arg(i)/*.arg(i , 2 ,QChar('0'))*/;
        ui->cbx_icon->addItem( QIcon(strPath) , "");
    }
}

SetUserDialog::~SetUserDialog()
{
    delete ui;
}

#include"QMessageBox"
//提交用户设置
void SetUserDialog::on_pb_set_clicked()
{
    int index = ui->cbx_icon->currentIndex();
    QString name = ui->le_name->text();
    QString feeling = ui->le_feeling->text();
    QString strdefault = "比较懒,什么也没写";

    QString tmpName = name;
    QString tmpFeeling = feeling;
    if( tmpName.remove(" ").isEmpty() ) {
        QMessageBox::about(this , "提示","不能是空名字");
        return;
    }
    if( name.length() > 10 )
    {
        QMessageBox::about(this , "提示","名字长了");
        return;
    }
    if( tmpFeeling.remove(" ").isEmpty())
    {
        feeling = strdefault;
    }
    if( feeling.length() > 50 )
    {
        QMessageBox::about(this , "提示","签名长了");
        return;
    }

    Q_EMIT SIG_setCommit( index , name , feeling);
}
