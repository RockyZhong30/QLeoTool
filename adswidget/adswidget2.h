#ifndef ADSWIDGET2_H
#define ADSWIDGET2_H

/**
 * 广告轮播控件2 作者:feiyangqingyun(QQ:517216493) 2018-9-12
 * 参考雨田哥(QQ:3246214072) https://blog.csdn.net/ly305750665/article/details/82496046
 * 1:可设置显示的图像集合
 * 2:可设置提示信息集合
 * 3:可设置指示器最小宽度和最大宽度
 * 4:可设置图片切换间隔
 * 5:可设置指示器颜色和提示文字颜色
 * 6:可设置指示器高度
 * 7:可设置指示器显示序号
 */

#include <QWidget>

class QLabel;
class QParallelAnimationGroup;
class QPropertyAnimation;

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT AdsWidget2 : public QWidget
#else
class AdsWidget2 : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(bool showNumber READ getShowNumber WRITE setShowNumber)
    Q_PROPERTY(int minHeight READ getMinHeight WRITE setMinHeight)
    Q_PROPERTY(int minWidth READ getMinWidth WRITE setMinWidth)
    Q_PROPERTY(int maxWidth READ getMaxWidth WRITE setMaxWidth)
    Q_PROPERTY(int interval READ getInterval WRITE setInterval)    
    Q_PROPERTY(int navRadius READ getNavRadius WRITE setNavRadius)

    Q_PROPERTY(QColor navColor READ getNavColor WRITE setNavColor)    
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor tipColor READ getTipColor WRITE setTipColor)
    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)

    Q_PROPERTY(QString imageNames READ getImageNames WRITE setImageNames)
    Q_PROPERTY(QString imageTips READ getImageTips WRITE setImageTips)

public:
    AdsWidget2(QWidget *parent = 0);
    ~AdsWidget2();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);

private:
    bool showNumber;        //是否显示序号
    int minHeight;          //指示器最小高度
    int minWidth;           //指示器最小拉伸宽度
    int maxWidth;           //指示器最大拉伸宽度
    int interval;           //图片切换间隔,单位毫秒    
    int navRadius;          //指示器圆角角度

    QColor navColor;        //指示器颜色    
    QColor textColor;       //指示器文字颜色
    QColor tipColor;        //提示文字颜色
    QColor darkColor;       //当前指示器加深颜色

    QString imageNames;     //图片名称
    QString imageTips;      //提示信息

    QList<QString> names;   //图片名称集合
    QList<QString> tips;    //提示信息集合
    QList<QLabel *> labs;   //存储指示器集合

    bool leftToRight;       //从左往右切换
    int offset;             //图片切换偏移量
    int currentIndex;       //当前图片索引
    int previousIndex;      //上一张图片索引
    QTimer *timer;          //定时器切换

    QWidget *widgetBg;      //存放广告图片的容器
    QWidget *widgetBanner;  //存放导航指示器的容器

    //动画切换
    QParallelAnimationGroup *animationGroup;
    QPropertyAnimation *animationImage;
    QPropertyAnimation *animationMin;
    QPropertyAnimation *animationMax;

private slots:
    void initWidget();
    void initForm();
    void changedAds();
    void changedAds(QLabel *lab);
    void changedImage(const QVariant &);
    void changedMin(const QVariant &);
    void changedMax(const QVariant &);

public:
    bool getShowNumber()        const;
    int getMinHeight()          const;
    int getMinWidth()           const;
    int getMaxWidth()           const;
    int getInterval()           const;    
    int getNavRadius()          const;

    QColor getNavColor()        const;    
    QColor getTextColor()       const;
    QColor getTipColor()        const;
    QColor getDarkColor()       const;

    QString getImageNames()     const;
    QString getImageTips()      const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置是否显示序号
    void setShowNumber(bool showNumber);
    //设置指示器高度
    void setMinHeight(int minHeight);
    //设置最小拉伸宽度
    void setMinWidth(int minWidth);
    //设置最大拉伸宽度
    void setMaxWidth(int maxWidth);
    //设置切换间隔
    void setInterval(int interval);    
    //设置指示器圆角角度
    void setNavRadius(int navRadius);

    //设置指示器颜色
    void setNavColor(const QColor &navColor);
    //设置指示器文字颜色
    void setTextColor(const QColor &textColor);
    //设置提示信息颜色
    void setTipColor(const QColor &tipColor);
    //设置加深颜色
    void setDarkColor(const QColor &darkColor);

    //设置图片名称
    void setImageNames(const QString &imageNames);
    //设置提示信息
    void setImageTips(const QString &imageTips);
};

#endif // ADSWIDGET2_H
