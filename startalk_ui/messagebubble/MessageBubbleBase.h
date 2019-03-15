#ifndef MESSAGEBUBBLEBASE_H
#define MESSAGEBUBBLEBASE_H

#include <QObject>
#include <QSharedPointer>
#include "XmppMessage.h"

class IMessageBubble{
public:
   
	virtual int getMessageMediaType() = 0;
    virtual int getMessageType() = 0;
	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString) = 0;
	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body) = 0;
    virtual bool getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js) = 0;
	virtual QString getTitle() = 0;
};

template <class T>
class MessageDecoraterImpl : public T{

public:
    virtual int getMessageType(){return Biz::UnKnow;}
    virtual int getMessageMediaType(){return Biz::UnKnow;};
    virtual bool getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js){return false;}
    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString){return false;};
    virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body) {return false;};
	virtual QString getTitle() {return "";};
};

class MessageDecoraterBase : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageDecoraterBase(QSharedPointer<IMessageBubble> bubble);
	~MessageDecoraterBase();
protected:
    QSharedPointer<IMessageBubble> m_spDecorated;
};


#endif // MESSAGEBUBBLEBASE_H
