#ifndef MESSAGESINGLECHATAUDEO_H
#define MESSAGESINGLECHATAUDEO_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}


class MessageSingleChatAudeo : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageSingleChatAudeo();
	~MessageSingleChatAudeo();
	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body);
private:
	
};

#endif // MESSAGESINGLECHATAUDEO_H
