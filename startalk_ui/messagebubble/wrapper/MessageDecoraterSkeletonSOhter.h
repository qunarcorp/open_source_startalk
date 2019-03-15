#pragma once
#include <QObject>
#include "messagebubble/MessageBubbleBase.h"
class MessageDecoraterSkeletonSOhter : public MessageDecoraterBase
{
public:
    MessageDecoraterSkeletonSOhter(QSharedPointer<IMessageBubble> bubble);
    ~MessageDecoraterSkeletonSOhter();
public:
	virtual int getMessageMediaType();
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);

private:
    static QString sHtmlcode;
	static QString sHtmlcodeGroup;
};

