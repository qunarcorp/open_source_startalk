#ifndef MessageEmotion_H
#define  MessageEmotion_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageEmotion : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageEmotion();
	~MessageEmotion();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
#endif //  MessageEmotion_H
