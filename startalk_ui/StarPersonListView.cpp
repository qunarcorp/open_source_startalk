#include "StarPersonListView.h"

#include <QDateTime>

#include "UserVcardManager.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include <QMenu>
#include <QContextMenuEvent>

#include "UIFrame.h"
#include "friendscontroller.h"
#include "conversationmanager.h"

StarPersonListView::StarPersonListView(QWidget *parent)
	: PinnedListView(parent)
{
	pMoveBlackNameMenu = new QMenu(this);
	QAction *action = pMoveBlackNameMenu->addAction(QStringLiteral("从该组移出"));
	connect(action,&QAction::triggered,this,&StarPersonListView::onMoveStarPerson);


	connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(onItemClicked(QModelIndex)));

	MainApp::UIFrame::getFriendsController ()->registStarPersonListView (this);
}

StarPersonListView::~StarPersonListView()
{

}

void StarPersonListView::onMoveStarPerson()
{
	QString jid = currentSelectJid ();
	if (!jid.isEmpty())
	{
		Biz::Session::getFriendManager()->setStarPerson(jid, 0);
		Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(jid,0,1);

		// 
	/*	Biz::Session::getGroupManager()->setStarPersonNotice(jid, 1);
		Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(jid,0,1);
		//消息提醒的设置，直接设置到data中
		if (mConversationId2Item.contains(jid)&&NULL!=mConversationId2Item.value(jid))
		{
			QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
			pItem->setNoticeTip(0);
		}
		updateNoticeOption(jid,true);
		*/
	}
}

void StarPersonListView::contextMenuEvent( const QString& jid)
{
	pMoveBlackNameMenu->exec(QCursor::pos());
}
