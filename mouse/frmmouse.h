#ifndef FRMMOUSE_H
#define FRMMOUSE_H

#include <QWidget>

namespace Ui {
class frmMouse;
}

class frmMouse : public QWidget
{
    Q_OBJECT

public:
    explicit frmMouse(QWidget *parent = 0);
    ~frmMouse();

private:
    Ui::frmMouse *ui;
};

#endif // FRMTIMERULER_H
