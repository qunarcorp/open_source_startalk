#pragma once

#include "CoreObject.h"
#include <QSharedPointer>
#include <QMap>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include "BizCallback.h"
#include "define.h"
#include "ParamObjects.h"
#include "Player.h"
#include "xmpp/JID.h"

using namespace qtalk;
namespace Biz {
    class MessageListData;

    class Player;

    class RoomVcard;

    class RobotVcard;

    class ImSelfPerson;

    class CheckConfigInfo;

    class UserVcard;

    class DomainUserStatus;

    class PersonConfInfo;

    class UserMoodInfo;

    class EmoticonPackageInfo;

    class XmppMessage;

    class HTTPResponce;

    class ChatHistoryByPageRequestParam;

    class ChatHistoryByBatchRequestParam;

    class GroupChatHistoryByPageRequestParam;

    class GroupChatHistoryByBatchRequestParam;

    class GroupReadPointRequestParam;

    class SystemNotifyHistoryByPageRequestParam;

    class SystemNotifyHistoryByBatchRequestParam;

    class ConsultHistoryByPageRequestParam;

    class ConsultHistoryByBatchRequestParam;

    class MucReadmarkRequestParam;

}
class WebService {
public:
    static QString sSecurityKey;
    static QString sU;
    static JID *Jid;
    static quint64 sUin;
	static int configVersion;
public:
    static QString getCKey();

    static QString getOldCKey();

    static void setUserJid(QString jid);

public:
    static void getPushStatus(const QString &userid, Biz::UnitCallback<QString> *callback);

    static void setPushStatus(const QString &userid, int status, Biz::UnitCallback<QString> *callback);

    static void getEmotionsList(Biz::UnitCallback<QList<QSharedPointer<Biz::EmoticonPackageInfo>>> *callback);

    static void getWorkStatus(const QString &userid, Biz::UnitCallback<QString> *callback);

    static void SetWorkStatus(const QString &userid, int status, int shopid, Biz::UnitCallback<QString> *callback);

    static void getsuggestinfo(const QString &userid, const QString &searchkey, Biz::UnitCallback<QString> *callback);

    static void getOrganizationbyshopid(const QString &userid, quint32 shopid, Biz::UnitCallback<QString> *callback);

    static quint64 getServerTime();

    static QSharedPointer<Biz::CheckConfigInfo> getCheckConfigInfo(quint64 cv);

    static void getDownloadFile(const QString &userid, const QString &urlimage, const QString &filename);

    static QSharedPointer<Biz::ImSelfPerson> getSelfUserInfoList(const QString &uis);

    static void getAddFriendInfo(const QString &selfid, quint64 timeStamp, quint64 limits,
                                 Biz::UnitCallback<QSharedPointer<Biz::MessageListData>> *callback);

    static QList<QSharedPointer<Biz::Player>> getUsers();

    static void getDepsInfos(const QString &userid, Biz::UnitCallback<QVariantList> *callback);

    // 服务器返回未读的消息，与本地未读的消息数算差量，为已读的，返回已读的消息idas
    static QList<QSharedPointer<Biz::Player>> getIncrementUsers(int maxverion);

    static void getMucVcard(const QMap<QString, int> &versions,
                            Biz::UnitCallback<QList<QSharedPointer<Biz::RoomVcard>>> *callback);

    static void getRobotList(const QString &userid, Biz::UnitCallback<QStringList> *callback);

    static void subscriptRobot(const QString &userid, const QString &rbtid, Biz::UnitCallback<QString> *callback);

    static void unSubscriptRobot(const QString &userid, const QString &rbtid, Biz::UnitCallback<QString> *callback);

    static QList<QSharedPointer<Biz::RobotVcard>> getRobotInfo(const QMap<QString, QString> &robotPairs);

    static void getRobotInfo(const QMap<QString, QString> &robotPairs,
                             Biz::UnitCallback<QList<QSharedPointer<Biz::RobotVcard>>> *callback);

    static void
    getRobotHeaders(const QMap<QString, QSharedPointer<Biz::RobotVcard>> &robots, Biz::GeneralCallback *callback);

    static bool getVersionUpdate(const long currentVersion, bool bTestFlight,
                                 const QSharedPointer<Biz::CheckVersionUpdate> &checkVersionUpdate);

    static void
    searchRobot(const QString &keyword, Biz::UnitCallback<QList<QSharedPointer<Biz::RobotVcard>>> *robotCallback);

    // 检查文件是否存在于服务器
    static bool
    checkFileExist(const QString &type, const QString &filePath, const QString &key, int size, QString &result);

    // guhua url
    static bool stpUrl(const QString &url, Biz::UnitCallback<QString> *callback);

    static void searchFirendsInfo(const QString &key, const QString &domainid, int limit, int page,
                                  Biz::UnitCallback<QList<QSharedPointer<Biz::ImSelfPerson>>> *resultJson);

    //获取最近连系人接口
    static void
    getRecentUserListInfo(const QString &userid, const QString &demain, Biz::UnitCallback<QVariant> *callback);

    //
    static void gethttpurlapi(const QString &url);

    //转移 发送的欢迎语
    static void
    sendwelcome(const QString &seatQId, const QString &userQId, const QString &shopid, const QString &businessline,
                Biz::UnitCallback<QString> *callback);

    //转移发送note消息
    static void
    sendnote(const QString &seatQid, const QString &userQId, const QString &shopid, const QString &productId,
             Biz::UnitCallback<QString> *callback);

    //日志的收集和发送
    static void collectLogs(Biz::UnitCallback<QString> *callback);

    //增量群列表的获取
    static void getIncrementJoinedRoom(quint64 lastime,
                                       Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::IncreaRoomInfo>>> *callback);

    //群列表中进行数据的merge
    static void groupRelationmerge(const QStringList &groupids);

    //二维码扫描给服务器串的参数
    static void doErCodeInforToServer(const QString &qercodeKey, Biz::UnitCallback<QString> *callback);

    static void doErCodeInforCancel(const QString &qercodeKey, Biz::UnitCallback<QString> *callback);

    static void doErCodeAuthInfor(const QString &qercodekey, int phare, Biz::UnitCallback<QString> *callback);

    //获取接受不提醒的信息
    static void getMsgNoticeList(Biz::UnitCallback<QMap<QString, int>> *callback);

    static void setGroupPushState(const QString &groupId, bool state, Biz::UnitCallback<QMap<QString, int>> *callback);

    //发送邮件
    static void collectLogsToEmail(const QString &content, Biz::UnitCallback<QString> *callback);

public:
    // java版本的
    static void getChatHistoryByPage(QSharedPointer<Biz::ChatHistoryByPageRequestParam> param,
                                     Biz::UnitCallback<QSharedPointer<Biz::HTTPResponce>> *callback);

    static QList<QSharedPointer<Biz::HTTPResponce>>
    getChatHistoryByBatch(const QSharedPointer<Biz::ChatHistoryByBatchRequestParam> &param);

    static void getGroupChatHistoryByPage(const QSharedPointer<Biz::GroupChatHistoryByPageRequestParam> &param,
                                          Biz::UnitCallback<QSharedPointer<Biz::HTTPResponce>> *callback);

    static QList<QSharedPointer<Biz::HTTPResponce>>
    getGroupChatHistoryByBatch(const QSharedPointer<Biz::GroupChatHistoryByBatchRequestParam> &param);

    static QSharedPointer<Biz::HTTPResponce>
    getGroupReadPoint(const QSharedPointer<Biz::GroupReadPointRequestParam> &param);

    static void getSystemNotifyHistoryByPage(const QSharedPointer<Biz::SystemNotifyHistoryByPageRequestParam> &param,
                                             Biz::UnitCallback<QSharedPointer<Biz::HTTPResponce>> *callback);

    static QList<QSharedPointer<Biz::HTTPResponce>>
    getSystemNotifyHistoryByBatch(const QSharedPointer<Biz::SystemNotifyHistoryByBatchRequestParam> &param);

    static void getConsultHistoryByPage(const QSharedPointer<Biz::ConsultHistoryByPageRequestParam> &param,
                                        Biz::UnitCallback<QSharedPointer<Biz::HTTPResponce>> *callback);

    static QList<QSharedPointer<Biz::HTTPResponce>>
    getConsultHistoryByBatch(const QSharedPointer<Biz::ConsultHistoryByBatchRequestParam> &param);

    static QMap<QString, quint64> getMucReadmark(const QSharedPointer<Biz::MucReadmarkRequestParam> &param);

	// 获取热线账号列表
	static void getVirtualAccountList(Biz::UnitCallback<QMap<QString,QVariant>> *callback);

public:


// 	//对于值班账号，获取某个时间点到当前的所有消息
    static QSharedPointer<Biz::MessageListData>
    getvertualondutyDomainHistory(const QString &id, const QString &ondutyid, const QString &domain, quint64 lastTime);

    // 获取群组的名片
    static void getDomainRoomVcard(const QList<QSharedPointer<Biz::RoomVcardRequestParam>> &params,
                                   Biz::UnitCallback<QList<QSharedPointer<Biz::RoomVcard>>> *callback);

    // 获取个人名片
    static void getDomainUserVcard(const QList<Biz::UserVcardRequestParam> &params,
                                   Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::ImSelfPerson>>> *callback);

    // 获取个人的在线状态
    static void
    getDomainUserStatus(const QList<Biz::UserStatusRequestParam> &params, Biz::UnitCallback<QStringList> *callback);

    // 获取个人配置项
    static void getPersonCfg(
            const QMap<QString, int> &keyMaps,
            Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::PersonConfInfo>>> *callback);

    static void getPersonCfgEx(
            const int oldVersion,
            Biz::UnitCallback<QMap<QString, QVariant>> *callback);

    static void
    savePersonCfg(QList<QSharedPointer<Biz::PersonConfInfo>> personCfgList, Biz::UnitCallback<bool> *callback);

    static void savePersonCfgEx(QMap<QString, QVariant> input, Biz::UnitCallback<QMap<QString, QVariant>> *callback);

    /*!
    * 功能 : 获取登陆导航
    */
    static void getLoginNav(const QString &NavAddr, Biz::UnitCallback<QString> *callback);

    /*!
    * 功能 : 获取 qchat 用户的qvt
    */
    static void getQVT(const QString &strData, Biz::UnitCallback<QString> *callback);

    static void getToken(Biz::UnitCallback<QString> *callback);


    static void excuteCommentRequest(const QString &url, Biz::UnitCallback<QString> *callback);

    //请求广告信息
    static void getAdverInfor(int nversion, Biz::UnitCallback<QString> *callback);

    //心情短语的获取和设置
    static void getUserMoodInfo(const QList<QSharedPointer<Biz::UserMoodInfo>> &usermoodlist,
                                Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::UserMoodInfo>>> *callback);

    static void setUserMoodInfo(const QString &userid, const QString &moodinfo,
                                Biz::UnitCallback<QSharedPointer<Biz::UserMoodInfo>> *callback);

    // 请求个人的领导名
    static void getUserDetail(const QString &userjid, Biz::UnitCallback<QString> *callback);

    // 请求个人的手机号，一天十次
    static void getUserMobile(const QString &userjid, Biz::UnitCallback<QString> *callback);

    //请求未审批的任务数
    static void getUserWorkspaceWaitCount(Biz::UnitCallback<QString> *callback);

    static void getDomainList(int nversion, Biz::UnitCallback<QString> *callback);


    static void getWechatUserLists(Biz::UnitCallback<QString> *callback);

    static void getGroupsLastMessage(Biz::UnitCallback<QString> *callback);

    //音视频的信息
    static void getAudioInforByckey(Biz::UnitCallback<QString> *callback);

    //获取群视频会议室的地址
    static void getGroupVideoRoomAddr(Biz::UnitCallback<QString> *callback);

    //获取在线状态
    static void getOnlineUsers(Biz::UnitCallback<QStringList> *callback);

    //保存主密码
    static void saveqcloudMain(const QString &param, Biz::UnitCallback<QString> *callback);

    //获取主密码
    static void getqcloudMain(const QString &param, Biz::UnitCallback<QString> *callback);

    //保存会话密码
    static void saveqcloudSub(const QString &param, Biz::UnitCallback<QString> *callback);

    //获取会话密码
    static void getqcloudSub(const QString &param, Biz::UnitCallback<QString> *callback);

    //删除子密码表中记录
    static void deleteqCloudSub(const QString &param, Biz::UnitCallback<QString> *callback);

    //更新子密码
    static void updateqCloudSub(const QString &param, Biz::UnitCallback<QString> *callback);

    //删除会话密码
    static void deleteqCloudMain(const QString &param, Biz::UnitCallback<QString> *callback);

    static quint64 getMessageLasttime(const QSharedPointer<Biz::MessageListData> &msglist);

    //获取代收绑定账号信息列表
    static void getCollectionBindUserInfor(Biz::UnitCallback<QString> *callback);

    //获取个人名片信息
    static void getDomainCollectionUserVcard(const QList<Biz::UserVcardRequestParam> &params,
                                             Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::ImSelfPerson>>> *callback);

    //获取个人名片信息
    static void getCollectionRoomVcard(const QList<QSharedPointer<Biz::RoomVcardRequestParam>> &params,
                                       Biz::UnitCallback<QList<QSharedPointer<Biz::RoomVcard>>> *callback);

    //搜索接口
    static void getSearchInfor(const QString &searchkey, int nStart, int nlenght, const QString &nGroupId,
                               Biz::UnitCallback<QString> *callback);

    //下载公钥
    static void getRsaPubKey(Biz::UnitCallback<QString> *callback);

    //获取连接中的信息
    static void getNoticeTipLinkInfo(const QString &link, Biz::UnitCallback<QString> *callback);

    // 主动关闭会话
    static void closeSession(const QString &userid, const QString &shopName);


    // 客服上线后调用分配客服接口
    static void sendMerchantOnline();


	// 快捷回复 相关接口
	static void syncQuickReplyList(long groupVersion, long contentVersion, Biz::UnitCallback<QMap<QString,QVariant>> *callback);
	static void setQuickReplyList(long groupVersion, long contentVersion, const QList<QSharedPointer<Biz::QuickReplyGroup>> &groupList, const QList<QSharedPointer<Biz::QuickReplyContent>> &contentList, Biz::UnitCallback<QMap<QString,QVariant>> *callback);
	static void __saveQuickReplyFromService(QVariantMap infoMap, QMap<QString, QVariant> &rMap);

	// 会话转移 相关接口
	static void getSeatList(const QString &shopId, Biz::UnitCallback<QMap<QString,QVariant>> *callback); 
	static void transformCsr(const QString &shopId, const QString &newCsrName, const QString &customerName, const QString &reason, Biz::UnitCallback<QMap<QString,QVariant>> *callback);

	// 发送功能按钮的Http请求
	static void sendTPRequest(const QString &url, const QString &chatId, const QString &realJid, int chatType);

protected:
    static QVariant parseHttpResult(const QString &rawResult);

    static int
    parseClientConfigResult(const QString &rawResult, QList<QPair<QPair<QString, QString>, QString>> *addlist,
                            QList<QPair<QPair<QString, QString>, QString>> *dellist, QList<QString> *keys);

    static bool httpResultResponse(const QString &rawResult);

    static QString requstPostWithQVTCookie(const QString &url, const QString &data);

    static void requestParseKey(const QString &retResponse);

public:
    ////////////////////////////////////// 新版http 请求组件 ////////////////////////////////////
    static QSharedPointer<Biz::HTTPResponce> postJson(const QString &url, const QString &jsonData);

    static QSharedPointer<Biz::HTTPResponce> postText(const QString &url, const QString &text);

    static QSharedPointer<Biz::HTTPResponce> get(const QString &url);

private:
    static QSharedPointer<Biz::HTTPResponce> post(QNetworkRequest request, const QByteArray &ba, int retrytime);

    static QSharedPointer<Biz::HTTPResponce> get(QNetworkRequest request, int retrytime);

    static void addClientCookie(QNetworkRequest &request);

protected:
    static QString makeDomainUrl(const QString &service);

    static QString makeUrl(const QString &service);

    static QString makeNewApiUrl(const QString &service);

    static QString makeInnerUrl(const QString &service);

    static QString makeSecurityString(const QString &url, bool bSec = true);

    static QString makeNavString(const QString &url);

    //如果ckey错误，主动的去拿一次ckey
    static void regetckey();

    static bool
    compareMsgTime(const QSharedPointer<Biz::XmppMessage> &beginmsg, const QSharedPointer<Biz::XmppMessage> &endmsg);
};

