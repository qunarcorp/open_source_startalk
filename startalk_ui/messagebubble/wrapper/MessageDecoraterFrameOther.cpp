#include "MessageDecoraterFrameOther.h"
#include "XmppMessage.h"

MessageDecoraterFrameOther::MessageDecoraterFrameOther(QSharedPointer<IMessageBubble> bubble)
    : MessageDecoraterBase(bubble)
{
}

MessageDecoraterFrameOther::~MessageDecoraterFrameOther()
{

}

int MessageDecoraterFrameOther::getMessageMediaType()
{
    return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterFrameOther::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
    const QString strTemplate = "<div class='other'><input type='checkbox' name='messageshared' value='%2' class='messageshareableselector' style='display:%3;' onclick='onMessageShareSelect()'/><div class='messagebubblewrapperframe'>%1</div></div>";
    QString strContent;
    if (!m_spDecorated->getTranslatedMessage(spMessage,strContent))
        return false;

    QString displayFlag = (spMessage->DisplayFlag()&Biz::XmppMessage::MessageDisplayFlag::MDF_SHAREMESSAGE == Biz::XmppMessage::MessageDisplayFlag::MDF_SHAREMESSAGE)?"inline":"none";
    htmlString = QString(strTemplate).arg(
        strContent,spMessage->MessageID(),displayFlag);
    return true;
}

bool MessageDecoraterFrameOther::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{

    return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}

QSharedPointer<IMessageBubble> MessageDecoraterFrameOther::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
    return QSharedPointer<IMessageBubble>(new MessageDecoraterFrameOther(bubble));
}
