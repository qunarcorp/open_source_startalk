#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageRobotRichText : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageRobotRichText();
	~MessageRobotRichText();


	virtual int getMessageType() override;


	virtual int getMessageMediaType() override;


	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString) override;


	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body) override;

};
