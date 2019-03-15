#include "vidioandaudiodialog.h"
#include "ChatCommObject.h"
#include "Session.h"
#include "SystemConfigData.h"
#include "vidioandaudiomanage.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "Account.h"
#include "ConfigureHelper.h"
#include "UserVcardManager.h"
#include "NotifyCenterController.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QEvent>

VidioAndAudioDialog::VidioAndAudioDialog(QWidget *parent)
: LocalManDialog(parent)
, ui(new Ui::VidioAndAudioDialog)
, mwebrtcCommObject(new ChatCommObject(this))
, mPage(new WebPage(this))
, mReceiver(new Biz::CallbackReceiver(this))
{
	ui->setupUi(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	//点击X需要关闭对话框并销毁
	setAttribute(Qt::WA_DeleteOnClose);
	overrideWindowFlags((Qt::WindowFlags)((windowFlags() & ~remove) | add));


	auto titlebar = ui->titlebar;
	titlebar->setSizeable(true);
	
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &VidioAndAudioDialog::onMin);

	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &VidioAndAudioDialog::onClose);
	setSizeGripEnabled(true);


	ui->webView->setPage(mPage);
	//QString strurl = Biz::Session::getSystemConfig()->VidioAndAudio_Host();
	//ui->webView->load(strurl);
	mPage->addChatChannelToHtml("client", mwebrtcCommObject);
	mwebrtcCommObject->setWebPage(mPage);

	connect(ui->webView, &webview::loadFinished, this, &VidioAndAudioDialog::onLoadHtmlFinish);

	connect(Biz::Session::getVidioAndAudioManager(), &Biz::VidioAndAudioManager::sgRecievedSingle, this, &VidioAndAudioDialog::onRecievedSingle);
	connect(mwebrtcCommObject, &ChatCommObject::sgVideoSendSingnal, this, &VidioAndAudioDialog::OnVideoSendSingnal);
	connect(mwebrtcCommObject, &ChatCommObject::sgCloseRtcWindow, this, &VidioAndAudioDialog::OnCloseRtcWindow);
	connect(mwebrtcCommObject, &ChatCommObject::sgWriteLocalLog, this, &VidioAndAudioDialog::onWriteLocalLog);
	connect(mwebrtcCommObject, &ChatCommObject::sgStartVideoSound, this, &VidioAndAudioDialog::onStartVideoSound);
	connect(mwebrtcCommObject, &ChatCommObject::sgStopVideoSound, this, &VidioAndAudioDialog::onStopVideoSound);
	

	QString strLocalFile = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/resources/AVChat_waitingForAnswer.mp3";


	if (QFile::exists(strLocalFile))
	{
		mEffectPlay.setMedia(QUrl::fromLocalFile(strLocalFile));
		mplaylist.addMedia(QUrl::fromLocalFile(strLocalFile));
		mplaylist.setPlaybackMode(QMediaPlaylist::Loop);
	}

	connect(Biz::Session::getVidioAndAudioManager(), &Biz::VidioAndAudioManager::sgVideoOrAudeoRecievPing, this, &VidioAndAudioDialog::onVideoOrAudeoRecievPing);
	connect(mwebrtcCommObject, &ChatCommObject::sgclose_video_room, this, &VidioAndAudioDialog::OnCloseVideoRoom);
	connect(mwebrtcCommObject, &ChatCommObject::sgfullScreen, this, &VidioAndAudioDialog::onFullScreenWindow);


	int screenwidth = QApplication::desktop()->screenGeometry().width();
	int screenheight = QApplication::desktop()->screenGeometry().height();
	mdefaultsize.setWidth(screenwidth - 100);
	mdefaultsize.setHeight(screenheight - 120);
}

VidioAndAudioDialog::~VidioAndAudioDialog()
{
	int a = 0;
	a = 9;
}

void VidioAndAudioDialog::onShowDlg(const QString& conversationId, bool bretflag)
{
	m_conversationId = conversationId;

	if (!bretflag)
	{
		WebPage::addQuaryCkeyCookie(ui->webView);
		mPage->setContextInfo(QMap<QString, QString>());
		QString strurl = mUrl;//Biz::Session::getSystemConfig()->VidioAndAudio_Host();
		ui->webView->load(QUrl(strurl));
	}
	
	
	showNormal();
	activateWindow();
}

void VidioAndAudioDialog::callVidioOrAudio(int type)
{
	if (mPage==NULL)
	{
		return;
	}

	setTitle(type);

	auto callback = mReceiver->createCallback<QString>([this, type](QString retjson){
		if (retjson == "error")
		{
			MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取json串异常,请重新启动客户端"));
			return;
		}
		
		if (type == AudeoVidioType::AUDEOTYPE)
		{
			QString strjsfun = QString("receiveRtcAudio('%1', '%2')").arg(retjson).arg(m_conversationId);
			mPage->runLocalJavaScript(strjsfun);
		}
		else if (type == AudeoVidioType::VIDEOTYPE)
		{
			QString strjsfun = QString("receiveRtc('%1', '%2')").arg(retjson).arg(m_conversationId);
			mPage->runLocalJavaScript(strjsfun);
		}

	}, [this]()
	{
		
	});
	
	Biz::Session::getVidioAndAudioManager()->getVidioInfor(callback);
}

void VidioAndAudioDialog::callVidioOrAudioStart(int type)
{
	if (mPage == NULL)
	{
		return;
	}
	setTitle(type);
	auto callback = mReceiver->createCallback<QString>([this, type](QString retjson){

		Log::e("VidioAndAudioDialog::callVidioOrAudioStart getVidioInfor ");
		if (retjson == "error")
		{
			MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取json串异常,请重新启动客户端"));
			return;
		}
		if (type == AudeoVidioType::AUDEOTYPE)
		{
			QString strjsfun = QString("startAudio('%1', '%2')").arg(retjson).arg(m_conversationId);
			mPage->runLocalJavaScript(strjsfun);
		}
		else if (type == AudeoVidioType::VIDEOTYPE)
		{
			Log::e("VidioAndAudioDialog::callVidioOrAudioStart getVidioInfor == 1 ");
			QString strjsfun = QString("startVideo('%1', '%2')").arg(retjson).arg(m_conversationId);
			mPage->runLocalJavaScript(strjsfun);
		}

	}, [this]()
	{
		
	});
	Biz::Session::getVidioAndAudioManager()->getVidioInfor(callback);
}

void VidioAndAudioDialog::setUrl(const QString& url)
{
	mUrl = url;
}

void VidioAndAudioDialog::onMin()
{
	//this->hide();
	this->setWindowState(Qt::WindowMinimized);
}

void VidioAndAudioDialog::onClose()
{
	QString strPeer = "closePeerConn()";
	mPage->runLocalJavaScript(strPeer);
	MainApp::UIFrame::getConversationController()->deleteVidioChatById(m_conversationId);
	MainApp::UIFrame::getConversationController()->deleteVidioChatById(mroomid);
	this->close();

	
	
}

void VidioAndAudioDialog::onLoadHtmlFinish()
{
	Log::e("VidioAndAudioDialog::onLoadHtmlFinish() sgLoadFinished ");
	emit sgLoadFinished(m_conversationId);

	QString str = ui->webView->title();
}

void VidioAndAudioDialog::onRecievedSingle(const QString& json, const QString&id)
{
	if (id != m_conversationId)
	{
		return;
	}
	Log::e(" VidioAndAudioDialog::onRecievedSingle");
	QString strnewJson = json;
	QString str = strnewJson.replace("&quot;", "\"");
	QString strRecievd = QString("receiveSignal('%1')").arg(strnewJson.replace("&quot;", "\""));
	mPage->runLocalJavaScript(strRecievd);

}

void VidioAndAudioDialog::OnVideoSendSingnal(const QString&json, const QString&id)
{
	if (id != m_conversationId)
	{
		return;
	}
	
	if (m_conversationId.isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(m_conversationId));


	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());

	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::webrtc);
	message->ExtendInfo(json);
	message->autoReply(true);


	auto callback = mReceiver->createCallback([]{}, [this](){

	});
	auto presendcallback = mReceiver->createCallback([this, message](){

	}, [this](){});

	Biz::Session::currentAccount().doSendMessage(message, callback, presendcallback);
}

void VidioAndAudioDialog::OnCloseRtcWindow(const QString&id)
{
	if (id != m_conversationId)
	{
		return;
	}
	onClose();
}

void VidioAndAudioDialog::onWriteLocalLog(const QString&id, const QString&log)
{
	if (id != m_conversationId)
	{
		return;
	}
	Log::wll(log);
}

void VidioAndAudioDialog::onStartVideoSound(const QString&id)
{
	if (id != m_conversationId)
	{
		return;
	}
	mEffectPlay.setPlaylist(&mplaylist);
	mEffectPlay.play();
}

void VidioAndAudioDialog::onStopVideoSound(const QString&id)
{
	if (id != m_conversationId)
	{
		return;
	}
	mEffectPlay.stop();
}

void VidioAndAudioDialog::setTitle( int type )
{

	QString title = "beta";
	QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(m_conversationId);
	if (type == AudeoVidioType::AUDEOTYPE)
	{
		title = QStringLiteral("(beta版)  %1 正在与你实时语音聊天中...").arg(displayname);
	}
	else if (type == AudeoVidioType::VIDEOTYPE)
	{
		title = QStringLiteral("(beta版)  %1 正在与你实时视频聊天中...").arg(displayname);
	}

	ui->titlebar->setLeftTitle(title);
	this->setWindowTitle(title);
}

void VidioAndAudioDialog::onVideoOrAudeoRecievPing(const QString& conversation, int type)
{
	if (conversation.isEmpty() || conversation != m_conversationId)
	{
		return;
	}

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversation));

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());

	
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::webrtc);
	message->autoReply(true);
	message->MediaType(type == Biz::MediaTypeAudeoPing?Biz::MediaTypeAudeoPingRespon:Biz::MediaTypeVideoPingRespon);


	auto callback = mReceiver->createCallback([]{}, [this](){

	});
	auto presendcallback = mReceiver->createCallback([this, message](){

	}, [this](){});

	Biz::Session::currentAccount().doSendMessage(message, callback, presendcallback);
}

void VidioAndAudioDialog::setRoomVideoParam(const QString& uuid, const QString& topic, quint64 starttm)
{
	mroomid = uuid;
	mwebrtcCommObject->setVedioRoomParam(uuid, topic, starttm, mPage);
}

void VidioAndAudioDialog::setWindowsDefaultSize()
{
	//this->setFixedSize(width, height);
	resize(mdefaultsize);

	int nNewY = (QApplication::desktop()->screenGeometry().height() - this->height()) / 2;
	int nNewX = (QApplication::desktop()->screenGeometry().width() - this->width()) / 2;

	this->move(nNewX, nNewY);
}

void VidioAndAudioDialog::OnCloseVideoRoom(const QString& roomid)
{
	if (roomid != mroomid)
	{
		return;
	}
	MainApp::UIFrame::getConversationController()->deleteVidioChatById(mroomid);
	onClose();



}

void VidioAndAudioDialog::onFullScreenWindow(const QString&roomid, bool bflag)
{
	if (roomid != mroomid)
	{
		return;
	}

	//判断主屏和副屏的位置
//	QPoint pt = QCursor::pos();
	QRect selfrect = this->geometry();
	QDesktopWidget* pDeskTopWidget = QApplication::desktop();
	QRect currentRect;
	for (int i = 0; i < QApplication::desktop()->screenCount(); i++)
	{
		QRect rectdesk;
		rectdesk.setLeft(pDeskTopWidget->screenGeometry(i).left());
		rectdesk.setTop(pDeskTopWidget->screenGeometry(i).top());
		rectdesk.setRight(pDeskTopWidget->screenGeometry(i).right());
		rectdesk.setBottom(pDeskTopWidget->screenGeometry(i).bottom());
		if (rectdesk.contains(selfrect))
		{
			if (bflag)//全屏展示
			{
				currentRect = rectdesk;
				int nNewY = currentRect.y();
				int nNewX = currentRect.x();

				this->move(nNewX, nNewY);
			}
			else
			{
				currentRect = rectdesk;
				currentRect.setWidth(currentRect.width() - 100);
				currentRect.setHeight(currentRect.height() - 120);
				int nNewY = currentRect.y() > 0 ? currentRect.y() - 100 / 2 : currentRect.y() + 100 / 2;
				int nNewX = currentRect.x() > 0 ? currentRect.x() - 120 / 2 : currentRect.x() + 100 / 2;

				this->move(nNewX, nNewY);

			}
			

			break;
		}
		
	}

	if (bflag)//全屏展示
	{
		//int screenwidth = QApplication::desktop()->screenGeometry().width();
		//int screenheight = QApplication::desktop()->screenGeometry().height();
		
		//resize(currentRect.width(), currentRect.height());
		//去掉标题栏
		ui->titlebar->setVisible(false);
	}
	if (!bflag) //取消全屏展示
	{
		//resize(currentRect);	
		ui->titlebar->setVisible(true);
	}

	resize(currentRect.width(), currentRect.height());
// 	int nNewY = (currentRect.height() - this->height()) / 2;
// 	int nNewX = (currentRect.width() - this->width()) / 2;
// 
// 	this->move(nNewX, nNewY);

	mwebrtcCommObject->setFullScreen(mPage, bflag);
}

void VidioAndAudioDialog::setStartVideoRoom(const QString& roomid)
{
	mwebrtcCommObject->setStartVideoRoom(mPage, roomid);
}

void VidioAndAudioDialog::setRoomTitle(const QString&roomtitle)
{
	QString strtitle = QStringLiteral("(beta版)  会议主题为 %1 会议正在进行中...").arg(roomtitle);
	ui->titlebar->setLeftTitle(strtitle);
	this->setWindowTitle(strtitle);
}

