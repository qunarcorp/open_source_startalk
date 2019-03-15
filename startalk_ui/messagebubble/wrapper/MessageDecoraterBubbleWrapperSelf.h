#pragma once

#include <QObject>
#include "messagebubble/MessageBubbleBase.h"

class MessageDecoraterBubbleWrapperSelf : public MessageDecoraterBase
{
public:
    enum MessageStatus
    {
        SendSuccess = 0,
        Sending     = 1,
        SendFail    = 2
    };
public:
	MessageDecoraterBubbleWrapperSelf(QSharedPointer<IMessageBubble> bubble);
	~MessageDecoraterBubbleWrapperSelf();
public:
	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);
};

