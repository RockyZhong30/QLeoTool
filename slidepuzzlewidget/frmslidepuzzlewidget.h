#ifndef FRMSLIDEPUZZLEWIDGET_H
#define FRMSLIDEPUZZLEWIDGET_H

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QMessageBox>
#include "ui_frmslidepuzzlewidget.h"

class FrmSlidePuzzleWidget : public QWidget
{
	Q_OBJECT

public:
	FrmSlidePuzzleWidget(QWidget *parent = 0);
	~FrmSlidePuzzleWidget();

private slots:
    void onUpdateWidget();
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

private:
	void initForm();

private:
	Ui::FrmSlidePuzzleWidgetClass ui;
};

#endif // FRMSLIDEPUZZLEWIDGET_H
