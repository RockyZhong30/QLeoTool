#pragma execution_character_set("utf-8")

#include "frmadswidget2.h"
#include "ui_frmadswidget2.h"

frmAdsWidget2::frmAdsWidget2(QWidget *parent) : QWidget(parent), ui(new Ui::frmAdsWidget2)
{
    ui->setupUi(this);
    this->initForm();
}

frmAdsWidget2::~frmAdsWidget2()
{
    delete ui;
}

void frmAdsWidget2::initForm()
{
    QString imageNames = ":/adswidget/image/adswidget/ad1.png;:/adswidget/image/adswidget/ad2.png;:/adswidget/image/adswidget/ad3.png";
    QString imageTips = "广告图片1;广告图片2;广告图片3";

    ui->adsWidget1->setInterval(2000);
    ui->adsWidget1->setImageNames(imageNames);

    ui->adsWidget2->setMinWidth(25);
    ui->adsWidget2->setMaxWidth(25);
    ui->adsWidget2->setMinHeight(25);
    ui->adsWidget2->setShowNumber(true);
    ui->adsWidget2->setImageNames(imageNames);
    ui->adsWidget2->setImageTips(imageTips);
}
