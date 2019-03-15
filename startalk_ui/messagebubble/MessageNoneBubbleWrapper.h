#pragma once

#include <QObject>
#include "messagebubble/MessageBubbleBase.h"

class MessageNoneBubbleWrapper : public MessageDecoraterBase
{
public:
	MessageNoneBubbleWrapper(QSharedPointer<IMessageBubble> bubble);
	~MessageNoneBubbleWrapper();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

private:
	QSharedPointer<IMessageBubble> spGroupOtherBubble;
	QSharedPointer<IMessageBubble> spSimpleOtherBubble;
	QSharedPointer<IMessageBubble> spSimpleSelfBubble;
};
