﻿#ifndef FRMWEBCLIENT_H
#define FRMWEBCLIENT_H

#include <QWidget>
#include <QtWebSockets>

namespace Ui {
class frmWebClient;
}

class frmWebClient : public QWidget
{
    Q_OBJECT

public:
    explicit frmWebClient(QWidget *parent = 0);
    ~frmWebClient();

private:
    Ui::frmWebClient *ui;

    bool isOk;
    QWebSocket *socket;
    QTimer *timer;

private slots:
    void initForm();
    void initConfig();
    void saveConfig();
    void changeTimer();
    void append(int type, const QString &data, bool clear = false);

private slots:
    void connected();
    void disconnected();
    void sendData(const QString &data);

    void textFrameReceived(const QString &data, bool isLastFrame);
    void binaryFrameReceived(const QByteArray &data, bool isLastFrame);
    void textMessageReceived(const QString &data);
    void binaryMessageReceived(const QByteArray &data);

private slots:
    void on_btnConnect_clicked();
    void on_btnSave_clicked();
    void on_btnClear_clicked();
    void on_btnSend_clicked();
};

#endif // FRMWEBCLIENT_H
