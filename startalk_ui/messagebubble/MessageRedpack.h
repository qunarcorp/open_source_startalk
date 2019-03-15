#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageRedpack : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageRedpack();
	~MessageRedpack();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
