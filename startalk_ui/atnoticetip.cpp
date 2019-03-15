#include "atnoticetip.h"

#include <QTimer>
#include <QDateTime>
#include "gloableeventobject.h"
AtNoticeTip::AtNoticeTip(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::AtNoticeTip()),popanimation(new QPropertyAnimation(this, "geometry" ))
{
    mTick = 0;
    mkeep = 2000;
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&AtNoticeTip::closetip);
    ui->pushButton->setIconSize(QSize(16,16));
    ui->pushButton->setIcon(QIcon(QPixmap(":Images/icon_close.png")));
	connect(ui->label, &QPushButton::clicked, this, &AtNoticeTip::closetip);
	ui->pushButton->setVisible(false);
}

AtNoticeTip::~AtNoticeTip()
{

}

void AtNoticeTip::setInfomation(const QString& sender,const QString& title,const QString& message)
{
    QString infomation = QString("%1 : %3").arg(sender).arg(message);
    QFontMetrics elidfont(ui->label->font());
    int width = ui->label->width();
    ui->label->setText(elidfont.elidedText (infomation, Qt::ElideRight, qMax(width,500)));
}

void AtNoticeTip::closetip(bool checked /*= false*/)
{
	//取消左边的“你被@多少次
	this->close();
}

void AtNoticeTip::showAnimotion(const QRect& startRect, const QRect& endRect)
{
    popanimation->setDuration(300);
    popanimation->setStartValue(startRect);
    popanimation->setEndValue(endRect);
    this->show();
    popanimation->start();

    mTick = QDateTime::currentMSecsSinceEpoch();
}

void AtNoticeTip::autoClose(int msec) {
    mkeep = msec;
    mTick = QDateTime::currentMSecsSinceEpoch();
    QTimer::singleShot( msec, this, SLOT(animateTimeout()) );
}

void AtNoticeTip::animateTimeout(){
    qint64 currtick = QDateTime::currentMSecsSinceEpoch();
    if (currtick-mTick<mkeep)
    {
        return;
    }

    closetip(true);
}

