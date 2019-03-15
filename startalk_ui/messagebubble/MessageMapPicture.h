#ifndef MESSAGEMAPPICTURE_H
#define MESSAGEMAPPICTURE_H
#include "MessageBubbleBase.h"



#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}


class MessageMapPicture : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageMapPicture();
	~MessageMapPicture();

	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
private:
	const static int sMediaType;
};

#endif // MESSAGEGROUPNOTICE_H
