#include "MessageRobotRichText.h"
#include "XmppMessage.h"


MessageRobotRichText::MessageRobotRichText()
{

}

MessageRobotRichText::~MessageRobotRichText()
{

}

int MessageRobotRichText::getMessageType()
{
	return Biz::subscription;
}

int MessageRobotRichText::getMessageMediaType()
{
	return Biz::MediaTypeRichText;
}

bool MessageRobotRichText::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg, QString& htmlString)
{
	const QString ROBOT_RICH_TEXT =
		"<div class='msg_white_fill_center'>"
		"    <div class='bubble9 white-center'>"
		"        <div><span class='msg_selectable msg_text_title'>%1</span></div>"
		"        <div><span class='msg_selectable msg_text_text'>%2</span></div>"
		"        <div style='height:200px;overflow:hidden' align='center'><img src='%3' style='border: none;width: 100%;height: 100%;'>"
		"        </div>"
		"        <div style='padding-top: 4px;'><span class='msg_selectable msg_text_text'>%4</span>"
		"        </div>"
		"        <div style='height: 4px;'><span></span></div>"
		"        <div class='active_divider'><span></span></div>"
		"        <div class='d_out' onmouseover=\"this.className=\'d_over\'\" onmouseout=\"this.className=\'d_out\'\" onclick=\"openUrl(\'%5\')\">"
		"          <table width='100%'><tbody><tr><td class='msg_text_text'><span id='ondetail'>%6</span></td><td align='right'>...</td></tr></tbody></table></div>"
		"    </div>"
		"</div>";

	if (msg.isNull())
		return false;
	QString strJsonData = msg->Body();
	QVariantMap jsonMap = QJsonDocument::fromJson(strJsonData.toUtf8()).toVariant().toMap();

	QString description = jsonMap["introduce"].toString();
	QString title = jsonMap["title"].toString();
	QString linkUrl = jsonMap["linkurl"].toString();
	QString imageurl = jsonMap["imageurl"].toString();
	QString date = jsonMap["date"].toString();
	htmlString = QString(ROBOT_RICH_TEXT).arg(title, date, imageurl.toHtmlEscaped(), description, linkUrl.toHtmlEscaped(), QStringLiteral("阅读详情"));

	return true;
}

bool MessageRobotRichText::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("机器人消息");
	return true;
}
