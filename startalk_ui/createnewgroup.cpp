#include "createnewgroup.h"
#include <QScrollBar>
#include <QApplication>
#include <QClipboard>
#include "Session.h"
#include "Account.h"
#include "portraithelper.h"
#include "RosterList.h"
#include "SystemConfigData.h"
#include "LanguageHelper.h"
#include "GroupListData.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "DealMessageBox.h"
#include "groupscontroller.h"
#include "DealMessageBox.h"
#include "GroupManager.h"
#include "friendsmanager.h"
#include "SearchUserListWidget.h"
#include "Session.h"
#include "conversationmanager.h"
#include "./diywidgit/customviews/qframelayout.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "editablesettings.h"
#include "groupmemberinput.h"

#include "SystemDefine.h"


const QString DEFAULT_GROUP_NAME = "QunarStaff";
const QSize GROUPSIZE = QSize(28,28);
const QSize MEMMBERSIZE = QSize(32,32);
const QSize MEMMBERSIZE_R = QSize(33,33);

void BaseItem::mouseReleaseEvent(QMouseEvent *)
{
    if (NULL != twiHolder)
    {
        twiHolder->setExpanded(!twiHolder->isExpanded());
    }
    onExpandItemChild();
}


PersonItem_L::PersonItem_L(QWidget* parent) : BaseItem(parent)
{
    ui.setupUi(this);
    connect(ui.selectButton,&QPushButton::clicked,this,&PersonItem_L::onSelectBtnClick);
	//image:url(: / Images / mainpanel_buddy_down.png)
	QPixmap pixmap(":Images/mainpanel_buddy_down.png");
	//pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui.header->size()));

	ui.header->setPixmap(pixmap);
}

PersonItem_L::~PersonItem_L()
{

}

void PersonItem_L::setHeader(const QString& headerPath)
{
	QPixmap pixmap;
	if (QFile::exists(headerPath))
	{
		pixmap = Biz::PortraitHelper::loadPixmap(headerPath);
		
	}
	else
	{
		pixmap =QPixmap(":Images/default_header.png");
		
	}

	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui.header->size()));

	ui.header->setPixmap(pixmap);
}

void PersonItem_L::setDisaplay(const QString& name)
{
    ui.display->setText(name);
}

void PersonItem_L::setActive(bool active)
{
    if (!active)
    {
        ui.widget->setStyleSheet(
            "QWidget#widget{"
            "background-color:#EAEBED;"
            "}"
            "QWidget#widget:hover{"
            "background-color:#4F9AD4;"
            "}"
            );
    }
    else
    {
        ui.widget->setStyleSheet(
            "QWidget#widget{"
            "background-color:#4F9AD4;"
            "}"

            );
    }
}

QString PersonItem_L::getDisplay()
{
    return ui.display->text();
}

void PersonItem_L::setSelectDisEnable()
{
	ui.selectButton->setChecked(true);
	ui.selectButton->setEnabled(false);
}

void PersonItem_L::onSelectBtnClick(bool cheched)
{
    emit sgSelectPerson(this,cheched);
}

void PersonItem_L::setSelectedBtnChecked(bool selected)
{
    ui.selectButton->setChecked(selected);
}

void PersonItem_L::setGroupBelong(const QString& shortName,const QString& fullName)
{
    ui.groupName->setText(QString("[%1]").arg(shortName));
    ui.groupName->setToolTip(QString("[%1]").arg(fullName));
}


GroupItem_L::GroupItem_L(QWidget* parent)
    :BaseItem(parent)
{
    ui.setupUi(this);
    connect(ui.selectbutton,&QPushButton::clicked,[this](bool b){
        QTreeWidgetItem* pItem = getTreeWidgetItemHolder();
        if (NULL!=pItem)
        {
            emit sgSelectMembersIn(getJid(),pItem,b);
        }
    }
    );
}

GroupItem_L::~GroupItem_L()
{

}


void GroupItem_L::setHeader(const QString& headerPath)
{
    //ui.header->setScaledContents(true);
    QPixmap pix(headerPath);
    pix = QPixmap::fromImage(pix.toImage().scaled(ui.header->size()));
    ui.header->setPixmap(pix);
}

void GroupItem_L::setDisaplay(const QString& name)
{
    ui.diaplay->setText(name);
}

void GroupItem_L::onExpandItemChild()
{
    QTreeWidgetItem* pItem = getTreeWidgetItemHolder();
    if (NULL!=pItem && 0==pItem->childCount())
    {
        emit sgLoadItemsChild(getJid(),pItem,ui.selectbutton->isChecked());
    }
}

void GroupItem_L::setSelectable(bool able)
{
    ui.selectbutton->setVisible(able);
}

void GroupItem_L::setSelectedBtnChecked(bool selected)
{
    ui.selectbutton->setChecked(selected);
}



PersonItem_R::PersonItem_R(QWidget* parent):BaseItem(parent)
{
    ui.setupUi(this);
    connect(ui.selectButton,&QPushButton::clicked,this,&PersonItem_R::onDeletePerson);
}

PersonItem_R::~PersonItem_R()
{

}

void PersonItem_R::setDisplayName(const QString& name)
{
    ui.display->setText(name);
}

void PersonItem_R::onDeletePerson(bool ignal)
{
    emit sgDeletePerson(this->getJid());
}

void PersonItem_R::setCloseable(bool b)
{
    ui.selectButton->setVisible(b);
}


CreateNewGroup::CreateNewGroup(LocalManDialog *parent)
    : LocalManDialog(parent)
    , resultCallback(NULL)
{
    ui.setupUi(this);
    initRosterTree();
    connect(ui.searchEdit,&QLineEdit::textChanged,this,&CreateNewGroup::onSearchEditInputChange);

    ui.splitter->setStretchFactor(0, 5);
    ui.splitter->setStretchFactor(1, 5);

    connect(ui.close,&QPushButton::clicked,[this](bool){this->close();});
    connect(ui.cancle,&QPushButton::clicked,[this](bool){this->close();});

    connect(ui.ok,&QPushButton::clicked,this,&CreateNewGroup::onAddmember);
    connect(ui.pushButton_creategroup, &QPushButton::clicked, this, &CreateNewGroup::onCreateGroupBtnClick);

    using namespace Qt;
    auto remove = WindowTitleHint;
	// WindowStaysOnTopHint add by wangchao 2018.08.30 // 子窗口默认显示在父窗口上
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    connect(ui.listWidget->verticalScrollBar(),&QScrollBar::valueChanged,this,&CreateNewGroup::onRightScrollBarValueChange);
    cacheIndex = 0;

    mCallbackReceiver = new Biz::CallbackReceiver(this);

	QString ghost = QApplication::clipboard()->text();
    if (!Biz::Session::getEditableSettings()->ShowAddUsersToGroup() 
		&& 0 != Util::GHOST_KEY_HIDE_FUNCTION.compare( QApplication::clipboard()->text(),Qt::CaseInsensitive))
    {
        ui.edit->setVisible(false);
    }
    connect(ui.edit,&QPushButton::clicked,[this](bool){
		GroupMemberInput inputDialog(this);
        inputDialog.exec();

        QMap<QString,QString> retMap = inputDialog.getInputUserMap();
        for (QString key:retMap.keys())
        {
            if (!key.isEmpty()&&!retMap.value(key).isEmpty())
            {
				m_mapPersonsCache.insert(retMap.value(key),key);
                addNewPerson2Right(key,retMap.value(key));
            }
        }
    });

    // 分类标题切换响应
    connect(ui.tabFriend,&QPushButton::clicked,this,&CreateNewGroup::onTabButtionClicked);
    connect(ui.tabDeps,&QPushButton::clicked,this,&CreateNewGroup::onTabButtionClicked);
    ui.memberstack->setCurrentWidget(ui.jiagoupage);
    ui.tabDeps->click();


}

CreateNewGroup::~CreateNewGroup()
{
}

void CreateNewGroup::initGroupWidget()
{

}

void CreateNewGroup::createTreeItemChildren(const QString& groupname,QTreeWidgetItem* parent,bool checked)
{

    Biz::RosterGroup* rGroup = Biz::Session::currentAccount().findRosterGroup(groupname);
    if (NULL!=rGroup && NULL != parent)
    {
        // 加人员
        foreach(Biz::RosterNode* node,rGroup->rosterNodeList)
        {
            QTreeWidgetItem* pItem = new QTreeWidgetItem();
            pItem->setSizeHint(0,MEMMBERSIZE);
            PersonItem_L* pPersonL = new PersonItem_L(NULL);
            pPersonL->setDisaplay(node->displayName);
            pPersonL->setJid(node->userId);
            pPersonL->setTreeWidgetItemHolder(pItem);
            pPersonL->setSelectedBtnChecked(checked);
            connect(pPersonL,&PersonItem_L::sgSelectPerson,this,&CreateNewGroup::onLSelectChange);
            parent->addChild(pItem);

            ui.jiagouTreeWidget->setItemWidget(pItem,0,pPersonL);

            m_mapPersonsL.insert(node->userId,pItem);
        }

        // 加子群组
        foreach(Biz::RosterGroup* group,rGroup->rosterGroupList)
        {
            QString fname = group->getFullName();

            QTreeWidgetItem* pItem = new QTreeWidgetItem();
            pItem->setSizeHint(0,GROUPSIZE);
            GroupItem_L* pGroupL = new GroupItem_L(NULL);
#if _DEBUG
            pGroupL->setDisaplay(group->getShortName() + 
                T_("DebugTitleInfor")
                .arg(group->getRosterList().size())
                .arg(group->getGroupList().size())
                .arg(group->getRosterListWithChildren().size()));

            /* pGroupL->setDisaplay(group->getShortName() + 
            QString::fromUtf8(" (%1人,%2组,共%3人)")
            .arg(group->getRosterList().size())
            .arg(group->getGroupList().size())
            .arg(group->getRosterListWithChildren().size()));*/
            pGroupL->setJid(group->getFullName());
#else
            pGroupL->setDisaplay(group->getShortName());
#endif
            QString fullName = group->getFullName();
            pGroupL->setJid(group->getFullName());
            pGroupL->setTreeWidgetItemHolder(pItem);
            pGroupL->setSelectable(true);
            pGroupL->setSelectedBtnChecked(checked);
            connect(pGroupL,&GroupItem_L::sgLoadItemsChild,this,&CreateNewGroup::onLoadItemsChild);
            connect(pGroupL,&GroupItem_L::sgSelectMembersIn,this,&CreateNewGroup::onAddMembersInGroup);
            parent->addChild(pItem);

            ui.jiagouTreeWidget->setItemWidget(pItem,0,pGroupL);
        }
    }
}

void CreateNewGroup::initRosterTree()
{
    m_mapPersonsL.clear();
    ui.jiagouTreeWidget->clear();
    ui.jiagouTreeWidget->setHeaderHidden(true);
    QString rootName = DEFAULT_GROUP_NAME;
    Biz::RosterGroup* pGroup = Biz::Session::currentAccount().getRootRosterGroup();
    if (pGroup!=NULL)
    {
        rootName = pGroup->name;
    }
    // 添加一个根成员
    QTreeWidgetItem* pRootItem = new QTreeWidgetItem(ui.jiagouTreeWidget);
    pRootItem->setSizeHint(0,GROUPSIZE);
    GroupItem_L* pGroupL = new GroupItem_L(NULL);
    pGroupL->setDisaplay(rootName);
    pGroupL->setTreeWidgetItemHolder(pRootItem);
    connect(pGroupL,&GroupItem_L::sgLoadItemsChild,this,&CreateNewGroup::onLoadItemsChild);
    ui.jiagouTreeWidget->addTopLevelItem(pRootItem);
    ui.jiagouTreeWidget->setItemWidget(pRootItem,0,pGroupL);

    // 添加以及群组
    createTreeItemChildren(rootName,pRootItem);

    // 展开成员
    pRootItem->setExpanded(true);
    ui.jiagouTreeWidget->setExpandsOnDoubleClick(false);
}

void CreateNewGroup::onLoadItemsChild(const QString& name, QTreeWidgetItem* pItem, bool checked)
{
    if (name.isEmpty() || NULL ==pItem)
    {
        return;
    }
    createTreeItemChildren(name,pItem,checked);
    pItem->setExpanded(true); 
}

void CreateNewGroup::onSearchEditInputChange(const QString& key)
{
    bool b = ui.tabDeps->isChecked();
    if(key.length() <=0 )
    {
        ui.stackedWidget->setCurrentWidget(ui.memberpage);
        return;
    }
    if (key.length()<3)
    {
        QTimeLine* pTimeLine = new QTimeLine(300);
        connect(pTimeLine,&QTimeLine::finished,[this,key,pTimeLine]{
            pTimeLine->deleteLater();
            QString strCurentText = ui.searchEdit->text();
            if (strCurentText == key)
            {
                auto callback = mCallbackReceiver->createCallback<QList<Biz::RosterNode*>>(
                    [this](QList<Biz::RosterNode*> results){
                        if(results.length() > 0)
                        {
                            rebuildSearchList(results.mid(0, results.size()>30?30:results.size()));
                        }

                        ui.searchEdit->activateWindow();
                        ui.searchEdit->setFocus();        

                },[]{});
                if (ui.tabDeps->isChecked())
                {
                    Biz::Session::getConverSationManager()->searchUserInOrganize(key,callback);
                }
                else
                {
                    Biz::Session::getConverSationManager()->searchUserInFriends(key, callback);
                }

            }
        });
        pTimeLine->start();
    }
    else
    {
        auto callback = mCallbackReceiver->createCallback<QList<Biz::RosterNode*>>(
            [this](QList<Biz::RosterNode*> results){
                if(results.length() > 0  )
                {
                    rebuildSearchList(results.mid(0, results.size()>30?30:results.size()));
                }
                ui.searchEdit->activateWindow();
                ui.searchEdit->setFocus();        

        },[]{});

        if (ui.tabDeps->isChecked())
        {
            Biz::Session::getConverSationManager()->searchUserInOrganize(key,callback);
        }
        else
        {
            Biz::Session::getConverSationManager()->searchUserInFriends(key, callback);
        }
    }
}


void CreateNewGroup::rebuildSearchList(const QList<Biz::RosterNode*>& searchResult)
{
    // 清除所有节点
    ui.searchTreeWidget->setHeaderHidden(true);
    ui.searchTreeWidget->clear();
    mLstItems.clear();
    m_mapSearchPersonsL.clear(); // 用于 右向左 状态同步
    foreach(Biz::RosterNode* pNode,searchResult)
    {
        // 将个人加在这
        QTreeWidgetItem* pPersonItem = new QTreeWidgetItem(ui.searchTreeWidget);
        pPersonItem->setSizeHint(0,MEMMBERSIZE);
        PersonItem_L* pGroupL = new PersonItem_L(NULL);
        pGroupL->setDisaplay(pNode->displayName);
        pGroupL->setTreeWidgetItemHolder(pPersonItem);
        pGroupL->setJid(pNode->userId);
        //pGroupL->setGroupBelong(pNode->group->getShortName(),pNode->group->getFullName());
        connect(pGroupL,&PersonItem_L::sgSelectPerson,this,&CreateNewGroup::onLSelectChange);
        ui.searchTreeWidget->addTopLevelItem(pPersonItem);
        ui.searchTreeWidget->setItemWidget(pPersonItem,0,pGroupL);
        mLstItems.push_back(pPersonItem);
        m_mapSearchPersonsL.insert(pNode->userId,pPersonItem);
    }

    if (mLstItems.size() > 0)
    {
        ui.stackedWidget->setCurrentWidget(ui.searchpage);
        ui.searchTreeWidget->setCurrentItem(mLstItems[0]);
        PersonItem_L* pWidget=(PersonItem_L*)ui.searchTreeWidget->itemWidget(mLstItems[0],0);
        pWidget->setActive(true);
    }
}

void CreateNewGroup::keyPressEvent(QKeyEvent *keyEvent)
{

    if (keyEvent->key() == Qt::Key_Down)
    {
        searchMoveDown();
        return ;
    }             
    else if (keyEvent->key() == Qt::Key_Up)
    {
        searchMoveUp();
        return ;
    } 
    else if (keyEvent->key() == Qt::Key_Return)
    {
        searchSelected();
        return ;
    } 
}

void CreateNewGroup::searchMoveDown()
{
    QTreeWidgetItem* pCurItem = ui.searchTreeWidget->currentItem();
    if (NULL!=pCurItem)
    {
        int index = mLstItems.indexOf(pCurItem);
        if (index>=0 && (index+1)<mLstItems.size())
        {
            QTreeWidgetItem* pNextItem = mLstItems[index+1];
            PersonItem_L* pWidget = NULL;
            if (NULL != (pWidget= (PersonItem_L*)ui.searchTreeWidget->itemWidget(pCurItem,0)))
            {
                pWidget->setActive(false);
            }
            if (NULL !=pNextItem && NULL != (pWidget=(PersonItem_L*)ui.searchTreeWidget->itemWidget(pNextItem,0)))
            {
                pWidget->setActive(true);
                ui.searchTreeWidget->setCurrentItem(pNextItem);
            }
        }
    }
}

void CreateNewGroup::searchMoveUp()
{
    QTreeWidgetItem* pCurItem = ui.searchTreeWidget->currentItem();
    if (NULL!=pCurItem)
    {
        int index = mLstItems.indexOf(pCurItem);
        if (index>0)
        {
            QTreeWidgetItem* pNextItem = mLstItems[index-1];
            PersonItem_L* pWidget = NULL;
            if (NULL != (pWidget=(PersonItem_L*)ui.searchTreeWidget->itemWidget(pCurItem,0)))
            {
                pWidget->setActive(false);
            }
            if (NULL !=pNextItem && NULL != (pWidget=(PersonItem_L*)ui.searchTreeWidget->itemWidget(pNextItem,0)))
            {
                pWidget->setActive(true);
                ui.searchTreeWidget->setCurrentItem(pNextItem);
            }
        }
    }
}

void CreateNewGroup::searchSelected()
{
    QTreeWidgetItem* pCurItem = ui.searchTreeWidget->currentItem();
    if (NULL!=pCurItem)
    {
        PersonItem_L* pWidget = NULL; 
        pWidget=(PersonItem_L*)ui.searchTreeWidget->itemWidget(pCurItem,0);
        if (NULL !=pWidget)
        {

            //m_mapPersonsCache.insert(pWidget->getDisplay(),pWidget->getJid());
            m_mapPersonsCache.insert(pWidget->getDisplay(),pWidget->getJid());

            addNewPerson2Right(pWidget->getJid(),pWidget->getDisplay()); // + 筛选回车点击
            mergeHeadCount();
            ui.searchEdit->setText("");
            ui.searchEdit->setFocus();
        }
    }

}
void CreateNewGroup::addNewPerson2Right(const QString& jid,const QString& displayName,bool closeable,bool stayTop)
{
    if (!m_mapPersonsR.contains(jid) )
    {
        if (closeable&&m_mapExistMembers.contains(jid))
        {
            return;
        }
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(MEMMBERSIZE_R);
        PersonItem_R* pWidget = new PersonItem_R(ui.listWidget);
        pWidget->setDisplayName(displayName);
        pWidget->setJid(jid);
        pWidget->setCloseable(closeable);
        connect(pWidget,&PersonItem_R::sgDeletePerson,this,&CreateNewGroup::onRDeletePerson);
        if (stayTop)
        {
            ui.listWidget->insertItem(0,pItem);
        }
        else
        {
            ui.listWidget->addItem(pItem);
        }

        ui.listWidget->setItemWidget(pItem,pWidget);
        m_mapPersonsR.insert(jid,pItem);
    }
    AdjuestCreateButton();
}

void CreateNewGroup::removePerson2Right(const QString& jid)
{
    if (m_mapPersonsR.contains(jid) && !m_mapExistMembers.contains(jid))
    {
        QListWidgetItem* pItem = m_mapPersonsR[jid];
        if (NULL != pItem)
        {
            int row = ui.listWidget->row(pItem);
            pItem = ui.listWidget->takeItem(row);
            delete pItem;
            m_mapPersonsR.remove(jid);
        }
    }
    if (m_mapPersonsCache.contains(jid))
    {
        m_mapPersonsCache.remove(jid);
    }
}


void CreateNewGroup::onLSelectChange(PersonItem_L* personL,bool selected)
{
    if (NULL == personL)
    {
        return;
    }
    PersonItem_L* pPersonL = NULL;
    QTreeWidgetItem* pCurItem = ui.jiagouTreeWidget->currentItem();
    if (NULL!=pCurItem && NULL !=(pPersonL=(PersonItem_L*)ui.jiagouTreeWidget->itemWidget(pCurItem,0)))
    {
        pPersonL->setActive(false);
    }
    // 体验不好，先干掉
    //     QTreeWidgetItem* pitem = personL->getTreeWidgetItemHolder();
    //     if (NULL!=pitem && NULL !=(pPersonL=(PersonItem_L*)ui.jiagouTreeWidget->itemWidget(pitem,0)))
    //     {
    //         pPersonL->setActive(true);
    //     }


    /////
    //m_mapPersonsCache.insert(personL->getDisplay(),personL->getJid());
    ////

    m_mapPersonsCache.insert(personL->getDisplay(),personL->getJid());

    if (selected)
    {
        addNewPerson2Right(personL->getJid(),personL->getDisplay()); // + 圆圈选中
        mergeHeadCount();
    }
    else
    {
        removePerson2Right(personL->getJid());
    }

    AdjuestCreateButton();
}

void CreateNewGroup::onRDeletePerson(const QString& jid)
{
    removePerson2Right(jid);

    if (m_mapPersonsL.contains(jid))
    {
        QTreeWidgetItem* item = m_mapPersonsL[jid];
        if (NULL != item)
        {
            PersonItem_L* pWidget = (PersonItem_L*)ui.jiagouTreeWidget->itemWidget(item,0);
            if (NULL != pWidget)
            {
                pWidget->setSelectedBtnChecked(false);
            }
        }
    }

    if (m_mapSearchPersonsL.contains(jid))
    {
        QTreeWidgetItem* item = m_mapSearchPersonsL[jid];
        if (NULL != item)
        {
            PersonItem_L* pWidget = (PersonItem_L*)ui.searchTreeWidget->itemWidget(item,0);
            if (NULL != pWidget)
            {
                pWidget->setSelectedBtnChecked(false);
            }
        }
        //判断群节点中是否还有被选中的，如果没有，则，群节点的勾被取消
        QTreeWidgetItem *itemgroup = m_mapGroups[jid];
        if (NULL != itemgroup)
        {
            GroupItem_L *pGroupWidget = dynamic_cast<GroupItem_L*>(ui.jiagouTreeWidget->itemWidget(itemgroup,0));
            if (NULL != pGroupWidget)
            {
                pGroupWidget->setSelectedBtnChecked(false);
                //setItemChildrenChecked(itemgroup,false);
            }
        }
    }

    m_mapPersonsCache.remove(m_mapPersonsCache.key(jid));
    mergeHeadCount();
    AdjuestCreateButton();
}


void CreateNewGroup::isCreateNewGroup(bool createnew)
{
    //ui.next->setVisible(createnew);
    ui.pushButton_creategroup->setVisible(createnew);
    ui.ok->setVisible(!createnew);

    if (createnew)
    {
        //setWindowTitle(QStringLiteral("新建群组"));
        //QString strtitle = T_("CreateGroup");
        setWindowTitle(T_("CreateGroup"));

        AdjuestCreateButton();

    }
    else
    {
        //setWindowTitle(QStringLiteral("邀请群成员"));
        setWindowTitle(T_("InviteInGroup"));
    }
}

void CreateNewGroup::setMemberList(const QMap<QString,QString>& membermap)
{
    m_mapExistMembers.clear();
    QMap<QString,QString>::const_iterator it;
    for(it = membermap.begin();it!=membermap.end();it++)
    {
        m_mapExistMembers.insert(it.key(),it.value());
        addNewPerson2Right(it.key(),it.value(),false); // + 存在
    }
    AdjuestCreateButton();
}

void CreateNewGroup::setItemChildrenChecked(QTreeWidgetItem* pItem,bool checked)
{
    int count = pItem->childCount();
    for (int  i=0; i<count; i++)
    {
        QTreeWidgetItem* subItem = pItem->child(i);
        if (NULL != subItem)
        {
            GroupItem_L* pgl = dynamic_cast<GroupItem_L*>(ui.jiagouTreeWidget->itemWidget(subItem,0));
            if (NULL != pgl)
            {
                pgl->setSelectedBtnChecked(checked);
                setItemChildrenChecked(subItem,checked);
            }
            PersonItem_L * ppl = dynamic_cast<PersonItem_L*>(ui.jiagouTreeWidget->itemWidget(subItem,0));
            if (NULL != ppl)
            {
                ppl->setSelectedBtnChecked(checked);
            }
        }
    }
}
void CreateNewGroup::onAddMembersInGroup(const QString& name,QTreeWidgetItem* pItem,bool checked)
{
    if (name.isEmpty() || NULL ==pItem)
    {
        return;
    }

    // 这个组里如果没成员，加成员
    if (pItem->childCount() == 0)
    {
		quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("createTreeitemChildren begin:") + QString(" -------> loginendime:%1").arg(getbegintickedtm));
        createTreeItemChildren(name,pItem,checked);
		quint64 getendtickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("createTreeitemChildren end:") + QString(" -------> loginendime:%1").arg(getendtickedtm));
    }
    else
    {
        setItemChildrenChecked(pItem,checked);
    }
    // 如果没展开，先展开
    if (!pItem->isExpanded())
    {
        // pItem->setExpanded(true);
    }
	QMap<QString, QString> tmpselectPerson;
    Biz::RosterGroup* rGroup = Biz::Session::currentAccount().findRosterGroup(name);
    if (NULL!=rGroup)
    {
		quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("createTreeitemChildren 加人员 begin:") + QString(" -------> loginendime:%1").arg(getbegintickedtm));
        // 加人员
        foreach(Biz::RosterNode* node,rGroup->getRosterListWithChildren()){
            QString userid = node->userId;
            QString userName = node->displayName;
            if (!checked)
            {
                m_mapPersonsCache.remove(userName);
                removePerson2Right(userid);
            }
            else
            {
                m_mapPersonsCache.insert(userName,userid);
                //addNewPerson2Right(userid,userName);
				if (!tmpselectPerson.contains(userid))
				{
					tmpselectPerson.insert(userid, userName);
				}
            }
        }
        cacheIndex = 0;
		//这里在进行addNewPerson2Right
		//GroupItem_L *pG = pItem->
		addPersonToRight(tmpselectPerson, pItem );

		quint64 getendtickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("createTreeitemChildren 加人员 end:") + QString(" -------> loginendime:%1").arg(getendtickedtm));
    }
}

void CreateNewGroup::onAddmember(bool b)
{
//     QStringList lst = m_mapPersonsR.keys();
// 
//     QStringList uidlstCache = m_mapPersonsCache.values();
//     lst.append(uidlstCache);
//     lst.append(m_mapExistMembers.keys());
//     lst = lst.toSet().toList();
	//新邀请的应该是不包含之前本来存在群中的人
	QStringList uidlstCache = m_mapPersonsCache.values();
	int tipCount = 10;
	if (uidlstCache.length() > tipCount)
	{
		QString message =  QString(QStringLiteral("您当前邀请了%1人，已超过%2人，请确定邀请所有人进群吗？").arg(uidlstCache.length()).arg(tipCount));
		bool ret = MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(message);
		if (!ret)
		{
			return;
		}
	}
    auto callback = mCallbackReceiver->createCallback<QStringList>([this](const QStringList& result){
         close();
    },[]{
        Log::e("reateNewGroup::onAddmember add member fail");
    });

    MainApp::UIFrame::getGroupsController()->inviteMembers(groupjid,uidlstCache,callback);
   
}
const int MAX_HC_STEP = 30;
void CreateNewGroup::onRightScrollBarValueChange(int value)
{
    QScrollBar* pbar = ui.listWidget->verticalScrollBar();
    if (pbar->maximum()-value<10)
    {
        innerBuildResultList(cacheIndex,MAX_HC_STEP);
    }
}

void CreateNewGroup::rebuildResultList()
{
    //清空数据
    cacheIndex = 0;
    ui.listWidget->clear();
    // m_mapPersonsR.clear();

    QMap<QString,QString>::const_iterator it;
    for(it = m_mapExistMembers.begin();it!=m_mapExistMembers.end();it++)
    {
        addNewPerson2Right(it.key(),it.value(),false); // + 已经存在
    }

    mergeHeadCount();

    // 创建现有的东西
    innerBuildResultList(cacheIndex,MAX_HC_STEP);

    AdjuestCreateButton();
}

void CreateNewGroup::innerBuildResultList(int begin,int step)
{
    int i = 0; // 已经画了几个
    int j=0; // 全队游标

    QMap<QString,QString>::iterator iter = m_mapPersonsCache.begin();
    for (;iter!=m_mapPersonsCache.end();iter++,j++)
    {
        if (i<step)
        {
            if (j>=begin)
            {
                addNewPerson2Right(iter.value(),iter.key()); // + 新建
                cacheIndex++;
                i++;
            }
        }
        else
        {
            break;
        }
    }

    AdjuestCreateButton();
}

void CreateNewGroup::mergeHeadCount()
{
    int count = m_mapPersonsCache.size();

    QStringList userids = m_mapPersonsCache.values();
    QStringList useridR = m_mapPersonsR.keys();
    foreach(QString userid,useridR)
    {
        if (!userids.contains(userid))
        {
            count++;
            userids.push_back(userid);
        }
    }

    QStringList useridex  = m_mapExistMembers.keys();
    foreach(QString userid,useridex)
    {
        if (!userids.contains(userid))
        {
            count++;
            userids.push_back(userid);
        }
    }
    ui.headcount->setText(T_("CREATE_NEW_GROUP_TIP").arg(count));

}

void  CreateNewGroup::onCreateGroupBtnClick()
{
    Log::e(QString("CreateNewGroup::onCreateGroupBtnClick"));
    QStringList uidlst = m_mapPersonsR.keys();
    QStringList uidlstCache = m_mapPersonsCache.values();
    uidlst.append(uidlstCache);
    uidlst = uidlst.toSet().toList();
	int tipCount = 10;
	if (uidlst.length() > tipCount)
	{
		QString message =  QString(QStringLiteral("您当前邀请了%1人，已超过%2人，请确定邀请所有人进群吗？").arg(uidlstCache.length()).arg(tipCount));
		bool ret = MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(message);
		if (!ret)
		{
			return;
		}
	}
    ui.pushButton_creategroup->setEnabled(false);
    auto callback = mCallbackReceiver->createCallback<QString>([this](const QString& groupjid){
        Log::e(QString("CreateNewGroup::onCreateGroupBtnClick callback success groupjid=%1").arg(groupjid));
        MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupjid);
        MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupjid,MainApp::ConversationController::sDefaultExtendPanel);
        MainApp::UIFrame::getConversationController()->activeConversation(groupjid);
        ui.pushButton_creategroup->setEnabled(true);
        this->close();
    },[this]{
        ui.pushButton_creategroup->setEnabled(true);
        Log::e(QString("CreateNewGroup::onCreateGroupBtnClick callback fail"));

        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (T_("CreateGroupMsg_Error"));
    });

    MainApp::UIFrame::getGroupsController()->createNewGroup(uidlst,callback);

}

void CreateNewGroup::AdjuestCreateButton()
{
    QStringList lst = m_mapPersonsR.keys();

    if (lst.count() > 0)
    {
        ui.pushButton_creategroup->setEnabled(true);
    }
    else
    {
        ui.pushButton_creategroup->setEnabled(false);
    }
}

void CreateNewGroup::onCreateGroupSuccess(const QString& groupid,const QString& groupname)
{
    this->groupjid = groupid;
    this->groupName = groupname;

    if (NULL!=resultCallback)
    {
        resultCallback->doCompleted(CREATE_GROUP_RESULT_SUCCESS);
    }
    // 回收资源
    this->close();
}

void CreateNewGroup::closeEvent(QCloseEvent *)
{
    this->deleteLater();
    CreateNewGroupSingleton::setNULLInstance();
}

void CreateNewGroup::onTabButtionClicked(bool bCheck)
{
    if (ui.tabFriend->isChecked())
    {
        ui.stackedWidget->setCurrentWidget(ui.memberpage);
        ui.memberstack->slideInWidget(ui.friendPage);
    }

    if (ui.tabDeps->isChecked())
    {
        ui.stackedWidget->setCurrentWidget(ui.memberpage);
        ui.memberstack->slideInWidget(ui.jiagoupage);
    }
}

void CreateNewGroup::showEvent(QShowEvent *)
{
    // 重新刷新 friend，deps的数据
    rebuildFriendList();

}

void CreateNewGroup::rebuildFriendList()
{
    // 清除所有节点
    QList<Biz::FriendsInfor> infos = Biz::Session::getFriendManager()->getFriendsInfo();
    ui.friendList->setHeaderHidden(true);
    ui.friendList->clear();
    QTreeWidgetItem* pFirstItem = NULL;
    foreach(const Biz::FriendsInfor& info,infos)
    {
        // 将个人加在这
        QTreeWidgetItem* pPersonItem = new QTreeWidgetItem(ui.friendList);
        pPersonItem->setSizeHint(0,MEMMBERSIZE);
        PersonItem_L* pGroupL = new PersonItem_L(NULL);
        pGroupL->setDisaplay(Biz::Session::currentAccount().getUserNameById(info.userid));
        pGroupL->setTreeWidgetItemHolder(pPersonItem);
        pGroupL->setJid(info.userid);
        connect(pGroupL,&PersonItem_L::sgSelectPerson,this,&CreateNewGroup::onFriendListSelectChange);
        ui.friendList->addTopLevelItem(pPersonItem);
        ui.friendList->setItemWidget(pPersonItem,0,pGroupL);

        if (pFirstItem == NULL)
        {
            pFirstItem = pPersonItem;
        }
    }

    ui.friendList->setCurrentItem(pFirstItem);
    //     PersonItem_L* pWidget=(PersonItem_L*)ui.friendList->itemWidget(pFirstItem,0);
    //     pWidget->setActive(true);
}

void CreateNewGroup::onFriendListSelectChange(PersonItem_L* personL,bool selected)
{
    if (NULL == personL)
    {
        return;
    }


    m_mapPersonsCache.insert(personL->getDisplay(),personL->getJid());

    if (selected)
    {
        addNewPerson2Right(personL->getJid(),personL->getDisplay()); // + 圆圈选中

    }
    else
    {
        removePerson2Right(personL->getJid());
    }

    mergeHeadCount();

    AdjuestCreateButton();
}

void CreateNewGroup::addPersonToRight( const QMap<QString, QString>& maplist, QTreeWidgetItem* pItem )
{
	if (!UIFrame::getGroupsController()->checkNewLimitedCount(maplist.size()))
	{
		//pItem->setCheckState(0,Qt::CheckState::Unchecked);
		return;
	}
	
	for (QString onekey: maplist.keys())
	{
		addNewPerson2Right(onekey, maplist.value(onekey));
	}
}

