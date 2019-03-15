#ifndef ADVINFORMANAGER_H
#define ADVINFORMANAGER_H

#include <QObject>
#include "managerbase.h"

namespace Biz
{
	enum AdvType
	{
		AdvType_Url = 1,
		AdvType_Image,
		AdvType_Video
	};
	enum AdvSourceType
	{
		AdvSourceType_Start,
		AdvSourceType_Pop
	};
	class AdvDataItem;
	class AdverConfigInfo;
	class AdvInforManager : public ManagerBase
	{
		Q_OBJECT

	public:
		AdvInforManager();
		~AdvInforManager();
		QList<QSharedPointer<Biz::AdvDataItem>> GetImageList();
	public:
		virtual void initManager();
		virtual void unInitManager();
		
        inline QSharedPointer<AdverConfigInfo>  getAdvConfigInfo(){return this->mAdvConfigInfo;};

		//传入json串，然后进行解析成自己的结构
		void ParsePopAdvInfor(const QString& str, Biz::UnitCallback<bool>* callback );
	private slots:
		void onLoginSuccess();
signals:
		void sgImages(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist);
        void sgShowAdvUrl(const QSharedPointer<Biz::AdvDataItem>& urlItem);
		void sgPopImages(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist);
	protected:
		void pareAdverData(int type=0);
	private:
		QSharedPointer<AdverConfigInfo> mAdvConfigInfo;
		QList<QSharedPointer<Biz::AdvDataItem>> imagelist; //图片
		QList<QSharedPointer<Biz::AdvDataItem>> urllist;       //url
		QList<QSharedPointer<Biz::AdvDataItem>> videolist;     //视频 
	};
}


#endif // ADVINFORMANAGER_H
