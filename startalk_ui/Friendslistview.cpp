#include "Friendslistview.h"
#include "Session.h"
#include "Account.h"
#include "SpellHelper.h"
#include "QMenu"
#include "QContextMenuEvent"
#include "QXmppUtils.h"
#include "SystemDefine.h"
#include "UserVcardManager.h"
#include "RosterList.h"
#include "portraithelper.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "dataapplication.h"
#include "NotifyCenterController.h"
#include "friendscontroller.h"

FriendsListView::FriendsListView(QWidget *parent)
	: PinnedListView(parent),pDeleteFriendMenu(NULL)
{
	pDeleteFriendMenu = new QMenu(this);

    QAction* pDeleteAct = NULL;
	QMenu *pSubMenu = pDeleteFriendMenu->addMenu(QStringLiteral("删除好友"));
	pDeleteAct = pSubMenu->addAction(QStringLiteral("从我的好友列表删除"));
	connect(pDeleteAct,&QAction::triggered,this,&FriendsListView::onLocalDeleteFriend);
	pDeleteAct = pSubMenu->addAction(QStringLiteral("从双方的好友列表删除"));
	connect(pDeleteAct,&QAction::triggered,this,&FriendsListView::onCompletelyDeleteFriend);


	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUseVcardChanged,this,&FriendsListView::onFriendVcardChanged);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &FriendsListView::onUpdatePortrait);


    MainApp::UIFrame::getFriendsController ()->registFriendsListView (this);
}

FriendsListView::~FriendsListView()
{
}

void FriendsListView::onLocalDeleteFriend( bool bret )
{
    QString currentId  = currentSelectJid ();
    if (!currentId.isEmpty ())
    {
        Biz::Session::getFriendManager()->getDeleteFriend(currentId, E_DELETE_FRIEND_MODE::DELETE_MODE_SINGLE);
    }
}

void FriendsListView::onCompletelyDeleteFriend( bool bRet )
{
    QString currentId  = currentSelectJid ();
    if (!currentId.isEmpty ())
    {
        Biz::Session::getFriendManager()->getDeleteFriend(currentId, E_DELETE_FRIEND_MODE::DELETE_MODE_DOUBLE);
    }
}

void FriendsListView::onFriendVcardChanged( const QStringList& userinforlist )
{
	for (QString userjid: userinforlist)
	{
		QSharedPointer<Biz::ImSelfPerson> spInfo = Biz::Session::getUserVcardManager()->userVcard(userjid);
		if (!spInfo.isNull())
		{
			QString displayname = spInfo->displayName();
            this->setItemName (userjid,displayname);
		}
	}
}


void FriendsListView::onUpdatePortrait(const QString& userJid)
{
    const QImage& image = Biz::PortraitHelper::getUserPortraitImage(userJid);
    this->setItemImage (userJid,image);
}

void FriendsListView::insertFriendItem(const QString& jid)
{
    if (jid.isEmpty())
        return;

    QString userjid = Biz::MessageUtil::makeSureUserJid (jid);
    QString strdisply = Biz::Session::currentAccount().getUserNameById(userjid);
    this->insertItem (userjid,strdisply);
    const QImage& image = Biz::PortraitHelper::getUserPortraitImage(userjid);
    this->setItemImage (userjid,image);
}


void FriendsListView::contextMenuEvent(const QString& jid)
{
    if (!jid.isEmpty())
    {
        pDeleteFriendMenu->exec(QCursor::pos());
    }
}
