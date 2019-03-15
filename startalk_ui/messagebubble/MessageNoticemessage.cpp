#include "MessageNoticemessage.h"
#include "XmppMessage.h"
#include "ConversationController.h"
#include "UIFrame.h"
//class=\"bubble9 white-center\"
const QString NOTICENEWS_BODY_HTML_TEMPLATE = 
	"<div  align=\"center\" >"
	"	<div style=\"max-width:90%;\">"
	//"		<span id= \"loaded\" style=\"font-size: 12px; color:#666666\">%5</span>\n"
	"		<div class=\"bubble9 white-center-notable\" >"
	"			<div style=\"margin:-13px;\">"
	"				<div> "
	"					<span style=\"color:#000;font-family:%6;font-size:20px;padding-left:5px;-webkit-user-select:text;\">%2</span>"
	"				</div>"
	"				<div style=\"margin-top:4px;padding-left:5px; padding-bottom:4px;\"> "
	"					<span style=\"color:#a1a1a1;font-family:%5;font-size:16px;-webkit-user-select:text;\">%3</span>"
	"				</div>"
	"				<div>"
	"					<hr style=\"vertical-align:middle;height:1px;border:none;border-top:1px solid #d1d1d1;margin-top:5px;margin-bottom:5px;\"/>"
	"				</div>"
	"				<div id='sysmsg'>"
	"					<span style=\"color:#666666;font-family:%6;font-size:14px;padding-left:5px;\" onclick=\"onOpenUrl('%1')\" >%4</span>"
	"				</div>"
	"			</div>"
	"		</div>"
	"	</div>"
	"</div>";

MessageNoticemessage::MessageNoticemessage()
{

}

MessageNoticemessage::~MessageNoticemessage()
{

}

int MessageNoticemessage::getMessageMediaType()
{
    return Biz::MediaTypeNotice;
}

bool MessageNoticemessage::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg,QString& htmlString)
{
	if (msg.isNull())
	{
		return false;
	}
	QString strTitle;
	QString strurl;
	QString strintroduce;

	QString body = msg->Body();
	QByteArray ba;
	ba = body.toUtf8();
	QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
	if(Json_Data.isObject())
	{

		QVariantMap result = Json_Data.toVariant().toMap();
		strTitle = result["title"].toString();
		strurl = result["link_url_pc"].toString();
		if (strurl.isEmpty())
		{
			strurl = result["linkurl"].toString();
		}
		strintroduce = result["content"].toString();

	}
	mTitle = strTitle;
	if (strintroduce.length() > 100)
	{
		strintroduce = strintroduce.mid(0, 100);
		strintroduce += "...";
	}
	//QString timeStemp = QDateTime::fromMSecsSinceEpoch(msg->UtcTime()).toString("hh:mm:ss");
	QString timeStemp = GetCurrentTm(msg->UtcTime());

	//htmlString = QString(NOTICENEWS_BODY_HTML_TEMPLATE).arg(msg->MessageID()).arg(strTitle,strintroduce).arg(QStringLiteral("查看全文")).arg(timeStemp).arg(QStringLiteral("微软雅黑"));
	htmlString = QString(NOTICENEWS_BODY_HTML_TEMPLATE).arg(msg->MessageID()).arg(strTitle,strintroduce).arg(QStringLiteral("查看全文")).arg(QStringLiteral("微软雅黑"));

   
    return true;
}

bool MessageNoticemessage::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[%1]").arg(mTitle);
    return true;
}

QString MessageNoticemessage::GetCurrentTm( quint64 tm )
{
	QString timeStemp;
	QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	QString timemsg = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd");
	if (timecurrent == timemsg)
	{
		timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("hh:mm:ss");
	}
	else
	{
		timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd hh:mm:ss");
	}

	return timeStemp;
}

