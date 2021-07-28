#-------------------------------------------------
#
# Project created by QtCreator 2021-05-25T18:21:00
#
#-------------------------------------------------
##    windeployqt + .exe;  // 创建debug .exe
QT       += core gui
##QT       += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeChat
TEMPLATE = app

include(./netapi/netapi.pri)
include(./RecordVideo/RecordVideo.pri)
include (./decoder/decoder.pri)

INCLUDEPATH += ./netapi/
INCLUDEPATH += ./RecordVideo/
INCLUDEPATH += ./decoder/


SOURCES += main.cpp\
    IMToolBox.cpp \
    chatdialog.cpp \
    notify.cpp \
    roomdialog.cpp \
    videoform.cpp \
        wechatdialog.cpp \
    ckernel.cpp \
    logindialog.cpp \
    setuserdialog.cpp \
    useritem.cpp \
    fileitem.cpp \
    bqform.cpp

HEADERS  += wechatdialog.h \
    IMToolBox.h \
    chatdialog.h \
    ckernel.h \
    logindialog.h \
    notify.h \
    roomdialog.h \
    setuserdialog.h \
    useritem.h \
    videoform.h \
    fileitem.h \
    bqform.h

FORMS    += wechatdialog.ui \
    chatdialog.ui \
    logindialog.ui \
    notify.ui \
    roomdialog.ui \
    setuserdialog.ui \
    useritem.ui \
    videoform.ui \
    fileitem.ui \
    bqform.ui
RESOURCES += \
    res.qrc \
    resource.qrc
