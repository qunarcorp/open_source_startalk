#include "MessageRedpack.h"
#include "XmppMessage.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"

MessageRedpack::MessageRedpack()
{

}

MessageRedpack::~MessageRedpack()
{

}

int MessageRedpack::getMessageMediaType()
{
	return Biz::MediaTypeRedPakage;
}

bool MessageRedpack::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg, QString& htmlString)
{
	const QString REDPACKAGE_TEXT_SIMPLE =
		"<div class=\"kx\" align=\"center\">"
		"	<div  class=\"mc-info-sender balloon-info\">"
		"		<div class=\"balloon-inside\">"
		"			<table class=\"bubble9 mc-remote-redpack\" align=\"center\">"
		"				<tr>"
		"					<td>"
		"						<img src=\"./image/HongbaoIcon.png\" width = 15 height=15 align=\"absbottom\"\"/>"
		"					</td>"
		"					<td style=\"vertical-align:middle;font-family:%4\">"
		"						<span class=\"infoMsg\" >"
		"						<span>%1<span style=\"color:#ff0000;\">%2</span>,%3</span>"
		"					</td>"
		"				</tr>"
		"			</table>"
		"		</div>"
		"	</div>"
		"</div>";

	if (msg.isNull())
		return false;

	QString strExterInfo = msg->ExtendInfo();

	QByteArray Date = strExterInfo.toLatin1();
	QString strUrl;         //红包页面
	QString strFromUser;   //发送红包的人
	QString strOpenUser;   //打开红包的人
	QString strType;      //红包类型 normal=普通红包,lucky=拼手气
	QString strTypeName; //红包类型字符串
	int Balance; //红包剩余个数

	QJsonParseError Json_Parse_Error;
	QJsonDocument Json_Data = QJsonDocument::fromJson(Date, &Json_Parse_Error);
	if (Json_Parse_Error.error == QJsonParseError::NoError)
	{
		QVariantMap dataMap = Json_Data.toVariant().toMap();
		strUrl = dataMap["Url"].toString();
		strFromUser = dataMap["From_User"].toString();
		strOpenUser = dataMap["Open_User"].toString();
		strType = dataMap["Type"].toString();
		strTypeName = dataMap["Typestr"].toString();
		Balance = dataMap["Balance"].toInt();


		QString strFromUserName = Biz::Session::currentAccount().getUserNameById(strFromUser);
		if (strFromUserName.isEmpty())
		{
			strFromUserName = strFromUser;
		}
		QString strOpenUserName = Biz::Session::currentAccount().getUserNameById(strOpenUser);
		if (strOpenUserName.isEmpty())
		{
			strOpenUserName = strOpenUser;

		}
		QString dataInfo;
		QString useridSelf = Biz::Session::currentAccount().accountData().UserID();
		if (useridSelf == strOpenUser)
		{
			if (useridSelf == strFromUser)
			{
				dataInfo = QStringLiteral("你领取了自己的");
			}
			else
			{
				dataInfo = QStringLiteral("你领取了%1的").arg(strFromUserName);
			}

		}
		else
		{
			dataInfo = QStringLiteral("%1领取了%2的").arg(strOpenUserName).arg(strFromUserName);
		}

		QString AfterInfo = Balance > 0 ? QStringLiteral("还剩%1个红包。").arg(Balance) : QStringLiteral("红包已领完。");
		htmlString = QString(REDPACKAGE_TEXT_SIMPLE).arg(dataInfo).arg(strTypeName).arg(AfterInfo).arg(QStringLiteral("微软雅黑"));
	}
	return true;
}

bool MessageRedpack::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body =  QStringLiteral("[红包消息]");
	return true;
}
