#include "MessageDecoraterBubbleWrapperOther.h"
#include "XmppMessage.h"
#include "CustomDefine.h"

MessageDecoraterBubbleWrapperOther::MessageDecoraterBubbleWrapperOther(QSharedPointer<IMessageBubble> bubble)
    : MessageDecoraterBase(bubble)
{
}

MessageDecoraterBubbleWrapperOther::~MessageDecoraterBubbleWrapperOther()
{

}

int MessageDecoraterBubbleWrapperOther::getMessageMediaType()
{
    return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterBubbleWrapperOther::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	const QString strTemplateSingleImage = "<div class='bubberwrapperImage'><div data-id='%1' data-user='message' class='balloon-inside'>%2</div></div><div id='%1_voiceicon' class='voiceplayicon' style='%3'></div>";

    const QString strTemplate = "<div class='bubberwrapper'><div class=' bubble9 mc-remote-sender %1'> <div data-id='%2' data-user='message' class='balloon-inside'>%3</div></div><div id='%2_voiceicon' class='voiceplayicon' style='%4'></div></div>";


    if (!this->m_spDecorated->getTranslatedMessage(spMessage,htmlString)) 
        return false;

	if (spMessage->MediaType() == Biz::MediaTypeImageNew || spMessage->MediaType() == Biz::MediaTypeProblemList)
	{
		htmlString = QString(strTemplateSingleImage).arg(
			spMessage->MessageID(),
			htmlString,
			(Biz::MediaTypeVoice != spMessage->MediaType() || Biz::MESSAGESTATE_LOCAL_VOICEPLAYED == (Biz::MESSAGESTATE_LOCAL_VOICEPLAYED&spMessage->LocalFlag()))?"display:none":"display:default");

		return true;
	} 

    htmlString = QString(strTemplate).arg("",
        spMessage->MessageID(),
        htmlString,
        (Biz::MediaTypeVoice != spMessage->MediaType() ||  Biz::MESSAGESTATE_LOCAL_VOICEPLAYED == (Biz::MESSAGESTATE_LOCAL_VOICEPLAYED&spMessage->LocalFlag()))?"display:none":"display:default");
    return true;
}

bool MessageDecoraterBubbleWrapperOther::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}

QSharedPointer<IMessageBubble> MessageDecoraterBubbleWrapperOther::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
    return QSharedPointer<IMessageBubble>(new MessageDecoraterBubbleWrapperOther(bubble));
}