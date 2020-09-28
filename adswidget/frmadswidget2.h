#ifndef FRMADSWIDGET2_H
#define FRMADSWIDGET2_H

#include <QWidget>

namespace Ui {
class frmAdsWidget2;
}

class frmAdsWidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit frmAdsWidget2(QWidget *parent = 0);
    ~frmAdsWidget2();

private:
    Ui::frmAdsWidget2 *ui;

private slots:
    void initForm();
};

#endif // FRMADSWIDGET2_H
