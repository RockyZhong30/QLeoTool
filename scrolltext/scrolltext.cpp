#include "scrolltext.h"

#include <QPainter>
#include <QDebug>

ScrollText::ScrollText(QWidget *parent)
    : QWidget(parent)
    , m_scrollText("Copyright 2020-2022 ZHB.")
    , m_timerId(0)
    , m_offset(0)
    , m_directionR2L(true)
{
    setScrollText(m_scrollText);
}

ScrollText::~ScrollText()
{

}

QString ScrollText::getScrollText() const
{
    return this->m_scrollText;
}

void ScrollText::setScrollText(const QString &text)
{
    int length = fontMetrics().width(text);
    length = (length >= width()) ? 50 : 30;
    this->m_scrollText = text.leftJustified(length, ' ');

    update();
    updateGeometry();
}

bool ScrollText::getDirectionR2L() const
{
    return this->m_directionR2L;
}

void ScrollText::setDirectionR2L(const bool &r2l)
{
    this->m_directionR2L = r2l;
    update();
}

QSize ScrollText::sizeHint() const
{
    return fontMetrics().size(0, m_scrollText);
}

void ScrollText::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    QFont f(font());
    f.setBold(false);
    painter.setFont(f);

    int textWidth = fontMetrics().width(m_scrollText);
    if(textWidth < 1)
    {
        return;
    }
    if(m_directionR2L)
    {
        int x = m_offset-textWidth;
        while(x < width())
        {
            painter.drawText(x, 0, textWidth, height(),
                             Qt::AlignLeft | Qt::AlignVCenter, m_scrollText);
            x += textWidth;
        }
    }
    else
    {
        int x = -m_offset;
        while(x < width())
        {
            painter.drawText(x, 0, textWidth, height(),
                             Qt::AlignLeft | Qt::AlignVCenter, m_scrollText);
            x += textWidth;
        }
    }
    painter.end();
}

void ScrollText::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    m_timerId = startTimer(30);
}

void ScrollText::hideEvent(QHideEvent *event)
{
    QWidget::hideEvent(event);
    killTimer(m_timerId);
    m_timerId = 0;
}

void ScrollText::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_timerId)
    {
        ++m_offset;
        if (m_offset >= fontMetrics().width(m_scrollText))
        {
            m_offset = 0;
        }
        scroll(-1, 0);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}
