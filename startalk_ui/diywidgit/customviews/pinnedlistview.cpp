#include "pinnedlistview.h"
#include <QPainter>
#include <QScrollBar>
#include <QDebug>
#include <QPropertyAnimation>
#include <QEvent>
#include <QWheelEvent>
#include <QApplication>

#include "qframelayout.h"
#include "SpellHelper.h"
#include "XmppMessage.h"


#include "colorset.h"
#include "GroupListData.h"

PinnedListView::PinnedListView(QWidget *parent)
    : QWidget(parent)
    , m_pTreeView (new QTreeView(parent))
{
    lastDbClickTick = 0;

    m_pDataModel = new PinnedListItemModel(m_pTreeView);
    m_pSortModel = new PinnedListItemSortFilterProxyModel(m_pTreeView);
    m_pSortModel->setSourceModel (m_pDataModel);
    m_pTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);  
    m_pTreeView->setExpandsOnDoubleClick (false);
    m_pTreeView->setModel (m_pSortModel);
    m_pTreeView->setItemDelegate(new PinnedListViewDelegate(m_pTreeView));
    m_pTreeView->setVerticalScrollMode (QAbstractItemView::ScrollPerPixel);
    m_pTreeView->setSelectionMode (QAbstractItemView::SelectionMode::NoSelection);

    m_pTreeView->expandAll ();

    QScrollBar* pbar = new SmoothVScrollBar(Qt::Orientation::Vertical);
    m_pTreeView->setVerticalScrollBar (pbar);

    m_pTreeView->setHeaderHidden (true);
    m_pTreeView->setAnimated (true);
    m_pTreeView->setIndentation (0);

    m_pTreeView->setVerticalScrollBarPolicy (Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

    m_pTreeView->setStyleSheet ("border:none;background:#00000000;");
    m_pHeaderText = new QPushButton(this);
    m_pHeaderText->setFlat (true);
    m_pHeaderText->setFixedHeight (20);
    m_pHeaderText->setText ("heder it is");
    m_pHeaderText->setStyleSheet (";background:#E0E0E0;padding-left:10px;text-align:left;");
    m_pHeaderText->setVisible (false);

    QFrameLayout* playout = new QFrameLayout(this);
    playout->appendWidget (m_pTreeView,ALINE_FILL);
    playout->appendWidget (m_pHeaderText,ALINE_MATCHWIDTH|ALINE_TOP);
    this->setLayout (playout);

    connect (m_pTreeView,&QTreeView::clicked,this,&PinnedListView::onItemClicked);
    connect (m_pTreeView,&QTreeView::doubleClicked,this,&PinnedListView::onItemDoubleClicked);
    this->setStyleSheet("border:none;");
}

PinnedListView::~PinnedListView()
{
}

void PinnedListView::setItemImage(const QString& jid,const QImage& image)
{
    QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);
    
    if (!indexes.isEmpty ())
    {
        QModelIndex index = indexes.at (0);
        QModelIndex indexRaw = m_pSortModel->mapToSource (index);
        QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
        if (NULL!=pItem)
        {
            pItem->setData (image,PinnedListView::UserColumnName::UCN_HeaderImage);
        }
    }

}


void PinnedListView::setItemName(const QString& jid,const QString& jidName)
{
    // 需要更新名字，以及排序
    QString nickName = jidName.isEmpty ()?Biz::MessageUtil::makeSureUserId (jid):jidName;
    QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);
    if (!indexes.isEmpty ())
    {
        QModelIndex index = indexes.at (0);
        QModelIndex indexRaw = m_pSortModel->mapToSource (index);
        QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
       
        if (NULL!=pItem)
        {
             QString currName = pItem->data (PinnedListView::UserColumnName::UCN_Name).toString ();
             if (currName == jidName)
                    return;
            PinnedListItem* pNewItem = new PinnedListItem(pItem);
            QString strPY = Biz::SpellHelper::MakeSpellCode(nickName,( Biz::SpellHelper::SpellOptions)0).trimmed();
            pNewItem->setData (nickName,PinnedListView::UserColumnName::UCN_Name);
            pNewItem->setData (strPY,PinnedListView::UserColumnName::UCN_SortKey);

            deleteItem (jid);

            QString groupName = strPY.isEmpty ()? QString("#") : strPY.at (0).toUpper ();
            if (groupName < "A" || groupName > "Z")
                groupName = "#";
              
            QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_Type, groupName, -1, Qt::MatchFlag::MatchExactly);
            QStandardItem* pGroupItem = NULL;
            if (indexes.isEmpty ())
            {
                pGroupItem = new PinnedListItem();
                pGroupItem->setData (groupName,UserColumnName::UCN_Type);
                pGroupItem->setData (groupName,UserColumnName::UCN_Name);
                m_pDataModel->appendRow (pGroupItem);
                pGroupItem->appendRow (pNewItem);
            }
            else
            {
                QModelIndex index = indexes.at (0);
                QModelIndex indexRaw = m_pSortModel->mapToSource (index);
                pGroupItem = m_pDataModel->itemFromIndex (indexRaw);
                pGroupItem->appendRow (pNewItem);
            }
        }
    }
    m_pTreeView->expandAll ();
    m_pSortModel->sort (0);
}

void PinnedListView::contextMenuEvent(QContextMenuEvent *e)
{
    QModelIndex index = m_pTreeView->indexAt(e->pos());
    QStandardItem* pItem = m_pDataModel->itemFromIndex(m_pSortModel->mapToSource(index));
    if (NULL!=pItem)
    {
        QString groupid = pItem->data (PinnedListView::UserColumnName::UCN_Type).toString ();
        if (groupid.isEmpty ())
        {
            QString jid = pItem->data (PinnedListView::UserColumnName::UCN_ID).toString ();
            emit sgContextMenuEvent(jid);
			contextMenuEvent (jid);
        }
    }
}

void PinnedListView::contextMenuEvent(const QString& jid)
{

}

void PinnedListView::activeItem(const QString& jid)
{
    QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);
    if (!indexes.isEmpty ())
    {
        QModelIndex index = indexes.at (0);
        m_pTreeView->setCurrentIndex (index);
    }
}

void PinnedListView::onItemDoubleClicked(const QModelIndex& index)
{
    QModelIndex indexRaw = m_pSortModel->mapToSource (index);
    QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
    lastDbClickTick = QDateTime::currentMSecsSinceEpoch();
    if (NULL!=pItem)
    {
        QString groupid = pItem->data (PinnedListView::UserColumnName::UCN_Type).toString ();
        if (groupid.isEmpty ())
        {
            QString jid = pItem->data (PinnedListView::UserColumnName::UCN_ID).toString ();
            emit sgItemDoubleClicked (jid);
        }
    }
}

void PinnedListView::onItemClicked(const QModelIndex& index)
{
    if (1000>QDateTime::currentMSecsSinceEpoch()-lastDbClickTick)
        return;

    QModelIndex indexRaw = m_pSortModel->mapToSource (index);
    QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
    if (NULL!=pItem)
    {
        QString groupid = pItem->data (PinnedListView::UserColumnName::UCN_Type).toString ();
        if (groupid.isEmpty ())
        {
            QString jid = pItem->data (PinnedListView::UserColumnName::UCN_ID).toString ();
            emit sgItemClicked (jid);
        }
    }
}

void PinnedListView::insertItem(const QString& jid)
{
    insertItem (jid,Biz::MessageUtil::makeSureUserId (jid));
}

void PinnedListView::insertItem(const QString& jid,const QString& jidName)
{
    QString strPY = Biz::SpellHelper::MakeSpellCode(jidName,( Biz::SpellHelper::SpellOptions)0).trimmed ();
    QString groupName = strPY.isEmpty ()? QString("#") : strPY.at (0).toUpper ();
    if (groupName < "A" || groupName > "Z")
        groupName = "#";

    // 如果没有group分组的，自动加一个上去
    QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_Type, groupName, -1, Qt::MatchFlag::MatchExactly);
    QStandardItem* pGroupItem = NULL;
    if (indexes.isEmpty ())
    {
        pGroupItem = new PinnedListItem();
        pGroupItem->setData (groupName,UserColumnName::UCN_Type);
        pGroupItem->setData (groupName,UserColumnName::UCN_Name);
        m_pDataModel->appendRow (pGroupItem);
    }
    else
    {
        QModelIndex index = indexes.at (0);
        QModelIndex indexRaw = m_pSortModel->mapToSource (index);
        pGroupItem = m_pDataModel->itemFromIndex (indexRaw);
    }

    if (NULL!=pGroupItem)
    {
		QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);
		if(indexes.isEmpty())
		{

			PinnedListItem* pItem =  new PinnedListItem();
			pItem->setData (jid,UserColumnName::UCN_ID);
			pItem->setData (jidName,UserColumnName::UCN_Name);
			pItem->setData (strPY, UserColumnName::UCN_SortKey);
			pGroupItem->appendRow (pItem);
		}
    }
    m_pTreeView->expandAll ();

    m_pSortModel->sort (0);
}

void PinnedListView::deleteItem(const QString& jid)
{
    QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);
    if (!indexes.isEmpty ())
    {
        QModelIndex index = indexes.at (0);
        QModelIndex indexraw = m_pSortModel->mapToSource (index);
        QStandardItem* pItem = m_pDataModel->itemFromIndex (indexraw);
        QString shotkey = pItem->data (PinnedListView::UserColumnName::UCN_SortKey).toString ();
        QString groupName = shotkey.isEmpty ()? QString("#") : shotkey.at (0).toUpper ();
        if (groupName < "A" || groupName > "Z")
            groupName = "#";

        QModelIndexList groupindexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_Type, groupName, -1, Qt::MatchFlag::MatchExactly);
        if (!groupindexes.isEmpty ())
        {
            QModelIndex gindex = groupindexes.at (0);
            QModelIndex gindexraw = m_pSortModel->mapToSource (gindex);
            QStandardItem* pgItem = m_pDataModel->itemFromIndex (gindexraw);

            if (NULL!=pgItem)
            {
                pgItem->removeRow (pItem->row ());

                if (!pgItem->hasChildren ())
                    m_pDataModel->removeRow (pgItem->row ());
            }
        }
    }

    if (m_pDataModel->rowCount () == 0)
    {
        emit sgListEmpty ();
    }
}

const QString PinnedListView::currentSelectJid()
{
   QModelIndex index = m_pTreeView->currentIndex ();
   QModelIndex dataIndex = m_pSortModel->mapToSource (index);
   QStandardItem* pItem = m_pDataModel->itemFromIndex (dataIndex);
   if (NULL!=pItem)
   {
       QString groupid = pItem->data (PinnedListView::UserColumnName::UCN_Type).toString ();
       if (groupid.isEmpty ())
           return pItem->data (PinnedListView::UserColumnName::UCN_ID).toString ();
   }
   return "";
}

void PinnedListView::clearAll()
{
    if (NULL!=m_pDataModel)
    {
        m_pDataModel->clear ();
    }

    emit sgListEmpty();
}

void PinnedListView::setGroupNoticeTipChangeinned(const QString&jid, int addoption, int removeoption)
{
	QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);

	if (!indexes.isEmpty ())
	{
		QModelIndex index = indexes.at (0);
		QModelIndex indexRaw = m_pSortModel->mapToSource (index);
		QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
		if (NULL!=pItem)
		{
			int CurrentNotictipoption = pItem->data(PinnedListView::UserColumnName::UCN_NoticeTip).toInt();
			CurrentNotictipoption = (CurrentNotictipoption & ~removeoption) | addoption;
			pItem->setData (CurrentNotictipoption,PinnedListView::UserColumnName::UCN_NoticeTip);
		}
	}
}

void PinnedListView::setGroupNoticeTipinned( const QString&jid, int noticeflag )
{
	QModelIndexList indexes = m_pSortModel->match(m_pSortModel->index(0, 0, QModelIndex()), UserColumnName::UCN_ID, jid, 2, Qt::MatchFlag::MatchRecursive|Qt::MatchFlag::MatchExactly);

	if (!indexes.isEmpty ())
	{
		QModelIndex index = indexes.at (0);
		QModelIndex indexRaw = m_pSortModel->mapToSource (index);
		QStandardItem* pItem = m_pDataModel->itemFromIndex (indexRaw);
		if (NULL!=pItem)
		{
			pItem->setData (noticeflag,PinnedListView::UserColumnName::UCN_NoticeTip);
		}
	}
}



void PinnedListViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing);

    //     QColor selectedBg   (ColorSetSingleton::getInstance()->recent_item_bk_checked());
    //     QColor normalBg     (ColorSetSingleton::getInstance()->transparent());
    //     QColor selectedText (ColorSetSingleton::getInstance()->recent_item_title_checked());
    //     QColor nameTextColor(ColorSetSingleton::getInstance()->recent_item_title_normal());

    QColor itemNormalBg     = ColorSetSingleton::getInstance ()->pinned_list_item_bk_normal ();
    QColor itemHoverdBg     = ColorSetSingleton::getInstance ()->pinned_list_item_bk_hover ();
    QColor itemCheckdBg     = ColorSetSingleton::getInstance ()->pinned_list_item_bk_checked ();


//     QColor itemNormalBg     = QColor("#EAEAEA");
//     QColor itemHoverdBg     = QColor("#E2E4E6");
//     QColor itemCheckdBg     = QColor("#CACDD3");

    QColor groupNormalBg    = ColorSetSingleton::getInstance ()->pinned_list_group_bk_checked ();
    QColor groupHoverdBg    = itemCheckdBg;

    QColor groupTextColor   = ColorSetSingleton::getInstance ()->pinned_list_text_checked ();
    QColor itemsTextColor   = groupTextColor;

    const bool isGroup = !index.data (PinnedListView::UserColumnName::UCN_Type).toString ().isEmpty ();

    const QRect frameRect = option.rect;
    // 画背景
    if (QStyle::State_Selected == (option.state & QStyle::State_Selected))
    {
        painter->fillRect(frameRect,isGroup?groupHoverdBg:itemCheckdBg);
    }
    else if (QStyle::State_MouseOver == (option.state & QStyle::State_MouseOver))
    {
        painter->fillRect(frameRect,isGroup?groupHoverdBg:itemHoverdBg);
    }
    else
    {
        painter->fillRect(frameRect,isGroup?groupNormalBg:itemNormalBg);
    }

    if (isGroup)
    {
        QFont font;
        font.setPixelSize(12);
        QPen groupNamePen(groupTextColor);
        painter->setFont (font);
        painter->setPen (groupNamePen);

        QRect groupRect = frameRect;
        groupRect.setLeft (groupRect.left ()+10); // margin-left 10px;

        QString nameText = index.data(PinnedListView::UserColumnName::UCN_Name).toString();

        QFontMetrics fontMetrics(font);
        nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, groupRect.width() - 30); // margin-right:30px;
        painter->drawText(groupRect,Qt::AlignVCenter|Qt::AlignLeft, nameText);
    }
    else
    {
        QRect headerRect = frameRect; //(10,4,32,32);
        headerRect.setX (headerRect.x ()+10);
        headerRect.setY (headerRect.y ()+4);
        headerRect.setWidth (32);
        headerRect.setHeight (32);
//         painter->setPen (QPen(QColor("#55AAFF")));
//         painter->drawRect (headerRect);

        QVariant value = index.data(PinnedListView::UserColumnName::UCN_HeaderImage);
        QImage image;
        if(value.type() == QVariant::Image)
        {
            image = qvariant_cast<QImage>(value);
            if(!image.isNull()){
                QRect imageRect = frameRect;
				//对消息提醒的处理
				int noticetip = index.data(PinnedListView::UserColumnName::UCN_NoticeTip).toInt();

				//为什么isGroup不能代表群？？？？
				if (/*isGroup && */(Biz::GroupSetting::RECV_WITHOUT_NOTICE == (noticetip& Biz::GroupSetting::RECV_WITHOUT_NOTICE)))
				{
					QPixmap pixmap = qvariant_cast<QPixmap>(value);
					QPixmap newpixmap = pixmap.scaled(32, 32);
					QPainter pt(&newpixmap);


					pt.setPen(QColor("#00000000"));
					QRect rectnew(headerRect.bottomRight().x()  - headerRect.topLeft().x() - 16 + 1, headerRect.bottomRight().y() - headerRect.topLeft().y() - 16 + 1 , 16, 16);
					QImage paintedImg = QImage(":Images/withoutnotice.png");
					
					//右下角的原图
					pt.drawImage(rectnew,paintedImg);

					image = newpixmap.toImage();
// 					QString strjid = Biz::MessageUtil::makeSureGroupId(index.data(PinnedListView::UserColumnName::UCN_ID).toString());
// 					QString strfileName = QString("D:/") + strjid + QString(".png");
// 					image.save(strfileName, "PNG");\
// 					
                    pt.restore ();
				}
                painter->drawImage(headerRect, image);
            }
        }

        QFont font;
        font.setPixelSize(12);
        QPen namePen(groupTextColor);
        painter->setFont (font);
        painter->setPen (namePen);


        QRect itemRect = frameRect;
        itemRect.setLeft (itemRect.left ()+52); // margin-left 10px;

        QString nameText = index.data(PinnedListView::UserColumnName::UCN_Name).toString();

        QFontMetrics fontMetrics(font);
        nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, itemRect.width() - 30); // margin-right:30px;
        painter->drawText(itemRect,Qt::AlignVCenter|Qt::AlignLeft, nameText); 

       
    }


    QString content = index.data ().toString ();
    painter->drawText (option.rect,content);

     painter->restore ();
}

QSize PinnedListViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString groupName = index.data (PinnedListView::UserColumnName::UCN_Type).toString ();
    return !groupName.isEmpty () ? QSize(20,20) : QSize(20,40);
}

PinnedListViewDelegate::PinnedListViewDelegate(QObject* parent)
    :QItemDelegate(parent)
{

}

PinnedListViewDelegate::~PinnedListViewDelegate()
{

}

PinnedListItemSortFilterProxyModel::PinnedListItemSortFilterProxyModel(QObject* parent)
{

}

PinnedListItemSortFilterProxyModel::~PinnedListItemSortFilterProxyModel()
{

}


bool PinnedListItemSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    bool bdesc = false;
    QString leftGroupName = left.data(PinnedListView::UserColumnName::UCN_Type).toString();
    QString rightGroupName = right.data(PinnedListView::UserColumnName::UCN_Type).toString();
    if(!leftGroupName.isEmpty() && rightGroupName.isEmpty())
        return bdesc;
    else if(leftGroupName.isEmpty() && !rightGroupName.isEmpty())
        return !bdesc;
    else if(!leftGroupName.isEmpty() && !rightGroupName.isEmpty())
    {
        bool result = leftGroupName.compare(rightGroupName);

        return (leftGroupName.compare(rightGroupName) < 0) ? !bdesc:bdesc;
    }
    //两个子节点，比在线状态
    else if(leftGroupName.isEmpty() && rightGroupName.isEmpty())
    {
        QString leftSortkey = left.data(PinnedListView::UserColumnName::UCN_SortKey).toString ();
        QString rightSortkey= right.data(PinnedListView::UserColumnName::UCN_SortKey).toString();

        return (leftSortkey.compare(rightSortkey) < 0) ? !bdesc : bdesc;
    }
    return bdesc;
}



PinnedListItemModel::PinnedListItemModel(QObject* parent)
{

}

PinnedListItemModel::~PinnedListItemModel()
{

}

void SmoothVScrollBar::wheelEvent(QWheelEvent *e)
{
    if (bSmooth)
    {
        setSingleStep (5);
    }
    return QScrollBar::wheelEvent (e);
}

SmoothVScrollBar::SmoothVScrollBar(QWidget *parent/*=0*/) : QScrollBar(parent)
{
    bSmooth = false;
    connect (this,SIGNAL(actionTriggered(int)),this,SLOT(onScrollBarActionTriggered(int)));
    connect (this,SIGNAL(valueChanged(int)),this,SLOT(onScrollBarValueChanged(int)));
    m_pScrollAnimation = new QPropertyAnimation(this,"value");
    m_nOneStepDuration = 300;
    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
    m_nLastPosition= 0;
    m_bForward = true;
}

SmoothVScrollBar::SmoothVScrollBar(Qt::Orientation o, QWidget *parent/*=0*/) : QScrollBar(o, parent)
{
    bSmooth = false;
    connect (this,SIGNAL(actionTriggered(int)),this,SLOT(onScrollBarActionTriggered(int)));
    connect (this,SIGNAL(valueChanged(int)),this,SLOT(onScrollBarValueChanged(int)));
    m_pScrollAnimation = new QPropertyAnimation(this,"value");
    m_nOneStepDuration = 300;
    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
    m_nLastPosition= 0;
    m_bForward = true;
}

SmoothVScrollBar::~SmoothVScrollBar()
{

}

void SmoothVScrollBar::onScrollBarValueChanged(int value)
{
    if (!bSmooth)
        return;

    m_nLastPosition = value;
}

void SmoothVScrollBar::onScrollBarActionTriggered(int value)
{
    if (!bSmooth)
        return;

    if ( !this->isSliderDown() && value == QAbstractSlider::SliderMove)
    {
        int currentPostion = this->sliderPosition();

        if (QAbstractAnimation::Running == m_pScrollAnimation->state ())
        {
            m_pScrollAnimation->pause ();

            if (m_bForward)
            {
                // 正向
                if (currentPostion<m_nLastPosition)
                {
                    m_bForward = false;

                    m_pScrollAnimation->setStartValue (m_nLastPosition);
                    m_pScrollAnimation->setEndValue (currentPostion);
                    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
                    m_pScrollAnimation->setDuration (m_nOneStepDuration);
                    m_pScrollAnimation->setCurrentTime (0);
                    m_pScrollAnimation->resume ();
                }
                else
                {
                    m_pScrollAnimation->setStartValue (m_nLastPosition);
                    m_pScrollAnimation->setDuration (qMin(int(m_pScrollAnimation->duration ()*1.5),m_nOneStepDuration*3));
                    m_pScrollAnimation->setEndValue (qMin(m_pScrollAnimation->endValue ().toInt ()+(m_pScrollAnimation->endValue ().toInt ()- m_pScrollAnimation->startValue ().toInt ()),m_nLastPosition+500));
                    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
                    m_pScrollAnimation->setCurrentTime (0);
                    m_pScrollAnimation->resume ();
                }
            }
            else
            {
                // 反向
                if (currentPostion > m_nLastPosition)
                {
                    m_bForward = true;
                    m_pScrollAnimation->setStartValue (m_nLastPosition);
                    m_pScrollAnimation->setEndValue (currentPostion);
                    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
                    m_pScrollAnimation->setDuration (m_nOneStepDuration);
                    m_pScrollAnimation->setCurrentTime (0);
                    m_pScrollAnimation->start ();
                }
                else
                {
                    m_pScrollAnimation->setStartValue (m_nLastPosition);
                    m_pScrollAnimation->setEndValue (qMax(m_pScrollAnimation->endValue ().toInt () - (m_pScrollAnimation->startValue ().toInt ()  - m_pScrollAnimation->endValue ().toInt () ),qMax(m_nLastPosition-500,0)));
                    m_pScrollAnimation->setDuration (qMin(int(m_pScrollAnimation->duration ()*1.5),m_nOneStepDuration*3));
                    m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
                    m_pScrollAnimation->setCurrentTime (0);
                    m_pScrollAnimation->resume ();
                }
            }
        }
        else{
            m_pScrollAnimation->setCurrentTime (0);
            m_pScrollAnimation->setEasingCurve (QEasingCurve::Linear);
            m_pScrollAnimation->setStartValue (m_nLastPosition);
            m_pScrollAnimation->setEndValue (currentPostion);
            m_pScrollAnimation->setDuration (m_nOneStepDuration);
            m_pScrollAnimation->start ();
        }
    }
}

PinnedListItem::PinnedListItem(const QStandardItem* otheritem)
{
    if (NULL!=otheritem)
    {
        QList<int> datas;
        datas << PinnedListView::UserColumnName::UCN_Type
            << PinnedListView::UserColumnName::UCN_ID
            << PinnedListView::UserColumnName::UCN_Name
            << PinnedListView::UserColumnName::UCN_SortKey
            << PinnedListView::UserColumnName::UCN_HeaderImage
			<< PinnedListView::UserColumnName::UCN_NoticeTip;

        for (int data : datas)
        {
            if (otheritem->data (data).isValid ())
            {
                this->setData (otheritem->data (data),data);
            }
        }
    }
}

PinnedListItem::PinnedListItem()
{

}

PinnedListItem::~PinnedListItem()
{

}
