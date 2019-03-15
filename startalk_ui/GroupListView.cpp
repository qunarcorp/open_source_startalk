#include "GroupListView.h"

#include <QAction>
#include "CallbackReceiver.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "QXmppUtils.h"
#include "group_setting.h"
#include "GroupListData.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

#include "GroupManager.h"
#include "UserVcardManager.h"
#include "accountmanager.h"

#include "groupscontroller.h"
#include "UIFrame.h"

GroupListView::GroupListView(QWidget *parent)
    : PinnedListView(parent)
 
{
    // init menu
    QAction* pAction = NULL;
    pContentMenu = new QMenu(this);
    pAction = pContentMenu->addAction(QStringLiteral("群设置"));
    connect(pAction,&QAction::triggered,this,&GroupListView::onOpenSettingView);

    
    pContentMenu->addSeparator();

    pAction = pContentMenu->addAction(QStringLiteral("退出群"));
    connect(pAction,&QAction::triggered,this,&GroupListView::onLeaveGroup);
    
// 	 connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,[this](const QString& jid){
//         mGroupItemModel->updateGroupAvatar(jid);
//     });

	connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupNoticeTipChange,this, &GroupListView::onGroupNoticeTipChange);


    MainApp::UIFrame::getGroupsController ()->registerGroupListView (this);
}

GroupListView::~GroupListView()
{

}

void GroupListView::contextMenuEvent(const QString& groupjid)
{
    if (!groupjid.isEmpty())
    {
        pContentMenu->exec(QCursor::pos());
    }
}

void GroupListView::onOpenSettingView(bool)
{
    QString groupJid = currentSelectJid ();
    if (!groupJid.isEmpty())
    {
        GroupSettingDialog* gsd = GroupSettingDialog::getInstance();
        gsd->hide();
        gsd->setupData(groupJid);
        gsd->initUi();
        gsd->activateWindow();
        gsd->showNormal();
    }
}

void GroupListView::onLeaveGroup(bool)
{
    QString groupJid = currentSelectJid ();
    if (!groupJid.isEmpty())
    {
        if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (QStringLiteral("退出群之后将无法接收群消息，是否退出？")))
            return;
        Biz::Session::getGroupManager()->leaveGroup(groupJid);
    }
}

void GroupListView::onGroupNoticeTipChange( const QString& groupjid, int addoption, int removeoption )
{
	setGroupNoticeTipChangeinned(groupjid, addoption, removeoption);
}

void GroupListView::setGroupNoticeTip( const QString& groupjid, int noticeflag )
{
	setGroupNoticeTipinned(groupjid, noticeflag);
}

