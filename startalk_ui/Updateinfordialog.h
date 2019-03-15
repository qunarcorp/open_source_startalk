#ifndef UPDATEINFORDIALOG_H
#define UPDATEINFORDIALOG_H

#include <QDialog>
#include "LocalManDialog.h"

#include "ui_UpdateInforNewDialog.h"
#include "define.h"
#include "ProgressDialog.h"

namespace Biz{
	class Account;
	class CallbackReceiver;
}

class UpdateInforDialog : public LocalManDialog
{
	Q_OBJECT
public:
    enum UpdateUserChoose
    {
        UpdateUserChooseLater,
        UpdateUserChooseOnce
    };
public:
	UpdateInforDialog(QDialog *parent=0);
	~UpdateInforDialog();

	enum MessageButton{
		MessageButton_Once = 0x0001,
		MessageButton_Later = 0x0002,
	};

	void setButton(int button);
	void setEditStringText(const QString&);


	void setOnceText(const QString& text);
	void setLaterText(const QString& text);
    void setCheckVersionUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& update);
	
private:
    QSharedPointer<Biz::CheckVersionUpdate> _checkVersionUpdate;
private slots:
	void onOnceClicked(bool);
	void onLaterClicked(bool);
	void onProgressDisplay(const qint64 done, const qint64 total);
	
private:
//	Ui::UpdateInforDialog *ui;
	Ui::UpdateInforNewDialog *ui;
	//Biz::CallbackReceiver* mReceiver;
	//ProgressDialog *dlg;
	QString mdownloadfilename;
};

#endif // UPDATEINFORDIALOG_H
