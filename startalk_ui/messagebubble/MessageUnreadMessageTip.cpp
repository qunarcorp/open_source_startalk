#include "MessageUnreadMessageTip.h"

const QString MessageUnreadTip::sKey = "unreadtipkey_57847cb4cfa94268b2d39f4e6e70ee6c";

int MessageUnreadTip::getMessageType()
{
    return Biz::MessageSourceType::RevertMsgType;
}

MessageUnreadTip::MessageUnreadTip()
{

}

MessageUnreadTip::~MessageUnreadTip()
{

}

int MessageUnreadTip::getMessageMediaType()
{
    return Biz::MessageMediaType::MediaTypeText;
}

bool MessageUnreadTip::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    //htmlString = QStringLiteral("<a id='%1'><table class='unreadtip'><tr><td class='spiderline'><div class='left'/></td><td class='center'>以下是未读消息</td><td class='spiderline'><div class='right'/></td><tr></table></a>").arg(MessageUnreadTip::sKey);
    return true;
}

bool MessageUnreadTip::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    return true;
}
