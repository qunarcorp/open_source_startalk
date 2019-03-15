#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include <QObject>
#include <QSharedPointer>
#include <QMap>
#include "MessageBubbleBase.h"
namespace Biz
{
	class XmppMessage;
}

class MessageTypeKey;

class MessageParser : public MessageDecoraterImpl<IMessageBubble>
{
public:
	static MessageParser* getInstance();
public:
	bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
	bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
    bool getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js);


    bool decorateWithTimestame(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
    bool decorateWithReply(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);


private:
	void initParserMap();
	MessageParser();
	~MessageParser();
private:
	static QMap<MessageTypeKey,QSharedPointer<IMessageBubble>> typedParserMap;
    static QMap<int,QSharedPointer<IMessageBubble>> parserMap;
	static MessageParser* mInstance;
};
#endif // MESSAGEBUBBLEBASE_H
