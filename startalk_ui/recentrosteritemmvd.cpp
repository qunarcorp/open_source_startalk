#include "recentrosteritemmvd.h"
#include <QVariant>
#include <QPainter>
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "UserVcardManager.h"

// QWidget * RecentRosterItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
// {
//     RecentItemView* widget = new RecentItemView(parent);
//     widget->setMinimumWidth(100);
//     widget->setMaximumWidth(100);
//     return widget;
// }
// 
// void RecentRosterItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
// {
//     QString dispalyname  = index.model()->data(index, RecentRosterItem::DispalyName).toString();  
//     RecentItemView *view = static_cast<RecentItemView*>(editor);  
//     view->setDisplayName(dispalyname); 
// }

RecentRosterItemDelegate::RecentRosterItemDelegate(): AVATER_HEIGHT(32),AVATER_WIDTH(32)
{

}

QSize RecentRosterItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
   return QSize(100,40);
}

void RecentRosterItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing);

    QColor selectedBg(0x00, 0x7A, 0xCC);
    QColor alternateBg(239, 245, 254);
    QColor selectedText(51, 51, 51);
    QColor nameTextColor(51, 51, 51);
    QColor statusTextColor(102, 102, 102);
    QColor timeColor(102, 102, 102);
    QColor unreadColor(Qt::GlobalColor::white);
    QColor unreadbackcolor(0xF3,0x8B,0x76);
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

    //     {
    //         //分割线
    //         rect = option.rect;
    //         QPoint left = rect.bottomLeft();
    //         //left.setX(left.x() + 4);
    //         QPoint right = rect.bottomRight();
    //         //right.setX(right.x() - 4);
    //         penDivision.setWidth(1);
    //         painter->setPen(penDivision);
    //         painter->drawLine(left, right);
    // 
    //     }


    QVariant value = index.data(Qt::DecorationRole);
    {
        //头像
        value = index.data(RecentRosterItem::Avatar);
        QImage image;
        if(value.type() == QVariant::Image)
        {
            image = qvariant_cast<QImage>(value);
        }

        if(!image.isNull()){
            rect = option.rect;
            rect.setWidth(AVATER_WIDTH);
            rect.setHeight(AVATER_HEIGHT);
            rect.moveTop(rect.y() + (option.rect.height() - AVATER_HEIGHT)/2);
            rect.moveLeft(option.rect.x() + 8);
            painter->drawImage(rect, image);
        }
    }


    {
        //名字
        QFont font;
        font.setPixelSize(12);

        rect = option.rect;
        rect.moveTop(rect.y() + 13);
        rect.setLeft(option.rect.x() + 8 + AVATER_WIDTH + 10);
        painter->setFont(font);
        painter->setPen(nameTextColor);

        QString nameText = index.model()->data(index, RecentRosterItem::DispalyName).toString();
        QFontMetrics fontMetrics(font);
        nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 8);
        painter->drawText(rect, nameText);
    }

    {
        // 未读消息数
        int unreadcount = index.model()->data(index, RecentRosterItem::UnreadeCount).toInt();
        if(unreadcount > 99){
            unreadcount = 99;
        }

        if (!unreadcount == 0)
        {
            QFont font;
            font.setPixelSize(12);
            QString str = QString("%1").arg(unreadcount);
            QFontMetrics qfm(font);
            int strw = qfm.width(str);
            int strh = qfm.height();

            QRectF rectFrame = option.rect;
            rectFrame.moveTop(option.rect.y() + 11);
            rectFrame.setLeft(option.rect.x() +230);
            rectFrame.setHeight(strh);
            rectFrame.setWidth(strw+10);

            painter->setRenderHint(QPainter::Antialiasing,true);
            painter->setBrush(QBrush(unreadbackcolor));
            painter->setPen(unreadbackcolor);
            painter->drawRoundedRect(rectFrame, 5.0, 5.0);


            QRect textRect = option.rect;
            textRect.moveTop(option.rect.y() + 11);
            textRect.setLeft(option.rect.x() +235);

            painter->setBrush(Qt::NoBrush);
            painter->setFont(font);
            painter->setPen(unreadColor);
            painter->drawText(textRect,QString("%1").arg(unreadcount));
        }
    }
    painter->restore();
}

RecentRosterModel::RecentRosterModel(QObject *parent)
{

}

RecentRosterModel::~RecentRosterModel()
{

}

RecentRosterItem* RecentRosterModel::getItemFromUid(const QString& bareJid)
{
    return NULL;
}


void RecentRosterModel::createGroupItem(const QString& id, const QString& displayname, int viewid)
{
    if (!m_uidItemMap.contains(id))
    {
        RecentRosterItem* item = new RecentRosterItem(this);
        m_uidItemMap[id] = item;
        item->setViewId(viewid);
        item->setDispalyName(displayname);
        item->setUID(id);
        item->setIsGroupChat(true);

        Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(Biz::MessageUtil::makeSureUserJid(id)));
        appendRow(item);
    }
}

void RecentRosterModel::createItem(const QString& id, const QString& displayname, int viewid)
{
    if (!m_uidItemMap.contains(id))
    {
        RecentRosterItem* item = new RecentRosterItem(this);
        m_uidItemMap[id] = item;
        item->setViewId(viewid);
        item->setDispalyName(displayname);
        item->setUID(id);
        item->setIsGroupChat(false);

       Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(Biz::MessageUtil::makeSureUserJid(id)));

        appendRow(item);
    }
}

void RecentRosterModel::removeItem(const QString& id, const QString& displayname)
{
    if (m_uidItemMap.contains(id))
    {
        removeRow(m_uidItemMap.value(id)->row());
    }
}

void RecentRosterModel::updatevCard(const QString& id, const QImage& path)
{
    if (m_uidItemMap.contains(id))
    {
        RecentRosterItem* item = m_uidItemMap.value(id);
        item->setAvatar(path);
    }
}

void RecentRosterModel::updateUnReadCount(const QString&jid, int count)
{
    if (m_uidItemMap.contains(jid))
    {
        RecentRosterItem* item = m_uidItemMap.value(jid);
        item->setUnreadeCount(count);
    }
}




RecentRosterItem::RecentRosterItem(const QString& jid, const QString& gpName, bool autoJoin)
{

}

RecentRosterItem::RecentRosterItem(QObject* parentconst) : QObject(parentconst)
{

}

RecentRosterItem::~RecentRosterItem()
{

}

void RecentRosterItem::setAvatar(const QImage& image)
{
    setData(QVariant(image),RecentRosterItem::Avatar);
}
// 
void RecentRosterItem::setViewId(int viewid)
{
    setData(QVariant(viewid),RecentRosterItem::ViewID);
}
// 
void RecentRosterItem::setDispalyName(const QString& name)
{
    setData(QVariant(name),RecentRosterItem::DispalyName);
}

void RecentRosterItem::setUID(const QString& id)
{
    setData(QVariant(id),RecentRosterItem::UserID);
}

void RecentRosterItem::setIsGroupChat(bool b)
{
    setData(QVariant(b),RecentRosterItem::IsGroupChat);
}

void RecentRosterItem::setUnreadeCount(int count)
{
    setData(QVariant(count),RecentRosterItem::UnreadeCount);
}

