#include "blacknamelistview.h"

#include <QDateTime>

#include "UserVcardManager.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include <QMenu>
#include <QContextMenuEvent>

#include "UIFrame.h"
#include "friendscontroller.h"

BlackNameListView::BlackNameListView(QWidget *parent)
	: PinnedListView(parent),pMoveBlackNameMenu(NULL)
{
	pMoveBlackNameMenu = new QMenu(this);
	QAction *action = pMoveBlackNameMenu->addAction(QStringLiteral("从该组移出"));
	connect(action,&QAction::triggered,this,&BlackNameListView::onMoveBlackName);


	connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(onItemClicked(QModelIndex)));

    MainApp::UIFrame::getFriendsController ()->registBlackNameListView (this);
}

BlackNameListView::~BlackNameListView()
{

}

void BlackNameListView::onMoveBlackName()
{
    QString jid = currentSelectJid ();
    if (!jid.isEmpty())
    {
        Biz::Session::getFriendManager()->cancelBlackName(jid);
    }
}

void BlackNameListView::contextMenuEvent( const QString& jid)
{
	pMoveBlackNameMenu->exec(QCursor::pos());
}
