#include "subscriptionnumitem.h"
#include "../LocalManBiz/SpellHelper.h"
#include "portraithelper.h"

const int AVATER_HEIGHT = 34;
const int AVATER_WIDTH = 34;
const int JOINPIC_SIZE = 17;

SubscriptionNumItem::SubscriptionNumItem(const QString& jid, const QString& gpName, bool autoJoin)
{
	setData(jid, SubscriptionNumItem::SubcriptionNumJid);
	setText(gpName);
	setData(Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(getSubcriptionNumJid()).toImage(), SubscriptionNumItem::Avatar);
	QString strPY = Biz::SpellHelper::MakeSpellCode(gpName,( Biz::SpellHelper::SpellOptions)0);
	setData(strPY, SubscriptionNumItem::SubcriptionNumPY);
}

SubscriptionNumItem::~SubscriptionNumItem()
{

}

QString SubscriptionNumItem::getSubcriptionNumName()
{
	return this->text();
}
void SubscriptionNumItem::setSubcriptionNumName(const QString& subscripName)
{
	setText(subscripName);
}

void SubscriptionNumItem::updateSubcriptionNumAvatar()
{
	setData(Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(getSubcriptionNumName()).toImage(), SubscriptionNumItem::Avatar);
}

QString SubscriptionNumItem::getSubcriptionNumJid()
{
	return data(SubscriptionNumItem::SubcriptionNumJid).toString();
}





SubscriptionNumItemDelegate::SubscriptionNumItemDelegate()
{

}

QSize SubscriptionNumItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);
	return QSize(44, 54);
}

void SubscriptionNumItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	painter->save();
	painter->setRenderHint(QPainter::TextAntialiasing);

	QColor selectedBg(81, 80, 80);
	QColor normalBg(58, 58, 58);
	QColor selectedText(255, 255, 255);
	QColor nameTextColor(207, 207, 207);
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
		value = index.data(SubscriptionNumItem::Avatar);
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

