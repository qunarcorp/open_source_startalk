#ifndef MessageChatNote_H
#define MessageChatNote_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageChatNote : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageChatNote();
	~MessageChatNote();

	virtual int getMessageMediaType();
	virtual int getMessageType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
protected:
	QString objectToHtml(QSharedPointer<Biz::XmppMessage>& spMessage);
};
#endif // MessageChatNote_H
