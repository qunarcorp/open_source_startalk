#ifndef ROBOTSEARCHEDITEM_H
#define ROBOTSEARCHEDITEM_H

#include <QWidget>
#include "ui_RobotSearchedItem.h"
namespace Biz{
	class CallbackReceiver;
}
class RobotSearchedItem : public QWidget
{
	Q_OBJECT
public:
	enum ShowType{
		ShowType_List = 0,
		ShowType_Search = 1
	};
public:
	RobotSearchedItem(QWidget *parent = 0);
	~RobotSearchedItem();
	void setShowType(int type);
	void setPixmap(const QPixmap& pixmap);
	void setName(const QString& name);
	void setId(const QString& id);

	virtual void enterEvent(QEvent *);

	virtual void leaveEvent(QEvent *);

private:
	Ui::RobotSearchedItem ui;
	QString rbtId;
	Biz::CallbackReceiver* mReceiver;
signals:
	void sgOpenRobotDialog(const QString& rbtid);
	private slots:
		void onAddRobotBtnClick(bool bcheck);
		void onOpenRobotBtnClick(bool bcheck);
		void onCancelRobotBtnClick(bool bcheck);
};

#endif // ROBOTSEARCHEDITEM_H
