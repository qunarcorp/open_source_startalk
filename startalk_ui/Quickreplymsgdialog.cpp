#include "Quickreplymsgdialog.h"
#include <QApplication>
#include <QDesktopWidget>

#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "quickrepysetting.h"
#include "gloableeventobject.h"



QuickReplyMsgDialog::QuickReplyMsgDialog(QWidget *parent)
	: LocalManWidget(parent)
{
	ui.setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
	setAttribute(Qt::WA_TranslucentBackground, true); 
	setAutoFillBackground(true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	setMoveable(false);
	Init();

	connect(ui.Replylistgroup, &QListWidget::itemClicked, this, &QuickReplyMsgDialog::onItemClicked);
	connect(ui.ReplylistMsg, &QListWidget::itemClicked, this, &QuickReplyMsgDialog::onItemClicked);
	connect(ui.pbSetting, &QPushButton::clicked, this, &QuickReplyMsgDialog::onpbSettingClicked);
	//connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyUpdate, this, &QuickReplyMsgDialog::onQuickReplyUpdate);
	connect(ui.ReplylistMsg, &QListWidget::itemEntered, this, &QuickReplyMsgDialog::onRightItemEntered);

	connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyGroupChange, this, &QuickReplyMsgDialog::onQuickReplyGroupChange);
	connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyAllContentChange, this, &QuickReplyMsgDialog::onQuickReplyAllContentChange);
	connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyContentChange, this, &QuickReplyMsgDialog::onQuickReplyContentChange);

}

QuickReplyMsgDialog::~QuickReplyMsgDialog()
{

} 

void QuickReplyMsgDialog::autoshow()
{
	show();
	activateWindow();
}

void QuickReplyMsgDialog::Init()
{ 
	showDetailInfor(Biz::Session::getServiceManager()->getDaoService()->getQuickReplyGroupItems());
	/*
	QList<QuickReplyMsgItem*> QuickmsgList;
	QString strQuickReplyMsgFilePath
		= Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/" + "quickreplyu.xml";
	//判断在appdata下面的快捷回复文件是否存在，
	QString strappdataQuickReplyFilePath =  Biz::ConfigureHelper::QuickReplyListConfigurePath(Biz::Session::currentAccount().accountData().UserID());
	if (QFile::exists(strappdataQuickReplyFilePath))
	{
		QuickmsgList = QuickReplyMsgMgr::GetInstance(strappdataQuickReplyFilePath)->getQuickReplyList();
	}
	else
	{
		QuickmsgList = QuickReplyMsgMgr::GetInstance(strQuickReplyMsgFilePath)->getQuickReplyList();
	}
	 
	showDetailInfor(QuickmsgList);
	*/
}

void QuickReplyMsgDialog::onItemClicked( QListWidgetItem *pItem )
{
	 QListWidget* psender = (QListWidget*)sender();
	if (psender == ui.Replylistgroup)
	{ 
		SetShowMsg(pItem->data(Qt::UserRole).toString());
	}
	else if (psender==ui.ReplylistMsg)
	{
		emit sgItemSelected(conversationId, pItem->text());
		this->hide();
	}
}

void QuickReplyMsgDialog::SetShowMsg( const QString &groupCid)
{ 
	ui.ReplylistMsg->clear();
	QList<QSharedPointer<Biz::QuickReplyContent>> contentList = Biz::Session::getServiceManager()->getDaoService()->getQuickReplyContentItems(groupCid);
	for (QSharedPointer<Biz::QuickReplyContent> contentItem : contentList) {
		QListWidgetItem * listitem = new QListWidgetItem;
		listitem->setData(Qt::DisplayRole, contentItem->Content());
		listitem->setData(Qt::UserRole, contentItem->ContentCId());
		listitem->setToolTip(contentItem->Content());
		ui.ReplylistMsg->addItem(listitem);
	}
	return;
	/*
	ui.ReplylistMsg->clear();
	QList <QuickReplyMsgItem*> itemlist;
	QString strText = text;
	if (valmap.contains(strText))
	{
		QMap<QString, QList<QuickReplyMsgItem*>> ::iterator itvalmap;
		for (itvalmap = valmap.begin(); itvalmap != valmap.end(); ++itvalmap)
		{
			if (itvalmap.key() == strText )
			{
				itemlist = valmap.value(itvalmap.key());
				break;
			}
		}

		if (itemlist.count() > 0)
		{
			QStringList strlist;
			for (QuickReplyMsgItem *item: itemlist)
			{

				//strlist.append(item->content);
				QListWidgetItem * listitem = new QListWidgetItem;
				listitem->setData(Qt::DisplayRole, item->content);
				listitem->setData(Qt::UserRole, item);
				listitem->setToolTip(item->content);
				ui.ReplylistMsg->addItem(listitem);
			}

			//ui.ReplylistMsg->addItems(strlist);
			ui.ReplylistMsg->sortItems();
		}

	}
	*/
}

void QuickReplyMsgDialog::onpbSettingClicked()
{
	QuickRepySetting *dlg;
	dlg = QuickRepySetting::Inistance();
	if (dlg)
	{
		dlg->ShowQuickReplySetting();
	}

}

void QuickReplyMsgDialog::onQuickReplyGroupChange() { 
	int currentRow = ui.Replylistgroup->currentRow(); 
	ui.Replylistgroup->clear();
	ui.ReplylistMsg->clear();
	QList<QSharedPointer<Biz::QuickReplyGroup>> groupList = Biz::Session::getServiceManager()->getDaoService()->getQuickReplyGroupItems();
	showDetailInfor(groupList);
	if (currentRow >= 0 && currentRow <= groupList.size() - 1)
	{
		ui.Replylistgroup->setCurrentRow(currentRow); 
		SetShowMsg(ui.Replylistgroup->currentItem()->data(Qt::UserRole).toString());
	} else if (groupList.size() > 0)
	{ 
		ui.Replylistgroup->setCurrentRow(0); 
		SetShowMsg(ui.Replylistgroup->currentItem()->data(Qt::UserRole).toString());
	}
}

void QuickReplyMsgDialog::onQuickReplyAllContentChange() {
	SetShowMsg(ui.Replylistgroup->currentItem()->data(Qt::UserRole).toString());
}

void QuickReplyMsgDialog::onQuickReplyContentChange(const QString &groupCid) {
	SetShowMsg(groupCid);
}

void QuickReplyMsgDialog::onQuickReplyUpdate(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList)
{
	ui.Replylistgroup->clear();
	ui.ReplylistMsg->clear();
	valmap.clear();
	showDetailInfor(replyGroupList);
}

void QuickReplyMsgDialog::mouseMoveEvent( QMouseEvent *event )
{

	LocalManWidget::mouseMoveEvent(event);
}

void QuickReplyMsgDialog::showDetailInfor(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList)
{
	if (replyGroupList.length()<=0) {
		return ;
	} 
	for (QSharedPointer<Biz::QuickReplyGroup> groupItem : replyGroupList) {  
		QListWidgetItem * listitem = new QListWidgetItem;
		listitem->setData(Qt::DisplayRole, groupItem->GroupName());
		listitem->setData(Qt::UserRole, groupItem->GroupCId());
		listitem->setToolTip(groupItem->GroupName());
		ui.Replylistgroup->addItem(listitem);  
	}   
	ui.Replylistgroup->setCurrentRow(0);
	//显示
	//onItemClicked(ui.Replylistgroup->selectedItems().at(0));
	SetShowMsg(ui.Replylistgroup->currentItem()->data(Qt::UserRole).toString());
	/*
	//把 常用 -----Item对应起来
	for (QuickReplyMsgItem *item: QuickmsgList)
	{
		if (valmap.contains(item->group))
		{
			//QList <QuickReplyMsgItem*>& itemlist = valmap[item->group];
			//itemlist.append(item);
			(valmap[item->group]).append(item);
		}
		else
		{
			QList <QuickReplyMsgItem*> itemlist;
			itemlist.append(item);
			valmap.insert(item->group, itemlist);
		}

	}


	//for
	QStringList list;
	QMap<QString, QList<QuickReplyMsgItem*>> ::iterator itvalmap;
	for (itvalmap = valmap.begin(); itvalmap != valmap.end(); ++itvalmap)
	{
		QString key = itvalmap.key();

		list.append(key);
		
	}

	ui.Replylistgroup->addItems(list);
	ui.Replylistgroup->sortItems();


	ui.Replylistgroup->setCurrentRow(0);
	//显示
	//onItemClicked(ui.Replylistgroup->selectedItems()->at(0));
	SetShowMsg(ui.Replylistgroup->currentItem()->text());
	*/
}

void QuickReplyMsgDialog::onRightItemEntered( QListWidgetItem*item )
{
	QListWidget* psender = (QListWidget*)sender();
	
	if (psender==ui.ReplylistMsg)
	{
		QString strText = item->text();
		
	}
}
