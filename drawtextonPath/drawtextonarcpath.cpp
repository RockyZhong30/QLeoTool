#include "drawtextonarcpath.h"

#include <QPainterPath>
#include <QPainter>
#include <QDebug>
#include <qmath.h>
#include <QImage>
#include <QPropertyAnimation>

#pragma execution_character_set("utf-8")

DrawtextonArcpath::DrawtextonArcpath(QWidget *parent)
	: QWidget(parent)
	, m_textColor(QColor("#FEA47F"))
	, m_rotation(0)
	, m_startAngle(0)
	, m_aniDurationTime(8000)
	, m_colorPointSize(12)
	, m_isRotate(false)
	, m_clockwise(true)
{
	m_rotateAni = new QPropertyAnimation(this, "");
	connect(m_rotateAni, &QPropertyAnimation::valueChanged, [this](const QVariant &value){
		m_rotation = value.toInt();
		update();
	});
	m_rotateAni->setLoopCount(-1);
	m_rotateAni->setEasingCurve(QEasingCurve::Linear);
}

DrawtextonArcpath::~DrawtextonArcpath()
{

}

QString DrawtextonArcpath::getDrawtext() const
{
	return m_text;
}

qreal DrawtextonArcpath::getStartAngle() const
{
	return m_startAngle;
}

QColor DrawtextonArcpath::getTextColor() const
{
	return m_textColor;
}

bool DrawtextonArcpath::getStartRotate() const
{
	return m_isRotate;
}

bool DrawtextonArcpath::getClockwise() const
{
	return m_clockwise;
}

int DrawtextonArcpath::getTextPointSize() const
{
	return m_colorPointSize;
}

void DrawtextonArcpath::setDrawTextonArcPath(const QString& text)
{
	m_text = text;
	updateTextPixmap();
}

void DrawtextonArcpath::setStartAngle(qreal startAngle)
{
	m_startAngle = startAngle;
	updateTextPixmap();
}

void DrawtextonArcpath::setTextColor(const QColor& color)
{
	m_textColor = color;
	updateTextPixmap();
}

void DrawtextonArcpath::setTextPointSize(int ponitsize)
{
	m_colorPointSize = ponitsize;
	updateTextPixmap();
}

void DrawtextonArcpath::setClockwise(bool clockwise)
{
	m_clockwise = clockwise;
	if (m_clockwise){
		m_rotateAni->setStartValue(0);
		m_rotateAni->setEndValue(360);
	}
	else{
		m_rotateAni->setStartValue(0);
		m_rotateAni->setEndValue(-360);
	}
	if (m_isRotate){
		m_rotateAni->stop();
		m_rotateAni->start();
	}
}

void DrawtextonArcpath::setStartRotate(bool startRotate)
{
	m_isRotate = startRotate;
	if (startRotate){
		m_rotateAni->setDuration(m_aniDurationTime);
		setClockwise(m_clockwise);
	}
	else{
		m_rotateAni->stop();
	}
}

void DrawtextonArcpath::setAnimationDurationTime(int msecs)
{
	m_rotateAni->setDuration(m_aniDurationTime);
	if (m_isRotate){
		m_rotateAni->stop();
		m_rotateAni->start();
	}
}

void DrawtextonArcpath::updateTextPixmap()
{
	QPixmap pixmap(this->width(), this->height());
	pixmap.fill(Qt::transparent);
	QString content = m_text;
	qreal q = m_startAngle;
	QPainter painter(&pixmap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::HighQualityAntialiasing | QPainter::SmoothPixmapTransform);
	painter.setPen(QPen(m_textColor, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(Qt::NoBrush);
	QFont font = painter.font();
	font.setFamily("Microsoft YaHei");
	font.setPointSize(m_colorPointSize);
	font.setWeight(60);
	painter.setFont(font);

	qreal xoffset = painter.fontMetrics().height();
	qreal yoffset = xoffset;
	qreal a = this->width() / 2.0 - xoffset;
	qreal b = this->height() / 2.0 - yoffset;


	painter.translate(xoffset, yoffset);
	painter.translate(a, b);
	painter.rotate(270);

	for (int i = 0; i < content.length(); i++)
	{
		qreal xpos = 0;
		qreal ypos = 0;

		if (q == 90 || q == 270){
			xpos = 0;
			ypos = -b;
		}
		else{
			xpos = 0;
			qreal angle = q * M_PI * 1.0 / 180;
			qreal tanValue = qTan(angle) * qTan(angle);
			qreal tmp = (1 + tanValue) * 1.0 / (qPow(b, 2) + qPow(a, 2) * tanValue);
			ypos = 0 - a * b * qSqrt(tmp);
		}

		painter.save();
		painter.rotate(q);
		const QChar&& charTxt = content.at(i);
		qreal l = painter.fontMetrics().width(charTxt) / 2.0;
		painter.drawText(QPointF(xpos - l, ypos), charTxt);
		painter.restore();
		q = q + (l * 360.0) / (M_PI * qAbs(ypos)) + 3;
	}

	m_pixmap = pixmap;
	update();
}

void DrawtextonArcpath::paintEvent(QPaintEvent *e)
{
	QWidget::paintEvent(e);
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

	const qreal iw = m_pixmap.width();
	const qreal ih = m_pixmap.height();
	const qreal wh = height();
	const qreal ww = width();

	painter.translate(ww / 2, wh / 2);
	painter.rotate(m_rotation);
	painter.translate(-iw / 2, -ih / 2);
	painter.drawPixmap(0, 0, m_pixmap);
}
