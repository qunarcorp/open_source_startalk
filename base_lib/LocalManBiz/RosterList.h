#ifndef ROSTERLIST_H
#define ROSTERLIST_H

#include "CoreObject.h"

namespace Biz
{
    class RosterGroup;
    class RosterNode : public QObject{
        Q_OBJECT
    public:
        RosterNode(RosterGroup* parent);
		RosterNode(const RosterNode&rn);
		RosterNode();
        ~RosterNode(){};
    public:
        bool matchKey(const QString& key, bool accurate = false);
        void parseNode(const QVariant& var);
		void parseChatNode(const QVariant& var);
    public:
        QString userId;
        QString displayName;
        QString namePinyin;
		QString strUin;

		//相关缩写
		QString Rtxidpy;
		QString Rtxidsx;
		QString Rtxidhzpy;
		QString Rtxidhzsx;
        int status;

        RosterGroup* group;
    };
    class RosterGroup : public QObject
    {
        Q_OBJECT
    public:
        RosterGroup(RosterGroup* parent);
        ~RosterGroup();
        RosterGroup* addGroup();
        RosterNode* addNode();
        void findNode(const QString& key, QList<RosterNode*>& result,bool accurate);
        void findNode(const QString& key, QStringList& result);
        RosterGroup* findGroup(const QString& key);
		RosterGroup* findGroupByIdAndKey(const QString&Key );
        void parseGroup(const QVariant& var);
		void parseChatGroup(const QVariantMap& var);
        QString getShortName();
        QString getFullName();
        void setName(const QString& n);
        QList<RosterNode*>& getRosterList() { return rosterNodeList;};
        QList<RosterNode*> getRosterListWithChildren();
        QList<RosterGroup*>& getGroupList() { return rosterGroupList;};
		void findMemberInfor(const QString& key, QStringList& result);
		QString findChatGroupRootName();
		
    public:
        static QString DEFAULT_NAME;
    public:
        QList<RosterNode*> rosterNodeList;
        QList<RosterGroup*> rosterGroupList;
	
        RosterGroup* group;
        QString name;
		QList<QString> m_username;
		QList<QString> m_Displayname;
		int id;
    };

    class ImSession : public QObject
    {
       
        Q_OBJECT
    public:
        enum SessionSaveType
        {
            SESSION_RECENT = 0x1,
            SESSION_CHATING = 0x2,
            SESSION_LOCAL = 0x4
        };

    public:
        ImSession();
        ~ImSession();
        ImSession(const Biz::ImSession &);
        const Biz::ImSession& operator= (const Biz::ImSession &);
		bool operator==(const Biz::ImSession&);

    public:
        QString xmppid;
		QString realJid;
        QString lastMessageId;
        quint64 lastupdateTime;
        int chatType;
        int unreadCount; 
        int configration;
    };
	
	class ImSelfPerson
	{
    public:
        enum UserSaveType
        {
            UserSaveType_Local = 1,
            UserSaveType_Remote = 2
        };
	public:
		ImSelfPerson()
		{
			//strUin = "";
			strUserId = "";
			strRealName="";
			nMaxtalkcount = 0;
			strWebName = "";
			strDepartment = "";
			sex = 0;
			strimageUrl = "";
			strmobile="";
			strNickName="";
			strEmail = "";
			channelid = "";
			version = 0;
			role = "";
			strmd5 = "";
			strsuppliername = "";
			strDisplayName = "";

            strMarkName = "";
            nUserType   = UserSaveType_Remote;
			//qchat下店铺id
			strShopId="";
			strdomain="";
		};
		~ImSelfPerson(){};
		QString displayName();
	public:
		//QString strUin;
		QString strUserId;
		QString strRealName;
		int nMaxtalkcount;
		QString strWebName;
		QString strDepartment;
		QString strimageUrl;
		QString strmobile;
		QString strNickName;
		QString strEmail;
		int sex;
		QString channelid;
		int version;
		QString role;
		QString strmd5;
		QString strsuppliername;
		QString strDisplayName; // 中间量，仅内存态，{webname|nickname|jid}[(suppliername)]

        QString strMarkName;
        int     nUserType;
		QString strShopId;
		QString strdomain;
	};

}

#endif // ROSTERLIST_H
