#ifndef MessageVoice_H
#define MessageVoice_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageVoice : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageVoice();
	~MessageVoice();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
#endif // MessageVoice_H
