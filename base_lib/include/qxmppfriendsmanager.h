#ifndef QXMPPFRIENDSMANAGER_H
#define QXMPPFRIENDSMANAGER_H


#include <QObject>
#include "QXmppClientExtension.h"

class QFriendVerifyModeIq;
class QFriendsListIq;
class QFriendVerifyResultPresence;
class QXmppDeleteFriendIq;
class QXmppVerifyInfoPresence;
class QXmppAllowVerifyPresence;
class QXmppDeleteFriendPresence;
class QBlackNameListIq;
class QSetBlackNameIq;
class QCancelBlackNameIq;

enum E_DELETE_FRIEND_MODE{
    DELETE_MODE_SINGLE = 1,
    DELETE_MODE_DOUBLE = 2
};


class QXMPP_EXPORT QXmppFriendsManager : public QXmppClientExtension
{
	Q_OBJECT;

public:
    QXmppFriendsManager();
    ~QXmppFriendsManager();

public:
    /*
     *	获取对端的验证模式
     */
    void getVerifyMode (const QString& userid);
    /*
     *	获取验证模式详情
     */
    void getVerifyModeDetail(const QString& userid);

    /*
     *	获取好友列表
     */
    void getFriendList(int version);

    /*
     *	验证好友
     *   0 : 直接拒绝，就不需要发验证了
     *   1 : 发送 verifyFriendInfomation
     *   2 : 发送 verifyFriendQuestion
     *   3 : 发送不带 answer的；
     */
    void verifyFriendInfomation(const QString& userid,const QString& infoText);
    void verifyFriendQuestion(const QString& userid,const QString& answer);
    void verifyFriend(const QString& userid);

    /*
     *	同意好友
     */
    void allowFriend(const QString& selfid, const QString& userid);

    /*
     *	拒绝好友
     */
    void deniedFriend(const QString& selfid, const QString& userid);

    /*
     *	删除好友
     */
    void deleteFriend(const QString& userid,E_DELETE_FRIEND_MODE mode);
	/*
	 *  设置自己的验证方式
	 */
	void setSelfFriendVerify( const QString& userid, int mode, const QString& strquestion, const QString& stranswer );
	/////////////////////黑名单的功能
	/*
	 * 获取黑名单
	 */
	void getBlackNameList(QBlackNameListIq&iq);
	//设置黑名单
	void setBlackName(const QString&Jid, QSetBlackNameIq&iq);
	//取消黑名单
	void cancelBlackName(const QString&Jid, QCancelBlackNameIq&iq);

protected:
    virtual bool handleStanza(const QDomElement &stanza);
    virtual bool handleIq(const QDomElement& iq);
    virtual bool handlePresence(const QDomElement& presence);
    
private:

signals:
    /*
     *	获取到验证模式
     */
    void sgVerifyModeReceive(const QFriendVerifyModeIq& verifyiq);
    /*
     *	获取到好友列表
     */
    void sgFriendsListReceive(const QFriendsListIq& friendListIq);
    /*
     *	收到添加好友的结果，发送方和被邀请方都需要在此
     */
    void sgFriendsVerifyReslutReceive(const QFriendVerifyResultPresence& reulstPresence);

	/*
	*   删除好友
	*/
	void sgDeleteFriendReceive(const QXmppDeleteFriendIq& deletfriendIq);

    void sgFriendsVerifyInfoReceive(const QXmppVerifyInfoPresence& presence);

	/*
	*       文本验证方式时，对方允许加你为好友
	*/
	void sgAllowVerifyFriendReceive(const QXmppAllowVerifyPresence& presence);

	/*
	*     被对方删除时受到的presence
	*/
	void sgDeleteFriendPresenceReceive(const QXmppDeleteFriendPresence& presence);


    void sgMaskUserNotify(const QString& userid);

    void sgCancelMaskUserNotify(const QString& userid);
};

#endif // QXMPPFRIENDSMANAGER_H
