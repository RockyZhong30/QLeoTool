#ifndef QLEOTOOL_H
#define QLEOTOOL_H

#include "common/shadowwidget.h"
#include "common.h"

class MainTopWidget;
class MainCenterWidget;

class QLeoTool : public ShadowWidget
{
    Q_OBJECT

public:
    QLeoTool(QWidget *parent = nullptr);
    ~QLeoTool();

private slots:
    void closeWidget();
    void showNavigation();

private:
    void initUi();
    void initConnect();

private:
    MainTopWidget       *m_topWidget;
    MainCenterWidget    *m_centerWidget;
};
#endif // QLEOTOOL_H