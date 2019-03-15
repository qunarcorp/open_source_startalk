#include "FriendsSearcher.h"
#include "Session.h"
#include "Account.h"
#include "SystemConfigData.h"
#include "CallbackReceiver.h"
#include "RosterList.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"

#include "animationreactor.h"
#include "ui_FriendsSearcher.h"

#include "diywidgit/customviews/qimdroplistview.h"
#include "diywidgit/customviews/qframelayout.h"

#include "jsonobject/domainlist.h"
#include "ConfigureHelper.h"



#include "ListWidgetBaseAdapter.h"


class DomainDropListUserData : public QIMDropListViewUserData {
public:
    QSharedPointer<Biz::DomainInfo> m_spRawDomainInfo;
};


class FriendSearchItem : public QWidget
{

public:
    enum FriendsSearchStatus
    {
        FriendsSearchStatusBase = 0,
        FriendsSearchStatusToBeAdd  = FriendsSearchStatusBase,
        FriendsSearchStatusToBeDelete   =   FriendsSearchStatusBase +1
    };
    FriendSearchItem(QWidget* parent):QWidget(parent) 
    {
       
        QLabel* headerImage = new QLabel(this);
        headerImage->setPixmap(QPixmap(":/Images/mainpanel_buddy_down.png"));
        headerImage->setFixedSize (QSize(28,28));

        itemName = new QLabel(this);

        actionBtn = new QPushButton(this);
        actionBtn->setText(QStringLiteral("加为好友"));
        actionBtn->setMinimumSize(QSize(72, 24));
        actionBtn->setMaximumSize(QSize(72, 24));

         QFrameLayout* pRootLayout = new QFrameLayout(this);
         pRootLayout->appendWidget (headerImage,ALINE_VCENTER|ALINE_LEFT,QMargins(0,0,0,0));
         pRootLayout->appendWidget (itemName,ALINE_VCENTER|ALINE_LEFT,QMargins(30,0,0,0));
         pRootLayout->appendWidget (actionBtn,ALINE_VCENTER|ALINE_RIGHT,QMargins(0,0,0,0));
         this->setLayout (pRootLayout);
    }
    ~FriendSearchItem()
    {
    };
    void setStatus(FriendsSearchStatus status){
        if (FriendSearchItem::FriendsSearchStatus::FriendsSearchStatusToBeDelete == status)
        {
            actionBtn->setText (QStringLiteral("删除好友"));
            actionBtn->setEnabled (true);
            actionBtn->setStyleSheet ("border:1px solid #1BA9BA;border-radius:3px;background:#00000000;color:#1BA9BA;");
            actionBtn->disconnect ();
            connect (actionBtn,&QPushButton::clicked,this,&FriendSearchItem::onDeleteFriend);
        }
        if (FriendSearchItem::FriendsSearchStatus::FriendsSearchStatusToBeAdd == status)
        {
            actionBtn->setText (QStringLiteral("加为好友"));
            actionBtn->setEnabled (true);
            actionBtn->setStyleSheet ("border:1px solid #CCCCCC;border-radius:3px;background:#1BA9BA;color:#FFFFFF;");
            actionBtn->disconnect ();
            connect (actionBtn,&QPushButton::clicked,this,&FriendSearchItem::onAddFriend);
        }
    };

    void onAddFriend(){
        if ( !userInfo.isNull())
        {
            QString qchatJid = userInfo->strUserId;
            if (Biz::Session::getFriendManager()->isAlreadyFriend(qchatJid))
            {
                MainApp::UIFrame::getNotifyCenterController ()->popupNotice (QStringLiteral("%1已经是好友了").arg(qchatJid));
                return;
            }
            Biz::Session::getFriendManager()->getUserVerifyMode(qchatJid);
            
        }
    };
    void onDeleteFriend(){
        if ( !userInfo.isNull())
        {
            QString jid = userInfo->strUserId;
            Biz::Session::getFriendManager()->getDeleteFriend(jid, E_DELETE_FRIEND_MODE::DELETE_MODE_SINGLE);
        }
    };
public:
    QLabel* itemName;
    QPushButton* actionBtn;
    QSharedPointer<Biz::ImSelfPerson> userInfo;
};



class FriendSearchResultListAdapter : public ListWidgetBaseAdapter
{
    enum DataKey
    {
        DataKeyBase = ListWidgetBaseAdapterUserRoleBase,
        DataKeyId   = DataKeyBase+1
    };

public:
    FriendSearchResultListAdapter(QListView* listview):ListWidgetBaseAdapter(listview){};
    ~FriendSearchResultListAdapter(){};

    virtual QWidget* CreateNewWidget(const QModelIndex& index)
    {
        QListWidget* pWidgetList = dynamic_cast<QListWidget*>(getListView ());
        if (NULL!=pWidgetList)
        {

        }
        QString key     = index.data(DataKeyId).toString ();
        FriendSearchItem* pItemview = new FriendSearchItem(NULL);
        QSharedPointer<Biz::ImSelfPerson> spData = userInfoDatas.value (key);
        if (!spData.isNull ())
        {
            pItemview->itemName->setText (spData->strNickName);
            pItemview->userInfo = spData;

            if (Biz::Session::getFriendManager ()->isAlreadyFriend (key))
                pItemview->setStatus (FriendSearchItem::FriendsSearchStatus::FriendsSearchStatusToBeDelete);
            else
                pItemview->setStatus (FriendSearchItem::FriendsSearchStatus::FriendsSearchStatusToBeAdd);
        }

        return pItemview;
    }

    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize(36,36);
    }

    virtual int count (){return userInfoDatas.count ();}

public:
    void setData(const QList<QSharedPointer<Biz::ImSelfPerson>>& datas)
    {
        userInfoDatas.clear ();
        QListWidget* pListWidget = dynamic_cast<QListWidget*>(getListView ());
        if (NULL!=pListWidget)
        {
            pListWidget->clear ();
            for (QSharedPointer<Biz::ImSelfPerson> boy : datas)
            {
                if (boy.isNull ())
                    continue;
                QListWidgetItem* pItem = new QListWidgetItem(pListWidget);
                pItem->setData (DataKeyId,boy->strUserId);
                pItem->setText (boy->strUserId);
                pListWidget->addItem (pItem);
                userInfoDatas.insert (boy->strUserId,boy);
            }
        }
    }
public:
    private:
    QMap<QString, QSharedPointer<Biz::ImSelfPerson>> userInfoDatas;
};



FriendsSearcher::FriendsSearcher(QWidget *parent)
    : LocalManWidget(parent)
    , receiver(new Biz::CallbackReceiver(this))
{
    ui = new Ui::FriendsSearcher();
    ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
	// WindowStaysOnTopHint add by wangchao 2018.08.30
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    this->setSizeGripEnabled(false);


    ui->titlebar->setMinable(false);
    ui->titlebar->setMaxable(false);

    connect(ui->titlebar,&TitlebarWidget::sgCloseOnClicked,this,&FriendsSearcher::onClose);

    setWindowTitle(QStringLiteral("添加朋友"));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    ui->levelStacked->setCurrentWidget(ui->empty);

    connect(ui->goSearch,&QPushButton::clicked,this,&FriendsSearcher::onGoSearchClicked);
    

    connect(ui->lineEdit,&QLineEdit::returnPressed,[this]{
        ui->goSearch->clicked();
    });

    ui->dropView->setContentViewParent(this);

    FriendSearchResultListAdapter* pAdapter  = new FriendSearchResultListAdapter(ui->listWidget);
    ui->listWidget->setItemDelegate(pAdapter);

    connect (ui->dropView,&QIMDropListView::currentTextChanged,this,&FriendsSearcher::onDomainListSelectChange);

    connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgDelFriendRecieve ,this, &FriendsSearcher::onFriendDeletedReceive);
    connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgFriendVerifyResultReceive, this, &FriendsSearcher::onFriendVerifyResponceReceive);
}

FriendsSearcher::~FriendsSearcher()
{

}

void FriendsSearcher::onGoSearchClicked(bool b)
{
    QString searchText = ui->lineEdit->text().trimmed();
    if (searchText.isEmpty())
    {
        ui->levelStacked->setCurrentWidget(ui->empty);
        return;
    }
    QSharedPointer<QIMDropListViewUserData> domaindata =  ui->dropView->getCurrentUserData();
    DomainDropListUserData* pDomainListData = (DomainDropListUserData*)domaindata.data ();   
    if (NULL!=pDomainListData && !pDomainListData->m_spRawDomainInfo.isNull ())
    {
        QString domainid = pDomainListData->m_spRawDomainInfo->id ();

        Biz::UnitCallback<QList<QSharedPointer<Biz::ImSelfPerson>>>* callback = receiver->createCallback<QList<QSharedPointer<Biz::ImSelfPerson>>>(
            [this](const QList<QSharedPointer<Biz::ImSelfPerson>>& personList){
                buildSearchResult(personList);
        },[](){}
        );

        Biz::Session::getFriendManager()->searchFriendInfo(searchText,domainid,0,callback);
    }
}

void FriendsSearcher::buildSearchResult(const QList<QSharedPointer<Biz::ImSelfPerson>>& retList)
{
    FriendSearchResultListAdapter* pAdater = dynamic_cast<FriendSearchResultListAdapter*>(ui->listWidget->itemDelegate());
    if (NULL!=pAdater)
    {
        pAdater->setData(retList);
        if (0<pAdater->count())
            ui->levelStacked->setCurrentWidget(ui->listpage);
        else
            ui->levelStacked->setCurrentWidget(ui->empty);
    }
}

void FriendsSearcher::onClose()
{
    this->hide();
    ui->lineEdit->setText("");
    FriendSearchResultListAdapter* pAdater = dynamic_cast<FriendSearchResultListAdapter*>(ui->listWidget->itemDelegate());
    if (NULL!=pAdater)
    {
        pAdater->setData(QList<QSharedPointer<Biz::ImSelfPerson>>());
        ui->levelStacked->setCurrentWidget(ui->empty);
    }
}


void FriendsSearcher::showEvent(QShowEvent *event)
{
     AnimationReactorSingleton::getInstance ()->opacityInWidget (this,100);
    initDomainListData();
    return LocalManWidget::showEvent (event);
}

void FriendsSearcher::initDomainListData()
{
    auto setDropData = [this](const QSharedPointer<Biz::DomainListInfo>& spInfo){
        if (NULL == spInfo->domains ())
            return;
        QList<QSharedPointer<QIMDropListViewUserData>> dropItems;
        for (IJsonSerializeable* pjsonItem : ((Biz::DomainList*)spInfo->domains ())->domains())
        {
            Biz::DomainInfo* pInfo = (Biz::DomainInfo*)pjsonItem;
            if (pInfo->id ().isEmpty () || pInfo->name ().isEmpty ())
                continue;
            DomainDropListUserData* pDomainUserData = new DomainDropListUserData;
            pDomainUserData->m_text        = pInfo->name ();
            pDomainUserData->m_hoverText   = pInfo->description ();
            pDomainUserData->m_spRawDomainInfo = QSharedPointer<Biz::DomainInfo>(new Biz::DomainInfo(*pInfo));
            QSharedPointer<QIMDropListViewUserData> userdata (pDomainUserData);
            dropItems.append (userdata);
        }
        ui->dropView->setData(dropItems);

        if (!spInfo->currentSelectId ().isEmpty ())
        {
            ui->dropView->setCurrentText(spInfo->currentSelectId());
        }
        else if (!dropItems.isEmpty())
        {
            ui->dropView->setCurrentText(dropItems.at (0)->m_text);
        } else {
            ui->dropView->setCurrentText("");
        }
    };

    QSharedPointer<Biz::DomainListInfo> spInfo (Biz::ConfigureHelper::loadDomainListConfigData ());
    if (!spInfo.isNull () && (QDateTime::currentMSecsSinceEpoch ()-spInfo->lastupdate ()) < 60*60*24)
    {
        setDropData(spInfo);
        return;
    }

    // 事实获取
    auto callback = receiver->createCallback<QSharedPointer<Biz::DomainList>> ([this,setDropData](const QSharedPointer<Biz::DomainList>& dl){
        if (!dl->domains ().empty ())
        {
            QSharedPointer<Biz::DomainListInfo> spInfo (Biz::ConfigureHelper::loadDomainListConfigData ());
            spInfo->domains (dl.data ());
            spInfo->lastupdate (QDateTime::currentMSecsSinceEpoch ());
            Biz::ConfigureHelper::saveDomainListConfigData (*spInfo.data ());
            setDropData(spInfo);
        }
    },[]{});

    Biz::Session::getFriendManager ()->getDomainList (callback);

}

void FriendsSearcher::onDomainListSelectChange(const QString& selectid)
{
    QSharedPointer<Biz::DomainListInfo> spInfo (Biz::ConfigureHelper::loadDomainListConfigData ());
    spInfo->currentSelectId(selectid);
    Biz::ConfigureHelper::saveDomainListConfigData (*spInfo.data ());
}

void FriendsSearcher::onFriendDeletedReceive(const QString&reson , const QString& jid, int ntype)
{
    QList<QListWidgetItem*> matchedItem = ui->listWidget->findItems(jid,Qt::MatchExactly);

    for (QListWidgetItem* pItem : matchedItem)
    {
        int nR = ui->listWidget->row (pItem);
        pItem = ui->listWidget->takeItem(nR);
        delete pItem;
    }
}

void FriendsSearcher::onFriendVerifyResponceReceive(const QString& result, const QString& reason, const QString& jid)
{
    QList<QListWidgetItem*> matchedItem = ui->listWidget->findItems(jid,Qt::MatchExactly);

    for (QListWidgetItem* pItem : matchedItem)
    {
        QWidget* pView = ui->listWidget->itemWidget(pItem);
        if (NULL!=pView)
        {
            FriendSearchItem* pItem = (FriendSearchItem*)pView;
            pItem->setStatus (FriendSearchItem::FriendsSearchStatusToBeDelete);
        }
    }
}

