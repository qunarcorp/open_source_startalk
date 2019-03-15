#ifndef QCLOUDMANAGER_H
#define QCLOUDMANAGER_H

#include "managerbase.h"
#include "loginmanager.h"
namespace Biz
{
	enum qCloudType
	{
		Password = 1,//密码箱
		ToDoList = 2,//
		Evenote = 3,//note 信息
		ChatPwdBox = 100 //会话密码密码箱
	};
	class qCloudManager : public ManagerBase
	{
		Q_OBJECT

	public:
		qCloudManager();
		~qCloudManager();

		virtual void initManager();

		virtual void unInitManager();

		void setSaveqcloudSunInfo(const QString& title, const QString& desc, const QString&content,int type, Biz::UnitCallback<bool>* callback );
		void setSaveqcloudMainInfo(const QString& title, const QString& desc, const QString&content,int type, Biz::UnitCallback<QString>* callback );
		void testEncrypt();
		void getqCloudMainKey(int type,Biz::UnitCallback<QString>* callback );
		void getqCloudSubKey(const QString& conversationId, Biz::UnitCallback<QString>* callback );
		void deleteqCloudSubKey(const QString& conversationId);
		void checkqCloudMainKey(const QString& pwd, Biz::UnitCallback<QString>* callback);

		void deleteqCloudMainKey(Biz::UnitCallback<bool>* callback);
		void doupdateqCloudSubKey(const QString&conversation, const QString& desc, const QString&content, Biz::UnitCallback<bool>* callback );
		void deleteqCloudSubAllKey(Biz::UnitCallback<bool>* callback);

		void isChatPwdBox(Biz::UnitCallback<bool>* callback);

	protected:
		void getqCloudMainInfofromServer(int type);
		void getqcloudSubInfofromServer(int type);
	private:
		QString mSelfMainKey; //这是自己心里的密码，有一个有效性的。
signals:
		void sgSelfConversationKey(const QString& key);
	public slots:
		void onLoginStatusChange(LoginStatus oldstatus,LoginStatus newstatus);
	};
}


#endif // QCLOUDMANAGER_H
