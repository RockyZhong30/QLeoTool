#include <QApplication>
#include <QDebug>
#include "qleotool.h"
#include "maintopwidget.h"
#include "maincenterwidget.h"

#include "leohomepage.h"
#include "battery/frmbattery.h"
#include "buttondefence/frmbuttondefence.h"
#include "comtool/form/frmcomtool.h"
#include "devicesizetable/frmdevicesizetable.h"
#include "flatui/frmflatui.h"
#include "imageswitch/frmimageswitch.h"
#include "ipaddress/frmipaddress.h"
#include "movewidget/frmmovewidget.h"
#include "lunarcalendarwidget/frmlunarcalendarwidget.h"
#include "navbutton/frmnavbutton.h"
#include "nettool/form/frmmain.h"
#include "pngtool/frmpngtool.h"
#include "qwtsource/frmqwtdemo.h"
#include "videopanel/frmvideopanel.h"
#include "lightbutton/frmlightbutton.h"
#include "2048/gui/qgameboard.h"
#include "AnimationButton/frmanimationbutton.h"
#include "barruler/frmbarruler.h"
#include "calculator/Calculator.h"
#include "curvechart/frmcurvechart.h"
#include "lednumber/frmlednumber.h"
#include "roundPlot/frmroundplot.h"
#include "adswidget/frmadswidget2.h"
#include "barvolume/frmbarvolume.h"
#include "mouse/frmmouse.h"
#include "roundcircle/frmroundcircle.h"
#include "drawtextonPath/frmdrawtextonpath.h"
#include "roulettedraw/frmroulettedraw.h"

QLeoTool::QLeoTool(QWidget *parent)
    : ShadowWidget(parent)
{
    this->initUi();
    this->initConnect();
    this->initParameter();
}

QLeoTool::~QLeoTool()
{
}

void QLeoTool::initUi()
{
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    m_topWidget = new MainTopWidget(this);
    m_centerWidget = new MainCenterWidget(this);
}

void QLeoTool::initConnect()
{
    connect(m_topWidget, &MainTopWidget::closeWidget, this, &QLeoTool::closeWidget);
    connect(m_topWidget, &MainTopWidget::homePageWidget, this, &QLeoTool::homePageWidget);
    connect(m_topWidget, &MainTopWidget::showNavigation, this, &QLeoTool::showNavigation);

    connect(m_centerWidget, &MainCenterWidget::listViewPress, this, &QLeoTool::navigationListViewClick);

    connect(m_centerWidget, &MainCenterWidget::setLabelNavigation, m_topWidget, &MainTopWidget::setLabelNavigation);
}

void QLeoTool::initParameter()
{
    showNavigation();
    LeoHomePage *homePage = new LeoHomePage(this);
    m_centerWidget->addFunWidget(LeoTool_homePage, "首页", homePage);
}

void QLeoTool::closeWidget()
{
    qApp->quit();
}

void QLeoTool::homePageWidget()
{
    if(m_centerWidget->isFunWidgetExist(LeoTool_homePage))
    {
        m_centerWidget->addFunWidget(LeoTool_homePage);
    }
    else
    {
        m_centerWidget->addFunWidget(LeoTool_homePage, "首页", new LeoHomePage(this));
    }
}

void QLeoTool::showNavigation()
{
    if(m_centerWidget->m_navigationListView->isHidden())
    {
        m_centerWidget->m_navigationListView->show();
    }
    else
    {
        m_centerWidget->m_navigationListView->hide();
    }
}

void QLeoTool::navigationListViewClick(QModelIndex index)
{
    NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toULongLong();
//    qDebug() << "index:" << node->label;
    if(LeoTool_Init == node->num)
    {
        return;
    }
    if(m_centerWidget->isFunWidgetExist(node->num))
    {
        m_centerWidget->addFunWidget(node->num);
    }
    else
    {
        QWidget *wgt = new QWidget(this);
        switch(node->num)
        {
        case LeoTool_homePage:
        {
            wgt = new LeoHomePage(this);
            break;
        }
        case LeoTool_Battary:
        {
            wgt = new frmBattery(this);
            break;
        }
        case LeoTool_ButtonDefence:
        {
            wgt = new frmButtonDefence(this);
            break;
        }
        case LeoTool_ComTool:
        {
            wgt = new frmComTool(this);
            break;
        }
        case LeoTool_DeviceSizetable:
        {
            wgt = new frmDeviceSizeTable(this);
            break;
        }
        case LeoTool_FlatUi:
        {
            wgt = new frmFlatUI(this);
            break;
        }
        case LeoTool_imageSwitch:
        {
            wgt = new frmImageSwitch(this);
            break;
        }
        case LeoTool_IpAdress:
        {
            wgt = new frmIPAddress(this);
            break;
        }
        case LeoTool_MoveWidget:
        {
            wgt = new frmMoveWidget(this);
            break;
        }
        case LeoTool_LunarCalenarWidget:
        {
            wgt = new frmLunarCalendarWidget(this);
            break;
        }
        case LeoTool_NavButton:
        {
            wgt = new frmNavButton(this);
            break;
        }
        case LeoTool_NetTool:
        {
            wgt = new frmMain(this);
            break;
        }
        case LeoTool_PngTool:
        {
            wgt = new frmPngTool(this);
            break;
        }
        case LeoTool_QwtDemo:
        {
            wgt = new frmQwtDemo(this);
            break;
        }
        case LeoTool_VideoPanel:
        {
            wgt = new frmVideoPanel(this);
            break;
        }
        case LeoTool_LightButton:
        {
            wgt = new frmLightButton(this);
            break;
        }
        case LeoTool_2048Game:
        {
            wgt = new QGameBoard(this);
            break;
        }
        case LeoTool_AnimationButton:
        {
            wgt = new frmAnimationButton(this);
            break;
        }
        case LeoTool_BarRuler:
        {
            wgt = new frmBarRuler(this);
            break;
        }
        case LeoTool_BarVolume:
        {
            wgt = new frmBarVolume(this);
            break;
        }
        case LeoTool_Calculator:
        {
            wgt = new Calculator(this);
            break;
        }
        case LeoTool_CurveChart:
        {
            wgt = new frmCurveChart(this);
            break;
        }
        case LeoTool_LedNumber:
        {
            wgt = new frmLedNumber(this);
            break;
        }
        case LeoTool_RoundPlot:
        {
            wgt = new frmRoundPlot(this);
            break;
        }
        case LeoTool_AdsWidget:
        {
            wgt = new frmAdsWidget2(this);
            break;
        }
        case LeoTool_Mouse:
        {
            wgt = new frmMouse(this);
            break;
        }
        case LeoTool_RoundCircle:
        {
            wgt = new frmRoundCircle(this);
            break;
        }
        case LeoTool_DrawTextOnPath:
        {
            wgt = new frmDrawTextOnPath(this);
            break;
        }
        case LeoTool_RouletteDraw:
        {
            wgt = new frmRouletteDraw(this);
            break;
        }
        default:
            return;
        }
        m_centerWidget->addFunWidget(node->num, node->label, wgt);
    }
}

