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
    devicesizetable/devicesizetable.cpp \
    devicesizetable/frmdevicesizetable.cpp \
    flatui/flatui.cpp \
    flatui/frmflatui.cpp \
    imageswitch/frmimageswitch.cpp \
    imageswitch/imageswitch.cpp \
    ipaddress/frmipaddress.cpp \
    ipaddress/ipaddress.cpp \
    movewidget/frmmovewidget.cpp \
    movewidget/movewidget.cpp \
    lunarcalendarwidget/frmlunarcalendarwidget.cpp \
    lunarcalendarwidget/lunarcalendarinfo.cpp \
    lunarcalendarwidget/lunarcalendaritem.cpp \
    lunarcalendarwidget/lunarcalendarwidget.cpp \
    navbutton/frmnavbutton.cpp \
    navbutton/navbutton.cpp \
    common/iconhelper.cpp \
    nettool/form/frmmain.cpp \
    nettool/form/frmtcpclient.cpp \
    nettool/form/frmtcpserver.cpp \
    nettool/form/frmudpclient.cpp \
    nettool/form/frmudpserver.cpp \
    common/tcpserver.cpp \
    common/app.cpp \
    common/quiwidget.cpp

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
    comtool/qextserialport/qextserialport.h \
    comtool/qextserialport/qextserialport_global.h \
    comtool/qextserialport/qextserialport_p.h \
    comtool/form/frmcomtool.h \
    devicesizetable/devicesizetable.h \
    devicesizetable/frmdevicesizetable.h \
    flatui/flatui.h \
    flatui/frmflatui.h \
    imageswitch/frmimageswitch.h \
    imageswitch/imageswitch.h \
    ipaddress/frmipaddress.h \
    ipaddress/ipaddress.h \
    movewidget/frmmovewidget.h \
    movewidget/movewidget.h \
    lunarcalendarwidget/frmlunarcalendarwidget.h \
    lunarcalendarwidget/lunarcalendarinfo.h \
    lunarcalendarwidget/lunarcalendaritem.h \
    lunarcalendarwidget/lunarcalendarwidget.h \
    navbutton/frmnavbutton.h \
    navbutton/navbutton.h \
    common/iconhelper.h \
    nettool/form/frmmain.h \
    nettool/form/frmtcpclient.h \
    nettool/form/frmtcpserver.h \
    nettool/form/frmudpclient.h \
    nettool/form/frmudpserver.h \
    common/tcpserver.h \
    common/app.h \
    common/head.h \
    common/quiwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/resource.qrc

SUBDIRS += \
    battery/battery.pro \
    buttondefence/buttondefence.pro

FORMS += \
    battery/frmbattery.ui \
    buttondefence/frmbuttondefence.ui \
    comtool/form/frmcomtool.ui \
    devicesizetable/frmdevicesizetable.ui \
    flatui/frmflatui.ui \
    imageswitch/frmimageswitch.ui \
    ipaddress/frmipaddress.ui \
    movewidget/frmmovewidget.ui \
    lunarcalendarwidget/frmlunarcalendarwidget.ui \
    navbutton/frmnavbutton.ui \
    nettool/form/frmmain.ui \
    nettool/form/frmtcpclient.ui \
    nettool/form/frmtcpserver.ui \
    nettool/form/frmudpclient.ui \
    nettool/form/frmudpserver.ui

win32:SOURCES += $$PWD/comtool/qextserialport/qextserialport_win.cpp
unix:SOURCES += $$PWD/comtool/qextserialport/qextserialport_unix.cpp
