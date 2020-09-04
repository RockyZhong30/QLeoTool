#include "maintopwidget.h"
#include "common.h"

#include <QDebug>

MainTopWidget::MainTopWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initParameter();
    this->initUI();
    this->initConnect();
}

void MainTopWidget::initParameter()
{
    m_localPix = QPixmap(":/image/top_bg");
    m_logoPix = QPixmap(":/image/top_right");
}

void MainTopWidget::initUI()
{
    this->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_TOP_HEIGHT);

    m_topLeftFrame = new QFrame(this);
    m_topLeftFrame->setAttribute(Qt::WA_TranslucentBackground);
    m_topLeftFrame->move(0, 0);
    m_topRightFrame = new QFrame(this);
    m_topRightFrame->setAttribute(Qt::WA_TranslucentBackground);
    QHBoxLayout *menuHLayout = new QHBoxLayout();
    m_btnHome = new QPushButton(this);
    m_btnHome->setFixedSize(60, 24);
    m_btnHome->setCursor(QCursor(Qt::PointingHandCursor));
    m_btnHome->setObjectName("homeButton");
    m_btnHelp = new QPushButton(this);
    m_btnHelp->setFixedSize(60, 24);
    m_btnHelp->setObjectName("helpButton");
    m_btnHelp->setCursor(QCursor(Qt::PointingHandCursor));
    m_btnQuit = new QPushButton(this);
    m_btnQuit->setFixedSize(60, 24);
    m_btnQuit->setObjectName("quitButton");
    m_btnQuit->setCursor(QCursor(Qt::PointingHandCursor));
    menuHLayout->addWidget(m_btnHome);
    menuHLayout->addWidget(m_btnHelp);
    menuHLayout->addWidget(m_btnQuit);
    menuHLayout->setContentsMargins(20, 10, 0, 10);
    menuHLayout->setSpacing(20);
    menuHLayout->addStretch();

    QHBoxLayout *NavigationHLayout = new QHBoxLayout();
    m_navigationLabel = new QLabel(this);
    m_navigationLabel->setObjectName("navigationLabel");
    m_navigationLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_btnNavigation = new QPushButton(this);
    m_btnNavigation->setFixedSize(220, 30);
    m_btnNavigation->setCursor(QCursor(Qt::PointingHandCursor));
    m_btnNavigation->setObjectName("navigationButton");
    NavigationHLayout->addWidget(m_btnNavigation);
    NavigationHLayout->addWidget(m_navigationLabel);
    NavigationHLayout->setContentsMargins(0, 3, 0, 0);
    NavigationHLayout->setSpacing(30);

    QVBoxLayout *topLefetVLyout = new QVBoxLayout();
    topLefetVLyout->addLayout(menuHLayout);
    topLefetVLyout->addLayout(NavigationHLayout);

    m_topLeftFrame->setLayout(topLefetVLyout);


    QHBoxLayout *topRightLayout = new QHBoxLayout();
    m_logoLabel = new QLabel(this);
    QSpacerItem *horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    m_logoLabel->setScaledContents(true);
    topRightLayout->addItem(horizontalSpacer);
    topRightLayout->addWidget(m_logoLabel);
    topRightLayout->setContentsMargins(0, 0, 0, 0);
    topRightLayout->setStretch(0, 1);
    topRightLayout->setStretch(1, 1);

    m_topRightFrame->setLayout(topRightLayout);


    QHBoxLayout *topHLayout = new QHBoxLayout();
    topHLayout->addWidget(m_topLeftFrame);
    topHLayout->addWidget(m_topRightFrame);
    topHLayout->setContentsMargins(0, 0, 0, 0);
    topHLayout->setSpacing(0);
    topHLayout->setStretchFactor(m_topLeftFrame, 3);
    topHLayout->setStretchFactor(m_topRightFrame, 1);
    this->setLayout(topHLayout);

//    m_QrcodePix = GlobalVar::createQRCode(GlobalVar::gCpuSerialNum);
}


void MainTopWidget::initConnect()
{
    connect(m_btnNavigation, &QPushButton::clicked, this, &MainTopWidget::showNavigation);
    connect(m_btnQuit, &QPushButton::clicked, this, &MainTopWidget::closeWidget);
}

void MainTopWidget::setLabelNavigation(QString name)
{
    m_navigationLabel->setText(name);
}

void MainTopWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_topLeftFrame->rect().width(), m_topLeftFrame->rect().height(), m_localPix, 0, 0, m_localPix.width(), m_localPix.height());
    painter.drawPixmap(m_topRightFrame->pos().x(), m_topRightFrame->pos().y(), m_topRightFrame->rect().width(), m_topRightFrame->rect().height(), m_logoPix, 0, 0, m_logoPix.width(), m_logoPix.height());

//    m_QrcodePix = m_QrcodePix.scaled(QSize(m_logoLabel->rect().width()*0.7, m_logoLabel->rect().height()*0.7));
//    m_logoLabel->setAlignment(Qt::AlignCenter);
//    m_logoLabel->setPixmap(m_QrcodePix);
}

void MainTopWidget::resizeEvent(QResizeEvent *)
{

}

