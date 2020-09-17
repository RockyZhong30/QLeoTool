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
//    qDebug() << "index:" << node->num;
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
        QString name;
        switch(node->num)
        {
        case LeoTool_homePage:
        {
            wgt = new LeoHomePage(this);
            name = "首页";
            break;
        }
        case LeoTool_Battary:
        {
            wgt = new frmBattery(this);
            name = "电池电量控件";
            break;
        }
        case LeoTool_ButtonDefence:
        {
            wgt = new frmButtonDefence(this);
            name = "通用按钮地图效果";
            break;
        }
        case LeoTool_ComTool:
        {
            wgt = new frmComTool(this);
            name = "串口调试助手";
            break;
        }
        case LeoTool_DeviceSizetable:
        {
            wgt = new frmDeviceSizeTable(this);
            name = "硬盘容量控件";
            break;
        }
        case LeoTool_FlatUi:
        {
            wgt = new frmFlatUI(this);
            name = "FlatUI控件集合";
            break;
        }
        case LeoTool_imageSwitch:
        {
            wgt = new frmImageSwitch(this);
            name = "图片开关控件";
            break;
        }
        case LeoTool_IpAdress:
        {
            wgt = new frmIPAddress(this);
            name = "IP地址输入控件";
            break;
        }
        case LeoTool_MoveWidget:
        {
            wgt = new frmMoveWidget(this);
            name = "通用控件移动类";
            break;
        }
        case LeoTool_LunarCalenarWidget:
        {
            wgt = new frmLunarCalendarWidget(this);
            name = "农历控件";
            break;
        }
        case LeoTool_NavButton:
        {
            wgt = new frmNavButton(this);
            name = "导航按钮控件";
            break;
        }
        case LeoTool_NetTool:
        {
            wgt = new frmMain(this);
            name = "网络中转服务器";
            break;
        }
        case LeoTool_PngTool:
        {
            wgt = new frmPngTool(this);
            name = "PNG图片警告去除工具";
            break;
        }
        case LeoTool_QwtDemo:
        {
            wgt = new frmQwtDemo(this);
            name = "qwt demo";
            break;
        }
        case LeoTool_VideoPanel:
        {
            wgt = new frmVideoPanel(this);
            name = "视频监控画面分割";
            break;
        }
        case LeoTool_LightButton:
        {
            wgt = new frmLightButton(this);
            name = "高亮按钮控件";
            break;
        }
        case LeoTool_2048Game:
        {
            wgt = new QGameBoard(this);
            name = "2048";
            break;
        }
        case LeoTool_AnimationButton:
        {
            wgt = new frmAnimationButton(this);
            name = "Animation动态按钮";
            break;
        }
        case LeoTool_BarRuler:
        {
            wgt = new frmBarRuler(this);
            name = "柱状标尺控件";
            break;
        }
        case LeoTool_Calculator:
        {
            wgt = new Calculator(this);
            name = "计算器";
            break;
        }
        default:
            return;
        }
        m_centerWidget->addFunWidget(node->num, name, wgt);
    }
}

