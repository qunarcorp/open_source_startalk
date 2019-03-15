#pragma once

#include <QObject>
#include "messagebubble/MessageBubbleBase.h"

class MessageDecoraterFrameSelf : public MessageDecoraterBase
{
public:
	MessageDecoraterFrameSelf(QSharedPointer<IMessageBubble> bubble);
	~MessageDecoraterFrameSelf();
public:
	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);

};

