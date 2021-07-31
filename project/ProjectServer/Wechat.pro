TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH+=./include/

LIBS+=-lmysqlclient
LIBS+=-lpthread
SOURCES += \
    src/Thread_pool.cpp \
    src/TCPNet.cpp \
    src/TCPKernel.cpp \
    src/Mysql.cpp \
    src/main.cpp \
    src/err_str.cpp

HEADERS += \
    include/Thread_pool.h \
    include/TCPNet.h \
    include/TCPKernel.h \
    include/packdef.h \
    include/Mysql.h \
    include/err_str.h \
    src/Mysql.cpp.bak

OTHER_FILES += \
    src/makefile

