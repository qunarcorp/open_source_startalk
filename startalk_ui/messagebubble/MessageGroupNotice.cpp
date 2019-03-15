#include "MessageGroupNotice.h"
#include "XmppMessage.h"


const int sMediaType = Biz::MediaTypeGroupNotify; 
const QString sHtmlFormat = "<div class=\"groupchat-message-center-notify\">%1</div>";

MessageGroupNotice::MessageGroupNotice()
{
}

MessageGroupNotice::~MessageGroupNotice()
{
}

int MessageGroupNotice::getMessageMediaType()
{
	return sMediaType;
}

bool MessageGroupNotice::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{ 
	if (!spMessage.isNull())
	{
		htmlString = sHtmlFormat.arg(spMessage->Body());
		return true;
	}
	return false;
}

bool MessageGroupNotice::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
	body = spMessage->Body();
	return true;
}
