#ifndef ADVERTINFODIALOG_H
#define ADVERTINFODIALOG_H

#include "LocalManDialog.h"
#include "ui_AdvertInfoDialog.h"
#include "CallbackReceiver.h"

class AdvertInfoDialog : public LocalManDialog
{
	Q_OBJECT

public:
	static AdvertInfoDialog* instance();
	void showAdvertInfoDlg();
	void setJid(const QString&jid);
private:
	
	void setPixmap(const QString& path, const QString& strweburl);
	void showProductInfor(const QString& fileName, const QString& title, const QString& price, 
		const QString& markprice, const QString& type, const QString& tag, const QString& strWeburl);
	static AdvertInfoDialog* pInstance;
	AdvertInfoDialog(QWidget *parent = NULL);
	~AdvertInfoDialog();
	QString mstrSendMsg;
	QString mstrUrl;
	QString mJid; 

	

private slots:
	void onClose();
	void onSearchProductInfo();
	void onSendMsg();
	void onOpenLabel(const QString& url);
private:
	Ui::AdvertInfoDialog ui;
	Biz::CallbackReceiver* mReceiver;

};

#endif // ADVERTINFODIALOG_H
