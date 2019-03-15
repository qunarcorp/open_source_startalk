#include "MessageDecoraterFrameSelf.h"
#include "XmppMessage.h"

QSharedPointer<IMessageBubble> MessageDecoraterFrameSelf::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
    return QSharedPointer<IMessageBubble>(new MessageDecoraterFrameSelf(bubble));
}


MessageDecoraterFrameSelf::MessageDecoraterFrameSelf(QSharedPointer<IMessageBubble> bubble)
    : MessageDecoraterBase(bubble)
{
}

MessageDecoraterFrameSelf::~MessageDecoraterFrameSelf()
{
}

int MessageDecoraterFrameSelf::getMessageMediaType()
{
    return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterFrameSelf::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
    const QString strTemplate = "<div class='messageshareablewrapper'><input type='checkbox' name='messageshared' value='%2' class='messageshareableselector' style='display:%3;' onclick='onMessageShareSelect()'/><div class='self'> <div class='messagebubblewrapperframe'> %1 </div></div></div>";
    QString strContent;
    if (!m_spDecorated->getTranslatedMessage(spMessage,strContent))
        return false;
    QString displayFlag = (spMessage->DisplayFlag()&Biz::XmppMessage::MessageDisplayFlag::MDF_SHAREMESSAGE == Biz::XmppMessage::MessageDisplayFlag::MDF_SHAREMESSAGE)?"inline":"none";
    htmlString = QString(strTemplate).arg(strContent,spMessage->MessageID(),displayFlag);
    return true;
}

bool MessageDecoraterFrameSelf::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}
