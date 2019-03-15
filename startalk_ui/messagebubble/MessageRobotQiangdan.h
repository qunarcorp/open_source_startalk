#ifndef MESSAGEROBOTQIANGDAN_H
#define MESSAGEROBOTQIANGDAN_H

#include "MessageBubbleBase.h"


namespace Biz
{
    class XmppMessage;
}

class MessageRobotQiangDan : public MessageDecoraterImpl<IMessageBubble>
{
public:
    MessageRobotQiangDan();
    ~MessageRobotQiangDan();

    virtual int getMessageMediaType();

    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

    virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    virtual int getMessageType();

private:
    const static QString sRobotQiangdanTemplete;
};

#endif // MESSAGEROBOTQIANGDAN_H
