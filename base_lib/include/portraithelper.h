#ifndef PORTRAITHELPER_H
#define PORTRAITHELPER_H

#include <QObject>
#include <QPixmap>
#include "SystemDefine.h"
namespace Biz
{
	extern const int HDEAULT_IMAGE_SIZE;
    extern const int DEAULT_IMAGE_SIZE;
    extern const QString DEFAULT_PATH_ROBOT;
    extern const QString DEFAULT_PATH_USER;
    extern const QString DEFAULT_PATH_GROUP;
    extern const QString DEFAULT_PATH_ROBOT_NOTICE;
    extern const QString DEFAULT_PATH_ROBOT_SUBJECT;


	class PortraitHelper : public QObject
	{
	    Q_OBJECT
	public:
		static QPixmap loadPixmap(const QString& path,int scaledSize = DEAULT_IMAGE_SIZE);
        static QPixmap getUserPortrait(const QString& userid,int scaledSize = DEAULT_IMAGE_SIZE);
        static QPixmap getUserProtraitByDefault(const QString& userid,const QString& defaultPath, int scaledSize = DEAULT_IMAGE_SIZE);
        static QPixmap getUserPortraitWithoutDownload(const QString& userid, int scledSize);
        static QImage  getUserPortraitImage(const QString& userid);
        static QImage  getUserPortraitGrayImage(const QString& userid);
        static QPixmap getGroupPortrait(const QString& groupjid);
        static QImage  getGroupPortraitImage(const QString& groupjid);
        static QPixmap  getGroupPortraitWithNoticeFlag(const QString& groupid);
        static void     updateUserPortrait(const QString& userid, int size = DEAULT_IMAGE_SIZE, const QString&suffer="png");
		static QImage  loadDefaultImage();
		static QImage   loadCombinationImage(const QString&id, const QString& defaultImagePath);
		static QString  getUserRawPortraitPath(const QString& userid,bool& rawExist);
		static QString getGifCovertPng(const QString& sourceFilePath, const QSize& size );
		
    public:
        static QString  getUserPortraitPath(const QString& userid);
        static QString  getUserPortraitPath(const QString& userid,const QString& defaultPath);
        static QString  getGroupPortraitPath(const QString& groupjid);
    private:
        
        static QString  _userDefaultPortraitPath(const QString& userid,const QString& filepath);
    private:
        static QString getfileBasePahtbyfilepathName(const QString&filePath);
        static QImage  loadImage(const QString& path);
        static QImage  loadGrayImage(const QString& path);
		static QImage LoadImageFromPath(const QString& filepath);
		
		static bool IsExistInPixmap(const QString& filepath);

    private:
        static QMap<QString,QPixmap> pixmaps;
        static QMap<QString,QImage> images;
		
		//这两个map存放的是图片userid 所对应的QPixmap图片
		static QMap<QString, QString> mPathToUserIdPixMap;    //(Path,idNUM）
		static QMap<QString , QPixmap> mUserIdToPixMap; //(idNUM, QPixmap)

		//这两个map存放的是图片userid 所对应的QImage图片
		static QMap<QString, QString> mPathToUserIdImgMap; //(Path, idNUM）
		static QMap<QString, QImage> mUserIdToImgMap; //(idNUM, QImage)


        static QMap<QString,QImage> grayImags;
        static QSharedPointer<QPixmap> emptyPixmap;

		//DispathThread mReadFileThread;
	};
}

#endif // PORTRAITHELPER_H
