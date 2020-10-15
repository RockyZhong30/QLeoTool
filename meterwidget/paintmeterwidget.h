#ifndef PAINTMETERWIDGET_H
#define PAINTMETERWIDGET_H

#include <QWidget>

class PaintMeterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintMeterWidget(QWidget *parent = 0);

    void setThreshold(double value);
    void setValue(double value);

protected:
    void thresholdManager();
    virtual void paintEvent(QPaintEvent *event);

private:
    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawTicks(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawUnits(QPainter *painter);
    void drawNeedle(QPainter *painter);
    void drawThresholdLine(QPainter *painter);
    void drawNumericValue(QPainter *painter);
    void drawCoverGlass(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawValidWindow(QPainter *painter);
    void drawWarningWindow(QPainter *painter);

    double m_value, m_maxValue, m_minValue;
    int m_precision, m_precisionNumeric;
    QString m_units, m_label;
    int m_steps;
    double m_startAngle, m_endAngle, m_threshold;
    bool m_thresholdFlag, m_enableValidWindow;
    double m_beginValidValue, m_endValidValue;
    bool m_enableWarningWindow;
    double m_beginWarningValue, m_endWarningValue;
    bool m_thresholdEnabled, m_numericIndicatorEnabled;
    QColor m_foreground, m_background;
};

#endif // PAINTMETERWIDGET_H
