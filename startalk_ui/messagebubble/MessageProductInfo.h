#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageProductInfo : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageProductInfo();
	~MessageProductInfo();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
