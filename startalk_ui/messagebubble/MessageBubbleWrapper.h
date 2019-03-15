#ifndef MESSAGEBUBBLEWRAPPER_H
#define MESSAGEBUBBLEWRAPPER_H

#include <QObject>
#include "messagebubble/MessageBubbleBase.h"

class MessageBubbleWrapper : public MessageDecoraterBase
{
public:
	MessageBubbleWrapper(QSharedPointer<IMessageBubble> bubble);
	~MessageBubbleWrapper();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

private:
	QSharedPointer<IMessageBubble> spGroupOtherBubble;
	QSharedPointer<IMessageBubble> spSimpleOtherBubble;
	QSharedPointer<IMessageBubble> spSimpleSelfBubble;
};

#endif // MESSAGEBUBBLEGROUPLEFT_H
