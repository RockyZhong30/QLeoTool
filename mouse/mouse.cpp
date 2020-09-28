#include "mouse.h"
#include "qpainter.h"
#include "qdebug.h"

Mouse::Mouse(QWidget *parent) : QWidget(parent)
{

}

void Mouse::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width / 2, height / 2);
    painter.scale(side / 100.0, side / 100.0);

    //绘制椭圆身体
    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(-10, -20, 20, 40);

    //绘制圆形眼睛
    painter.setBrush(Qt::white);
    painter.drawEllipse(-10, -17, 8, 8);
    painter.drawEllipse(2, -17, 8, 8);

    //绘制鼻子
    painter.setBrush(Qt::black);
    painter.drawEllipse(QRectF(-2, -22, 4, 4));

    //绘制两个眼珠
    painter.drawEllipse(QRectF(-8.0, -17, 4, 4));
    painter.drawEllipse(QRectF(4.0, -17, 4, 4));

    //绘制圆形大耳朵
    painter.setBrush(Qt::darkYellow);
    painter.drawEllipse(-17, -12, 16, 16);
    painter.drawEllipse(1, -12, 16, 16);

    //绘制尾巴
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(path);
}
