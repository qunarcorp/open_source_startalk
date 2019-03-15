#ifndef MessageSystemmessage_H
#define MessageSystemmessage_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageSystemmessage : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageSystemmessage();
	~MessageSystemmessage();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
protected:
	QString GetCurrentTm(quint64 tm);

};
#endif // MessageSystemmessage_H
