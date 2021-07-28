#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include <IMToolBox.h>
#include "videoform.h"

class RoomDialog;

namespace Ui {
class RoomDialog;
}

class RoomDialog : public QDialog
{
    Q_OBJECT

signals:
    void SIG_closeVideo();

    void SIG_openVideo();
    void SIG_closeSound();

    void SIG_openSound();

    void SIG_leaveRoom(int);
public:
    explicit RoomDialog(QWidget *parent = nullptr);
    ~RoomDialog();

    Ui::RoomDialog *getUi() const;

public slots:
    void on_pu_leaveroom_clicked();

    void slot_setInfo(int);
    void clear();
    void on_pb_openVideo_clicked();

    void on_pb_openSound_clicked();

    void on_cb_photo_currentIndexChanged(const QString &arg1);

    void on_pb_close_clicked();

    void slot_addVideoform(VideoForm *video);

    void slot_removeVideoform(VideoForm *video);

    void slot_setBigImageID(int ,QString);

    int slot_getBigImageID();

public:
    Ui::RoomDialog *ui;

    int m_roomid;
    VideoForm *m_videoForm;
    // 先于子类 后于父类
    IMToolList *m_videoList;

    friend class RoomDialog;
};

#endif // ROOMDIALOG_H
