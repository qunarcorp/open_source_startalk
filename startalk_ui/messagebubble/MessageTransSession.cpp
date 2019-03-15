#include "MessageTransSession.h"
#include "XmppMessage.h"


#include "Session.h"
#include "Account.h"
#include "AccountData.h"

MessageTransSession::MessageTransSession()
{

}

MessageTransSession::~MessageTransSession()
{

}

int MessageTransSession::getMessageMediaType()
{
	return Biz::MediaTypeTransShop;
}

bool MessageTransSession::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg, QString& htmlString)
{
	if (msg.isNull())
		return false;

	const QString TRANSFER_TEXT_SIMPLE =
		"<div class=\"kx\" align=\"center\">"
		"	<div  class=\"mc-info-sender balloon-info\">"
		"		<div class=\"balloon-inside\">"
		"			<table class=\"bubble9 mc-remote-redpack\" align=\"center\">"
		"				<tr>"
		"					<td style=\"vertical-align:middle;font-family:%4\">"
		"						<span class=\"infoMsg\" >"
		"						<span>%1</span>"
		"						<span style = \" color:#209fff\">%2</span>"
		"						<span>%3</span>"
		"						<a href=\"#\"><span class=\"transercss\" onclick=\"onchangeclicked('%6')\">%5</span></a>"
		"						</span>"
		"					</td>"
		"				</tr>"
		"			</table>"
		"		</div>"
		"	</div>"
		"</div>";

	QString strExterInfo = msg->Body();

	QByteArray Date = strExterInfo.toUtf8();
	QString from;         //来自哪里

	QJsonParseError Json_Parse_Error;
	QJsonDocument Json_Data = QJsonDocument::fromJson(Date, &Json_Parse_Error);
	if (Json_Parse_Error.error == QJsonParseError::NoError)
	{
		QVariantMap dataMap = Json_Data.toVariant().toMap();
		QString displayid = dataMap["f"].toString();
		if (msg->MsgSourceType() == Biz::MessageSourceType::consult)
		{
			from = Biz::MessageUtil::makeSureUserId(dataMap["u"].toString());
		}
		else
		from = dataMap["f"].toString();
		QString strreson = dataMap["r"].toString();

		QString strDisplayname = Biz::Session::currentAccount().getUserNameById(displayid);
		if (strDisplayname.isEmpty())
		{
			strDisplayname = from;
		}

		QString displaybefor = QStringLiteral("收到来自");
		QString displayafter = QStringLiteral("的会话转移,原因为：%1").arg(strreson);

		quint64 tm = QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer();
		QString strcurrentm = QDateTime::fromMSecsSinceEpoch(tm).toString("hh:mm:ss");

		htmlString = QString(TRANSFER_TEXT_SIMPLE).arg(strcurrentm + "  " + displaybefor).arg(strDisplayname).arg(displayafter)
			.arg(QStringLiteral("微软雅黑")).arg(QStringLiteral("历史会话")).arg(from);
	}
	return true;
}

bool MessageTransSession::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("会话转移");
	return true;
}
