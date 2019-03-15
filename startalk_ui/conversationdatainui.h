#ifndef CONVERSATIONDATAINUI_H
#define CONVERSATIONDATAINUI_H

#include <QObject>
#include <QSharedPointer>

class MimeTypeMessage;
namespace Biz{
	class XmppMessage;
}

class ConversationDataInUI : public QObject
{
	Q_OBJECT

public:
	ConversationDataInUI(QObject *parent=NULL);
	~ConversationDataInUI();
public:
	void SetCurrentReceivedList(const QList<QSharedPointer<Biz::XmppMessage>>& recivedlist);
	void SetHistoryMsgList(const QList<QSharedPointer<Biz::XmppMessage>>& historymsglist);
	void SetWillSendMsg(const QSharedPointer<MimeTypeMessage>& msg);
	QSharedPointer<MimeTypeMessage> getWillSendMsg();
	void SetMsgId(const QString& msgid);
	void SetConversationId(const QString& conversationId);
	QList<QSharedPointer<Biz::XmppMessage>> GetHistoryMsgList();
	void setScrollPos(int nPos);
	int GetScrollPos(const QString& conversationId){return m_scrollPos;};
	bool GetAtbar();
	void SetAtbar(bool bret);
	void setRightPannel( bool bshow);
	bool getRightPannel();
	void setmoodInfor(const QString& moodinfo);
	QString getmoodInfor();
protected:
	void SortHistoryMsg();
	
private slots:
	void onUpdateHistoryMsglist(const QString& conversationid, const QList<QSharedPointer<Biz::XmppMessage>>& historymsglist);
	void onCleanHistoryMsglist(const QString& conversationid);
	void onUpdateHistoryMsgSendSuccess(const QString& conversationid, const QString& msgid, int status);
private:
	//历史消息
	QList<QSharedPointer<Biz::XmppMessage>> m_HistoryMsgList;
	//输入的消息
	QSharedPointer<MimeTypeMessage> m_WillSendMessage;
	
	//接收到，还未展示的数据
	QList<QSharedPointer<Biz::XmppMessage>> m_CurrentRecivedList;
	//滚动条位置的消息Id
	QString m_msgid;
	QString m_ConversatinId;
	int m_scrollPos;
	//qchat中有右边的产品信息面板
	bool mRightPannel;
	//聊天框中有@和未读的信息
	bool mAtbar;
	bool mUnReadbar;
	QString mUnReadMsgCount;

	QString mMoodInfo;

};

#endif // CONVERSATIONDATAINUI_H
