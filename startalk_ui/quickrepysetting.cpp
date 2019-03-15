#include "quickrepysetting.h"
#include "ConfigureHelper.h"

#include "quickreplyedititemdlg.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "QFileDialog"
#include "gloableeventobject.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "QuickReplyGroupMgr.h"
#include "QuickReplyMsgMgrV2.h"

QuickRepySetting* QuickRepySetting::pInstance=NULL;

QuickRepySetting::QuickRepySetting(QWidget *parent)
	: LocalManDialog(parent),strGroupItem(""),strItem("")
{
	ui.setupUi(this);
	
    mCallbackReceiver = new Biz::CallbackReceiver(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	//setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	
	setWindowTitle(QStringLiteral("编辑快捷回复"));

	auto titlebar = ui.TitleBar;
	titlebar->setSizeable(false);
	titlebar->setLeftTitle(QStringLiteral("编辑快捷回复"));
	titlebar->setMaxable(false);
	titlebar->setMinable(false);
	
	QStringList header1;
	header1 << QStringLiteral("组名");
	ui.QtableView_2->SetHeaderList(header1);

	QStringList header;
	header << QStringLiteral("内容");
	ui.QtableView->SetHeaderList(header);
	Init();
	int nwidth = ui.QtableView->width();
	ui.QtableView_2->head->resizeSection(0, 135);
	ui.QtableView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.QtableView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	ui.QtableView->head->resizeSection(0, 400);
	ui.QtableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &QuickRepySetting::onClose);
	connect(ui.pbAdd, &QPushButton::clicked, this, &QuickRepySetting::onAddItem);
	connect(ui.pbMody, &QPushButton::clicked, this, &QuickRepySetting::onModyItem);
	connect(ui.pbDelete, &QPushButton::clicked, this, &QuickRepySetting::onDeleteItem);
	connect(ui.pbMoveUp, &QPushButton::clicked, this, &QuickRepySetting::onContentMoveUp);
	connect(ui.pbMoveDown, &QPushButton::clicked, this, &QuickRepySetting::onContentMoveDown);
	connect(ui.pbOk, &QPushButton::clicked, this, &QuickRepySetting::onClickedOk);
	connect(ui.pbCancel, &QPushButton::clicked, this, &QuickRepySetting::onClickedCancel);
	//connect(ui.pbReply, &QPushButton::clicked, this, &QuickRepySetting::onClickedReply);
	
	connect(ui.pbAddGroup, &QPushButton::clicked, this, &QuickRepySetting::onClickedGroupMgr);
	
	connect(ui.QtableView_2, &QAbstractItemView::clicked, this, &QuickRepySetting::groupSelectChange); 
	connect(ui.QtableView, &QAbstractItemView::clicked, this, &QuickRepySetting::contentSelectChange);
	connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyGroupChange, this, &QuickRepySetting::quickReplyGroupDataChange);
	//connect(GloableEventObject::getInstance(), &GloableEventObject::sgQuickReplyContentChange, this, &QuickRepySetting::quickReplyContentDataChange);

}

QuickRepySetting::~QuickRepySetting()
{

}

void QuickRepySetting::quickReplyGroupDataChange() {
	ui.QtableView_2->clear();
	groupList = Biz::Session::getServiceManager()->getDaoService()->getQuickReplyGroupItems();
	for(QSharedPointer<Biz::QuickReplyGroup> groupInfo : groupList){ 
		QStringList strlist;
		strlist << groupInfo->GroupName();
		ui.QtableView_2->addRow(strlist);
	} 
}

void QuickRepySetting::quickReplyContentDataChange(const QString &groupCid) {
	ui.QtableView->clear(); 
	contentList = Biz::Session::getServiceManager()->getDaoService()->getQuickReplyContentItems(groupCid);
	for(QSharedPointer<Biz::QuickReplyContent> contentInfo : contentList){ 
		QStringList strlist;
		strlist << contentInfo->Content();
		ui.QtableView->addRow(strlist);
	}
}

void QuickRepySetting::groupSelectChange(const QModelIndex& index) {
	int groupRow = index.row(); 
	QSharedPointer<Biz::QuickReplyGroup> groupInfo = groupList.at(groupRow);
	quickReplyContentDataChange(groupInfo->GroupCId());
}

void QuickRepySetting::contentSelectChange(const QModelIndex& index) {

}

void QuickRepySetting::onClose()
{
	this->close();
}
QuickRepySetting* QuickRepySetting::Inistance()
{
	if (pInstance == NULL)
	{
		pInstance = new QuickRepySetting();
	}
	return pInstance;
}

void QuickRepySetting::ShowQuickReplySetting()
{
	showNormal();
	activateWindow();
}

void QuickRepySetting::Init()
{
	quickReplyGroupDataChange();
	ui.QtableView_2->setFocus();
	if (groupList.size() > 0)
	{
		ui.QtableView_2->selectRow(0); 
		QSharedPointer<Biz::QuickReplyGroup> groupInfo = groupList.at(0);
		quickReplyContentDataChange(groupInfo->GroupCId());
	}
	/*
	QList<QSharedPointer<Biz::QuickReplyContent>> contentList = Biz::Session::getServiceManager()->getDaoService()->getQuickReplyContentItems();
	for(QSharedPointer<Biz::QuickReplyContent> contentInfo : contentList){ 
		QStringList strlist;
		strlist << groupInfo->GroupName();
		ui.QtableView_2->addRow(strlist);
	}
	
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

	//QList<QuickReplyMsgItem*>& QuickmsgList = QuickReplyMsgMgr::GetInstance(strQuickReplyMsgFilePath)->getQuickReplyList();

	if (QuickmsgList.length()<=0)
	{
		return ;
	}
	QMap<QString, QStringList> groupContentMap;
	for (QuickReplyMsgItem *item: QuickmsgList)
	{

		if (!strAllGroups.contains(item->group))
		{
			strAllGroups.append(item->group);
			QStringList strlist1;
			strlist1 << item->group;
			ui.QtableView_2->addRow(strlist1);	
		}
		QStringList strlist;
		if (groupContentMap.contains(item -> group))
		{
			strlist = groupContentMap.value(item -> group);
		} else
		{
			groupContentMap.insert(item -> group, strlist);
		}
		strlist << item->content;
	} 
	*/
	
}

void QuickRepySetting::onAddItem()
{
	if (groupList.size() > 0)
	{
		QuickReplyEditItemDlg dlg(0, groupList); 
		QItemSelectionModel *groupSelect = ui.QtableView_2->selectionModel();
		int nGroupRow = 0;
		if (groupSelect->hasSelection()) { 
			nGroupRow = groupSelect->currentIndex().row();
			dlg.setSelectGroupIndex(nGroupRow);
		}
		if (dlg.exec() == QDialog::Accepted)
		{  
			QSharedPointer<Biz::QuickReplyGroup> groupInfo = groupList.at(nGroupRow);
			quickReplyContentDataChange(groupInfo->GroupCId());
		}  
	} else
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请先创建组，再添加内容"));
	}
	
}

void QuickRepySetting::onModyItem()
{
	QString strgroupitem;
	QString strTextContext;
	QModelIndexList groupIndexlist;
	QModelIndexList contentIndexlist; 
	QItemSelectionModel *groupSelect = ui.QtableView_2->selectionModel();
	QItemSelectionModel *contentSelect = ui.QtableView->selectionModel();
	if (groupSelect->hasSelection()&&contentSelect->hasSelection())
	{
		//groupIndexlist = groupSelect->selectedRows();
		//contentIndexlist = contentSelect->selectedRows(); 
		int nGroupRow = groupSelect->currentIndex().row();
		int nContentRow = contentSelect->currentIndex().row();
		//int nCol = select->currentIndex().column();
		QSharedPointer<Biz::QuickReplyContent> contentInfo = contentList.at(nContentRow); 
		QuickReplyEditItemDlg dlg(1, groupList);
		dlg.setSelectGroupIndex(nGroupRow);
		dlg.SetModyContent(contentInfo); 
		if (dlg.exec() == QDialog::Accepted)
		{  
			QSharedPointer<Biz::QuickReplyGroup> groupInfo = groupList.at(nGroupRow);
			quickReplyContentDataChange(groupInfo->GroupCId());
			ui.QtableView->selectRow(nContentRow);
		}
	}
	else
	{
		//QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请选中一行"));
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请选中要修改的一行"));
	}  
}

void QuickRepySetting::onDeleteItem()
{
	QItemSelectionModel *select = ui.QtableView->selectionModel();
	if (select->hasSelection())
	{
		int nContentRow = select->currentIndex().row();
		QSharedPointer<Biz::QuickReplyContent> contentInfo = contentList.at(nContentRow);
		int ret = Biz::Session::getServiceManager()->getDaoService()->signDeleteQuickReplyContent(contentInfo->ContentCId());
		if (ret ==1)
		{ 
			ui.QtableView->remove();
		} else
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("删除内容失败"));
		}
	}
	else
	{
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请选中要删除的一行"));
	}
}

void QuickRepySetting::onContentMoveUp() { 
	QItemSelectionModel *select = ui.QtableView->selectionModel();
	if (select->hasSelection())
	{
		int nContentRow = select->currentIndex().row();
		if (nContentRow <= 0)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("当前选择的内容已经是第一条"));
		} else
		{
			int prepContentRow = nContentRow - 1;
			QSharedPointer<Biz::QuickReplyContent> contentInfo = contentList.at(nContentRow);
			QSharedPointer<Biz::QuickReplyContent> prepContentInfo = contentList.at(prepContentRow);
			int currntSeq = contentInfo->ContentSeq();
			contentInfo->ContentSeq(prepContentInfo->ContentSeq());
			prepContentInfo->ContentSeq(currntSeq);
			QList<QSharedPointer<Biz::QuickReplyContent>> uContentList;
			uContentList.append(contentInfo);
			uContentList.append(prepContentInfo);
			bool ret = Biz::Session::getServiceManager()->getDaoService()->updateQuickReplyContentSeqs(uContentList);
			if (ret)
			{
				quickReplyContentDataChange(contentInfo->GroupCId());
				ui.QtableView->selectRow(prepContentRow);
				emit GloableEventObject::getInstance()->sgQuickReplyContentChange(contentInfo->GroupCId());
			} else
			{
				 MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("修改内容顺序失败"));
			}
		}
	} else {
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请选中要删除的一行"));
	}
}

void QuickRepySetting::onContentMoveDown() {
	QItemSelectionModel *select = ui.QtableView->selectionModel();
	if (select->hasSelection())
	{
		int nContentRow = select->currentIndex().row();
		if (nContentRow >= contentList.size()-1)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("当前选择的内容已经是第一条"));
		} else
		{
			int nextContentRow = nContentRow + 1;
			QSharedPointer<Biz::QuickReplyContent> contentInfo = contentList.at(nContentRow);
			QSharedPointer<Biz::QuickReplyContent> prepContentInfo = contentList.at(nextContentRow);
			int currntSeq = contentInfo->ContentSeq();
			contentInfo->ContentSeq(prepContentInfo->ContentSeq());
			prepContentInfo->ContentSeq(currntSeq);
			QList<QSharedPointer<Biz::QuickReplyContent>> uContentList;
			uContentList.append(contentInfo);
			uContentList.append(prepContentInfo);
			bool ret = Biz::Session::getServiceManager()->getDaoService()->updateQuickReplyContentSeqs(uContentList);
			if (ret)
			{
				quickReplyContentDataChange(contentInfo->GroupCId());
				ui.QtableView->selectRow(nextContentRow);
				emit GloableEventObject::getInstance()->sgQuickReplyContentChange(contentInfo->GroupCId());
			} else
			{
				 MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("修改内容顺序失败"));
			}
		}
	} else {
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请选中要删除的一行"));
	}
}

void QuickRepySetting::onExportReply()
{
	QList<QStringList> list = ui.QtableView->GetAllRowData();
	QString strDesk = Biz::ConfigureHelper::getDeskWindowPath() + "QuickReply.txt";
	strDesk = strDesk.replace("//","/");
	
	QString saveFileName = QFileDialog::getSaveFileName(0, "Save File", strDesk, "Txt(*.txt)");
	if (!saveFileName.isNull())
	{
		if (QFile::exists(saveFileName))
		{
			QFile::remove(saveFileName);
		}
		//写json文件
		WriteJsonText(list, saveFileName);


		saveFileName.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
		QProcess::startDetached("explorer /select," + saveFileName);
	}

}

void QuickRepySetting::onImportReply()
{
	QString fileName = QFileDialog::getOpenFileName(this,"","","Txt(*.txt)");
	if (!fileName.isNull())
	{
       QList<QuickReplyMsgItem*> list = ReadJsonText(fileName);
	   if (list.length()<=0)
	   {
		   return ;
	   }

	   for (QuickReplyMsgItem *item: list)
	   {
		   QStringList strlist;

		   if (!strAllGroups.contains(item->group))
		   {
			   strAllGroups.append(item->group);	
		   }

		   strlist << item->group << item->content;
		   ui.QtableView->addRow(strlist);
	   }

	}
}

void QuickRepySetting::onClickedOk()
{ 
	// 同步配置到服务器
	auto callback = mCallbackReceiver->createCallback<QMap<QString, QVariant>>(
		[this](const QMap<QString, QVariant> &result){  
			bool ret = result.value("ret").toBool();
			if (ret)
			{ 
				bool groupChange = result.value("groupChange").toBool();
				bool contentChange = result.value("contentChange").toBool();
				if (groupChange)
				{
					emit GloableEventObject::getInstance()->sgQuickReplyGroupChange();
				}
				if (contentChange)
				{
					emit GloableEventObject::getInstance()->sgQuickReplyAllContentChange();
				}
			} else
			{
				QString errMsg = result.value("errmsg").toString();
				MainApp::UIFrame::getNotifyCenterController ()->alertMessage (errMsg);
			}
		},[]{}); 
	QuickReplyMsgMgrV2::getInstance()->syncQuickReplyToRemote(callback); 
	this->close();
}

void QuickRepySetting::onClickedCancel()
{
	this->close();
}

void QuickRepySetting::onClickedGroupMgr()
{
	QuickReplyGroupMgr dlg(0); 
	if (dlg.exec() == QDialog::Accepted)
	{
		//QStringList strgroupItemContext;
		//dlg.getContent(strgroupItemContext);
		//ui.QtableView->addRow(strgroupItemContext);
	}
}

void QuickRepySetting::onClickedReply()
{
	//把界面上的数据写到文件中
	QList<QuickReplyMsgItem*> QuickmsgList;
	int nRow = ui.QtableView->rowCount();
	QList<QStringList> list = ui.QtableView->GetAllRowData();
	foreach (QStringList strlst, list)
	{
		QuickReplyMsgItem *item = new QuickReplyMsgItem;
		item->group = strlst.at(0);
		item->content = strlst.at(1);

		QuickmsgList.append(item);

	}
	QString strQuickReplyMsgFilePath
		= Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/" + "quickreplyu.xml";



	QString strappdataQuickReplyFilePath =  Biz::ConfigureHelper::QuickReplyListConfigurePath(Biz::Session::currentAccount().accountData().UserID());
	QuickReplyMsgMgr::GetInstance(strQuickReplyMsgFilePath)->SaveQuickReplyFile(strappdataQuickReplyFilePath, QuickmsgList);

	//
	emit GloableEventObject::getInstance()->sgQuickReplyUpdate(QuickmsgList);

}

void QuickRepySetting::WriteJsonText(const QList<QStringList>& list, const QString& strFilePath)
{
	QJsonObject obj;
	QJsonObject quickReply;
	QJsonArray Replyarry;
	
	foreach (QStringList strlst, list)
	{
		quickReply.insert("Group", strlst.at(0));
		quickReply.insert("content", strlst.at(1));
		Replyarry.append(quickReply);
	}
	obj.insert("data", Replyarry);
	QJsonDocument doc(obj);

	QString strjsData = QString::fromUtf8(doc.toJson());


	

	QFile file(strFilePath); 
	if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) 
	{ 
		return;
	} 
	QTextStream in(&file); 
	in<<strjsData<<"\n";
	file.close();

	//strDesk.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
	//QProcess::startDetached("explorer /select," + strDesk);
	
}


QList<QuickReplyMsgItem*> QuickRepySetting::ReadJsonText(const QString& strFilePath)
{
	QFile file(strFilePath);
	QList<QuickReplyMsgItem*> listmsg;
	if(file.open(QIODevice::ReadOnly | QIODevice::Text))  
	{  
	
		QByteArray line=file.readAll();
		QTextCodec* gbk_codec = QTextCodec::codecForName("GBK");
		QString gbk_string = gbk_codec->toUnicode(line);

		file.close();

		QByteArray arr = gbk_string.toUtf8();
		

		if (gbk_string.length()!=0)
		{
			
			
			QJsonDocument Json_Data = QJsonDocument::fromJson(arr);
			if(Json_Data.isObject())
			{
				
					QVariantMap result = Json_Data.toVariant().toMap();
					QVariantList resultList = result["data"].toList();
					for(QVariant item : resultList)
					{
						QuickReplyMsgItem * msgitem = new QuickReplyMsgItem;
						//memset(msgitem, 0, sizeof(QuickReplyMsgItem));
						QVariantMap mapItem = item.toMap();
						QString groupid = mapItem["Group"].toString();
						QString strcontent = mapItem["content"].toString();
						msgitem->group = groupid;
						msgitem->content = strcontent;
						listmsg.append(msgitem);
					}

				

			}
		}
		return listmsg;
	}
	else 
	return listmsg;

}
