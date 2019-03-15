#ifndef MESSAGEROBOTDEAL_H
#define MESSAGEROBOTDEAL_H

#include "MessageBubbleBase.h"


namespace Biz
{
    class XmppMessage;
}

class MessageRobotDeal : public MessageDecoraterImpl<IMessageBubble>
{
public:
    MessageRobotDeal();
    ~MessageRobotDeal();

    virtual int getMessageMediaType();

    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

    virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    virtual int getMessageType();

private:
    const static QString sRobotDealTemplete;
};

#endif // MESSAGEROBOTDEAL_H
