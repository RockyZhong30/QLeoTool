#ifndef MAINCENTERWIDGET_H
#define MAINCENTERWIDGET_H

#include <QWidget>
#include "common/basestylewidget.h"
#include "NavListView/navlistview.h"
#include "scrolltext/scrolltext.h"

class MainCenterWidget : public BaseStyleWidget
{
    Q_OBJECT

    struct stuTab
    {
        QString name;
        int number;
        QWidget *wgt;

        stuTab() : name(""), number(0), wgt(NULL){}
    };

public:
    explicit            MainCenterWidget(QWidget *parent = 0);

    void                addFunWidget(int number, QString name = "", QWidget *wgt = NULL);
    bool                isFunWidgetExist(int number);
public:
    QTabWidget          *m_centerWidget;
    NavListView         *m_navigationListView;
    ScrollText          *m_scrollTextWidget;

protected:
    void                paintEvent(QPaintEvent *e);

private slots:
    void                tabCloseRequested(int index);
    void                tabCurrentChanged(int index);

signals:
    void                setLabelNavigation(QString);
    void                listViewPress(QModelIndex index);

private:
    void                initParameter();
    void                initUI();
    void                initAnimation();
    void                initConnect();
private:
    QList<stuTab>       m_lstTabWidgetIndex;
    QPixmap             m_centerPix;

};

#endif // MAINCENTERWIDGET_H
