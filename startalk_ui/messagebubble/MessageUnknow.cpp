#include "MessageUnknow.h"
#include "XmppMessage.h"


MessageUnknow::MessageUnknow()
{

}

MessageUnknow::~MessageUnknow()
{

}

bool MessageUnknow::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	htmlString = QStringLiteral("本平台不支持的消息，或在手机端查看");
	return true;
}

bool MessageUnknow::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("本平台不支持的消息，或在手机端查看");
	return true;
}

int MessageClientCookie::getMessageMediaType()
{
	return Biz::MediaTypeClientCookie;
}

int MessagePostBackCookie::getMessageMediaType()
{
	return Biz::MediaTypeShockAndPostBackCookie;
}

int MessagePostBackCookie::getMessageType()
{
	return Biz::subscription;
}
