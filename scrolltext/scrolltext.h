#ifndef SCROLLTEXT_H
#define SCROLLTEXT_H

#include <QWidget>
#include <QTimerEvent>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT RouletteDraw : public QWidget
#else
class ScrollText : public QWidget
#endif
{
    Q_OBJECT
    Q_PROPERTY(QString rotate READ getScrollText WRITE setScrollText)
    Q_PROPERTY(bool rotate READ getDirectionR2L WRITE setDirectionR2L)

public:
    explicit ScrollText(QWidget *parent = 0);
    ~ScrollText();

    QSize sizeHint() const;

signals:

public:
    QString getScrollText() const;
    bool getDirectionR2L() const;

public Q_SLOTS:
    void setScrollText(const QString &text);
    void setDirectionR2L(const bool &r2l);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);
    virtual void timerEvent(QTimerEvent *event);

private:
    QString m_scrollText;
    int m_timerId;
    int m_offset;
    bool m_directionR2L;
};

#endif // SCROLLTEXT_H
