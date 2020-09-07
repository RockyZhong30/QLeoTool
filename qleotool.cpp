#include <QApplication>
#include <QDebug>
#include "qleotool.h"
#include "maintopwidget.h"
#include "maincenterwidget.h"

#include "leohomepage.h"
#include "battery/frmbattery.h"
#include "buttondefence/frmbuttondefence.h"
#include "comtool/form/frmcomtool.h"

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
        default:
            return;
        }
        m_centerWidget->addFunWidget(node->num, name, wgt);
    }
}

