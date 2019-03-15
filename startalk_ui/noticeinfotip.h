#ifndef NOTICEINFOTIP_H
#define NOTICEINFOTIP_H

#include <QWidget>
#include "jsonobject/systemnotify.h"
#include <QPushButton>
namespace Ui
{
	class NoticeInfoTip;
}
namespace Biz{
	class CallbackReceiver;
}
enum InforClickedType
{
	Link,
	request,
	text,
	newChat
};
static const char *typeInfo[] = {"link", "request", "text", "newChat"};


class ItemBtn:public QPushButton
{
public:
	ItemBtn(QWidget*widget)
		:QPushButton(widget)
	{};
	~ItemBtn(){};
	void setBtnData(const QSharedPointer<Biz::NoticeStrInfor>& info)
	{
		minfor = info;
	}
	QSharedPointer<Biz::NoticeStrInfor> getBtnData()
	{
		return minfor;
	}
	void setBtnType(int type)
	{
		mtype = type;
	}
	int getBtnType()
	{
		return mtype;
	}
private:
	QSharedPointer<Biz::NoticeStrInfor> minfor;
	int mtype;
};



class NoticeInfoTip : public QWidget
{
	Q_OBJECT

public:
	NoticeInfoTip(QWidget *parent);
	~NoticeInfoTip();
	void setInfor(const QList <QSharedPointer<Biz::NoticeStrInfor>>& list);
	void showTip();
public slots:
	void closetip();
	void onClickedStyle();
private:
	Ui::NoticeInfoTip *ui;
	Biz::CallbackReceiver* mReceiver;

};

#endif // NOTICEINFOTIP_H
