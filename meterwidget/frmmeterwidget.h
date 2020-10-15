#ifndef FRMMETERWIDGET_H
#define FRMMETERWIDGET_H

#include <QWidget>

namespace Ui {
class frmMeterWidget;
}

class frmMeterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit frmMeterWidget(QWidget *parent = 0);
    ~frmMeterWidget();

private Q_SLOTS:
    void update(int value);

private:
    Ui::frmMeterWidget *ui;
};

#endif // FRMMETERWIDGET_H
