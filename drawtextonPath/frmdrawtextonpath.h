#ifndef FRMDRAWTEXTONPATH_H
#define FRMDRAWTEXTONPATH_H

#include <QWidget>
#include "ui_frmdrawtextonpath.h"

//namespace Ui
//{
//    class frmDrawTextOnPath;
//}

class frmDrawTextOnPath : public QWidget
{
	Q_OBJECT

public:
    frmDrawTextOnPath(QWidget *parent = 0);
    ~frmDrawTextOnPath();

protected:
	void paintEvent(QPaintEvent *e);

private:
    Ui::frmDrawTextOnPath ui;
};

#endif // FRMDRAWTEXTONPATH_H
