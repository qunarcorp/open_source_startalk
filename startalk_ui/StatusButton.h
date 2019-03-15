#ifndef STATUSBUTTON_H
#define STATUSBUTTON_H

#include "CoreObject.h"
#include <QAbstractButton>

class StatusButton : public QAbstractButton
{
    Q_OBJECT

public:
    StatusButton(QWidget *parent);
    ~StatusButton();

public slots:
    void onMessageCountChanged(int);
private:
    virtual void paintEvent( QPaintEvent * );
public:
    void enablePixmap(const QString& val);
    void disablePixmap(const QString& val);
    void hoverPixmap(const QString& val);
protected:
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
private:

    int mMessageCount;
    QImage mEnableImage;
    QImage mDisableImage;
    QImage mHoverImage;
    QImage mTip;
    bool    mHover;
};

#endif // STATUSBUTTON_H
