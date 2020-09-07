#include "leohomepage.h"
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QPainter>

LeoHomePage::LeoHomePage(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initUi();
    this->initConnect();
}

LeoHomePage::~LeoHomePage()
{
}

void LeoHomePage::initUi()
{
    m_bgPix = QPixmap(":/image/bear");
    QLabel* labelText = new QLabel();
    labelText->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    QString text;
    text = readFile(":/html/aboutHtml");
    labelText->setText(text);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addStretch();
    layout->addWidget(labelText);
    this->setLayout(layout);
}

void LeoHomePage::initConnect()
{

}

QString LeoHomePage::readFile(const QString filename)
{
    QFile f(filename);
    if(!f.open(QFile::ReadOnly | QFile::Text))
    {
        return QString();
    }
    else
    {
        QTextStream in(&f);
        return in.readAll();
    }
}

void LeoHomePage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->rect().width(), this->rect().height(), m_bgPix, 0, 0, m_bgPix.width(), m_bgPix.height());
}

