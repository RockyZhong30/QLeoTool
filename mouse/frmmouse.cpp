#include "frmmouse.h"
#include "ui_frmmouse.h"

frmMouse::frmMouse(QWidget *parent) : QWidget(parent), ui(new Ui::frmMouse)
{
    ui->setupUi(this);
}

frmMouse::~frmMouse()
{
    delete ui;
}
