#ifndef QLEOTOOL_H
#define QLEOTOOL_H

#include <QModelIndex>

#include "common/shadowwidget.h"
#include "common.h"

class MainTopWidget;
class MainCenterWidget;

class QLeoTool : public ShadowWidget
{
    Q_OBJECT

public:
    enum LeoToolNum
    {
        LeoTool_Init = 0,
        LeoTool_homePage,
        LeoTool_Battary,
        LeoTool_ButtonDefence,
        LeoTool_DeviceSizetable,
        LeoTool_FlatUi,
        LeoTool_imageSwitch,
        LeoTool_IpAdress,
        LeoTool_MoveWidget,
        LeoTool_LunarCalenarWidget,
        LeoTool_NavButton,
        LeoTool_VideoPanel,
        LeoTool_LightButton,
        LeoTool_AnimationButton,
        LeoTool_BarRuler,
        LeoTool_BarVolume,
        LeoTool_CurveChart,
        LeoTool_LedNumber,
        LeoTool_RoundPlot,
        LeoTool_AdsWidget,
        LeoTool_Mouse,
        LeoTool_RoundCircle,
        LeoTool_DrawTextOnPath,
        LeoTool_RouletteDraw,
        LeoTool_Calculator,
        LeoTool_ComTool,
        LeoTool_NetTool,
        LeoTool_PngTool,
        LeoTool_QwtDemo,
        LeoTool_2048Game,
        LeoTool_end
    };

    QLeoTool(QWidget *parent = nullptr);
    ~QLeoTool();

private slots:
    void closeWidget();
    void homePageWidget();
    void showNavigation();

    void navigationListViewClick(QModelIndex index);

private:
    void initUi();
    void initConnect();
    void initParameter();

private:
    MainTopWidget       *m_topWidget;
    MainCenterWidget    *m_centerWidget;
};
#endif // QLEOTOOL_H
