#include "collectionitem.h"
#include "XmppMessage.h"
#include "colorset.h"

const int AVATER_HEIGHT = 34;
const int AVATER_WIDTH = 34;

CollectionItem::CollectionItem(const QString& userid, const QString&dispname)
{
	setData(Biz::MessageUtil::makeSureUserJid(userid), CollectionItem::UserID);
	
	
	setData(dispname, CollectionItem::BindUserDisplayName);

	
	setCollectionItemType(CollectionBindUser);
}

CollectionItem::CollectionItem( const QString& userid, const QString&displayname, const QString& chatTime )
{
	setData(Biz::MessageUtil::makeSureUserJid(userid), CollectionItem::UserID);


	setData(displayname, CollectionItem::BindItemDisplayName);

	setCollectionItemType(CollectionBindItem);
}



CollectionItem::CollectionItem()
{

}

CollectionItem::~CollectionItem()
{

}





void CollectionItem::setCollectionItemType( int type )
{

	setData(type, CollectionBindType);
	
}
void CollectionItem::setAvatar(const QImage& image)
{
	setData(QVariant(image),CollectionItem::Avatar);
}

void CollectionItem::setBindUserUnReadCount( int ncount )
{
	setData(ncount, CollectionItem::UnreadUserCount);
}

void CollectionItem::setBindUserItemUnReadCount( int ncount )
{
	setData(ncount, CollectionItem::UnreadItemCount);
}

void CollectionItem::setBindUserDisplay( const QString& displayname )
{
	setData(displayname, CollectionItem::BindUserDisplayName);
}

void CollectionItem::setBindUserItemDisplay( const QString& displayname )
{
	setData(displayname, CollectionItem::BindItemDisplayName);
}

////////////////////////////CollectionItemDelegate
CollectionItemDelegate::CollectionItemDelegate()
{

}


QSize CollectionItemDelegate::sizeHint( const QStyleOptionViewItem& option, const QModelIndex& index ) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);

// 	int block = index.data(rosterItem::IsBlock).toInt();
// 	if (block!=0)
// 	{
// 		return QSize(0,0);
// 	}
	return QSize(40, 40);
}

void CollectionItemDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const
{
	


	painter->save();
	painter->setRenderHint(QPainter::TextAntialiasing);

	QColor selectedBg(ColorSetSingleton::getInstance()->recent_item_bk_checked());
	QColor normalBg(ColorSetSingleton::getInstance()->transparent());
	QColor selectedText(ColorSetSingleton::getInstance()->recent_item_title_checked());
	QColor nameTextColor(ColorSetSingleton::getInstance()->recent_item_title_normal());
	QColor frameColor(150,150,150);

	QRect rect = option.rect;
	QPen penDivision;

	//是否选择
	if (option.state & QStyle::State_Selected)
	{
		painter->fillRect(option.rect, selectedBg);
		//            painter->fillRect(option.rect, option.palette.highlight());
		//            penDivision.setColor(option.palette.highlight().color());
		penDivision.setColor(selectedBg);
		nameTextColor = selectedText;
		//statusTextColor = selectedText;
	}
	else
	{
		painter->fillRect(option.rect, normalBg);
	}
	QPixmap pixmap;
	QFont font;
	font.setPixelSize(12);
	QFont timefont;
	timefont.setPixelSize(11);



	QVariant value = index.data(Qt::DecorationRole);
	{
		//头像
		value = index.data(CollectionItem::Avatar);
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
			painter->setPen(frameColor);
		}
	}

// 	{
// 		//名字
// 		rect = option.rect;
// 		rect.moveTop(rect.y() + 8);
// 		rect.setLeft(option.rect.x() + 8 + AVATER_WIDTH + 10);
// 		painter->setFont(font);
// 		painter->setPen(nameTextColor);
// 
// 		QString nameText = index.model()->data(index, CollectionItem::DisplayName).toString();
// 		if(nameText == "ac0323654993456a9dd8c8fbe2422ab8" 
// 			|| nameText == "bc1a2d45b4dc422abd6f864201a4d1eb")
// 		{
// 			int a = 0;
// 			a = 10;
// 		}
// 		QFontMetrics fontMetrics(font);
// 		nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
// 		painter->drawText(rect, nameText);
// 
// 	}

	//名字
	rect = option.rect;
	rect.moveTop(rect.y() + 8);
	/*rect.setLeft(option.rect.x() + 10+16);*/
	painter->setFont(font);
	painter->setPen(nameTextColor);

	QString nameText = "";
	QString testdisplay = index.model()->data(index, CollectionItem::BindUserDisplayName).toString();
	if(!index.data(CollectionItem::BindUserDisplayName).toString().isEmpty())
	{
		nameText = index.data(CollectionItem::BindUserDisplayName).toString();
		QString xiaoxiestr = nameText.toLower();
		
		rect = option.rect;
		rect.moveTop(rect.y() + 8);
		rect.setLeft(option.rect.x() + 8 + AVATER_WIDTH + 10);
		

	/*	nameText = nameText.left(nameText.indexOf("\n"));*/
		QFontMetrics fontMetrics(font);
		nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
		painter->drawText(rect, nameText);

		//未读数的展示
		int nunRead = index.data(CollectionItem::UnreadUserCount).toInt();
		if (nunRead >0)
		{
			QRect unReadRect = option.rect;
			unReadRect.setLeft(unReadRect.right() - 40);
			unReadRect.moveTop(unReadRect.y() + 8);
			unReadRect.setWidth(17);
			unReadRect.setHeight(17);
			painter->drawPixmap(unReadRect, QPixmap(":/Images/tipsIcon.png"));
// 			painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
// 			painter->drawRoundRect(unReadRect, 75, 75);
			painter->setPen(QPen(Qt::white, Qt::DashLine));
			painter->drawText(unReadRect,  Qt::AlignCenter|Qt::AlignHCenter, QString::number(nunRead));
		}
		

		return;

	}
	else if(!index.data(CollectionItem::BindItemDisplayName).toString().isEmpty())
		nameText = index.data(CollectionItem::BindItemDisplayName).toString();
	else
		nameText = index.data(CollectionItem::UserID).toString();

	if(nameText == "ac0323654993456a9dd8c8fbe2422ab8" 
		|| nameText == "bc1a2d45b4dc422abd6f864201a4d1eb")
	{
		int a = 0;
		a = 10;
	}

	rect.setLeft(option.rect.x() + 8 + AVATER_WIDTH + 10);
	nameText = nameText.left(nameText.indexOf("\n"));
	QFontMetrics fontMetrics(font);
	nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
	painter->drawText(rect, nameText);

	//未读数的展示
	int nunRead = index.data(CollectionItem::UnreadItemCount).toInt();
	if(nunRead >0)
	{
		QRect unReadRect = option.rect;
		
		unReadRect.setLeft(unReadRect.right() - 40);
		unReadRect.moveTop(unReadRect.y() + 8);
		unReadRect.setWidth(17);
		unReadRect.setHeight(17);

		painter->drawPixmap(unReadRect, QPixmap(":/Images/tipsIcon.png"));
		painter->setPen(QPen(Qt::white, Qt::DashLine));
		painter->drawText(unReadRect, Qt::AlignCenter|Qt::AlignHCenter,QString::number(nunRead));
	}
	


}
