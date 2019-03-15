#pragma once
#include <QObject>
#include "messagebubble/MessageBubbleBase.h"


// MessageDecoraterFrame* 代表顶级的消息气泡装饰,控制左右显示
// MessageDecoraterSkeleton* 二级气泡装饰，携带发送者，头像，时间信息，不包括气泡级内容
// MessageDecoraterBubbleWrapperSelf* 三级气泡，携带气泡，气泡状态属性，与气泡高度相同
// IMessageBubble 气泡核心，根据消息内容变化而变化。
// 嵌套时必须 顶层->二级->三级->气泡 嵌套


class MessageDecoraterFrameOther : public MessageDecoraterBase
{
public:
    MessageDecoraterFrameOther(QSharedPointer<IMessageBubble> bubble);
    ~MessageDecoraterFrameOther();
public:
    virtual int getMessageMediaType();
    virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
    virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);

    static QSharedPointer<IMessageBubble> decorate(const QSharedPointer<IMessageBubble>& bubble);
};

