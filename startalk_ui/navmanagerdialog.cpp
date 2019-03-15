#include "navmanagerdialog.h"
#include "ui_NavManagerDialog.h"
#include "addnavdialog.h"
#ifdef _WINDOWS
#include "QZXing.h"
#else
#include "../modules/QZxing/QZXing.h"
#endif
#include "Session.h"
#include "ConfigureHelper.h"
#include "AccountData.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "editablesettings.h"
#include "accountmanager.h"
#include "LoginParamSettingDialog.h"
#include "SystemConfigData.h"
#include "UiHelper.h"
#include "loginmanager.h"
#include "accountmanager.h"

NavManagerDialog::NavManagerDialog(QWidget *parent)
	: LocalManWidget(parent)
	,ui(new Ui::NavManagerDialog())
	,m_pLoginParamSettingDialog(NULL)
	,mLastTitle("")
	,mLastNav("")
	,mCurrentpitem(NULL)
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	//setAutoFillBackground(true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

	//ui->titlebar->setSizeable(false);
	connect(ui->titlebar, &TitlebarWidget::sgCloseOnClicked, this, &NavManagerDialog::onCloseclicked);
	connect(ui->listWidget, &QListWidget::itemClicked, this, &NavManagerDialog::onListWidgetItemClick);
	setWindowTitle(QStringLiteral("服务器配置"));
	ui->titlebar->setMinable(false);
	
	

// 	ui->label_NAV->setWordWrap(true); // 自动换行设置
// 	ui->label_NAV->setFixedWidth(210);
// 	ui->label_NAV->adjustSize();
	
	//暂时屏蔽“高级”按钮
	ui->pbt_adver->setVisible(false);

	ui->lineEdit_title->installEventFilter(this);
	ui->textEdit_nav->installEventFilter(this);
	
}

NavManagerDialog::~NavManagerDialog()
{

}

void NavManagerDialog::showNavManagerDialog()
{
	InitData();
	
	show();
	activateWindow();

	mLastNav = ui->textEdit_nav->toPlainText();
	mLastTitle = ui->lineEdit_title->text();
}

void NavManagerDialog::InitData()
{
	ui->listWidget->clear();
	
	ui->radbtn_xmpp->setChecked(!Biz::Session::getEditableSettings()->PbEnable());
	ui->radbtn_pb->setChecked(Biz::Session::getEditableSettings()->PbEnable());

	auto raidoChangeFun = [this](){


		bool bxmpp = ui->radbtn_xmpp->isChecked();
		bool bpb   = ui->radbtn_pb->isChecked();
		

		Biz::Session::getEditableSettings()->PbEnable(bpb);
		Biz::ConfigureHelper::saveEditSettings(*Biz::Session::getEditableSettings());
	};

	connect(ui->pbt_addNav, &QPushButton::clicked, this, &NavManagerDialog::onAddNav);

	connect(ui->pbt_deleteNav, &QPushButton::clicked, this, &NavManagerDialog::ondeleteNav);

	connect(ui->pbt_applyNav, &QPushButton::clicked, this, &NavManagerDialog::onApplyNav);

	connect(ui->pbt_adver, &QPushButton::clicked, this, &NavManagerDialog::onAdverClicked);

	connect(ui->pbt_selectnone,&QPushButton::clicked,this, &NavManagerDialog::onSelectNone);

	connect(ui->radbtn_xmpp ,&QRadioButton::clicked, raidoChangeFun);

	connect(ui->radbtn_pb  ,&QRadioButton::clicked, raidoChangeFun);
	LoadnavInfor();
}

void NavManagerDialog::LoadnavInfor()
{
	Biz::Session::loadNavConfigListInfo();

	QList <QSharedPointer<Biz::NavConfigInfo>> navlist = Biz::Session::getNavConfigInfolist();

	for(QSharedPointer<Biz::NavConfigInfo> oneaccount:navlist)
	{
		insertOneItem(oneaccount->title(), oneaccount->nav(), false);
	}

	int ncount = ui->listWidget->count();
	if (ncount >0)
	{
		if(mCurrentpitem != NULL)
		{
			ui->listWidget->setItemSelected(mCurrentpitem, true);
			onListWidgetItemClick(mCurrentpitem);
		}
		else
		{
			QListWidgetItem*pItem = ui->listWidget->item(0);
			ui->listWidget->setItemSelected(pItem, true);
			onListWidgetItemClick(pItem);
		}
		
	}
	else
	{
		showNormal();
		onAddNav();
	}
	
}

void NavManagerDialog::onAddNav()
{
	AddNavDialog *pdialog = AddNavDialogSingleton::getInstance();
	if (pdialog)
	{
	//	pdialog->showAddNavDialog();
		if (QDialog::Accepted == pdialog->exec())
		{
			QString strCompare = pdialog->getCompanyUrl();
			QString strNewNav;
			//这地方给判断一下，如果输入的是域名，则加在后面，如果输入的是https的，就原样保存
			if (strCompare.indexOf("https://",0, Qt::CaseInsensitive) == 0
				|| strCompare.indexOf("http://", 0, Qt::CaseInsensitive) == 0)
			{
				strNewNav = strCompare;
			}
			else
			{
				strNewNav = QString("https://qt.qunar.com/package/static/qtalk/publicnav?c=%1").arg(strCompare);
			}

			
// 			if (strTitle.isEmpty())
// 			{
// 				int ncount = ui->listWidget->count();
// 				strTitle = QStringLiteral("新添导航%1").arg(++ncount);
// 			}
			insertOneItem(strCompare, strNewNav);

		}
	}

}

void NavManagerDialog::ondeleteNav()
{
	QListWidgetItem *item = ui->listWidget->currentItem();
	if (item==NULL)
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("没有可删除项"));
		return;
	}
	int nIndex = ui->listWidget->currentRow();
	ui->listWidget->takeItem(nIndex);
	QString strUrl = item->data(ItemDataNavUrl).toString();


	Biz::Session::loadNavConfigListInfo();
 	QList<QSharedPointer<Biz::NavConfigInfo>> list = Biz::Session::getNavConfigInfolist();
	for (QSharedPointer<Biz::NavConfigInfo> oneaccount: list)
	{
		
		if (oneaccount->nav() == strUrl)
		{
			list.removeOne(oneaccount);
			break;
		}
	}


	Biz::Session::saveNavConfigListInfo(list);
	
	int ncount = ui->listWidget->count();
	if (ncount >= 1)
	{
		ui->listWidget->setCurrentRow( ncount-1 );
		//ui->listWidget->currentIndex();
		ui->listWidget->clicked(ui->listWidget->currentIndex());
		onApplyNav();
	}
	else
	{
		ui->lineEdit_title->setText("");
		ui->textEdit_nav->setPlainText("");
		ui->label_yu->setText("");
		ui->label_erCode->setPixmap(QPixmap(""));
		QString strNavUrl = ui->textEdit_nav->toPlainText();
		Biz::Session::getAccountManager()->accountData().NavAddr(strNavUrl);
		Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
		Biz::Session::saveLoginNavSetting ();

	}
}

void NavManagerDialog::onApplyNav()
{
	QString strNavUrl = ui->textEdit_nav->toPlainText();

	Biz::Session::getAccountManager()->accountData().NavAddr(strNavUrl);
	Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
	Biz::Session::saveLoginNavSetting ();

	if (strNavUrl.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("还未选中导航"));
		return;
	}

	

	this->close();

}

void NavManagerDialog::onCloseclicked()
{
	this->close();
}

void NavManagerDialog::insertOneItem( const QString&title, const QString& navurl,bool bsave )
{
	QString strhttpnav = Biz::Session::getLoginManager()->getNavConfig();

	QPixmap pixIcon(":/Images/icon/nav.png");
	if (navurl != strhttpnav)
	{
		
		QImage greyImg = pixIcon.toImage();
		MainApp::imageToGray(greyImg);
		pixIcon = QPixmap::fromImage(greyImg);
	}
	

	QListWidgetItem *pitem = new QListWidgetItem(QIcon(pixIcon), title, ui->listWidget);
	pitem->setData(ItemDataNavUrl, navurl);
	pitem->setData(ItemDataTitle, title);
	QUrl url(navurl);
	QUrlQuery query(url);

	QString strField = query.queryItemValue("c");
	if (strField.isEmpty())
	{
		//strField = "ejabhost1";
		strField = navurl;
	}
	pitem->setData(ItemDataField,strField);
	pitem->setSizeHint(QSize(180, 30));
	ui->listWidget->addItem(pitem);
	

	if (bsave)
	{
		saveChangeNavconfigInfor(title, strField, navurl);
	}
	

	//onListWidgetItemClick(pitem);

 	int ncount = ui->listWidget->count();
	ui->listWidget->setCurrentRow( ncount - 1 );
	
//	QModelIndex index = ui->listWidget->currentIndex();
	 ui->listWidget->clicked(ui->listWidget->currentIndex());


	if (pitem->data(ItemDataNavUrl).toString() == strhttpnav)
	{
		mCurrentpitem= pitem;
	}

}

void NavManagerDialog::onListWidgetItemClick(QListWidgetItem *item)
{
	QString strNvaurl = item->data(ItemDataNavUrl).toString();
	QString strTitle = item->data(ItemDataTitle).toString();
	QString strField =  item->data(ItemDataField).toString();

	
	//绘制右边的内容
 	ui->lineEdit_title->setText(strTitle);
	ui->lineEdit_title->setToolTip(strTitle);

	ui->textEdit_nav->setPlainText(strNvaurl);
	
	//
	ui->label_yu->setToolTip(strField);
	QFontMetrics elidyufont(ui->label_yu->font());
	QString elidedyuText = elidyufont.elidedText (strField, Qt::ElideRight, qMax(180,ui->label_yu->width()));
	ui->label_yu->setText(elidedyuText);

	

	QSize size = ui->label_erCode->geometry().size();
#if _DEBUG
#else
	QPixmap rcodePixmap = QZXing::encodeString(strNvaurl, size.width());
	rcodePixmap = QPixmap::fromImage(rcodePixmap.toImage().scaled(size));
	ui->label_erCode->setPixmap(rcodePixmap);
#endif

	mLastNav = strNvaurl;
	mLastTitle = strTitle;

}

// void NavManagerDialog::saveNavconfigInfor( const QString& navtitle, const QString& navurl )
// {
// 	QList <QSharedPointer<Biz::NavConfigInfo>> navlist = Biz::Session::getNavConfigInfolist();
// 
// 	//判断account.dat中有相关的数据
// 	bool bhaveIn = false; 
// 	if (navlist.length() > 0)
// 	{
// 		for(QSharedPointer<Biz::NavConfigInfo> oneaccount:navlist)
// 		{
// 			
// 			if (oneaccount->nav() == navurl)
// 			{
// 				bhaveIn = true;
// 				break;
// 			}
// 		}
// 	}
// 
// 	if (bhaveIn)
// 	{
// 		return;
// 	}
// 
// 	QSharedPointer<Biz::NavConfigInfo> account(new Biz::NavConfigInfo);
// 	account->ID(navlist.size() + 1);
// 	account->title(navtitle);
// 	account->nav(navurl);
// 	
// 	navlist.append(account);
// 	Biz::Session::saveNavConfigListInfo(navlist);
// }

void NavManagerDialog::onAdverClicked()
{
	if (NULL == m_pLoginParamSettingDialog)
	{
		m_pLoginParamSettingDialog = new LoginParamSettingDialog(this);
	}
	QPoint pos = this->pos();
	pos.setX(pos.x()+(this->width()-m_pLoginParamSettingDialog->width())/2);
	pos.setY(pos.y()+(this->height()-m_pLoginParamSettingDialog->height())/2);
	m_pLoginParamSettingDialog->autoshow(pos);
}

bool NavManagerDialog::eventFilter( QObject *obj, QEvent *event )
{
	if (event->type() == QEvent::FocusOut)
	{
		if (obj == ui->lineEdit_title)
		{
			QString title = ui->lineEdit_title->text();
			if (title.compare(mLastTitle, Qt::CaseInsensitive) != 0)
			{
				//更改这个展示
				ChangeValue(title, ui->label_yu->toolTip(), ui->textEdit_nav->toPlainText());
				ui->lineEdit_title->setToolTip(title);
				mLastTitle = title;
			}
			
			//return true;
		}

		if (obj == ui->textEdit_nav)
		{
			QString nav = ui->textEdit_nav->toPlainText();
			if (nav.compare(mLastNav,Qt::CaseInsensitive)!=0)
			{
				ChangeValue(ui->lineEdit_title->text(), ui->label_yu->toolTip(), nav);
				insertOneItem(ui->lineEdit_title->text(), nav);
				mLastNav = nav;

			}
			
			//return true;
		}
	}

	return LocalManWidget::eventFilter(obj,event);
}

void NavManagerDialog::ChangeValue(const QString&title, const QString& yu, const QString& nav)
{
	QListWidgetItem *pcurrentItem = ui->listWidget->currentItem();
	if (pcurrentItem)
	{
		pcurrentItem->setText(title);
		pcurrentItem->setData(ItemDataTitle, title);
		pcurrentItem->setData(ItemDataNavUrl, nav);

		saveChangeNavconfigInfor(title, yu, nav);
	}
}


void NavManagerDialog::saveChangeNavconfigInfor(const QString&navtitle, const QString& navyu, const QString& navurl)
{
	Biz::Session::loadNavConfigListInfo();
	QList <QSharedPointer<Biz::NavConfigInfo>> navlist = Biz::Session::getNavConfigInfolist();

	//判断account.dat中有相关的数据
	bool bhaveIn = false; 
	if (navlist.length() > 0)
	{
		for(QSharedPointer<Biz::NavConfigInfo> oneaccount:navlist)
		{

			if (oneaccount->nav() == navurl)
			{
				
				oneaccount->title(navtitle);
				
				oneaccount->yu(navyu);
				bhaveIn = true;
				break;
			}
		}
	}

	if (bhaveIn)
	{
		Biz::Session::saveNavConfigListInfo(navlist);
		return;
	}

	QSharedPointer<Biz::NavConfigInfo> account(new Biz::NavConfigInfo);
	account->ID(navlist.size() + 1);
	account->title(navtitle);
	account->nav(navurl);
	account->yu(navyu);

	navlist.append(account);
	Biz::Session::saveNavConfigListInfo(navlist);

	
}

void NavManagerDialog::onSelectNone()
{
	ui->lineEdit_title->setText("");
	ui->textEdit_nav->setPlainText("");
	ui->label_yu->setText("");
	ui->label_erCode->setPixmap(QPixmap(""));
	QString strNavUrl = ui->textEdit_nav->toPlainText();
	Biz::Session::getAccountManager()->accountData().NavAddr(strNavUrl);
	Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
	Biz::Session::saveLoginNavSetting ();

	mCurrentpitem= NULL;
	this->close();

}
