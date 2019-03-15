#ifndef ACCOUNTDATA_H
#define ACCOUNTDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    enum EUserType
    {
        EUserTypeNone           = 0,
        EUserTypeEmployee       = 1,
        EUserTypeMerchant       = 2
    };
    class Roster;
    class GroupListData;
    class AccountData : public IXmlSerializeable
    {
        Q_OBJECT;
        //登录界面用
        PROPERTY(QString,   LoginAccount);//xxx@yyy.com
        PROPERTY(QString,   LoginPassword);   // 这个密码原则上只在内存中使用，不用做落地的密码，新增个字段保存落地的字段
        PROPERTY(QString,   savedPassword);   // 这个字段保存需要落地的密码，只在登录的时候将密码带到界面上去，不参与登录动作

        PROPERTY(QString,   UserID);//xxx
        PROPERTY(bool,      IsSaveAccount);
        PROPERTY(bool,      IsAutoLogin);
        PROPERTY(int,       Presence);
        PROPERTY(bool,      firstRun);
        PROPERTY(QString,   FullName);
		/*PROPERTY(QString,   QUserName);userid */
		PROPERTY(int,       EUserType);
        PROPERTY(QList<IXmlSerializeable*>, Rosters);
		PROPERTY(int,       SaveVersion);
        PROPERTY(int,       LastestVersion);
		PROPERTY(quint64,       MainChatVersion);

        PROPERTY(int,       Version);
		//自己是值班账号，对应的值班账号id
		PROPERTY(bool, IsOnduty);
		PROPERTY(QString, OndutyId);
		PROPERTY(QString, NavAddr);
    public:
        AccountData();
        ~AccountData();
         bool updateConfig();
        void addRoster(Roster* roster);
        void removeRoster(Roster* roster);

        void unserializeItem(const QString&, QDomElement&);

		QString userJid();
    private:
        const static int    sAccountDataVersion;
    };

    class LoginNavConfigInfo : public IXmlSerializeable
    {
        Q_OBJECT
    private:
        PROPERTY(int,Version);
        PROPERTY(quint64,LastUpdataTime);
        PROPERTY(QString,NavData);
		PROPERTY(QString, SecondNavData);
    public:
        LoginNavConfigInfo()
        {
            Version(0);
            LastUpdataTime(0);
        }
        ~LoginNavConfigInfo(){};
    };

	class LoginAccountConfigInfo:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(int,ID);
		PROPERTY(QString,LoginAccount);
		PROPERTY(QString,savedPassword);
		PROPERTY(QString,UserID);
		PROPERTY(bool,IsSaveAccount);
		PROPERTY(bool,IsAutoLogin);
		PROPERTY(QString,Domain);
		PROPERTY(QString,NAVAddr);
		PROPERTY(quint64,LastLoginTime);
	public:
		LoginAccountConfigInfo()
		{
			ID(0);
			LastLoginTime(0);
		}
		~LoginAccountConfigInfo(){};
	};

	class NavConfigInfo:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(int,ID);
		PROPERTY(QString,title);
		PROPERTY(QString,nav);
		PROPERTY(QString, yu);
	public:
		NavConfigInfo()
		{
			ID(1);
			title(QStringLiteral("qtalk域"));
			title(QStringLiteral("https://qt.qunar.com/package/static/qtalk/nav"));
		}
		~NavConfigInfo(){};
	};

}
#endif // ACCOUNTDATA_H
