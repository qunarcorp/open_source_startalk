#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageHotelQuestions : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageHotelQuestions();
	~MessageHotelQuestions();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};

