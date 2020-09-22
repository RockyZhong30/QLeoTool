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

###****************************PWD***********************
include ($$PWD/qwtsource/qwt/qwt.pri)
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/qwtsource/qwt
###******************************************************

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
    common/quiwidget.cpp \
    pngtool/frmpngtool.cpp \
    qwtsource/frmqwtdemo.cpp \
    videopanel/frmvideopanel.cpp \
    videopanel/videopanel.cpp \
    lightbutton/frmlightbutton.cpp \
    lightbutton/lightbutton.cpp \
    2048/gui/qgameboard.cpp \
    2048/gui/qgameoverwindow.cpp \
    2048/gui/qresetbutton.cpp \
    2048/gui/qtile.cpp \
    2048/core/board.cpp \
    2048/core/game.cpp \
    2048/core/observer.cpp \
    2048/core/subject.cpp \
    2048/core/tile.cpp \
    AnimationButton/animationbutton.cpp \
    AnimationButton/frmanimationbutton.cpp \
    barruler/barruler.cpp \
    barruler/frmbarruler.cpp \
    calculator/BigInt.cpp \
    calculator/Calc.cpp \
    calculator/Calculator.cpp \
    calculator/ChildWindow.cpp \
    calculator/Complex.cpp \
    calculator/GeneticAlgorithm.cpp \
    calculator/HugeCalc.cpp \
    calculator/linearAlgebra.cpp \
    calculator/nonLinearAlgebra.cpp \
    calculator/polynomial.cpp \
    curvechart/curvechart.cpp \
    curvechart/frmcurvechart.cpp \
    lednumber/frmlednumber.cpp \
    lednumber/lednumber.cpp \
    roundPlot/frmroundplot.cpp \
    roundPlot/roundplot.cpp

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
    common/quiwidget.h \
    pngtool/frmpngtool.h \
    qwtsource/frmqwtdemo.h \
    videopanel/frmvideopanel.h \
    videopanel/videopanel.h \
    lightbutton/frmlightbutton.h \
    lightbutton/lightbutton.h \
    2048/gui/qgameboard.h \
    2048/gui/qgameoverwindow.h \
    2048/gui/qresetbutton.h \
    2048/gui/qtile.h \
    2048/gui/qwinwindow.h \
    2048/core/board.h \
    2048/core/game.h \
    2048/core/observer.h \
    2048/core/subject.h \
    2048/core/tile.h \
    AnimationButton/animationbutton.h \
    AnimationButton/frmanimationbutton.h \
    barruler/barruler.h \
    barruler/frmbarruler.h \
    calculator/BigInt.h \
    calculator/Calc.h \
    calculator/Calculator.h \
    calculator/ChildWindow.h \
    calculator/Complex.h \
    calculator/GeneticAlgorithm.h \
    calculator/HugeCalc.h \
    calculator/linearAlgebra.h \
    calculator/nonLinearAlgebra.h \
    calculator/polynomial.h \
    curvechart/curvechart.h \
    curvechart/frmcurvechart.h \
    lednumber/frmlednumber.h \
    lednumber/lednumber.h \
    roundPlot/frmroundplot.h \
    roundPlot/roundplot.h

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
    nettool/form/frmudpserver.ui \
    pngtool/frmpngtool.ui \
    qwtsource/frmqwtdemo.ui \
    videopanel/frmvideopanel.ui \
    lightbutton/frmlightbutton.ui \
    AnimationButton/frmanimationbutton.ui \
    barruler/frmbarruler.ui \
    calculator/about.ui \
    calculator/calculator.ui \
    calculator/constant.ui \
    calculator/history.ui \
    calculator/hugeCalc.ui \
    calculator/linearAlgebra.ui \
    calculator/nonLinearAlgebra.ui \
    calculator/permAndComb.ui \
    calculator/variable.ui \
    curvechart/frmcurvechart.ui \
    lednumber/frmlednumber.ui \
    roundPlot/frmroundplot.ui

win32:SOURCES += $$PWD/comtool/qextserialport/qextserialport_win.cpp
unix:SOURCES += $$PWD/comtool/qextserialport/qextserialport_unix.cpp
