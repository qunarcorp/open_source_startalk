#pragma once

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    class EditableSettings : public IXmlSerializeable
    {
		Q_OBJECT;
    public:
        enum INNERLOGOPTION{
            ILO_LOGNONE     = 0,
            ILO_HTTPLOG     = 1,
            ILO_HTMLLOG     = 2,
            ILO_DAOLOG      = 4
        };
        PROPERTY(int,       GroupMailLimited);
		PROPERTY(QString,   DefaultSaveAsPath);
		PROPERTY(int,       DefaultOfflieMessageTimeLimit);
		PROPERTY(bool,      ShowSenderId);
		PROPERTY(bool,      ShowAddUsersToGroup);
        PROPERTY(bool,      BetaEnvEnable);
        PROPERTY(bool,      PbEnable);
        PROPERTY(bool,      LimitMaxBasechatDialogCount);
        PROPERTY(int,       LimitMaxBasechatDialogCountN);
        PROPERTY(int,       Version);
        PROPERTY(int,       ShowInnerLog);
        PROPERTY(QString,   SupportWeb);
        PROPERTY(QString,   ESUrl);
        PROPERTY(QString,   ProductDetail);
        PROPERTY(QString,   WebLoginUrl);
        PROPERTY(QString,   IpToCity);
		PROPERTY(QString,	SessionHistory);
        PROPERTY(QString,   WorkStatusUrl);
        PROPERTY(QString,   MsgShareUrl);
        PROPERTY(bool,      CancelVersionUpdate);
		PROPERTY(bool,      ChatHistoryMsgable);
		PROPERTY(int,      ChatHistoryMsgCount);
		PROPERTY(int,      CurrentVersion);
		PROPERTY(QString,  TTSUrl);
		PROPERTY(QString,  WebChatUrl); //微信中的url地址
		PROPERTY(QString,  DefaultLogRecived);
		PROPERTY(QString,  LastDomain);
		PROPERTY(QString, SaveCloudMain);
		PROPERTY(QString, getCloudMain);
		PROPERTY(QString, SaveCloudSub);
		PROPERTY(QString, getCloudSub);
		PROPERTY(QString, getdeleteCloudSub);
		PROPERTY(QString, getdeleteCloudMain);
		PROPERTY(QString, getupdateCloudSub);
		//扫码登录中需要用的三个接口
		PROPERTY(QString, getstartqrcode);
		PROPERTY(QString, getcancelqrcode);
		PROPERTY(QString, getcheckReadyqrcode);

		PROPERTY(QString, getCollectUserVcard);
		PROPERTY(QString, getCollectRoomVcard);
		PROPERTY(QString, getCollectBindUserList);

		//获取表情图片列表的
		PROPERTY(QString, getEmotionUrl);
		PROPERTY(int, DefaultDeleteCatch);

		//qchat店铺
		PROPERTY(QString, getSeatStatus);
		PROPERTY(QString, setSeatStatus);
		PROPERTY(QString, question);

		PROPERTY(QString, gethelp);
		PROPERTY(QString, getchangelog);

		PROPERTY(QString, getworkplace);
		//这是给测试的音视频的地址
		PROPERTY(bool , IsTestVedio);
		PROPERTY(bool, IsFirstCleanMsgDB);
		PROPERTY(bool, IsDeleteAccount);

		//搜素的地址
		PROPERTY(QString, getMsgNotice);
		PROPERTY(QString, setGroupPushState);

		//收集日志发邮件
		PROPERTY(QString, getLogsSendEmail);
		//下载公钥的地址
		PROPERTY(QString, getRsaKey);//"qtapi/nck/rsa/get_public_key.do"

		//ops 中获取人员信息的接口
		PROPERTY(QString, getOpsUserDetail);

		//ops 中获取人员的电话号码
		PROPERTY(QString, getOpsUserMobile);


	public:
        bool updateConfig();
        EditableSettings();
        ~EditableSettings();
    private:
        const static int    sEditableSettingVersion;
    };
}
