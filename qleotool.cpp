#include <QApplication>
#include <QDebug>
#include "qleotool.h"
#include "maintopwidget.h"
#include "maincenterwidget.h"

QLeoTool::QLeoTool(QWidget *parent)
    : ShadowWidget(parent)
{
    this->initUi();
    this->initConnect();
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
    Q_UNUSED(index);
}

