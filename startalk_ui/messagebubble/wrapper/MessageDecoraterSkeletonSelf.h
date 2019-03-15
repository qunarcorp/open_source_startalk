#pragma once

#include <QObject>
#include "messagebubble/MessageBubbleBase.h"


class MessageDecoraterSkeletonSelf : public MessageDecoraterBase
{
public:
	MessageDecoraterSkeletonSelf(QSharedPointer<IMessageBubble> bubble);
	~MessageDecoraterSkeletonSelf();
public:
	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);

private:
    static QString sHtmlcode;
	static QString sHtmlcodeGroup;
};


