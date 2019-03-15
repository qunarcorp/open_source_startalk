#include "MessageControlRevokeMessage.h"
#include "XmppMessage.h"

#include "Session.h"
#include "AccountData.h"
#include "accountmanager.h"
#include "UserVcardManager.h"

MessageControlRevokeMessage::MessageControlRevokeMessage()
{

}

MessageControlRevokeMessage::~MessageControlRevokeMessage()
{

}

int MessageControlRevokeMessage::getMessageMediaType()
{
    return Biz::MediaTypeRevokeMessage;
}

int MessageControlRevokeMessage::getMessageType()
{
    return Biz::revoke;
}

bool MessageControlRevokeMessage::getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString strJson = spMessage->Body();
    QVariantMap dataMap = QJsonDocument::fromJson(strJson.toUtf8()).toVariant().toMap();
    QString strMsgId;
    QString strUserId;
    
    if (dataMap.contains("messageId"))
        strMsgId = dataMap.value("messageId").toString();
    
    if (dataMap.contains("fromId"))
        strUserId = Biz::MessageUtil::makeSureUserId(dataMap.value("fromId").toString());
    
    bool bSelf = Biz::MessageUtil::compareJid(strUserId,Biz::Session::getAccountManager()->accountData().UserID());
    if (!strMsgId.isEmpty())
    {
        js = QString("replaceMessage(\"%1_framework\",\"<div data-use='newline' class='fn-clearfix systemnotify'>%2</div>\")").arg(strMsgId,(bSelf?QStringLiteral("你"):Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserJid(strUserId)))+QStringLiteral("撤回了一条消息"));
        return true;
    }
    return false;
}

bool MessageControlRevokeMessage::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if(spMessage.isNull())
		return false;
    QString strJson = spMessage->Body();
    QVariantMap dataMap = QJsonDocument::fromJson(strJson.toUtf8()).toVariant().toMap();
    QString strUserId;
	QString strUserIdbyDemo;

    if (dataMap.contains("fromId"))
        strUserIdbyDemo = dataMap.value("fromId").toString();//Biz::MessageUtil::makeSureUserId(dataMap.value("fromId").toString());
	strUserId = Biz::MessageUtil::makeSureUserId(strUserIdbyDemo);

    bool bSelf = Biz::MessageUtil::compareJid(strUserId,Biz::Session::getAccountManager()->accountData().UserID());

    htmlString = QString("<div data-use='newline' class='fn-clearfix systemnotify'>%2</div>").arg(
        (bSelf ? 
        QStringLiteral("你"):
        Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserIdbyDemo))
        +QStringLiteral("撤回了一条消息"));
   return true;
}

bool MessageControlRevokeMessage::getShotTranslatedMessage( QSharedPointer<Biz::XmppMessage> spMessage, QString&body )
{
	body = QStringLiteral("撤回了一条消息");
	return true;
}
