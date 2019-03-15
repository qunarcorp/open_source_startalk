#ifndef WEBVIEW_H
#define WEBVIEW_H
#include <qglobal.h>

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
#include <QWebView>
#else
#include <QtWebEngineWidgets/QWebEngineView>
#endif

#include "WebPage.h"
class BaseChatDialog;
class ChatCommObject;
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
class webview : public QWebView
#else
class webview : public QWebEngineView
#endif

{
    Q_OBJECT

public:
    explicit webview(QWidget *parent = 0);
    ~webview();
public:
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    void load(const QUrl &url);
    void setPage(WebPage *page);
    void webviewInitChannel(WebPage*page, BaseChatDialog*basechat, ChatCommObject* mCommObject);
    void webviewInitChannelOfDialog(WebPage*page, QDialog*dialog, ChatCommObject* mCommObject);
#endif
protected:
	virtual void contextMenuEvent(QContextMenuEvent *event);
    virtual void keyPressEvent(QKeyEvent* event);
public slots:
	void selectAllPage();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
	void onFeaturePermissionRequested(const QUrl &securityOrigin, QWebEnginePage::Feature feature);
#endif
signals:
	void customContextMenuRequested(const QPoint&pt);
    void copyEventActionRequested();

    
private:
	WebPage *mPage;
};

#endif // WEBVIEW_H
