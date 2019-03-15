#pragma once
#include <QListWidget>
#include "CallbackReceiver.h"

class QListWidgetItemSortable;


class ConversationListWidget :
	public QListWidget
{
	Q_OBJECT
public:
	ConversationListWidget(QWidget* parent);
	virtual ~ConversationListWidget(void);
public:
	void addLinkItem(const QString& jid,const QString& name,const QString& belongExtendid);
	void addGroupChatDialog(const QString& jid);
	void addChatDialog(const QString& jid);
	void addConsultDialog(const QString& jid,const QString& virtualid,const QString& realseat,bool isSeat);
	void addRobotDialog(const QString& jid);
	void addNewsDialog(const QString& jid);
	void addRawHtmlDialog(const QString& jid);
	bool isConsultChatItem(const QString& conversationId);
	bool isSimpleChatItem(const QString& conversationId);
	bool isGroupChatItem(const QString& conversationId);
	bool isNewsChatItem(const QString& conversationId);
	bool isRobotChatItem(const QString& conversationId);
	bool isLinkedItem(const QString& conversationId);
	bool isRawHtmlItem(const QString& conversationId);
	QStringList gethasConversationId();

	QString  getConsultVirtualJid(const QString& conversationId);
	QString	 getConsultRealJid(const QString& conversationId);
	bool	getConsultIsSeatFlag(const QString& conversationId);

public:
	void updateNoticeTip(const QString& jid, int noticetip);
	void updateTopMost(const QString& jid, bool bTopMost);
	void updateUnReadCount(const QString&jid,int nCount);
	void updateAllConversationUnreadCount();
	void updateLinkItemUnReadCount(const QString&jid);
	void updateAtCount(const QString&jid, int count, int type);
	void updateRobotVcard(const QString& conversationId,const QString& displayName);
	void updateGroupHeader(const QString& jid);
	void updatevCard(const QString& id);
	void updateConversationLastTimeStamp(const QString& userId, quint64 timestamp);
	void increaseAtCount(const QString&jid, int count, int type, const QString& msgid);
	int getunReadCount(const QString& strjid);
	void updateChatContent(const QString&jid, const QString&content);
public:
	void clearData();
	void autoScroll(const QString& userid,QAbstractItemView::ScrollHint hint = EnsureVisible);
	void activityChatDialog(const QString& uid);
	void deleteItem(const QString& id);
	bool hasCouversation(const QString& conversatindId);
	QString currentUid();

protected:
	virtual void doCloseLastItemChat();

protected:
	void insertItem(const QString& conversationId,QListWidgetItemSortable* item);
	void doSetUserHeader(const QString& userid);
	QListWidgetItem* getConversationItem(const QString& conversationId);

protected:
	QMap<QString,QListWidgetItemSortable*> mConversationId2Item;
	Biz::CallbackReceiver* mReceiver;

signals:
	void conversationActived(const QString& conversationID);
	void conversationClicked(const QString& conversationId);
	void extendListActived(const QString& extendid);
	void showAtInfoBlock(const QString& conversationID, const QString& atmsgid);
	public slots:
		void currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
		void itemClicked(QListWidgetItem * current);
};



