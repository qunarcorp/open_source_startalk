#include "RosterTreeItemModel.h"
#include "rosterItem.h"
#include "CallbackReceiver.h"
#include "RosterList.h"
#include "SpellHelper.h"
#include "PresenceStatus.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "qimagereader.h"
#include "UserVcardManager.h"
#include "UIFrame.h"
#include "ConversationController.h"

using namespace Biz;
RosterTreeItemModel::RosterTreeItemModel(QObject *parent)
    : QStandardItemModel(parent)
{
    mReceiver = new Biz::CallbackReceiver(this);
}

RosterTreeItemModel::~RosterTreeItemModel()
{

}

rosterItem* RosterTreeItemModel::getRosterItemFromBareJid(const QString& bareJid)
{
    if(m_jidRosterItemMap.contains(bareJid))
        return m_jidRosterItemMap[bareJid];
    else
        return 0;
}

QStandardItem* RosterTreeItemModel::initRosterTree()
{
	QString groupName = Biz::Session::currentAccount().getRootRosterGroup()->name;
	QString groupFullName = groupName + "/";
	rosterItem* newGroup = new rosterItem(groupName,groupFullName);
	newGroup->setIsGroup(1);
    QList<RosterNode*> nodelst = Biz::Session::currentAccount().getRootRosterGroup()->getRosterListWithChildren();
    int onlinecount = 0;
    for (RosterNode* node:nodelst)
    {
        if (node->status==6)
        {
            onlinecount++;
        }
    }
    newGroup->setEntryCount(nodelst.size());
    newGroup->setEntryOnlineCount(onlinecount);
	m_GroupRosterItemMap[groupFullName] = newGroup;
    
    this->appendRow(newGroup);

    rosterItem* defaultitem = new rosterItem("","");
    defaultitem->setIsBlock(1);
    newGroup->appendRow(defaultitem);
    return newGroup;
}


void RosterTreeItemModel::onUpdatePresence(const QStringList& onlineUsers)
{
    QMap<QString,rosterItem*>::iterator iter = m_jidRosterItemMap.begin();
    for (;iter!=m_jidRosterItemMap.end();iter++)
    {
        QString userid = Biz::MessageUtil::makeSureUserJid(iter.key());
        rosterItem* item = iter.value();
        if (onlineUsers.contains(userid))
        {
            item->setPresencce(PresenceStatus::ONLINE);
        }
        else
        {
            item->setPresencce(PresenceStatus::OFFLINE);
			//updateSubonline(userid);
        }

    }
}


void RosterTreeItemModel::updatevCard(const QString& bareJid, const QImage& img)
{    
}
void RosterTreeItemModel::searchRosterList(const QString& key, QStringList& resultList)
{
    QModelIndexList indexes = match(index(0, 0, QModelIndex()), rosterItem::DisplayName_PINYIN, key, -1, Qt::MatchFlag::MatchContains | Qt::MatchRecursive);
    for (int i = 0; i < indexes.size(); ++i)
    {
        rosterItem* p =  (rosterItem*)itemFromIndex(indexes.at(i));        
        if(p && p->getGroup().length() == 0)
            resultList.append(p->getDisplayName());
    }
}

QString RosterTreeItemModel::DisplayNameToUserId(const QString& displayName)
{
    return Biz::Session::currentAccount().getUserIDByName(displayName);
}

rosterItem* RosterTreeItemModel::getGroupItemByGn(const QString& groupname)
{
    if(m_GroupRosterItemMap.contains(groupname))
        return m_GroupRosterItemMap[groupname];
    else 
        return 0;
}

void RosterTreeItemModel::bindChild(const QString& groupname, rosterItem* parent)
{
    RosterGroup* rGroup = Biz::Session::currentAccount().findRosterGroup(groupname);
    if (NULL!=rGroup && NULL != parent)
    {
        // 加人员
        foreach(RosterNode* node,rGroup->rosterNodeList)
        {
            rosterItem* item = new rosterItem(node->userId, "","");                
            item->setDisplayName(node->displayName);
            item->setDisplayPY(node->namePinyin);
			//这个时候判断
			if (Biz::Session::getUserVcardManager()->isUserOnline(Biz::MessageUtil::makeSureUserJid(node->userId)))
			{
				item->setPresencce(PresenceStatus::ONLINE);
			}
            if (node->status==6)
            {
                item->setPresencce(PresenceStatus::ONLINE);
            }
            parent->appendRow(item);
            m_jidRosterItemMap[node->userId] = item;
        }

        // 加子群组
		QStringList askids;
        foreach(RosterGroup* group,rGroup->rosterGroupList)
        {
            QString fname = group->getFullName();
			QString groupname = group->name; 
            rosterItem* newGroup = new rosterItem(group->getShortName(),group->getFullName());
            newGroup->setIsGroup(1);
            QList<RosterNode*> nodelst = group->getRosterListWithChildren();
            int onlinecount = 0;
            for (RosterNode* node:nodelst)
            {
                if (node->status==6)
                {
                    onlinecount++;
                }
				//先屏蔽此功能，后续在研究方法加上
// 				if (onlineUserlist.contains(MessageUtil::makeSureUserJid(node->userId)))
// 				{
// 					onlinecount++;
// 				}
				//此处取问题中心的值
				//暂时让咨询回答问题的人存放起来，前面有特殊的用处
				if(groupname == QStringLiteral("QChat问题反馈中心"))
				{
					if (!askids.contains(node->userId))
					{
						askids.push_back(node->userId);
					}
				}		
            }
			if (askids.size() > 0)
			{
				MainApp::UIFrame::getConversationController()->setAskIds(askids);
			}
            newGroup->setEntryCount(nodelst.size());
            newGroup->setEntryOnlineCount(onlinecount);
            m_GroupRosterItemMap[group->getFullName()] = newGroup;
            parent->appendRow(newGroup);

            rosterItem* defaultitem = new rosterItem("","");
            defaultitem->setIsBlock(1);
            newGroup->appendRow(defaultitem);
        }
    }
}


void RosterTreeItemModel::updateSuoxie(const QVariantList& rosterNode)
{
	for(QVariant var : rosterNode)
	{
		QVariantMap itemMap = var.toMap();
		QString userName = itemMap["U"].toString();
		QString userNamertxpy = itemMap["FPY"].toString();
		QString userNamertxsx = itemMap["FSX"].toString();
		QString userNamehzpy = itemMap["SPY"].toString();
		QString userNamehzsx = itemMap["SSX"].toString();
	}
}

void RosterTreeItemModel::cleanData()
{
	m_GroupRosterItemMap.clear();
	m_jidRosterItemMap.clear();
}

void RosterTreeItemModel::updateSumonline( const QString& userid )
{
	if (onlineUserlist.contains(userid))
	{
		return;
	}
	
	onlineUserlist.append(userid);
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

		rosterItem* item = this->getGroupItemByGn(groupFullName);
		if (item != NULL)
		{

			item->setEntryOnlineCount(item->data(rosterItem::EntryOnlineCount).toInt() + 1);
			
		}

	}
}

void RosterTreeItemModel::ShowPresenceOnline( const QStringList& onlineUsers )
{
	//onlineUserlist中有的元素，而onlineUsers中没有的，就视为下线
	//那么对这些下线的人就要做相应的数字减少
	QStringList strSubUserlist;
	for (QString str: onlineUserlist)
	{
		if (onlineUsers.contains(str))
		{
			continue;
		}
		else
		{
			strSubUserlist.append(str);
		}
	}

	for (QString str: onlineUsers)
	{
		updateSumonline(str);
	}
	
	for (QString str: strSubUserlist)
	{
		updateSubonline(str);
	}
}

void RosterTreeItemModel::updateSubonline( const QString& userid )
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

		rosterItem* item = this->getGroupItemByGn(groupFullName);
		if (item != NULL)
		{

			item->setEntryOnlineCount(item->data(rosterItem::EntryOnlineCount).toInt() - 1);

		}

	}
}
