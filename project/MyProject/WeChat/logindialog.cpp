#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//登录清空
void LoginDialog::on_pb_clear_clicked()
{
    ui->le_tel->setText("");
    ui->le_password->setText("");
}
//注册的清空
void LoginDialog::on_pb_clear_register_clicked()
{
    ui->le_tel_register->setText("");
    ui->le_password_register->setText("");
    ui->le_confirm_register->setText("");
}

#include <QMessageBox>
#include <QRegExp>
//登录按钮
void LoginDialog::on_pb_login_clicked()
{
    QString tel = ui->le_tel->text();
    QString password = ui->le_password->text();

    //验证 合法
    if( tel.isEmpty() ||password.isEmpty() )
    {
        // QMessageBox::about( );
        // QMessageBox::information();
        // QMessageBox::critical();
        // QMessageBox::warning();
        // QMessageBox::question();
        QMessageBox::about( this , "提示","手机号或密码不能为空" );
        return;
    }
    QRegExp exp("[0-9]{8,11}");
    bool res = exp.exactMatch( tel );
    if( !res )
    {
        QMessageBox::about( this , "提示","手机号非法" );
        return;
    }
    if( password.length() > 10 )
    {
        QMessageBox::about( this , "提示","密码非法" );
        return;
    }

    Q_EMIT SIG_LoginCommit( tel , password );
}
//注册按键
void LoginDialog::on_pb_register_clicked()
{
    QString tel = ui->le_tel_register->text();
    QString password = ui->le_password_register->text();
    QString confirm = ui->le_confirm_register->text();

    //验证 合法
    if( tel.isEmpty() ||password.isEmpty() || confirm.isEmpty() )
    {
        QMessageBox::about( this , "提示","手机号或密码不能为空" );
        return;
    }
    QRegExp exp("[0-9]{8,11}");
    bool res = exp.exactMatch( tel );
    if( !res )
    {
        QMessageBox::about( this , "提示","手机号非法" );
        return;
    }
    if( password.length() > 10 )
    {
        QMessageBox::about( this , "提示","密码非法" );
        return;
    }
    if( password != confirm )
    {
        QMessageBox::about( this , "提示","两次密码不同" );
        return;
    }

    Q_EMIT SIG_RegisterCommit( tel , password );
}

void LoginDialog::closeEvent(QCloseEvent *event)
{
    event->accept();
    // event->ignore();
    Q_EMIT SIG_close();
}

Ui::LoginDialog *LoginDialog::getUi() const
{
    return ui;
}
