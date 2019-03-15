#ifndef ATNOTICETIP_H
#define ATNOTICETIP_H

#include <QObject>
#include <QPropertyAnimation>
#include "ui_AtNoticeTip.h"

class AtNoticeTip : public QWidget
{
    Q_OBJECT

public:
    AtNoticeTip(QWidget *parent);
    ~AtNoticeTip();
    void setInfomation(const QString& sender,const QString& title,const QString& message);
    void showAnimotion(const QRect& startRect, const QRect& endRect);
    void autoClose(int mesc);
protected:
    void closetip(bool checked = false);
    protected slots:
    void animateTimeout();

private:
    Ui::AtNoticeTip* ui;
    QPropertyAnimation* popanimation ;
    qint64 mTick;
    qint64 mkeep;
};

#endif // ATNOTICETIP_H
