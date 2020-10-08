#include "frmdrawtextonpath.h"

#include <QStyleOption>
#include <QPainter>
#pragma execution_character_set("utf-8")

frmDrawTextOnPath::frmDrawTextOnPath(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);

    ui.widget_5->setDrawTextonArcPath("你是九月的南方   浪花拍过烈日暴晒过的沙漠   你是忽然大雨瓢泼 带着我的向往");
	ui.widget_5->setStartAngle(0);
	ui.widget_5->setAnimationDurationTime(5000);
	ui.widget_5->setStartRotate(true);

	ui.widget->setTextColor(QColor("#9AECDB"));
	ui.widget->setTextPointSize(16);
    ui.widget->setDrawTextonArcPath("怎么大风越狠     宛如一丝尘土  随风自由的在狂舞");
	ui.widget->setAnimationDurationTime(10000);
	ui.widget->setStartRotate(true);

//	ui.widget_6->setTextColor(QColor("#FD7272"));
//	ui.widget_6->setTextPointSize(20);
//    ui.widget_6->setDrawTextonArcPath("夏天白昼明治的红豆     一口沁甜了倦意感受");
//	ui.widget_6->setAnimationDurationTime(15000);
//	ui.widget_6->setStartRotate(true);

	ui.widget_4->setTextColor(QColor("#F97F51"));
    ui.widget_4->setTextPointSize(12);
    ui.widget_4->setDrawTextonArcPath("我们不去歌唱生活的理想  天青色等烟雨");
	ui.widget_4->setStartAngle(270);
    ui.widget_4->setStartRotate(true);


	ui.widget_3->setTextColor(QColor("#D6A2E8"));
	ui.widget_3->setTextPointSize(14);
    ui.widget_3->setDrawTextonArcPath("再落这尘土的路边数着票子 在寒冷冷的雾气中   点燃一支香烟");
	ui.widget_3->setAnimationDurationTime(10000);
	ui.widget_3->setClockwise(false);
	ui.widget_3->setStartRotate(true);

//	ui.widget_7->setTextColor(QColor("#BDC581"));
//    ui.widget_7->setTextPointSize(12);
//    ui.widget_7->setDrawTextonArcPath("早晨的油锅冒着热气  卖油条的人们和我轻声交谈");
//	ui.widget_7->setStartAngle(90);
//    ui.widget_7->setStartRotate(true);

//	ui.widget_2->setTextColor(QColor("#B53471"));
//	ui.widget_2->setTextPointSize(16);
//    ui.widget_2->setDrawTextonArcPath("666 Fuck Fuck Fuck");
//	ui.widget_2->setAnimationDurationTime(10000);
//	ui.widget_2->setClockwise(false);
//	ui.widget_2->setStartRotate(true);

	ui.widget_8->setTextColor(QColor("#0652DD"));
	ui.widget_8->setTextPointSize(16);
    ui.widget_8->setDrawTextonArcPath("666 666 666 666 666");
	ui.widget_8->setAnimationDurationTime(10000);
	ui.widget_8->setStartRotate(true);
}

frmDrawTextOnPath::~frmDrawTextOnPath()
{

}

void frmDrawTextOnPath::paintEvent(QPaintEvent *e)
{
	QWidget::paintEvent(e);
	// 背景图
	QPainter p(this);
	p.fillRect(this->rect(), QColor("#182C61"));
}
