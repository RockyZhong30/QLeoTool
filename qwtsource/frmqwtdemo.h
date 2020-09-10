#ifndef FRMQWTDEMO_H
#define FRMQWTDEMO_H

#include <QWidget>

namespace Ui {
class frmQwtDemo;
}

class frmQwtDemo : public QWidget
{
    Q_OBJECT

public:
    explicit frmQwtDemo(QWidget *parent = 0);
    ~frmQwtDemo();

private:
    Ui::frmQwtDemo *ui;
};

#endif // FRMQWTDEMO_H
