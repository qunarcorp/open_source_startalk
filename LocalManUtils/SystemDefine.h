#pragma once
#include "CoreObject.h"

namespace Util{

    // 程序的运行环境
    extern const bool ENV_OPTION;
	extern const bool checkOneProgress;

	//应用程序设置
    extern const QString COMPANY_NAME;
	extern const QString ORGANIZATION_NAME;
	extern const QString APPLICATION_NAME;
	extern const QString APPLICATION_VERSION;
    extern const QString APPLICATION_BUILD_VERSION;
    extern const int GLOBAL_INTERNAL_VERSION;
    //旅图服务Protocol
    extern const QString PB_HOST;
    QString getDeviceID();

    // 常量
    extern const QString NEWS_DIALOG_ID;
	extern const QString SYSTEMNEWS_DIALOG_ID;
	extern const QString NOTICENEWS_DIALOG_ID;
	extern const QString SUBSCRIPTIONNUM_ID;
	extern const QString FRIENDS_DIALOG_ID;
	extern const QString QIANGDAN_DIALOG_ID;
	extern const QString COLLECTION_DIALOG_ID;
	extern const QString TIP_TIP_ID ;

	//颜色值
	extern const QString LeftUnCheckedClr;
	extern const QString LeftCheckedClr ;
	extern const QString RightUnCheckedClr ;
	extern const QString RightCheckedClr ;

	//好友和公众号
	extern const QString strPYGzh;
	extern const QString strPYTitleFriends;

	extern const QString strGzh;
	extern const QString strTitleFriends;
	extern const QString strTS;

	extern const int maxImageWidth;
	extern const int maxImageHeigh;

    // 平台类型
    extern const int nPlatformType;

	//组合信息内容
	extern const QString StarPersonId;
	extern const QString StarPersonName;

	extern const QString GroupsId;
	extern const QString GroupsName;

	extern const QString OrganizationId;
	extern const QString OrganizationName;

	extern const QString FriendsId;
	extern const QString FriendsName;

	extern const QString BlackFriendsId;
	extern const QString BlackFriendsName;

	extern const QString BackWardId;

	extern const QString UserNoticeMsg ;
	extern const QString GroupNoticeMsg ;

    extern const QString WorkPlaceId;
    extern const QString WorkPlaceName;

	extern const qint32 XPSYSTEMVERSION;

	extern const int GETHISTORYCOUNTLIMITED;
	extern const QString SELFSETEMPTY;

	extern const int SizeOfGifImage;

	extern const QString PassWordBoxId;
	extern const QString PassWordBoxName;

	extern const QString NoteInforId;
	extern const QString NoteInforName;

	extern const QString GHOST_KEY_HIDE_FUNCTION;
	

	enum PlatfromCode
	{
		PLATFROM_QTALK       = 0x1,
		PLATFROM_QCHAT       = 0x2
	};

}
