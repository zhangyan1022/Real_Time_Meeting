#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QImage>

#include <QMouseEvent>
#include <QPaintEvent>

class VideoForm;

namespace Ui {
class VideoForm;
}

class VideoForm : public QWidget
{
    Q_OBJECT
signals:
    void SIG_itemClicked(int);
public:
    explicit VideoForm(QWidget *parent = nullptr);
    ~VideoForm();

    void setInfo(int id,QString name);

    // 重载函数
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
public slots:
    void slot_setOneImage(QImage image);

public:
    Ui::VideoForm *ui;
    int m_id;
    QString m_name;
    QImage m_image;

    friend class VideoForm;
};

#endif // VIDEOFORM_H
