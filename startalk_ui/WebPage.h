#ifndef WEBPAGE_H
#define WEBPAGE_H
#include <qglobal.h>
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
#include <QWebPage>
#include <QtNetwork/QNetworkRequest>
class QWebFrame;
#else
#include <QtWebEngineWidgets/QWebEnginePage>
#endif

class WebViewCommObject;
class webview;
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
class WebPage : public QWebPage
#else
class WebPage : public QWebEnginePage
#endif
{
    Q_OBJECT

public:
    WebPage(QObject *parent);
    ~WebPage();
    void runLocalJavaScript(const QString& javaScript);
    void addChatChannelToHtml(const QString& strclientapi, const WebViewCommObject* pObject);
	static void addQuaryHistoryCookie(webview *webview, const QString& ukey, const QString& kKey, const QString&domain);
	static void addQuaryCookie(webview *webview, const QString& qcook, const QString& vcook, const QString& tcook);
    void setContextInfo(const QMap<QString,QString>& contextInfo) { this->m_contextInfos = contextInfo;};
    QMap<QString,QString> getContextInfo() {return m_contextInfos;};
	static void addQuaryCkeyCookie(webview*webview);
protected:
    QMap<QString,QString> m_contextInfos;
protected:
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	bool isLoaded;
    virtual QString userAgentForUrl(const QUrl& url) const;
   // virtual void javaScriptAlert(QWebFrame * frame, const QString & msg);
    virtual void	javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID);
	virtual bool acceptNavigationRequest( QWebFrame *frame, const QNetworkRequest &request, NavigationType type );
signals:
	void openLink(const QUrl & url);
	void ButtonClicked(const QUrl&url);
    private slots :
        void onPreLoadUrl();
        void onFrameCreate(QWebFrame *frame);
#else
    void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID);
	virtual bool certificateError(const QWebEngineCertificateError &error);
#endif
};


#endif // WEBPAGE_H
