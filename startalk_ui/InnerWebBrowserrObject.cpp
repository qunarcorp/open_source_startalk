#include "InnerWebBrowserrObject.h"
#include <QJsonObject>
#include "WebService.h"
#include "WebPage.h"

#include "Session.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "SystemConfigData.h"
#include "Account.h"
#include "ConfigureHelper.h"

InnerWebBrowserrObject::InnerWebBrowserrObject(QObject* parent)
    : WebViewCommObject(parent)
{
}


InnerWebBrowserrObject::~InnerWebBrowserrObject(void)
{
}

void InnerWebBrowserrObject::audioDownloadProgress(WebPage* page,const QString& url,const QString& progress)
{
    QString js =  QString("audioDownloadProgress('%1','%2')").arg (url,progress) ;
    page->runLocalJavaScript(js);
}

void InnerWebBrowserrObject::audioPlayerReady( WebPage* page,const QString& url)
{
    QString js =  QString("audioPlayerReady('%1')").arg (url) ;
    page->runLocalJavaScript(js);
}

void InnerWebBrowserrObject::audioStartPlay( WebPage* page,const QString& url)
{
    QString js =  QString("audioStartPlay('%1')").arg (url) ;
    page->runLocalJavaScript(js);
}

void InnerWebBrowserrObject::audioFinishPlay( WebPage* page,const QString& url)
{
    QString js =  QString("audioFinishPlay('%1')").arg (url) ;
    page->runLocalJavaScript(js);
}

void InnerWebBrowserrObject::audoPlayError( WebPage* page,const QString& url,const QString& erorcode)
{
    QString js =  QString("audoPlayError('%1','%2')").arg (url,erorcode) ;
    page->runLocalJavaScript(js);
}


void InnerWebBrowserrObject::getUserInfoFromClient()
{
    QString ckey = WebService::getOldCKey();//WebService::getCKey ();

    QMap<QString,QString> contextInfo;
    if (m_webview!=NULL)
        contextInfo = m_webview->getContextInfo();

    QJsonObject object;
    object.insert ("ckey",ckey);
    object.insert ("username",Biz::Session::getAccountManager()->accountData().UserID());
    object.insert ("domain",Biz::Session::getSystemConfig ()->getXmppDomain ());
    object.insert ("fromjid",contextInfo.value ("fromjid")); 
    object.insert ("chattype",contextInfo.value ("chattype")); // 单人是0，群是1
    object.insert ("rk",WebService::sSecurityKey);
#ifdef QCHAT
    object.insert ("client",QString("qchat"));
#else
    object.insert ("client",QString("qtalk"));
#endif // QCHAT
    QString jsonStr = QJsonDocument(object).toJson (QJsonDocument::Compact);

    QString js =  QString("_getUserInfoFromClient('%1')").arg (jsonStr) ;
    if (m_webview!=NULL)
        m_webview->runLocalJavaScript(js);

}
