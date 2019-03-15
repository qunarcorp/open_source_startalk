#ifndef WEBLOGINWIDGET_H
#define WEBLOGINWIDGET_H

#include <QWidget>

#if (QT_VERSION >=QT_VERSION_CHECK(5, 6, 0))
#include <QtWebEngineCore/QWebEngineCookieStore>
#include <QNetworkCookie>
#endif

#include "ui_WebloginWidget.h"

#include "LocalManDialog.h"

namespace Ui{
	class WebLoginWidget;
}
class WebLoginWidget : public LocalManDialog
{
	Q_OBJECT

public:
	WebLoginWidget(QWidget *parent=NULL);
	~WebLoginWidget();

private:
    void chargeLoginCookies(const QList<QNetworkCookie>& cookies);
private:
	Ui::WebloginWidget* ui;
	QString mloginUrl;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QList<QNetworkCookie> m_cookies;
#endif


private slots:
	void onurlChange(const QUrl& url);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    void handleCookieAdded(const QNetworkCookie &cookie);
#endif
};

#endif // WEBLOGINWIDGET_H
