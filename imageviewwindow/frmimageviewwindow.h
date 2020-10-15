#ifndef FRMIMAGEVIEWWINDOW_H
#define FRMIMAGEVIEWWINDOW_H

#include <QWidget>

namespace Ui {
class frmImageViewWindow;
}

class frmImageViewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit frmImageViewWindow(QWidget *parent = 0);
    ~frmImageViewWindow();

private:
    Ui::frmImageViewWindow *ui;
};

#endif // FRMIMAGEVIEWWINDOW_H
