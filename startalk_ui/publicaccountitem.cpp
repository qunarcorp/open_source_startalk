#include "publicaccountitem.h"
#include "Session.h"
#include "portraithelper.h"
#include <QPainter>
#include "portraithelper.h"
#include "colorset.h"
#include "../LocalManBiz/SpellHelper.h"

const int AVATER_HEIGHT = 34;
const int AVATER_WIDTH = 34;
const int JOINPIC_SIZE = 17;

PublicAccountItem::PublicAccountItem( const QString&id, const QString& name )
{
	setData(id, PublicAccountItem::PublicAccountid);
	setText(name);
	setData(Biz::PortraitHelper::getUserProtraitByDefault(id,Biz::DEFAULT_PATH_ROBOT).toImage(), PublicAccountItem::Avatar);
	QString strPY = Biz::SpellHelper::MakeSpellCode(name,( Biz::SpellHelper::SpellOptions)0);
	setData(strPY, PublicAccountItem::PulicAccountPY);
}

PublicAccountItem::~PublicAccountItem()
{

}

QString PublicAccountItem::getPublicAccountItemid()
{
	return data(PublicAccountItem::PublicAccountid).toString();
}

void PublicAccountItem::setPublicAccountName( const QString& pName )
{
	setText(pName);
}

////////////////////////PublicAccountItemDelegate

PublicAccountItemDelegate::PublicAccountItemDelegate()
{

}

QSize PublicAccountItemDelegate::sizeHint( const QStyleOptionViewItem& option, const QModelIndex& index ) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);
	return QSize(44, 60);
}

void PublicAccountItemDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const
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
		value = index.data(PublicAccountItem::Avatar);
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

	{
		//名字
		rect = option.rect;
		rect.moveTop(rect.y() + 18);
		rect.setLeft(option.rect.x() + 8 + AVATER_WIDTH + 10);
		painter->setFont(font);
		painter->setPen(nameTextColor);

		QString nameText = index.model()->data(index, Qt::DisplayRole).toString();
		QFontMetrics fontMetrics(font);
		nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 30);
		painter->drawText(rect, nameText);

	}
	
	painter->restore();
}
