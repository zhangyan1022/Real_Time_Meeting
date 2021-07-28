#ifndef USERITEM_H
#define USERITEM_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT
signals:
    void SIG_itemClicked();
public:
    explicit UserItem(QWidget *parent = 0);
    ~UserItem();

public slots:
    void on_pb_icon_clicked();

    void mouseDoubleClickEvent(QMouseEvent *event);

    void slot_setInfo( int id , QString name ,
                       int state = 0 , int iconid = 1 , QString feeling ="比较懒,什么也没写");
private:
    Ui::UserItem *ui;
public:
    int m_id;
    QString m_name;
    int m_state;
    int m_iconid;
    QString m_feeling;
};

#endif // USERITEM_H
