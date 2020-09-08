#ifndef MAINTOPWIDGET_H
#define MAINTOPWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include "common/basestylewidget.h"



class MainTopWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit        MainTopWidget(QWidget *parent = 0);

    void            setLabelNavigation(QString name);

public slots:

signals:
    void            closeWidget();
    void            showNavigation();
    void            homePageWidget();
    void            helpTestWidget();

protected:
    void            paintEvent(QPaintEvent *e);
    void            resizeEvent(QResizeEvent *);
private slots:

private:
    void            initParameter();
    void            initUI();
    void            initConnect();

private:
    QFrame          *m_topLeftFrame;
    QFrame          *m_topRightFrame;
    QPushButton     *m_btnHome;
    QPushButton     *m_btnHelp;
    QPushButton     *m_btnQuit;
    QPushButton     *m_btnNavigation;
    QLabel          *m_logoLabel;
    QLabel          *m_navigationLabel;

    QPixmap         m_QrcodePix;
    QPixmap         m_localPix;
    QPixmap         m_logoPix;

};

#endif // MAINTOPWIDGET_H
