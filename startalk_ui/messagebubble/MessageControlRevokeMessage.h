#ifndef MessageControlRevokeMessage_H
#define MessageControlRevokeMessage_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageControlRevokeMessage : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageControlRevokeMessage();
	~MessageControlRevokeMessage();

	virtual int getMessageMediaType();

    virtual int getMessageType();

    virtual bool getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js);

    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString&body);
};
#endif // MessageControlRevokeMessage_H
