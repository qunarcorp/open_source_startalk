#include "encryptchatdialog.h"
#include "ui_EncryptChatDialog.h"
#include "TitlebarWidget.h"
#include "UIFrame.h"
#include "encryptchatcontroller.h"

EncryptChatDialog::EncryptChatDialog(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::EncryptChatDialog)
	,mbencrypt(false)
	,mWaiteTime(new QTimer(this))
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	this->setSizeGripEnabled(false);
	//设置成模态的框
	setWindowModality(Qt::ApplicationModal);

	auto titlebar = ui->titlebarWidget;
	titlebar->setSizeable(false);
	titlebar->setMinable(false);

	
	ui->label_icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/empticon.png")));

	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &EncryptChatDialog::onCloseDialog);

	connect(ui->pB_Cancel, &QPushButton::clicked, this, &EncryptChatDialog::onpbtCancel);
	connect(ui->pB_Decrypt, &QPushButton::clicked, this, &EncryptChatDialog::onpbtDecrypt);
	connect(ui->pB_Encrypt, &QPushButton::clicked, this, &EncryptChatDialog::onpbtEncrypt);

	connect(MainApp::UIFrame::getEncryptChatcontroller(), &MainApp::EncryptChatController::sgEncryptResponeInfor,
		this, &EncryptChatDialog::onEncryptChatResponeInfor);


	mWaiteTime->setInterval(1000 *60);
	connect(mWaiteTime,&QTimer::timeout,this, &EncryptChatDialog::onTimeoutFinished);

}

EncryptChatDialog::~EncryptChatDialog()
{

}

void EncryptChatDialog::setConversationId( const QString&conversationId )
{
	mConversationId = conversationId;
}

void EncryptChatDialog::setEncryptButtonType( bool btype )
{
	mbencrypt = true;
	ui->pB_Encrypt->setText(QStringLiteral("关闭加密会话"));
}

void EncryptChatDialog::onCloseDialog()
{
	this->close();
}

void EncryptChatDialog::onpbtCancel()
{
	this->close();
	MainApp::UIFrame::getEncryptChatcontroller()->sgCancelEncryptChat(mConversationId);

	ui->label_icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/empticon.png")));
	ui->label_infor->setText(QStringLiteral("加密会话"));
	ui->pB_Encrypt->setText(QStringLiteral("开始加密会话"));
}

void EncryptChatDialog::onpbtDecrypt()
{
	MainApp::UIFrame::getEncryptChatcontroller()->sgDecryptChat(mConversationId);
	this->close();
}

void EncryptChatDialog::onpbtEncrypt()
{
	if (mbencrypt)
	{
		MainApp::UIFrame::getEncryptChatcontroller()->sgCloseEncryptChat(mConversationId);
		mbencrypt = false;
		ui->pB_Encrypt->setText(QStringLiteral("开始加密会话"));

		this->close();
	}
	else
	{
		MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptChat(mConversationId);
		
	}
	
}

void EncryptChatDialog::onEncryptChatResponeInfor( int type, const QString& conversationId, const QString&infor )
{
	if (type == MainApp::ResponeWait) //等待
	{
		ui->label_icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/jiazai.png")));
		ui->label_infor->setText(infor);
		mWaiteTime->start();
	}
	else if (type == MainApp::ResponeArgee) //同意
	{
		ui->label_icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/empticon.png")));
		ui->label_infor->setText(infor);

		//下次打开这个框子，应该变成关闭会话加密的文字
		mbencrypt = true;
		ui->pB_Encrypt->setText(QStringLiteral("关闭加密会话"));

		mWaiteTime->stop();
		this->close();
	}
	else if (type == MainApp::ResponeRefuse) //拒绝
	{
		ui->label_icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/empticon.png")));
		ui->label_infor->setText(infor);

		mWaiteTime->stop();
		this->close();
	}
	else if (type == MainApp::ResponeClose)
	{
		mbencrypt = true;
		ui->pB_Encrypt->setText(QStringLiteral("开始加密会话"));
	}
	//this->close();
}

void EncryptChatDialog::onTimeoutFinished()
{
	mWaiteTime->stop();

	this->close();
}
