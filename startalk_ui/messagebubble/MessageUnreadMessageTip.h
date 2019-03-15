#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}

class MessageUnreadTip : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageUnreadTip();
	~MessageUnreadTip();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    virtual int getMessageType();

   const static QString sKey;

};
