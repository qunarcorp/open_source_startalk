#include "MessageProductAd.h"
#include "XmppMessage.h"


const QString PRODUCT_BODY_HTML_TEMPLATE=
    "<a href='javascript:openUrl(\"%1\")'>"
    "	<table class=\"mod-home-onSale\">"
    "		<tr>"
    "			<td rowspan=\"3\" class=\"mod-left-image\">"
    "			<img class=\"mod-left-image-span\" src=\"%2\">"
    "			</td>"
    "		</tr>"
    "		<tr>"
    "		<td colspan=\"2\">"
    "		<div class=\"mod-title\">%3</div>"
    "		</td>"
    "		</tr>"
    "		<tr>"
    "		<td>"
    "		<div class=\"mod-price\"><em>%4</em>								</div>"
    "		</td>"
    "		<td>"
    "		<div class=\"onSale-body-left-words-bottom clrfix\">"
    "		<span class =\"market-markprice\">%5<span>%6</span>	</span></div>"
    "		</td>"
    "		</tr>"
    "		</table>"
    "		</a>";


MessageProductAd::MessageProductAd()
{

}

MessageProductAd::~MessageProductAd()
{

}

int MessageProductAd::getMessageMediaType()
{
    return Biz::MediaTypeProductInfo;
}

bool MessageProductAd::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    QString body = spMessage->Body();
    QString strTitle;
    QString qprice;
    QString markprice;
    QString weburl;
    QString strType;
    QString strimgurl;

    QString strExenInfor = body;

    QByteArray ba;
    ba = strExenInfor.toUtf8();
    QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
    if(Json_Data.isObject())
    {
        QVariantMap result = Json_Data.toVariant().toMap();
        QVariantMap strdata = result["data"].toMap();
        strTitle = strdata["title"].toString();
        strType = strdata["type"].toString();
        strimgurl = strdata["imageUrl"].toString();
        qprice = strdata["price"].toString();
        markprice = strdata["marketPrice"].toString();
        weburl = strdata["webDtlUrl"].toString();

    }
    else
    {
        return false;
    }
    QString strAfterTitle;
    if (strTitle.length() > 50 )
    {
        strAfterTitle = strTitle.left(50);
        strAfterTitle += "...";
    }
    else
    {
        strAfterTitle = strTitle;
    }
    htmlString = QString(PRODUCT_BODY_HTML_TEMPLATE).arg(weburl).arg(strimgurl).arg(strAfterTitle)
        .arg(qprice).arg(QStringLiteral("门市价：¥")).arg(markprice);

    return true;
}

bool MessageProductAd::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[产品推荐]");
    return true;
}
