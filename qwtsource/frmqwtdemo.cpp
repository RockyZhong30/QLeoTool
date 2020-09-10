#include "frmqwtdemo.h"
#include "ui_frmqwtdemo.h"
#include "qwt/qwt.h"
#include "qwt/qwt_dial.h"
#include "qwt/qwt_plot.h"

frmQwtDemo::frmQwtDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmQwtDemo)
{
    ui->setupUi(this);
}

frmQwtDemo::~frmQwtDemo()
{
    delete ui;
}
