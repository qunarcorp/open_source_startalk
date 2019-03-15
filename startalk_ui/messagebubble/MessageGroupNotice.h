#ifndef MESSAGEGROUPNOTICE_H
#define MESSAGEGROUPNOTICE_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}


class MessageGroupNotice : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageGroupNotice();
	~MessageGroupNotice();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

private:
	
};

#endif // MESSAGEGROUPNOTICE_H
