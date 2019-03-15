#include "RosterListWidget.h"
#include "rosterItem.h"
#include <QApplication>
#include <QMenu>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QLabel>

#include "Framework.h"
#include "RecentItemView.h"

#include "UiHelper.h"
#include "rosterItemSortFilterProxyModel.h"
#include "CallbackReceiver.h"
#include "RosterList.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "QXmppUtils.h"
#include "XmppMessage.h"
#include "LanguageHelper.h"
#include "rosterItem.h"
#include "recentrosteritemmvd.h"

#include "group_setting.h"
#include "GroupListData.h"
#include "QMessageBox"
#include "GroupChatDialog.h"
#include "MultiDialogContainer.h"
#include "SystemConfigData.h"
#include "portraithelper.h"
#include <QDrag>
#include "BizCallback.h"


#include "SettingData.h"
#include "CustomDefine.h"
#include "gloableeventobject.h"
#include "UserVcardManager.h"
#include "RobotManager.h"
#include "portraithelper.h"
#include "GroupManager.h"
#include "accountmanager.h"
#include "ChatDialog.h"
#include "conversationmanager.h"

#include "RosterListItems.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"
#include "NotifyCenterController.h"
#include "RosterListItemAdapter.h"

#include "MarkUserInfoWidget.h"
#include "colorset.h"
#include "XmppMessage.h"

#include "conversationmanager.h"
#include "dataapplication.h"
#include "userminiprofile.h"
#include "virtualaccountcontroller.h"
#include "virtualaccountmanager.h"

RosterListWidget::RosterListWidget(QWidget* parent)
    : ConversationListWidget(parent)
    , mReceiver(new Biz::CallbackReceiver(this))
    , groupMenu(new QMenu(this))
    , itemMemu(new QMenu(this))
	,m_pActionBlackNameAction(NULL)
	,m_pActionStarPresonAction(NULL)
	,pGroupRecvWithNotice(NULL)
	,pGroupRecvWithoutNotice(NULL)
	,pSignalRecvWithNotice(NULL)
	,pSignalRecvWithoutNotice(NULL)
{
     connect(this,&ConversationListWidget::conversationActived,[this](const QString& conversationid){
          MainApp::UIFrame::getConversationController()->activeConversation(conversationid);
     });
     connect(this,&ConversationListWidget::extendListActived,[](const QString& extendlistid){
         MainApp::UIFrame::getConversationController()->activeLinkedPannel(extendlistid,true);
     });

	 connect(this,&ConversationListWidget::showAtInfoBlock,[this](const QString& conversationId, const QString& atmsgId){
		 MainApp::UIFrame::getConversationController()->showAtInfoBlockByConversation(conversationId, atmsgId);
	 });

	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUseVcardChanged,this,&RosterListWidget::onUpdateUserVcard);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &RosterListWidget::onUpdatePortrait);

    connect (Biz::Session::getGroupManager (),&Biz::GroupManager::sgGroupVcardUpdated,this,&RosterListWidget::onRoomListNameReceived);
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,this,&RosterListWidget::onUpdatePresence);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgChatWebUpdateStatus, this, &RosterListWidget::onChatWebUpdateStatus);


    QAction* action = NULL;

    action = new QAction(QStringLiteral("清除所有未读"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::clearAllUnreadCount);
    groupMenu->addAction(action);
    groupMenu->addSeparator();
    itemMemu->addAction(action);
    itemMemu->addSeparator();

    action = new QAction(QStringLiteral("修改备注信息"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::addMarkUserInfo);
    groupMenu->addAction(action);

	action = new QAction(QStringLiteral("资料信息"),this);
	connect(action,&QAction::triggered,this,&RosterListWidget::ViewDataInfo);
	groupMenu->addAction(action);
	itemMemu->addAction(action);

    groupMenu->addSeparator();
    itemMemu->addAction(action);
    itemMemu->addSeparator();

    action = new QAction(T_("recent_item_action2"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::setting);
    groupMenu->addAction(action);

    QAction* pTopAction = groupMenu->addAction(QStringLiteral(""));
    connect(pTopAction, &QAction::triggered, this, &RosterListWidget::onToggleGroupSetTop);
    itemMemu->addAction(pTopAction);
    this->m_pActionSetTop = pTopAction;

	//二人里加一个菜单，添加为好友的菜单
	m_pActionFriendAction = groupMenu->addAction(QStringLiteral("添加为好友"));
	connect(m_pActionFriendAction, &QAction::triggered, this, &RosterListWidget::onAddFriends);
	itemMemu->addAction(m_pActionFriendAction);
	
	//二人里添加星标联系人的操作
	m_pActionStarPresonAction = groupMenu->addAction(QStringLiteral("星标联系人"));
	connect(m_pActionStarPresonAction, &QAction::triggered, this, &RosterListWidget::onAddStarPersonNameList);
	itemMemu->addAction(m_pActionStarPresonAction);
	
	//二人里加上移植到黑名单的操作
#ifndef QCHAT
	m_pActionBlackNameAction = groupMenu->addAction(QStringLiteral("移至黑名单"));
	connect(m_pActionBlackNameAction, &QAction::triggered, this, &RosterListWidget::onAddBlackNameList);
	itemMemu->addAction(m_pActionBlackNameAction);
#endif // QCHAT

 	
	//群消息的设置
    QMenu* pSubMenu = groupMenu->addMenu(QStringLiteral("消息提醒设置"));
    action = pSubMenu->addAction(QStringLiteral("接收不提醒消息"));
    pGroupRecvWithoutNotice = action;
    connect(action,&QAction::triggered,this,&RosterListWidget::onRecvWithoutNotice);
    action = pSubMenu->addAction(QStringLiteral("接收并提醒消息"));
    pGroupRecvWithNotice = action;
    connect(action,&QAction::triggered,this,&RosterListWidget::onRecvWithNotice);
    groupMenu->addSeparator();

	//二人消息的设置
 	QMenu* pSignalSubMenu = itemMemu->addMenu(QStringLiteral("消息设置"));
 	action = pSignalSubMenu->addAction(QStringLiteral("接收不提醒消息"));
 	pSignalRecvWithoutNotice = action;
 	connect(action,&QAction::triggered,this,&RosterListWidget::onRecvWithoutNotice);
 	action = pSignalSubMenu->addAction(QStringLiteral("接收并提醒消息"));
 	pSignalRecvWithNotice = action;
 	connect(action,&QAction::triggered,this,&RosterListWidget::onRecvWithNotice);
 	itemMemu->addSeparator();

    action = new QAction(T_("recent_item_action3"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::quit);
    groupMenu->addAction(action);

    groupMenu->addSeparator();
    itemMemu->addSeparator();

    action = new QAction(QStringLiteral("删除会话记录及消息"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::remove);
    groupMenu->addAction(action);
    itemMemu->addAction(action);


    action = new QAction(QStringLiteral("关闭"),this);
    connect(action,&QAction::triggered,this,&RosterListWidget::close);
    groupMenu->addAction(action);
    itemMemu->addAction(action);

    this->setSortingEnabled(true);

    setAcceptDrops(true);


    unreadBtn = new QPushButton(this);
    unreadBtn->setFlat(true);
    unreadBtn->setFixedSize(70,32);
    unreadBtn->setStyleSheet("color:#FFFFFF;border-image:url(:/Images/bubble_newmessage.png);");
    unreadBtn->setText(QStringLiteral("未读消息"));
    unreadBtn->move(90,10);
    unreadBtn->setVisible(false);
    connect(unreadBtn,&QPushButton::clicked,[this](bool b){
        this->verticalScrollBar()->setValue(0);
    });

    connect(this->verticalScrollBar(),&QScrollBar::valueChanged,[this](int value){
        if (50 > value) // 一个item的高度
        {
            unreadBtn->setVisible(false);
        }
    });


    connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgVcardUpdateNotify,this,&RosterListWidget::onRobotVcardUpdated);

    connect(MainApp::UIFrame::getMainDialogController(),&MainDialogController::sgMainThemeChanged,this,&RosterListWidget::onMainThemeChanged);
	connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgAddBlackName, this, &RosterListWidget::onAddBlackName);
	connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgBlackNameListUpdate, this, &RosterListWidget::onBlackNameListUpdate);
}

RosterListWidget::~RosterListWidget()
{
    disconnect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgVcardUpdateNotify,this,&RosterListWidget::onRobotVcardUpdated);
    disconnect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,this,&RosterListWidget::onUpdatePresence);
}


void RosterListWidget::profile(bool check) {
    QModelIndexList list = this->selectedIndexes();

    if (list.size()>0)
    {
        bool b = list.at(0).data(RecentRosterItem::IsGroupChat).toBool();
        if (b)
        {
            QString str = list.at(0).data(RecentRosterItem::UserID).toString();
            Biz::Session::getGroupManager()->requestConfigration(str);
        }
        else
        {
        }
    }
}
void RosterListWidget::setting(bool check){
    QListWidgetItem* item = this->currentItem();
    RecentItemView* view = (RecentItemView*)itemWidget(item);
        QString jid = view->Id();
        GroupSettingDialog* gsd = GroupSettingDialog::getInstance();
        gsd->setupData(jid);
        gsd->initUi();
        gsd->activateWindow();
        gsd->showNormal();
}
void RosterListWidget::quit(bool check){

    QListWidgetItem* item = this->currentItem();
    RecentItemView* view = (RecentItemView*)itemWidget(item);
    QString strselect = view->Id();
    int nrow = currentRow();

    if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (QStringLiteral("退出群之后将无法接收群消息，是否退出？")))
    {
        return;
    }

    Biz::Session::getGroupManager()->leaveGroup(strselect);
    return;
}
void RosterListWidget::close(bool check){

    QListWidgetItem* item = this->currentItem();
    QListWidgetItemSortable* pSortItem = dynamic_cast<QListWidgetItemSortable*>(item);
    if (NULL ==pSortItem)
    {
        Log::e("RosterListView::closeItem item is null");
        return;
    }
    QString conversationId = pSortItem->conversationId();
    closeItem(conversationId);
}
void RosterListWidget::remove(bool check)
{
    QListWidgetItem* item = this->currentItem();
    QListWidgetItemSortable* pSortItem = dynamic_cast<QListWidgetItemSortable*>(item);
    if (NULL ==pSortItem)
        return;

    QString conversationId = pSortItem->conversationId();
    // 会话层删除会话记录
    MainApp::UIFrame::getConversationController()->removeConversation(conversationId);
    // 删除数据库中会话记录以及历史消息
    Biz::Session::getConverSationManager()->deleteConversation(conversationId);


}

void RosterListWidget::closeItem(const QString& conversationid)
{
    MainApp::UIFrame::getConversationController()->removeConversation(conversationid);
    Biz::Session::getConverSationManager()->removeChartingImSession(conversationid);

	//如果是虚拟账号，就应该结束session
	if (Biz::Session::getVirtualManager()->IsVirtualAccount(Biz::MessageUtil::makeSureUserId(conversationid)))
	{
		Biz::Session::getVirtualManager()->setvirtualaccountEndChat(Biz::MessageUtil::makeSureUserId(conversationid));
	}
}

// 
// void RosterListView::updatePresence(const QString& userId, int status)
// {
//    doSetUserHeader(userId);
// }
void RosterListWidget::onUpdatePresence(const QStringList& onlineUserLst)
{
    Q_UNUSED(onlineUserLst);

    for (QListWidgetItemSortable* pItem:mConversationId2Item.values())
    {
        if (NULL != pItem && !pItem->isGroupChatItem())
        {
            QString userId = mConversationId2Item.key(pItem);
            doSetUserHeader(userId);
        }
    }
}

void RosterListWidget::contextMenuEvent(QContextMenuEvent * e)
{
    QListWidgetItem* itemclick = this->itemAt(e->pos());
    if (itemclick == NULL)
    {
        return;
    }

    QListWidgetItem* item = this->currentItem();
    QListWidgetItemSortable* sortableItem = dynamic_cast<QListWidgetItemSortable*>(item);

    m_pActionSetTop->setText(sortableItem->isTop()?QStringLiteral("取消置顶"):QStringLiteral("置顶聊天"));

    if (sortableItem->isGroupChatItem())
    {
        QString groupJid = sortableItem->conversationId();

		//现在不从groups.dat中取数据了
		auto successparam = [this](int flag)
		{
			pGroupRecvWithNotice->setIcon( (flag & Biz::SESSION_CFG_SILENCE) !=Biz::SESSION_CFG_SILENCE?QIcon(QPixmap(":Images/accept_button.png")):QIcon());
			pGroupRecvWithoutNotice->setIcon( (flag & Biz::SESSION_CFG_SILENCE)==Biz::SESSION_CFG_SILENCE?QIcon(QPixmap(":Images/accept_button.png")):QIcon());
			groupMenu->exec(QCursor::pos());
		};
		auto failparam = [this]
		{
			groupMenu->exec(QCursor::pos());
		};
		auto req = mReceiver->createCallback<int>(successparam, failparam);
		Biz::Session::currentAccount().doGetGroupExternFlagbyJid(groupJid, req);
		if (m_pActionFriendAction)
		{
			m_pActionFriendAction->setVisible(false);
		}
		if (m_pActionBlackNameAction)
		{
			m_pActionBlackNameAction->setVisible(false);
		}
		if (m_pActionStarPresonAction)
		{
			m_pActionStarPresonAction->setVisible(false);
		}
    }
    else if (sortableItem->isLinkedItem())
    {
        // 没有菜单
    }
    else 
    {
		if (sortableItem->isSimpleChatItem())
		{
			QString groupJid = sortableItem->conversationId();
			auto successparam = [this](int flag)
			{
				pSignalRecvWithNotice->setIcon( (flag & Biz::SESSION_CFG_SILENCE) !=Biz::SESSION_CFG_SILENCE?QIcon(QPixmap(":Images/accept_button.png")):QIcon());
				pSignalRecvWithoutNotice->setIcon( (flag & Biz::SESSION_CFG_SILENCE)==Biz::SESSION_CFG_SILENCE?QIcon(QPixmap(":Images/accept_button.png")):QIcon());
				itemMemu->exec(QCursor::pos());
			};
			auto failparam = [this]
			{
				itemMemu->exec(QCursor::pos());
			};
			auto req = mReceiver->createCallback<int>(successparam, failparam);
			Biz::Session::currentAccount().doGetGroupExternFlagbyJid(groupJid, req);
		}
		if (m_pActionFriendAction)
		{
			m_pActionFriendAction->setVisible(sortableItem->isSimpleChatItem());
		}
		if (m_pActionBlackNameAction)
		{
			m_pActionBlackNameAction->setVisible(sortableItem->isSimpleChatItem());
		}
		if (m_pActionStarPresonAction)
		{
			m_pActionStarPresonAction->setVisible(sortableItem->isSimpleChatItem());
		}
        itemMemu->exec(QCursor::pos());
    }
}
void RosterListWidget::onToggleGroupSetTop(bool) {
    QListWidgetItem* item = this->currentItem();
    QListWidgetItemSortable* sortableItem = dynamic_cast<QListWidgetItemSortable*>(item);

    bool currentValue = sortableItem->isTop();

    RecentItemView* view = (RecentItemView*)itemWidget(item);
    QString xmppid = view->Id();

    updateTopMost(xmppid,!currentValue);

    !currentValue?
        Biz::Session::getConverSationManager()->updateRecentImSessionConfigration(xmppid,Biz::SESSION_CFG_TOPMOST,0):
    Biz::Session::getConverSationManager()->updateRecentImSessionConfigration(xmppid,0,Biz::SESSION_CFG_TOPMOST);

}

void RosterListWidget::onRecvWithNotice(bool)
{
    QListWidgetItem* item = this->currentItem();
    RecentItemView* view = (RecentItemView*)itemWidget(item);
    QString jid = view->Id();

    
   // 
	Biz::Session::getGroupManager()->setMessageNotice(jid, Biz::SESSION_CFG_SILENCE);
	Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(jid,0,Biz::SESSION_CFG_SILENCE);
	//消息提醒的设置，直接设置到data中
	if (mConversationId2Item.contains(jid)&&NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setNoticeTip(0);
	}
    updateNoticeOption(jid,true);
   
}

void RosterListWidget::onRecvWithoutNotice(bool)
{
    QListWidgetItem* item = this->currentItem();
    RecentItemView* view = (RecentItemView*)itemWidget(item);
    QString jid = view->Id();

    //
	Biz::Session::getGroupManager()->setMessageNotice(jid, 0);

	Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(jid,Biz::SESSION_CFG_SILENCE,0);

	//消息提醒的设置，直接设置到data中
	if (mConversationId2Item.contains(jid)&&NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setNoticeTip(Biz::SESSION_CFG_SILENCE);
	}

    updateNoticeOption(jid,false);
    
}


void RosterListWidget::onRoomListNameReceived(const QStringList& mapData)
{
    Biz::GroupListData* pList = Biz::Session::getAccountManager ()->getGroupsData ();
    if (NULL==pList)
        return;
    Log::e(QString("RosterListWidget::onRoomListNameReceived  mapdata size =%1").arg(mapData.size()));
    for (QString conversationId: mapData)
    {
        if (mConversationId2Item.contains(conversationId)&&NULL!=mConversationId2Item.value(conversationId))
        {
            Biz::GroupSetting* pSetting = pList->getGroupSetting(conversationId);
            if (NULL!=pSetting)
            {
                QString groupName = pSetting->Name ();
                if (!groupName.isEmpty ())
                {
                    QListWidgetItemSortable* pItem = mConversationId2Item.value(conversationId);

                    pItem->setTitle(groupName);
					Log::e(QString("RosterListWidget::onRoomListNameReceived groupName=%1").arg(groupName));
                }
            }
        }
    }
}


bool RosterListWidget::isItemWidgetVisable(QWidget* pwidiget)
{
    if (NULL == pwidiget)
    {
        return true; // false 顶气泡
    }

    QPoint parentPos = pwidiget->pos();
    return 0<=parentPos.y();
}


void RosterListWidget::onRostListDown()
{
	int curPos = this->currentRow();
	if(curPos!=-1)
	{
		int nextRow = curPos+1 >= this->count() ? -1:curPos+1;
		this->setCurrentRow(nextRow);
		if (nextRow<0)
		{
			this->setCurrentRow(0);
		}
	}

}

void RosterListWidget::onRostListUp()
{
	int curPos = this->currentRow();
	if(curPos!=-1)
	{
		int nextRow = curPos-1;
		this->setCurrentRow(nextRow);
		if (nextRow<0)
		{
			this->setCurrentRow(this->count()-1);
		}
	}
}

void RosterListWidget::doCloseLastItemChat()
{
    int rawCount = MainApp::UIFrame::getConversationController()->getCouversationCount();
    
    Biz::AllUserSettingData* pSetting = Biz::Session::getSettingConfig();
    if (NULL!=pSetting && rawCount<pSetting->MaxSessionLimited())
        return;

    QListWidgetItem* pItem = item(rawCount-1);


    QListWidgetItemSortable* pSortItem = dynamic_cast<QListWidgetItemSortable*>(pItem);
    if (NULL ==pSortItem)
    {
        Log::e("RosterListView::closeItem item is null");
        return;
    }
    QString conversationId = pSortItem->conversationId();
    closeItem(conversationId);
}

void RosterListWidget::clearAllUnreadCount()
{
	if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",QStringLiteral("确定要清除所有未读？"),QStringLiteral("取消"),QStringLiteral("确认")))
	{
			MainApp::UIFrame::getConversationController()->setAllMessageRead();
	}
}

void RosterListWidget::onChatWebUpdateStatus( const QString& groupjid, bool bret )
{
// 	QStringList simpleChatUids;
// 	QMap<QString,RecentItemView*>::iterator iter = mUid2RecentItemView.begin();
// 	for (; iter!=mUid2RecentItemView.end();iter++)
// 	{
// 		if (!(*iter)->isGroupChat())
// 		{
// 			QString userId = iter.key();
// 			doSetUserHeader(userId);
// 		}
// 	}
}

void RosterListWidget::onAddFriends( bool bret )
{
	QListWidgetItem* item = this->currentItem();
	RecentItemView* view = (RecentItemView*)itemWidget(item);
	QString jid = view->Id();
	
	if (Biz::Session::getFriendManager()->isAlreadyFriend(jid))
	{
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("%1已经是好友了").arg(jid));
		return;
	}

    Biz::Session::getFriendManager()->getUserVerifyMode(jid);    
}

void RosterListWidget::onRobotVcardUpdated(const QStringList& updatedList)
{
    for (QString id:updatedList)
    {
       updatevCard(id);
    }
}

void RosterListWidget::onUpdateUserVcard( const QStringList& userinforlist )
{
	foreach (QString userid, userinforlist)
	{
		QSharedPointer<Biz::ImSelfPerson> person = Biz::Session::getUserVcardManager()->userVcard(userid);
		if (!person.isNull())
		{
			QString userid = person->strUserId;
            if (mConversationId2Item.contains(userid) && NULL!=mConversationId2Item.value(userid))
            {
                QListWidgetItemSortable* pItem = mConversationId2Item.value(userid);
                pItem->setTitle(person->displayName());
            }
			//else
			{
				const QList<QString>& ids = mConversationId2Item.keys();
				auto it = std::find_if(ids.cbegin(), ids.cend(), [userid, ids](const QString& id)
				{
					return id.contains("|shop") && id.mid(0, id.indexOf("|shop")) == userid;
				});
				if (it != ids.cend())
				{
					QListWidgetItemSortable* pItem = mConversationId2Item.value(*it);
					pItem->setTitle(person->displayName());
				}
			}
		}
	}
}

void RosterListWidget::onUpdatePortrait(const QString& userJid)
{
	doSetUserHeader(userJid);
}

void RosterListWidget::addMarkUserInfo()
{
    QListWidgetItem* item = this->currentItem();
    QListWidgetItemSortable* pSortItem = dynamic_cast<QListWidgetItemSortable*>(item);
    if (NULL ==pSortItem)
        return;

    QString conversationId = pSortItem->conversationId();

    MarkUserInfoWidgetSingleton::getInstance()->setData(conversationId);
    MarkUserInfoWidgetSingleton::getInstance()->show();
}


void RosterListWidget::onMainThemeChanged()
{
    RosterListItemAdapter* pAdapter = dynamic_cast<RosterListItemAdapter*>(itemDelegate());
    if (NULL!=pAdapter)
    {
        pAdapter->setNormalBackground(ColorSetSingleton::getInstance()->transparent());
        pAdapter->setHoverBackground(ColorSetSingleton::getInstance()->recent_item_bk_hover());
        pAdapter->setSelectBackground(ColorSetSingleton::getInstance()->recent_item_bk_checked());
    }
}

void RosterListWidget::onAddBlackNameList( bool )
{
	QListWidgetItem* item = this->currentItem();
	RecentItemView* view = (RecentItemView*)itemWidget(item);
	QString jid = view->Id();
	QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(jid);
	if (displayname.isEmpty())
	{
		displayname = Biz::MessageUtil::makeSureUserId(jid);
	}
	if (Biz::Session::getFriendManager()->getBlackNameInfoList().contains(Biz::MessageUtil::makeSureUserJid(jid)))
	{
		

        MainApp::UIFrame::getNotifyCenterController ()->popupNotice (QStringLiteral("%1已经在黑名单").arg(displayname));
		return;
	}

	//增加第二次询问
	QString strMessage = QStringLiteral("是否确定把[%1]加入黑名单？").arg(displayname);
	if (MainApp::UIFrame::getNotifyCenterController()->alertMessage ("",strMessage,QStringLiteral("取消"),QStringLiteral("确定")))
	{
		Biz::Session::getFriendManager()->setBlackName(jid);  
	}

	  
}

// 设置星标联系人处理槽函数
void RosterListWidget::onAddStarPersonNameList(bool)
{
	QListWidgetItem* item = this->currentItem();
	RecentItemView* view = (RecentItemView*)itemWidget(item);
	QString jid = view->Id();


	// 
	Biz::Session::getFriendManager()->setStarPerson(jid, 1);
	Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(jid,0,1);
	//星标联系人的设置，直接设置到列表的item  data的相应role 中
	if (mConversationId2Item.contains(jid)&&NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setStarPerson(0);
	}
//	updateNoticeOption(jid,true);
}

void RosterListWidget::onAddBlackName( const QString& jid, int rt )
{
	if (jid.isEmpty())
	{
		return;
	}
	if (rt == Biz::FriendsManager::RESULTSUCCESS)
	{
		//删掉该item
		deleteItem(jid);
	}
}

void RosterListWidget::ViewDataInfo()
{
	QListWidgetItem* item = this->currentItem();
	QListWidgetItemSortable* sortableItem = dynamic_cast<QListWidgetItemSortable*>(item);
	QString jid = sortableItem->conversationId();

	if(sortableItem->isSimpleChatItem())
	{
		UserMiniProfile::getInstance()->setUserid(jid);
		UserMiniProfile::getInstance()->autoshow();
	}
	if (sortableItem->isGroupChatItem())
	{
		Biz::Session::getUserVcardManager()->getRoomVcardByforce(jid);
		setting(true);
	}
}

void RosterListWidget::updateNoticeOption(const QString& jid,bool bNotice)
{
    if (jid.contains("@"))
    {
        Biz::GroupListData *gld = Biz::Session::currentAccount().getGroupsData();
        if (NULL != gld)
        {
			//二人对话也用到了Biz::GroupSetting设置消息提醒标识
            Biz::GroupSetting* pgs = gld->getGroupSetting(jid);
            if (NULL!=pgs)
            {
                pgs->GroupMsgNoticeOption(bNotice?Biz::GroupSetting::RECV_WITH_NOTICE:Biz::GroupSetting::RECV_WITHOUT_NOTICE);
                emit Biz::Session::getUserVcardManager()->sgGroupHeaderUpdate(jid);
            }
        }
    }
}

void RosterListWidget::autoscrolltoTop()
{
    scrollToTop();
}

void RosterListWidget::onBlackNameListUpdate( const QStringList& blacknamelist )
{
	if (blacknamelist.size() <= 0)
	{
		return;
	}
	
	for (QString oneblackname: blacknamelist)
	{
		deleteItem(oneblackname);
		// 删除数据库中会话记录以及历史消息
		//Biz::Session::getConverSationManager()->deleteConversation(oneblackname);
	}

}