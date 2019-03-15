#ifndef WEBVIEWCOMMOBJECT_H
#define WEBVIEWCOMMOBJECT_H

#include <QObject>
class WebPage;

class WebViewCommObject : public QObject
{
    Q_OBJECT

public:
    WebViewCommObject(QObject* parent =0);
    ~WebViewCommObject();

    Q_INVOKABLE void jsGotoToUrl(const QString&);
    // 在系统的浏览器中展示次url
    Q_INVOKABLE void openUrl(const QString& url);
    // 在自己的浏览器中展示次url
    Q_INVOKABLE void openNewLink(const QString& url) {emit sgOpenUrlInInnerWebBrowser(url);};

    Q_INVOKABLE QString jsTranslate(const QString&);

    Q_INVOKABLE void jslog(QString log);
    Q_INVOKABLE void openNewSession(const QString& otherSessionId);
    Q_INVOKABLE void closeBrowser(int code);
public:
    void setWebPage(WebPage* view);

protected:
    WebPage* m_webview;
signals:
    void sgCloseBrowser(int code);
     void sgOpenUrlInInnerWebBrowser(const QString& url);
    
};

#endif // WEBVIEWCOMMOBJECT_H
