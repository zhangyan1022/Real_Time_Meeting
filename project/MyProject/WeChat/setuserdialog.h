#ifndef SETUSERDIALOG_H
#define SETUSERDIALOG_H

#include <QDialog>

namespace Ui {
class SetUserDialog;
}

class SetUserDialog : public QDialog
{
    Q_OBJECT

signals:
    void SIG_setCommit( int iconid , QString name , QString feeling );

public:
    explicit SetUserDialog(QWidget *parent = 0);
    ~SetUserDialog();

private slots:
    void on_pb_set_clicked();

private:
    Ui::SetUserDialog *ui;
};

#endif // SETUSERDIALOG_H
