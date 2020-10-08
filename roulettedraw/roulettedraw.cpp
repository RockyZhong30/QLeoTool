#pragma execution_character_set("utf-8")

#include "roulettedraw.h"
#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"

RouletteDraw::RouletteDraw(QWidget *parent)
    : QWidget(parent)
    , m_rotation(0)
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    setMouseTracking(true);
}

RouletteDraw::~RouletteDraw()
{

}

void RouletteDraw::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    drawBg(&painter);
    drawPoint(&painter);
}

void RouletteDraw::mousePressEvent(QMouseEvent *event)
{
    if (qApp->mouseButtons() == Qt::LeftButton)
    {
        QRegion ellipseRegion(m_pointerRect, QRegion::Ellipse);
        if (ellipseRegion.contains(event->pos()))
        {
            int rotateRand = qrand() % 360 + 360 * 5;
            m_rotation = 0;
            QPropertyAnimation *animation = new QPropertyAnimation(this, "rotate");
            animation->setEasingCurve(QEasingCurve::OutCubic);
            animation->setDuration(5000);
            animation->setStartValue(0);
            animation->setEndValue(rotateRand);

            connect(animation, SIGNAL(finished()), this, SLOT(rotateFinished()));
            animation->start(QAbstractAnimation::DeleteWhenStopped);
        }

    }
}

void RouletteDraw::mouseMoveEvent(QMouseEvent *event)
{
    QRegion ellipseRegion(m_pointerRect, QRegion::Ellipse);
    if (ellipseRegion.contains(event->pos()))
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}

void RouletteDraw::drawBg(QPainter *painter)
{
    painter->save();
    //窗口宽、高
    int nWindowWidth = this->width();
    int nWindowHeight = this->height();
    //背景图
    QPixmap pixmap = QPixmap(":/roulettedraw/image/roulettedraw/back.png");
    //中心偏移至中心位置
    painter->translate(nWindowWidth / 2, nWindowHeight / 2);
    //旋转m_rotation角度
    painter->rotate(-1 * m_rotation);
    painter->drawPixmap(QRect(0 - pixmap.width() / 2, 0 - pixmap.height() / 2, pixmap.width(), pixmap.height()), pixmap);
    painter->restore();
}

void RouletteDraw::drawPoint(QPainter *painter)
{
    painter->save();
    //绘制方向指针
    int nWindowWidth = this->width();
    int nWindowHeight = this->height();
    QPixmap pointer = QPixmap(":/roulettedraw/image/roulettedraw/pointer.png");
    m_pointerRect = QRect((nWindowWidth - pointer.width()) / 2, (nWindowHeight - pointer.height() - 30) / 2, pointer.width(), pointer.height());
    painter->drawPixmap(m_pointerRect, pointer);
    painter->restore();
}

void RouletteDraw::rotateFinished()
{
    float rotation = m_rotation - 360 * 5;
    int currentIndex = 0;
    for (int index = 0; index < 16; index++)
    {
        rotation -= 22.5;
        if (rotation <= 0)
        {
            currentIndex = index;
            break;
        }
    }

//    QMessageBox msgBox;
//    QString message = QStringLiteral("恭喜您中奖：%1 ！").arg(currentIndex);
//    msgBox.setText(message);
//    msgBox.exec();
}

int RouletteDraw::getRotate() const
{
    return m_rotation;
}

void RouletteDraw::setRotate(int rotate)
{
    m_rotation = rotate;
    update();
}


