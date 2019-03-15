#include "MessageEmotion.h"
#include <QFileIconProvider>
#include "XmppMessage.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "ImageHelper.h"
#include "SystemDefine.h"

const QString VideoMessageTemplate = "<video  width=\"%2\" height=\"%3\" preload controls=\"controls\" poster=\"%4\">"
										"<source src=\"%1\" />"
									 "</video>";


MessageEmotion::MessageEmotion()
{

}

MessageEmotion::~MessageEmotion()
{

}

int MessageEmotion::getMessageMediaType()
{
    return Biz::MediaTypeVideo;
}

bool MessageEmotion::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull() || spMessage->MediaType()!=Biz::MediaTypeImageNew)
        return false;

    QByteArray byteary;
    byteary = spMessage->ExtendInfo().toUtf8();

    int Duration = 0;
    QString ThumbfileUrl;
    QString ThumbfileName;
	QString videoFileUrl;
	QString videoFileName;
	QString videoFileSize;
	int nHeight ;
	int nWidth;
    QJsonDocument Json_Data = QJsonDocument::fromJson(byteary);
    if(Json_Data.isObject())
    {
        QVariantMap result = Json_Data.toVariant().toMap();
        ThumbfileName = result["ThumbName"].toString();
		ThumbfileUrl = result["ThumbUrl"].toString();
		nHeight = result["Height"].toInt();
		nWidth = result["Width"].toInt();
		videoFileUrl = result["FileUrl"].toString();
		videoFileName = result["FileName"].toString();
		videoFileSize = result["FileSize"].toString();
		Duration = result["Duration"].toInt();  
    }

	Biz::ImageHelper::getImageScaleSize (nWidth,nHeight, 350, 550);
  
    videoFileUrl = Biz::ConfigureHelper::makeFullUrl(videoFileUrl);
	
    //htmlString = QString(VideoMessageTemplate).arg(videoFileUrl).arg(nWidth).arg(nHeight).arg(ThumbfileUrl);[obj type=\"url\" value=\"%1\"]

	htmlString = QStringLiteral("视频：<a href='javascript:openUrl(\"%1\")'>%1</a> ").arg(videoFileUrl);
    

    return true;
}

bool MessageEmotion::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[表情]");
    return true;
}
