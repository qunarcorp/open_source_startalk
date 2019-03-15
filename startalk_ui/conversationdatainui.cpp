#include "conversationdatainui.h"
#include "ConversationController.h"
#include "UIFrame.h"
#include "XmppMessage.h"
#include "BaseChatDialog.h"
bool CompareXmppMessageThan(const QSharedPointer<Biz::XmppMessage>& msgone, const QSharedPointer<Biz::XmppMessage>& msgtwo);
ConversationDataInUI::ConversationDataInUI(QObject *parent)
	: QObject(parent)
	,m_scrollPos(0)
	,mRightPannel(false)
	,mAtbar(false)
	,mUnReadbar(false)
{
// 	connect(MainApp::UIFrame::getConversationController(), &MainApp::ConversationController::sgupdateHistoryMsglist, this, &ConversationDataInUI::onUpdateHistoryMsglist);
// 	connect(MainApp::UIFrame::getConversationController(), &MainApp::ConversationController::sgCleanHistoryMsglist, this,&ConversationDataInUI::onCleanHistoryMsglist);
// 	connect(MainApp::UIFrame::getConversationController(), &MainApp::ConversationController::sgupdateHistoryMsglistSendSuccess, this,&ConversationDataInUI::onUpdateHistoryMsgSendSuccess);
}

ConversationDataInUI::~ConversationDataInUI()                                                   
{

}

void ConversationDataInUI::SetHistoryMsgList( const QList<QSharedPointer<Biz::XmppMessage>>& historymsglist )
{
	if (historymsglist.size() == 0)
	{
		return;
	}
	for (QSharedPointer<Biz::XmppMessage> xmppMsg: historymsglist)
	{
		bool bfinded = false;
// 		if (!m_HistoryMsgList.contains(xmppMsg))
// 		{
// 			m_HistoryMsgList.push_back(xmppMsg);
// 		}
		for (QSharedPointer<Biz::XmppMessage> historymsg: m_HistoryMsgList)
		{
			
			if (historymsg->MessageID() == xmppMsg->MessageID())
			{
				bfinded = true;
				break;
			}
			
		}
		if (xmppMsg->Body().isEmpty())
		{
			continue;
		}
		if (!bfinded )
		{
			m_HistoryMsgList.push_back(xmppMsg);
		}
	}
	//这个地方应该给消息进行排序，否则到时候取出去的时候都是乱序了
	SortHistoryMsg();
}

void ConversationDataInUI::SetCurrentReceivedList( const QList<QSharedPointer<Biz::XmppMessage>>& recivedlist )
{
	m_CurrentRecivedList = recivedlist;
}

void ConversationDataInUI::SetWillSendMsg( const QSharedPointer<MimeTypeMessage>& msg )
{
	m_WillSendMessage = msg;
}
QSharedPointer<MimeTypeMessage> ConversationDataInUI::getWillSendMsg()
{
	if(m_WillSendMessage.isNull())
		m_WillSendMessage = QSharedPointer<MimeTypeMessage>(new MimeTypeMessage);

	return m_WillSendMessage;
}
void ConversationDataInUI::SetMsgId( const QString& msgid )
{
	m_msgid = msgid;
}

void ConversationDataInUI::onUpdateHistoryMsglist( const QString& conversationid, const QList<QSharedPointer<Biz::XmppMessage>>& historymsglist )
{
	if (conversationid == m_ConversatinId)
	{
		SetHistoryMsgList(historymsglist);
	}
}

void ConversationDataInUI::SetConversationId( const QString& conversationId )
{
	m_ConversatinId = conversationId;
}

void ConversationDataInUI::onCleanHistoryMsglist( const QString& conversationid )
{
	if (m_ConversatinId == conversationid)
	{
		m_HistoryMsgList.clear();
	}
}

QList<QSharedPointer<Biz::XmppMessage>> ConversationDataInUI::GetHistoryMsgList()
{
	return m_HistoryMsgList;
}

void ConversationDataInUI::SortHistoryMsg()
{
	qSort(m_HistoryMsgList.begin(), m_HistoryMsgList.end(), CompareXmppMessageThan);
}

void ConversationDataInUI::setScrollPos( int nPos )
{
	m_scrollPos = nPos;
}

void ConversationDataInUI::onUpdateHistoryMsgSendSuccess( const QString& conversationid, const QString& msgid, int status )
{
	if (m_ConversatinId == conversationid)
	{
		for (QSharedPointer<Biz::XmppMessage> historymsg: m_HistoryMsgList)
		{

			if (historymsg->MessageID() == msgid)
			{
				historymsg->Flag(status);
				break;
			}
		}
	}
}

bool ConversationDataInUI::GetAtbar()
{
	return mAtbar;
}

void ConversationDataInUI::SetAtbar( bool bret )
{
	mAtbar = bret;
}

void ConversationDataInUI::setRightPannel(  bool bshow )
{
	mRightPannel = bshow;
}

bool ConversationDataInUI::getRightPannel()
{
	return mRightPannel;
}

void ConversationDataInUI::setmoodInfor( const QString& strmoodinfo )
{
	mMoodInfo = strmoodinfo;
}

QString ConversationDataInUI::getmoodInfor()
{
	return mMoodInfo;
}

bool CompareXmppMessageThan( const QSharedPointer<Biz::XmppMessage>& msgone, const QSharedPointer<Biz::XmppMessage>& msgtwo )
{
	return msgone->UtcTime() <= msgtwo->UtcTime();
}
