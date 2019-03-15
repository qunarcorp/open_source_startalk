#include "advpopdialog.h"
#include <QTimer>
#include "Session.h"
#include "advinformanager.h"
#include "./jsonobject/adverconfiginfo.h"

namespace Biz
{
	class AdverConfigInfo;
}

AdvPopDialog::AdvPopDialog(QWidget *parent)
	: LocalManWidget(parent)
	,ui(new Ui::AdvPopDialog)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->move((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height());
}

AdvPopDialog::~AdvPopDialog()
{
	if (ui)
	{
		delete ui;
	}
}

void AdvPopDialog::showAdvPopAnimation(const QList <QSharedPointer<Biz::AdvDataItem>> & picpathlist)
{
	QSharedPointer<Biz::AdverConfigInfo> spConfigInfo = Biz::Session::getAdvInforManager()->getAdvConfigInfo();
	if (spConfigInfo.isNull())
		return; // 数据不足
	if (!spConfigInfo->shown())
		return; // 无广告

	ui->advwidget->setCloseable(spConfigInfo->allowskip()); // 可以关闭

	ui->advwidget->showAllPicture(picpathlist);

	ui->advwidget->setVisible(true);

	show();
	animation=new QPropertyAnimation(this,"pos");
	animation->setDuration(1000);
	animation->setStartValue(QPoint(this->x(),this->y()));
	animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),(desktop.availableGeometry().height()-this->height())));
	animation->start();


	remainTimer=new QTimer();
	connect(remainTimer,SIGNAL(timeout()),this,SLOT(closeAnimation()));
	remainTimer->start(2000);
}

void AdvPopDialog::closeAnimation()
{
	remainTimer->stop();
	disconnect(remainTimer,SIGNAL(timeout()),this,SLOT(closeAnimation()));
	delete remainTimer;
	remainTimer=NULL;

	animation->setStartValue(QPoint(this->x(),this->y()));
	animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height()));
	animation->start();

	connect(animation,SIGNAL(finished()),this,SLOT(clearAll()));
}

void AdvPopDialog::clearAll()
{
	disconnect(animation,SIGNAL(finished()),this,SLOT(clearAll()));
	delete animation;
	animation=NULL;
}
