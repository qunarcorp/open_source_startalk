#include "RobotSearchView.h"

#include "CallbackReceiver.h"
#include "Session.h"
#include "RobotManager.h"
#include "portraithelper.h"
#include "RobotSearchedListWidgetAdapter.h"
RobotSearchView* RobotSearchView::pInstance = NULL;

RobotSearchView::RobotSearchView(QWidget *parent)
	: LocalManDialog(parent)
{
	mReceiver = new Biz::CallbackReceiver(this);

	ui.setupUi(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	// add by wangchao 2018.08.30
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	this->setSizeGripEnabled(true);

	auto titlebar = ui.titilebar;
	titlebar->setSizeable(false);
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	setWindowTitle(QStringLiteral("搜索公众号"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
	titlebar->setWindowTitle(QStringLiteral("搜索公众号"));
	setWindowTitle(QStringLiteral("搜索公众号"));
#endif
	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &RobotSearchView::onMin);
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &RobotSearchView::onMin);

	connect(ui.myrobot,&QPushButton::clicked,this,&RobotSearchView::onTabChange);
	connect(ui.searchrobot,&QPushButton::clicked,this,&RobotSearchView::onTabChange);

	connect(ui.lineEdit, &QLineEdit::textChanged, this, &RobotSearchView::onSearchTextChanged);

	connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgRobotSubscriptedListChange,this,&RobotSearchView::onRobotSubscriptedListChange);

	pAdapterList = new RobotListWidgetAdapter(ui.myRobotList);
	ui.myRobotList->setItemDelegate(pAdapterList);

	pAdapterSearch = new RobotSearchResultListAdapter(ui.searchRobotList);
	ui.searchRobotList->setItemDelegate(pAdapterSearch);
}

RobotSearchView::~RobotSearchView()
{

}

RobotSearchView* RobotSearchView::getInstance()
{
	if (pInstance==NULL)
	{
		pInstance = new RobotSearchView(NULL);
	}
	return pInstance;
}

void RobotSearchView::autoshow()
{
	this->showNormal();
	this->activateWindow();
	ui.myRobotList->clear();
	ui.searchRobotList->clear();
	ui.lineEdit->setText("");
	ui.searchrobot->click();
	onSearchTextChanged("");
}

void RobotSearchView::onTabChange(bool bckech)
{
	QWidget* pSender = (QWidget*)sender();
	if (pSender == ui.searchrobot && ui.searchrobot->isChecked())
	{
		ui.stackedWidget->setCurrentWidget(ui.robotSearchPage);
		onSearchTextChanged(ui.lineEdit->text());
	}
	else
	{
		ui.stackedWidget->setCurrentWidget(ui.myRobotListPage);
		this->rebuildRobotList(Biz::Session::getRobotManager()->getSubscriptedRobotList());
	}
}

void RobotSearchView::rebuildRobotList(const QStringList& robotList)
{
	ui.myRobotList->clear();

	for (QString rbtid:robotList)
	{
		QListWidgetItem* pItem = new QListWidgetItem(ui.myRobotList);
		pItem->setData(RobotShearchedDataRbtId,rbtid);
		ui.myRobotList->addItem(pItem);
	}
}

void RobotSearchView::onSearchTextChanged(const QString & text)
{
	auto callback = mReceiver->createCallback<QList<QSharedPointer<Biz::RobotVcard>>>(
		[this](const QList<QSharedPointer<Biz::RobotVcard>>& result){
			int nsize = result.size();
			ui.searchRobotList->clear();

			QMap<QString,QSharedPointer<Biz::RobotVcard>> mapData;
			for (QSharedPointer<Biz::RobotVcard> spVcard:result)
			{
				QString rbtid = spVcard->RbtId();
				if (!rbtid.isEmpty())
				{
					mapData.insert(rbtid,spVcard);
					QListWidgetItem* pItem = new QListWidgetItem(ui.searchRobotList);
					pItem->setData(RobotShearchedDataRbtId,rbtid);
					ui.searchRobotList->addItem(pItem);
				}
			}
			if (pAdapterSearch!=NULL)
			{
				pAdapterSearch->setRobotVcard(mapData);
			}
	}, [this](){});

	Biz::Session::getRobotManager()->searchRobot(text,callback);
}

void RobotSearchView::onRobotSubscriptedListChange()
{
	ui.myrobot->click();
    this->rebuildRobotList(Biz::Session::getRobotManager()->getSubscriptedRobotList());
}
