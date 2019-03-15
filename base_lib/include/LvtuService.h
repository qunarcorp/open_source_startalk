#ifndef LVTUSERVICE_H
#define LVTUSERVICE_H

#include "CoreObject.h"
#include "BizCallback.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include "XmppMessage.h"

#include "define.h"
#include "servicemanager.h"
namespace google{
	namespace protobuf{
		class Message;
	}
}

namespace ApiResponse{
	class UserLoginItem;
	class RosterProfile;
}



namespace Biz
{
	enum MessageMediaType;
	class Player;
	class AsyncRequest;
	class JsonResponse;
	class XmppMessage;
	class MessageListData;
	class StatisticsItem;
	class RosterList;
	class IHttpService;

	class LvtuService : public QObject
		, public Biz::IHttpService
	{
		Q_OBJECT

	public:
		LvtuService();
		~LvtuService();

	public:

		virtual QString getTkey();
		virtual QString getUser();
		// 文件系统
		void uploadAvatarWithCheck(const QString& filepath,Biz::ProgressedUnitCallback<QString,quint64>* callback);
		void uploadFileWithCheck(const QString& filepath,Biz::ProgressedUnitCallback<QString,quint64>* callback);
		void uploadImageWithCheck(const QString& filepath,Biz::ProgressedUnitCallback<QString,quint64>* callback);

		void uploadFileAfterCheck(
			const QString& type,		// [avatar|img|file]
			const QString& filePath,
			const QString& key,			// md5|uuid
			int size,					// file size
			const QString& name,			// file 时必须
			Biz::ProgressedUnitCallback<QString,quint64>* callback );
		virtual void getDownloadFile(const QString& urlimage,const QDir& idr, const QString& filename, Biz::ProgressedUnitCallback<QString,qint64>* callback);
		// 文件系统 end
		void getOnlineUsers( Biz::UnitCallback<QStringList>* callback);
		void setCancelSend(const QString& messageid);
		void updateVcard(const QString& userid, const QString& url);
		void updateMucVcard(const QString& muc_name, const QString& nickName, const QString& subject, const QString& desc, const QString& picUrl,
			Biz::UnitCallback<QVariantList>* callback, bool flage = true);
		void getServerTime(Biz::UnitCallback<qint64>* callback);

		inline void setUKParams(const QString& u,const QString& k){this->u = u;this->k = k;};

		void reportEvent(const QMap<QString,QVariant>& params);
		
		void setChatSelfInfo(const QString &strUserInfor,Biz::UnitCallback<QString>* callback);
		virtual void getCityByIpaddr(const QString& strIpaddr, Biz::UnitCallback<QString>* callback);
		void getProductionInfo(const QString& strProductId, const QString& businessid, Biz::UnitCallback<QVariantMap>* callback);
	public:
		void resetNetManager();
	private:
		void requstGet(const QString& url,const std::function<void(QNetworkReply*,int)>& callback, int retrytime=2);
		void requstPost(const QString& url,const QString& data,const std::function<void(QNetworkReply*,int)>& callback,int retrytime=2);
		bool doCheckFileMD5(const QString& strfilepath, const QString&md5);

		QString makeSecurityString(const QString& url, bool bret=true);
		QString makeSecurityChatString(const QString& body);
		static QString makeUrl(const QString& service);
		static QString makePicBurl(const QString& service);
	private:
		QNetworkAccessManager* mWebManager;
        QStringList m_tobecancleMessageIds;
		QString u;
		QString k;
	private:
		static QString IM_UPLOADFILEP;
		static QString IM_UPLOAD_LOGO;
	};

}

#endif // LVTUSERVICE_H
