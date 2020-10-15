#include "frmimageviewwindow.h"
#include "ui_frmimageviewwindow.h"

frmImageViewWindow::frmImageViewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmImageViewWindow)
{
    ui->setupUi(this);
}

frmImageViewWindow::~frmImageViewWindow()
{
    delete ui;
}
