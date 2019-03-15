#include "WebPage.h"


#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QWebChannel>
#include <QtWebEngineCore/QWebEngineCookieStore> 
#include <QtWebEngineWidgets/QWebEngineProfile>
#else
#include <QWebFrame>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#endif

#include "Log.h"
#include "UIFrame.h"
#include "ConversationController.h"

#include "ChatCommObject.h"

#include "ChatBubbleController.h"

#include "Session.h"
#include "SettingData.h"
#include "gloableeventobject.h"
#include "ChatDisplayOptionWidget.h"
#include "webview.h"
#include "WebService.h"
#include "AccountData.h"
#include "SystemDefine.h"
#include "editablesettings.h"  

WebPage::WebPage(QObject *parent)
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    : QWebEnginePage(parent)
#else
    : QWebPage(parent)
#endif
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
    connect(this,&QWebPage::frameCreated,this,&WebPage::onFrameCreate);
    onFrameCreate(mainFrame());

	//this->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(this,&QWebPage::linkClicked,[this](const QUrl& url){
        QString strUrl = url.toString();
        this->mainFrame()->load(url);
		
    });

	connect(this,&QWebPage::loadFinished,[this](bool res){
		isLoaded = true;
	});
	
	isLoaded = false;
#endif
	
}

WebPage::~WebPage()
{
}

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
QString WebPage::userAgentForUrl(const QUrl& url) const
{
    QString strUrl = url.toString();
    QString curentAgent = QWebPage::userAgentForUrl(url);
	curentAgent += " qunarqchat-pc-client";
    return  curentAgent;
}

void WebPage::onFrameCreate(QWebFrame *frame)
{
    disconnect(frame,&QWebFrame::loadStarted,this,&WebPage::onPreLoadUrl);
    connect(frame,&QWebFrame::loadStarted,this,&WebPage::onPreLoadUrl);
}

void WebPage::onPreLoadUrl()
{
    QWebFrame* pSenderFrame = dynamic_cast<QWebFrame*>(sender());
    if (NULL!=pSenderFrame)
    {
        QUrl redirectUrl = pSenderFrame->requestedUrl();
        QUrlQuery query (redirectUrl);
        QString schema = redirectUrl.scheme();
        QString host = redirectUrl.host();
        QString param = query.toString();
        QString strUrl =  redirectUrl.toString();

        MainApp::UIFrame::getConversationController()->shouldOverrideUrlLoading(redirectUrl);
    }
}

// void WebPage::javaScriptAlert(QWebFrame * frame, const QString & msg)
// {
// 	//QMessageBox::about(NULL, "title", msg);
// }

bool WebPage::acceptNavigationRequest( QWebFrame *frame, const QNetworkRequest &request, NavigationType type )
{
	if(type==0){//如果是用户点击  
		QString str = frame->requestedUrl().toString();
		if(frame!=mainFrame()){ //如果不是在本窗口的连接  
			emit openLink(request.url());//发送打开新连接信号  
		}else{  
			int a = 8;
			a = 9;
			QString fileName = request.url().fileName();
			if (fileName == "sesstran_his")
			{ 
				emit openLink(request.url());//发送打开新连接信号 
				return false;
			} 
			//emit loadLink(request.url());//发送点击连接信号  
		}  

	}  

	emit ButtonClicked(request.url());

	return QWebPage::acceptNavigationRequest(frame, request, type);  
}

#endif

void WebPage::runLocalJavaScript(const QString& javaScript)
{
    if (!Util::ENV_OPTION ||
        Biz::Session::getEditableSettings()->BetaEnvEnable() || 
        (Biz::EditableSettings::INNERLOGOPTION::ILO_HTMLLOG == 
		(Biz::Session::getEditableSettings()->ShowInnerLog()&Biz::EditableSettings::INNERLOGOPTION::ILO_HTMLLOG)))
    {
        Log::e("cmd : "+javaScript);
    }

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))

	if (isLoaded)
		mainFrame()->evaluateJavaScript(javaScript);
#else
    this->runJavaScript(javaScript);
#endif
}

void WebPage::addChatChannelToHtml(const QString& strclientapi, const WebViewCommObject* pObject)
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
    mainFrame()->addToJavaScriptWindowObject(strclientapi, (QObject*)pObject);
    connect(mainFrame(), &QWebFrame::javaScriptWindowObjectCleared,[this,strclientapi,pObject](){
        mainFrame()->addToJavaScriptWindowObject(strclientapi, (QObject*)pObject);
    });
#else
    QWebChannel *channel = new QWebChannel();
    channel->registerObject(QStringLiteral("%1").arg(strclientapi), (QObject*)pObject);
    setWebChannel(channel);
#endif
}


void WebPage::addQuaryHistoryCookie(webview *webview, const QString& ukey, const QString& kKey, const QString&domain)
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	QNetworkCookieJar* pCookieJar = webview->page()->networkAccessManager()->cookieJar();
	if (NULL == pCookieJar)
		pCookieJar = new QNetworkCookieJar();
	QNetworkCookie ucookie;
	ucookie.setDomain(".qunar.com");
	ucookie.setPath("/");
	ucookie.setName("_u");
	ucookie.setValue(WebService::sU.toLatin1());

	QNetworkCookie kcookie;
	kcookie.setDomain(".qunar.com");
	kcookie.setPath("/");
	kcookie.setName("_k");
	kcookie.setValue(WebService::sSecurityKey.toLatin1());

	QNetworkCookie dcookie;
	dcookie.setDomain(".qunar.com");
	dcookie.setPath("/");
	dcookie.setName("_d");
	dcookie.setValue(domain.toLatin1());

	QNetworkCookie ckeycookie;
	ckeycookie.setDomain(".qunar.com");
	ckeycookie.setPath("/");
	ckeycookie.setName("q_ckey");
	ckeycookie.setValue(WebService::getCKey().toLatin1());


	pCookieJar->insertCookie(ucookie);
	pCookieJar->insertCookie(kcookie);
	pCookieJar->insertCookie(dcookie);
	pCookieJar->insertCookie(ckeycookie);

	webview->page()->networkAccessManager()->setCookieJar(pCookieJar);
#else

	QNetworkCookie ucookie;
	ucookie.setDomain(".qunar.com");
	ucookie.setPath("/");
	ucookie.setName("_u");
	ucookie.setValue(ukey.toLatin1());

	QNetworkCookie kcookie;
	kcookie.setDomain(".qunar.com");
	kcookie.setPath("/");
	kcookie.setName("_k");
	kcookie.setValue(kKey.toLatin1());

	QNetworkCookie dcookie;
	dcookie.setDomain(".qunar.com");
	dcookie.setPath("/");
	dcookie.setName("_d");
	dcookie.setValue(domain.toLatin1());

	QNetworkCookie ckeycookie;
	ckeycookie.setDomain(".qunar.com");
	ckeycookie.setPath("/");
	ckeycookie.setName("_cKey");
	ckeycookie.setValue(WebService::getCKey().toLatin1());

	QWebEngineCookieStore *cookself = NULL;
	cookself = webview->page()->profile()->cookieStore();
	cookself->setCookie(ucookie);
	cookself->setCookie(kcookie);
	cookself->setCookie(dcookie);
	cookself->setCookie(ckeycookie);

#endif
}

void WebPage::addQuaryCookie(webview *webview, const QString& strqcook, const QString& strvcook, const QString& strtcook)
{
	QNetworkCookie qcookie;
	qcookie.setDomain(".qunar.com");
	qcookie.setPath("/");
	qcookie.setName("_q");
	qcookie.setValue(strqcook.toLatin1());

	QNetworkCookie vcookie;
	vcookie.setDomain(".qunar.com");
	vcookie.setPath("/");
	vcookie.setName("_v");
	vcookie.setValue(strvcook.toLatin1());

	QNetworkCookie tcookie;
	tcookie.setDomain(".qunar.com");
	tcookie.setPath("/");
	tcookie.setName("_t");
	tcookie.setValue(strtcook.toLatin1());

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	QNetworkCookieJar* pCookieJar = webview->page()->networkAccessManager()->cookieJar();
	if (NULL == pCookieJar)
		pCookieJar = new QNetworkCookieJar();


	pCookieJar->insertCookie(qcookie);
	pCookieJar->insertCookie(vcookie);
	pCookieJar->insertCookie(tcookie);

	webview->page()->networkAccessManager()->setCookieJar(pCookieJar);
#else
	QWebEngineCookieStore *cookself = NULL;
	cookself = webview->page()->profile()->cookieStore();
	cookself->setCookie(qcookie);
	cookself->setCookie(vcookie);
	cookself->setCookie(tcookie);
#endif
}



#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
void WebPage::javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID)
{
    Log::e (QString("webpage console error line %1 : %2 in %3").arg (lineNumber).arg (message,sourceID));
}
#else
void WebPage::javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID)
{
    Log::e (QString("webpage console error level %4 line %1 : %2 in %3").arg (lineNumber).arg (message,sourceID).arg(level));
}

bool WebPage::certificateError(const QWebEngineCertificateError &error)
{
	if (error.isOverridable())
	{
		int nerror = error.error();
		QString strdes = error.errorDescription();
	}
	return true;
}

#endif


void WebPage::addQuaryCkeyCookie( webview*webview )
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	QNetworkCookieJar* pCookieJar = webview->page()->networkAccessManager()->cookieJar();
	if (NULL == pCookieJar)
		pCookieJar = new QNetworkCookieJar();
	QNetworkCookie ucookie;
	ucookie.setDomain(".qunar.com");
	ucookie.setPath("/");
	ucookie.setName("p_user");
	ucookie.setValue(WebService::sU.toLatin1());

	QNetworkCookie kcookie;
	kcookie.setDomain(".qunar.com");
	kcookie.setPath("/");
	kcookie.setName("_k");
	kcookie.setValue(WebService::sSecurityKey.toLatin1());

	QNetworkCookie ckeycookie;
	ckeycookie.setDomain(".qunar.com");
	ckeycookie.setPath("/");
	ckeycookie.setName("q_ckey");
	ckeycookie.setValue(WebService::getCKey().toLatin1());


	pCookieJar->insertCookie(ucookie);
	pCookieJar->insertCookie(kcookie);
	pCookieJar->insertCookie(ckeycookie);

	webview->page()->networkAccessManager()->setCookieJar(pCookieJar);
#else

	QNetworkCookie ucookie;
	ucookie.setDomain(".qunar.com");
	ucookie.setPath("/");
	ucookie.setName("p_user");
	ucookie.setValue(WebService::sU.toLatin1());

	QNetworkCookie kcookie;
	kcookie.setDomain(".qunar.com");
	kcookie.setPath("/");
	kcookie.setName("_k");
	kcookie.setValue(WebService::sSecurityKey.toLatin1());

	QNetworkCookie ckeycookie;
	ckeycookie.setDomain(".qunar.com");
	ckeycookie.setPath("/");
	ckeycookie.setName("q_ckey");
	ckeycookie.setValue(WebService::getCKey().toLatin1());

	QWebEngineCookieStore *cookself = NULL;
	cookself = webview->page()->profile()->cookieStore();
	cookself->setCookie(ucookie);
	cookself->setCookie(kcookie);
	cookself->setCookie(ckeycookie);

#endif
}