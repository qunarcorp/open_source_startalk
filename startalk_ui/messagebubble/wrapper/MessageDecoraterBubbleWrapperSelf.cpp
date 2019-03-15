#include "MessageDecoraterBubbleWrapperSelf.h"
#include "XmppMessage.h"

MessageDecoraterBubbleWrapperSelf::~MessageDecoraterBubbleWrapperSelf()
{

}

MessageDecoraterBubbleWrapperSelf::MessageDecoraterBubbleWrapperSelf(QSharedPointer<IMessageBubble> bubble)
    : MessageDecoraterBase(bubble)
{
}

int MessageDecoraterBubbleWrapperSelf::getMessageMediaType()
{
    return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterBubbleWrapperSelf::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
	const QString strTemplateSingleImage = "<div class='bubberwrapperImage'><div class='sendloadingwrap'><img id='%1_loadingimg' data-msgid='%1' data-sendfail='%3'  onclick='resendmessage(id);' src='%4' class='img' style='display:%5;'/></div> <div data-id='%1' data-user='message' class='balloon-inside'>%2</div></div>";


    const QString strTemplate = "<div class='bubberwrapper'><div class='sendloadingwrap'><img id='%1_loadingimg' data-msgid='%1' data-sendfail='%3'  onclick='resendmessage(id);' src='%4' class='img' style='display:%5;'/></div><div class='bubble9 mc-local-sender'> <div data-id='%1' data-user='message' class='balloon-inside'>%2</div></div></div>";

    int sendfail = MessageStatus::SendSuccess;
    if (spMessage->isMessageSendSuccess())
        sendfail = MessageStatus::SendSuccess;
    if (spMessage->isMessageSendFail())
        sendfail = MessageStatus::SendFail;
    if (spMessage->isMessageSending())
        sendfail = MessageStatus::Sending;

    QString strSengImg = (sendfail == MessageStatus::Sending)?"image/loading.gif":"image/tanhao.png";
    QString strDisplayValue = ((Biz::MessageSourceType::ChatMessage==spMessage->MsgSourceType() ||Biz::MessageSourceType::GroupMessage==spMessage->MsgSourceType() )&&sendfail != MessageStatus::SendSuccess)?"default":"none";

    if (!this->m_spDecorated->getTranslatedMessage(spMessage,htmlString))
        return false;

	if (spMessage->MediaType() == Biz::MediaTypeImageNew || spMessage->MediaType() == Biz::MediaTypeImageNew)
	{
		htmlString = QString(strTemplateSingleImage).arg(
			spMessage->MessageID(),
			htmlString,
			QString::number(sendfail),
			strSengImg,
			strDisplayValue);
		return true;
	}

    htmlString = QString(strTemplate).arg(
        spMessage->MessageID(),
        htmlString,
        QString::number(sendfail),
        strSengImg,
        strDisplayValue);
    return true;
}

bool MessageDecoraterBubbleWrapperSelf::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}

QSharedPointer<IMessageBubble> MessageDecoraterBubbleWrapperSelf::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
    return QSharedPointer<IMessageBubble>(new MessageDecoraterBubbleWrapperSelf(bubble));
}
