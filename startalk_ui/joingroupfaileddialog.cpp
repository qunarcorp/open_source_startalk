#include "JoinGroupFailedDialog.h"
#include <QTime>
#include "Session.h"
#include "Account.h"
#include "QXmppUtils.h"

#include "GroupManager.h"

GroupJoinFailedItem::GroupJoinFailedItem(QWidget *parent)
    : QWidget(parent)
    , pContainerLst(NULL)
{
    ui.setupUi(this);

    connect(ui.rejoin,&QPushButton::clicked,this,&GroupJoinFailedItem::onReJoinCliecked);
    connect(ui.pushButton_2,&QPushButton::clicked,this,&GroupJoinFailedItem::onLeftCliecked);
}

GroupJoinFailedItem::~GroupJoinFailedItem()
{

}

void GroupJoinFailedItem::reset()
{
    ui.rejoin->setEnabled(true);
    ui.pushButton_2->setEnabled(true);
}

void GroupJoinFailedItem::onReJoinCliecked(bool)
{
    ui.rejoin->setEnabled(false);
    ui.pushButton_2->setEnabled(false);

    QTimer::singleShot(500,this,SLOT(onReJoinGroup()));
}

void GroupJoinFailedItem::onLeftCliecked(bool)
{

    Biz::Session::getGroupManager()->leaveGroup(id);

    emit removeItem(id);
}

void GroupJoinFailedItem::rejoin()
{
    this->onReJoinCliecked(false);
}

void GroupJoinFailedItem::onReJoinGroup()
{
   //Biz::Session::getGroupManager()->joinGroup(id);
}

void GroupJoinFailedItem::setGroupJid(const QString& groupJid)
{
    id = groupJid;
    QString groupname = Biz::Session::currentAccount().getGroupNickName(groupJid);
    if (groupname.isEmpty())
    {
        groupname = Biz::MessageUtil::makeSureUserId(groupJid);
    }
    ui.groupname->setText(groupname);
}

JoinGroupFailedDialog* JoinGroupFailedDialog::pInstance = NULL;

JoinGroupFailedDialog::JoinGroupFailedDialog(LocalManWidget *parent)
    : LocalManWidget(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Tool;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));


    auto titlebar = ui.titlebar;
    titlebar->setSizeable(false);
    titlebar->setLeftTitle(QStringLiteral("以下群加入失败"));
    titlebar->setMaxable(false);
    titlebar->setMinable(false);
    

    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &JoinGroupFailedDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &JoinGroupFailedDialog::onClose);

    // bind accouts signal
    connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupJoinedSuccess,this,&JoinGroupFailedDialog::onGroupJoinSuccess);
    connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupJoidFailed,this,&JoinGroupFailedDialog::onGroupJoinFail);
    
    // bind self signals;
    connect(ui.pushButton,&QPushButton::clicked,this,&JoinGroupFailedDialog::rejoinAllClicked);
}

JoinGroupFailedDialog::~JoinGroupFailedDialog()
{
    disconnect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupJoinedSuccess,this,&JoinGroupFailedDialog::onGroupJoinSuccess);
    disconnect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupJoidFailed,this,&JoinGroupFailedDialog::onGroupJoinFail);
}

JoinGroupFailedDialog* JoinGroupFailedDialog::getInstance()
{
    if (NULL == pInstance)
    {
        pInstance = new JoinGroupFailedDialog(NULL);
    }
    return pInstance;
}

// 有可能被重入
void JoinGroupFailedDialog::addJoinFailedGroup(const QString& groupJid)
{
    if (!items.contains(groupJid))
    {
        QListWidgetItem* item = new QListWidgetItem(ui.listWidget);
        GroupJoinFailedItem* itemView = new GroupJoinFailedItem(NULL);
        itemView->setGroupJid(groupJid);
        item->setSizeHint(itemView->sizeHint());
        ui.listWidget->addItem(item);
        ui.listWidget->setItemWidget(item,itemView);
        items.insert(groupJid,item);

        connect(itemView,&GroupJoinFailedItem::removeItem,this,&JoinGroupFailedDialog::onGroupJoinSuccess);
    }
    else
    {
        QListWidgetItem* item = items[groupJid];
        GroupJoinFailedItem* itemView = NULL;
        if (NULL!=item &&
            NULL!= (itemView = (GroupJoinFailedItem*)ui.listWidget->itemWidget(item)) &&
            groupJid == itemView->groupJid())
        {
            itemView->reset();
        }
    }
}

void JoinGroupFailedDialog::onGroupJoinSuccess(const QString& groupjid)
{
    if (items.contains(groupjid))
    {
         QListWidgetItem* item = items[groupjid];
        int row = ui.listWidget->row(item);
        GroupJoinFailedItem* itemView = (GroupJoinFailedItem*)ui.listWidget->itemWidget(item);
        ui.listWidget->takeItem(row);
        itemView->deleteLater();
        items.remove(groupjid);
    }

    if (0==ui.listWidget->count())
    {
        this->hide();
        this->deleteLater();
        pInstance = NULL;
    }
}

void JoinGroupFailedDialog::onGroupJoinFail(const QString& groupid)
{
    addJoinFailedGroup(groupid);
}

void JoinGroupFailedDialog::rejoinAllClicked(bool)
{
    foreach(QListWidgetItem* item, items.values()){
        GroupJoinFailedItem* itemView = NULL;
        if (NULL!=item &&
            NULL!= (itemView = (GroupJoinFailedItem*)ui.listWidget->itemWidget(item)) )
        {
            itemView->rejoin();
        }
    }
}
