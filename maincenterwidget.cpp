#include "maincenterwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QStackedLayout>
#include <QVBoxLayout>
#include "common.h"

MainCenterWidget::MainCenterWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initParameter();
    this->initUI();
    this->initAnimation();
    this->initConnect();
}

void MainCenterWidget::initParameter()
{
    m_centerPix = QPixmap(":/image/center_bg");
}

void MainCenterWidget::initUI()
{
    this->setGeometry(0, SCREEN_TOP_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT-SCREEN_TOP_HEIGHT);
    QHBoxLayout *centerHLayout = new QHBoxLayout();
    m_centerWidget = new QTabWidget(this);
    m_centerWidget->setTabPosition(QTabWidget::South);
    m_centerWidget->setIconSize(QSize(28, 28));
    m_centerWidget->setElideMode(Qt::ElideNone);
    m_centerWidget->setDocumentMode(false);
    m_centerWidget->setTabsClosable(true);

    m_navigationListView = new NavListView(this);
    m_navigationListView->readData(":/xml/toolXml");
    m_navigationListView->setIcoColorBg(false);
//    m_navigationListView->setColorLine(QColor(32, 53, 74));
//    m_navigationListView->setColorBg(QColor(52, 73, 94), QColor(24, 189, 155), QColor(24, 189, 155, 150));
//    m_navigationListView->setColorText(QColor(254, 255, 255), QColor(252, 252, 252), QColor(0, 0, 0));

    centerHLayout->addWidget(m_navigationListView);
    centerHLayout->addWidget(m_centerWidget);
    centerHLayout->setStretchFactor(m_navigationListView, 1);
    centerHLayout->setStretchFactor(m_centerWidget, 3);
    centerHLayout->setSpacing(0);
    centerHLayout->setContentsMargins(0, 0, 0, 0);
    m_navigationListView->hide();

    this->setLayout(centerHLayout);
}

void MainCenterWidget::initAnimation()
{


}

void MainCenterWidget::initConnect()
{
    connect(m_navigationListView, SIGNAL(pressed(QModelIndex)), this, SIGNAL(listViewPress(QModelIndex)));
    connect(m_centerWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequested(int)));
    connect(m_centerWidget, SIGNAL(currentChanged(int)), this, SLOT(tabCurrentChanged(int)));
}

void MainCenterWidget::addFunWidget(QString name, int number, QWidget *wgt)
{
    for(int i = 0; i < m_lstTabWidgetIndex.count(); i++)
    {
        if(m_lstTabWidgetIndex.at(i).name == name)
        {
            m_centerWidget->setCurrentWidget(m_lstTabWidgetIndex.at(i).wgt);
            m_centerWidget->setTabText(m_centerWidget->currentIndex(), m_lstTabWidgetIndex.at(i).name);
            return;
        }
    }

    int index = m_centerWidget->addTab(wgt, QIcon(":/image/application"), name);
    m_centerWidget->setCurrentIndex(index);

    stuTab tab;
    tab.name = name;
    tab.number = number;
    tab.wgt = wgt;
    m_lstTabWidgetIndex.append(tab);
}

bool MainCenterWidget::isFunWidgetExist(int number)
{
    for(int i = 0; i < m_lstTabWidgetIndex.count(); i++)
    {
        if(number == m_lstTabWidgetIndex.at(i).number)
        {
            return true;
        }
    }

    return false;
}

void MainCenterWidget::tabCloseRequested(int index)
{
    for(int i = 0; i < m_lstTabWidgetIndex.count(); i++)
    {
        if(m_lstTabWidgetIndex.at(i).name == m_centerWidget->tabText(index))
        {
            QWidget *wgt = m_lstTabWidgetIndex.at(i).wgt;
            for(int j = 0; j < m_lstTabWidgetIndex.count();)
            {
                if(m_lstTabWidgetIndex.at(j).wgt == wgt)
                    m_lstTabWidgetIndex.removeAt(j);
                else
                    j++;
            }
            break;
        }
    }

    m_centerWidget->removeTab(index);
    emit hideNavListView("");
}

void MainCenterWidget::tabCurrentChanged(int index)
{
    m_centerWidget->setCurrentIndex(index);

    for(int i = 0; i < m_lstTabWidgetIndex.count(); i++)
    {
        if(m_lstTabWidgetIndex.at(i).name == m_centerWidget->tabText(index))
        {
            emit hideNavListView(m_lstTabWidgetIndex.at(i).name);
            break;
        }
    }
}

void MainCenterWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(m_centerWidget->pos().x(), m_centerWidget->pos().y(), m_centerWidget->rect().width(), m_centerWidget->rect().height(), m_centerPix, 0, 0, m_centerPix.width(), m_centerPix.height());
}

