#ifndef WORKSTATUSWIDGET_H
#define WORKSTATUSWIDGET_H

#include <QWidget>

namespace Ui
{
	class WorkStatusWidget;
}

namespace Biz
{
	class WorkStatusData;
	class CallbackReceiver;
}


class WorkStatuswidget : public QWidget
{
	Q_OBJECT

public:
	WorkStatuswidget(QWidget *parent=NULL);
	~WorkStatuswidget();
	void setTitleInfor(const QString&title);
	void setStatus(int status);
	void setSid(int sid);
private:
	 Ui::WorkStatusWidget *ui;
	 Biz::CallbackReceiver* mReceiver;
	 int mSid;
};

#endif // WORKSTATUSWIDGET_H
