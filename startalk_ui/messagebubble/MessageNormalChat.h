#ifndef MESSAGENORMALCHAT_H
#define MESSAGENORMALCHAT_H
#include "MessageBubbleBase.h"
#include <functional>



namespace Biz
{
	class XmppMessage;
}


class MessageNormalChat : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageNormalChat();
	~MessageNormalChat();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

protected:
    QString objectToHtml(QSharedPointer<Biz::XmppMessage>& spMessage);

	QString parseAtInfo(const QSharedPointer<Biz::XmppMessage>& spMessage,const QString& htmlstr);


};

#endif // MESSAGEGROUPNOTICE_H
