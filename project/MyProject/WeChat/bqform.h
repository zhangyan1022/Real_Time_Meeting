#ifndef BQFORM_H
#define BQFORM_H

#include <QWidget>
#include<QPushButton>
#include<QFocusEvent>

namespace Ui {
class bqForm;
}

class bqForm : public QWidget
{
    Q_OBJECT

public:
    explicit bqForm(QWidget *parent = 0);
    ~bqForm();

private slots:
    void on_quitBtn_clicked();

    void on_BackBtn_clicked();

    void on_ForwardBtn_clicked();
    void on_Click();

//    virtual bool event(QEvent *event);
//    virtual bool eventFilter(QObject *o, QEvent *e);
signals:
    void  SIG_BQID( qint32 id/* QIcon ico*/);
private:
    Ui::bqForm *ui;
    QStringList lstBtn;
    QList<QPushButton*> m_listBtn;
};

#endif // BQFORM_H
