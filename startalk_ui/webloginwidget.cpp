#include "webloginwidget.h"
#include "TitlebarWidget.h"

#include <QNetworkCookie>
#include "Session.h"
#include "Account.h"
#include "loginmanager.h"
#include "AccountData.h"
#include "UserSettingData.h"
#include "accountmanager.h"
#include "UIFrame.h"
#include "LoginController.h"
#include "diywidgit/customviews/qframelayout.h"
#include "ConfigureHelper.h"
#include "editablesettings.h"


#if (QT_VERSION >=QT_VERSION_CHECK(5, 6, 0))
#include <QtWebEngineCore/QWebEngineCookieStore>
#include <QtWebEngineWidgets/QWebEngineProfile>
#else
#include <QNetworkCookieJar>
#endif

WebLoginWidget::WebLoginWidget(QWidget *parent)
	: LocalManDialog(parent),ui(new Ui::WebloginWidget)
{
	ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
    this->setSizeGripEnabled(true);

    auto titlebar = ui->widgettitlebar;
    titlebar->setSizeable(false);
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
    setWindowTitle(QStringLiteral("web登录"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
    titlebar->setWindowTitle(QStringLiteral("web登录"));
    setWindowTitle(QStringLiteral("web登录"));
#endif

	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManDialog::onMin);
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, [this]{
        MainApp::UIFrame::getLoginController()->showNormalLoginDialog();
    });
	mloginUrl = Biz::Session::getEditableSettings()->WebLoginUrl();

	connect(ui->webView, &webview::urlChanged, this, &WebLoginWidget::onurlChange);

    connect(ui->webView, &webview::titleChanged,[this](const QString& title){
        if (title.isEmpty())
        {
            setWindowTitle(title);
        }
    });

    ui->webView->load(QUrl(mloginUrl));

    QFrameLayout* pLayout = new QFrameLayout(ui->widget_webview);
    pLayout->appendWidget(ui->webView,ALINE_FILL);
    pLayout->appendWidget(ui->login,ALINE_MATCHWIDTH|ALINE_BOTTOM);

    connect(ui->login,&QPushButton::clicked,[this]{
        onurlChange(QUrl(mloginUrl));
        ui->login->setEnabled(false);
    });

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QWebEngineCookieStore* pstore = ui->webView->page()->profile()->cookieStore();
    connect(pstore, &QWebEngineCookieStore::cookieAdded, this, &WebLoginWidget::handleCookieAdded);
#endif
}

WebLoginWidget::~WebLoginWidget()
{

}

void WebLoginWidget::onurlChange( const QUrl& url )
{
	QString strurl = url.toString();
    QString loginRes1 = QString("qt.qunar.com");
    QString loginRes2 = QString("www.qunar.com/index.htm");
	if ( strurl.contains(loginRes1) || strurl.contains(loginRes2))
	{

        QList <QNetworkCookie> cookie;
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
        QNetworkCookieJar *pCookieJar = ui->webView->page()->networkAccessManager()->cookieJar();
        cookie = pCookieJar->cookiesForUrl(QUrl(strurl));
#endif
        chargeLoginCookies(cookie);

	}
    ui->login->setEnabled(true);
}
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
void WebLoginWidget::handleCookieAdded(const QNetworkCookie &cookie)
{
    // only new cookies
    for (auto c: m_cookies) {
        if (c.hasSameIdentifier(cookie))
            return;
    }
    m_cookies.append(cookie);
    chargeLoginCookies(m_cookies);
}


#endif


void WebLoginWidget::chargeLoginCookies(const QList<QNetworkCookie>& cookies)
{
    QSharedPointer<Biz::UserSettingData> spUserSetting =
        Biz::Session::getAccountManager()->getCurrentUserSettingData();
	QString strCachUserName = spUserSetting->LoginTokenUserName();
    bool bQVTChanged = false;
    for (int i = 0; i < cookies.count(); ++i )
    {
        QString strname = cookies.at(i).name();

        // str = _q=U.ywud2995; expires=Fri, 25-Mar-2016 07:44:36 GMT; domain=.qunar.com; path=/
        QString str     = cookies.at(i).toRawForm();
        QString strTmp  = str.split(";").first();
        QString strK    = cookies.at(i).name();
        QString strV    = cookies.at(i).value();
        do
        {
            if (strK == "_s")
            {
                bQVTChanged = true;
                spUserSetting->SCookie(strV);
                break;
            }
            if (strK == "_v")
            {
                bQVTChanged = true;
                spUserSetting->VCookie(strV);
                break;
            }
            if (strK == "_t")
            {
                bQVTChanged = true;
               spUserSetting->TCookie(strV);
                break;
            }
            if (strK=="_q")
            {
                bQVTChanged = true;
                spUserSetting->QCookie(strV);
                QString userid = strV.mid(strV.indexOf("U.") + QString("U.").length());
                Biz::Session::getAccountManager()->resetCurrentUserData(userid);
				spUserSetting->LoginTokenUserName(userid);
                break;
            }
        } while (false);
    }

    if (bQVTChanged &&
        !spUserSetting->QCookie().isEmpty() &&
        !spUserSetting->VCookie().isEmpty() &&
        !spUserSetting->TCookie().isEmpty() )
    {
		if (QString::compare(spUserSetting->LoginTokenUserName(), strCachUserName) != 0)
		{
			spUserSetting->LoginToken("");
		}
		
		Biz::Session::getAccountManager()->setCurrentUserSettingData(spUserSetting);
		
        Biz::ConfigureHelper::saveConfigureData(Biz::Session::getAccountManager()->accountData().UserID(),*spUserSetting.data());
		Log::e("WebLoginWidget::chargeLoginCookies MainApp::UIFrame::getLoginController()->signin()");


        MainApp::UIFrame::getLoginController()->signin();
        MainApp::UIFrame::getLoginController()->showNormalLoginDialog();
    }
}
