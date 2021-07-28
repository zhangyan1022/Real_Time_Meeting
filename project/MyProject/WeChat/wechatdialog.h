#ifndef WECHATDIALOG_H
#define WECHATDIALOG_H

#include <QDialog>
#include<QCloseEvent>
#include<useritem.h>
#include<QVBoxLayout>
#include<QMenu>
#include "roomdialog.h"


// 声明有员类
class CKernel;
namespace Ui {
class WeChatDialog;
}

class WeChatDialog : public QDialog
{
    Q_OBJECT
signals:
    void SIG_close();
    void SIG_addFriend();
    void SIG_createRoom();
    void SIG_joinRoom(int);
    void SIG_systemSet();
    void SIG_offLine();
public:
    explicit WeChatDialog(QWidget *parent = 0);
    ~WeChatDialog();

    void closeEvent(QCloseEvent *event);

public slots:
    void slot_setInfo( int id, QString name, int iconid , QString feeling);
    void slot_addUserItem(QWidget *item);
    void slot_removeUserItem(QWidget *item);
    void slot_dealMenu(QAction* action);

private slots:
    void on_pb_menu_clicked();

    void on_pb_close_clicked();

private:
    Ui::WeChatDialog *ui;

    int m_id;
    QString m_name;
    QString m_feeling;
    int m_iconid;

    QVBoxLayout *m_mainLayout;

    QMenu *m_mainMenu;

    RoomDialog *m_roomDlg;
    int m_roomId;
    // 添加友元类
    friend class CKernel;
};

#endif // WECHATDIALOG_H
