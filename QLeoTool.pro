QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NavListView/navlistview.cpp \
    common/basestylewidget.cpp \
    common/shadowwidget.cpp \
    main.cpp \
    maincenterwidget.cpp \
    maintopwidget.cpp \
    qleotool.cpp \
    battery/battery.cpp \
    battery/frmbattery.cpp \
    buttondefence/buttondefence.cpp \
    buttondefence/frmbuttondefence.cpp \
    leohomepage.cpp \
    comtool/qextserialport/qextserialport.cpp \
    comtool/form/frmcomtool.cpp \
    comtool/api/app.cpp \
    comtool/api/quiwidget.cpp \
    devicesizetable/devicesizetable.cpp \
    devicesizetable/frmdevicesizetable.cpp \
    flatui/flatui.cpp \
    flatui/frmflatui.cpp \
    imageswitch/frmimageswitch.cpp \
    imageswitch/imageswitch.cpp

HEADERS += \
    NavListView/navlistview.h \
    common.h \
    common/basestylewidget.h \
    common/shadowwidget.h \
    maincenterwidget.h \
    maintopwidget.h \
    qleotool.h \
    battery/battery.h \
    battery/frmbattery.h \
    buttondefence/buttondefence.h \
    buttondefence/frmbuttondefence.h \
    leohomepage.h \
    comtool/head.h \
    comtool/qextserialport/qextserialport.h \
    comtool/qextserialport/qextserialport_global.h \
    comtool/qextserialport/qextserialport_p.h \
    comtool/form/frmcomtool.h \
    comtool/api/app.h \
    comtool/api/quiwidget.h \
    devicesizetable/devicesizetable.h \
    devicesizetable/frmdevicesizetable.h \
    flatui/flatui.h \
    flatui/frmflatui.h \
    imageswitch/frmimageswitch.h \
    imageswitch/imageswitch.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/resource.qrc \
    buttondefence/main.qrc \
    imageswitch/main.qrc

SUBDIRS += \
    battery/battery.pro \
    buttondefence/buttondefence.pro

FORMS += \
    battery/frmbattery.ui \
    buttondefence/frmbuttondefence.ui \
    comtool/form/frmcomtool.ui \
    devicesizetable/frmdevicesizetable.ui \
    flatui/frmflatui.ui \
    imageswitch/frmimageswitch.ui

win32:SOURCES += $$PWD/comtool/qextserialport/qextserialport_win.cpp
unix:SOURCES += $$PWD/comtool/qextserialport/qextserialport_unix.cpp
