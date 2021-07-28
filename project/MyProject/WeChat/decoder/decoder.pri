HEADERS += \
    $$PWD/decoder.h \
    $$PWD/encoder.h \
    $$PWD/frame.h

SOURCES += \
    $$PWD/decoder.cpp \
    $$PWD/encoder.cpp \
    $$PWD/frame.cpp


INCLUDEPATH += ./ffmpeg/include

##LIBS += ./ffmpeg/lib -lavformat
##LIBS += ./ffmpeg/lib -lavcodec
##LIBS += ./ffmpeg/lib -lavutil
##LIBS += ./ffmpeg/lib -lswscale
