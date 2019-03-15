#ifndef MessageNoticemessage_H
#define MessageNoticemessage_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageNoticemessage : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageNoticemessage();
	~MessageNoticemessage();

	virtual int getMessageMediaType();


	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
protected:
	QString GetCurrentTm(quint64 tm);
private:
	QString mTitle;
};
#endif // MessageNoticemessage_H
