#include "MessageLiuYan.h"
#include "XmppMessage.h"
#include "Session.h"
#include "ConfigureHelper.h"
MessageLiuYan::MessageLiuYan()
{

}

MessageLiuYan::~MessageLiuYan()
{

}

int MessageLiuYan::getMessageMediaType()
{
	return Biz::MediaTypeSystemLY;
}

bool MessageLiuYan::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg, QString& htmlString)
{
	const QString LY_BODY_HTML_TEMPLATE =
		"		<div class=\"balloon-inside\" style = \"background-color:#FFFFFF; border: 1px solid #d1d1d1; border-radius:5px;margin:1px;\" width=\"460\">"
		"           <div style=\"-webkit-user-select: text;margin:5px;\">"
		"				<span style=\"color:%5;font-family:%4;font-size:14px;display:block;word-break:break-all;padding-left:3px;padding-right:3px;\">"
		"                %6&nbsp;&nbsp;&nbsp;&nbsp;%7</span>"
		"           </div>"
		"			<div>"
		"					<hr style=\"vertical-align:middle;height:1px;border:none;border-top:1px solid #d1d1d1;margin-top:5px;margin-bottom:5px;\"/>"
		"			</div>"
		"			<div align=\"left\" style=\"margin:5px;\">"
		"				<span id ='%1_Left' style=\"color:%5;font-family:%4;font-size:14px;-webkit-user-select:text;\">%2</span>"
		"			</div>"
		"			<div>"
		"					<hr style=\"vertical-align:middle;height:1px;border:none;border-top:1px solid #d1d1d1;margin-top:5px;margin-bottom:5px;\"/>"
		"			</div>"
		"			<div id='sysmsg' style=\"margin:5px; \">"
		"					<span style=\"color:#666666;font-family:%4;font-size:14px;vertical-align:middle;\" onclick=\"onOpenUrl('%1')\">%3</span>"
		"			</div>"
		"		</div>";



	const QString NEWS_BODY_HTML_TEMPLATE_L =
		"<div  align=\"left\" class=\"other\" >                                                                                                                  \n"
		"	<table  width=\"460\">                                                                                                                               \n"
		"		<tr>                                                                                                                                             \n"
		"			<td width=\"50px\" rowspan=\"2\" align=\"center\"  valign=\"top\"><img src=\"%2\" width=\"30px\" height=\"30px\" />                          \n"
		"			</td>                                                                                                                                        \n"
		"			<td style=\"-webkit-user-select: text\"><span id= \"loaded\" style=\"font-size: 12px; color:#666666\">%3 %4</span>\n"
		"			</td>                                                                                                                                        \n"
		"		</tr>                                                                                                                                            \n"
		"		<tr>                                                                                                                                             \n"
		"			<td> <div class=\" bubble9 mc-remote-sender\"> %5</div>                            \n"
		"			</td>                                                                                                                                        \n"
		"		</tr>                                                                                                                                            \n"
		"		</table>                                                                                                                                         \n"
		"</div>																																					\n"
		;

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
	if (Json_Data.isObject())
	{

		QVariantMap result = Json_Data.toVariant().toMap();
		strTitle = result["title"].toString();
		strurl = result["link_url_pc"].toString();
		if (strurl.isEmpty())
		{
			strurl = result["linkurl"].toString();
		}
		strintroduce = result["content"].toString();
		strintroduce = strintroduce.replace("\r\n", "<br>");

	}

	if (strintroduce.length() > 100)
	{
		strintroduce = strintroduce.mid(0, 100);
		strintroduce += "...";
	}
	//QString timeStemp = QDateTime::fromMSecsSinceEpoch(msg->UtcTime()).toString("hh:mm:ss");
	QString timeStemp = GetCurrentTm(msg->UtcTime());

	//translatedBody = QString(LY_BODY_HTML_TEMPLATE).arg(msg->MessageID()).arg(strTitle,strintroduce).arg(QStringLiteral("查看全文")).arg(timeStemp).arg(QStringLiteral("微软雅黑"));



	QString htmlStringSystem = QString(LY_BODY_HTML_TEMPLATE).arg(msg->MessageID()).arg(strintroduce).arg(QStringLiteral("查看全文")).arg(QStringLiteral("微软雅黑")).arg("#000000").arg(strTitle).arg(timeStemp);

	//QString senderHeadUrl = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "\\resources\\defaultportrait.png";
	//htmlString = QString(NEWS_BODY_HTML_TEMPLATE_L).arg("file:///" + senderHeadUrl).arg(strTitle, timeStemp, htmlStringSystem);
	htmlString = htmlStringSystem;
	return true;
}

bool MessageLiuYan::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("[留言消息]");
	return true;
}


QString MessageLiuYan::GetCurrentTm(quint64 tm)
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