#include "conversationlistwidget.h"

#include "RosterListItems.h"
#include "RecentItemView.h"
#include "RosterListItemAdapter.h"

#include "Session.h"
#include "GroupManager.h"
#include "UserVcardManager.h"
#include "conversationmanager.h"
#include "UserVcardManager.h"
#include "virtualaccountmanager.h"
#include "UtilHelper.h"
#include "SystemConfigData.h"
#include "SystemDefine.h"

ConversationListWidget::ConversationListWidget(QWidget* parent)
	: QListWidget(parent)
	,mReceiver(new Biz::CallbackReceiver(this))
{
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	RosterListItemAdapter* pAdapter = new RosterListItemAdapter(this);
	this->setItemDelegate(pAdapter);

	connect(this, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,
		SLOT(currentItemChanged(QListWidgetItem*,QListWidgetItem*)));

	connect(this,&QListWidget::itemClicked,this,&ConversationListWidget::itemClicked);
}

ConversationListWidget::~ConversationListWidget(void)
{

}


void ConversationListWidget::insertItem(const QString& conversationId,QListWidgetItemSortable* item)
{
	mConversationId2Item.insert(conversationId,item);
}

void ConversationListWidget::doSetUserHeader(const QString& userId)
{
	if (mConversationId2Item.contains(userId) && NULL!=mConversationId2Item.value(userId))
	{

		mConversationId2Item.value(userId)->setUserImageChange(QDateTime::currentMSecsSinceEpoch());
		Log::e(QString("ConversationListWidget::doSetUserHeader userId=%1").arg(userId));
	}
}

QListWidgetItem* ConversationListWidget::getConversationItem(const QString& conversationId)
{
	// 判定本层
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId);
	}
	return NULL;
}

void ConversationListWidget::addGroupChatDialog(const QString& jid)
{
	if (mConversationId2Item.contains(jid))
		return;

	doCloseLastItemChat();

	GroupChatItem* pItem = new GroupChatItem(this);
	pItem->setConversationId(jid);
	pItem->setText(jid);
	pItem->setTitle(Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(jid));
	// pItem->setTitle(Biz::Session::getGroupManager()->getGroupNickName(jid));
	insertItem(jid,pItem);

	Log::e(QString("RosterListView::addGroupChatDialog RecentItemView id =%1").arg(jid));
}


void ConversationListWidget::addChatDialog(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
		return;

	doCloseLastItemChat();
	SimpleChatItem* pItem = new SimpleChatItem(this);
	pItem->setConversationId(conversationId);
	//判断是否是虚拟账号
	if (Util::UtilHelper::isVirtualAccountId(conversationId, Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		QString strRealName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Util::UtilHelper::getRealIdfromID(conversationId));
		QString strVirtualName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Util::UtilHelper::getvirtualfromID(conversationId));
#ifdef QCHAT
		QString userName = QStringLiteral("%1").arg(strRealName);
#else
		QString userName = QString("%1-%2").arg(strVirtualName, strRealName);
#endif // QCHAT


		pItem->setTitle(userName);
	}
	else
	{
		pItem->setTitle(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
	}

	pItem->setText(conversationId);
	insertItem(conversationId,pItem);
	Log::e(QString("RosterListView::addChatDialog RecentItemView id =%1").arg(conversationId));
}

void ConversationListWidget::addConsultDialog(const QString& conversationId,const QString& virtualid,const QString& realseat,bool isSeat)
{
	if (mConversationId2Item.contains(conversationId))
		return;

	doCloseLastItemChat();
	ConsultChatItem* pItem = new ConsultChatItem(this);
	pItem->setConversationId(conversationId);
	pItem->setVirtualAccount(virtualid);
	pItem->setRealJid(realseat);
	pItem->setIsSeat(isSeat);
	// 兼容RealJid丢了的问题，由于逻辑不熟 先整好 再找原因
	if (pItem->getRealJid().length() <= 0)
	{
		QStringList list = pItem->conversationId().split("|");
		if (list.length() == 2)
		{
			pItem->setRealJid(list.first()); 
			pItem->setVirtualAccount(list.last());
			if (pItem->getRealJid().length() <= 0)
			{
				return;
			}
		} else
		{
			// 异常逻辑 暂时忽略掉会话 这种的是作为用户咨询的
			// return;
		}
	}
	//判断是否是虚拟账号
	if (isSeat)
	{
		QString strRealName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(realseat);
		QString strVirtualName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(virtualid);
#ifdef QCHAT
		QString userName = QStringLiteral("%1").arg(strRealName);
#else
		QString userName = QString("%1-%2").arg(strVirtualName, strRealName);
#endif // QCHAT

		pItem->setTitle(userName);
	}
	else
	{
		pItem->setTitle(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
	}

	pItem->setText(conversationId);
	insertItem(conversationId,pItem);
	Log::e(QString("RosterListView::addConsultDialog RecentItemView id =%1").arg(conversationId));
}



void ConversationListWidget::addNewsDialog(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
		return;

	doCloseLastItemChat();


	NewsChatItem* pItem = new NewsChatItem(this);
	pItem->setConversationId(conversationId);
	pItem->setTitle(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
	pItem->setText(conversationId);
	insertItem(conversationId,pItem);

	Log::e(QString("RosterListView::addNewsDialog RecentItemView id =%1").arg(conversationId));
}



void ConversationListWidget::addRawHtmlDialog(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
		return;

	doCloseLastItemChat();


	SimpleChatItem* pItem = new SimpleChatItem(this);
	pItem->setConversationId(conversationId);
	pItem->setTitle(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
	pItem->setText(conversationId);
	insertItem(conversationId,pItem);

	Log::e(QString("RosterListView::addChatDialog RecentItemView id =%1").arg(conversationId));

}


void ConversationListWidget::addLinkItem( const QString& conversationId,
										 const QString& conversationName,
										 const QString& belongExtendid)
{

	if (mConversationId2Item.contains(conversationId))
		return;

	doCloseLastItemChat();
	LinkedItem* pItem = new LinkedItem(this);
	pItem->setConversationId(conversationId);
	pItem->setTitle(conversationName);
	pItem->setText(conversationId);
	pItem->setLinkedKey(conversationId);
	insertItem(conversationId,pItem);

	Log::e(QString("RosterListView::addLinkItem RecentItemView id =%1").arg(conversationId));
}



void ConversationListWidget::addRobotDialog(const QString& conversationId)
{

	if (mConversationId2Item.contains(conversationId))
		return;

	Log::e(QString("ConversationListWidget::addRobotDialog RecentItemView id =%1").arg(conversationId));

	doCloseLastItemChat();
	RobotChatItem* pItem = new RobotChatItem(this);
	pItem->setConversationId(conversationId);
	pItem->setTitle(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
	pItem->setText(conversationId);
	insertItem(conversationId,pItem);
}



void ConversationListWidget::doCloseLastItemChat()
{

}

bool ConversationListWidget::isConsultChatItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isConsultChatItem();
	}
	return false;
}
bool ConversationListWidget::isSimpleChatItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isSimpleChatItem();
	}
	return false;
}

bool ConversationListWidget::isGroupChatItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isGroupChatItem();
	}
	return false;
}

bool ConversationListWidget::isNewsChatItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isNewsChatItem();
	}
	return false;
}

bool ConversationListWidget::isRobotChatItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isRobotChatItem();
	}
	return false;
}

bool ConversationListWidget::isLinkedItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isLinkedItem();
	}
	return false;
}

bool ConversationListWidget::isRawHtmlItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId))
	{
		return mConversationId2Item.value(conversationId)->isRawHtmlItem();
	}
	return false;
}

void ConversationListWidget::updateUnReadCount(const QString&jid, int nCount)
{
	if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setUnreadCount(nCount);
	}
}

void ConversationListWidget::updateLinkItemUnReadCount(const QString&jid)
{
	if (mConversationId2Item.contains(jid))
	{

		auto successparam = [this, jid](int unReadcount)
		{
			// 异步切换，以前的判定不可信
			if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
			{
				QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
				pItem->setUnreadCount(unReadcount);
			}
		};
		auto failparam = [this]
		{

		};
		auto req = mReceiver->createCallback<int>(successparam, failparam);

		Biz::Session::getConverSationManager()->getLinkItemUnReadCount(jid, req);
	}
}

void ConversationListWidget::updateAtCount(const QString&jid, int count, int type)
{
	if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
	{
		mConversationId2Item.value(jid)->setAtCount(count);
		mConversationId2Item.value(jid)->setAtType(type);
	}
}


void ConversationListWidget::updateGroupHeader(const QString& jid)
{
	doSetUserHeader(jid);
}


void ConversationListWidget::updatevCard(const QString& id)
{
	doSetUserHeader(id);
}

void ConversationListWidget::updateTopMost(const QString& jid, bool bTopMost)
{
	if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
	{
		Log::e(QString("ConversationListWidget::updateTopMost xmppid = %1  bTopMost=%2").arg(jid).arg(bTopMost));
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setTop(bTopMost);
	}
}


void ConversationListWidget::updateConversationLastTimeStamp(const QString& userId, quint64 timestamp)
{
	Log::e(QString("%1 updateConversationLastTimeStamp:conversationId(%2),time(%3)").arg(QStringLiteral("设置会话的最后时间")).arg(userId).arg(timestamp));
	QString userIdStr;
	userIdStr = QStringList(mConversationId2Item.keys()).join(",");
	Log::e(QString("%1 updateConversationLastTimeStamp:mConversationId2Item list(%2)").arg(QStringLiteral("设置会话的最后时间")).arg(userIdStr));
	if (mConversationId2Item.contains(userId)&&NULL!=mConversationId2Item.value(userId))
	{
		mConversationId2Item.value(userId)->setLastTimeStamp(timestamp);
		Log::e(QString("%1 updateJidLastTimeStamp:conversationId(%2),time(%3)").arg(QStringLiteral("设置会话的最后时间完成")).arg(userId).arg(timestamp));
	}
}

void ConversationListWidget::updateAllConversationUnreadCount()
{
	for (QListWidgetItemSortable* pItem : mConversationId2Item.values())
	{
		pItem->setUnreadCount(0);
	}
}

void ConversationListWidget::increaseAtCount(const QString&jid, int count, int type, const QString& msgid)
{
	if (mConversationId2Item.contains(jid)&&NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		int currntCount = pItem->atCount();
		pItem->setAtCount(currntCount+count);
		pItem->setAtmsgId(msgid);
		pItem->setAtType(type);
	}
}

void ConversationListWidget::updateRobotVcard(const QString& conversationId,const QString& displayName)
{
	if (mConversationId2Item.contains(conversationId) && NULL!=mConversationId2Item.value(conversationId))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(conversationId);
		if (pItem->isRobotChatItem())
			pItem->setTitle(displayName);
	}
}


void ConversationListWidget::clearData()
{
	mConversationId2Item.clear();
	this->clearSelection();
	this->clear();
}

void ConversationListWidget::autoScroll(const QString& userid,QAbstractItemView::ScrollHint hint /*= EnsureVisible*/)
{
	if (mConversationId2Item.contains(userid)&&NULL!=mConversationId2Item.value(userid))
	{
		scrollToItem(mConversationId2Item.value(userid),hint);
		// 不知为啥会引起乱滚的异常,先注释掉 2016年9月6日
		//scrollToTop();
	}
}

void ConversationListWidget::activityChatDialog(const QString& uid)
{
	if(mConversationId2Item.contains(uid) && NULL != mConversationId2Item.value(uid))
	{
		setCurrentItem(mConversationId2Item.value(uid));
		autoScroll(uid);
	}
}



void ConversationListWidget::deleteItem(const QString& conversationId)
{
	if (mConversationId2Item.contains(conversationId)&& NULL!=mConversationId2Item.value(conversationId));
	{
		QListWidgetItem* item = mConversationId2Item.value(conversationId);
		int nR = row (item);
		item = takeItem(nR);
		delete item;
		mConversationId2Item.remove(conversationId);
		Log::e(QString("RosterListView::deleteItem to destroy RecentItemView jid =%1").arg(conversationId));
	}
}

bool ConversationListWidget::hasCouversation(const QString& conversatindId)
{
	return NULL != getConversationItem(conversatindId);
}


QString ConversationListWidget::currentUid()
{
	QListWidgetItem* item = this->currentItem();
	if (NULL==item)
	{
		return "";
	}
	RecentItemView* view = (RecentItemView*)itemWidget(item);
	if (view!=NULL)
	{
		return view->Id();
	}
	return "";
}




// slots here ////////////////////////////////////////////////////////////////////////
void ConversationListWidget::currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous)
{
	if (NULL == current)
		return;

	QString conversationId = current->data(RosterListItemDataConversationId).toString();
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("ConversationListWidget::currentItemChanged begin time=%1 groupjid=%2").arg(getmsgendticked).arg(conversationId));
	if (conversationId.isEmpty())
	{
		Log::e("RosterListView::currentItemChanged isempty");
		return;
	}

	//这地方判断一下，是否有at信息，如果有at信息，则在聊天框显示at块
	int ncount = current->data(RosterListItemDataAtCount).toInt();

	if (ncount > 0)
	{
		QString strMsgId = current->data(RosterListItemDataAtMsgId).toString();
		emit showAtInfoBlock(conversationId, strMsgId);
	}


	emit conversationActived(conversationId);
}


void ConversationListWidget::itemClicked(QListWidgetItem * current)
{

	if (NULL == current)
		return;
	QString conversationId = current->data(RosterListItemDataConversationId).toString();
	if (conversationId.isEmpty())
	{
		Log::e("RosterListView::itemClicked isempty");
		return;
	}

	do 
	{
		if (current->data(RosterListItemDataConversationTypeGroup).toBool())
		{
			emit conversationActived(conversationId);	
			emit conversationClicked(conversationId);
			break;
		}

		if (current->data(RosterListItemDataConversationTypeChat).toBool())
		{
			emit conversationActived(conversationId);
			emit conversationClicked(conversationId);

			break;
		}

		if (current->data(RosterListItemDataConversationTypeRobot).toBool() || 
			current->data(RosterListItemDataConversationTypeNews).toBool())
		{
			if (Biz::MessageUtil::compareJid(conversationId, Util::QIANGDAN_DIALOG_ID))
			{
				Biz::Session::getConverSationManager()->sgShowEmpty(conversationId);
			}
			else if (Biz::MessageUtil::compareJid(conversationId, Util::COLLECTION_DIALOG_ID))
			{
				Biz::Session::getConverSationManager()->sgShowEmpty(conversationId);
			}
			else
			{
				Biz::Session::getConverSationManager()->setLocalCoversationMessageRead(conversationId);
				emit conversationActived(conversationId);
				emit conversationClicked(conversationId);
			}
			break;
		}

		if (current->data(RosterListItemDataConversationTypeLinked).toBool())
		{
			emit extendListActived(conversationId);
			break;
		}
	} while (false);


}
void ConversationListWidget::updateNoticeTip( const QString& jid, int noticetip )
{
	if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(jid);
		pItem->setNoticeTip(noticetip);
	}
}

int ConversationListWidget::getunReadCount( const QString& strjid )
{
	int nunReadcount = 0;
	if (mConversationId2Item.contains(strjid) && NULL!=mConversationId2Item.value(strjid))
	{
		QListWidgetItemSortable* pItem = mConversationId2Item.value(strjid);
		nunReadcount = pItem->unreadCount();
	}
	return nunReadcount;
}

void ConversationListWidget::updateChatContent(const QString&jid, const QString&content)
{
	if (mConversationId2Item.contains(jid) && NULL!=mConversationId2Item.value(jid))
	{
		mConversationId2Item.value(jid)->setDescription(content);
	}
}



QStringList ConversationListWidget::gethasConversationId()
{
	QStringList ids = mConversationId2Item.keys();
	QStringList simplechatids;
	for (QString strid: ids)
	{
		//if (!Biz::MessageUtil::isGroupJid(strid))
		{
			simplechatids.push_back(strid);
		}
	}
	return simplechatids;
}

QString ConversationListWidget::getConsultVirtualJid(const QString& conversationId)
{
	if (!isConsultChatItem(conversationId))
		return "";

	if (mConversationId2Item.contains(conversationId))
	{
		ConsultChatItem* pItem = dynamic_cast<ConsultChatItem*> (mConversationId2Item.value(conversationId));
		if (NULL!=pItem)
		{
			return pItem->getvirtualAccount();
		}
	}
	return "";
}

QString ConversationListWidget::getConsultRealJid(const QString& conversationId)
{
	if (!isConsultChatItem(conversationId))
		return "";

	if (mConversationId2Item.contains(conversationId))
	{
		ConsultChatItem* pItem = dynamic_cast<ConsultChatItem*> (mConversationId2Item.value(conversationId));
		if (NULL!=pItem)
		{
			return pItem->getRealJid();
		}
	}
	return "";
}

bool ConversationListWidget::getConsultIsSeatFlag(const QString& conversationId)
{
	if (!isConsultChatItem(conversationId))
		return false;

	if (mConversationId2Item.contains(conversationId))
	{
		ConsultChatItem* pItem = dynamic_cast<ConsultChatItem*> (mConversationId2Item.value(conversationId));
		if (NULL!=pItem)
		{
			return pItem->getIsSeat();
		}
	}
	return false;
}
