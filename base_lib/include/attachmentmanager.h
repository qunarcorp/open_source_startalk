#ifndef ATTACHMENTMANAGER_H
#define ATTACHMENTMANAGER_H
#include <QObject>
#include "managerbase.h"
#include "Player.h"

namespace Biz
{
    class XmppMessageAttachment;

	class AttachmentManager : public ManagerBase
	{
		Q_OBJECT

	public:
		AttachmentManager();
		~AttachmentManager();
	public:
		virtual void initManager();
		virtual void unInitManager();


		void downloadAttachImage(const QString& conversationId, const QSharedPointer<Biz::XmppMessageAttachment>& attach);
        QSharedPointer<Biz::XmppMessageAttachment> getAttachmemtInfoByFileId(const QString& fileId);

        QSharedPointer<Biz::XmppMessageAttachment> getAttachmentInfoByUrl(const QString& strUrl);
		void getAttachmentInfoByUrl(const QString&url,Biz::UnitCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>* callback);

        // 不指定存储路径
        void dowloadAttachFile(const QString& messageID,Biz::UnitCallback<QString>* callback);

        void downloadAttachFileSaveTo(const QString& messageID,const QString& saveFolder,Biz::UnitCallback<QString>* callback);

        // 消息附件
        void saveMessageAttchmentInfo(const QSharedPointer<Biz::XmppMessageAttachment>& xma);
        void saveMessageAttchmentInfo(const QSharedPointer<Biz::XmppMessageAttachment>& xma,Biz::GeneralCallback* callback);

        void getFileLocalPathByMessageId(const QString& msgid,Biz::UnitCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>* callback);
        void getFileLocalPathByUrl(const QString& url,Biz::UnitCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>* callback);

        void loadAllAttachmentInfos(const QList<QSharedPointer<Biz::XmppMessageAttachment>>& xmas);
        
        void cancleSendFile(const QString& messageid);
		void insertImageAttachInfor(const QString& jid, const QSharedPointer<Biz::ImageAttachInfor> imageattachinfo );
		QSharedPointer <Biz::ImageAttachInfor> getImageAttachInforByImageId(const QString& jid,const QString&Id);
        QList <QSharedPointer <Biz::ImageAttachInfor>> getImageAttachlist(const QString&jid);
		void cleanImageAttachlistbyId(const QString&jid);
		void AttatchGifImageReplace();
	private:
		void GifconvertPng(const QString& filePath, const QString& msgid, int nwidth, int nheight);
		void initAttatchInfo();
		
	private:
        //QMap<QString, QSharedPointer<Biz::AttachMentInfo>> mAttachInfomap; // 内存太的，用于图片
        QMap<QString, QSharedPointer<Biz::XmppMessageAttachment>> mAttatchments; // 数据库太的，用于文件，有可能合二为一
		QMap<QString, QList <QSharedPointer<Biz::ImageAttachInfor>>> mImageAttachmap; 
		//由于时序的问题，导致下载完图片后，立即发送信号去更改图片，无效（有时候先下载完了，发了信号，但是html页面中的图片还没显示）
		QMap<QString, QString> mMsgidImageSrcmap;
		CallbackReceiver* mCallbackReceiver;
signals:
        //发送文件展示的进度条的信号
        void sgUploadProgressDisplay(const QString&key, const qint64 done, const qint64 total);
        void sgUploadProgressOver(const QString&key);

        void sgDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total);
		void sgDownloadProgressFinish(const QString&key, const QString& fileName, const QString& path);

		//替换gif大图
		void sgUpdateReplaceImage(const QString&msgid, const QString& fileTargePath);
	public slots:
		void onSuccessConnected();
	};
}
#endif // ATTACHMENTMANAGER_H
