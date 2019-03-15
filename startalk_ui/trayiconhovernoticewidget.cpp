#include "trayiconhovernoticewidget.h"

#include <QListWidgetItem>

#include "SystemIcon.h"
#include "portraithelper.h"
#include "XmppMessage.h"
#include "Session.h"
#include "Account.h"
#include "UserVcardManager.h"
#include "GroupManager.h"

TrayIconHoverNoticeWidget::TrayIconHoverNoticeWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

   
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | Tool | WindowStaysOnTopHint;
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    connect(&SystemIcon::instance(),&SystemIcon::sgMouseHover,this,&TrayIconHoverNoticeWidget::smartShow);
    connect(&SystemIcon::instance(),&SystemIcon::sgMouseLeave,this,&TrayIconHoverNoticeWidget::smartHide);
    connect(ui.listWidget,&QListWidget::itemClicked,this,&TrayIconHoverNoticeWidget::onItemClicked);
    connect(ui.ignore,&QPushButton::clicked,[this](bool){
        SystemIcon::instance().stopTrayIcon();
        this->markAllItemRead();
    });

    hideDelay.setDuration(300);
    connect(&hideDelay,&QTimeLine::finished,[this](){
        this->hide();
    });

}

TrayIconHoverNoticeWidget::~TrayIconHoverNoticeWidget()
{

}

void TrayIconHoverNoticeWidget::smartShow(const QRect& trayRect)
{
    int itemcount = qMin(ui.listWidget->count(),5);
    setFixedHeight(47*itemcount+33*2+1*2);

    if (itemcount!=0)
    {
        if (!this->isVisible())
        {
            QPoint pos = trayRect.topLeft()/this->devicePixelRatio();
			
            this->move(pos.x()-(this->width()-trayRect.width())/2,pos.y()-this->height()-5);
            this->show();
            this->activateWindow();
        }
        hideDelay.stop();
    }
}

void TrayIconHoverNoticeWidget::smartHide()
{
    QPoint gpos = QCursor::pos();
    QPoint curPos = this->mapFromGlobal(gpos);
    if (!this->rect().contains(curPos))
    {
        hideDelay.start();
    }
}

void TrayIconHoverNoticeWidget::leaveEvent(QEvent *)
{
    hideDelay.start();
}

void TrayIconHoverNoticeWidget::addUnreadMessage(const QSharedPointer<Biz::XmppMessage>& pMsg)
{
    QString peerid = pMsg->ConversationID();
    addUnreadMessage(peerid,pMsg);
}

void TrayIconHoverNoticeWidget::addUnreadMessage(const QString& jid,const QSharedPointer<Biz::XmppMessage>& pMsg)
{
    QString peerid = jid;
    if (items.contains(peerid))
    {
        QListWidgetItem* pitem = items[peerid];
        TrayHoverNoticeItem* pWidget = (TrayHoverNoticeItem*)ui.listWidget->itemWidget(pitem);
		if (pWidget)
		{
			 pWidget->increseUnreadCount(1);
		}
    }
    else
    {
        // 新加一向
        QListWidgetItem* pitem = new QListWidgetItem(ui.listWidget);
        pitem->setSizeHint(QSize(47,47));
        ui.listWidget->addItem(pitem);
        items.insert(peerid,pitem);

        TrayHoverNoticeItem* pWidget = new TrayHoverNoticeItem(NULL);
        pWidget->increseUnreadCount(1);
        pWidget->setJid(peerid);
        QString name;
        if (peerid.contains("@conference.")) //判断是不是群
        {
            name = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(peerid);//Biz::Session::currentAccount().getGroupNickName(peerid);
            if (name.isEmpty())
            {
				name = Biz::MessageUtil::makeSureGroupId(peerid);
            }
        }
        else
        {
			name = Biz::Session::getUserVcardManager()->getUserNameByConversationId(peerid);
			if (name.isEmpty())
			{
				name = Biz::MessageUtil::makeSureUserId(peerid);
			}
        }

        if (name.isEmpty())
        {
            name = peerid;
        }

        pWidget->setDisplayName(name);
        ui.listWidget->setItemWidget(pitem,pWidget);

        
        int itemcount = qMin(ui.listWidget->count(),5);
        setFixedHeight(47*itemcount+33*2+1*2);

        ui.title->setText(QStringLiteral("新消息（%1）").arg(ui.listWidget->count()));
    }
}

void TrayIconHoverNoticeWidget::markAllItemRead()
{
    foreach(QString key,items.keys()){
        QListWidgetItem* pItem = items[key];
        int row = ui.listWidget->row(pItem);
        pItem = ui.listWidget->takeItem(row);
        TrayHoverNoticeItem* pWidget = (TrayHoverNoticeItem*)ui.listWidget->itemWidget(pItem);
        if (NULL!=pWidget)
        {
            delete pWidget;
        }
    }

    ui.listWidget->clear();
    items.clear();
    this->hide();
}

void TrayIconHoverNoticeWidget::markItemRead(const QString& peerid)
{
    if (items.contains(peerid))
    {
        QListWidgetItem* pItem = items[peerid];
        int row = ui.listWidget->row(pItem);
        pItem = ui.listWidget->takeItem(row);
        TrayHoverNoticeItem* pWidget = (TrayHoverNoticeItem*)ui.listWidget->itemWidget(pItem);
        if (NULL!=pWidget)
        {
            delete pWidget;
        }

    }
}

void TrayIconHoverNoticeWidget::onItemClicked(QListWidgetItem* pItem)
{
    if (NULL!=pItem)
    {
        TrayHoverNoticeItem* pWidget = (TrayHoverNoticeItem*)ui.listWidget->itemWidget(pItem);
        if (NULL!=pWidget)
        {
            emit sgOpenItem(pWidget->getJid());
        }
    }
        
}



TrayHoverNoticeItem::TrayHoverNoticeItem(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.count->setText("0");
	

}

TrayHoverNoticeItem::~TrayHoverNoticeItem()
{

}

void TrayHoverNoticeItem::increseUnreadCount(int offset)
{
    int count = ui.count->text().toInt();
    ui.count->setText(QString::number(count + offset));
}

void TrayHoverNoticeItem::setDisplayName(const QString& name)
{
    ui.name->setText(name);
}

void TrayHoverNoticeItem::setJid(const QString& jid)
{
    this->jid = jid;
// 	QTimeLine* pTimer = new QTimeLine();
// 	connect(pTimer, &QTimeLine::finished, [this, pTimer, jid] {
// 		QSize size = ui.header->size();
// 		QPixmap& pixmap = Biz::PortraitHelper::getGroupPortrait(jid);
// 		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(size));
// 		ui.header->setPixmap(pixmap);
// 		pTimer->stop();
// 	});
	
    if (jid.contains("@"))
    {
        QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(jid);
        //ui.header->setScaledContents(true);
		QSize size = ui.header->size();
		size = this->size();
		QRect rect = ui.header->geometry();
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(QSize(33, 33)/*ui.header->size()*/));
        ui.header->setPixmap(pixmap);
		//pTimer->start();
    }
    else
    {
        QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(jid);
       // ui.header->setScaledContents(true);
		QSize size = ui.header->size();
		QRect rect = ui.header->geometry();
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(QSize(33,33)/*ui.header->size()*/));
        ui.header->setPixmap(pixmap);
		//pTimer->start();
    }
   
}
