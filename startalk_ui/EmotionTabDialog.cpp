#include "EmotionTabDialog.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStackedLayout>

#include "LanguageHelper.h"
#include "QFileDialog"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "EmotionListData.h"
#include "ConfigureHelper.h"
#include "EmotionManager.h"
#include "Player.h"
#include "diywidgit/customviews/qframelayout.h"
#include "../3rd/quazip/JlCompress.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "emotionmanagerdialog.h"
#include "SettingData.h"

const static char* user_data = "user_data";
const static int btnwidth = 40;
EmotionTabDialog::EmotionTabDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
	setAttribute(Qt::WA_TranslucentBackground, true); 
	//setAutoFillBackground(true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	//setBackgroundRole();
	
	//让移动的宽度，每次移动一个按钮的宽度
	QScrollBar* bar = ui.scrollArea->horizontalScrollBar();
	bar->setSingleStep(btnwidth + 1);


	InitMenu();
	InitEmotion();
	connect(ui.setting, &QPushButton::clicked, this, &EmotionTabDialog::OnSettingBtnClicked);



    connect(ui.leftpage,&QPushButton::clicked,[this](bool bcheck){
        QScrollBar* bar = ui.scrollArea->horizontalScrollBar();
       // bar->setValue(qMax(0,bar->value()-bar->pageStep()));
		bar->setValue(bar->value()-btnwidth);
        int val = bar->value();
        ui.leftpage->setEnabled(bar->value()>0);
        ui.rightpage->setEnabled(bar->value()<bar->maximum());
    });

    connect(ui.rightpage,&QPushButton::clicked,[this](bool bcheck){
        QScrollBar* bar = ui.scrollArea->horizontalScrollBar();
       // bar->setValue(qMin(bar->maximum(),bar->value()+bar->pageStep()));
		 bar->setValue(bar->value()+btnwidth);
        int val = bar->value();
        ui.leftpage->setEnabled(bar->value()>0);
        ui.rightpage->setEnabled(bar->value()<bar->maximum());
    });


    connect(ui.scrollArea->horizontalScrollBar(),&QAbstractSlider::rangeChanged,[this](int min, int max){
        ui.leftpage->setVisible(true);
        ui.rightpage->setVisible(true);
         QScrollBar* bar = ui.scrollArea->horizontalScrollBar();
        ui.leftpage->setEnabled(bar->value()>0);
        ui.rightpage->setEnabled(bar->value()<bar->maximum());
    });

    

//     ui.lastpage->setVisible(false);
//     ui.nextpage->setVisible(false);
	ui.leftpage->setArrowType(Qt::LeftArrow);
	ui.rightpage->setArrowType(Qt::RightArrow);

   // ui.setting ->setVisible(false);

     QFrameLayout* layout = new QFrameLayout(ui.contentpanel);
     layout->appendWidget(ui.stackedWidget,ALINE_FILL);
     layout->appendWidget(ui.emotListPanel,ALINE_FILL);

     ui.contentpanel->setLayout(layout);
     //layout->setCurrentWidget(ui.stackedWidget);
     ui.emotListPanel->setVisible(false);

     ui.emotList->setAutoExclusive(true);

     connect(ui.emotList,&QPushButton::clicked,this,&EmotionTabDialog::onCheckEmotionBtnClicked);

	 connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgReloadEmojiconPackage,this,&EmotionTabDialog::onReloadEmojiconPackage);

     connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgUploadEmotionResult,[this](bool result){
         MainApp::UIFrame::getNotifyCenterController ()->popupNotice (result?QStringLiteral("收藏图片成功"):QStringLiteral("收藏图片失败"));
		 if (result)
		 {
			 Biz::Session::getEmoticonManager()->sgSaveEmotionSuccess();
		 }
     });
	 connect(Biz::Session::getEmoticonManager(), &Biz::EmotionManager::sgDeleteCustomerEmotion, this, &EmotionTabDialog::onDeleteCustormerEmotion);
	 connect(Biz::Session::getEmoticonManager(), &Biz::EmotionManager::sgDownloadFinishEmotionPackage, this, &EmotionTabDialog::OnDownloadFinishEmotionPackage);
}

EmotionTabDialog::~EmotionTabDialog()
{

}

void EmotionTabDialog::init()
{
}



void EmotionTabDialog::autoshow()
{
	QPoint pos = QCursor::pos();
	int heightscreen=QApplication::desktop()->screenGeometry().bottom(); 

	int h = 210;
	int width = this->geometry().width();
	int height = this->geometry().height();


	//让图像框显示在工具条的上面
	if ( ((pos.x() - width/2) >0) && ((pos.y() -height - 20) > 0) )
	{
		this->move(pos.x() - width/2, pos.y() - height - 20);
	}
	else 
	{
		this->move(pos);
	}

    bool hasChecked = false;
    for (int i=0;i<ui.btngroup_layout->count();i++)
    {
        QPushButton* pbtn =dynamic_cast<QPushButton*>(ui.btngroup_layout->itemAt(i)->widget());
        if (pbtn!=NULL)
        {
            hasChecked |= pbtn->isChecked();
        }
    }

    if (!hasChecked && ui.btngroup_layout->count() > 1 )
    {
        QPushButton* pbtn =dynamic_cast<QPushButton*>(ui.btngroup_layout->itemAt(1)->widget());
        if (NULL!=pbtn)
        {
           pbtn->click();
        }
    }

	show();
	activateWindow();
}

void EmotionTabDialog::InitEmotion()
{
    // 获取所有的表情包id
    QStringList list = Biz::Session::getEmoticonManager()->getEmoticonIds();
	if (list.contains("qunar_camel"))
	{
		addOneEmotionPackage("qunar_camel");
		list.removeOne("qunar_camel");
	}
	
	for (QString pid:list)
	{
		addOneEmotionPackage(pid);
	}
}


void EmotionTabDialog::addOneEmotionPackage(const QString& pkgid)
{
	//判断一下
	if (parseToolBarContianBtn(pkgid))
	{
		return;
	}

	QPushButton* pbtn = new QPushButton(ui.btngroup);
	pbtn->setAutoExclusive(true);
	pbtn->setProperty(user_data,pkgid);
	pbtn->setFlat(true);
	pbtn->setCheckable(true);
	pbtn->setFixedSize(btnwidth,30);

	do 
	{
		QSharedPointer<Biz::EmoticonPackage> spPackage = Biz::Session::getEmoticonManager()->getEmotionPackageInfo(pkgid);
		if (!spPackage.isNull())
		{
			if (spPackage->strPackageId == Biz::EmotionManager::sCustomPackageName)
			{
				QPixmap couver(":Images/custom_emoj_btn.png");
				couver.setDevicePixelRatio(1.0);
				pbtn->setIcon(couver);
				pbtn->setIconSize(QSize(24,24));
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
					pbtn->setIcon(couver);
					pbtn->setIconSize(QSize(24,24));
					break;
				}
				else
				{
					pbtn->setText(spPackage->strPackageDesc);
					break;
				}
			}
		}
		pbtn->setText(pkgid);
	} while (false);

	ui.btngroup_layout->addWidget(pbtn);

	connect(pbtn,&QPushButton::clicked,this,&EmotionTabDialog::onTabBtnClicked);

	int fixwidth = (ui.btngroup_layout->count()-1)*(btnwidth+ui.btngroup_layout->spacing()) + 70+ui.btngroup_layout->spacing();
	ui.btngroup->setFixedWidth(fixwidth);
}



void EmotionTabDialog::onTabBtnClicked( bool b )
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());

    // 表情切换
    QString pkgid = btn->property(user_data).toString();
    if (pkgid.isEmpty())
    {
        return;
    }

    if (!mapEmoticonDialogs.contains(pkgid))
    {
        EmotionDialog* pDialog = new EmotionDialog(this);
		pDialog->setitemInLine(7);
		pDialog->setitemSize(61);
		pDialog->setitempadding(5);
        pDialog->initEmoticonPkgIcons(pkgid);
        mapEmoticonDialogs.insert(pkgid,pDialog);
        ui.stackedWidget->addWidget(pDialog);
        connect(pDialog,&EmotionDialog::sgSelectItem,this,&EmotionTabDialog::onEmoticonSelected);
    }

    ui.stackedWidget->setCurrentWidget(mapEmoticonDialogs.value(pkgid));
    ui.emotListPanel->setVisible(false);
}

void EmotionTabDialog::OnSettingMenu()
{
	settingMenu->exec(QCursor::pos());
}



void EmotionTabDialog::onImportEmotion()
{
// 
// 	QString strDir = QFileDialog::getExistingDirectory(this, "Open Directory", "", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
// 	if (!strDir.isEmpty())
// 	{
// 		int npos = strDir.lastIndexOf("/");
// 		QString FileName = strDir.mid(npos+1);
// 		//onCreateOnePBInPanl(FileName.replace("Emoticon", ""), strDir + QString("/%1.xml").arg(FileName));
// 		Biz::EmotionListData* gld  = Biz::Session::currentAccount().getEmotionsData();
// 		Biz::EmotionSetting *setting = gld->getEmotionSetting();
// 
// 		setting->TitleName(FileName.replace("Emoticon", ""));
// 		setting->EmotionPath(strDir + QString("/%1.xml").arg(FileName));
// 
// 
// 		//写数据到Emotion.dat文件中
// 		Biz::Session::currentAccount().saveEmotionListData();
// 	}
}

void EmotionTabDialog::onExportEmotion()
{

}

void EmotionTabDialog::onCustomEmotion()
{

}

void EmotionTabDialog::InitMenu()
{
	settingMenu = new QMenu(ui.setting);

	QAction* action = NULL;
	action = new QAction(T_("Emotion_ImportMenu"),ui.setting);
	connect(action,&QAction::triggered,this,&EmotionTabDialog::onImportEmotion);
	settingMenu->addAction(action);

	action = NULL;
	action = new QAction(T_("Emotion_ExportMenu"), ui.setting);
	connect(action, &QAction::triggered,this,&EmotionTabDialog::onExportEmotion);
	settingMenu->addAction(action);

	settingMenu->addSeparator();

	action = NULL;
	action = new QAction(T_("Emotion_CustomMenu"), ui.setting);
	connect(action, &QAction::triggered,this,&EmotionTabDialog::onCustomEmotion);
	settingMenu->addAction(action);
}

QStringList EmotionTabDialog::getAllPackageIds()
{
    QStringList strList;
    strList = Biz::Session::getEmoticonManager()->getEmoticonIds();
    return strList;
}

void EmotionTabDialog::onEmoticonSelected(const QString& pkgid,const QString& shortcut)
{
	QSharedPointer<Biz::EmoticonPackage> spPackage = Biz::Session::getEmoticonManager()->getEmotionPackageInfo(pkgid);
	if (!spPackage.isNull())
	{
		if (spPackage->bMiniData)
		{
			QSharedPointer<Biz::EmotionItem> spItem = spPackage->emotionMap.value(shortcut);
			if (!spItem.isNull())
			{
				if (!spItem->strUrl.isEmpty())
					emit sgSendUrlImage(mconversionId,pkgid,shortcut);
				else
					emit sgSendImage(mconversionId,spItem->strPath);
			}
		}
		else
		{
			emit sgSelectItem(mconversionId,pkgid,shortcut);
		}
	}
	
    this->hide();
}

void EmotionTabDialog::onCheckEmotionBtnClicked(bool bcheck)
{
    
    ui.emotListPanel->setVisible(ui.emotList->isChecked());
    
    disconnect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgEmotionInfoListRecvied,this,&EmotionTabDialog::onEmotionInfoListRecvied);
    connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgEmotionInfoListRecvied,this,&EmotionTabDialog::onEmotionInfoListRecvied);
    Biz::Session::getEmoticonManager()->getEmotionsPackages();
}

void EmotionTabDialog::onEmotionInfoListRecvied(const QList<QSharedPointer<Biz::EmoticonPackageInfo>>& list)
{
    QVBoxLayout* hl = (QVBoxLayout*)ui.emotcionShop->layout();
    QLayoutItem *child;
    while ((child = hl->takeAt(0)) != 0) {
		QWidget* pWidget = child->widget();
		if (NULL!=pWidget)
		{
			pWidget->setParent(NULL);
			delete pWidget;
		}
        delete child;
    }

    QStringList localPkgid = Biz::Session::getEmoticonManager()->getEmoticonIds();

	//看有多少被删除的
	Biz::AllUserSettingData *pSetting = Biz::Session::getSettingConfig();
	QString strdelete = pSetting->DeleteEmotionList();
	QStringList strdeletelist;
	if (!strdelete.isEmpty())
	{
		strdeletelist = strdelete.split(",");
	}

    for (QSharedPointer<Biz::EmoticonPackageInfo> item:list)
    {
		if (item->id().isEmpty())
		{
			continue;
		}

        EmoticonDownloadInfoWidget* widget = new EmoticonDownloadInfoWidget(ui.emotcionShop);
        hl->addWidget(widget);
        widget->name->setText(item->name());
        widget->desc->setText(item->desc());
        widget->spEpinfo = item;
		widget->pTabDialog = this;
        if (localPkgid.contains(item->id()))
        {
			if (strdeletelist.contains(item->id()))
			{
				widget->download->setText(QStringLiteral("下载"));
				widget->download->setEnabled(true);
			}
			else
			{
				widget->download->setText(QStringLiteral("已下载"));
				widget->download->setEnabled(false);
			}
        }
    }
}

void EmotionTabDialog::onReloadEmojiconPackage(const QString& pkgid)
{
	if (mapEmoticonDialogs.contains(pkgid))
	{
		EmotionDialog* pDialog = mapEmoticonDialogs.value(pkgid);
		pDialog->initEmoticonPkgIcons(pkgid);
	}
}

void EmotionTabDialog::OnSettingBtnClicked()
{
	EmotionManagerDialog *pEmotionManagerdlg = EmotionManagerDialog::getInstance();
	if(pEmotionManagerdlg)
	{
		if(!pEmotionManagerdlg->isVisible())
		{
			pEmotionManagerdlg->onShowEmotionManagerDialog();
		}
		else
		{
			pEmotionManagerdlg->hide();
		}
		
		this->close();
	}
}

void EmotionTabDialog::onDeleteCustormerEmotion( const QString&pkgid )
{

	if ( pkgid == Biz::EmotionManager::sCustomPackageName )//删除自定义中的表情
	{
		if ( mapEmoticonDialogs.contains(pkgid))
		{
			EmotionDialog* pDialog = mapEmoticonDialogs.value(pkgid);
			pDialog->initEmoticonPkgIcons(pkgid);
		}
	}
	else //删除管理的表情
	{
		//先删掉toolbar上的btn
		QPushButton*pbtn = getEmotionButtonById(pkgid);
		if (pbtn)
		{
			ui.btngroup_layout->removeWidget(pbtn);
		}

		int fixwidth = (ui.btngroup_layout->count()-1)*(btnwidth+ui.btngroup_layout->spacing()) + 70+ui.btngroup_layout->spacing();
		ui.btngroup->setFixedWidth(fixwidth);


		//然后删掉页面中的Dialog
		EmotionDialog* pDialog = mapEmoticonDialogs.value(pkgid);
		if (pDialog)
		{
			mapEmoticonDialogs.remove(pkgid);
			ui.stackedWidget->removeWidget(pDialog);
		}
		//下载页面中的下载按钮,“已下载”变成“下载”
		//emit Biz::Session::getEmoticonManager()->sgDeleteEmotionPackage(pkgid);
		QStringList localPkgid = Biz::Session::getEmoticonManager()->getEmoticonIds();
		QVBoxLayout* hl = (QVBoxLayout*)ui.emotcionShop->layout();
		QLayoutItem *child;

		
		while ((child = hl->takeAt(0)) != 0) {
			EmoticonDownloadInfoWidget* pWidget = (EmoticonDownloadInfoWidget*)child->widget();
			if (NULL!=pWidget)
			{
				if (pkgid == pWidget->spEpinfo->id())
				{
					pWidget->download->setText(QStringLiteral("下载"));
					pWidget->download->setEnabled(true);
					break;
				}
				
			}
			
		}



	}

}




void EmotionTabDialog::OnDownloadFinishEmotionPackage( const QString&pkgid )
{
	addOneEmotionPackage(pkgid);
}

bool EmotionTabDialog::parseToolBarContianBtn( const QString&id )
{
	QStringList ids;
	bool bResult = false;
	for (int i=0;i<ui.btngroup_layout->count();i++)
	{
		QPushButton* pbtn =dynamic_cast<QPushButton*>(ui.btngroup_layout->itemAt(i)->widget());
		if (pbtn!=NULL)
		{
			ids.push_back(pbtn->property(user_data).toString());
		}
	}
	if (ids.contains(id))
	{
		bResult = true;
	}

	return bResult;
}

QPushButton* EmotionTabDialog::getEmotionButtonById( const QString&id )
{
	QStringList ids;
	bool bResult = false;
	QPushButton *retBtn = NULL;
	for (int i=0;i<ui.btngroup_layout->count();i++)
	{
		QPushButton* pbtn =dynamic_cast<QPushButton*>(ui.btngroup_layout->itemAt(i)->widget());
		if (pbtn!=NULL)
		{
			QString btnId = pbtn->property(user_data).toString();
			if (id == btnId)
			{
				retBtn = pbtn;
				break;
			}
		}
	}

	return retBtn;
}

EmoticonDownloadInfoWidget::EmoticonDownloadInfoWidget(QWidget* parent) :QWidget(parent),pTabDialog(NULL)
{
    // 横向布局 头像+文字区+按钮
    horizontalLayout_5 = new QHBoxLayout(this);
    horizontalLayout_5->setContentsMargins(10, 0, 10, 0);
    // 右侧头像
    label = new QLabel(this);
    label->setMinimumSize(QSize(32, 32));
    label->setMaximumSize(QSize(32, 32));
    label->setStyleSheet(QLatin1String("image:url(:/Images/toolbar_emoticon_hover.png);\n"
        "border:2px solid #666666;\n"
        "border-radius: 4px;"));


    horizontalLayout_5->addWidget(label);

    widget_5 = new QWidget(this);
    verticalLayout_3 = new QVBoxLayout(widget_5);
    verticalLayout_3->setSpacing(0);
    verticalLayout_3->setContentsMargins(0, 0, 0, 0);
    widget_6 = new QWidget(widget_5);
    widget_6->setObjectName(QStringLiteral("widget_6"));
    verticalLayout_4 = new QVBoxLayout(widget_6);
    verticalLayout_4->setSpacing(0);
    verticalLayout_4->setContentsMargins(0, 0, 0, 0);

    name = new QLabel(widget_6);
    name->setObjectName(QStringLiteral("name"));

    verticalLayout_4->addWidget(name);


    verticalLayout_3->addWidget(widget_6);

    widget_8 = new QWidget(widget_5);
    verticalLayout_5 = new QVBoxLayout(widget_8);
    verticalLayout_5->setSpacing(0);
    verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
    verticalLayout_5->setContentsMargins(0, 0, 0, 0);
    desc = new QLabel(widget_8);
    desc->setObjectName(QStringLiteral("desc"));

    verticalLayout_5->addWidget(desc);
    verticalLayout_3->addWidget(widget_8);
    horizontalLayout_5->addWidget(widget_5);
    download = new QPushButton(this);
    download->setText(QStringLiteral("下载"));
    download->setMinimumSize(QSize(70, 30));
    download->setMaximumSize(QSize(70, 30));

    horizontalLayout_5->addWidget(download);

    connect(download,&QPushButton::clicked,[this](bool b){
        if (!spEpinfo.isNull())
        {
            Biz::Session::getEmoticonManager()->downloadEmotionsPackage(spEpinfo);
        }
    });

	connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgUpdateDescription,this,&EmoticonDownloadInfoWidget::onUpdateDescription);
	connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgDownloadPackageResult,this,&EmoticonDownloadInfoWidget::onDownloadPackageResult);
	connect(Biz::Session::getEmoticonManager(),&Biz::EmotionManager::sgDeleteEmotionPackage, this, &EmoticonDownloadInfoWidget::onDeleteEmotionPackage);
}

void EmoticonDownloadInfoWidget::onUpdateDescription(const QString& pkgid, const QString& descinfo)
{
	if (pkgid != spEpinfo->id())
	{
		return;
	}

	this->desc->setText(descinfo);
}

void EmoticonDownloadInfoWidget::onDownloadPackageResult(const QString& pkgid,bool bResult)
{
	if (spEpinfo->id()!=pkgid)
	{
		return;
	}
	if (bResult)
	{
		this->download->setText(QStringLiteral("已下载"));
		this->download->setEnabled(false);
		this->desc->setText(spEpinfo->desc());
		if (NULL!=pTabDialog)
		{
			pTabDialog->addOneEmotionPackage(pkgid);
		}
	}
	else
	{
		this->desc->setText(QStringLiteral("下载失败"));
	}
}

void EmoticonDownloadInfoWidget::onDeleteEmotionPackage( const QString& pkgid )
{
	if (pkgid.isEmpty() || spEpinfo->id()!=pkgid )
	{
		return;
	}
	this->download->setText(QStringLiteral("下载"));
	this->download->setEnabled(true);

}

EmoticonDownloadInfoWidget::~EmoticonDownloadInfoWidget()
{

}
