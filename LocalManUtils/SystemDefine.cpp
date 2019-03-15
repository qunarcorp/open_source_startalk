#include "SystemDefine.h"
#include "UtilHelper.h"
#include <QNetworkInterface>

#define DEV     0
#define BETA    0
#define ONLINE  1


namespace Util{
    /*
     *	true 生产环境
     *  false  beta环境
     */
#if _DEBUG
    const bool ENV_OPTION = true;
#else
    const bool ENV_OPTION = true;
	const bool checkOneProgress = true;
#endif

#ifdef QCHAT
    const int nPlatformType     = PlatfromCode::PLATFROM_QCHAT;    
#else
    const int nPlatformType     = PlatfromCode::PLATFROM_QTALK;
#endif
    

    const QString COMPANY_NAME = "Qunar";
	const QString ORGANIZATION_NAME = "QunarDujia";
#ifndef QCHAT
	const QString APPLICATION_NAME = "QunarIM";
    const QString APPLICATION_VERSION = "0.1.0.112";
    const int GLOBAL_INTERNAL_VERSION = 10121112;
 
#else
	const QString APPLICATION_NAME = "QunarChatIM";

	const QString APPLICATION_VERSION = "0.0.3.94";

	const int GLOBAL_INTERNAL_VERSION = 10121394;

#endif // !QCHAT
    const QString NEWS_DIALOG_ID = "news_dialog";

	//系统消息和公告消息
	const QString SYSTEMNEWS_DIALOG_ID = "rbt-system";
	const QString NOTICENEWS_DIALOG_ID = "rbt-notice";
	const QString QIANGDAN_DIALOG_ID = "rbt-qiangdan";
	const QString TIP_TIP_ID = "tip_tip";

	//订阅号的Id
	const QString SUBSCRIPTIONNUM_ID = "subscription-num";
	const QString FRIENDS_DIALOG_ID = "friends-fs";

	const QString LeftUnCheckedClr = "#ff0000";
	const QString LeftCheckedClr = "#a1a1a1";
	const QString RightUnCheckedClr ="#000088";
	const QString RightCheckedClr = "#76EE00";

	

	//代收
	const QString COLLECTION_DIALOG_ID="collection_rbt";
	const QString strPYGzh="GONGZHONGHAO";
	const QString strPYTitleFriends = "HAOYOUXINXI";
	const QString strGzh = QStringLiteral("公众号");
	const QString strTitleFriends = QStringLiteral("好友信息");
	const QString strTS = "#";
	const int maxImageWidth = 325;
	const int maxImageHeigh = 200;

	const QString StarPersonId      = "XINGBIAOLIANXIREN";
	const QString StarPersonName    = QStringLiteral("星标联系人");

	const QString GroupsId      = "QUNZHU";
	const QString GroupsName    = QStringLiteral("群组列表");

	const QString OrganizationId    = "ZUZHIJIEGOU";
	const QString OrganizationName  = QStringLiteral("组织架构");

	const QString FriendsId     = "HAOYOULIEBIAO";
	const QString FriendsName   = QStringLiteral("好友列表");

	const QString BlackFriendsId    = "HEIMINGDAN";
	const QString BlackFriendsName  = QStringLiteral("黑名单");

    const QString WorkPlaceId   = "WorkPlaceId";  
    const QString WorkPlaceName = QStringLiteral("工作区");

	const QString BackWardId = "BACKWARD";
	const QString UserNoticeMsg = "UserNoticeMsg";
	const QString GroupNoticeMsg = "GroupNoticeMsg";
	const qint32 XPSYSTEMVERSION =  0x0030; //xp的版本号

	const int GETHISTORYCOUNTLIMITED = 20;
	const QString SELFSETEMPTY = "SELFSETEMPTY"; //商家手动设置的空

	const int SizeOfGifImage = 1024 * 1024 * 1;

	const QString PassWordBoxId = "PassWordId";
	const QString PassWordBoxName = QStringLiteral("密码箱");

	const QString NoteInforId = "NoteInforId";
	const QString NoteInforName = QStringLiteral("笔记");

	const QString GHOST_KEY_HIDE_FUNCTION = "whosyourdaddy";

    QString getDeviceID()
    {
        static QString macAddress;

        if(!macAddress.isEmpty())
            return macAddress;
        
        auto list = QNetworkInterface::allInterfaces();
        foreach(auto itor, list){
            macAddress = itor.hardwareAddress();
            break;
        }

        if(!macAddress.isEmpty()){
            return macAddress;
        }

        //补充逻辑，读下文件，如果没有则生成一个
        QString file = UtilHelper::GuidPath();
        QFile f(file);
        if(!f.open(QIODevice::ReadWrite)){
            auto guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
            macAddress = guid;
            return macAddress;
        }

        macAddress = QString::fromUtf8(f.readAll());
        if(macAddress.isEmpty()){
            auto guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
            macAddress = guid;
            f.write(macAddress.toUtf8());
        }

        f.close();
        return macAddress;
    }

}

