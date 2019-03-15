#ifndef FRIENDSMANAGER_H
#define FRIENDSMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "qxmppfriendsmanager.h"
#include "MessageListData.h"

class QFriendVerifyModeIq;
class QFriendsListIq;
class QFriendVerifyResultPresence;

class QXmppFriendsManager;

namespace Biz
{
	enum AddStatus
	{
		WAITSTATUS,
		REFUSESTATUS,
		AGREESTATUS,
		DeleteStatus
	};
	enum AddDirection
	{
		ADDDIRECTION,
		BYADDDIRECTION
	};
	struct FriendsInfor
	{
		QString userid;
		QString Friend;
		QString userName;
        QString userDescription;
		int relationship;
		int ver;
		FriendsInfor()
		{
			userid = "";
			Friend = "";
			relationship = 0;
			ver = 0;
		}
	};

    enum VeryFriendMode
    {
        FriendRefuse,
        FriendInformation,
        FriendQuestAndAnswer,
        FriendDirectAdd
    };

	class ImSelfPerson;
    class DomainList;
    class WechatUserListParam;

	class FriendsManager : public ManagerBase
	{
	    Q_OBJECT
	
	public:
	    FriendsManager();
	    ~FriendsManager();
		enum RESULT
		{
			RESULTSUCCESS, RESULTFAIL
		};
    public:
        virtual void initManager();
        virtual void unInitManager();
    public:
		void setAgreeAddFriendToDB(const QString& userid);
		void setRefuseAddFriendToDB(const QString& userid);
		void getDeleteFriend(const QString& userid, E_DELETE_FRIEND_MODE moden);
        void getUserVerifyMode(const QString& userid);
        void getSelfVerifyMode();
        void verify(const QString& userid);
        void verify(const QString& userid,const QString& answer);
        void verifyInfoMode(const QString& userid,const QString& reason);
        void allowVerify(const QString& userid);
        void deniedVerify(const QString& userid);
        void getFriendsList(int version);
		//设置配置项
		void setSelfFriendVerify(int mode, const QString& strquestion, const QString& stranswer);
		//得到相应的历史消息信息
		void getAddFriendsInfoList(const QString& userId, int count, quint64 lasttime, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);

		// 搜索好友
		void searchFriendInfo(const QString& key,const QString& domainid,int page, Biz::UnitCallback<QList<QSharedPointer<Biz::ImSelfPerson>>>* callback);

		bool isAlreadyFriend(const QString& userjid);
		inline QList <FriendsInfor>  getFriendsInfo(){return friendInfoList.values();};
		//获取黑名单
		QStringList getBlackNameInfoList();
		void setBlackName(const QString&Jid);
		void cancelBlackName(const QString&Jid);

		// 设置星标联系人状态 type 设置的是发送json协议中的 value 0代表取消 1 代表设置
		void setStarPerson(const QString& jid, int type);

         void getDomainList(UnitCallback<QSharedPointer<Biz::DomainList>>* uicallback);

         void getWechatUserList(UnitCallback<QSharedPointer<Biz::WechatUserListParam>>* callback);

		 QStringList getStarPersonInfoList();

	private:
		void getAddFriendsInfo(const QString& userId, int count, quint64 lasttime, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);
		//存放自己的模式及相关
		void SaveSelfMode(const QString& md, const QString& qu, const QString&as);
		void getBlackNameList();

        void _updateBlackNameList(const QStringList& add,const QStringList& remove);

		void getStarPersonList();
       
	private:
        QXmppFriendsManager* friendExterd;
		QMap<QString,FriendsInfor> friendInfoList;
		
		//存放黑名单的地方
		QStringList mAllBlackNamelist;
		
		//存放星标联系人的地方
		QStringList mAllStarPersonlist;

		CallbackReceiver* mReceiver;
signals:
		void sgAddhtmlInfor();
		void sgDelFriendRecieve(const QString&reson , const QString& jid, int ntype=1);
		void sgFriendsList(const QStringList& friendslist);
		void sgVerifyFriendModeReceive(const QString& model, const QString& question, const QString& jid);
		void sgFriendVerifyResultReceive(const QString& result, const QString& reason, const QString& jid);
		void sgFriendVerifyResultByReceive(const QString& reason, const QString& jid); 
        void sgFriendVerifyInfoReceive(const QString& id,const QString& body);
		void sgAllowVerifyFriendReceive(const QString& id, const QString& result);
		void sgBlackNameListUpdate(const QStringList& userid);
		void sgManagerBlackNameListUpdate();
		void sgAddBlackName(const QString& id, int result);
		void sgCancelBlackName(const QString& id, int result);
		void sgManagerStarPersonListUpdate();
public slots:
		void onDeleteFriendReceive(const QXmppDeleteFriendIq& delfriendiq);
        void onVerifyModeReceive(const QFriendVerifyModeIq& verifyiq);
        void onFriendsListReceive(const QFriendsListIq& friendListIq);
        void onFriendsVerifyReslutReceive(const QFriendVerifyResultPresence& reulstPresence);
        void onFriendsVerifyInfoReceive(const QXmppVerifyInfoPresence& infoPresecne);
		void onConnected();
		void onAllowVerifyFriendReceive(const QXmppAllowVerifyPresence& allowPresecne);
		void onDeleteFriendPresenceReceive(const QXmppDeleteFriendPresence& deletepresence);
		// http 同步数据后处理槽函数
		void onPersonCfg();	
	};
}

#endif // FRIENDSMANAGER_H
