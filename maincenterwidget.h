#ifndef MAINCENTERWIDGET_H
#define MAINCENTERWIDGET_H

#include <QWidget>
#include "common/basestylewidget.h"
#include "NavListView/navlistview.h"

class MainCenterWidget : public BaseStyleWidget
{
    Q_OBJECT

    struct stuTab
    {
        QString name;
        int number;
        QWidget *wgt;
    };

public:
    explicit            MainCenterWidget(QWidget *parent = 0);

    void                addFunWidget(QString name, int number, QWidget *wgt);
public:
    QTabWidget          *m_centerWidget;
    NavListView         *m_navigationListView;

protected:
    void                paintEvent(QPaintEvent *e);

private slots:
    void                tabCloseRequested(int index);
    void                tabCurrentChanged(int index);

signals:
    void                hideNavListView(QString);
    void                listViewPress(QModelIndex index);

private:
    void                initParameter();
    void                initUI();
    void                initAnimation();
    void                initConnect();
private:
    QList<stuTab>       m_lstTabWidgetIndex;
    QPixmap             m_centerPix;
    QStringList         m_listItem;

};

#endif // MAINCENTERWIDGET_H
