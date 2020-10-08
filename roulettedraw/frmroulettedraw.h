#ifndef FRMROULETTEDRAW_H
#define FRMROULETTEDRAW_H

#include <QWidget>

namespace Ui {
class frmRouletteDraw;
}

class frmRouletteDraw : public QWidget
{
    Q_OBJECT

public:
    explicit frmRouletteDraw(QWidget *parent = 0);
    ~frmRouletteDraw();

private:
    Ui::frmRouletteDraw *ui;
};

#endif // FRMROULETTEDRAW_H
