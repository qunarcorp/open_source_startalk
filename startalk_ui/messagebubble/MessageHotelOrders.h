#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageHotelOrders: public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageHotelOrders();
	~MessageHotelOrders();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
