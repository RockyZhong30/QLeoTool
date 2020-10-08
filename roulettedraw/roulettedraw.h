#ifndef ROULETTEDRAW_H
#define ROULETTEDRAW_H

/**
 * 轮盘抽奖控件
 */

#include <QWidget>
#include <QApplication>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QTime>
#include <QMessageBox>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT RouletteDraw : public QWidget
#else
class RouletteDraw : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(int rotate READ getRotate WRITE setRotate)

public:
    explicit RouletteDraw(QWidget *parent = 0);
    ~RouletteDraw();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void drawBg(QPainter *painter);
    void drawPoint(QPainter *painter);

private:
    int m_rotation;                 //旋转角度
    QRect m_pointerRect;

private slots:

public:
    int getRotate()                const;

public Q_SLOTS:
    void rotateFinished();

    void setRotate(int rotate);
};

#endif // ROULETTEDRAW_H
