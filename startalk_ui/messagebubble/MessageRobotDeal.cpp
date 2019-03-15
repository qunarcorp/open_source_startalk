#include "MessageRobotDeal.h"
#include <QDateTime>
#include "XmppMessage.h"

#include "portraithelper.h"

const QString MessageRobotDeal::sRobotDealTemplete = 
    "  <div class=\"dealmsg_frame\">                                                                         "
    "  	<div class=\"time_frame\"> <span class=\"time_span\">%1</span> </div>                       "
    "  	<div class=\"content_frame\" >                                                                       "
    "  		<div><img class=\"img\" src=\"%2\"><span class=\"title\">#%4#</span></div>      "
    "  		<div class=\"splinediv\"><hr class=\"line\"> </div>                                              "
    "  		<div class=\"text\"><span class=\"text_span\">%5</span></div>  "
    "  		<button id=\"%3\"class=\"deal_btn\" onclick=\"javascript:window.location.href='%6'\">%7</button>                                                         "
    "  	</div>                                                                                               "
    "  </div>																								 "	;

MessageRobotDeal::MessageRobotDeal()
    : MessageDecoraterImpl<IMessageBubble>()
{

}

MessageRobotDeal::~MessageRobotDeal()
{

}

int MessageRobotDeal::getMessageMediaType()
{
    return Biz::MediaTypeRobotQiangDan;
}
int MessageRobotDeal::getMessageType()
{
    return Biz::subscription;
}


bool MessageRobotDeal::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;
    QString strJsonData = spMessage->ExtendInfo();
    QVariantMap jsonMap = QJsonDocument::fromJson(strJsonData.toUtf8()).toVariant().toMap();

    QString title       = jsonMap.value("source").toString();
    QString content     = jsonMap.value("detail").toString();
    QString dealurl     = jsonMap.value("dealurl").toString();
    QString dealId      = jsonMap.value("dealid").toString();
    int nTimeOut        = jsonMap.value("timeout").toInt();

    QString senderHeadUrl  = Biz::PortraitHelper::getUserPortraitPath(spMessage->ConversationID());

    if( !QFile::exists(senderHeadUrl))
        senderHeadUrl = "./image/default_header.png";
    else
    {
        if (senderHeadUrl.at(0) == ':')
        {
            senderHeadUrl = "./image/default_header.png";
        }
        else
        {
            senderHeadUrl = "file:///" + senderHeadUrl;
        }
    }

    QJsonObject jobj;
    jobj.insert("msgid",spMessage->MessageID());
    jobj.insert("dealid",dealId);
    QString paramString = QJsonDocument(jobj).toJson(QJsonDocument::Compact);
    QUrl callbackUrl("localscheme://windows.robot.deal");
    QUrlQuery quq(callbackUrl);
    quq.addQueryItem("param",paramString);
    callbackUrl.setQuery(quq);

    QString timeStr = QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("hh:mm MM-dd");
    htmlString = QString(sRobotDealTemplete).arg(
        timeStr,
        senderHeadUrl,
        dealId + "_btndeal",
        title,
        content,
        callbackUrl.toString(),
        QStringLiteral("抢单"));

    return true;
}

bool MessageRobotDeal::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("来生意了");
    return true;
}

