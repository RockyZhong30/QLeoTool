#ifndef TIMEMETERWIDGET_H
#define TIMEMETERWIDGET_H

#include <QWidget>

class TimeMeterWidget : public QWidget
{
public:
    explicit TimeMeterWidget(QWidget *parent = 0);

    void setValue(qreal value);
    qreal value() const { return m_value;}

protected:
    virtual void paintEvent(QPaintEvent *event);

    void drawCrown(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);

    bool m_numericIndicatorEnabled;
    QColor m_foreground, m_background;
    QString m_units, m_title;
    int m_scaleMajor, m_scaleMinor;
    int m_maxValue, m_minValue;
    int m_startAngle,m_endAngle;
    double m_value;
    int m_precision;
};

#endif // TIMEMETERWIDGET_H
