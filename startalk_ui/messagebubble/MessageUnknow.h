#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageUnknow : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageUnknow();
	~MessageUnknow();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};

class MessageClientCookie : public MessageUnknow {
public:
	virtual int getMessageMediaType() override;
};

class MessagePostBackCookie : public MessageUnknow {
public:
	virtual int getMessageMediaType() override;
	virtual int getMessageType() override;
};