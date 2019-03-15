#pragma  once
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageGroupRoomVideo : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageGroupRoomVideo();
	~MessageGroupRoomVideo();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
	QString GetCurrentTm(quint64 tm);
};

class MessageLiveGroupRoomVideo : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageLiveGroupRoomVideo();
	~MessageLiveGroupRoomVideo();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
	QString GetCurrentTm(quint64 tm);
};
