#include "SelectContactDialog.h"
#include "CallbackReceiver.h"
#include "RosterList.h"
#include "Session.h"
#include "Account.h"
#include "rosterItem.h"
#include "GroupVisitorMVD.h"
#include "LanguageHelper.h"
#include "QXmppUtils.h"
#include "TitlebarWidget.h"
#include <QKeyEvent>
#include "../LocalManBiz/SpellHelper.h"
#include "RosterList.h"

SelectContactDialog::SelectContactDialog(QWidget *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);
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

    auto titlebar = ui.titlebarWidget;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgMaxOnClicked, this, &LocalManDialog::onMax);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &SelectContactDialog::onClose);

    connect(ui.leftTreeView, &QTreeView::clicked, this, &SelectContactDialog::onLeftSelectChanged);
    connect(ui.leftTreeView, &QListWidget::doubleClicked, this, &SelectContactDialog::onLeftItemDBClicked);
    

    connect(ui.rightWidget, &QListWidget::itemSelectionChanged, this, &SelectContactDialog::onRightSelectChanged);
    connect(ui.rightWidget, &QListWidget::itemDoubleClicked, this, &SelectContactDialog::onRightItemDBClicked);
   

    ui.addBtn->setEnabled(false);
    ui.delBtn->setEnabled(false);
    ui.btnOK->setText(T_("MessageBox_Confirm"));
    ui.btnCancel->setText(T_("MessageBox_Cancel"));

    connect(ui.addBtn, &QPushButton::clicked, this, &SelectContactDialog::onAddClicked);
    connect(ui.delBtn, &QPushButton::clicked, this, &SelectContactDialog::onDelClicked);
    connect(ui.btnOK, &QPushButton::clicked, this, &SelectContactDialog::onOK);
    connect(ui.btnCancel, &QPushButton::clicked, this, &SelectContactDialog::onCancel);
    
    ui.lineEdit->installEventFilter(this);
    connect(ui.lineEdit, &QLineEdit::textChanged, this, &SelectContactDialog::onSearchTextChanged);
    ui.lineEdit->setFocus();
    
    searchResultDlg = new SearchResultDialog(this);
    connect(searchResultDlg, &SearchResultDialog::sgItemSelected, this, &SelectContactDialog::onSearchResult);


    ui.titlebarWidget->setLeftTitle(T_("SelectContactDialog_Title"));
    this->setWindowTitle(T_("SelectContactDialog_Title"));
    
    connect(&Biz::Session::currentAccount(), &Biz::Account::sgRosterListChanged, ui.leftTreeView, &RosterTreeView::onRosterListChanged );
    ui.leftTreeView->setExpandsOnDoubleClick(false);
     ui.leftTreeView->setStyleSheet(
        " QTreeView::branch:has-siblings:!adjoins-item {                   "
        "     border-image: none;                                "
        " }                                                                "
        "                                                                  "
        " QTreeView::branch:has-siblings:adjoins-item {                    "
        "     border-image: none;                          "
        " }                                                                "
        "                                                                  "
        " QTreeView::branch:!has-children:!has-siblings:adjoins-item {     "
        "     border-image: none;                            "
        " }                                                                "
        "                                                                  "
        " QTreeView::branch:has-children:!has-siblings:closed,             "
        " QTreeView::branch:has-children:!has-siblings:closed,             "
        " QTreeView::branch:closed:has-children:has-siblings {             "
        "         border-image: none;                                      "
        "         image: url(:/Images/branch-closed.png);                           "
        " }                                                                "
        "                                                                  "
        " QTreeView::branch:open:has-children:!has-siblings,               "
        " QTreeView::branch:open:has-children:has-siblings  {              "
        "         border-image: none;                                      "
        "         image: url(:/Images/branch-closed.png);                             "
        " }                                                                "       );
     ui.leftTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

SelectContactDialog::~SelectContactDialog()
{
    delete searchResultDlg;
}

void SelectContactDialog::onLeftSelectChanged(const QModelIndex &index)
{
    ui.addBtn->setEnabled(true);
}
void SelectContactDialog::onRightSelectChanged()
{
    //只有从左边选中过来的人才能删除，原来群里有的人不能删
    if(ui.rightWidget->selectedItems().count() > 0)
    {
        QString strRightText = ui.rightWidget->selectedItems().at(0)->text();
        bool bFound = false;
        for(QString str : mSelectedList)
        {
            if(str == strRightText)
            {
                bFound = true;
                break;
            }
        }
        if(bFound)
             ui.delBtn->setEnabled(true);
        else
             ui.delBtn->setEnabled(false);
    }
}
void SelectContactDialog::onAddClicked(bool)
{
    QModelIndexList miList = ui.leftTreeView->selectionModel()->selectedIndexes();
    foreach(QModelIndex itemIndex, miList)
    {
        QModelIndex currentIndex = itemIndex;
        if( currentIndex.isValid() )
        {
            QString groupName = currentIndex.data(rosterItem::GroupFullName).toString();
            if(!groupName.isEmpty())
            {
                //添加本组内成员
                Biz::RosterGroup* rosterGroup =  Biz::Session::currentAccount().findRosterGroup(groupName);
                addNodeToRight(rosterGroup);


                ////是群组 加里面所有人
                //int rowCount = ui.leftTreeView->model()->rowCount(currentIndex);
                //for(int i = 0; i < rowCount; ++i)
                //{
                //    QModelIndex idx = ui.leftTreeView->model()->index(i, 0, currentIndex);
                //    addNodeToRight(idx);
                //}
            }else{
                //是个人
                QString strName = currentIndex.data(rosterItem::DisplayName).toString();   
                if (!strName.isEmpty() && !mSelectedList.contains(strName))
                {
                    ui.rightWidget->addItem(new QListWidgetItem(strName));
                    mSelectedList.append(strName);
                }   
            }
        }
    }
    
}
void SelectContactDialog::addNodeToRight(Biz::RosterGroup* rosterGroup)
{
    if(rosterGroup)
    {
        foreach (Biz::RosterNode* node, rosterGroup->getRosterList())
        {
            QString strName = node->displayName;
            if (!strName.isEmpty() && !mSelectedList.contains(strName))
            {
                ui.rightWidget->addItem(new QListWidgetItem(strName));
                mSelectedList.append(strName);
            }   
        }

        foreach (Biz::RosterGroup* node, rosterGroup->getGroupList())
        {
            addNodeToRight(node);            
        }
    }
}

void SelectContactDialog::onDelClicked(bool)
{
    if(ui.rightWidget->selectedItems().count() > 0)
    {
        QString strName = ui.rightWidget->selectedItems().at(0)->text();
        ui.rightWidget->takeItem(ui.rightWidget->row(ui.rightWidget->selectedItems().at(0)));
        mSelectedList.removeOne(strName);
    }
}

void SelectContactDialog::onOK(bool)
{   
    this->accept();
}

void SelectContactDialog::onCancel(bool)
{
    this->reject();
}

QList<QPair<QString,QString>> SelectContactDialog::getSelectedItem()
{
    QList<QPair<QString,QString>> resultList;
    for(QString str : mSelectedList)
    {
        QString uid = Biz::Session::currentAccount().getUserIDByName(str);
        if (uid.isEmpty())
        {
            uid = str;
        }
        resultList.append(QPair<QString,QString>(str, uid) );
//         QMap<QString, QString>::iterator itr = mMapNameJid.find(str);
//         if(itr != mMapNameJid.end())
//         {
//             resultList.append(QPair<QString,QString>(str, itr.value()) );
//         }
    }
    return resultList;

}


void SelectContactDialog::onLeftItemDBClicked(const QModelIndex &index)
{
    QModelIndex currentIndex = ui.leftTreeView->currentIndex();
    if( currentIndex.isValid() )
        AddItem(currentIndex.data(rosterItem::DisplayName).toString());
}
void SelectContactDialog::onRightItemDBClicked(QListWidgetItem *pItem)
{
    if(pItem)
    {
        QString strName = ui.rightWidget->selectedItems().at(0)->text();
        ui.rightWidget->takeItem(ui.rightWidget->row(pItem));
        mSelectedList.removeOne(strName);
    }
}

void SelectContactDialog::onClose(bool)
{
     this->reject();
     close();
}
void SelectContactDialog::AddItem(QString strName)
{
    if(strName.length() > 0 && !mSelectedList.contains(strName))
    {
        ui.rightWidget->addItem(new QListWidgetItem(strName));
        mSelectedList.append(strName);
    }
}

//pGrouListData是群列表，会添加到右边
void SelectContactDialog::setGroupList(GroupVisitorModel* pGrouListData){

    //left 取好友列表
//     auto callback = mReceiver->createCallback<QSharedPointer<Biz::RosterList>>([this, pGrouListData](const QSharedPointer<Biz::RosterList>& rosterList )
//     {
//         //保存左边列表
//         for(Biz::RosterItem* pItem : rosterList->rosters())
//         {
//             mMapNameJid[pItem->displayName] = pItem->userId;
//             //mMapJidName[pItem->userId] =  pItem->displayName;            
//         }               
// 
//         //删除已经在群里的人
//         //left: 有@的全jid  right:只有username
//         if( pGrouListData )
//         {
//             for(int i=0; i<pGrouListData->rowCount(); i++ )
//             {
//                 QString rightNameStr = pGrouListData->item(i)->text();
//                 if( mMapNameJid.contains(rightNameStr) )
//                 {
//                     //QString strName = mMapJidName[rightNameStr];
//                     //mMapJidName.remove(rightNameStr);
//                     mMapNameJid.remove(rightNameStr);
//                 }
//             }
//         }
//        
//         //添加到控件
//         QStringList strRosterList;
//         QMap<QString,QString>::iterator it; 
//         for ( it = mMapNameJid.begin(); it != mMapNameJid.end(); ++it ) 
//         {
//             strRosterList.append(it.key());
//             QString strPY = Biz::SpellHelper::MakeSpellCode(it.key(),(Biz::SpellHelper::SpellOptions)0);
//             mMapPinYinName[strPY.toLower()] = it.key();
//         }
//         ui.leftWidget->addItems(strRosterList);
//         if( pGrouListData )
//         {
//             for(int i=0; i<pGrouListData->rowCount(); i++ )
//                 ui.rightWidget->addItem( new QListWidgetItem(pGrouListData->item(i)->text()));
//         }
//        
// 
//     }, []{});
//     Biz::Session::currentAccount().getRosters(callback);  

    QStringList strRosterList;
    Biz::Session::currentAccount().findRosterUsers("",strRosterList);

    //ui.leftWidget->addItems(strRosterList);

    if( pGrouListData )
    {
        for(int i=0; i<pGrouListData->rowCount(); i++ )
            ui.rightWidget->addItem( new QListWidgetItem(pGrouListData->item(i)->text()));
    }

};

bool SelectContactDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui.lineEdit) 
    {
        if (event->type() == QEvent::KeyPress) 
        {
            QKeyEvent *keyEvent = reinterpret_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Down)
            {
                SearchMoveDown();
                return true;
            }             
            else if (keyEvent->key() == Qt::Key_Up)
            {
                SearchMoveUp();
                return true;
            } 
            else if (keyEvent->key() == Qt::Key_Return)
            {
                SearchSelected();
                return true;
            } 
        }else if(event->type() == QEvent::FocusOut)
        {
            if( !searchResultDlg->isActiveWindow())
                searchResultDlg->hide();
        }
    }
    return QWidget::eventFilter(obj, event);
}

void SelectContactDialog::SearchMoveDown()
{
    searchResultDlg->setMoveDown();
}
void SelectContactDialog::SearchMoveUp()
{
    searchResultDlg->setMoveUp();
}
void SelectContactDialog::SearchSelected()
{
    searchResultDlg->selectItem();
}

void SelectContactDialog::onSearchResult(const QString& text)
{
    QString key = text.left(text.indexOf(" "));
    QStringList resultList;

    /*Biz::Session::currentAccount().findRosterUsers(key,resultList);
    //ui.leftTreeView->searchContact(key, resultList);
    if(resultList.length() == 1){
        QString strName = key;   
        if (!mSelectedList.contains(strName))
        {
            ui.rightWidget->addItem(new QListWidgetItem(strName));
            mSelectedList.append(strName);
        }   
    }*/

	QString strName = key;   
	if (!mSelectedList.contains(strName))
	{
		ui.rightWidget->addItem(new QListWidgetItem(strName));
		mSelectedList.append(strName);
	}   
}

void SelectContactDialog::onSearchTextChanged(const QString & text)
{
    if(text.length() <=0 )
    {
        //ui.searchEdit->setVisible(false);
        searchResultDlg->hide();
        return;
    }

    QList<Biz::RosterNode*> list;
    Biz::Session::currentAccount().findRosterUsers(text, list); 

    if(list.length() > 0)
    {
        QStringList resultList;
        foreach(Biz::RosterNode* node , list)
        {
            QString strGroup;
            if(node->group)
            {
                strGroup = node->group->getFullName() ;
                //去掉第一个/前的内容
                if(strGroup.indexOf("/") != -1)
                {
                    strGroup = strGroup.mid(strGroup.indexOf("/")+1);
                    strGroup = "[" + strGroup.left(strGroup.length()-1) + "]";
                }
            }
            resultList.append(node->displayName + " " + strGroup);
        }
        searchResultDlg->setList(resultList);
        searchResultDlg->resize(QSize(400, 200));
        QPoint editPos = ui.lineEdit->mapToGlobal(ui.lineEdit->pos());
        searchResultDlg->move(editPos.rx()- ui.lineEdit->pos().rx(), editPos.ry() + ui.lineEdit->height() - ui.lineEdit->pos().ry());
        if(!searchResultDlg->isVisible())
            searchResultDlg->show();
        searchResultDlg->setFocus();

        ui.lineEdit->activateWindow();
        ui.lineEdit->setFocus();        
    }else{
        searchResultDlg->hide();
    }
}

void SelectContactDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (!searchResultDlg->isHidden())
	{
		QPoint editPos = ui.lineEdit->mapToGlobal(ui.lineEdit->pos());
		searchResultDlg->move(editPos.rx()- ui.lineEdit->pos().rx(), editPos.ry() + ui.lineEdit->height() - ui.lineEdit->pos().ry());
	}
	LocalManDialog::mouseMoveEvent(event);
}

