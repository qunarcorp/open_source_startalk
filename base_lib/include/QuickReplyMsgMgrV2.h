#ifndef QUICKREPLYMSGMGRV2_H
#define QUICKREPLYMSGMGRV2_H

#include <QObject>
#include "Player.h" 
#include "BizCallback.h"
#include "loginmanager.h"

namespace Biz{
    class CallbackReceiver; 
}

class QuickReplyMsgMgrV2 : public QObject
{
	Q_OBJECT

public:  
    static QuickReplyMsgMgrV2* getInstance();
	// 本地添加
	// QList<QSharedPointer<Biz::QuickReplyGroup>> getQuickReplyGroupList();
	// QList<QSharedPointer<Biz::QuickReplyContent>> getQuickReplyContentList(const QString &groupCid);
	// void addQuickReplyGroupInfo(QSharedPointer<Biz::QuickReplyGroup> &groupInfo);
	// void addQuickReplyContentInfo(QSharedPointer<Biz::QuickReplyContent> &contentInfo);
	// void updateQuickReplyGroupInfo(QSharedPointer<Biz::QuickReplyGroup> &groupInfo);
	// void updateQuickReplyContentInfo(QSharedPointer<Biz::QuickReplyContent> &contentInfo);
	// void deleteQuickReplyGroupInfo(QSharedPointer<Biz::QuickReplyGroup> &groupInfo);
	// void deleteQuickReplyContentInfo(QSharedPointer<Biz::QuickReplyContent> &contentInfo);

	// 同步信息配置
	void syncQuickReplyToRemote(Biz::UnitCallback<QMap<QString,QVariant>>* callback);
	void updateQuickReplyFromRemote(Biz::UnitCallback<QMap<QString,QVariant>>* callback);
private:  
	Biz::CallbackReceiver* mCallbackReceiver;
    static QuickReplyMsgMgrV2* pInstance;
    QuickReplyMsgMgrV2(QObject *parent);
    ~QuickReplyMsgMgrV2();
	
public slots:
	void onLoginStatusChange(Biz::LoginStatus oldstatus, Biz::LoginStatus newstatus);
};

#endif // QUICKREPLYMSGMGRV2_H
