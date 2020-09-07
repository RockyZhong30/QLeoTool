#ifndef LEOHOMEPAGE_H
#define LEOHOMEPAGE_H

#include "common/basestylewidget.h"
#include <QLabel>
#include <QProcess>
#include <QPixmap>

class LeoHomePage : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit LeoHomePage(QWidget *parent = 0);
    ~LeoHomePage();

public:
    QProcess        *pProcess;

protected:
    void            paintEvent(QPaintEvent *e);

signals:

public slots:

private:
    void            initUi();
    void            initConnect();

    QString         readFile(const QString filename);

private:
    QPixmap         m_bgPix;
};

#endif // LEOHOMEPAGE_H
