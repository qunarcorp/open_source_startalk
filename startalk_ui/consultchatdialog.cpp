#include "consultchatdialog.h"
#include "Session.h"

#include "virtualaccountmanager.h"
#include "UserVcardManager.h"

#include "accountmanager.h"
#include "AccountData.h"
#include "Account.h"

#include "SystemConfigData.h"

#include "editablesettings.h"

#include "Ordermanagedialog.h"

#include "WebService.h"


#include "UIFrame.h"
#include "ConversationController.h"
#include "virtualaccountcontroller.h"
#include "MainDialogController.h"
#include "NotifyCenterController.h"

#include "ui_ChatDialog.h"

ConsultChatDialog::ConsultChatDialog(MultiDialogContainer* cntainer,QWidget *parent/*=0*/)
	: ChatDialog(cntainer,parent)
{
	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgRealConversationJidChange,this,&ConsultChatDialog::onRealConversationJidChange);

	int nToolBarDisableMask = ui->toolbar->getBtnEnableMask();
	nToolBarDisableMask = nToolBarDisableMask | BTN_TRANS;
	nToolBarDisableMask = nToolBarDisableMask | BTN_QUICK;
	nToolBarDisableMask = nToolBarDisableMask | BTN_CLOSESESSION;
	ui->toolbar->setBtnEenable(nToolBarDisableMask);

	connect(ui->toolbar,&ChatToolBar::sgCloseSessionBtnClicked,this,&ConsultChatDialog::onCloseRemoteSession);
}

ConsultChatDialog::~ConsultChatDialog()
{

}

void ConsultChatDialog::resetUI(void) {
	if (m_bIsSeat == false)
	{
		int nToolBarDisableMask = ui->toolbar->getBtnEnableMask();
		nToolBarDisableMask = nToolBarDisableMask & ~BTN_TRANS;
		nToolBarDisableMask = nToolBarDisableMask | BTN_QUICK;
		nToolBarDisableMask = nToolBarDisableMask & ~BTN_CLOSESESSION;
		ui->toolbar->setBtnEenable(nToolBarDisableMask);
	} else { 
		int nToolBarDisableMask = ui->toolbar->getBtnEnableMask();
		nToolBarDisableMask = nToolBarDisableMask | BTN_TRANS;
		nToolBarDisableMask = nToolBarDisableMask | BTN_QUICK;
		nToolBarDisableMask = nToolBarDisableMask | BTN_CLOSESESSION;
		ui->toolbar->setBtnEenable(nToolBarDisableMask);
	}
}

void ConsultChatDialog::showTransChatHistory(const QString& from)
{
	QString strUrl = Biz::Session::getEditableSettings()->SessionHistory();
	QUrl qu(strUrl);
	QUrlQuery quq(qu);
	quq.addQueryItem("from", from);
	quq.addQueryItem("to", Biz::MessageUtil::makeSureUserId(mVirtualId));
	quq.addQueryItem("u", Biz::Session::getAccountManager()->accountData().UserID());
	quq.addQueryItem("k", WebService::sSecurityKey);
	qu.setQuery(quq);
	strUrl = qu.toString();
	CommentWebViewSingleton::getInstance()->setQunarCookie();
	CommentWebViewSingleton::getInstance()->openCommonUrl(strUrl);
}



void ConsultChatDialog::SendMsgByrealName( const QString&realname, QSharedPointer<Biz::XmppMessage>& message )
{
	if(message.isNull())
		return;
	message->Realto(realname);
	message->Realfrom(Biz::Session::getAccountManager()->accountData().UserID());
	auto callback = receiver->createCallback([]{}, [this](){
		// 发送图片失败
		
	});
	auto presendcallback = receiver->createCallback([this, message](){
		appendMessage(false,false,message);
	},[this](){});

	message->Chatid(Biz::consultmsgType::VistorToOnDuty);
	message->qchatid(Biz::consultmsgType::VistorToOnDuty);
	messageSendPrepare (message);
	message->MsgSourceType(Biz::consult);
	message->cctext(m_cctext);
	message->bu(m_bu);
	Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);


	sendMessageComplete(message);
	
}


void ConsultChatDialog::getRealName( QSharedPointer<Biz::XmppMessage>& message )
{
	if (message.isNull())
	{
		return;
	}
	auto callback = receiver->createCallback<QString>([this,message](QString realname)
	{
		if (realname.isEmpty())
		{
			realname = message->ConversationID();
		}
		QSharedPointer<Biz::XmppMessage> msg = message;
		SendMsgByrealName(realname, msg);

	}, []{});


	Biz::Session::getVirtualManager()->getRealAccountbyVirtualAccount(Biz::MessageUtil::makeSureUserId(conversationId()), callback);
}

void ConsultChatDialog::onLoadRoster(const QString& userID, const QString& displayName)
{

	QString strDisplayTitle = displayName;
	if (UtilHelper::isVirtualAccountId(userID, Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		QString strRealName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(UtilHelper::getRealIdfromID(userID));
		QString strVirtualName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(UtilHelper::getvirtualfromID(userID));
#ifdef QCHAT
		QString strDisplayTitle = QStringLiteral("%1").arg(strRealName);
		ui->platformIcon->setVisible(true);
		QPixmap pix(":Images/icon/shopvirtual.png");
		pix = QPixmap::fromImage(pix.toImage().scaled(QSize(16,16)));
		ui->platformIcon->setPixmap(pix);
		QString strtooltip = QStringLiteral("咨询%1店铺中产品").arg(strVirtualName);
		ui->platformIcon->setToolTip(strtooltip);

#else
		strDisplayTitle = QString("%1-%2").arg(strVirtualName, strRealName);
#endif // QCHAT
	}
	
	ChatDialog::onLoadRoster(userID,strDisplayTitle);

	QSharedPointer<Biz::XmppMessage> msg (new Biz::XmppMessage(conversationId()));

	QStringList list = msg->ConversationID().split("|"); 
		if (list.length() == 2)
		{ 
			msg->from(list.last());
			msg->Realfrom(list.first()); 
			if (msg->Realfrom().length() <= 0)
			{
				return;
			}
			msg->MsgDirection(Biz::MessageDirection::MessageTypeOther);
			msg->MsgSourceType(Biz::consult);
			Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
		} 

}

void ConsultChatDialog::preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool& bshow)
{
	ChatDialog::preFormatMessageToHtml(spMessage,isHistory,hasMore,bshow);

	//这里把虚拟账号的信息存放一下，如果有继续发生消息的情况
	//在这里保存realid和虚拟账号的关系
	if(spMessage->MsgSourceType() == Biz::MessageSourceType::consult)
	{
		QString conversationId = spMessage->ConversationID();
		QString virtualid = spMessage->virtualId();

		if (!UtilHelper::isVirtualAccountId(conversationId, Biz::Session::getSystemConfig()->getXmppDomain()))
		{
			if (isHistory)
			{
				virtualid = spMessage->virtualId();
			}
			else
			{
				virtualid = spMessage->from();
			}
			conversationId = Biz::XmppMessage::makeConsultConversation5Id(spMessage->ConversationID(),virtualid);
		}
		if (virtualid.isEmpty())
		{
			virtualid = UtilHelper::getvirtualfromID(conversationId);
		}
		//这里加一个判断，防止virtualid 错误了
		QString strvirtualid = UtilHelper::getvirtualfromID(conversationId);
		if (strvirtualid != virtualid)
		{
			virtualid = strvirtualid;
		}
		MainApp::UIFrame::getConversationController()->insertchatingvraccount(conversationId, virtualid);

		if ((spMessage->MediaType() == Biz::MediaTypeTransShop || spMessage->MediaType() == Biz::MediaTypeTransVisitor)
			&& (spMessage->MsgDirection() == Biz::MessageDirection::MessageTypeSelf) )
		{
			bshow = false;
		}

		if (!spMessage->virtualId().isEmpty())
		{
			mVirtualId = spMessage->virtualId();
		}
	}

}

void ConsultChatDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (spMessage.isNull())
		return;
	
	ChatDialog::messageSendPrepare(spMessage);


	spMessage->MsgSourceType(Biz::consult);
	spMessage->ConversationID(conversationId());
	spMessage->from(Biz::Session::getAccountManager()->accountData().userJid());
	spMessage->virtualId(mVirtualId);
	spMessage->Realto(mRealConversation);
	spMessage->Realfrom(Biz::Session::getAccountManager()->accountData().userJid());
	spMessage->Chatid( m_bIsSeat ? Biz::consultmsgType::OnDutyToVistor : Biz::consultmsgType::VistorToOnDuty);
	spMessage->qchatid( m_bIsSeat ? Biz::consultmsgType::OnDutyToVistor : Biz::consultmsgType::VistorToOnDuty);

}

void ConsultChatDialog::onRealConversationJidChange(const QString& virturalid,const QString& realJid)
{
	if (!m_bIsSeat && Biz::MessageUtil::compareJid(virturalid,conversationId()))
	{
		mRealConversation = realJid;
	}
}

QString ConsultChatDialog::getChatId()
{
	return QString::number( m_bIsSeat ? Biz::consultmsgType::OnDutyToVistor : Biz::consultmsgType::VistorToOnDuty);
}

void ConsultChatDialog::showSigleCreateMuc()
{
	QString conversion = Biz::MessageUtil::makeSureUserJid(mRealConversation);
	MainApp::UIFrame::getMainDialogController()->showCreateGroupDialog(conversion);
}

void ConsultChatDialog::onCloseRemoteSession()
{
	if ( MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(QStringLiteral("提示"),QStringLiteral("确认关闭会话？")) )
	{
		Biz::Session::getConverSationManager()->closeRemoteSession(mRealConversation,mVirtualId);
	}
}

