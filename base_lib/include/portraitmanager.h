#ifndef PORTMANAGER_H
#define PORTMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "DispathThread.h"

namespace Biz
{
	class portraitManager : public ManagerBase
	{
		Q_OBJECT

	public:
		portraitManager();
		~portraitManager();

		virtual void initManager();

		virtual void unInitManager();
		//获取图像
		void getPixmap(const QString& id, int scaledSize, Biz::UnitCallback<QPixmap>* callback);

		void getPixmap(const QString& id, int scaledSize);
	private:
		QString getfileBasePahtbyfilepathName(const QString&filePath);
		//启动一个线程去读取文件
		void ThreadReadFile(const QString&filePath);

		//需要去另外的线程中下载该文件
		void DownloadFile(const QString&id);

		//把读取到的文件插入到相应的map中
		void insertmap(const QImage& image, const QString& filePath);
	private:
		DispathThread mReadFileThread;


		//这两个map存放的是图片userid 所对应的QPixmap图片
		QMap<QString, QString> mPathToUserIdPixMap;    //(Path,idNUM）
		QMap<QString , QPixmap> mUserIdToPixMap; //(idNUM, QPixmap)

		//这两个map存放的是图片userid 所对应的QImage图片
		QMap<QString, QString> mPathToUserIdImgMap; //(Path, idNUM）
		QMap<QString, QImage> mUserIdToImgMap; //(idNUM, QImage)

signals:
		void sgUpdatePixmap(const QString&userId, const QPixmap& pixmap);
	};
}
#endif // PORTMANAGER_H
