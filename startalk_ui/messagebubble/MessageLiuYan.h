#pragma once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageLiuYan : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageLiuYan();
	~MessageLiuYan();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
	QString GetCurrentTm(quint64 tm);
};
