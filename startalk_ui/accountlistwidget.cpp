#include "accountlistwidget.h"
#include "ui_AccountListWidget.h"
#include "diywidgit/customviews/qframelayout.h"
#include "Session.h"
#include "AccountData.h"

class AccountItem : public QListWidgetItem
{
public:

	virtual bool operator <(const QListWidgetItem &other) const
	{
		return true;
	}
};

AccountListWidget::AccountListWidget(QWidget *parent)
	: QWidget(parent)
	,ui(new Ui::AccountListWidget)
	,m_pAdapter(NULL)
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = Qt::Tool | FramelessWindowHint | Qt::Popup;
	overrideWindowFlags((Qt::WindowFlags)((windowFlags() & ~remove) | add));

	connect(ui->listWidget, &QListWidget::itemClicked, this, &AccountListWidget::onItemClicked);
	
	m_pAdapter = new AccountListWidgetAdapter(ui->listWidget);
	ui->listWidget->setItemDelegate(m_pAdapter);

	ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	ui->listWidget->setSpacing(0);

	connect(m_pAdapter, &AccountListWidgetAdapter::sgLoginAccountDelete, this, &AccountListWidget::onLoginAccountDelete);
}

AccountListWidget::~AccountListWidget()
{

}

void AccountListWidget::setItemSize( const QSize& size )
{
	m_ItemHeight = size.height();
	m_ItemWidth = size.width();
}

void AccountListWidget::setList( const QList<QSharedPointer<Biz::LoginAccountConfigInfo>>& accountlist )
{
	if (accountlist.size() <=0)
	{
		return;
	}
	m_pAdapter->setClear();
	ui->listWidget->clear();
	m_pAdapter->setList(accountlist);
	//QListWidget* plistview = (QListWidget*)getListView();
	/*for (QSharedPointer<Biz::LoginAccountConfigInfo> oneaccount: accountlist)
	{
		QWidget*container= new QWidget(this);

		container->setFixedHeight(m_ItemHeight);
		container->setFixedWidth(m_ItemWidth);

		QLabel *plab = new QLabel(container);
		plab->setStyleSheet("color:  #333333;"
							"font: 14px;"
							"border: 1px solid #FFFFFF;");
		//plab->setFixedWidth(m_ItemWidth/2);
		plab->setAlignment(Qt::AlignHCenter|Qt::AlignLeft);
		QPushButton*pb = new QPushButton(container);
		pb->setFixedWidth(m_ItemHeight);
		pb->setFixedHeight(m_ItemHeight);
		pb->setText("1234");
		pb->setStyleSheet("hover:border-image: url(:/Images/close-hover.png);"
							"pressed:border-image: url(:/Images/close-down.png);");
		pb->setFlat(true);
		container->show();
		QFrameLayout*pAccountLayout = new QFrameLayout(container);
		pAccountLayout->appendWidget(plab, ALINE_FILL);
		pAccountLayout->appendWidget(pb, ALINE_MATCHHEIGHT|ALINE_RIGHT);

		plab->setText(oneaccount->LoginAccount());
		

		QListWidgetItem *item = new QListWidgetItem();
		QSize size = item->sizeHint();
		item->setSizeHint(QSize(size.width(),m_ItemHeight));
		ui->listWidget->addItem(item);
		container->setSizeIncrement(size.width(),m_ItemHeight);
		ui->listWidget->setItemWidget(item,container);
	}*/
}

void AccountListWidget::showEvent( QShowEvent * )
{
	//m_pAdapter->setList();
}





void AccountListWidget::onItemClicked( QListWidgetItem *item )
{
	QSharedPointer<Biz::LoginAccountConfigInfo> logininfo(new Biz::LoginAccountConfigInfo);
	QString strtext = item->text();
	logininfo->ID(item->data(AccountListWidgetAdapter::AccountItemDataRangeID).toInt());
	logininfo->LoginAccount(item->data(AccountListWidgetAdapter::AccountItemDataRangeLoginAccount).toString());
	logininfo->savedPassword(item->data(AccountListWidgetAdapter::AccountItemDataRangesavedPassword).toString());
	logininfo->UserID(item->data(AccountListWidgetAdapter::AccountItemDataRangeUserID).toString()) ;
	logininfo->IsAutoLogin(item->data(AccountListWidgetAdapter::AccountItemDataRangeIsAutoLogin).toBool()) ;
	logininfo->IsSaveAccount(item->data(AccountListWidgetAdapter::AccountItemDataRangeIsSaveAccount).toBool()) ;
	logininfo->Domain(item->data(AccountListWidgetAdapter::AccountItemDataRangeDomain).toString()) ;
	logininfo->NAVAddr(item->data(AccountListWidgetAdapter::AccountItemDataRangeNAVAddr).toString()) ;
	
	emit sgAccountItemSelected(logininfo);
	this->hide();
}

void AccountListWidget::onLoginAccountDelete( const QString&loginaccount , const QString&loginpwd, const QString&navaddr )
{
	Biz::Session::loadLoginAccountConfigInfo();
	QList<QSharedPointer<Biz::LoginAccountConfigInfo>> list = Biz::Session::getLoginAccountConfigInfolist();
	for (QSharedPointer<Biz::LoginAccountConfigInfo> oneaccount: list)
	{
		if (!oneaccount.isNull())
		{
			QString newloginAccount = Biz::MessageUtil::makeSureUserId(loginaccount);
			if (oneaccount->LoginAccount() == newloginAccount && oneaccount->NAVAddr() == navaddr)
			{
				list.removeOne(oneaccount);
				break;
			}
		}
		
	}
	
	//设置一下ui的高度
	int nsize = list.size();
	setFixedHeight(nsize*(30+1));
	Biz::Session::saveLoginAccountConfigInfo(list);


	//重新重置一下每个item中的pb上的数字
//	QList<QSharedPointer<Biz::LoginAccountConfigInfo>> list = Biz::Session::getLoginAccountConfigInfolist();
// 	for (QSharedPointer<Biz::LoginAccountConfigInfo> oneaccount: list)
// 	{
// 
// 	}

	//QListView* plistView = (QListView*)getListView ();

}

/////////////AccountItem
AccountItemView::AccountItemView( )
	:m_plabel(NULL)
	,m_pb(NULL)
	,nIndex(0)
{
	QWidget* pWidget = new QWidget(this);
	pWidget->setObjectName ("AccountItemWidget");//border:1px solid #FF0000
	pWidget->setStyleSheet("#AccountItemView QWidget#pWidget {border:1px solid #FF0000;}");

	m_plabel = new QLabel(this);
	m_plabel->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
	m_plabel->setObjectName ("Accountcontent");
	m_plabel->setStyleSheet(QStringLiteral("QLabel {border:none;color:#333333;font: 14px;font-family:微软雅黑;}"));
	
	//m_pb = new QPushButton(this);
	m_pb = new QDeleteButton(this);
	m_pb->setObjectName("AccountButton");
	m_pb->setFlat(true);
	m_pb->setFixedWidth(40);
	m_pb->setFixedHeight(28);
// 	m_pb->setStyleSheet("QPushButton::hover{border:1px solid #FF0000;hover:border-image: url(:/Images/close-hover.png);}"
// 		"QPushButton::pressed{border-image: url(:/Images/close-down.png);}");

	m_pb->setStyleSheet(
		"QPushButton                   "
		"{                             "
		"    border: none ;            "
		"}                             "
		"                              "
		"QPushButton:hover             "
		"{                             "
		"    image: url(:/Images/close-hover.png); "
		"}                             "
		"QPushButton:pressed           "
		"{                             "
		"    image: url(:/Images/close-down.png); "
		"}                             "
		);

	QFrameLayout* pLayout = new QFrameLayout(pWidget);
	pLayout->appendWidget (m_plabel,ALINE_FILL,QMargins(9,0,0,0));
	pLayout->appendWidget (m_pb,ALINE_MATCHHEIGHT|ALINE_RIGHT,QMargins(0,0,10,0));
	pWidget->setLayout (pLayout);
	

	QFrameLayout* pWrap = new QFrameLayout(this);
	pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
	this->setLayout(pWrap);

	
// 	this->setStyleSheet ("#AccountItemView {border:1px solid #FF000000; font-family:微软雅黑;}\r\n \
// 						 #AccountItemView QWidget#pWidget{border:1px solid #D1D1D1; font-family:微软雅黑;}\r\n \
// 						 #AccountItemView QLabel#m_plabel{color:#333333;font: 14px;}\r\n \
// 						 #AccountItemView QPushButton#m_pb{border-image: url(:/Images/close-hover.png);}\r\n \
// 						 #AccountItemView QPushButton#m_pb:hover{border-image: url(:/Images/close-hover.png);}\r\n \
// 						 #AccountItemView QPushButton#m_pb:pressed{border-image: url(:/Images/close-down.png);}");

}

AccountItemView::AccountItemView( const AccountItemView&account )
{


	this->m_plabel = new QLabel();
	
	
	this->m_pb =new QDeleteButton();
	this->nIndex = account.nIndex;
	
}


AccountItemView::~AccountItemView()
{

}
///////////////AccountListWidgetAdapter
AccountListWidgetAdapter::AccountListWidgetAdapter( QAbstractItemView* parent )
	:ListWidgetBaseAdapter(parent)
{

}

AccountListWidgetAdapter::~AccountListWidgetAdapter()
{

}

QWidget* AccountListWidgetAdapter::CreateNewWidget( const QModelIndex& index )
{
	
	
	QString strContent = index.data (AccountItemDataRangeLoginAccount).toString ();
	
	QListView* plistView = (QListView*)getListView ();
	AccountItemView* pItemView = new AccountItemView();

	pItemView->m_plabel->setText (strContent);
	pItemView->nIndex =  index.data(AccountItemDataRangeIndex).toInt();
	pItemView->m_pb->setIndex(pItemView->nIndex);
	mpAccountItemlist.push_back(pItemView);
	connect(pItemView->m_pb, &QDeleteButton::sgdeleteclick, [this ](int nIndex){
		
		

		//删除item， account.dat中删除这项
		QListWidget* plistview = (QListWidget*)getListView();
		int ncount = plistview->count();

		int ncurrent = plistview->currentRow();

		QListWidgetItem * item = plistview->takeItem ( nIndex - 1 );
		mpAccountItemlist.removeAt(nIndex - 1);
		
		for (int nI = 0; nI < mpAccountItemlist.size(); nI++)
		{
			AccountItemView* psortItemView = mpAccountItemlist.at(nI);
			psortItemView->m_pb->setIndex(nI+1);
		}

		QString strContent = item->data (AccountItemDataRangeLoginAccount).toString ();
		QString strPwd = item->data(AccountItemDataRangesavedPassword).toString();
		QString strNavAddr = item->data(AccountItemDataRangeNAVAddr).toString();
		emit sgLoginAccountDelete(strContent, strPwd, strNavAddr);
	});
	return pItemView;
}

QSize AccountListWidgetAdapter::sizeHint( const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	return QSize(30,30);
}

void AccountListWidgetAdapter::updateData( QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option )
{

}

void AccountListWidgetAdapter::setList( const QList<QSharedPointer<Biz::LoginAccountConfigInfo>>& accountlist )
{
	QListWidget* plistview = (QListWidget*)getListView();
	int nI = 0;
	for (QSharedPointer<Biz::LoginAccountConfigInfo> oneaccount: accountlist)
	{
		if (oneaccount.isNull())
		{
			continue;
		}
		AccountItem* pItem = new AccountItem;

		QString groupName = oneaccount->LoginAccount ();
		pItem->setData (AccountItemDataRangeID,oneaccount->ID());
		QString strLoginAccount = oneaccount->LoginAccount();
		QString strDomain = oneaccount->Domain();
#ifdef QCHAT
		if (strDomain == "ejabhost")
		{
			strLoginAccount = strLoginAccount + "@qchat";
		}
		else
		{
			strLoginAccount = strLoginAccount + "@" + strDomain;
		}

#else
		if (strDomain == "ejabhost")
		{
			strLoginAccount = strLoginAccount + "@qtalk";
		}
		else
		{
			strLoginAccount = strLoginAccount + "@" + strDomain;
		}
#endif // QCHAT

		
		pItem->setData (AccountItemDataRangeLoginAccount,strLoginAccount);
		pItem->setData (AccountItemDataRangesavedPassword,oneaccount->savedPassword());
		pItem->setData (AccountItemDataRangeIsSaveAccount,oneaccount->IsSaveAccount());
		pItem->setData (AccountItemDataRangeIsAutoLogin,oneaccount->IsAutoLogin());
		pItem->setData (AccountItemDataRangeDomain,oneaccount->Domain());
		pItem->setData (AccountItemDataRangeNAVAddr,oneaccount->NAVAddr());
		pItem->setData (AccountItemDataRangeLastTime,oneaccount->LastLoginTime());
		pItem->setSizeHint(QSize(232, 30));
		plistview->addItem (pItem);
		pItem->setData(AccountItemDataRangeIndex, ++nI);
	}
}

void AccountListWidgetAdapter::deleteItem( const QString& id )
{

}

void AccountListWidgetAdapter::setClear()
{
	mpAccountItemlist.clear();
}

bool QDeleteButton::eventFilter( QObject *obj, QEvent *event )
{
	if (obj==this)
	{
		if ( (event->type() == QEvent::MouseButtonPress)   || (event->type() == QEvent::MouseButtonDblClick) )
		{
			sgdeleteclick(this->m_Index);
			return true;
		}
	}
	return QPushButton::eventFilter(obj, event);
}
