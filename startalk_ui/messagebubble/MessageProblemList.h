#ifndef MessageProblemList_H
#define MessageProblemList_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}

class MessageProblemList : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageProblemList(void);
	~MessageProblemList(void);

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

private:
	bool getProblemListTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	bool getHintsTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString); 

};

#endif // MessageProblemList_H