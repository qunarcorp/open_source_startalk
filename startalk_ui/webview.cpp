#include "webview.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QApplication>
#include <QClipboard>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
#include <QWebEngineView>
#include <QWebChannel>
#include "featurepermissionbar.h"
#endif

#include "LanguageHelper.h"

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
 webview::webview(QWidget *parent) : QWebView(parent)
#else
webview::webview(QWidget *parent) : QWebEngineView(parent)
#endif
{
	mPage = NULL;
}

webview::~webview()
{
 
}
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
void webview::load(const QUrl &url)
{
	//QWebEngine DEBUG --remote-debugging-port=9223
	QWebEngineView::load(url);
}

void webview::setPage(WebPage *page)
{
	mPage = page;
	QWebEngineView::setPage(page);
	//
	connect(mPage, &WebPage::featurePermissionRequested, this, &webview::onFeaturePermissionRequested);
	qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "9223"); 
}

void webview::webviewInitChannel(WebPage*page, BaseChatDialog*basechat, ChatCommObject* mCommObject)
{
	QWebChannel *channel = new QWebChannel((QObject*)basechat);
	channel->registerObject(QStringLiteral("CLIENT_API"), (QObject*)mCommObject);
	page->setWebChannel(channel);
}

void webview::webviewInitChannelOfDialog(WebPage*page, QDialog*dialog, ChatCommObject* mCommObject)
{
	QWebChannel *channel = new QWebChannel((QObject*)dialog);
	channel->registerObject(QStringLiteral("CLIENT_API"), (QObject*)mCommObject);
	page->setWebChannel(channel);
}

void webview::onFeaturePermissionRequested(const QUrl &securityOrigin, QWebEnginePage::Feature feature)
{
	FeaturePermissionBar *permissionBar = new FeaturePermissionBar(this);
	connect(permissionBar, &FeaturePermissionBar::featurePermissionProvided, page(), &QWebEnginePage::setFeaturePermission);

	// Discard the bar on new loads (if we navigate away or reload).
	connect(page(), &QWebEnginePage::loadStarted, permissionBar, &QObject::deleteLater);

	permissionBar->requestPermission(securityOrigin, feature);
}

#endif

void webview::contextMenuEvent(QContextMenuEvent *event)
{
// 	QMenu *menu = page()->createStandardContextMenu();
// 	const QList<QAction*> actions = menu->actions();
// 	QList<QAction*>::const_iterator it = qFind(actions.cbegin(), actions.cend(), page()->action(QWebEnginePage::OpenLinkInThisWindow));
// 	if (it != actions.cend()) {
// 		(*it)->setText(tr("QMenu"));
// 		++it;
// 		menu->insertAction(*it, page()->action(QWebEnginePage::OpenLinkInNewWindow));
// 		menu->insertAction(*it, page()->action(QWebEnginePage::OpenLinkInNewTab));
// 	}
// 	
// 	menu->popup(event->globalPos());
	
// 	QMenu *menu = new QMenu(this);
// 	QAction* mActionWebViewSeleAll = menu->addAction(T_("GroupTextEditMenu_item_All"));
// 	connect(mActionWebViewSeleAll, &QAction::triggered, this, &webview::selectAllPage);
// 	menu->popup(event->globalPos());
//	emit customContextMenuRequested(event->globalPos());
}



#include <QMessageBox>
void webview::selectAllPage()
{
	//QMessageBox::information(this, "test", "testesttest");
}

void webview::keyPressEvent(QKeyEvent* keyEvent)
{
    if (NULL!=keyEvent && keyEvent->modifiers() == (Qt::ControlModifier) && keyEvent->key() == Qt::Key_C)
    {
        emit copyEventActionRequested();
    }      

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
    return QWebView::keyPressEvent(keyEvent);
#else
    return QWebEngineView::keyPressEvent(keyEvent);
#endif
}
