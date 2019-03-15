#include "RosterListItems.h"






QListWidgetItemSortable::QListWidgetItemSortable(QListWidget *view /*= 0*/, int type /*= Type*/) 
    : QListWidgetItem(view,type)
{
    setConversationId("");
    setTitle("");
    setDescription("");
    setUnreadCount(0);
    setTop(false);
    setAtType(0);
    setAtCount(0);
	setAtmsgId("");
}


bool QListWidgetItemSortable::operator<(const QListWidgetItem &other) const
{
    bool bSwap = true;

    QListWidgetItemSortable* pOther = dynamic_cast<QListWidgetItemSortable*>((QListWidgetItem*)&other);
    if (NULL == pOther)
    {
        return !bSwap;
    }

    QListWidgetItemSortable& otherS = (QListWidgetItemSortable&)other;

    // Check set top
    if (this->isTop() != otherS.isTop()) {
        return isTop()?bSwap:!bSwap;
    }

    // 最新的时间
    if (this->getLastTimeStamp() != otherS.getLastTimeStamp())
    {
        return (this->getLastTimeStamp() > otherS.getLastTimeStamp())?bSwap:!bSwap;
    } 

    // 其他的按照字典顺序排序
    QString thisName = title();
    QString otherName = otherS.title();

    if (!thisName.isEmpty() && !otherName.isEmpty())
    {
        return thisName.compare(otherName)<0 ? bSwap : !bSwap;
    }

    return !bSwap;
}

bool QListWidgetItemSortable::isLinkedItem()
{
    if (data(RosterListItemDataConversationTypeLinked).isValid())
    {
        return data(RosterListItemDataConversationTypeLinked).toBool();
    }
    return false;
}

bool QListWidgetItemSortable::isRawHtmlItem()
{
    if (data(RosterListItemDataConversationTypeRawHtml).isValid())
    {
        return data(RosterListItemDataConversationTypeRawHtml).toBool();
    }
    return false;
}

bool QListWidgetItemSortable::isRobotChatItem()
{
    if (data(RosterListItemDataConversationTypeRobot).isValid())
    {
        return data(RosterListItemDataConversationTypeRobot).toBool();
    }
    return false;
}

bool QListWidgetItemSortable::isNewsChatItem()
{
    if (data(RosterListItemDataConversationTypeNews).isValid())
    {
        return data(RosterListItemDataConversationTypeNews).toBool();
    }
    return false;
}

bool QListWidgetItemSortable::isGroupChatItem()
{
    if (data(RosterListItemDataConversationTypeGroup).isValid())
    {
        return data(RosterListItemDataConversationTypeGroup).toBool();
    }
    return false;
}

bool QListWidgetItemSortable::isConsultChatItem()
{
	if (data(RosterListItemDataConversationTypeConsult).isValid())
	{
		return data(RosterListItemDataConversationTypeConsult).toBool();
	}
	return false;
}

bool QListWidgetItemSortable::isSimpleChatItem()
{
    if (data(RosterListItemDataConversationTypeChat).isValid())
    {
        return data(RosterListItemDataConversationTypeChat).toBool();
    }
    return false;
}

void QListWidgetItemSortable::setTop(bool top)
{
    setData(RosterListItemDataIsTop,top);
}

bool QListWidgetItemSortable::isTop() const
{
    return data(RosterListItemDataIsTop).toBool();
}

qint64 QListWidgetItemSortable::getLastTimeStamp() const
{
    return data(RosterListItemDataLastTimeStamp).toLongLong();
}

void QListWidgetItemSortable::setLastTimeStamp(qint64 time)
{
    setData(RosterListItemDataLastTimeStamp,time);
}

void QListWidgetItemSortable::setConversationId(const QString& conversationId)
{
    setData(RosterListItemDataConversationId,conversationId);
}

QString QListWidgetItemSortable::conversationId()
{
    return data(RosterListItemDataConversationId).toString();
}

void QListWidgetItemSortable::setTitle(const QString& title)
{
    setData(RosterListItemDataTitle,title);
}


void QListWidgetItemSortable::setMarkTitle(const QString& marktitle)
{
    setData(RosterListItemDataMarkTitle,marktitle);
}


QString QListWidgetItemSortable::markTitle()
{
    return data(RosterListItemDataMarkTitle).toString();
}




void QListWidgetItemSortable::setStarPerson(int starperson)
{
	setData(RosterListItemDataStarPerson, starperson);
}

int QListWidgetItemSortable::getsetStarPerson()
{
	return data(RosterListItemDataStarPerson).toInt();
}

QString QListWidgetItemSortable::title() const 
{
    return data(RosterListItemDataTitle).toString();
}

void QListWidgetItemSortable::setDescription(const QString& desc)
{
    setData(RosterListItemDataDesc,desc);
}

QString QListWidgetItemSortable::description()
{
    return data(RosterListItemDataDesc).toString();
}

void QListWidgetItemSortable::setUnreadCount(int count)
{
    setData(RosterListItemDataUnreadCount,count);
}

int QListWidgetItemSortable::unreadCount()
{
    return data(RosterListItemDataUnreadCount).toInt();
}

void QListWidgetItemSortable::setAtType(int type)
{
    setData(RosterListItemDataAtFlag,type);
}

int QListWidgetItemSortable::atType()
{
    return data(RosterListItemDataAtFlag).toInt();
}

void QListWidgetItemSortable::setAtCount(int count)
{
    setData(RosterListItemDataAtCount,count);
}

int QListWidgetItemSortable::atCount()
{
    return data(RosterListItemDataAtCount).toInt();
}

void QListWidgetItemSortable::setUserImageChange(quint64 changeversion)
{
    setData(RosterListItemDataHeaderChange,changeversion);
}

void QListWidgetItemSortable::setNoticeTip( int noticetip )
{
	setData(RosterListItemDataNoticeTip, noticetip);
}

int QListWidgetItemSortable::getNoticeTip()
{
	return data(RosterListItemDataNoticeTip).toInt();
}

void LinkedItem::setLinkedKey(const QString& key)
{
    setData(RosterListItemDataLinkedId,key);
}

QString LinkedItem::linkedKey()
{
    return data(RosterListItemDataLinkedId).toString();
}

void QListWidgetItemSortable::setAtmsgId( const QString&msgid )
{
	setData(RosterListItemDataAtMsgId, msgid);
}

QString QListWidgetItemSortable::getAtmsgId()
{
	return data(RosterListItemDataAtMsgId).toString();
}