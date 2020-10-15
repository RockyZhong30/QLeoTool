#ifndef RADARMETERWIDGET_H
#define RADARMETERWIDGET_H

#include <QWidget>

class RadarMeterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadarMeterWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void timerEvent(QTimerEvent *event);

private:
    QRect m_drawArea;
    int m_pieRotate, m_timerId, m_pointTimerId, m_nSpeed;
    QList<QPoint> m_points;
    QList<int> m_pointsAlapha;
};

#endif // RADARMETERWIDGET_H
