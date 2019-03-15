#ifndef MESSAGESINGLECHATVIDEO_H
#define MESSAGESINGLECHATVIDEO_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}

class MessageSingleChatVideo : public MessageDecoraterImpl<IMessageBubble>
{

public:
	MessageSingleChatVideo();
	~MessageSingleChatVideo();
	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body);
private:
	
};

#endif // MESSAGESINGLECHATVIDEO_H
