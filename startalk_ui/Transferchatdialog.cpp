#include "Transferchatdialog.h"
#include "RosterList.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "CallbackReceiver.h"
#include "UserVcardManager.h"
#include "SystemConfigData.h"
#include "gloableeventobject.h"
#include "StaticData.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "UtilHelper.h"
#include "accountmanager.h"
#include "jsonobject/httpresult.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

TransferChatDialog* TransferChatDialog::pInstance = NULL;
TransferChatDialog::TransferChatDialog(const QString& userid,LocalManDialog *parent)
	: LocalManDialog(parent),nType(0),mStrclickedTreeText(""),strPeerid(""),mncount(0)
{
	ui.setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	mReceiver = new Biz::CallbackReceiver(this);

	connect(ui.btnClose, &QPushButton::clicked, this, [this](bool){this->close();});

	//initColleageTree();

	connect(ui.btnOk, &QPushButton::clicked, this, &TransferChatDialog::OnClickedBtnOk);
	connect(ui.treeWidget, &QTreeWidget::itemClicked, this, &TransferChatDialog::onTreeWidgetItemPress);
	connect(ui.btnCancle, &QPushButton::clicked, this, [this](bool){this->close();});
	setWindowTitle(QStringLiteral("转移会话"));
	connect(GloableEventObject::getInstance(),&GloableEventObject::sgHideMainWidge,this,&TransferChatDialog::onHideTransferDlg);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,this,&TransferChatDialog::onUpdateStatus);
	connect(ui.lineEdit, &QLineEdit::textChanged, this, &TransferChatDialog::onSearchShopInfo);
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgRecivedRetmsg, this, &TransferChatDialog::onRecivedRetMsg);
	createTree();
}

TransferChatDialog::~TransferChatDialog()
{

}

void TransferChatDialog::setType(TransferType ntype)
{
	nType = ntype;
	if (ntype == TransferType::TRANSFERNUM)
	{
		ui.label_6->setVisible(false);
		ui.lineEdit->setVisible(false);
		ui.label_title->setText(QStringLiteral("根据用户Id转移"));
		ui.stackedWidget->setCurrentIndex(0);
	}
	else if(ntype == TransferType::TRANSFERRELATION)
	{
		ui.label_title->setText(QStringLiteral("根据联系人转移"));
		ui.stackedWidget->setCurrentIndex(1);
	}
	else if (ntype == TransferType::TRANSFERCOLLEGA)
	{
		ui.label_6->setVisible(true);
		ui.lineEdit->setVisible(true);
		ui.label_title->setText(QStringLiteral("根据同事进行转移"));
		ui.stackedWidget->setCurrentIndex(2);
		
	}
}

void TransferChatDialog::initColleageTree()
{
// 	QString userid = Biz::Session::currentAccount().accountData().UserID();
// 	QList<Biz::RosterNode*> usernodes;
// 	Biz::Session::currentAccount().findRosterUsers(userid,usernodes,true);
// 	if (usernodes.length() == 0)
// 	{
// 		Log::e("Transferchatdialog find usernode fail " + userid);
// 		return;
// 	}
// 	Biz::RosterNode* pUserNodes = usernodes.at(0);
// 	Biz::RosterGroup* pGroup = pUserNodes->group;
// 
// 	QString groupName = pGroup->name;
// 
// 
// 	ui.treeWidget->setColumnCount(1); //设置列数
// 	ui.treeWidget->setHeaderLabel(QStringLiteral("选择要转移的同事")); //设置头的标题
// 
// 	QTreeWidgetItem *groupItem = new QTreeWidgetItem(ui.treeWidget,QStringList(groupName));
// 	//imageItem1->setIcon(0,QIcon("xxx.png"));
// 	groupItem->setIcon(0, QIcon(QPixmap(":/Images/branch-closed.png")));

    auto onlineCb = mReceiver->createCallback<QStringList>([this/*,pGroup,groupItem*/](const QStringList& ids){
		int a = 5;
		int b = 8;
        // 加人员
//         foreach(Biz::RosterNode* node,pGroup->getRosterListWithChildren()){
//             QString userid = node->userId;
//             QString userName = node->userId;
//             if ((node->status == 6 || Biz::Session::getUserVcardManager()->isUserOnline(userid))
//                 && userid != Biz::Session::currentAccount().accountData().QUserName() )
//             {
//                 QString strName = Biz::Session::currentAccount().getUserNameById(userid);
//                 if (strName.isEmpty())
//                 {
//                     strName = userid;
//                 }
//                 QTreeWidgetItem *groupItemchilder = new QTreeWidgetItem(groupItem,QStringList(strName)); //子节点1
//                 groupItem->addChild(groupItemchilder); //添加子节点
//             }
// 
//         }
// 
//         ui.treeWidget->expandAll();//展开所
    },[](){});

    Biz::Session::getUserVcardManager()->getOnlineUsers(onlineCb);
}


void TransferChatDialog::OnClickedBtnOk()
{
	QString strTransferToUserid;
	QString strTransferReson;
	if (nType == TransferType::TRANSFERNUM)
	{
		strTransferToUserid = ui.lineEdit_id->text();
		strTransferReson = ui.textEdit_resons->toPlainText();
	}
	else if (nType == TransferType::TRANSFERCOLLEGA)
	{
		
		strTransferToUserid = mStrclickedTreeId;
		strTransferReson = ui.textEdit_page2->toPlainText();
	}

	if (strTransferToUserid.isEmpty())
	{
	
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("用户Id不能为空"));
		return;
	}
	if (strTransferReson.isEmpty())
	{
		
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("转移原因不能为空"));
		return;
	}
	bool bretConsult = UtilHelper::isVirtualAccountId(strPeerid, Biz::Session::getSystemConfig()->getXmppDomain());//是是否consult类型的
	if (!bretConsult) 
	{

		QJsonObject obj;
		obj.insert("TransId", strTransferToUserid/*strPeerid*/);
		obj.insert("TransReson", strTransferReson);

		QJsonDocument doc(obj);

		auto a = doc.toJson().simplified();
		QString content = QString::fromUtf8(doc.toJson());

		QJsonObject objshop;
		objshop.insert("u", strPeerid);
		objshop.insert("d", Biz::Session::getSystemConfig()->getXmppDomain());
		objshop.insert("f", Biz::Session::currentAccount().accountData().UserID());
		objshop.insert("r", strTransferReson);
		QJsonDocument docshop(objshop);
		QString contentshop = QString::fromUtf8(docshop.toJson(QJsonDocument::Compact));

		//转移给webchat
		SendTransferMsgold(strPeerid, content, strTransferToUserid);
		//发消息给同事
		SendTransferMsgold(strTransferToUserid, contentshop);

	}
	else
	{
		

		QJsonObject objshop;
		if (UtilHelper::isVirtualAccountId(strPeerid, Biz::Session::getSystemConfig()->getXmppDomain()))
		{
			objshop.insert("u", UtilHelper::getRealIdfromID(strPeerid));//
		}
		else
		{
			objshop.insert("u", strPeerid);//
		}

		objshop.insert("d", Biz::Session::getSystemConfig()->getXmppDomain());
		objshop.insert("f", Biz::Session::currentAccount().accountData().UserID());
		objshop.insert("r", strTransferReson);
		objshop.insert("toId", MainApp::UIFrame::getConversationController()->getvraccountbychating(strPeerid));
		//增加一个id值
		QString uuidshop = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");;
		objshop.insert("retId", uuidshop); //一个值
		objshop.insert("rt", strTransferToUserid);
		
		QJsonDocument docshop(objshop);
		QString contentshop = QString::fromUtf8(docshop.toJson(QJsonDocument::Compact));

		
		//发消息给同事
		SendTransferMsg(strTransferToUserid, contentshop);
		//上报事件
		Biz::StaticData::reportTakeTimeEvent("90005",1,"Transfer");

		
		//转移给webchat 只有在收到了同事的回馈，才给发送webchat
		//SendTransferMsg(strPeerid, content, strTransferToUserid);

	
// 		QString peerid = MainApp::UIFrame::getConversationController()->getvraccountbychating(strPeerid);
// 		QString conversationId = strPeerid;
// 		QTimeLine* pTimeLine = new QTimeLine(5000);
// 		connect(pTimeLine,&QTimeLine::finished,[pTimeLine,peerid,strTransferToUserid, conversationId, this]{
// 			pTimeLine->deleteLater();
// 			bool shopvalue = MainApp::UIFrame::getConversationController()->getTransferShopValuebyId(conversationId);
// 			bool Visitorvalue = MainApp::UIFrame::getConversationController()->getTransferVisitorValuebyId(conversationId);
// 			MainApp::UIFrame::getConversationController()->sgTransferResult(conversationId, strTransferToUserid,shopvalue, Biz::ReplayShop);
// 			MainApp::UIFrame::getConversationController()->sgTransferResult(conversationId, strTransferToUserid,Visitorvalue, Biz::ReplayVisitor);
// 
// 			//最后判断一下，给webchat的和客户端的是否都发成功了
// 			if (shopvalue && Visitorvalue )
// 			{
// 				//关闭会话框
// 				MainApp::UIFrame::getConversationController()->removeConversation(/*peerid*/conversationId);
// 				Biz::Session::getConverSationManager()->removeChartingImSession(/*peerid*/conversationId);
// 			}
// 		});
// 		pTimeLine->start();
	}
}

void TransferChatDialog::onTreeWidgetItemPress( QTreeWidgetItem *item, int column )
{
	QTreeWidgetItem *parentItem = item->parent();
	if (parentItem != NULL) //点击的是子树
	{
		mStrclickedTreeText = item->text(column);
		int n = parentItem->indexOfChild(item);
		
		mStrclickedTreeId = item->data(n, Qt::UserRole + 1).toString();
	}
	else //点击的是根
	{
		QString strclick = item->text(column);
		QString idkey = item->data(0, Qt::UserRole + 1).toString();
		//根据信息进行查找，该id下的在线的人有哪些

		getOrganizationbyId(item, idkey);


	}
}

void TransferChatDialog::SendTransferMsg(const QString &strid,const QString& strcontent, const QString& strcolleage)
{
	QString strTo = MainApp::UIFrame::getConversationController()->getvraccountbychating(strid);
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(/*strid*/strTo));
	message->MsgSourceType(Biz::consult);
    message->MsgDirection(Biz::MessageTypeSelf);
	message->Body(strcontent);
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->Chatid(chatid.toLongLong());
	message->MediaType(Biz::MediaTypeTransVisitor);

	//
	if (UtilHelper::isVirtualAccountId(strid, Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		message->Realto(Biz::MessageUtil::makeSureUserJid(UtilHelper::getRealIdfromID(strid)) );
	}
	else
	{
		message->Realto(Biz::MessageUtil::makeSureUserJid(strid) );
	}
	
	message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
	message->qchatid(Biz::consultmsgType::OnDutyToVistor);
	message->virtualId(strTo);
	message->from(Biz::Session::currentAccount().accountData().UserID());
	message->cctext(m_cctext);
	message->bu(m_bu);
	auto callback = mReceiver->createCallback([this,strid, message, strcolleage]()
	{
		//提示信息，显示该消息转移
		//emit Biz::Session::currentAccount().sgTransferResultInfor(message);
		this->hide();

	}, [this, strcolleage]{
	//	emit Biz::Session::currentAccount().sgTransferFailInfor(strcolleage);
	});
	Biz::Session::currentAccount().doSendMessage(message, callback,NULL);
}

void TransferChatDialog::SendTransferMsg( const QString &strid,const QString& strcontent )
{
	QString strTo = MainApp::UIFrame::getConversationController()->getvraccountbychating(strPeerid);
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(/*strid*/strTo));
	message->MsgSourceType(Biz::consult);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->Body(strcontent);
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->Chatid(chatid.toLongLong());
	message->MediaType(Biz::MediaTypeTransShop);
	message->Realto(strid);
	message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
	message->qchatid(Biz::consultmsgType::OnDutyToVistor);
	message->ExtendInfo(strcontent);
	message->virtualId(strTo);
	message->from(Biz::Session::currentAccount().accountData().UserID());
	message->cctext(m_cctext);
	message->bu(m_bu);
	auto callback = mReceiver->createCallback([this,strid, message]()
	{
		
	}, [this]{

	});
	Biz::Session::currentAccount().doSendMessage(message, callback,NULL);
	
}

void TransferChatDialog::timerEvent( QTimerEvent * event)
{
// 	if (mTimerId == event->timerId())
// 	{
// 		if (mncount < 4 && )
// 		{
// 			killTimer(mTimerId);
// 			//
// 		}
// 
// 		++mTimerId;
// 
// 	}
}


void TransferChatDialog::setPeerid( const QString& strPid )
{
	if (!strPid.isEmpty())
	{
		strPeerid = strPid;
	}
	
}

void TransferChatDialog::setChatid( const QString&strchatid )
{
	chatid = strchatid;
}

void TransferChatDialog::setcctext( const QString& cctext )
{
	m_cctext = cctext;
}

void TransferChatDialog::setbu( const QString&bu )
{
	m_bu = bu;
}

TransferChatDialog* TransferChatDialog::instance( const QString& userid )
{
	if (pInstance==NULL)
	{
		pInstance = new TransferChatDialog(userid);
	}
	return pInstance;
}

void TransferChatDialog::showTransferDlg( )
{
	showNormal();
	activateWindow();

	initColleageTree();
}

void TransferChatDialog::onHideTransferDlg()
{
	this->hide();
}

void TransferChatDialog::onUpdateStatus( const QStringList& onlineUsers )
{
	ui.treeWidget->clear();
	QString userid = Biz::Session::currentAccount().accountData().UserID();
	QList<Biz::RosterNode*> usernodes;
	Biz::Session::currentAccount().findRosterUsers(userid,usernodes,true);
	if (usernodes.length() == 0)
	{
		Log::e("Transferchatdialog find usernode fail " + userid);
		return;
	}
	int ncount = usernodes.count();
	for (int nI = 0; nI < usernodes.count(); nI++)
	{

	
	Biz::RosterNode* pUserNodes = usernodes.at(nI);
	Biz::RosterGroup* pGroup = pUserNodes->group;

	QString groupName = pGroup->name;
	ui.treeWidget->setColumnCount(1); //设置列数
	ui.treeWidget->setHeaderLabel(QStringLiteral("选择要转移的同事")); //设置头的标题
	QTreeWidgetItem *groupItem = new QTreeWidgetItem(ui.treeWidget,QStringList(groupName));
	groupItem->setIcon(0, QIcon(QPixmap(":/Images/branch-closed.png")));

	foreach(Biz::RosterNode* node,pGroup->getRosterListWithChildren()){
		QString userid = node->userId;
		QString userDisplayName = node->displayName;
 		if ((node->status == 6 || Biz::Session::getUserVcardManager()->isUserOnline(Biz::MessageUtil::makeSureUserJid(userid)))
			&& userid != Biz::Session::currentAccount().accountData().UserID() )
		{
		
 			int nchildercount = groupItem->childCount();
			if (nchildercount == 0)
			{
				QTreeWidgetItem *groupItemchilder = new QTreeWidgetItem(groupItem,QStringList(userDisplayName)); //子节点1
				groupItemchilder->setData(nchildercount, Qt::UserRole + 1, userid);
				groupItem->addChild(groupItemchilder); //添加子节点
				
			}
			else 
			{
				QString strName = Biz::Session::currentAccount().getUserNameById(userid);
				if (strName.isEmpty())
				{
					strName = userid;
				}
				bool bret = false;
				int ncount = 0;
				for (int nI = 0; nI < nchildercount; nI ++  )
				{
					QTreeWidgetItem * childItem = groupItem->child(nI);
					QString strNewText = childItem->text(0);
					if(strName == strNewText)
					{
						bret= true;
						break;
					}
					
				}
				if (!bret)
				{
					QTreeWidgetItem *groupItemchilder = new QTreeWidgetItem(groupItem,QStringList(strName)); //子节点1
					groupItemchilder->setData(nchildercount, Qt::UserRole + 1, userid);
					groupItem->addChild(groupItemchilder); //添加子节点
					
				}

			}
			
			
		}

	}

	ui.treeWidget->expandAll();//展开所
	}
}

void TransferChatDialog::createTree()
{
	QString userid = Biz::Session::currentAccount().accountData().UserID();
	QList<Biz::RosterNode*> usernodes;
	Biz::Session::currentAccount().findRosterUsers(userid,usernodes,true);
	if (usernodes.length() == 0)
	{
		Log::e("Transferchatdialog find usernode fail " + userid);
		return;
	}
	for (int nI = 0; nI < usernodes.count(); nI++)
	{


		Biz::RosterNode* pUserNodes = usernodes.at(nI);
		Biz::RosterGroup* pGroup = pUserNodes->group;

		QString groupName = pGroup->name;
		ui.treeWidget->setColumnCount(1); //设置列数
		ui.treeWidget->setHeaderLabel(QStringLiteral("选择要转移的同事")); //设置头的标题
		groupItem = new QTreeWidgetItem(ui.treeWidget,QStringList(groupName));
		groupItem->setIcon(0, QIcon(QPixmap(":/Images/branch-closed.png")));
	}
}

void TransferChatDialog::SendTransferMsgold( const QString &strid,const QString& strcontent, const QString& strcolleage )
{
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(strid));
	message->MsgSourceType(Biz::Trans);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->Body(strcontent);
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->Chatid(chatid.toLongLong());
	message->MediaType(Biz::MediaTypeTransVisitor);
	message->autoReply(true);
	message->cctext(m_cctext);
	message->bu(m_bu);
	auto callback = mReceiver->createCallback([this,strid, message, strcolleage]()
	{
		//提示信息，显示该消息转移
		emit Biz::Session::currentAccount().sgTransferResultInfor(message);
		this->hide();

	}, [this, strcolleage]{
		emit Biz::Session::currentAccount().sgTransferFailInfor(strcolleage);
	});
	Biz::Session::currentAccount().doSendMessage(message, callback,NULL);
}

void TransferChatDialog::SendTransferMsgold( const QString &strid,const QString& strcontent )
{
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(strid));
	message->MsgSourceType(Biz::Trans);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->Body(strcontent);
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->Chatid(chatid.toLongLong());
	message->MediaType(Biz::MediaTypeTransShop);

	message->ExtendInfo(strcontent);
	message->cctext(m_cctext);
	message->bu(m_bu);
	auto callback = mReceiver->createCallback([this,strid, message]()
	{

	}, []{});
	Biz::Session::currentAccount().doSendMessage(message, callback,NULL);
}

void TransferChatDialog::onSearchShopInfo( const QString&text )
{
	if (text.length() <=0)
	{
		initColleageTree();
		return;
	}

	auto searchFunc = [this, text]
	{

		auto callback = mReceiver->createCallback<QString>([this](const QString& ret)
		{
			Biz::ShopInforResponce resultJson;
			resultJson.unserializeFromString(ret);
			bool bRet = resultJson.ret();
			if (!bRet)
			{
				initColleageTree();
			}
			else
			{
				int nsize = resultJson.data().size();
				if(nsize >0)
				{
					mSearchShopmap.clear();
					for (IJsonSerializeable* pitem : resultJson.data ())
					{
						Biz::ShopInfoDetail* pOrder = (Biz::ShopInfoDetail*)(pitem);
						mSearchShopmap.insert(pOrder->id(), pOrder->name());
					}
					createBindTree();
				}
				else
				{
					initColleageTree();
				}


			}


		}, [this]{});

		Biz::Session::getAccountManager()->getShopInfo(text, callback);

	};

	if (text.length()<3) 
	{
		QTimeLine* pTimeLine = new QTimeLine(300);
		connect(pTimeLine,&QTimeLine::finished,[this,text,pTimeLine,searchFunc]{
			pTimeLine->deleteLater();
			QString strCurentText = ui.lineEdit->text();
			if (strCurentText == text)
				searchFunc();
		});
		pTimeLine->start();
	}
	else
	{
		searchFunc();
	}
}

void TransferChatDialog::createBindTree()
{
	ui.treeWidget->clear();
	QString userid = Biz::Session::currentAccount().accountData().UserID();
	int nsize = mSearchShopmap.count();
	if (nsize == 0)
	{
		Log::e("Transferchatdialog tree is empty " + userid);
		initColleageTree();
		return;
	}
	
	for (QString onekey: mSearchShopmap.keys())
	{
		QString groupName = mSearchShopmap.value(onekey);
		ui.treeWidget->setColumnCount(1); //设置列数
		ui.treeWidget->setHeaderLabel(QStringLiteral("选择要转移的同事")); //设置头的标题
		QTreeWidgetItem *groupItem = new QTreeWidgetItem(ui.treeWidget,QStringList(groupName));
		groupItem->setData(0, Qt::UserRole + 1, onekey);
		groupItem->setIcon(0, QIcon(QPixmap(":/Images/branch-closed.png")));
	}
}

void TransferChatDialog::getOrganizationbyId(QTreeWidgetItem *item, const QString& id )
{
	auto callback = mReceiver->createCallback<QString>([this, item](const QString& ret)
	{
		Biz::MemberResponce resultJson;
		resultJson.unserializeFromString(ret);
		bool bRet = resultJson.ret();
		if (!bRet)
		{
			initColleageTree();
		}
		else
		{
			int nsize = resultJson.data().size();
			if(nsize >0)
			{
				mMembermap.clear();
				for (IJsonSerializeable* pitem : resultJson.data ())
				{
					Biz::OneMemberDetail* pOrder = (Biz::OneMemberDetail*)(pitem);
					
					QString strNameOfOnline;
					QString webname = pOrder->W();
					if (webname.isEmpty())
					{
						webname = pOrder->N();
					}
					if (pOrder->O().compare("online", Qt::CaseInsensitive) == 0)
					{
						strNameOfOnline = QStringLiteral("%1 (在线)").arg(webname);
					}
					else 
					{
						strNameOfOnline = QStringLiteral("%1 (离线)").arg(webname);
					}
					mMembermap.insert(pOrder->U(), strNameOfOnline);


				}
				createAddChrildTree(item);
			}
			else
			{
				initColleageTree();
			}


		}


	}, [this]{

	});

	if (id.isEmpty())
	{
		initColleageTree();
	}
	else
		Biz::Session::getAccountManager()->getOriganizeByShopId(id.toLong(), callback);
}

void TransferChatDialog::createAddChrildTree( QTreeWidgetItem*item )
{
	for(QString onekey:mMembermap.keys()){
		QString userid = onekey;
		QString userDisplayName = mMembermap.value(onekey);
		if (userid != Biz::Session::currentAccount().accountData().UserID() )
		{

			int nchildercount = item->childCount();
			if (nchildercount == 0)
			{
				QTreeWidgetItem *groupItemchilder = new QTreeWidgetItem(item,QStringList(userDisplayName)); //子节点1
				groupItemchilder->setData(nchildercount, Qt::UserRole + 1, userid);
				item->addChild(groupItemchilder); //添加子节点

			}
			else 
			{
				bool bret = false;
				int ncount = 0;
				for (int nI = 0; nI < nchildercount; nI ++  )
				{
					QTreeWidgetItem * childItem = item->child(nI);
					QString strNewText = childItem->text(0);
					if(userDisplayName == strNewText)
					{
						bret= true;
						break;
					}

				}
				if (!bret)
				{
					QTreeWidgetItem *groupItemchilder = new QTreeWidgetItem(item,QStringList(userDisplayName)); //子节点1
					groupItemchilder->setData(nchildercount, Qt::UserRole + 1, userid);
					item->addChild(groupItemchilder); //添加子节点

				}

			}


		}

	}

	ui.treeWidget->expandAll();//展开所
}

void TransferChatDialog::setTransInfo( const QString& productId, const QString& businessId )
{
	mProductId = productId;
	mBusinessline = businessId;
}

//收到BClient 的回馈后，给webchat 发送转移的消息
void TransferChatDialog::onRecivedRetMsg( const QString& from, int type)
{
	if (type == Biz::TransReply::ReplayShop)
	{
		QString strTransferToUserid;
		QString strTransferReson;
		if (nType == TransferType::TRANSFERNUM)
		{
			strTransferToUserid = ui.lineEdit_id->text();
			strTransferReson = ui.textEdit_resons->toPlainText();
		}
		else if (nType == TransferType::TRANSFERCOLLEGA)
		{
			strTransferToUserid = mStrclickedTreeId;
			strTransferReson = ui.textEdit_page2->toPlainText();
		}

		QJsonObject obj;
		obj.insert("realtoId", strTransferToUserid);
		obj.insert("TransReson", strTransferReson);
		obj.insert("toId", MainApp::UIFrame::getConversationController()->getvraccountbychating(from));//
		obj.insert("realtoIdNickName", Biz::Session::getUserVcardManager()->getUserNameByConversationId(strTransferToUserid));
		obj.insert("realfromIdNickName", Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::Session::currentAccount().accountData().UserID()));
		//增加一个id值
		QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");;
		obj.insert("retId", uuid); //一个值
		QJsonDocument doc(obj);

		auto a = doc.toJson().simplified();
		QString content = QString::fromUtf8(doc.toJson());


		//转移给webchat
		SendTransferMsg(from, content, strTransferToUserid);

		//这个时候，调用茵梦接口给同事发送note消息
		QString strcolleageId = UtilHelper::getRealIdfromID(from);
		QString uid = UtilHelper::getvirtualfromID(from);
		QString strwebId = UtilHelper::getRealIdfromID(from);
		Biz::Session::getAccountManager()->sendNote(strTransferToUserid, strwebId,  uid, mProductId, mBusinessline);
	}

}