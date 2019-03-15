#include "WebViewCommObject.h"
#include "Log.h"
#include <QDesktopServices>
#include "LanguageHelper.h"


#include "UIFrame.h"
#include "ConversationController.h"

#include "XmppMessage.h"

#include "WebPage.h"

WebViewCommObject::WebViewCommObject(QObject* parent)
    : QObject(parent)
    , m_webview(NULL)
{
}

WebViewCommObject::~WebViewCommObject()
{

}

void WebViewCommObject::jsGotoToUrl( const QString& val )
{
    QDesktopServices::openUrl(QUrl(val));
}

void WebViewCommObject::openUrl(const QString& url)
{
    QDesktopServices bs;        
    QUrl urls(url);
    QString sc = urls.scheme();
    if (sc.isEmpty())
    {
        urls.setScheme("http");
    }
    bs.openUrl(QUrl(urls));
}

QString WebViewCommObject::jsTranslate( const QString& val )
{
    return T_(val);
}

 void WebViewCommObject::jslog(QString log)
{
    // qDebug() << QString("from js: ") << log;
    Log::e(" WebViewCommObject::jslog " + log);
}


 void WebViewCommObject::openNewSession(const QString& otherSessionId)
 {
     QString conversationId = Biz::MessageUtil::makeSureUserJid(otherSessionId);
     MainApp::UIFrame::getConversationController()->createNewChatDialog(conversationId);
     MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
     MainApp::UIFrame::getConversationController()->activeConversation(conversationId);
     MainApp::UIFrame::getConversationController()->moveSessionToTop(conversationId);
 }



 void WebViewCommObject::closeBrowser(int code)
{
    emit sgCloseBrowser(code);
}

 void WebViewCommObject::setWebPage(WebPage* view)
 {
     this->m_webview = view;
 }

