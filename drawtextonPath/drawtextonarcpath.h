#ifndef DRAWTEXTONPATH_H
#define DRAWTEXTONPATH_H

/**
* 弧形文本 作者:雨田哥(QQ:3246214072) 2019-04-29 http://www.qtcn.org/bbs/read-htm-tid-85602.html
*1. 弧形文字
*2. 自定义圆弧大小
*3. 自定义文字起始角度设置
*4. 滚动圆弧字体(顺时针，逆时针)
*5. 自定义文本颜色，大小设置
*/

#include <QWidget>

class QPropertyAnimation;

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT DrawtextonArcpath : public QWidget
#else
class DrawtextonArcpath : public QWidget
#endif
{
	Q_OBJECT
	Q_PROPERTY(QString drawText   READ getDrawtext      WRITE setDrawTextonArcPath)
	Q_PROPERTY(qreal   startAngle READ getStartAngle    WRITE setStartAngle)
	Q_PROPERTY(QColor textColor   READ getTextColor     WRITE setTextColor)
	Q_PROPERTY(int textPointSize  READ getTextPointSize WRITE setTextPointSize)
	Q_PROPERTY(bool startRotate   READ getStartRotate   WRITE setStartRotate)
	Q_PROPERTY(bool clockwise     READ getClockwise     WRITE setClockwise)

public:
	DrawtextonArcpath(QWidget *parent = 0);
	~DrawtextonArcpath();

public:
	QString getDrawtext()      const;
	qreal   getStartAngle()    const;
	QColor  getTextColor()     const;
	int     getTextPointSize() const;
	bool    getStartRotate()   const;
	bool    getClockwise()     const;

public:
	void setAnimationDurationTime(int msecs);		//设置旋转一圈时长

public slots:
	void setDrawTextonArcPath(const QString& text);	//设置弧形文本
	void setStartAngle(qreal startAngle);		    //设置起始角度
	void setTextColor(const QColor& color);		    //设置文本颜色
	void setTextPointSize(int ponitsize);		    //设置字体大小
	void setStartRotate(bool startRotate);			//是否旋转
	void setClockwise(bool clockwise);				//是否顺时针旋转

private:
	void updateTextPixmap();	//更新弧形图像

protected:
	void paintEvent(QPaintEvent *e);

private:	
	bool    m_isRotate;			// 是否旋转
	bool    m_clockwise;		// true顺时针旋转 false逆时针旋转
	int     m_colorPointSize;	// 弧形字体大小
	int     m_aniDurationTime;	// 旋转一圈时间
	qreal   m_rotation;			// 旋转角度
	qreal   m_startAngle;		// 起始角度
	QColor  m_textColor;		// 字体颜色	
	QPixmap m_pixmap;			// 弧形图像
	QString m_text;				// 弧形文本
	QPropertyAnimation* m_rotateAni;

};
#endif // DRAWTEXTONPATH_H
