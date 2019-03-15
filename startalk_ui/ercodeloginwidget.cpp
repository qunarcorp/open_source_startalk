#include "ercodeloginwidget.h"
#include "ui_ErCodeLoginWidget.h"
#include "UIFrame.h"
#include "LoginController.h"
#include "Session.h"
#include "loginmanager.h"
#include "DownloadManager.h"
#include "CallbackReceiver.h"
#include "BizCallback.h"
#include "ConfigureHelper.h"

#ifdef _WINDOWS
#include "QZXing.h"
#else
#include "../modules/QZxing/QZXing.h"
#endif

ErCodeLoginWidget::ErCodeLoginWidget(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::ErCodeLoginWidget)
	,mReceiver(new Biz::CallbackReceiver(this))
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	this->setSizeGripEnabled(false);

	auto titlebar = ui->titlebarWidget;
	titlebar->setSizeable(false);
	
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	setWindowTitle(QStringLiteral("二维码登录"));
	mtitleinfor = QStringLiteral("用qchat手机端扫描二维码登录,点击二维码进行刷新。");
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
	titlebar->setWindowTitle(QStringLiteral("二维码登录"));
	setWindowTitle(QStringLiteral("二维码登录"));
	mtitleinfor = QStringLiteral("用qtalk手机端扫描二维码登录,点击二维码进行刷新。");
#endif

	ui->title_label->setText(mtitleinfor);

	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManDialog::onMin);
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &ErCodeLoginWidget::onCloseWidget);
	connect(ui->pbtn_return, &QPushButton::clicked, [this]{
		MainApp::UIFrame::getLoginController()->doErCodeInfoCancel(mqerCodeInfo);
		MainApp::UIFrame::getLoginController()->showNormalLoginDialog();
	});

	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgAuthUserInfor, this, &ErCodeLoginWidget::onShowAuthUserInfo);
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgResultInfor, this, &ErCodeLoginWidget::onResultUserInfo);
	
	ui->ercode_label->installEventFilter(this);
	ui->ercode_label->setCursor(QCursor(Qt::PointingHandCursor));
	ui->ercode_label->setToolTip(QStringLiteral("点击刷新二维码"));
	
}

ErCodeLoginWidget::~ErCodeLoginWidget()
{
	MainApp::UIFrame::getLoginController()->doErCodeInfoCancel(mqerCodeInfo);
}

bool ErCodeLoginWidget::eventFilter( QObject *obj, QEvent *event )
{
	if (obj == ui->ercode_label)
	{
		if (event->type() == QEvent::MouseButtonDblClick
			|| event->type() == QEvent::MouseButtonPress
			)
		{
			ui->title_label->setText(mtitleinfor);
			initErcode();
		}
	}
	 return LocalManDialog::eventFilter(obj,event);
}

void ErCodeLoginWidget::initErcode()
{
	ui->widget_6->setVisible(false);
	QString strGuuid =  QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");

	QString strqerCodeInfo;
#ifdef QCHAT
	strqerCodeInfo = QString("qimlogin://qrcodelogin?k=%1&v=1.0&p=qchat").arg(strGuuid);
#else
	strqerCodeInfo = QString("qimlogin://qrcodelogin?k=%1&v=1.0&p=qtalk").arg(strGuuid);
#endif // QCHAT


	QSize size = ui->ercode_label->geometry().size();
	QPixmap rcodePixmap = QZXing::encodeString(strqerCodeInfo, size.width());
	
	rcodePixmap = QPixmap::fromImage(rcodePixmap.toImage().scaled(size));
	ui->ercode_label->setPixmap(rcodePixmap);
	mqerCodeInfo = strGuuid;
	//把数据发给服务器
	MainApp::UIFrame::getLoginController()->doErCodeInfoToServer(strGuuid);
}

void ErCodeLoginWidget::onShowAuthUserInfo( const QString&userurl, const QString& nickname )
{
	if (userurl.isEmpty())
	{
		return;
	}
	
	if (!nickname.isEmpty())
	{
		ui->widget_6->setVisible(true);
		ui->nickname_label->setText(nickname);
	}
	//下载图像
	auto callbacksuccess = [this](const QString& protraitPath){

		QSize size = ui->ercode_label->geometry().size();
		
		QPixmap rcodePixmap;
		rcodePixmap.load(protraitPath);

		rcodePixmap = QPixmap::fromImage(rcodePixmap.toImage().scaled(size));
		ui->ercode_label->setPixmap(rcodePixmap);

		
	};
	
	auto callbackfail = [this]{
		
	};

	Biz::ProgressedUnitCallback<QString,qint64>* callback
		= mReceiver->createProgressCallback<QString,qint64>(
		[this,callbacksuccess]( const QString& protraitPath ){
			callbacksuccess(protraitPath);
	},
		[this](qint64 done,qint64 total) {
		
	}, 
		[this, callbackfail]{
			callbackfail();
	} 
	);


	QString filename = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","") + ".png";
	QString path = Biz::ConfigureHelper::getQunarDataDir() + "/temp";
	
	
	Biz::Session::getDownLoadManager()->downloadFileForAllUser(userurl,callback,path,filename);
}

void ErCodeLoginWidget::onResultUserInfo( const QString&infor )
{
	if (infor.isEmpty())
	{
		return;
	}

	ui->title_label->setText(infor);
}

void ErCodeLoginWidget::onCloseWidget( bool bret )
{
	MainApp::UIFrame::getLoginController()->showNormalLoginDialog();
	MainApp::UIFrame::getLoginController()->doErCodeInfoCancel(mqerCodeInfo);
	LocalManDialog::onClose(bret);
}
