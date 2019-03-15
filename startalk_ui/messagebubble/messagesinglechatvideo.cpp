#include "messagesinglechatvideo.h"

const QString VideoMessageTemplate = "<table class='voicemessagewrap' > <tr class='voicemessage'>\
											<td><img class='img' src='%2' /></td>\
											<td style='width:%3px;text-align:%5;'> %1</td>\
										    </tr></table>";


MessageSingleChatVideo::MessageSingleChatVideo()
{

}

MessageSingleChatVideo::~MessageSingleChatVideo()
{

}

int MessageSingleChatVideo::getMessageMediaType()
{
	return Biz::MessageMediaType::MediaTypeaudioReceiveRtc;
}

bool MessageSingleChatVideo::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
	QString strbody = spMessage->Body();
	if (!strbody.isEmpty())
	{
		htmlString = VideoMessageTemplate.arg(strbody, "./image/vidio.png");
		return true;
	}
	return false;
}

bool MessageSingleChatVideo::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("[视频聊天]");
	return true;
}
