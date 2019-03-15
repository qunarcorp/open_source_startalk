#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include "managerbase.h"
namespace Biz
{
	class DownloadManager : public ManagerBase
	{
	    Q_OBJECT
	
	public:
	    DownloadManager();
	    ~DownloadManager();
    public:
        virtual void initManager();
        virtual void unInitManager();

	public:
        // folder 如果是相对路径，就放在默认的文件存储路径下，如果folder是存在的路径，那么就放在指定的目录下
		void downloadFile(
			const QString& url, 
			const QString& filename ,
			const QString& folder ,
			const QString& conversationId,
			bool autoRenameIfExist,
			Biz::UnitCallback<QString>* callback);

        void downloadFileWithProgress(
            const QString& url, 
            const QString& filename ,
            const QString& subFolder ,
            const QString& conversationId,
            bool autoRenameIfExist,
            Biz::ProgressedUnitCallback<QString,qint64>* callback);

		void downloadPortrait(
			const QString& url, 
			const QString& filename ,
			const QString& conversationId,
			bool autoRenameIfExist,
			Biz::UnitCallback<QString>* callback);

	public:
		void downloadFileForAllUser(const QString& url,Biz::ProgressedUnitCallback<QString,qint64>* callback,const QString& defaultSavePath=QString(),const QString& defaultSaveName=QString());
		//QString getImageLocalSavePath(const QString& url,const QString& conversationId);
		//QString getImageLocalSaveName(const QString& url);

	private:
		QString getfileName(const QString& strfilename);
		

signals:
		void sgDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total);
		void sgDownloadProgressFinish(const QString&key, const QString& fileName, const QString& path);
	private:
	    
	};
}

#endif // DOWNLOADMANAGER_H
