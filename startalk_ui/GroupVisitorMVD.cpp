#include "GroupVisitorMVD.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include <ConfigureHelper.h>
#include <QDateTime>
#include <QPainter>
#include "UiHelper.h"
#include "SpellHelper.h"
#include "portraithelper.h"
#include "gloableeventobject.h"

GroupVisitorModel::GroupVisitorModel(QObject *parent)
    : QStandardItemModel(parent)
{
}

GroupVisitorModel::~GroupVisitorModel()
{

}

VisitorItem* GroupVisitorModel::getItemFromBareJid(const QString& bareJid)
{
	Q_ASSERT(bareJid.contains("@") || bareJid=="blank");
	if (!bareJid.contains("@") && bareJid!="blank")
	{
		int a = 10;
		a = 20;
	}
	QModelIndexList indexes = match(index(0, 0, QModelIndex()), VisitorItem::UserJid, bareJid, -1, Qt::MatchFlag::MatchExactly);
	if (indexes.size()==1)
	{
		VisitorItem* p =  dynamic_cast<VisitorItem*>(itemFromIndex(indexes.at(0)));       
		return p;
	}
	return NULL;
}

void GroupVisitorModel::updatePresence(const QString& jid, VisitorItem::Status status)
{    
    if (NULL != getItemFromBareJid(jid))
    {
        getItemFromBareJid(jid)->setPresence(status);
    }
}
VisitorItem::Status GroupVisitorModel::getStatus(const QString& jid)
{    
    if (NULL != getItemFromBareJid(jid))
    {
        return getItemFromBareJid(jid)->getStatus();
    }
    return VisitorItem::NONE;
}
void GroupVisitorModel::createItem(const QString& jid, int aff, const QString& gpName, VisitorItem::Status status)
{
    Log::assert(!jid.isEmpty());
	
    if(NULL==getItemFromBareJid(jid)) {
	
        VisitorItem* item = new VisitorItem(jid, gpName, false, aff);      
        item->setPresence(status);
       appendRow(item);
    }
}
void GroupVisitorModel::removeItem(const QString& jid)
{
    QModelIndexList indexes = match(index(0, 0, QModelIndex()), VisitorItem::UserJid, jid, -1, Qt::MatchFlag::MatchExactly);
    for (int i = 0; i < indexes.size(); ++i)
    {
        VisitorItem* p =  (VisitorItem*)itemFromIndex(indexes.at(i));        
        if(p)
            removeRow(p->row());
    }


}
QMap<QString, VisitorItem*> GroupVisitorModel::GetGroupItemMap()
{
	QMap<QString,VisitorItem*> retMap;

	for (int i=0; i<rowCount(); i++)
	{
		VisitorItem* p =  dynamic_cast<VisitorItem*>(item(i));
		QString jid = p->MemberJid();
		if (NULL!=p && !retMap.contains(p->MemberJid()))
		{
			retMap.insert(p->MemberJid(),p);
		}
	}
    return retMap;
}

void GroupVisitorModel::updateAffic(const QString& jid, int aff)
{
	VisitorItem* pItem = getItemFromBareJid(jid);
    if(NULL!=pItem)
    {
        int nAffic = pItem->data(VisitorItem::UserAffiliationType).toInt();
        if (nAffic != aff)
        {
            pItem->setData(aff, VisitorItem::UserAffiliationType);
        }
    }
}
int GroupVisitorModel::GetCountItem()
{
    return rowCount();
}
void GroupVisitorModel::wheelMove()
{
}

void GroupVisitorModel::updateData(const QString& jid)
{
    if (NULL != getItemFromBareJid(jid))
    {
        getItemFromBareJid(jid)->updateData(jid);
    }
}

int GroupVisitorModel::getOnlineMemberCount()
{
    QModelIndexList indexes = match(index(0, 0, QModelIndex()), VisitorItem::Presence, VisitorItem::ONLINE, -1, Qt::MatchFlag::MatchExactly);
    int count = indexes.length();
    return count;
}



void GroupVisitorModel::updateDisplayName( const QString& userid , const QString& displayname)
{
	if (NULL != getItemFromBareJid(userid))
	{
		getItemFromBareJid(userid)->setDisplayname(displayname);
	}
}

void GroupVisitorModel::setItemFontSize( int nsize )
{
	for (VisitorItem* item:GetGroupItemMap().values())
	{
		if (item)
		{
			item->setFontSize(nsize);
		}
	}
}

// MID Item ////////////////////////////////////////////////////////////////////////
VisitorItem::VisitorItem(const QString& jid, const QString& gpName, bool autoJoin, int ntype)
{
    setData(jid, VisitorItem::UserJid);
	setDisplayname(gpName.isEmpty()? Biz::Session::currentAccount().getUserNameById(jid):gpName);
    setData(Status::OFFLINE, VisitorItem::Presence);
    setData(ntype, VisitorItem::UserAffiliationType);

	// 逃逸一下jid的domain，看看是否是本域的人
#ifndef QCHAT
	if (Biz::MessageUtil::compareJid(jid,Biz::MessageUtil::makeSureUserId(jid)))
	{
		setEmailAddress(Biz::MessageUtil::makeSureUserId(jid) +"@qunar.com");
	}
#endif // !QCHAT
	setData(12, VisitorItem::GroupFontSize);

}

VisitorItem::~VisitorItem()
{
}

void VisitorItem::setPresence(Status status)
{
    setData(status, VisitorItem::Presence);
}
VisitorItem::Status VisitorItem::getStatus()
{
    return (VisitorItem::Status)(this->data(VisitorItem::Presence).toInt()); 
}


void VisitorItem::updateData(const QString& jid)
{
    Q_UNUSED(jid);
    setData(QDateTime::currentMSecsSinceEpoch(),VisitorItem::REPAINT);
}

void VisitorItem::setMemberJid(const QString& memberJid)
{
    setData(memberJid,VisitorItem::UserJid);
}
QString VisitorItem::MemberJid(){
	return data(VisitorItem::UserJid).toString();
}

void VisitorItem::setDisplayname( const QString& dislayname )
{
	setText(dislayname);
	QString strPY = Biz::SpellHelper::MakeSpellCode(dislayname,( Biz::SpellHelper::SpellOptions)0);
	setData(strPY, VisitorItem::NickNamePY);
	setToolTip(dislayname);
}

void VisitorItem::setEmailAddress(const QString& email)
{
	setData(email,VisitorItem::Email);
}

QString VisitorItem::emailAddress()
{
	return data(VisitorItem::Email).toString();
}

QString VisitorItem::nickName()
{
	return text();
}



void VisitorItem::setFontSize( int nsize )
{
	setData(nsize, VisitorItem::GroupFontSize);
}




//////////////////////////////////////////////////////////////////////////
VisitorItemDelegate::VisitorItemDelegate() : AVATER_HEIGHT(20),AVATER_WIDTH(20),JOINPIC_SIZE(14)
{
}

QSize VisitorItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(148, 28);
}

void VisitorItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing);

    QColor selectedBg(223, 223, 223);
    QColor alternateBg(239, 245, 254);
    QColor selectedText(51, 51, 51);
    QColor nameTextColor(51, 51, 51);
    QColor statusTextColor(102, 102, 102);
    QColor timeColor(102, 102, 102);
    QColor unreadColor(Qt::GlobalColor::white);
    QColor frameColor(150,150,150);

    QRect rect = option.rect;
    QPen penDivision;

    //是否选择
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, selectedBg);
        penDivision.setColor(selectedBg);
    }
    else
    {
        penDivision.setColor(QColor(215, 216, 217));
    }

    QVariant value = index.data(Qt::DecorationRole);

    {
        //头像
        QString userid = index.data(VisitorItem::UserJid).toString();

        int userpresence = index.data(VisitorItem::Presence).toInt();
        if (VisitorItem::Status::ONLINE == userpresence)
        {
            QImage image = Biz::PortraitHelper::getUserPortraitImage(userid);
            if(!image.isNull()){
                rect = option.rect;
                rect.setWidth(AVATER_WIDTH);
                rect.setHeight(AVATER_HEIGHT);
                rect.moveTop(rect.y() + (option.rect.height() - AVATER_HEIGHT)/2);
                rect.moveLeft(option.rect.x() + 12 + 16 );
                painter->drawImage(rect, image);
            }
        }
        else 
        {
            QImage image = Biz::PortraitHelper::getUserPortraitGrayImage(userid);
            if(!image.isNull()){
                rect = option.rect;
                rect.setWidth(AVATER_WIDTH);
                rect.setHeight(AVATER_HEIGHT);
                rect.moveTop(rect.y() + (option.rect.height() - AVATER_HEIGHT)/2);
                rect.moveLeft(option.rect.x() + 12 + 16 );
                painter->drawImage(rect, image);
            }
        }
        
    }

    //加所属关系的图标(所属关系有所有者，管理员，成员)
    QVariant Uservalue = index.data(Qt::UserRole);
    {
        int userAffType = index.data(VisitorItem::UserAffiliationType).toInt();
        QImage image;
        if (QXmppMucItem::OwnerAffiliation == userAffType)
        {
            image = QImage(":/Images/groupCreator.png");
        } else if (QXmppMucItem::AdminAffiliation == userAffType)
        {
            image = QImage(":/Images/groupAdmin.png");
        }

        if (!image.isNull())
        {
            rect = option.rect;
            rect.setWidth(16);
            rect.setHeight(16);
            rect.moveTop(rect.y() + 4 + (option.rect.height() - AVATER_HEIGHT)/2);
            rect.moveLeft(option.rect.x() +5 );
            QRect frameRect = rect;

            frameRect.moveLeft(rect.left()-(painter->pen().width()+1)/2);
            frameRect.moveTop(rect.top()-(painter->pen().width()+1)/2);
            frameRect.setWidth(rect.width() + painter->pen().width());
            frameRect.setHeight(rect.height() + painter->pen().width());

            painter->drawImage(rect, image);
            painter->setPen(frameColor);
        }
    }

    {
        //名字
		int nfontsize = index.model()->data(index, VisitorItem::GroupFontSize).toInt();
		if (nfontsize < 12)
		{
			nfontsize = 12;
		}
		else if (nfontsize > 20)
		{
			nfontsize = 20;
		}
		
        QFont font;
        font.setPixelSize(nfontsize);

        rect = option.rect;
        rect.moveTop(rect.y() + 5);
        rect.setLeft(option.rect.x() + 12+ AVATER_WIDTH + 10  + 16);
        painter->setFont(font);
        painter->setPen(nameTextColor);

        QString nameText = index.model()->data(index, Qt::DisplayRole).toString();
        QFontMetrics fontMetrics(font);
        nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 8);
        painter->drawText(rect, nameText);

        static QSet<QString> nameset;
        if (!nameset.contains(nameText))
        {
            nameset.insert(nameText);
        }
    }
    painter->restore();
}
