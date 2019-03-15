#ifndef ERCODELOGINWIDGET_H
#define ERCODELOGINWIDGET_H

#include "LocalManDialog.h"

namespace Ui{
	class ErCodeLoginWidget;
}

namespace Biz{
	class CallbackReceiver;
}

class ErCodeLoginWidget : public LocalManDialog
{
	Q_OBJECT

public:
	ErCodeLoginWidget(QWidget *parent=NULL);
	~ErCodeLoginWidget();
	void initErcode();
protected:
	virtual bool eventFilter( QObject *, QEvent * );
	
public slots:
	void onShowAuthUserInfo(const QString&userurl, const QString& nickname);
	void onResultUserInfo(const QString&infor);
	void onCloseWidget(bool bret);
private:
	Ui::ErCodeLoginWidget *ui;
	QString mtitleinfor;
	QString mqerCodeInfo;
	Biz::CallbackReceiver* mReceiver;
};

#endif // ERCODELOGINWIDGET_H
