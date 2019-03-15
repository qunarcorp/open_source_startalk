#ifndef QUICKREPLYMSGDIALOG_H
#define QUICKREPLYMSGDIALOG_H

#include <QWidget>
#include "ui_ReplyMsgInforDialog.h"
#include "QuickReplyMsgMgr.h"
#include "UtilHelper.h"
#include "localmanwidget.h"
#include "Player.h"

class QuickReplyMsgDialog : public LocalManWidget
{
	Q_OBJECT

public:
	QuickReplyMsgDialog(QWidget *parent=0);
	~QuickReplyMsgDialog();

	void autoshow();
	inline void setWinid(const QString& id) {conversationId = id;} ;
protected:
	virtual void mouseMoveEvent( QMouseEvent * );
private:
	void Init();
	QMap<QString, QList<QuickReplyMsgItem*>> valmap;
	void SetShowMsg(const QString&text);
	void showDetailInfor(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList);
private slots:
	void onItemClicked(QListWidgetItem *pItem);
	void onpbSettingClicked();
	void onQuickReplyUpdate(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList);
	void onQuickReplyGroupChange();
	void onQuickReplyAllContentChange();
	void onQuickReplyContentChange(const QString &groupCid);
	void onRightItemEntered(QListWidgetItem*item);
signals:
	void sgItemSelected(const QString& id,const QString &str);

	

private:
	Ui::ReplayMsgInforDialog ui;
	QString conversationId;
};

typedef Util::SingletonTemplete<QuickReplyMsgDialog> QuickReplyMsgDialogSingleton;
#endif // QUICKREPLYMSGDIALOG_H
