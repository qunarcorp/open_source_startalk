#include "groupfilelistview.h"

#include <QPushButton>
#include <QFileIconProvider>
#include <QGraphicsDropShadowEffect>
#include <QDateTime>

#include "ui_groupfilelistview.h"
#include "animationreactor.h"

#include "BizCallback.h"
#include "CallbackReceiver.h"
#include "MessageListData.h"

#include "Session.h"
#include "MessageManager.h"
#include "attachmentmanager.h"
#include "Account.h"

#include "XmppMessage.h"
#include "diywidgit/customviews/qframelayout.h"

#include "groupfileview.h"

#include "jsonobject/messagefileextendsobject.h"

#include "ConfigureHelper.h"
#include "UiHelper.h"

#include "UIFrame.h"
#include "groupscontroller.h"

#include "UiHelper.h"

GroupFileListView::GroupFileListView(QWidget *parent)
    : LocalManDialog(parent)
    , m_pCallbackReceiver(NULL)
{
    m_pCallbackReceiver = new Biz::CallbackReceiver(this);
   

    ui = new Ui::GroupFileListView();
    ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
	// WindowStaysOnTopHint add by wangchao // 子窗口默认显示在父窗口上方
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Tool | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(QStringLiteral("群文件"));

    auto titlebar = ui->titlebar;
    titlebar->setMaxable(false);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &GroupFileListView::onMin);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &GroupFileListView::onMin);

    ui->stackedWidget->setCurrentWidget(ui->emptypage);
     m_pAdater = new GroupFileListViewAdapter(ui->treeWidget);
    ui->treeWidget->setItemDelegate(m_pAdater);

    ui->treeWidget->setExpandsOnDoubleClick(false);
    ui->treeWidget->setIndentation(0);
    ui->treeWidget->setHeaderHidden(true);
}

GroupFileListView::~GroupFileListView()
{
    delete ui;
}

void GroupFileListView::showEvent(QShowEvent *event)
{
    AnimationReactorSingleton::getInstance ()->opacityInWidget (this,100);
    // getallgroupmessage
}

void GroupFileListView::refreshFileMessage(const QString& conversationId)
{
    ui->treeWidget->clear();
    ui->stackedWidget->setCurrentWidget(ui->emptypage);

    auto getFilesSuccess    = [this](const QSharedPointer<Biz::MessageListData>& messagelist){
        if (!messagelist->getMessageList ().isEmpty ())
        {
            ui->stackedWidget->setCurrentWidget(ui->listpage);
            m_pAdater->setMessageList (messagelist);
        }
    };
    auto getFilesFail       = []{};
    Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* uicb = 
        m_pCallbackReceiver->createCallback<QSharedPointer<Biz::MessageListData>> (getFilesSuccess,getFilesFail);
    Biz::Session::getMessageManager ()->getAllFileMessage (conversationId,uicb);

    this->show();
    this->activateWindow ();
}



GroupListFileItemView::GroupListFileItemView(QWidget* parent)
    : QWidget(parent)
{
    m_spFileOperator = QSharedPointer<GroupFileOperator>(new GroupFileOperator);
     this->setFixedHeight (54);

    QWidget* pRootWidget = new QWidget(this);
    pRootWidget->setObjectName ("GroupListFileItemView");
    pRootWidget->setFixedHeight (44);
    QFrameLayout* pR = new QFrameLayout(this);
    pR->appendWidget (pRootWidget,ALINE_VCENTER|ALINE_MATCHWIDTH);
    this->setLayout (pR);

    QLabel* pIconLabel = new QLabel(pRootWidget);
    pIconLabel->setScaledContents (false);
    pIconLabel->setText ("");
    pIconLabel->setObjectName ("iconlabel");
    pIconLabel->setFixedSize (46,42);
    pIconLabel->setAlignment (Qt::AlignHCenter|Qt::AlignVCenter);
    m_pIconLabel = pIconLabel;


    QLabel* pDisplay = new QLabel(pRootWidget);
    pDisplay->setText ("");
    pDisplay->setObjectName ("display");
    pDisplay->setFixedHeight (42);
    m_pTitle = pDisplay;

    QWidget* pFunctionsWidget = new QWidget(pRootWidget);
    pFunctionsWidget->setFixedSize (160,42);
    pFunctionsWidget->setObjectName ("functionPannel");
    QHBoxLayout*  horizontalLayout = new QHBoxLayout(pFunctionsWidget);


    horizontalLayout->setSpacing(3);
    horizontalLayout->setContentsMargins(10, 0, 10, 0);

    QPushButton* pDownBtn   = createFuntionButton (pFunctionsWidget);
    pDownBtn->setText (QStringLiteral("下载"));
    connect (pDownBtn,&QPushButton::clicked,this,&GroupListFileItemView::onDownloadFileClicked);
    horizontalLayout->addWidget(pDownBtn);
    m_pBtnDownload = pDownBtn;

    QPushButton* pOpenBtn   = createFuntionButton (pFunctionsWidget);
    pOpenBtn->setText (QStringLiteral("打开"));
    connect (pOpenBtn,&QPushButton::clicked,[this]{m_spFileOperator->onOpen ();});
    horizontalLayout->addWidget (pOpenBtn);
    m_pBtnOpen = pOpenBtn;

    QPushButton* pSaveAsBtn   = createFuntionButton (pFunctionsWidget);
    pSaveAsBtn->setFixedWidth (40);
    pSaveAsBtn->setText (QStringLiteral("另存为"));
    connect (pSaveAsBtn,&QPushButton::clicked,this,&GroupListFileItemView::onSaveAsClicked);
    horizontalLayout->addWidget (pSaveAsBtn);

    QPushButton* pOpenDirBtn   = createFuntionButton (pFunctionsWidget);
    pOpenDirBtn->setText (QStringLiteral("位置"));
    connect (pOpenDirBtn,&QPushButton::clicked,[this]{m_spFileOperator->onOpenDir ();});
    horizontalLayout->addWidget (pOpenDirBtn);
    m_pLocaltion = pOpenDirBtn;

    QPushButton* pTransformBtn   = createFuntionButton (pFunctionsWidget);
    pTransformBtn->setText (QStringLiteral("转发"));
    connect (pTransformBtn,&QPushButton::clicked,[this]{m_spFileOperator->onShare ();});
    horizontalLayout->addWidget (pTransformBtn);

    pFunctionsWidget->setLayout (horizontalLayout);


    m_pProgressBar = new QProgressBar(pRootWidget);
    m_pProgressBar->setObjectName ("progress");
    m_pProgressBar->setRange (0,100);
    m_pProgressBar->setFixedHeight (3);
    m_pProgressBar->setVisible (false);
    m_pProgressBar->setEnabled (true);



    QFrameLayout* pLayout = new QFrameLayout(pRootWidget);
    pLayout->appendWidget (pIconLabel,ALINE_VCENTER|ALINE_LEFT,QMargins(1,1,0,1));
    pLayout->appendWidget (pDisplay,ALINE_VCENTER|ALINE_MATCHWIDTH,QMargins(48,1,160,1));
    pLayout->appendWidget (pFunctionsWidget,ALINE_VCENTER|ALINE_RIGHT,QMargins(0,1,1,1));
    pLayout->appendWidget (m_pProgressBar,ALINE_BOTTOM|ALINE_MATCHWIDTH,QMargins(48,1,0,1));

   
    pRootWidget->setLayout (pLayout);

    connect (Biz::Session::getAttachmentManager (),&Biz::AttachmentManager::sgDownloadProgressDisplay,this,&GroupListFileItemView::onDownloadProgressDisplay);
	connect (Biz::Session::getAttachmentManager (),&Biz::AttachmentManager::sgDownloadProgressFinish,this,&GroupListFileItemView::onDownloadProgressFinish);

}

QPushButton* GroupListFileItemView::createFuntionButton(QWidget* parent)
{
    QPushButton* pNewBtn = new QPushButton(parent);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(pNewBtn->sizePolicy().hasHeightForWidth());
    pNewBtn->setSizePolicy(sizePolicy);
    pNewBtn->setFlat(true);
    return pNewBtn;
}

GroupListFileItemView::~GroupListFileItemView()
{

}

void GroupListFileItemView::setMessage(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
    if (!spMessage.isNull () && Biz::MediaTypeFile == spMessage->MediaType ())
    {
        m_spFileOperator->m_spMessage = spMessage;
        QString extendInfo = spMessage->Body ();
        Biz::MessageFileExtendsObject mfeo(NULL);
        mfeo.unserializeFromString (extendInfo);
        QString fileName = mfeo.FileName ();

        QString displayName = MainApp::getMaxLineCountLimitText (fileName,250,1,m_pTitle->font ());
        m_pTitle->setText (displayName);
        m_pTitle->setToolTip (fileName);

        // icon 如果文件已经下载了，就用文件自身的icon，如果文件没有下载就用默认的icon,等文件下载完毕之后再更换一次icon

        QString strDownloadUrl = mfeo.HttpUrl ();
        strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);

        // url  在本地的缓存文件
        QString newurl = UtilHelper::addMsgIdParamToUrl (strDownloadUrl,spMessage->MessageID ());
        QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
            Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (newurl);

        QString strfile;
        if (!spAttach.isNull ())
        {
            strfile = spAttach->LOCALCOPY ();
#ifdef _WINDOWS
            strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif // _WINDOWS
        }	
			
		QPixmap iconPixmap = MainApp::getFileIcon (strfile, QSize(28, 28));
		m_pIconLabel->setPixmap (iconPixmap.scaled (28,28,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		
        m_pBtnDownload->setVisible (!QFile::exists (strfile));
        m_pBtnOpen->setVisible (QFile::exists (strfile));
        m_pLocaltion->setEnabled (QFile::exists (strfile));
    }
}

void GroupListFileItemView::onDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total)
{
    if (NULL!= m_pProgressBar
        && !m_spFileOperator.isNull () 
        && !m_spFileOperator->m_spMessage.isNull ()
        && key == m_spFileOperator->m_spMessage->MessageID ()
        )
    {
        m_pProgressBar->setEnabled (true);
       
        int myvalue = 0;
        if (total == 0)
            myvalue = 0;
        else
            myvalue = qBound((qint64)0,done*100/total,(qint64)100);

        m_pProgressBar->setValue (myvalue);
        m_pProgressBar->setVisible (true);

		if (done == total)
		{
			m_pProgressBar->setVisible (false);
			// 下载成功,1秒钟后滚动条淡入淡出的消失
// 			QTimeLine* pTimeLine = new QTimeLine(1000);
// 			connect (pTimeLine,&QTimeLine::finished,[this,pTimeLine]{
// 				pTimeLine->deleteLater ();
// 				AnimationReactorSingleton::getInstance ()->opacityOutWidget (m_pProgressBar,100);
// 			});
// 
// 			pTimeLine->start ();
		}

    }
}

void GroupListFileItemView::onDownloadFileClicked(bool b)
{
    auto dlcbSuccess    = [this](const QString& path){
		//这个地方暂时不要了，因为在下载中，和下载完成中把这两个都做了
        /*// 下载成功,1秒钟后滚动条淡入淡出的消失
        QTimeLine* pTimeLine = new QTimeLine(1000);
        connect (pTimeLine,&QTimeLine::finished,[this,pTimeLine,path]{
            pTimeLine->deleteLater ();
            m_pBtnDownload->setVisible (false);
            m_pBtnOpen->setVisible (!m_pBtnDownload->isVisible ());
            m_pLocaltion->setEnabled (!m_pBtnDownload->isVisible ());

            AnimationReactorSingleton::getInstance ()->opacityOutWidget (m_pProgressBar,100);
            MainApp::saveFileIcon (path);
            QIcon fileIcon = MainApp::getFileIcon (path);
            QPixmap iconPixmap = fileIcon.pixmap(QSize(28,28));
            m_pIconLabel->setPixmap (iconPixmap.scaled (28,28,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        });

        pTimeLine->start ();*/
    };

    auto dlcbFail       = [this]{
        m_pProgressBar->setEnabled (false);
        QTimeLine* pTimeLine = new QTimeLine(1000);
        connect (pTimeLine,&QTimeLine::finished,[this,pTimeLine]{
            pTimeLine->deleteLater ();
            AnimationReactorSingleton::getInstance ()->opacityOutWidget (m_pProgressBar,100);
        });
		 pTimeLine->start ();
    };
    auto dlCB = MainApp::UIFrame::getGroupsController ()->createCallback<QString> (dlcbSuccess,dlcbFail);
    m_spFileOperator->onDownload (dlCB);
}

void GroupListFileItemView::onSaveAsClicked(bool b)
{
    auto dlcbSuccess    = [this](const QString& path){
        // 下载成功,1秒钟后滚动条淡入淡出的消失
       /* QTimeLine* pTimeLine = new QTimeLine(1000);
        connect (pTimeLine,&QTimeLine::finished,[this,pTimeLine,path]{
            pTimeLine->deleteLater ();
            m_pBtnDownload->setVisible (false);
            m_pBtnOpen->setVisible (!m_pBtnDownload->isVisible ());
            m_pLocaltion->setEnabled (!m_pBtnDownload->isVisible ());

            AnimationReactorSingleton::getInstance ()->opacityOutWidget (m_pProgressBar,100);

            MainApp::saveFileIcon (path);
            QIcon fileIcon = MainApp::getFileIcon (path);
            QPixmap iconPixmap = fileIcon.pixmap(QSize(28,28));
            m_pIconLabel->setPixmap (iconPixmap.scaled (28,28,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        });

        pTimeLine->start ();*/
    };

    auto dlcbFail       = [this]{
        m_pProgressBar->setEnabled (false);
        QTimeLine* pTimeLine = new QTimeLine(1000);
        connect (pTimeLine,&QTimeLine::finished,[this,pTimeLine]{
            pTimeLine->deleteLater ();
            AnimationReactorSingleton::getInstance ()->opacityOutWidget (m_pProgressBar,100);
        });
    };
    auto dlCB = MainApp::UIFrame::getGroupsController ()->createCallback<QString> (dlcbSuccess,dlcbFail);
    m_spFileOperator->onSaveAs (dlCB);
}

void GroupListFileItemView::onDownloadProgressFinish( const QString&key, const QString& fileName, const QString& filePath )
{
	if (!m_spFileOperator.isNull () 
		&& !m_spFileOperator->m_spMessage.isNull ()
		&& key == m_spFileOperator->m_spMessage->MessageID())
	{
		MainApp::saveFileIcon (filePath);
	
		QPixmap iconPixmap = MainApp::getFileIcon (filePath, QSize(28, 28));
		m_pIconLabel->setPixmap (iconPixmap.scaled (28,28,Qt::KeepAspectRatio,Qt::SmoothTransformation));

		//收尾工作
		m_pBtnDownload->setVisible (false);
		m_pBtnOpen->setVisible (!m_pBtnDownload->isVisible ());
		m_pLocaltion->setEnabled (!m_pBtnDownload->isVisible ());
	}
}





GroupFileListViewAdapter::GroupFileListViewAdapter(QAbstractItemView* parent)
    : ListWidgetBaseAdapter(parent)
{
  
}
GroupFileListViewAdapter::~GroupFileListViewAdapter()
{

}

QWidget* GroupFileListViewAdapter::CreateNewWidget(const QModelIndex& index)
{
    int type = index.data (GroupFileListViewAdapter::FILELISTDATA_TYPE).toInt ();
    if (GroupFileListItemType::GroupFileListItemTypePinned == type)
    {
        QLabel* pLabel = new QLabel;
        pLabel->setText (index.data(FILELISTDATA_DISPLAY).toString ());
        pLabel->setAlignment (Qt::AlignVCenter|Qt::AlignLeft);
        pLabel->setObjectName ("pinned");

        QWidget* pRootWidget = new QWidget();
        pRootWidget->setFixedHeight (28);
        QFrameLayout* pR = new QFrameLayout(pRootWidget);
        pR->appendWidget (pLabel,ALINE_FILL);
        pRootWidget->setLayout (pR);
        return pRootWidget;
    }
    else
    {
       GroupListFileItemView* pItemView = new GroupListFileItemView(NULL);
       QString messageid = index.data(GroupFileListViewAdapter::FILELISTDATA_ID).toString ();
       QSharedPointer<Biz::XmppMessage> spMessage = m_messages.value (messageid);
       pItemView->setMessage (spMessage);
       return pItemView;
    }
}

QSize GroupFileListViewAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int type = index.data (GroupFileListViewAdapter::FILELISTDATA_TYPE).toInt ();
    if (GroupFileListItemType::GroupFileListItemTypePinned == type)
    {
        return QSize(28,28);
    }
    else
    {
        return QSize(54,54);
    }
}



QTreeWidgetItem* GroupFileListViewAdapter::findGroup(quint64 lasttime)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    if (NULL!=pTreeWidget)
    {
        int topLevelItem = pTreeWidget->topLevelItemCount ();
        for (int i=0; i < topLevelItem;i++)
        {
            QTreeWidgetItem* pItem = pTreeWidget->topLevelItem(i);
            quint64 nMin = pItem->data (0,FILELISTDATA_RANGE_MIN).toULongLong ();
            quint64 nMax = pItem->data (0,FILELISTDATA_RANGE_MAX).toULongLong ();
            if (nMin <= lasttime && lasttime < nMax)
            {
                return pItem;
            }
        }
    }
    return NULL;
}

void GroupFileListViewAdapter::setMessageList(const QSharedPointer<Biz::MessageListData>& messageList)
{

    if (messageList.isNull ())
        return ;
    
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    pTreeWidget->clear ();
    m_messages.clear ();
//     treeWidgetItemMaps.clear ();
//     treeWidgetRangeMaps.clear ();
	
    for (QSharedPointer<Biz::XmppMessage> spMessage: messageList->getMessageList ())
    {
        if (spMessage.isNull ())
            continue;
        m_messages.insert (spMessage->MessageID (),spMessage);
        
        quint64 lasttime = spMessage->UtcTime ();
        QTreeWidgetItem* pParentItem = findGroup (lasttime);
        if (NULL == pParentItem)
        {
            // 创建组，这里半写死就可以
            QDateTime dt = QDateTime::currentDateTime ();
            dt.setTime(QTime());
            dt = dt.addDays (-1);
            quint64 currentTimeStamp = QDateTime::currentMSecsSinceEpoch () - Biz::Session::currentAccount ().getTimeOffsetFromServer ();
            quint64 baseTimeStame = dt.toMSecsSinceEpoch()-Biz::Session::currentAccount ().getTimeOffsetFromServer ();

            QList<QPair<QPair<quint64,quint64>,QString>> groupDatas;
            groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(baseTimeStame,currentTimeStamp),QStringLiteral("今天")));
            groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(baseTimeStame-60*60*24*1000,baseTimeStame),QStringLiteral("1天前")));
            groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(baseTimeStame-60*60*24*1000*4,baseTimeStame-60*60*24*1000),QStringLiteral("3天前")));
            groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(0,baseTimeStame-60*60*24*1000*4),QStringLiteral("更早")));


            for (QPair<QPair<quint64,quint64>,QString> pair:groupDatas)
            {
                if (lasttime >= pair.first.first)
                {
                    GroupFileMessageItem* pItem = new GroupFileMessageItem;
                    pItem->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
                    pItem->setData (0,FILELISTDATA_TYPE,GroupFileListItemTypePinned);
                    pItem->setData (0,FILELISTDATA_RANGE_MIN,pair.first.first);
                    pItem->setData (0,FILELISTDATA_RANGE_MAX,pair.first.second);
                    pItem->setData (0,FILELISTDATA_DISPLAY,pair.second);
                    pItem->setData (0,FILELISTDATA_ID,pair.second);
                    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
					
					pTreeWidget->addTopLevelItem(pItem);
                   pParentItem = pItem;
                  //  treeWidgetRangeMaps.insert (pair.second,pItem);
                    break;
                }
            }
        }
        if (NULL!=pParentItem)
        {
            GroupFileMessageItem* pItem = new GroupFileMessageItem;
            pItem->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
            pItem->setData (0,FILELISTDATA_TYPE,GroupFileListItemTypeData);
            pItem->setData (0,FILELISTDATA_TIMESTAMP,lasttime);
            pItem->setData (0,FILELISTDATA_DISPLAY,spMessage->ConversationID ());
            pItem->setData (0,FILELISTDATA_ID,spMessage->MessageID ());
            //treeWidgetItemMaps.insert (spMessage->ConversationID (),pItem);
            pParentItem->addChild (pItem);
        }

    }

    pTreeWidget->expandAll ();
}
