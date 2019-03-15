#include "MessageActionRichText.h"
#include "XmppMessage.h"


MessageActionRichText::MessageActionRichText()
{

}

MessageActionRichText::~MessageActionRichText()
{

}

int MessageActionRichText::getMessageType()
{
	return Biz::subscription;
}

int MessageActionRichText::getMessageMediaType()
{
	return Biz::MediaTypeActionsRichText;
}

bool MessageActionRichText::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg, QString& htmlString)
{
	if (msg.isNull())
		return false;

	const QString ROBOT_ACTION_RICH_TEXT =
		"<div class='msg_white_fill_center' >"
		"    <div class='bubble9 white-center'>"
		"        <div class='active_rich_header'><img src='%1' class='active_rich_header_image'>"
		"            <div class='active_rich_header_info'>"
		"                <span class='active_rich_header_info_text'>%2</span>"
		"            </div>"
		"        </div>"
		"        <div class='active_divider'></div>"
		"        %3"
		"    </div>"
		"</div>";
	QString strJsonData = msg->Body();
	QVariantMap jsonMap = QJsonDocument::fromJson(strJsonData.toUtf8()).toVariant().toMap();
	QString introduce = jsonMap["introduce"].toString();
	QString linkurl = jsonMap["linkurl"].toString();
	QString imageurl = jsonMap["imageurl"].toString();
	QVariant subtitles = jsonMap["subtitles"];
	QString items;
	TransRobotActionRichTextItem(items, subtitles);

	htmlString = QString(ROBOT_ACTION_RICH_TEXT).arg(QUrl(imageurl).toEncoded(), introduce.toHtmlEscaped(), items);
	return true;
}

bool MessageActionRichText::TransRobotActionRichTextItem(QString& htmlString, QVariant subtitles)
{
	
	const QString ROBOT_ACTION_RICH_TEXT_ITEM =
		"<div class='active_rich_header_info_item'>"
		"    <table class='active_rich_header_info_item_content'>"
		"        <tbody class='d_out' onmouseover=\"this.className=\'d_over\'\" onmouseout=\"this.className=\'d_out\'\" onclick=\"openUrl(\'%1')\">"
		"        <tr>"
		"            <td>%2</td>"
		"            <td class='active_rich_header_info_item_picture' align='right'><img src='%3' class='active_rich_header_info_item_picture'></td>"
		"        </tr>"
		"        </tbody>"
		"    </table>"
		"     <div class='active_divider'></div>"
		"</div>";

	QVariantList jsonList = subtitles.toList();
	for (QVariant item : jsonList)
	{
		QVariantMap jsonMap = item.toMap();
		QString linkurl = jsonMap.value("linkurl").toString();
		QString iconurl = jsonMap.value("iconurl").toString();
		QString introduce = jsonMap.value("introduce").toString();
		QString itemHtml = QString(ROBOT_ACTION_RICH_TEXT_ITEM).arg(QUrl(linkurl).toEncoded(), introduce.toHtmlEscaped(), QUrl(iconurl).toEncoded());
		htmlString += itemHtml;
	}

	return true;
}

bool MessageActionRichText::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("机器人消息");
	return true;
}
