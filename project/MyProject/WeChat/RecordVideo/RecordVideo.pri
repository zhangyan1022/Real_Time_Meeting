QT       += core gui

INCLUDEPATH+=C:\Users\ZY\Desktop\WeChat0604\OpenCV\include\opencv\
                    C:\Users\ZY\Desktop\WeChat0604\OpenCV\include\opencv2\
                    C:\Users\ZY\Desktop\WeChat0604\OpenCV\include


LIBS+=C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_calib3d2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_contrib2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_core2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_features2d2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_flann2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_gpu2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_highgui2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_imgproc2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_legacy2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_ml2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_objdetect2410.dll.a\
        C:\Users\ZY\Desktop\WeChat0604\OpenCV\lib\libopencv_video2410.dll.a


HEADERS += \
    $$PWD/screen_read.h \
    $$PWD/video_read.h \
    $$PWD/common.h \
    $$PWD/myfacedetect.h

SOURCES += \
    $$PWD/screen_read.cpp \
    $$PWD/video_read.cpp \
    $$PWD/myfacedetect.cpp



