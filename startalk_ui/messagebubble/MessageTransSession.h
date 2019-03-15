#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}


// A转移给B,这个消息是B收到消息之后的展示的方案。A的展示是用systemnotify做的

class MessageTransSession : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageTransSession();
	~MessageTransSession();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
