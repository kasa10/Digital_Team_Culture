QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg quickwidgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GraphController/bookitem.cpp \
    GraphController/g_arrow.cpp \
    GraphController/g_object.cpp \
    GraphController/g_scene.cpp \
    GraphController/groupitem.cpp \
    GraphController/groupobject.cpp \
    GraphController/humanobject.cpp \
    GraphController/personitem.cpp \
    GraphController/sceneview.cpp \
    Semanthic/Singleton.cpp \
    Semanthic/datagenerator.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GraphController/bookitem.h \
    GraphController/g_arrow.h \
    GraphController/g_object.h \
    GraphController/g_scene.h \
    GraphController/groupitem.h \
    GraphController/groupobject.h \
    GraphController/humanobject.h \
    GraphController/personitem.h \
    GraphController/sceneview.h \
    Semanthic/Singleton.h \
    Semanthic/datagenerator.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
