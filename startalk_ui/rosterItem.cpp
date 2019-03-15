#include "rosterItem.h"
#include <QImage>
#include <QApplication>
#include "LanguageHelper.h"
#include "XmppMessage.h"

#include "colorset.h"


const int AVATER_HEIGHT = 20;
const int AVATER_WIDTH = 20;

rosterItem::rosterItem(const QString& groupName,const QString& gfullName)
{
    setData(groupName, rosterItem::GroupDisplayName);
    setData(gfullName, rosterItem::GroupFullName);
}
rosterItem::rosterItem(const QString& userID, const QString& lastMsg, const QString& chatTime)
{
    setData(Biz::MessageUtil::makeSureUserJid(userID), rosterItem::UserID);
    setData(lastMsg, rosterItem::StatusText);
    setData(QDateTime::fromString(chatTime, "yyyy-MM-dd hh:mm:ss"), rosterItem::LastMessageTime);
    setData(QVariant(0), rosterItem::UnreadCount);
    setData(static_cast<int>(PresenceStatus::OFFLINE), PresenceType);   
    setData(QDateTime::fromMSecsSinceEpoch(0), rosterItem::LastTimeDrawTime);
    setData("", rosterItem::LastTimeDrawResult);
    setData(QVariant(0), rosterItem::EntryOnlineCount);
    setData(QVariant(0), rosterItem::EntryCount);
}

void rosterItem::setUserId(const QString& uid)
{
    setData(uid, rosterItem::UserID);
}
void rosterItem::setDisplayName(const QString& dispName)
{
    setData(dispName, rosterItem::DisplayName);
}
void rosterItem::setDisplayPY(const QString& dispName)
{
    setData(dispName, rosterItem::DisplayName_PINYIN);
}

QString rosterItem::getDisplayName()
{
    return this->data(rosterItem::DisplayName).toString();  
}
QString rosterItem::getUserId()
{
    return this->data(rosterItem::UserID).toString();  
}

QString rosterItem::getGroup(){
    return this->data(rosterItem::GroupDisplayName).toString();  
}

void rosterItem::setGroupName(const QString& gpName){
    setData(gpName, rosterItem::GroupDisplayName);
}
void rosterItem::setIsGroup(int i)
{
    setData(i, rosterItem::IsGroup);
}


void rosterItem::setIsBlock(int i)
{
    setData(i, rosterItem::IsBlock);
}


void rosterItem::setAvatar(const QImage& image)
{
    if (!image.isNull())
    {
        setData(QVariant(image), rosterItem::Avatar);
    }
}

QImage rosterItem::getAvatar()
{
    return qvariant_cast<QImage>(data(rosterItem::Avatar));
}

void rosterItem::setUnreadCount( int count )
{
    setData(QVariant(count), rosterItem::UnreadCount);
    emit sgUnreadCountChanged();
}

int rosterItem::getUnreadCount()
{
    return this->data(rosterItem::UnreadCount).toInt();    
}
int rosterItem::getPresence()
{
    return this->data(rosterItem::PresenceType).toInt();   
}
void rosterItem::setPresencce(PresenceStatus::AvailableStatusType status)
{
    setData(static_cast<int>(status), PresenceType);        
}
void rosterItem::setEntryCount(int count)
{
    setData(QVariant(count), rosterItem::EntryCount);
}
int rosterItem::getEntryCount()
{
    return this->data(rosterItem::EntryCount).toInt(); 
}
void rosterItem::setEntryOnlineCount(int count)
{
    setData(QVariant(count), rosterItem::EntryOnlineCount);
}
int rosterItem::getEntryOnlineCount()
{
    return this->data(rosterItem::EntryOnlineCount).toInt(); 

}

int rosterItem::isGroupItem()
{
    return this->data(rosterItem::IsGroup).toInt() != 0;
}



//////////////////////////////////////////////////////////////////////////

rosterItemDelegate::rosterItemDelegate()
{
}

QSize rosterItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    int block = index.data(rosterItem::IsBlock).toInt();
    if (block!=0)
    {
        return QSize(0,0);
    }
    return QSize(44, 30);
}

void rosterItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    int block = index.data(rosterItem::IsBlock).toInt();
    if (block!=0)
    {
        return;
    }


    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing);

    QColor selectedBg(ColorSetSingleton::getInstance()->recent_item_bk_checked());
    QColor nameTextColor(ColorSetSingleton::getInstance()->recent_item_title_checked());
    QColor statusTextColor(102, 102, 102);

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
    QPixmap pixmap;
    QFont font;
    font.setPixelSize(12);
    QFont timefont;
    timefont.setPixelSize(11);

    QVariant value = index.data(Qt::DecorationRole);
    {
        int isGroup = index.data(rosterItem::IsGroup).toInt();
        if (isGroup==0)
        {
            // 在线状态圆点
            QColor onlinecole;

            QVariant statusValue = index.data(rosterItem::PresenceType);
            int status = qvariant_cast<int>(statusValue);
            if( status == PresenceStatus::ONLINE){
                onlinecole = QColor(0,255,0);
            }else{
                onlinecole = QColor(128,128,128);
            }

            // 画个圈
            QRect frameRect(rect.left()+10,rect.top()+9,12,12);
            QPen pen(onlinecole, 2);
            painter->setPen(pen);
            painter->setBrush(Qt::NoBrush);
            painter->drawEllipse(frameRect);

            QRect soildRect(frameRect.left()+2,frameRect.top()+2,7,7);
            painter->setPen(QPen(onlinecole,1));
            painter->setBrush(QBrush(onlinecole,Qt::SolidPattern));
            painter->drawEllipse(soildRect);
        }
    }
  
    {
        //名字
        rect = option.rect;
        rect.moveTop(rect.y() + 7);
        rect.setLeft(option.rect.x() + 10+16);
        painter->setFont(font);
        painter->setPen(nameTextColor);

        QString nameText = "";
        if(!index.data(rosterItem::GroupDisplayName).toString().isEmpty())
        {
            nameText = index.data(rosterItem::GroupDisplayName).toString();
			QString xiaoxiestr = nameText.toLower();
			if (nameText == "PMO")
			{
				int a = 9;
			}
            rect.setLeft(option.rect.x() + 7);

            nameText = nameText.left(nameText.indexOf("\n"));
            QFontMetrics fontMetrics(font);
            nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
            painter->drawText(rect, nameText);

            // 话在线人数
            QString info = QStringLiteral("(%1/%2)").arg(index.data(rosterItem::EntryOnlineCount).toInt()).arg(index.data(rosterItem::EntryCount).toInt());
            QRect infoRect = option.rect;
            infoRect.moveTop(option.rect.y() + 7);
			int nwidthfontMetrics = fontMetrics.width(xiaoxiestr);
			int nupperfontMetrics = fontMetrics.width(nameText);
            infoRect.setLeft(option.rect.x() + 7 + fontMetrics.width(xiaoxiestr) + 10 );
            QFontMetrics infofontMetrics(font);
			int nwidth = infoRect.width();
            info = infofontMetrics.elidedText(info, Qt::ElideRight, infoRect.width());
            
            painter->setPen(statusTextColor);
            painter->drawText(infoRect,info);

            return;

        }
        else if(!index.data(rosterItem::DisplayName).toString().isEmpty())
            nameText = index.data(rosterItem::DisplayName).toString();
        else
            nameText = index.data(rosterItem::UserID).toString();

        nameText = nameText.left(nameText.indexOf("\n"));
        QFontMetrics fontMetrics(font);
        nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
        painter->drawText(rect, nameText);

    }
    
}


