#pragma once
#include <QObject>
#include "messagebubble/MessageBubbleBase.h"

class MessageDecoraterSkeletonGOther : public MessageDecoraterBase
{
public:
    MessageDecoraterSkeletonGOther(QSharedPointer<IMessageBubble> bubble);
    ~MessageDecoraterSkeletonGOther();
public:
	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);

private:
    static QString sHtmlcode;
};
