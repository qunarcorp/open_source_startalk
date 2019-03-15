#include "Ordermanagedialog.h"
#include <QClipboard>
#include <QDesktopServices>
#include <QMenu>
#include <QInputDialog>
#include "InnerWebBrowserrObject.h"
#include "TitlebarWidget.h"
#include "Session.h"
#include "Account.h"
#include "WebService.h"
#include "AccountData.h"
#include "accountmanager.h"
#include "DownloadManager.h"

#include "WebPage.h"
#include "diywidgit/customviews/qframelayout.h"
#include "UserSettingData.h"
#include "editablesettings.h"

#include "ConfigureHelper.h"


#include "CallbackReceiver.h"
#include "BizCallback.h"
#ifndef Q_NO_AMR
#include "amrgit/AudioPlayer.h"
#endif // !Q_NO_AMR
#include "ChatCommObject.h"
#include "SystemConfigData.h"
#include "UIFrame.h"
#include "ConversationController.h" 

OrderManageDialog::OrderManageDialog(QWidget *parent)
	: LocalManDialog(parent)
    ,ui(new Ui::OrderManageDialog)
	,mCommObject(new InnerWebBrowserrObject(this))
    , mReceiver(new Biz::CallbackReceiver(this))
	, mwebrtcCommObject(new ChatCommObject(this))
{
	ui->setupUi(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	// WindowStaysOnTopHint add by wangchao //子窗口默认显示在父窗口上
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	
	setWindowTitle("");

	auto titlebar = ui->titlebar;
	titlebar->setSizeable(true);
	titlebar->setMaxable(false);
    

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &OrderManageDialog::onMin);

	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &OrderManageDialog::onClose);
	setSizeGripEnabled(true);
#if (defined _WINDOWS) && !(defined WIN64)
    ui->verticalLayout->addWidget(ui->webView);
#endif // _WINDOWS

	mPage = new WebPage(this);
	ui->webView->setPage(mPage);
	connect(mCommObject, &InnerWebBrowserrObject::sgCloseBrowser, this, &OrderManageDialog::onJsCloseBrowser);
    mPage->addChatChannelToHtml("ClientApi", mCommObject);
    mCommObject->setWebPage(mPage);
    connect (mCommObject,&WebViewCommObject::sgOpenUrlInInnerWebBrowser,[this](const QString& url){ 
        QMap<QString,QString> contextInfo;
        contextInfo.insert ("fromjid","");
        contextInfo.insert ("chattype","");
        CommentWebViewSingleton::getInstance()->openCommonUrlWithCookie(QUrl(url).toEncoded(),contextInfo);
    });
    connect (mCommObject,&InnerWebBrowserrObject::sgPlayAudio,this,&OrderManageDialog::onPlayVodio);
    connect (mCommObject,&InnerWebBrowserrObject::sgStopAudio,[]{
#ifndef Q_NO_AMR
        VoicePlayerSingleton::getInstance ()->stopCurrentPlayingVoice ();
#endif //Q_NO_AMR
    });

	QFrameLayout* ptitleLayout = new QFrameLayout(ui->titlepanel);
	ptitleLayout->appendWidget(ui->lbTitle,ALINE_FILL);
	ptitleLayout->appendWidget(ui->pbLoad,ALINE_MATCHWIDTH|ALINE_TOP,QMargins(10,0,10,0));
	ptitleLayout->appendWidget(ui->btnBack,ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,0,0));
	ptitleLayout->appendWidget(ui->btnMenu,ALINE_RIGHT|ALINE_VCENTER,QMargins(0,0,10,0));

	connect(ui->webView,&webview::loadProgress,[this](int progress){
		ui->pbLoad->setVisible(true);
		ui->pbLoad->setValue(progress);
	});
	connect(ui->webView,&webview::loadFinished,[this]{ui->pbLoad->setVisible(false);});
	connect(ui->webView,&webview::titleChanged,[this](const QString& title){
        QFontMetrics elidfont(ui->lbTitle->font());
        QString elidedText = elidfont.elidedText(title, Qt::ElideRight, qMax(300,qMin(300, ui->lbTitle->width())));
        ui->lbTitle->setText(elidedText);
        ui->lbTitle->setToolTip(title);
        setWindowTitle(title);
    });
	connect(ui->btnBack,&QPushButton::clicked,[this]{ui->webView->back();});


    QMenu* pMenu = new QMenu(this);
    QAction* pAction = NULL;
    pAction = pMenu->addAction(QStringLiteral("使用默认浏览器打开"));
    connect(pAction,&QAction::triggered,[this]{
        QDesktopServices bs;        
        QUrl url = ui->webView->url();
        QString sc = url.scheme();
        if (sc.isEmpty())
        {
            url.setScheme("http");
        }
        bs.openUrl(url);
    });

    pAction = pMenu->addAction(QStringLiteral("复制链接地址"));
    connect(pAction,&QAction::triggered,[this]{
        QString url = ui->webView->url().toString();
        if (!url.isEmpty())
        {
            QClipboard *board = QApplication::clipboard();  
            board->setText(url);
        }
    });



    pAction = pMenu->addAction(QStringLiteral("刷新"));
    connect(pAction,&QAction::triggered,[this]{ui->webView->reload();});

    pMenu->addSeparator();

    pAction = pMenu->addAction(QStringLiteral("打开一个新的网址..."));
    connect(pAction, &QAction::triggered, [this] {
        bool isOK;
        QString text = QInputDialog::getText(
            NULL,
            QStringLiteral("输入网址"), 
            QStringLiteral("输入网址"), 
            QLineEdit::Normal, 
            "", &isOK);
        if (isOK) {

            QUrl url(QUrl(text).toEncoded());
            QString sc = url.scheme();
            if (sc.isEmpty())
            {
                url.setScheme("http");
            }
            ui->webView->load(url);
        }
    });

    connect(ui->btnMenu,&QPushButton::clicked,[this,pMenu]{pMenu->exec(QCursor::pos());});
	//打开页面中的链接
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	connect(mPage, &WebPage::openLink, this, &OrderManageDialog::onOpenLink);
	connect(mPage, &WebPage::ButtonClicked, this, &OrderManageDialog::onButtonClicked);
#endif
    this->installEventFilter(this);

	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/html/help_loading.html";
	QUrl url = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(url);

}

OrderManageDialog::~OrderManageDialog()
{

}

void OrderManageDialog::showQiangdanDlg()
{
	showNormal();
	activateWindow();
	setQunarCookie();

	ui->webView->load(Biz::Session::getSystemConfig()->getqcGrabOrder());
}

void OrderManageDialog::showOrderManageDlg()
{
	showNormal();
	activateWindow();
    setQunarCookie();
	ui->webView->load(Biz::Session::getSystemConfig()->getqcOrderManager());//Biz::Session::getEditableSettings()->OrderList()
}

void OrderManageDialog::onMin()
{
	this->hide();
}

void OrderManageDialog::onClose()
{
	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/html/help_loading.html";
	QUrl url = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(url);
	this->close();
}

void OrderManageDialog::showHistoryRecordDlg()
{
	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/html/help_loading.html";
	QUrl urltmp = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(urltmp);

	QString url = Biz::Session::getSystemConfig()->getSimpleapiUrl();
	url += Biz::Session::getEditableSettings()->ESUrl();
	showNormal();
	activateWindow();
    setQunarHistoryRecordCookie();
    ui->webView->load(url);
}


void OrderManageDialog::showSystemOrNoticeUrl(const QString&strurl)
{
	showNormal();
	activateWindow();
	QUrl url = QUrl(strurl);

    setQunarCookie();
	ui->webView->load(url);
}

void OrderManageDialog::openCommonUrl(const QString& url)
{
	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/html/help_loading.html";
	QUrl urltmp = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(urltmp);

    mPage->setContextInfo (QMap<QString,QString>());
    showNormal();
    activateWindow(); 
	setQunarCookie(); 

	ui->webView->load(url);
	Log::e("OrderManageDialog::openCommonUrl : " + url);
}

void OrderManageDialog::openWebRtcOrAudio(const QString&url, int type)
{
	mPage->setContextInfo(QMap<QString, QString>());
	showNormal();
	activateWindow();

	//ChatCommObject* mCommObject = new ChatCommObject(this);
	ui->webView->load(url);
	Log::e("OrderManageDialog::openWebRtcOrAudio : " + url);
	mPage->addChatChannelToHtml("client", mwebrtcCommObject);
	if (type == 0)
	{
		QString strjsfun = "receiveRtcAudio()";
		mPage->runLocalJavaScript(strjsfun);
	}
	else if (type == 1)
	{
		QString strjsfun = "receiveRtc()";
		mPage->runLocalJavaScript(strjsfun);
	}
}

void OrderManageDialog::openCommonUrlWithCookie(const QString& url, const QMap<QString, QString>& cookies)
{
	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/html/help_loading.html";
	QUrl urltmp = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(urltmp);

    mPage->setContextInfo (cookies);
    showNormal();
    activateWindow();
	setQunarCookie();
    ui->webView->load(url);
    Log::e("OrderManageDialog::openCommonUrlWithCookie : " + url);
}

void OrderManageDialog::setQunarCookie()
{
	WebPage::addQuaryCookie(
        ui->webView, 
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->QCookie(),
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->VCookie(),
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->TCookie()); 
}

void OrderManageDialog::setQunarHistoryRecordCookie()
{
	QString strDomain = Biz::Session::getSystemConfig()->getXmppDomain();
	WebPage::addQuaryHistoryCookie(ui->webView, WebService::sU.toLatin1()
		, WebService::sSecurityKey.toLatin1(), strDomain);
}
void OrderManageDialog::onJsCloseBrowser(int code)
{
    this->onClose();
}

void OrderManageDialog::showHtmlContent(const QString& content)
{
    this->showNormal();
    this->activateWindow();
    QString strHtml = QString("<html><body><div style='word-wrap: break-word;word-break:break-all;'>%1</div></body></html>").arg(content);
    ui->webView->setHtml(strHtml);
}

void OrderManageDialog::showActiveDlg()
{
	this->showNormal();
	this->activateWindow();
}


void OrderManageDialog::onOpenLink( const QUrl& url )
{
	QDesktopServices::openUrl(url);  
}

void OrderManageDialog::onPlayVodio(const QString& url)
{
    if (url.isEmpty ())
        return;
    QString fileName = Biz::ConfigureHelper::GetBufferMD5 (url);
    

    auto playaudio = [url,this](const QString& localpath){
        mCommObject->audioStartPlay (mPage,url);
        if (!QFile::exists (localpath))
        {
            Log::e (QString("play sound error is not exist"));
            mCommObject->audoPlayError(mPage,url,"1");
        }
        auto finishcb   = [this,url]{
            mCommObject->audioFinishPlay (mPage,url);
        };
        auto errorcb    = [this,url](int code,QString error){
            Log::e (QString("play sound error %1 : %2").arg (code).arg (error));
            mCommObject->audoPlayError(mPage,url,"1");
        };
#ifndef Q_NO_AMR
        VoicePlayerSingleton::getInstance ()->playLocalVoice (localpath,finishcb,errorcb);
#endif //Q_NO_AMR
    };

    Biz::ProgressedUnitCallback<QString,qint64>* progressedcb = mReceiver->createProgressCallback<QString,qint64>(
        [this,url,playaudio](const QString& path)
    {
        mCommObject->audioPlayerReady (mPage,url);
        playaudio(path);
    },
        [this,url](qint64 done,qint64 total){
            qint64 progress = done*100/total;
            mCommObject->audioDownloadProgress (mPage,url,QString::number (progress));
    },
        [this,url]{
            mCommObject->audoPlayError(mPage,url,"0");
    });

    if(!url.isEmpty())
        Biz::Session::getDownLoadManager()->downloadFileWithProgress(url,fileName,"","",false,progressedcb);
}

void OrderManageDialog::onButtonClicked( const QUrl& url )
{
	QString strurl = url.toString();
	
	//QString decode = QUrl::	fromPercentEncoding(strurl.toUtf8());


	QString loginRes1 = QString("qchat://open_singlechat");
	
	if ( strurl.contains(loginRes1))
	{

		QUrlQuery query(url);



		QString userid = query.queryItemValue("userid");

		userid = QUrl::	fromPercentEncoding(userid.toUtf8());
		
		QString urlappend = query.queryItemValue("urlappend");
		urlappend = QUrl::fromPercentEncoding(urlappend.toUtf8());

		QString closewnd = query.queryItemValue("closewnd");


		//信息存放到服务器上，
		QJsonObject obj;
		obj.insert("userid", userid);
		obj.insert("urlappend", urlappend);
		QString param = QJsonDocument(obj).toJson(QJsonDocument::Compact);
		

		MainApp::UIFrame::getConversationController()->setZhongbaoInfor(userid,param);


		//然后创建一个聊天框
		MainApp::UIFrame::getConversationController()->doCreateChatDialog(userid, urlappend);

		if (closewnd.toInt() == 1)
		{
			this->close();
		}

	}
}

void OrderManageDialog::openCollectionSet()
{
	showNormal();
	activateWindow();
	setCkeyCookie();
	QString url = Biz::Session::getSystemConfig()->getMConfig();
	ui->webView->load(url);
	Log::e("OrderManageDialog::openCommonUrlWithCookie : " + url);
}

void OrderManageDialog::openMeetingInfo(const QString& url) {
	showNormal();
	activateWindow();
	setCkeyCookie(); 
	ui->webView->load(url);
}

void OrderManageDialog::setCkeyCookie()
{
	WebPage::addQuaryCkeyCookie(ui->webView);
}

