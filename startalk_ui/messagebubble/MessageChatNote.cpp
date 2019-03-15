#include "MessageChatNote.h"
#include "XmppMessage.h"
#include "ConversationController.h"
#include "UIFrame.h"

QString mydecodeUrl(QString body, QMap<QString,QString>& guid2htmlstring)
{

	QString strResult = body;
	QRegExp regExp("(((ftp|https?)://|www.)[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})([^ ^\"^\\[^\\]^\\r^\\n]*))");    
	auto pos = 0;
	while ((pos = regExp.indexIn(body, pos)) != -1) {
		QString url = regExp.cap(0);
		QString rawUrl = QUrl(url).toEncoded();
		QString htmlString = QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,url.toHtmlEscaped());

		QString guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
		guid2htmlstring.insert(guid,htmlString);
		strResult.replace(strResult.indexOf(url),url.length(),guid);
		pos += regExp.matchedLength();
	}    

	return strResult;    
}

MessageChatNote::MessageChatNote()
{

}

MessageChatNote::~MessageChatNote()
{

}

int MessageChatNote::getMessageMediaType()
{
    return Biz::MessageTypeNote;
}

bool MessageChatNote::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

	QString body = spMessage->Body();
	//QByteArray bodyByte = body.toUtf8(); 
	spMessage->Body(body);
	
	QString msg;
    QString strExenInfor = body;

    QByteArray ba;
    ba = strExenInfor.toUtf8();
	QJsonParseError Json_Parse_Error;
	QJsonDocument Json_Data = QJsonDocument::fromJson(ba, &Json_Parse_Error);
	if (Json_Parse_Error.error == QJsonParseError::NoError)
	{
		if(Json_Data.isObject())
		{
			QVariantMap result = Json_Data.toVariant().toMap();


			QString newbody = QString::fromLocal8Bit(result["url"].toString().toLocal8Bit().data());
			//newbody = "QunariPhone://hy?url=https%3A%2F%2Ftouch.qunar.com%2Fplus%2Fproduct_detail%3Fpid%3D000291253336%26moduleId%3D439747%26sourceFrom%3Dvisa";
			//由于url发生变化，所以需要在这里进行判断一下
			//QunariPhone://hy?url=https%3A%2F%2Ftouch.qunar.com%2Fplus%2Fproduct_detail%3Fpid%3D000291253336%26moduleId%3D439747%26sourceFrom%3Dvisa
			if (newbody.contains("://hy?"))
			{
				QUrl url(newbody);
				QUrlQuery queryurl(url);
				newbody = queryurl.queryItemValue("url");
				newbody = QUrl::fromPercentEncoding(newbody.toLatin1());
			}

			spMessage->Body(newbody);
			htmlString = objectToHtml(spMessage);
			htmlString.replace(8232,'\n'); // --> 软回车变成硬回车
			return true;
		}
		else
		{
			Log::e("MessageChatNote::getTranslatedMessage  parse json is error Json_Data.isObject == NULL");
			return false;
		}
	}
    else
    {
		Log::e(QString("MessageChatNote::getTranslatedMessage  parse json is error=%1").arg(Json_Parse_Error.error));
        return false;
    }
   
    return true;
}

bool MessageChatNote::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[客人访问产品咨询]");
    return true;
}

QString MessageChatNote::objectToHtml( QSharedPointer<Biz::XmppMessage>& rawmsg )
{
	if(rawmsg.isNull())
		return "";
	QString strRawMsgBody = rawmsg->Body();
	QRegExp regExp("\\[obj type=[\\\\]?\"([^\"]*)[\\\\]?\" value=[\\\\]?\"([^\"]*)[\\\\]?\"(.*)\\]");    
	regExp.setMinimal(true);

	QStringList strHtmllist;
	// 把obj片段先匹配成 uuid ,然后将uuid匹配成 <a> 等标签,为了防止特殊字符带来的解析干扰
	QMap<QString,QString> item2Guid;
	QMap<QString,QString> guid2Html;

	auto pos = 0;
	while ((pos = regExp.indexIn(strRawMsgBody, pos)) != -1) 
	{
		QString item    = regExp.cap(0); // 符合条件的整个字符串  
		QString type    = regExp.cap(1); // 多媒体类型
		QString val     = regExp.cap(2); // 路径
		QString extPart = regExp.cap(3); // 宽高

		// 替换的key
		QString replaceKey = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", ""); 

		if( "url" == type) {
#pragma region linkparser
			QString rawUrl = QUrl(val).toEncoded();
			QString htmlString = QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,val.toHtmlEscaped());
			strHtmllist.append(htmlString);

			item2Guid.insert(item,replaceKey);
			guid2Html.insert(replaceKey,htmlString);
			strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
#pragma endregion linkparser
		}
		pos += replaceKey.length();
	}  

	strRawMsgBody = mydecodeUrl(strRawMsgBody,guid2Html);

	strRawMsgBody = strRawMsgBody.toHtmlEscaped();
	strRawMsgBody = strRawMsgBody.replace(" ","&nbsp;");
	strRawMsgBody = strRawMsgBody.replace("\r\n","<br/>");
	strRawMsgBody = strRawMsgBody.replace("\n","<br/>");

	foreach(QString key,guid2Html.keys()){
		strRawMsgBody.replace(key,guid2Html.value(key));
	}

	return strRawMsgBody;
}

int MessageChatNote::getMessageType()
{
	return Biz::Note;
}
