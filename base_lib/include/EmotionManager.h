#pragma once
#include "CoreObject.h"
#include <QList>
#include <QString>
#include <QMap>

#include "managerbase.h"

namespace Biz
{
	
	class EmotionItem;
	class EmoticonPackage;
	class EmoticonPackageInfo;
	class EmotionPackageListModule;

	class EmotionManager : public ManagerBase
	{
	    Q_OBJECT
	public:
	    EmotionManager();
	    ~EmotionManager();
	
	public:
	    virtual void initManager();
	    virtual void unInitManager();
	public:
		//personcfg中删除
		void deletePersonConfig(const QStringList& strdelUrllist);
		//删除表情包中的表情
		void DeleteEmotionList(const QString& pkgid, const QStringList& list );
		// 获取表情包内的所有表情
        QList<QSharedPointer<Biz::EmotionItem>> getEmotionList(const QString& pkgid);
		// 查找表情
        QSharedPointer<Biz::EmotionItem> findEmoticon(const QString& shortcut);
        QSharedPointer<Biz::EmotionItem> findEmoticon(const QString& pkgid,const QString& shortcut);
		// 保存本地的图片作为自定义表情
		void saveCustomEmojicon(const QString& emjPath, bool bsilent = false);
        // 添加一个网络的地址作为滴定仪表情
        void addCustomEmojicon(const QString& emotioncUrl);

		// 获取当前所有的表情包的id
        QStringList getEmoticonIds();

		// 获取表情包
        QSharedPointer<EmoticonPackage> getEmotionPackageInfo(const QString& pkgid);
		
		// 获取表情列表
        void getEmotionsPackages();
		// 下载表情包
        void downloadEmotionsPackage(const QSharedPointer<Biz::EmoticonPackageInfo> spEpi);

        void buildPersonConfig();

		//删除一个表情包
		void setDeletePackage(const QString& pkgid);

    public:
        void buildCuntomConfigration();
        void addACustomEmoj(const QString& shortcut,const QString& imagePath,const QString& imageUrl);
    protected:
        QStringList getImgsPathToMerge();
	private:
		// 加载本地的表情包，根据xml加载，完成后保存在 emoticonPackages 及 ids
	    bool innerLoadPackage(const QString& configPath);
		bool customEmotionPackageInit;
		public:
			static QString sCustomPackageName;
            const static QString sCustomEmotionAsyncKey;
	private:
		QMap<QString, QSharedPointer<EmoticonPackage> > emoticonPackages;
		// 表情包落地缓存
		Biz::EmotionPackageListModule *mEmotionListData;
signals:
		void sgDeleteCustomerEmotion(const QString&pkg);
		void sgSaveEmotionSuccess();

        void sgEmotionInfoListRecvied( const QList<QSharedPointer<Biz::EmoticonPackageInfo>>& list );

		void sgUpdateDescription(const QString& pkgid,const QString& descinfo);
		void sgDownloadPackageResult(const QString& pkgid,bool bResult);

		void sgReloadEmojiconPackage(const QString& pkgid);

        void sgUploadEmotionResult(bool bResult);
		void sgDownloadFinishEmotionPackage(const QString& pkgid);

		void sgDeleteEmotionPackage(const QString&pkgid);
        public slots:
             void onPersonCfgChange(const QStringList& changedKeys);
	};
	
	class EmotionItem
	{
	public:
	    EmotionItem(){}
	    EmotionItem(const EmotionItem &other)
	    {
	        faceId = other.faceId;
	        shortcut = other.shortcut;
	        thumbFile = other.thumbFile;
	        orgFile = other.orgFile;
	        strtip = other.strtip;
	        strPath = other.strPath;
	        key = other.key;
            strUrl = other.strUrl;
	    }
	
	    QString faceId;
	    QString shortcut;
	    QString thumbFile;
	    QString orgFile;
	    QString strtip;
	    QString strPath;
	    QString key;
        QString strUrl;
	};
	
	
	class EmoticonPackage
	{
	public:
	
	    QSharedPointer<EmotionItem> packageCoverImg;
	    QString strPackageDesc;
	    QString strPackageId;
	    int     nPackageVersion;
	    bool    bMiniData;
	
	
	    QMap<QString, QSharedPointer<EmotionItem>>  emotionMap;
        QList<QSharedPointer<EmotionItem>> emotionList;
	
	    EmoticonPackage(){}
	    EmoticonPackage(const EmoticonPackage &other)
	    {
	        emotionMap = other.emotionMap;
            emotionList = other.emotionList;
	    }
	    const EmoticonPackage& operator=(const EmoticonPackage &other)
	    {
	        emotionMap = other.emotionMap;
            emotionList = other.emotionList;
	        return *this;
	    }

	};
}
