#ifndef ORDERMANAGEDIALOG_H
#define ORDERMANAGEDIALOG_H

#include "LocalManDialog.h"
#include "ui_OrderManageDialog.h"
#include <QtNetwork/QNetworkCookie>
#include <QtNetwork/QNetworkCookieJar>
#include "ChatWebPage.h"

#include <QNetworkAccessManager>
#include <QUrl>
#include "UtilHelper.h"

class InnerWebBrowserrObject;
namespace Biz{
    class CallbackReceiver;
}

class OrderManageDialog : public LocalManDialog
{
	Q_OBJECT
        friend class Util::SingletonTemplete<OrderManageDialog>;
public:
	
	void showQiangdanDlg();
	void showOrderManageDlg();
	void showHistoryRecordDlg();
    void setQunarCookie();
	void setQunarHistoryRecordCookie();
	void showSystemOrNoticeUrl(const QString&url);
    void openCommonUrl(const QString& url);
	void openWebRtcOrAudio(const QString&url, int type);
    void openCommonUrlWithCookie(const QString& url,const QMap<QString,QString>& cookies);
    void showHtmlContent(const QString& content);
	void showActiveDlg();
	void openCollectionSet();
	void openMeetingInfo(const QString& url);
	void setCkeyCookie();
private:
	OrderManageDialog(QWidget *parent=NULL);
	~OrderManageDialog();
private slots:
	void onMin();
	void onClose();
    void onJsCloseBrowser(int code);
	void onOpenLink(const QUrl& url);
    void onPlayVodio(const QString& url);
	void onButtonClicked(const QUrl& url);
private:
	Ui::OrderManageDialog *ui;
	QNetworkAccessManager* mWebManager;
	WebPage *mPage;
	InnerWebBrowserrObject* mCommObject;
    Biz::CallbackReceiver* mReceiver;
	ChatCommObject* mwebrtcCommObject;
};

typedef Util::SingletonTemplete<OrderManageDialog> CommentWebViewSingleton;
#endif // ORDERMANAGEDIALOG_H
