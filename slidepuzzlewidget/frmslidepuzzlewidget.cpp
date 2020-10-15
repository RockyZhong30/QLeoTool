#include "frmslidepuzzlewidget.h"

FrmSlidePuzzleWidget::FrmSlidePuzzleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initForm();
}

FrmSlidePuzzleWidget::~FrmSlidePuzzleWidget()
{

}

void FrmSlidePuzzleWidget::initForm()
{
    QTimer::singleShot(33, this, SLOT(onUpdateWidget()));
    ui.puzzleWidget->setPixmap(":/slidepuzzlewidget/image/slidepuzzlewidget/back1.png");
}

void FrmSlidePuzzleWidget::onUpdateWidget()
{
    ui.horizontalSlider->setRange(0, this->width());
}

void FrmSlidePuzzleWidget::on_horizontalSlider_valueChanged(int value)
{
    ui.puzzleWidget->setValue(value);
}

void FrmSlidePuzzleWidget::on_horizontalSlider_sliderReleased()
{
    QString content = ui.puzzleWidget->isOverlap() ? "验证成功！" : "验证失败！";
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("滑块图片验证码"));
    msgBox.setText(content);
    msgBox.exec();

    static int testIndex = 1;
    testIndex = testIndex + 1 > 4 ? 1 : testIndex + 1;
    ui.horizontalSlider->setValue(0);
    ui.puzzleWidget->setPixmap(QString(":/slidepuzzlewidget/image/slidepuzzlewidget/back%1.png").arg(testIndex));
}
