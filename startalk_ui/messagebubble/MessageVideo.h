#ifndef MessageVideo_H
#define  MessageVideo_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageVideoFile : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageVideoFile();
	~MessageVideoFile();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};
#endif //  MessageVideo_H
