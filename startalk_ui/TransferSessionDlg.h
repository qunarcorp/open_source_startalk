#ifndef TRANSFERSESSIONDLG_H
#define TRANSFERSESSIONDLG_H

#include <QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QButtonGroup>
#include "localmanwidget.h"
#include "UtilHelper.h"

namespace Biz{
    class CallbackReceiver; 
}

class TransferSessionDlg : public LocalManWidget
{
	Q_OBJECT

public:
	TransferSessionDlg(QWidget *parent=0);
	~TransferSessionDlg();
	void showTranferDlg(QString &userJid);
private:
	bool transferDoing;
	QString transferUserJid;
	void init();
	void loadTransferList();
	QWidget *createItemWidget(const QString &text);
	Biz::CallbackReceiver* mCallbackReceiver;
	void showErrorView(const QString &title, const QString &content);
	QString getWillTransferUserJid();
	
	void setupUi();
	QWidget *selectUserView;
	QListWidget *userListWidget;
	QPushButton *pbNextStepBtn;
	QButtonGroup *radioGroupBtn;
	QWidget *transferReasonView;
	QLabel	*reasonLabel;
	QTextEdit *reasonTextEdit; 
	QPushButton *pbOkBtn;
	QPushButton *pbCancelBtn;
	QWidget *transferResultView;
	QLabel  *resultLabel;
	QLabel	*resultContentLabel;
	QPushButton *pbDoneBtn;
	
private slots:
	void onNextStep();
	void onTransferOk();
	void onTransferCancel();
	void onTransferDone();

};

typedef Util::SingletonTemplete<TransferSessionDlg> TransferSessionDlgSingleton;

#endif // TRANSFERSESSIONDLG_H
