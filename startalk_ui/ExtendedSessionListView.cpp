#include "ExtendedSessionListView.h"
#include "ui_ExtendedSessionListView.h"
#include "diywidgit/customviews/qframelayout.h"
#include "StarPersonListView.h"
#include "combinationlistview.h"
#include "GroupListView.h"
#include "rostertreeview.h"
#include "Friendslistview.h"
#include "publicaccountlistview.h"
#include "blacknamelistview.h"
#include "wechatuserlist.h"
#include "collectiontreeview.h"
#include "Session.h"
#include "conversationmanager.h"

ExtendedSessionListView::ExtendedSessionListView(QWidget *parent)
    : QWidget(parent)
	,ui(new Ui::ExtendedSessionListView)
	, mpContentView(NULL)
{
    ui->setupUi(this);
    setExtendTitleVisable(false);
    connect(ui->pb_back,&QPushButton::clicked,[this](bool b){
        emit sgBackButtonClicked(getBelongExtendid());
    });
	
	
}

ExtendedSessionListView::~ExtendedSessionListView()
{

}


void ExtendedSessionListView::setExtendTitle(const QString& title)
{
   
    ui->titleText->setText(title);
}

void ExtendedSessionListView::setExtendTitleVisable(bool visable)
{
    ui->title_panel->setVisible(visable);
}

void ExtendedSessionListView::setLindedId(const QString& id)
{
    lindItemId=id;
}

QString ExtendedSessionListView::getLindedId()
{
    return lindItemId;
}

void ExtendedSessionListView::setBelongExtendid(const QString& id)
{
    beLongExtendId=id;
}

QString ExtendedSessionListView::getBelongExtendid() const
{
    return beLongExtendId;
}

QWidget* ExtendedSessionListView::getContentView() const
{
    return mpContentView;
}

void ExtendedSessionListView::setContentView( QWidget* pContentView )
{

	QFrameLayout* pContentLayout = new QFrameLayout(ui->widget);
	if (NULL!=pContentView)
	{
		mpContentView = pContentView;
		pContentLayout->appendWidget(mpContentView,ALINE_FILL);
	}

}


ExtendedSessionListView* ExtendedSessionListView::getCombinationListView() const
{
	return (ExtendedSessionListView*)getContentView();
}

//////////////////////////RecentExtendedSessionListView
RecentExtendedSessionListView::RecentExtendedSessionListView( QWidget*parent  )
	:ExtendedSessionListView(parent)
{
	RosterListWidget* pWidget = new RosterListWidget(this);
	setContentView(pWidget);
}

RecentExtendedSessionListView::~RecentExtendedSessionListView()
{

}

RosterListWidget* RecentExtendedSessionListView::getRosterListView() const
{
	RosterListWidget* prosterlistwidget = dynamic_cast<RosterListWidget*>(this->getContentView());
	return  prosterlistwidget;
}

RosterListWidget* RecentExtendedSessionListView::getCombinationListView() const
{
	RosterListWidget* prosterlistwidget = dynamic_cast<RosterListWidget*>(this->getContentView());
	return  prosterlistwidget;
}

//////////////////////////CombinationExtendedSessionListView
CombinationExtendedSessionListView::CombinationExtendedSessionListView( QWidget*parent /*= 0*/ )
	:ExtendedSessionListView(parent)
{
	CombinationListView *pListView = new CombinationListView(this);
	pListView->setObjectName("CombinationListView");
	setContentView(pListView);
}
CombinationExtendedSessionListView::~CombinationExtendedSessionListView()
{

}
CombinationListView* CombinationExtendedSessionListView::getCombinationListView() const
{
	CombinationListView *pcombinationlistview = dynamic_cast<CombinationListView*>(this->getContentView());
	return pcombinationlistview;
}

//CombinationOfStartPersonExtendedListView
CombinationOfStarPersonExtendedListView::CombinationOfStarPersonExtendedListView( QWidget*parent /*= 0*/ )
	:ExtendedSessionListView(parent)
{
	StarPersonListView *pListView = new StarPersonListView(this);
	pListView->setObjectName("StarPersonListView");
	setContentView(pListView);
}

CombinationOfStarPersonExtendedListView::~CombinationOfStarPersonExtendedListView()
{

}

StarPersonListView* CombinationOfStarPersonExtendedListView::getCombinationListView() const
{
	StarPersonListView *pListview = dynamic_cast<StarPersonListView*>(this->getContentView());

	return pListview;
}

///////////////////////////CombinationOfGroupExtendedListView
CombinationOfGroupExtendedListView::CombinationOfGroupExtendedListView( QWidget*parent /*= 0*/ )
	:ExtendedSessionListView(parent)
{
	GroupListView *pListView = new GroupListView(this);
	pListView->setObjectName("GroupListView");
	setContentView(pListView);
}

CombinationOfGroupExtendedListView::~CombinationOfGroupExtendedListView()
{

}

GroupListView* CombinationOfGroupExtendedListView::getCombinationListView() const
{
	GroupListView *pListview = dynamic_cast<GroupListView*>(this->getContentView());
	
	return pListview;
}
///////////////////////////CombinationOfOrganiExtendedListView
CombinationOfOrganiExtendedListView::CombinationOfOrganiExtendedListView( QWidget*parent /*= 0*/ )
	:ExtendedSessionListView(parent)
{
	RosterTreeView *pListView = new RosterTreeView(this);
	pListView->setObjectName("RosterTreeView");
	setContentView(pListView);
}

CombinationOfOrganiExtendedListView::~CombinationOfOrganiExtendedListView()
{

}

RosterTreeView* CombinationOfOrganiExtendedListView::getCombinationListView() const
{
	RosterTreeView *pListView = dynamic_cast<RosterTreeView*>(this->getContentView());
	
	return pListView;
}

///////////////////////////CombinationOfFriendExtendedListView
CombinationOfFriendExtendedListView::CombinationOfFriendExtendedListView( QWidget*parent /*= 0*/ )
	:ExtendedSessionListView(parent)
{
	FriendsListView *pListView = new FriendsListView(this);
	pListView->setObjectName("FriendsListView");
	setContentView(pListView);
}

CombinationOfFriendExtendedListView::~CombinationOfFriendExtendedListView()
{

}

FriendsListView* CombinationOfFriendExtendedListView::getCombinationListView() const
{
	FriendsListView *pListView = dynamic_cast<FriendsListView*>(this->getContentView());
	return pListView;
}

////////////////////////////CombinationOfPublicAccountExtendedListView
CombinationOfPublicAccountExtendedListView::CombinationOfPublicAccountExtendedListView( QWidget*parent /*= 0*/ )
{
	PublicAccountListView *pListView = new PublicAccountListView(this);
	pListView->setObjectName("PublicAccountListView");
	setContentView(pListView);
}

CombinationOfPublicAccountExtendedListView::~CombinationOfPublicAccountExtendedListView()
{

}

PublicAccountListView* CombinationOfPublicAccountExtendedListView::getCombinationListView() const
{
	PublicAccountListView *pListView = dynamic_cast<PublicAccountListView*>(this->getContentView());
	return pListView;
}
////////////////////////////CombinationOfBlackNameExtendedListView
CombinationOfBlackNameExtendedListView::CombinationOfBlackNameExtendedListView( QWidget*parent /*= 0*/ )
{
	BlackNameListView *pListView = new BlackNameListView(this);
	pListView->setObjectName("BlackNameListView");
	setContentView(pListView);
}

CombinationOfBlackNameExtendedListView::~CombinationOfBlackNameExtendedListView()
{

}

BlackNameListView* CombinationOfBlackNameExtendedListView::getCombinationListView() const
{
	BlackNameListView *pListView = dynamic_cast<BlackNameListView*>(this->getContentView());
	return pListView;
}

CombinationOfWechatsExtendedListView::CombinationOfWechatsExtendedListView(QWidget*parent /*= 0*/)
{
    WechatUserListView *pListView = new WechatUserListView(this);
    pListView->setObjectName("WechatUserListView");
    setContentView(pListView);
}

CombinationOfWechatsExtendedListView::~CombinationOfWechatsExtendedListView()
{

}

WechatUserListView* CombinationOfWechatsExtendedListView::getCombinationListView() const
{
    WechatUserListView *pListView = dynamic_cast<WechatUserListView*>(this->getContentView());
    return pListView;
}
/////////////////////////////////////CombinationOfCollectionExtendedListView
CollectionExtendedListView::CollectionExtendedListView( QWidget*parent /*= 0*/ )
{
	CollectionTreeView *pListView = new CollectionTreeView(this);
	pListView->setObjectName("CollectionTreeView");
	setContentView(pListView);
}

CollectionExtendedListView::~CollectionExtendedListView()
{

}

CollectionTreeView* CollectionExtendedListView::getcollectionListView() const
{
	CollectionTreeView *pListView = dynamic_cast<CollectionTreeView*>(this->getContentView());

	return pListView;
}

CollectionTreeView* CollectionExtendedListView::getCombinationListView() const
{
	CollectionTreeView *pListView = dynamic_cast<CollectionTreeView*>(this->getContentView());

	return pListView;
}
