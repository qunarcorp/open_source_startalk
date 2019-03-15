#ifndef ROBOTSEARCHVIEW_H
#define ROBOTSEARCHVIEW_H

#include <QWidget>
#include "ui_RobotSearchView.h"
#include "LocalManDialog.h"
namespace Biz{
	class CallbackReceiver;
}

class RobotListWidgetAdapter;
class RobotSearchResultListAdapter;
class RobotSearchView : public LocalManDialog
{
	Q_OBJECT

public:
	static RobotSearchView* getInstance();
	void autoshow();
private:
	RobotSearchView(QWidget *parent = 0);
	~RobotSearchView();
private:
	void rebuildRobotList(const QStringList& robotList);

private:
	Ui::RobotSearchView ui;
	static RobotSearchView* pInstance;
	Biz::CallbackReceiver* mReceiver;

	RobotListWidgetAdapter* pAdapterList;
	RobotSearchResultListAdapter* pAdapterSearch;


signals:
	void sgOpenRobotDialog(const QString& rbtid);
private slots:
	void onTabChange(bool bckech);
	void onSearchTextChanged(const QString & text);
	void onRobotSubscriptedListChange();
};

#endif // ROBOTSEARCHVIEW_H
