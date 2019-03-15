#include "groupfileview.h"

#include <QFileIconProvider>
#include <QFileDialog>
#include <QProgressBar>
#include "diywidgit/customviews/qframelayout.h"
#include "jsonobject/messagefileextendsobject.h"
#include "XmppMessage.h"
#include "UiHelper.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "attachmentmanager.h"
#include "MessageManager.h"
#include "loginmanager.h"
#include "conversationmanager.h"

#include "UtilHelper.h"

#include "editablesettings.h"
#include "SettingData.h"

#include "UIFrame.h"
#include "groupscontroller.h"
#include "animationreactor.h"
#include "ConversationController.h"
#include "NotifyCenterController.h"

#include "conversationselectwidget.h"




void GroupFileOperator::onOpen()
{
    // 存在即打开
    QString extendInfo = m_spMessage->Body ();
    Biz::MessageFileExtendsObject mfeo(NULL);
    mfeo.unserializeFromString (extendInfo);
    QString strDownloadUrl = mfeo.HttpUrl ();
    strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);
    // url  在本地的缓存文件
    QString newurl = UtilHelper::addMsgIdParamToUrl (strDownloadUrl,m_spMessage->MessageID ());
    QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
        Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (newurl);
    if (spAttach.isNull ())
        return;

    QString strfile = spAttach->LOCALCOPY ();
#ifdef _WINDOWS
    strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif // _WINDOWS

    if (QFile::exists (strfile))
    {
        QProcess::startDetached("explorer \""+strfile+"\"");
    }
    else
    {
        QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());
        QProcess::startDetached("explorer \""+localPath+"\"");
        Log::e(QString("local file cann't find msgid %1").arg(m_spMessage->MessageID ()));
    }

}

void GroupFileOperator::onDownload(Biz::UnitCallback<QString>* dlcb)
{
    if (!m_spMessage.isNull ())
    {
        QString msgid = m_spMessage->MessageID ();
        Biz::Session::getAttachmentManager ()->dowloadAttachFile (msgid,dlcb);
    }
}

void GroupFileOperator::onOpenDir()
{

    QString extendInfo = m_spMessage->Body ();
    Biz::MessageFileExtendsObject mfeo(NULL);
    mfeo.unserializeFromString (extendInfo);
    QString strDownloadUrl = mfeo.HttpUrl ();
    strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);
    // url  在本地的缓存文件
    QString newurl = UtilHelper::addMsgIdParamToUrl (strDownloadUrl,m_spMessage->MessageID ());
    QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
        Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (newurl);
    if (spAttach.isNull ())
        return;

    QString strfile = spAttach->LOCALCOPY ();
#ifdef _WINDOWS
    strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif // _WINDOWS

    if (QFile::exists (strfile))
    {
#ifdef _WINDOWS
        QString cmd = "explorer /select,\\" + strfile;
        QProcess::startDetached("explorer /select," + strfile);
#else
        strfile.replace("\\", "/");
        QProcess::execute("nautilus " +  strfile + "\"");
#endif
    }
    else
    {
        QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());
#ifdef _WINDOWS
        localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
        QProcess::startDetached("explorer /select,\""+localPath+"\"");
        Log::e(QString("local file cann't find msgid %1").arg(m_spMessage->MessageID ()));
#else
        localPath.replace("\\", "/");
        QProcess::execute("nautilus "+ localPath + +"\"");
#endif
    }
}

void GroupFileOperator::onSaveAs(Biz::UnitCallback<QString>* callback)
{
    // 1 选择保存路径，输入默认保存地址和默认保存文件名
    QString extendInfo = m_spMessage->Body ();
    Biz::MessageFileExtendsObject mfeo(NULL);
    mfeo.unserializeFromString (extendInfo);

    QString saveAsPath = MainApp::makeDefaultSavePath ();
#ifdef _WINDOWS
    saveAsPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#else
    saveAsPath.replace("\\","/");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif

    QString strextername = QFileInfo(mfeo.FileName()).suffix ();
    QString suffixname = strextername.isEmpty()?"All files(*.*)":QString("Files (*.%1)").arg(strextername);

    QString saveFileName = QFileDialog::getSaveFileName(0, "Save File", mfeo.FileName (), suffixname);
    if (saveFileName.isEmpty ())
    {
        return;
    }

    // 2查看本地文件是否已经存在

    QString strDownloadUrl = mfeo.HttpUrl ();
    strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);
    // url  在本地的缓存文件
    QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
        Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (strDownloadUrl);

    QString strfile;
    if (!spAttach.isNull ())
    {
        strfile = spAttach->LOCALCOPY ();
    }


    auto saveasFuntion = [this,saveFileName](QString strfile){
     
        QString targetPath = saveFileName;
        if (!strfile.isEmpty () && !targetPath.isEmpty())
        {
            UtilHelper::copyFileToPath(strfile, targetPath, true);
            QString newSaveAdDir = QFileInfo(targetPath).absoluteDir().absolutePath();
            Biz::Session::getEditableSettings()->DefaultSaveAsPath(newSaveAdDir);
            Biz::Session::saveEditableSettings();

#ifdef _WINDOWS
            QString cmd = "explorer /select,\\" + targetPath;
            targetPath.replace("/","\\");
            QProcess::startDetached("explorer /select," + targetPath);
#else
            targetPath.replace("\\", "/");
            QProcess::execute("nautilus " +  targetPath + "\"");
#endif
        }
        else
        {
            Log::e(QString("local file cann't find msgid %1").arg(m_spMessage->MessageID ()));
        }
    };

    if (QFile::exists (strfile))
    {
        saveasFuntion(strfile);
    }
    else
    {
        auto dlcbSuccess    = [this,callback,saveasFuntion](const QString& path){
            saveasFuntion(path);
            if (NULL!=callback)
            {
                callback->doCompleted (path);
            }
        };

        auto dlcbFail       = [this,callback]{
            if (NULL!=callback)
            {
                callback->doFailure ();
            }
        };
        auto dlCB = MainApp::UIFrame::getGroupsController ()->createCallback<QString> (dlcbSuccess,dlcbFail);

        if (!m_spMessage.isNull ())
        {
            QString msgid = m_spMessage->MessageID ();
            Biz::Session::getAttachmentManager ()->downloadAttachFileSaveTo (msgid,saveFileName,dlCB);
        }

    }
}

void GroupFileOperator::onShare()
{
    if (m_spMessage.isNull ())
        return;

    QString conversationid = m_spMessage->ConversationID ();
    ConversationSelectWidgetSingleton::getInstance()->setConversationDataList();
    ConversationSelectWidgetSingleton::getInstance()->setExceptConversationIds(QStringList(conversationid));
    ConversationSelectWidgetSingleton::getInstance()->exec();

    QString sendToConversationId = ConversationSelectWidgetSingleton::getInstance()->conversationId();
    if (!sendToConversationId.isEmpty())
    {
        auto getMessageByIdCallback = MainApp::UIFrame::getConversationController ()->createCallback<QSharedPointer<Biz::XmppMessage>>([this,sendToConversationId](const QSharedPointer<Biz::XmppMessage>& spMessage){
            QString oldid = spMessage->MessageID();

            spMessage->MessageID("");
            spMessage->ConversationID(sendToConversationId);
            spMessage->MsgDirection(Biz::MessageTypeSelf);
            spMessage->UtcTime(Biz::Session::getLoginManager()->getServerTimeWithOffset());
            spMessage->MsgSourceType(sendToConversationId.contains("conference")?Biz::GroupMessage:Biz::ChatMessage);
            auto callback = MainApp::UIFrame::getConversationController ()->createCallback([this,sendToConversationId]()
            {
                if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",QStringLiteral("转发成功，是否跳转到新会话?"),QStringLiteral("取消"),QStringLiteral("确定")))
                {
                    MainApp::UIFrame::getConversationController()->activeConversation(sendToConversationId);
                    MainApp::UIFrame::getConversationController()->moveSessionToTop(sendToConversationId);
                    emit Biz::Session::getConverSationManager()->sgReloadConversationMsg(sendToConversationId);
                }

            }, [this,spMessage,sendToConversationId,oldid]{
                QString nenwid = spMessage->MessageID();
                Log::e(QStringLiteral("转发失败 send msg %1 (to:%3) to conversation %2").arg(sendToConversationId,oldid,nenwid));
            });

            Biz::Session::currentAccount().doSendMessage(spMessage,callback,NULL);
        },[]{});
        Biz::Session::getMessageManager()->getMessageById(m_spMessage->MessageID (),getMessageByIdCallback);
    }
}





GroupFileView::GroupFileView(QWidget* parent)
    : QWidget(parent)
{
    m_spFileOperator = QSharedPointer<GroupFileOperator>(new GroupFileOperator);

    this->setFixedHeight (33);
    this->setObjectName ("GroupFileView");

    QFrameLayout* pRootLayout = new QFrameLayout(this);
    QWidget* pwidget = new QWidget(this);
    pwidget->setObjectName ("fileinfopannel");
    QFrameLayout* pDisplayLayout = new QFrameLayout(pwidget);
    m_pIconLabel = new QLabel(pwidget);
    m_pIconLabel->setFixedSize (20,20);
    m_pTitle = new QLabel(pwidget);
    m_pTitle->setAlignment (Qt::AlignVCenter);

    m_pProgressBar = new QProgressBar(pwidget);
    m_pProgressBar->setObjectName ("progress");
    m_pProgressBar->setRange (0,100);
    m_pProgressBar->setFixedHeight (3);
    m_pProgressBar->setVisible (false);
    m_pProgressBar->setEnabled (true);

    pDisplayLayout->appendWidget (m_pIconLabel,ALINE_VCENTER|ALINE_LEFT,QMargins(10,0,0,0));
    pDisplayLayout->appendWidget (m_pTitle,ALINE_MATCHHEIGHT|ALINE_LEFT,QMargins(40,0,0,0));
    pDisplayLayout->appendWidget (m_pProgressBar,ALINE_MATCHWIDTH|ALINE_BOTTOM,QMargins(40,0,0,0));

    pwidget->setLayout (pDisplayLayout);


    QWidget* pFunctionsWidget = new QWidget(this);
    pFunctionsWidget->setObjectName ("functionPannel");
    QHBoxLayout*  horizontalLayout = new QHBoxLayout(pFunctionsWidget);


    horizontalLayout->setSpacing(3);
    horizontalLayout->setContentsMargins(10, 0, 10, 0);
    QSpacerItem* horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  //  horizontalLayout->addItem(horizontalSpacer);

    QPushButton* pDownBtn   = createFuntionButton (pFunctionsWidget);
    pDownBtn->setText (QStringLiteral("下载"));
    connect (pDownBtn,&QPushButton::clicked,this,&GroupFileView::onDownloadFileClicked);
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
    connect (pSaveAsBtn,&QPushButton::clicked,this,&GroupFileView::onSaveAsClicked);
    horizontalLayout->addWidget (pSaveAsBtn);

    QPushButton* pOpenDirBtn   = createFuntionButton (pFunctionsWidget);
    pOpenDirBtn->setText (QStringLiteral("位置"));
    connect (pOpenDirBtn,&QPushButton::clicked,[this]{m_spFileOperator->onOpenDir ();});
    m_pLocaltion = pOpenDirBtn;
    horizontalLayout->addWidget (pOpenDirBtn);

    QPushButton* pTransformBtn   = createFuntionButton (pFunctionsWidget);
    pTransformBtn->setText (QStringLiteral("转发"));
    connect (pTransformBtn,&QPushButton::clicked,[this]{m_spFileOperator->onShare ();});
    horizontalLayout->addWidget (pTransformBtn);

    pFunctionsWidget->setLayout (horizontalLayout);
    pFunctionsWidget->setVisible (false);
    m_pFuntionsWidget = pFunctionsWidget;

    pRootLayout->appendWidget (pwidget,ALINE_FILL);
    pRootLayout->appendWidget (pFunctionsWidget,ALINE_FILL);
    this->setLayout (pRootLayout);

     connect (Biz::Session::getAttachmentManager (),&Biz::AttachmentManager::sgDownloadProgressDisplay,this,&GroupFileView::onDownloadProgressDisplay);
	 connect (Biz::Session::getAttachmentManager (),&Biz::AttachmentManager::sgDownloadProgressFinish,this,&GroupFileView::onDownloadProgressFinish);
}


GroupFileView::~GroupFileView()
{

}

QPushButton* GroupFileView::createFuntionButton(QWidget* parent)
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

void GroupFileView::enterEvent(QEvent * event)
{
    if (NULL!=m_pFuntionsWidget)
    {
        m_pFuntionsWidget->setVisible (true);
    }
}

void GroupFileView::leaveEvent(QEvent * event)
{
    if (NULL!=m_pFuntionsWidget)
    {
        m_pFuntionsWidget->setVisible (false);
    }
}

void GroupFileView::setMessage(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
    if (!spMessage.isNull () && Biz::MediaTypeFile == spMessage->MediaType ())
    {
        m_spFileOperator->m_spMessage = spMessage;
        QString extendInfo = spMessage->Body ();
        Biz::MessageFileExtendsObject mfeo(NULL);
        mfeo.unserializeFromString (extendInfo);
        QString fileName = mfeo.FileName ();

        QString displayName = MainApp::getMaxLineCountLimitText (fileName,m_pTitle->width (),1,m_pTitle->font ());
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
      
		QPixmap iconPixmap = MainApp::getFileIcon (strfile, QSize(20, 20));
		m_pIconLabel->setScaledContents (true);
		m_pIconLabel->setPixmap (iconPixmap);
	

        m_pBtnDownload->setVisible (!QFile::exists (strfile));
        m_pBtnOpen->setVisible (QFile::exists (strfile));
        m_pLocaltion->setEnabled (QFile::exists (strfile));
    }
}



void GroupFileView::onDownloadFileClicked(bool b)
{
    auto dlcbSuccess    = [this](const QString& path){
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
    };
    auto dlCB = MainApp::UIFrame::getGroupsController ()->createCallback<QString> (dlcbSuccess,dlcbFail);
    m_spFileOperator->onDownload (dlCB);
}

void GroupFileView::onSaveAsClicked(bool b)
{
    auto dlcbSuccess    = [this](const QString& path){
        // 下载成功,1秒钟后滚动条淡入淡出的消失
        /*QTimeLine* pTimeLine = new QTimeLine(1000);
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

void GroupFileView::onDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total)
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
			m_pProgressBar->setVisible(false);
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

void GroupFileView::onDownloadProgressFinish( const QString&key, const QString& fileName, const QString& filePath )
{
	if (!m_spFileOperator.isNull () 
		&& !m_spFileOperator->m_spMessage.isNull ()
		&& key == m_spFileOperator->m_spMessage->MessageID())
	{
		MainApp::saveFileIcon (filePath);
	
		QPixmap iconPixmap = MainApp::getFileIcon (filePath, QSize(28,28));
		m_pIconLabel->setPixmap (iconPixmap.scaled (28,28,Qt::KeepAspectRatio,Qt::SmoothTransformation));

		//收尾工作
		m_pBtnDownload->setVisible (false);
		m_pBtnOpen->setVisible (!m_pBtnDownload->isVisible ());
		m_pLocaltion->setEnabled (!m_pBtnDownload->isVisible ());
	}
}

