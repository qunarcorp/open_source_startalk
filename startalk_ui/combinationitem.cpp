#include "combinationitem.h"
#include <QPainter>
#include "portraithelper.h"
#include "colorset.h"

const int AVATER_HEIGHT = 34;
const int AVATER_WIDTH = 34;
const int JOINPIC_SIZE = 17;

const int BACKWARDAVATER_HEIGHT=30;
const int BACKWARDAVATER_WIDTH=30;

// const int UNREADRECT_WIDTH  = 24;
// const int UNREADRECT_HEIGHT = 15;
const int UNREADRECT_WIDTH  = 12;
const int UNREADRECT_HEIGHT = 12;

CombinationItem::CombinationItem(const QString& id, const QString& strName)
{
	setData(id, CombinationItem::Combinationid);
	setText(strName);
	setData(Biz::PortraitHelper::loadCombinationImage(getCombinationItemid(),""), CombinationItem::Avatar);
	setData(Biz::PortraitHelper::loadCombinationImage(Util::BackWardId,""), CombinationItem::BackWardAvatar);
    setData (true,CombinationItem::BackWardEnable);
	setData(false, CombinationItem::UnReadIconEnable);
	
}

CombinationItem::~CombinationItem()
{

}

QString CombinationItem::getCombinationItemid()
{
	return data(CombinationItem::Combinationid).toString();
}

void CombinationItem::setCombinationExtendable(bool bExtendable)
{
    setData (bExtendable,CombinationItem::BackWardEnable);
}

void CombinationItem::setIconImage(const QImage& image)
{
    setData(image, CombinationItem::Avatar);
}

void CombinationItem::setCombinationUnReadIconable( bool banble )
{
	setData(banble, CombinationItem::UnReadIconEnable);
}

void CombinationItem::setCombinationUnReadIconCount( int count )
{
	setData(count, CombinationItem::UnReadCount);
}




/////CombinationItemDelegate
CombinationItemDelegate::CombinationItemDelegate()
{
	
}

QSize CombinationItemDelegate::sizeHint( const QStyleOptionViewItem& option, const QModelIndex& index ) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);
	return QSize(44, 60);
}

void CombinationItemDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const
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
		value = index.data(CombinationItem::Avatar);
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
	//有为完成的工作任务
	{
		
		bool bable = index.data (CombinationItem::UnReadIconEnable).toBool ();
		int ncount = index.data (CombinationItem::UnReadCount).toInt();
		if(bable&& ncount > 0)
		{
			 QColor textcole = QColor(255,255, 255);
			 QColor textbkg = QColor(249, 95, 86);

			QRect rect = option.rect;
			int nrectwidth = rect.width();
			int nrectheight = rect.height();
			QRect newRect;
			QRect textRect;
			newRect.setLeft(rect.right() - BACKWARDAVATER_WIDTH);
			newRect.setWidth(UNREADRECT_WIDTH);
			newRect.setHeight(UNREADRECT_HEIGHT);
			int nheight = (rect.height() - UNREADRECT_HEIGHT)/2;
			newRect.moveTop(rect.y() +  nheight);
			textRect = newRect;
			textRect.setLeft(newRect.left() );
			
			
			// 画个有背景的圆

			painter->setRenderHint(QPainter::Antialiasing);  // 反锯齿;  
			painter->setPen(Qt::transparent);
			painter->setBrush(QBrush(textbkg,Qt::SolidPattern));
			//painter->drawRoundedRect(newRect, 7, 7);
			painter->drawEllipse(newRect);
			
			//计算文字在红色区域的中间位置
// 			painter->setPen(QPen(textcole,1));
// 			QString text = QString::number(qMin(ncount, 99));
// 			 QFontMetrics fm(font);
// 			int nwidth = fm.width(text);
// 			textRect.setLeft(newRect.left() + (newRect.width() - nwidth)/2 - 1 );
// 			textRect.moveTop(textRect.top() - 1);
// 			painter->drawText(textRect, text);
		}
	

	}
	//右边的方向箭头
	{
		//头像
        bool bExtendAble = index.data (CombinationItem::BackWardEnable).toBool ();
        if (bExtendAble)
        {
            QVariant backwardvalue = index.data(CombinationItem::BackWardAvatar);
            QImage image;
            if(backwardvalue.type() == QVariant::Image)
            {
                image = qvariant_cast<QImage>(backwardvalue);
            }

            if(!image.isNull()){
                QRect rect = option.rect;
                rect.setLeft(rect.right() - BACKWARDAVATER_WIDTH);
                rect.setWidth(BACKWARDAVATER_WIDTH);
                rect.setHeight(BACKWARDAVATER_HEIGHT);
                rect.moveTop(rect.y() + (option.rect.height() - BACKWARDAVATER_HEIGHT)/2);

                painter->drawImage(rect, image);
                painter->setPen(frameColor);
            }
        }
	}
	painter->restore();
}
