#include "MessageRobotQiangdan.h"
#include <QDateTime>
#include "XmppMessage.h"

#include "portraithelper.h"
#include "./jsonobject/hotels.h"

const QString MessageRobotQiangDan::sRobotQiangdanTemplete = 
    "  <div class=\"dingdanmsg_frame\">                                                                         "
    "  	<div class=\"time_frame\"> <span class=\"time_span\">%1</span> </div>                       "
    "  	<div class=\"content_frame\" >                                                                       "
    "  		<div><span class=\"title\">%2</span></div>      "
    "  		<div class=\"text\"><span class=\"text_span\">%3</span></div>  "
    "  	</div>                                                                                               "
	"  	<div> <button id=\"%4\"class=\"deal_btn\" data-user=\"%4\" %7 onclick=\"onOpenUrl('%5')\">%6</button></div> "
    "  </div>																								 "	;

MessageRobotQiangDan::MessageRobotQiangDan()
    : MessageDecoraterImpl<IMessageBubble>()
{

}

MessageRobotQiangDan::~MessageRobotQiangDan()
{

}

int MessageRobotQiangDan::getMessageMediaType()
{
    return Biz::MediaTypeRobotYYQiangDan;
}
int MessageRobotQiangDan::getMessageType()
{
    return Biz::subscription;
}


bool MessageRobotQiangDan::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;
	QString strJsonData = spMessage->ExtendInfo();
	if (!strJsonData.isEmpty())
	{ 
	
		QVariantMap jsonMap = QJsonDocument::fromJson(strJsonData.toUtf8()).toVariant().toMap();
		QString strtitle = jsonMap.value("title").toString();
		QString strdealid = jsonMap.value("dealId").toString();
		QString strdealurl = jsonMap.value("dealUrl").toString();
		QString strDisplay = jsonMap.value("btnDisplay").toString(); 
		QVariant strcontentdetail = jsonMap["detail"];

		QVariantMap detailMap = strcontentdetail.toMap();
		QString strbudgetinfor = detailMap.value("budgetInfo").toString();
		QString strordertime = detailMap.value("orderTime").toString();
		QString stremarks = detailMap.value("remarks").toString();
		QString strContent = QStringLiteral("%1<br>%2<br>%3").arg(strbudgetinfor, strordertime, stremarks); 

		QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
		QString timemsg = QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd");
		QString timeStr = (timecurrent==timemsg)?
			QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("hh:mm:ss") :
			QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd hh:mm:ss");
		//这地方需要知道此消息是否是已经被抢的
		if(spMessage->Checked())
		{
			strDisplay = spMessage->BackupInfo();
			htmlString = QString(sRobotQiangdanTemplete).arg(
				timeStr,
				strtitle,
				strContent,
				strdealid + "_btndeal",
				strdealurl,
				strDisplay, "disabled=\"disabled\"");
		}
		else
		{
			htmlString = QString(sRobotQiangdanTemplete).arg(
				timeStr,
				strtitle,
				strContent,
				strdealid + "_btndeal",
				strdealurl,
				strDisplay,"");
		}
		
		return true;
	}
	return false;

}

bool MessageRobotQiangDan::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
	if (spMessage->MediaType() == Biz::MediaTypeRobotYYQiangDan)
	{
		 body = QStringLiteral("来生意了");
	}
   
    return true;
}

