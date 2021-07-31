HEADERS += \
    $$PWD/encoder.h \
    $$PWD/frame.h \
    $$PWD/decoder.h

SOURCES += \
    ##$$PWD/decoder.cpp \
    $$PWD/encoder.cpp \
    $$PWD/frame.cpp    \
    $$PWD/decoder.cpp


INCLUDEPATH += ./ffmpeg/include

LIBS += \
        -L$$PWD/ffmpeg/lib -lavformat \
        -L$$PWD/ffmpeg/lib -lavcodec \
        -L$$PWD/ffmpeg/lib -lavutil \
        -L$$PWD/ffmpeg/lib -lswscale \
