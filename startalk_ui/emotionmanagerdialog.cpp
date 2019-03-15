#include "emotionmanagerdialog.h"
#include "ui_EmotionManagerDialog.h"
#include "Session.h"
#include "EmotionManager.h"
#include <QGridLayout>
#include "diywidgit/customviews/DrawablePushbutton.h"
#include "QFileDialog"
#include "EmotionDialog.h"
#include "SystemDefine.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "SettingData.h"


const static QString innerId1 = "emotqq";
const static QString innerId2 = "xxxxx";



EmotionManagerDialog* EmotionManagerDialog::instance = NULL;
EmotionManagerDialog::EmotionManagerDialog(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::EmotionManagerDialog())
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
	connect(ui->titlebar, &TitlebarWidget::sgCloseOnClicked, this, &EmotionManagerDialog::onCloseclicked);
	setWindowTitle("EmotionManager");
	ui->titlebar->setMinable(false);
	QTabBar *tabar = ui->tabWidget->tabBar();
	tabar->setCurrentIndex(0);
	initUi();
}

EmotionManagerDialog::~EmotionManagerDialog()
{

}

EmotionManagerDialog* EmotionManagerDialog::getInstance()
{
	if(instance== NULL)
	{
		instance = new EmotionManagerDialog(NULL);

	}
	return instance;
}

void EmotionManagerDialog::onCloseclicked()
{
	this->close();
}

void EmotionManagerDialog::initUi()
{
	ui->addSaveEmotionBtn->setEnabled(false);
	ui->deleteSaveEmotionBtn->setEnabled(true);
	//对tab的点击
	connect(ui->tabWidget, &QTabWidget::tabBarClicked, this, &EmotionManagerDialog::onTabBarClicked);
	//对操作按钮的点击
	connect(ui->addSaveEmotionBtn, &QPushButton::clicked, this, &EmotionManagerDialog::onAddSaveEmotionBtnClicked);
	connect(ui->deleteSaveEmotionBtn, &QPushButton::clicked, this, &EmotionManagerDialog::onDeleteSaveEmotionBtnClicked);
	connect(ui->downloadBtn, &QPushButton::clicked, this, &EmotionManagerDialog::onDownloadBtnClicked);
	connect(ui->listWidget_local, &QListWidget::currentItemChanged, this, &EmotionManagerDialog::onCurrentItemChange);
	connect(ui->listWidget_server, &QListWidget::currentItemChanged, this, &EmotionManagerDialog::onCurrentItemServerChange);
	connect(ui->listWidget_local, &QListWidget::itemClicked, this, &EmotionManagerDialog::onCurrentItemClicked);
	//初始化数据
	//InitLocalData();
	InitServerData();
}

void EmotionManagerDialog::onTabBarClicked( int index )
{
	if (index == 1)
	{
		disconnect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgEmotionInfoListRecvied,this,&EmotionManagerDialog::onManagerEmotionInfoListRecvied);
		connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgEmotionInfoListRecvied,this,&EmotionManagerDialog::onManagerEmotionInfoListRecvied);
		Biz::Session::getEmoticonManager()->getEmotionsPackages();
	}
	if (index == 0)
	{
		ui->listWidget_local->setCurrentRow(0);

		QModelIndex index = ui->listWidget_local->currentIndex();
		ui->listWidget_local->clicked(index);
	}
	QTabBar *tabar = ui->tabWidget->tabBar();
	tabar->setCurrentIndex(index);
}

void EmotionManagerDialog::onAddSaveEmotionBtnClicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,"","","Images(*.png *.jpeg *.jpg *.tiff *.gif)");
	if (!fileName.isNull())
	{
		QString imgPath = fileName;
		
		if (QFile::exists(imgPath)) //存在
		{

			QFileInfo infor(imgPath);
			if ( (infor.suffix().compare("gif", Qt::CaseInsensitive) == 0) &&  infor.size() > SizeOfGifImage )
			{
				MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("上传的gif图片不能大于1M"));
				return;
			}


			Biz::Session::getEmoticonManager()->saveCustomEmojicon(imgPath);


			connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgReloadEmojiconPackage,this,&EmotionManagerDialog::onReloadEmojiconPackage);

// 			connect(Biz::Session::getEmoticonManager(), &Biz::EmotionManager::sgReloadEmojiconPackage, [this](const QString& pkgi){
// 				if (m_locallistwidget.contains(pkgi))
// 				{
// 					QListWidgetItem *pItem = ui->listWidget_local->currentItem();
// 					if (pItem!= NULL)
// 					{
// 						onCurrentItemChange(pItem, NULL);
// 
// 					}
// 				}
// 
// 			} );



		}
	}
}

void EmotionManagerDialog::onDeleteSaveEmotionBtnClicked()
{
	QListWidgetItem *pItem = ui->listWidget_local->currentItem();
	if (pItem == NULL)
	{
		return;
	}
	int nrow = ui->listWidget_local->row(pItem);
	QString pkgi = pItem->data(Qt::UserRole).toString();
	if (pkgi.isEmpty())
	{
		return;
	}
	if (m_locallistwidget.contains(pkgi))
	{
		if(mapEmoticonManagerDialogs.contains(pkgi))
		{
			EmotionDialog *pEmotiondlg = mapEmoticonManagerDialogs.value(pkgi);
			if (pEmotiondlg)
			{

				if ( pkgi == Biz::EmotionManager::sCustomPackageName)
				{
					pEmotiondlg->deleteEmotionPkgIcons(pkgi);	
				}
				else
				{
					//当前页面中删除掉
					ui->listWidget_local->takeItem(nrow);
					mapEmoticonManagerDialogs.remove(pkgi);
					ui->stackedWidget_local->removeWidget(pEmotiondlg);

					Biz::Session::getEmoticonManager()->setDeletePackage(pkgi);
				}
				
				emit Biz::Session::getEmoticonManager()->sgDeleteCustomerEmotion(pkgi);
				
				
			}
		}
	}
}

void EmotionManagerDialog::onDownloadBtnClicked()
{
	Biz::Session::getEmoticonManager()->downloadEmotionsPackage(spDownloadinfo);
}

void EmotionManagerDialog::InitLocalData()
{
	// 获取自己下载的表情包id
	QStringList list = Biz::Session::getEmoticonManager()->getEmoticonIds();
	for (QString pid:list)
	{
		addOneEmotionPackage(pid, ui->listWidget_local);
	}
	ui->listWidget_local->setCurrentRow(0);
}

void EmotionManagerDialog::InitServerData()
{
	//获取服务器上的表情包
	QStringList list = Biz::Session::getEmoticonManager()->getEmoticonIds();
	for (QString pid:list)
	{
		addOneEmotionPackage(pid, ui->listWidget_server);
	}
	ui->listWidget_server->setCurrentRow(0);

}

void EmotionManagerDialog::addOneEmotionPackage( const QString& pkgid, QListWidget*listwidget )
{
	QListWidgetItem * listwidgetitem = NULL;
	do 
	{
		QSharedPointer<Biz::EmoticonPackage> spPackage = Biz::Session::getEmoticonManager()->getEmotionPackageInfo(pkgid);
		if (!spPackage.isNull())
		{
			if (spPackage->strPackageId == Biz::EmotionManager::sCustomPackageName)
			{
				QPixmap couver(":Images/custom_emoj_btn.png");
				
				couver.setDevicePixelRatio(1.0);

				
				
				listwidgetitem = new QListWidgetItem(QIcon(couver.scaled(QSize(30, 30))), QStringLiteral("表情"));
				listwidget->setIconSize(QSize(30, 30));
				listwidgetitem->setSizeHint(QSize(130, 35));
				
				listwidgetitem->setData(Qt::DisplayRole, QStringLiteral("自定义表情"));
				listwidgetitem->setData(Qt::UserRole, pkgid);
				
				if (listwidget == ui->listWidget_local && !m_locallistwidget.contains(pkgid))
				{
					listwidget->addItem(listwidgetitem);
					m_locallistwidget.push_back(pkgid);
				}
				if (listwidget == ui->listWidget_server && !m_Serverlistwidget.contains(pkgid))
				{
					listwidget->addItem(listwidgetitem);
					m_Serverlistwidget.push_back(pkgid);
				}
				
				break;
			}
			QSharedPointer<Biz::EmotionItem> spItem = spPackage->packageCoverImg;
			if (spItem.isNull() && spPackage->emotionList.size()>0)
			{
				spItem = spPackage->emotionList.at(0);
			}

			if (!spItem.isNull())
			{
				QPixmap couver(spItem->strPath);
				if (!couver.isNull())
				{
					couver.setDevicePixelRatio(1.0);
					
					
					listwidgetitem = new QListWidgetItem(QIcon(couver.scaled(QSize(30, 30))), pkgid);
					listwidget->setIconSize(QSize(30, 30));
					listwidgetitem->setSizeHint(QSize(130, 35));
					listwidgetitem->setData(Qt::UserRole, pkgid);
					listwidgetitem->setData(Qt::DisplayRole, spPackage->strPackageDesc);
					if (listwidget == ui->listWidget_local && !m_locallistwidget.contains(pkgid))
					{
						listwidget->addItem(listwidgetitem);
						m_locallistwidget.push_back(pkgid);
					}
					if (listwidget == ui->listWidget_server && !m_Serverlistwidget.contains(pkgid))
					{
						listwidget->addItem(listwidgetitem);
						m_Serverlistwidget.push_back(pkgid);
					}
					
					break;
				}
			}
		}
		
	} while (false);

}

void EmotionManagerDialog::onCurrentItemChange(QListWidgetItem * item, QListWidgetItem*preitem)
{
	if (NULL == item)
		return;
	QString stritemtext = item->data(Qt::UserRole).toString();
	if (stritemtext.isEmpty())
	{
		return;
	}
	bool bEnable = (stritemtext == Biz::EmotionManager::sCustomPackageName)?true:false;
	
	
	
	ui->addSaveEmotionBtn->setEnabled(bEnable);
	ui->addSaveEmotionBtn->setVisible(bEnable);
	//ui->deleteSaveEmotionBtn->setEnabled(bEnable);
	
	const QList<QSharedPointer<Biz::EmotionItem>>& emotionList = Biz::Session::getEmoticonManager()->getEmotionList(stritemtext);
	int nemotionlenght = emotionList.size();


	//
	if (!mapEmoticonManagerDialogs.contains(stritemtext))
	{
		EmotionDialog* pDialog = new EmotionDialog(this);
		QSize size = ui->widget_6->size();
		pDialog->settype(true);
		
		pDialog->setMinandMaxSize(295, size.height());
		pDialog->setitemInLine(7);
		pDialog->setitemSize(41);
		pDialog->setitempadding(3);
		pDialog->initEmoticonPkgIcons(stritemtext);
		mapEmoticonManagerDialogs.insert(stritemtext,pDialog);
		ui->stackedWidget_local->addWidget(pDialog);
	}
	ui->stackedWidget->setCurrentWidget(ui->page_local);
	ui->stackedWidget_local->setCurrentWidget(mapEmoticonManagerDialogs.value(stritemtext));
}

void EmotionManagerDialog::onCustomEmotionSelected()
{
	DrawablePushButton* button = dynamic_cast<DrawablePushButton*>(sender());
	if (NULL!=button)
	{
		EmotionUserData* userData = dynamic_cast<EmotionUserData*>(button->userData(Qt::UserRole));
		bool bret = button->isChecked();
		if (!bret)
		{
			button->setStyleSheet("background-color: #3dbbca;");
			userData->m_bselect = true;
		}
		else
		{
			button->setStyleSheet("background-color: #FFFFFF;");
			userData->m_bselect = false;
		}
		
		button->setCheckable(!button->isChecked());
		
	}
}

void EmotionManagerDialog::onShowEmotionManagerDialog()
{
	show();
	activateWindow();
	InitLocalData();
	QTabBar *tabar = ui->tabWidget->tabBar();
	tabar->setCurrentIndex(0);
}

void EmotionManagerDialog::onReloadEmojiconPackage( const QString&pkgi )
{
	if (m_locallistwidget.contains(pkgi))
	{
		if(mapEmoticonManagerDialogs.contains(pkgi))
		{
			EmotionDialog *pEmotiondlg = mapEmoticonManagerDialogs.value(pkgi);
			if (pEmotiondlg)
			{
				pEmotiondlg->initEmoticonPkgIcons(pkgi);
			}
		}

		QListWidgetItem *pItem = ui->listWidget_local->currentItem();
		if (pItem!= NULL)
		{
			onCurrentItemChange(pItem, NULL);
			disconnect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgReloadEmojiconPackage,this,&EmotionManagerDialog::onReloadEmojiconPackage);
		}
	}
}

void EmotionManagerDialog::onCurrentItemServerChange( QListWidgetItem*item, QListWidgetItem*preitem )
{
	if (NULL == item)
		return;
	QString stritemtext = item->data(Qt::UserRole).toString();
	if (stritemtext.isEmpty())
	{
		return;
	}
	m_CurrentId = stritemtext;
	ui->stackedWidget->setCurrentWidget(ui->page_server);
	QString strDownloadurl = item->data(Qt::WhatsThisRole).toString();
	setEmotionPackageInfo(stritemtext, strDownloadurl);
	



}

void EmotionManagerDialog::onManagerEmotionInfoListRecvied( const QList<QSharedPointer<Biz::EmoticonPackageInfo>>& list )
{
	m_emotionpackageInfolist = list;
	ui->listWidget_server->clear();

	m_Serverlistwidget.clear();
	QListWidgetItem * listwidgetitem = NULL;
	for (QSharedPointer<Biz::EmoticonPackageInfo> item:list)
	{
		if (item->id().isEmpty())
		{
			continue;
		}
		
		//addOneEmotionPackage(item->id(), ui->listWidget_server);
		//图像必须放置默认图片了
		QPixmap couver = QPixmap(QString::fromUtf8(":/Images/default_header.png"));
		couver.setDevicePixelRatio(1.0);
		listwidgetitem = new QListWidgetItem(QIcon(couver.scaled(QSize(30, 30))), item->id());
		ui->listWidget_server->setIconSize(QSize(30, 30));
		listwidgetitem->setSizeHint(QSize(130, 35));
		listwidgetitem->setData(Qt::DisplayRole, item->name());
		listwidgetitem->setData(Qt::UserRole, item->id());
		listwidgetitem->setData(Qt::WhatsThisRole, item->downloadUrl());
		if (!m_Serverlistwidget.contains(item->id()))
		{
			ui->listWidget_server->addItem(listwidgetitem);
			m_Serverlistwidget.push_back(item->id());
		}
		

	}

	
	ui->listWidget_server->setCurrentRow(0);

}



void EmotionManagerDialog::setEmotionPackageInfo( const QString& pkgid, const QString& downloadurl )
{
	//删除的
	Biz::AllUserSettingData *pSetting = Biz::Session::getSettingConfig();
	QString strdelete = pSetting->DeleteEmotionList();
	QStringList strDeleteList;
	if (!strdelete.isEmpty())
	{
		strDeleteList = strdelete.split(",");
	}
	 QStringList localPkgid = Biz::Session::getEmoticonManager()->getEmoticonIds();
	for (QSharedPointer<Biz::EmoticonPackageInfo> item:m_emotionpackageInfolist)
	{
		if (item->id().isEmpty() || item->id() != pkgid)
		{
			continue;
		}
		
		ui->label_showName->setText(item->name());
		ui->label_showmiaoshu->setText(item->desc());
		ui->label_showSize->setText(QString::number(item->file_size()));

		if (localPkgid.contains(item->id()) && !strDeleteList.contains(item->id()))
		{
			ui->downloadBtn->setText(QStringLiteral("已下载"));
			ui->downloadBtn->setEnabled(false);
			QSharedPointer<Biz::EmoticonPackage> spPackage = Biz::Session::getEmoticonManager()->getEmotionPackageInfo(item->id());
			QSharedPointer<Biz::EmotionItem> spItem = spPackage->packageCoverImg;
			if (spItem.isNull() && spPackage->emotionList.size()>0)
			{
				spItem = spPackage->emotionList.at(0);
			}

			if (!spItem.isNull())
			{
				QPixmap couver(spItem->strPath);
				if (!couver.isNull())
				{
					couver.setDevicePixelRatio(1.0);
					ui->label_icon->setPixmap(couver.scaled(ui->label_icon->size()));
				}
			}
			
		}
		else
		{
			ui->downloadBtn->setText(QStringLiteral("下载"));
			ui->downloadBtn->setEnabled(true);
			QPixmap pixmap = QPixmap(QString::fromUtf8(":/Images/default_header.png"));
			pixmap.setDevicePixelRatio(1.0);
			ui->label_icon->setPixmap(pixmap.scaled(QSize(ui->label_icon->size())));

			spDownloadinfo = QSharedPointer<Biz::EmoticonPackageInfo>(new Biz::EmoticonPackageInfo);
			spDownloadinfo->id(pkgid);
			spDownloadinfo->downloadUrl(downloadurl);
			spDownloadinfo->desc(ui->label_showmiaoshu->text());
			connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgUpdateDescription,this,&EmotionManagerDialog::onUpdateDescription);
			connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgDownloadPackageResult,this,&EmotionManagerDialog::onDownloadPackageResult);
		}
	}
}

void EmotionManagerDialog::onCurrentItemClicked( QListWidgetItem * item )
{
	onCurrentItemChange(item, NULL);
}

void EmotionManagerDialog::onUpdateDescription( const QString& pkgid, const QString& descinfo )
{
	if(pkgid != m_CurrentId)
	{
		return;
	}

	ui->label_showmiaoshu->setText(descinfo);

}

void EmotionManagerDialog::onDownloadPackageResult( const QString& pkgid,bool bResult )
{
	if (m_CurrentId!=pkgid)
	{
		return;
	}
	if (bResult)
	{
		ui->downloadBtn->setText(QStringLiteral("已下载"));
		ui->downloadBtn->setEnabled(false);	
		//下载完了后，需要通知EmotiontabDialog 界面
		emit Biz::Session::getEmoticonManager()->sgDownloadFinishEmotionPackage(pkgid);
	}
	else
	{
		ui->downloadBtn->setText(QStringLiteral("下载失败"));
	}
	if (!spDownloadinfo.isNull())
	{
		ui->label_showmiaoshu->setText(spDownloadinfo->desc());
	}
	
}
