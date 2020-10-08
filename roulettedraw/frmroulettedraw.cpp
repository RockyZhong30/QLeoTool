#include "frmroulettedraw.h"
#include "ui_frmroulettedraw.h"

frmRouletteDraw::frmRouletteDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmRouletteDraw)
{
    ui->setupUi(this);
}

frmRouletteDraw::~frmRouletteDraw()
{
    delete ui;
}
