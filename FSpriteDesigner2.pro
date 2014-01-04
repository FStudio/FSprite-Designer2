#-------------------------------------------------
#
# Project created by QtCreator 2013-08-14T21:30:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FSpriteDesigner2
TEMPLATE = app

INCLUDEPATH +=  src \


SOURCES += \
    src/SdMsgCenter.cc \
    src/SdMain.cc \
    src/SdGlobal.cc \
    src/widget/SdMainWindow.cc \
    src/widget/SdEditViewWidget.cc \
    src/widget/SdProjectExploreWidget.cc \
    src/widget/SdResourceExploreWidget.cc \
    src/widget/SdAnimationTitleBar.cc

HEADERS  += \
    src/SdMsgCenter.h \
    src/SdGlobal.h \
    src/widget/SdPropertyWidget.h \
    src/widget/SdMainWindow.h \
    src/widget/SdEditViewWidget.h \
    src/widget/SdAnimaionWidget.h \
    src/widget/SdProjectExploreWidget.h \
    src/widget/SdResourceExploreWidget.h \
    src/SdMacros.h \
    src/widget/SdAnimationTitleBar.h


INCLUDEPATH +=faeris/lib/libfaeris/src \
                         faeris/lib/lib3rdparty/c99/include \
                         faeris/lib/lib3rdparty/freetype/include \
                         faeris/lib/lib3rdparty/curl/include \
                         faeris/lib/lib3rdparty/GL/include \
                         faeris/lib/lib3rdparty/libpng/include \
						 faeris/lib/lib3rdparty/pthread/include \


win32 {

        LIBS += -L$$PWD/faeris/lib/library/win32  -llibfaerisd   \
                -L$$PWD/faeris/lib/library/win32/3rdparty -lcurld -lglew32 -llibpngd -lfreetype

		CONFIG +=console
}

FORMS += \
    resource/ui/input_text.ui \
    resource/ui/ResourcePreView.ui

RESOURCES += \
    resource/qrc/image.qrc


