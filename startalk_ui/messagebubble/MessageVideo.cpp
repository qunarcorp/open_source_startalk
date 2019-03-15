#include "MessageVideo.h"
#include <QFileIconProvider>
#include "XmppMessage.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "ImageHelper.h"
#include "SystemDefine.h"

const QString VideoMessageTemplate = "<div><video  width=\"%2\" height=\"%3\" preload=\"none\" controls=\"controls\" poster=\"%4\">"
										"<source src=\"%1\" type=\"video/mp4\" />"
									 "</video> </div>";

const QString VideoMessageWapTemplate = "<div><img   src=\"%1\"  style='width:%2;height:%4' />"
									 "</div>";
MessageVideoFile::MessageVideoFile()
{

}

MessageVideoFile::~MessageVideoFile()
{

}

int MessageVideoFile::getMessageMediaType()
{
    return Biz::MediaTypeVideo;
}

bool MessageVideoFile::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull() || spMessage->MediaType()!=Biz::MediaTypeVideo)
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
  
	ThumbfileUrl = Biz::ConfigureHelper::makeFullUrl(ThumbfileUrl);

    videoFileUrl = Biz::ConfigureHelper::makeFullUrl(videoFileUrl);
	
    //htmlString = QString(VideoMessageTemplate).arg(videoFileUrl).arg(nWidth).arg(nHeight).arg(ThumbfileUrl);

	htmlString = QStringLiteral("视频：<a href='javascript:openUrl(\"%1\")'>%1</a> ").arg(videoFileUrl);
	//htmlString = QString(VideoMessageWapTemplate).arg(ThumbfileUrl).arg(nWidth).arg(nHeight);

    return true;
}

bool MessageVideoFile::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[视频文件]");
    return true;
}
