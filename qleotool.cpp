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
    connect(m_topWidget, SIGNAL(closeWidget()), this, SLOT(closeWidget()));
    connect(m_topWidget, SIGNAL(showNavigation()), this, SLOT(showNavigation()));
}

void QLeoTool::closeWidget()
{
    qDebug() << "-----------------111111111111111---------------";
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

