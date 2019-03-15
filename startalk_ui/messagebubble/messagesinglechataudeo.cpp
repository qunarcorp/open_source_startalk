#include "messagesinglechataudeo.h"

const QString AudioMessageTemplate = "<table class='voicemessagewrap' > <tr class='voicemessage'>\
									 <td><img class='img' src='%2' /></td>\
									 <td style='width:%3px;text-align:%5;'> %1</td>\
									 </tr></table>";

MessageSingleChatAudeo::MessageSingleChatAudeo()
{

}

MessageSingleChatAudeo::~MessageSingleChatAudeo()
{

}

int MessageSingleChatAudeo::getMessageMediaType()
{
	return Biz::MessageMediaType::MediaTypeaudioReceiveRtcAudio;
}

bool MessageSingleChatAudeo::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
	QString body = spMessage->Body();
	if (!body.isEmpty())
	{
		htmlString = AudioMessageTemplate.arg(body, "./image/audio.png");
		return true;
	}
	return false;
}

bool MessageSingleChatAudeo::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("[语音聊天]");
	return true;
}
