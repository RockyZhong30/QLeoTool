#pragma execution_character_set("utf-8")

#include "adswidget2.h"
#include "qpainter.h"
#include "qevent.h"
#include "qlabel.h"
#include "qlayout.h"
#include "qpropertyanimation.h"
#include "qsequentialanimationgroup.h"
#include "qparallelanimationgroup.h"
#include "qtimer.h"
#include "qdebug.h"

AdsWidget2::AdsWidget2(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
}

AdsWidget2::~AdsWidget2()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

bool AdsWidget2::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (obj->inherits("QLabel")) {
            //先停止定时器,防止按下切换的时候短时间内再度切换
            timer->stop();
            changedAds((QLabel *)obj);
            timer->start(interval);
        }
    }

    return QWidget::eventFilter(obj, event);
}

void AdsWidget2::showEvent(QShowEvent *)
{    
    animationImage->setStartValue(0);
    animationImage->setEndValue(width());
    animationMax->setStartValue(maxWidth);
    animationMax->setEndValue(minWidth);
    animationMin->setStartValue(minWidth);
    animationMin->setEndValue(maxWidth);
    animationGroup->start();

    //立即设置当前指示器
    if (names.count() > 0) {
        changedAds(labs.at(0));
    }
}

void AdsWidget2::paintEvent(QPaintEvent *)
{
    if (names.count() == 0) {
        return;
    }

    int width = this->width();
    int height = this->height();

    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
    painter.setPen(tipColor);

    //设置字体
    QFont font;
    font.setPixelSize(15);
    painter.setFont(font);

    //取出上一张图片+当前图片,并平滑缩放
    QPixmap previousPix(names.at(previousIndex));
    QPixmap currentPix(names.at(currentIndex));
    previousPix = previousPix.scaled(width, height, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    currentPix = currentPix.scaled(width, height, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    int widthOffset = offset + width;
    if (leftToRight) {
        widthOffset = offset - width;
    }

    //绘制上一张图片
    painter.drawPixmap(offset, 0, previousPix);
    //绘制当前图片
    painter.drawPixmap(widthOffset, 0, currentPix);

    //绘制上一张图片提示信息,有可能上一张图片提示信息为空
    if (previousIndex <= tips.count() - 1) {
        painter.drawText(QRect(offset + 10, height - minHeight - 40, width - 20, 30), tips.at(previousIndex), option);
    }

    //绘制当前图片提示信息,有可能当前图片提示信息为空
    if (currentIndex <= tips.count() - 1) {
        painter.drawText(QRect(widthOffset + 10, height - minHeight - 40, width - 20, 30), tips.at(currentIndex), option);
    }
}

void AdsWidget2::initWidget()
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    widgetBg = new QWidget(this);
    widgetBg->setObjectName(QString::fromUtf8("widgetBg"));

    QGridLayout *gridLayout = new QGridLayout(widgetBg);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    QSpacerItem *verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

    widgetBanner = new QWidget(widgetBg);
    widgetBanner->setObjectName(QString::fromUtf8("widgetBanner"));

    QHBoxLayout *horizontalLayout = new QHBoxLayout(widgetBanner);
    horizontalLayout->setSpacing(3);
    gridLayout->addWidget(widgetBanner, 1, 0, 1, 1);

    QSpacerItem *horizontalSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);
    verticalLayout->addWidget(widgetBg);
}

void AdsWidget2::initForm()
{
    showNumber = false;
    minHeight = 6;
    minWidth = 6;
    maxWidth = 25;
    interval = 3000;
    navRadius = 3;

    navColor = QColor(220, 220, 220);
    textColor = QColor(20, 20, 20);
    tipColor = QColor(255, 255, 255);
    darkColor = QColor(255, 255, 255);

    imageNames.clear();
    imageTips.clear();

    leftToRight = true;
    offset = 0;
    currentIndex = 0;
    previousIndex = 0;

    //定时器切换图片
    timer = new QTimer(this);
    timer->setInterval(interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(changedAds()));
    timer->start();

    //定义动画组
    animationGroup = new QParallelAnimationGroup(this);

    //定义动画切换图片
    animationImage = new QPropertyAnimation(this, "");
    connect(animationImage, SIGNAL(valueChanged(const QVariant &)), this, SLOT(changedImage(const QVariant &)));
    animationImage->setEasingCurve(QEasingCurve::OutCirc);
    animationImage->setDuration(800);
    animationGroup->addAnimation(animationImage);

    QSequentialAnimationGroup *sequentialGroup = new QSequentialAnimationGroup(animationGroup);

    //用于切换最小拉伸宽度
    animationMin = new QPropertyAnimation(sequentialGroup, "");
    connect(animationMin, SIGNAL(valueChanged(const QVariant &)), this, SLOT(changedMin(const QVariant &)));
    animationMin->setEasingCurve(QEasingCurve::OutCubic);
    animationMin->setDuration(400);

    //用于切换最大拉伸宽度
    animationMax = new QPropertyAnimation(sequentialGroup, "");
    connect(animationMax, SIGNAL(valueChanged(const QVariant &)), this, SLOT(changedMax(const QVariant &)));
    animationMax->setEasingCurve(QEasingCurve::OutCubic);
    animationMax->setDuration(400);

    //按钮切换串行运行
    sequentialGroup->addAnimation(animationMin);
    sequentialGroup->addAnimation(animationMax);
    animationGroup->addAnimation(sequentialGroup);
}

void AdsWidget2::changedAds()
{
    if (names.count() == 0) {
        return;
    }

    previousIndex = currentIndex;
    if (currentIndex < names.count() - 1) {
        currentIndex++;
    } else {
        currentIndex = 0;
    }

    changedAds(labs.at(currentIndex));
}

void AdsWidget2::changedAds(QLabel *lab)
{
    int index = labs.indexOf(lab);

    //如果索引负数则取最后一张
    if (index < 0) {
        index = names.count() - 1;
    }

    //如果索引到了最大张数则取第一张
    if (index >= names.count()) {
        index = 0;
    }

    currentIndex = index;

    //图片切换,计算当前是否左滑右滑
    if (previousIndex < currentIndex) {
        animationImage->setStartValue(0);
        animationImage->setEndValue(0 - width());
        leftToRight = false;
    } else {
        animationImage->setStartValue(0);
        animationImage->setEndValue(width());
        leftToRight = true;
    }

    animationGroup->start();

    QString qss = QString("border:none;background:%1;color:%2;border-radius:%3px;")
            .arg(navColor.name()).arg(textColor.name()).arg(navRadius);
    QString qssCurrent = QString("border:none;background:%1;color:%2;border-radius:%3px;")
            .arg(darkColor.name()).arg(textColor.name()).arg(navRadius);

    //将当前指示器突出显示
    foreach (QLabel *currentLab, labs) {
        if (currentLab == lab) {
            currentLab->setStyleSheet(qssCurrent);
        } else {
            currentLab->setStyleSheet(qss);
        }
    }
}

void AdsWidget2::changedImage(const QVariant &variant)
{
    offset = variant.toInt();
    update();
}

void AdsWidget2::changedMin(const QVariant &variant)
{
    labs.at(currentIndex)->setFixedWidth(variant.toInt());
}

void AdsWidget2::changedMax(const QVariant &variant)
{
    //设置按钮最大宽度,产生动态拉伸效果
    for (int i = 0; i < names.count(); i++) {
        if (currentIndex != i && labs.at(i)->width() > minWidth) {
            labs.at(i)->setFixedWidth(variant.toInt());
        }
    }
}

bool AdsWidget2::getShowNumber() const
{
    return this->showNumber;
}

int AdsWidget2::getMinHeight() const
{
    return this->minHeight;
}

int AdsWidget2::getMinWidth() const
{
    return this->minWidth;
}

int AdsWidget2::getMaxWidth() const
{
    return this->maxWidth;
}

int AdsWidget2::getInterval() const
{
    return this->interval;
}

int AdsWidget2::getNavRadius() const
{
    return this->navRadius;
}

QColor AdsWidget2::getNavColor() const
{
    return this->navColor;
}

QColor AdsWidget2::getTextColor() const
{
    return this->textColor;
}

QColor AdsWidget2::getTipColor() const
{
    return this->tipColor;
}

QColor AdsWidget2::getDarkColor() const
{
    return this->darkColor;
}

QString AdsWidget2::getImageNames() const
{
    return this->imageNames;
}

QString AdsWidget2::getImageTips() const
{
    return this->imageTips;
}

QSize AdsWidget2::sizeHint() const
{
    return QSize(200, 150);
}

QSize AdsWidget2::minimumSizeHint() const
{
    return QSize(20, 15);
}

void AdsWidget2::setShowNumber(bool showNumber)
{
    if (this->showNumber != showNumber) {
        this->showNumber = showNumber;
        update();
    }
}

void AdsWidget2::setMinHeight(int minHeight)
{
    if (this->minHeight != minHeight) {
        this->minHeight = minHeight;
        update();
    }
}

void AdsWidget2::setMinWidth(int minWidth)
{
    if (this->minWidth != minWidth) {
        this->minWidth = minWidth;
        update();
    }
}

void AdsWidget2::setMaxWidth(int maxWidth)
{
    if (this->maxWidth != maxWidth) {
        this->maxWidth = maxWidth;
        update();
    }
}

void AdsWidget2::setInterval(int interval)
{
    if (this->interval != interval) {
        this->interval = interval;
        timer->setInterval(this->interval);
        update();
    }
}

void AdsWidget2::setNavRadius(int navRadius)
{
    if (this->navRadius != navRadius) {
        this->navRadius = navRadius;
        update();
    }
}

void AdsWidget2::setNavColor(const QColor &navColor)
{
    if (this->navColor != navColor) {
        this->navColor = navColor;
        update();
    }
}

void AdsWidget2::setTextColor(const QColor &textColor)
{
    if (this->textColor != textColor) {
        this->textColor = textColor;
        update();
    }
}

void AdsWidget2::setTipColor(const QColor &tipColor)
{
    if (this->tipColor != tipColor) {
        this->tipColor = tipColor;
        update();
    }
}

void AdsWidget2::setDarkColor(const QColor &darkColor)
{
    if (this->darkColor != darkColor) {
        this->darkColor = darkColor;
        update();
    }
}

void AdsWidget2::setImageNames(const QString &imageNames)
{
    if (this->imageNames != imageNames) {
        this->imageNames = imageNames;

        //先清空原有所有指示器
        qDeleteAll(labs);
        labs.clear();

        //根据图片链表自动生成导航指示器和图片链表
        names = this->imageNames.split(";");
        for (int i = 0; i < names.count(); i++) {
            QLabel *lab = new QLabel;
            lab->setStyleSheet(QString("border:none;background:%1;color:%2;border-radius:%3px;")
                               .arg(navColor.name()).arg(textColor.name()).arg(navRadius));
            widgetBanner->layout()->addWidget(lab);
            lab->setFixedSize(minWidth, minHeight);
            if (showNumber) {
                lab->setAlignment(Qt::AlignCenter);
                lab->setText(QString::number(i + 1));
            }

            lab->installEventFilter(this);
            labs.append(lab);
        }
    }
}

void AdsWidget2::setImageTips(const QString &imageTips)
{
    if (this->imageTips != imageTips) {
        this->imageTips = imageTips;
        tips = this->imageTips.split(";");
        update();
    }
}
