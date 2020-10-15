#include "frmmeterwidget.h"
#include "ui_frmmeterwidget.h"

frmMeterWidget::frmMeterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMeterWidget)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &frmMeterWidget::update);
}

frmMeterWidget::~frmMeterWidget()
{
    delete ui;
}

void frmMeterWidget::update(int value)
{
    ui->widget->setValue(value);
    ui->widget_2->setValue(value);
    ui->widget_3->setValue(value);
}
