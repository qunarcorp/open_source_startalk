#include "rostertreeview.h"
#include "CallbackReceiver.h"
#include "RosterList.h"
#include "rosterItem.h"
#include "RosterTreeItemModel.h"
#include "Session.h"
#include "Account.h"
#include "RosterTreeItemSortProxyModel.h"
#include <QImageReader>
#include <QXmlStreamWriter>
#include <QKeyEvent>
#include "QXmppUtils.h"
#include "Session.h"
#include "ConfigureHelper.h"
#include "AccountData.h"
#include "XmppMessage.h"
#include "RosterList.h"
#include "UserVcardManager.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "conversationmanager.h"
#include <QMenu>
#include <QtConcurrent/QtConcurrent>
#pragma comment(lib,"Qt5Concurrent.lib")

void ShowPresenceOnlineFun(RosterTreeView* rostertreeview, const QStringList& onlineusers )
{
	rostertreeview->getRosterTreeItemModel()->ShowPresenceOnline(onlineusers);
}
RosterTreeView::RosterTreeView(QWidget *parent)
    : QTreeView(parent)
    , mReceiver(new Biz::CallbackReceiver(this))
    , mChat("Chat", this)
    ,lastDbClickTick(0)
    , mMenu(new QMenu(this))
	,pAddFriend(NULL)
{
    mRosterTreeItemModel = new RosterTreeItemModel(this);
    mRosterItemSortFilterModel = new RosterTreeItemSortProxyModel(this);
    mRosterItemSortFilterModel->setSourceModel(mRosterTreeItemModel);
    this->setModel(mRosterItemSortFilterModel);
    mRosterItemSortFilterModel->sort(0);    

    this->header()->hide();
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);  
    setItemDelegate(new rosterItemDelegate());

    connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicked(QModelIndex)));
    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(clicked(QModelIndex)));
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,[this](const QStringList& onlineUsers){
        mRosterTreeItemModel->onUpdatePresence(onlineUsers);
		//展示在线的人数
		//这个实现，不应该在主线程中占用资源
		//(这样写在虽然在功能上初步的实现了在线的状态问题，但是在代码架构上就显得比较错误了)
		//先暂时屏蔽，后续研究方法给加上
		//mRosterTreeItemModel->ShowPresenceOnline(onlineUsers);
		//QtConcurrent::run(ShowPresenceOnlineFun,this,onlineUsers);
    });

    connect(&Biz::Session::currentAccount(), &Biz::Account::sgRosterListChanged, this, &RosterTreeView::onRosterListChanged );

    setContextMenuPolicy(Qt::CustomContextMenu);  

    setExpandsOnDoubleClick(false);

    connect(this,SIGNAL(customContextMenuRequested(const QPoint &)),   
        this, SLOT(slotCustomContextMenu(const QPoint &)));  


    QAction* pTopAction = mMenu->addAction(QStringLiteral("刷新在线状态")); 
	pAddFriend = mMenu->addAction(QStringLiteral("加为好友"));

    connect(pTopAction, &QAction::triggered,[this](bool){
        Biz::Session::getUserVcardManager()->getOnlineUsersOnTimer();
    });

	connect(pAddFriend, &QAction::triggered,[this](bool){

		QModelIndex currentIndex = this->currentIndex(); 
		if( currentIndex.isValid() ) 
		{
			if (currentIndex.data(rosterItem::IsGroup).toInt()==0)
			{
				QString gn =  currentIndex.data(rosterItem::UserID).toString();

				if (Biz::Session::getFriendManager()->isAlreadyFriend(gn))
				{
                    MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("%1已经是好友了").arg(gn));
					return;
				}

                Biz::Session::getFriendManager()->getUserVerifyMode(gn);
			}
		}
		
	});
}

RosterTreeView::~RosterTreeView()
{

}

void RosterTreeView::onRosterListChanged(const QVariantList& rosterList)
{
    if(mRosterItemSortFilterModel->rowCount() <= 0)
    {
        QStandardItem* prootIndex = mRosterTreeItemModel->initRosterTree();
		if (!prootIndex)
		{
			return;
		}
        QModelIndex currentIndex = mRosterTreeItemModel->indexFromItem(prootIndex);

        if (currentIndex.isValid())
        {
            if (currentIndex.data(rosterItem::IsGroup).toInt()!=0)
            {
                QString gn =  currentIndex.data(rosterItem::GroupFullName).toString();
                rosterItem* ri = mRosterTreeItemModel->getGroupItemByGn(gn);
               
                if (isExpanded(currentIndex))
                {
                    setExpanded(currentIndex,false);
                }
                else 
                {
                    if (!ri->hasChildren()||1==ri->rowCount())
                    {
						mRosterTreeItemModel->bindChild(gn,ri);
                    }
                    setExpanded(currentIndex,true);
                    this->expandAll();
                }
            }
        }
        
    }
}



void RosterTreeView::clicked(const QModelIndex& index)
{
    if (500>QDateTime::currentMSecsSinceEpoch()-lastDbClickTick)
    {
        return;
    }
    expand_helper();
}

void RosterTreeView::expand_helper(){
    QModelIndex currentIndex = this->currentIndex(); 
    if( currentIndex.isValid() ) 
    {
        if (currentIndex.data(rosterItem::IsGroup).toInt()!=0)
        {
            QString gn =  currentIndex.data(rosterItem::GroupFullName).toString();
            rosterItem* ri = mRosterTreeItemModel->getGroupItemByGn(gn);

            if (isExpanded(currentIndex)&&ri->rowCount()>1)
            {
                setExpanded(currentIndex,false);
            }
            else 
            {
                if (!ri->hasChildren()||1==ri->rowCount())
                {
                    mRosterTreeItemModel->bindChild(gn,ri);
                }
                setExpanded(currentIndex,true);
            }

            emit sgGroupAttached(gn);
        }
        else
        {
            QString userid = currentIndex.data(rosterItem::UserID).toString();
            emit sgUserAttached(userid);
        }
    }
}

void RosterTreeView::doubleClicked(const QModelIndex& index)
{
    showChatDialog_helper();
    lastDbClickTick = QDateTime::currentMSecsSinceEpoch();
}


void RosterTreeView::showChatDialog_helper()
{
    QModelIndex currentIndex = this->currentIndex();

    QString userName = selectedUserID();
    if(userName.isEmpty())
        return;
	Biz::Session::getConverSationManager()->setConversationMessageRead(userName);
    rosterItem* pItem =  mRosterTreeItemModel->getRosterItemFromBareJid(Biz::MessageUtil::makeSureUserId(userName));
    if(pItem)
    {
        pItem->setUnreadCount(0);
        emit sgChatDialog(userName, pItem->getDisplayName());
    }
    
}
QString RosterTreeView::selectedUserID()
{
    QModelIndex currentIndex = this->currentIndex();
    if( currentIndex.isValid() )
        return currentIndex.data(rosterItem::UserID).toString();        
    return QString("");
}

void RosterTreeView::keyPressEvent(QKeyEvent* event1)
{
    if(event1->key() == Qt::Key_Return)
    {
        showChatDialog_helper();
    }
    QTreeView::keyPressEvent(event1);
}
QString RosterTreeView::getDisplayName(const QString& peerId)
{
    rosterItem* pItem =  mRosterTreeItemModel->getRosterItemFromBareJid(peerId);
    if( pItem )
        return pItem->getDisplayName();
    return "";
}
 void RosterTreeView::searchContact(const QString& key, QStringList& resultList)
{
    mRosterTreeItemModel->searchRosterList(key, resultList);
}

void RosterTreeView::openChatDialog(const QString& DisplayName)
{
    QString userId = mRosterTreeItemModel->DisplayNameToUserId(DisplayName);
    if(!userId.isEmpty())
    {
        emit sgChatDialog(userId, DisplayName);
    }
    
}

void RosterTreeView::onTraceItem(const QString& userid)
{
    QList<Biz::RosterNode*> usernodes;
    Biz::Session::currentAccount().findRosterUsers(userid,usernodes,true);
    if (usernodes.length() == 0)
    {
        Log::e("find usernode fail " + userid);
        return;
    }
    Biz::RosterNode* pUserNodes = usernodes.at(0);
    Biz::RosterGroup* pGroup = pUserNodes->group;
    QStringList tracePath;
    while (true)
    {
        if (pGroup==NULL)
        {
            break;
        }
        QString fullName = pGroup->getFullName();
		if (!fullName.isEmpty())
		{
			tracePath.push_front(fullName);
		}
        
        pGroup = pGroup->group;
    }
    foreach(QString groupFullName,tracePath)
    {
		
        rosterItem* item = mRosterTreeItemModel->getGroupItemByGn(groupFullName);
		if (item != NULL)
		{
			QModelIndex index = mRosterItemSortFilterModel->mapFromSource(mRosterTreeItemModel->indexFromItem(item));
			setExpanded(index,true);

			if (!item->hasChildren()||1==item->rowCount())
			{
				mRosterTreeItemModel->bindChild(groupFullName,item);
			}
		}
        
    }

    rosterItem* useritem =  mRosterTreeItemModel->getRosterItemFromBareJid(userid);
    QModelIndex index = mRosterItemSortFilterModel->mapFromSource(mRosterTreeItemModel->indexFromItem(useritem));
    setCurrentIndex(index);
    emit sgUserAttached(userid);
}

void RosterTreeView::oncleanData()
{
	mRosterTreeItemModel->cleanData();
	mRosterTreeItemModel->clear();
	mRosterItemSortFilterModel->clear();
}

void RosterTreeView::slotCustomContextMenu(const QPoint &pos)
{
    if (NULL != mMenu)
    {
		QModelIndex currentIndex = this->currentIndex(); 
		if( currentIndex.isValid() ) 
		{
			if (currentIndex.data(rosterItem::IsGroup).toInt()!=0)
			{
				pAddFriend->setVisible(false);
			}
			else
			{
				pAddFriend->setVisible(true);
			}
			
		}
        mMenu->exec(QCursor::pos());
    }
}


