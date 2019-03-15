#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageActionRichText : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageActionRichText();
	~MessageActionRichText();


	virtual int getMessageType() override;


	virtual int getMessageMediaType() override;


	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString) override;


	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body) override;
private:
	bool TransRobotActionRichTextItem(QString& htmlString, QVariant subtitles);


};
