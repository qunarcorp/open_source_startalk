#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageVote : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageVote();
	~MessageVote();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};

class MessageVotePro : public MessageDecoraterImpl<IMessageBubble>
{
public:
    MessageVotePro();
    ~MessageVotePro();

    virtual int getMessageMediaType();

    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

    virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
};