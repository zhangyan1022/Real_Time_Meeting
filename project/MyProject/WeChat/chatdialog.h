#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QObject>
#include "fileitem.h"
#include <QVBoxLayout>
#include <QFont>
#include "bqform.h"
namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT


signals:
    void SIG_SendChatMessage(int ,QString);
    void SIG_SendFile(int ,QString);
public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

public slots:
    void SetInfo(int id,QString name);
    void slot_recvChatMsg(QString content);
    void slot_showOffline();
    void slot_addFileItem( FileItem* item );
private slots:
    void on_pb_send_clicked();
    // 发送文件
    void on_pu_tool5_clicked();

private:
    Ui::ChatDialog *ui;

    int m_id;
    QString m_name;
    QVBoxLayout * m_fileLayout;
    QFont m_font;
    bqForm *m_bq;
};

#endif // CHATDIALOG_H
