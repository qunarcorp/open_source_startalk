#ifndef MESSAGEMEETINGREMIND_H
#define MESSAGEMEETINGREMIND_H

#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}

class MessageMeetingRemind : public MessageDecoraterImpl<IMessageBubble> {
	public: 
		MessageMeetingRemind(void);
		~MessageMeetingRemind(void);   
		virtual int getMessageMediaType(); 
		virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString); 
		virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body); 
	private: 
		bool getMeetingRemindMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
};

#endif // MESSAGEMEETINGREMIND_H
