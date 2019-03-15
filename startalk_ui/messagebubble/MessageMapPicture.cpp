#include "MessageMapPicture.h"
#include "XmppMessage.h"


#include "MessageBubbleWrapper.h"

const int MessageMapPicture::sMediaType = Biz::MediaTypeMapPicutre; 

const QString gMessageFormat = 
	"<table>\
	<tbody>\
	<tr>\
	<td>\
	<div class=\"mapimage-panel\">\
	<div>\
	<img class=\"image\" src=\"%1\" title=\"%2\" onclick=\"openUrl('%4')\"></div>\
	<div class=\"textbk\"><span class=\"text\">%3</span></div>\
	</div>\
	</td>\
	</tr>\
	</tbody>\
	</table>";


MessageMapPicture::MessageMapPicture()
{
}

MessageMapPicture::~MessageMapPicture()
{
}

int MessageMapPicture::getMessageMediaType()
{
	return sMediaType;
}

bool MessageMapPicture::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
	QString locationJson = spMessage->ExtendInfo();
	QVariantMap jsonMap = QJsonDocument::fromJson(locationJson.toUtf8()).toVariant().toMap();
	if (!jsonMap.isEmpty())
	{
// 		{
// 				"adress": "中国北京市海淀区王庄路1号",
// 				"fileUrl": "file/v1/download/b/32c127f82566b3f0ff63f955bf8aafd5.jpg?name\u003d32c127f82566b3f0ff63f955bf8aafd5.jpg\u0026file\u003d32c127f82566b3f0ff63f955bf8aafd5.jpg\u0026fileName\u003d32c127f82566b3f0ff63f955bf8aafd5.jpg",
// 				"latitude": "40.003791",
// 				"longitude": "116.345609",
// 				"name": ""
// 		}


		QString picUrl = QString("http://api.map.baidu.com/staticimage?zoom=15&markerStyles=m,Y,0xFF0000&markers=%1,%2&center=%1,%2")
			.arg(jsonMap.value("longitude").toString(),jsonMap.value("latitude").toString());
		QString localtion = QStringLiteral("http://api.map.baidu.com/marker?location=%2,%1&title=我的位置&content=%3&output=html")
			.arg(jsonMap.value("longitude").toString(),jsonMap.value("latitude").toString(),jsonMap.value("adress").toString());
		QString displayinfo = jsonMap.value("adress").toString();
		picUrl = QUrl(picUrl).toEncoded();
		localtion = QUrl(localtion).toEncoded();
		htmlString = gMessageFormat.arg(picUrl,displayinfo,displayinfo,localtion);
		return true;
	}

	return false;
}

bool MessageMapPicture::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	body = QStringLiteral("[定位]");
	return true;
	
}
