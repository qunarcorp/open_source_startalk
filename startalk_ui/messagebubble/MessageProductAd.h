#ifndef MessageProductAd_H
#define MessageProductAd_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageProductAd : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageProductAd();
	~MessageProductAd();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
#endif // MessageProductAd_H
