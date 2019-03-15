#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageAddingFriend : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageAddingFriend();
	~MessageAddingFriend();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
