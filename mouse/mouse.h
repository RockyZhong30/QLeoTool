#ifndef MOUSE_H
#define MOUSE_H

#include <QWidget>

class Mouse : public QWidget
{
    Q_OBJECT
public:
    explicit Mouse(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MOUSE_H
