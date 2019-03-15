#ifndef NEWSDIALOG_H
#define NEWSDIALOG_H

#include <QWidget>
#include "ui_newsdialog.h"
#include "BaseChatDialog.h"
#include "MessageListData.h"
#include "SystemDefine.h"
#include "RobotManager.h"
#include "ChatDialog.h"

class MultiDialogContainer;
class ChatCommObject;
class Biz::CallbackReceiver;
class WebPage;
class RobotManager;
namespace Biz
{
	enum SystemEnum
	{
		NOTSET,
		SYSDIALOG,
		NOTICEDIALOG,
		NEWSDIALOG,
		FRIENDSDIALOG
	};
};

class NewsDialog : public ChatDialog//public BaseChatDialog
{
	Q_OBJECT

public:
	NewsDialog(MultiDialogContainer* cntainer, int ntype,QWidget *parent=0);
	~NewsDialog();


	virtual void onLoadRoster(const QString& userID, const QString& displayName);
	virtual void messageSendPrepare (const QSharedPointer<Biz::XmppMessage>& spMessage);
	protected:
	virtual void getHistoryByPage(int count, quint64 timestamp, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);
protected:

};

#endif // NEWSDIALOG_H
