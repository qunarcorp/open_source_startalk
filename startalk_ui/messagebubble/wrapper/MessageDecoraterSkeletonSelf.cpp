#include "MessageDecoraterSkeletonSelf.h"
#include "XmppMessage.h"

#include "Session.h"
#include "UserVcardManager.h"
#include "accountmanager.h"
#include "portraithelper.h"

#include "SettingData.h"


#include "MessageDecoraterBubbleWrapperSelf.h"

#include "LanguageHelper.h"
#include "SystemConfigData.h"

QSharedPointer<IMessageBubble> MessageDecoraterSkeletonSelf::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
    return QSharedPointer<IMessageBubble>(new MessageDecoraterSkeletonSelf(bubble));
}
MessageDecoraterSkeletonSelf::MessageDecoraterSkeletonSelf(QSharedPointer<IMessageBubble> bubble)
    : MessageDecoraterBase(bubble)
{
}

MessageDecoraterSkeletonSelf::~MessageDecoraterSkeletonSelf()
{

}

int MessageDecoraterSkeletonSelf::getMessageMediaType()
{
    return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterSkeletonSelf::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    if (!m_spDecorated->getTranslatedMessage(spMessage,htmlString))
        return false;

    // 发送者id
    QString senderid = Biz::Session::getAccountManager()->accountData().UserID();

    // 发送者头像
    QString senderHeadUrl = 
        Biz::PortraitHelper::getUserPortraitPath(Biz::Session::getAccountManager()->accountData().UserID());

    if (senderHeadUrl.at(0) == ':')
    {
        senderHeadUrl = "./image/default_header.png";
    }
    else
    {
		senderHeadUrl = Biz::PortraitHelper::getGifCovertPng(senderHeadUrl, QSize(90, 90));
        senderHeadUrl = QUrl::fromLocalFile(senderHeadUrl).toString() + "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
    }
	QString msgid = spMessage->MessageID();
	
    //发送端的时间戳
    QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString timemsg = QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd");
    QString timeStemp = (timecurrent==timemsg)?
        QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("hh:mm:ss") :
        QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd hh:mm:ss");

	QString Sfont = Biz::Session::getSettingConfig()->MFontFamily();

	QString strconversationId= spMessage->ConversationID();
	//由于qchat 发版，这个阅读状态的给先屏蔽掉
	if (!Biz::MessageUtil::isGroupJid(strconversationId) && Biz::Session::getSystemConfig()->NAV_ABILITI_ShowMsgStat())
	{
		QString msgstatusvalue = "";

		if (spMessage->isMessageSendSuccess()){
			msgstatusvalue = T_("MessageState_UnReaded");
		}

// 		if (spMessage->isMessageSendFail()){
// 			msgstatusvalue = QStringLiteral("发送失败");
// 		}

		if (spMessage->isMessageSending()){
			msgstatusvalue = QStringLiteral("发送中");
		}

		if (Biz::MESSAGESTATE_REMOTE_RECIVED == (Biz::MESSAGESTATE_REMOTE_RECIVED&spMessage->RemoteFlag()))
			msgstatusvalue = T_("MessageState_UnReaded");
		if (Biz::MESSAGESTATE_REMOTE_READED == (Biz::MESSAGESTATE_REMOTE_READED&spMessage->RemoteFlag()))
			msgstatusvalue = T_("MessageState_Readed");

		QString messagestateStyle = !msgstatusvalue.isEmpty() ? "":"display:none";
		htmlString = QString(sHtmlcode)
			.arg(
			senderHeadUrl,
			Biz::Session::getAccountManager()->accountData().FullName(),
			timeStemp,
			htmlString,
			Biz::MessageUtil::makeSureUserJid(senderid),
			msgid,
			messagestateStyle,
			msgstatusvalue);
	}
	else
	{
		htmlString = QString(sHtmlcodeGroup)
			.arg(
			senderHeadUrl,
			Biz::Session::getAccountManager()->accountData().FullName(),
			timeStemp,
			htmlString, Biz::MessageUtil::makeSureUserJid(senderid));
	}

    
  
    return true;

}

bool MessageDecoraterSkeletonSelf::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}


QString MessageDecoraterSkeletonSelf::sHtmlcodeGroup =
	"<table class=\"chat-message-left-table\">"
	"	<tr data-type=\"qtalk\"> "
	"		<td colspan='2' class='title' > "
	"			<div class='hideline'>"
	"				<span class='namehide'>%2</span>"
	"				<span class='tabtimehide'>%3</span>"
	"			</div>"
	"		</td>"
	"	</tr>"
	"	<tr data-type=\"qtalk\">"
	"		<td align='right'> %4 </td> "
	"		<td style=\"min-width:50px;\" align='center' valign='top' >"
	"			<img class='chat-message-left-table headimg' src='%1' data-resourcehead='%5'/> "
	"		</td>"
	"	</tr>"
	"</table>";



QString MessageDecoraterSkeletonSelf::sHtmlcode =
    "<table class=\"chat-message-left-table\">"
	"	<tr data-type=\"qtalk\"> "
	"		<td colspan='2' class='title' > "
	"			<div class='hideline'>"
	"				<span class='namehide'>%2</span>"
	"				<span class='tabtimehide'>%3</span>"
	"			</div>"
	"		</td>"
	"	</tr>"
	"	<tr data-type=\"qtalk\">"
	"		<td align='right'> %4 <div class=\"svalue\" data-id='%6' data-user='msgstatus' style='%7' >%8</div></td> "
	"		<td style=\"min-width:50px;\" align='center' valign='top' >"
	"			<img class='chat-message-left-table headimg' src='%1' data-resourcehead='%5'/> "
	"		</td>"
	"	</tr>"
	"</table>";

 //
