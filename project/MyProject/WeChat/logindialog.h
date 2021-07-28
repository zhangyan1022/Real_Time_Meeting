#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include<QCloseEvent>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
signals:
    void SIG_LoginCommit(QString tel , QString password );
    void SIG_RegisterCommit(QString tel , QString password );
    void SIG_close();
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    Ui::LoginDialog *getUi() const;

private slots:
    void on_pb_clear_clicked();

    void on_pb_clear_register_clicked();

    void on_pb_login_clicked();

    void on_pb_register_clicked();

    void closeEvent(QCloseEvent * event );
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
