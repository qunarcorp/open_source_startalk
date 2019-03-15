#include "MessageBubbleBase.h"
#include "XmppMessage.h"

MessageDecoraterBase::MessageDecoraterBase(QSharedPointer<IMessageBubble> bubble)
    : m_spDecorated(bubble)
{
}   

MessageDecoraterBase::~MessageDecoraterBase()
{

}

