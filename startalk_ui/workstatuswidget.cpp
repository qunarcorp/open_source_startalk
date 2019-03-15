#include "workstatuswidget.h"
#include "ui_WorkStatusWidget.h"
#include "jsonobject/httpresult.h"

#include "Session.h"
#include "accountmanager.h"
#include "CallbackReceiver.h"
#include "BizCallback.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"


WorkStatuswidget::WorkStatuswidget(QWidget *parent)
	: QWidget(parent)
	,ui(new Ui::WorkStatusWidget)
	,mReceiver(new Biz::CallbackReceiver(this))
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	/*    setAttribute(Qt::WA_TranslucentBackground, true); */
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	




	//服务模式
	
	connect(ui->radioButton_StandardModel, &QRadioButton::clicked, [this](){

		Log::e("WorkStatuswidget::onWorkStatusClicked radioButton_StandardModel" );

		auto callback = mReceiver->createCallback<QString>([this](QString strRet)
		{
			if (strRet.isEmpty())
			{
				MainApp::UIFrame::getNotifyCenterController ()->popupNotice ( QStringLiteral("设置状态错误!!"));
				Log::e(QStringLiteral("SettingDetail::onWorkStatusClicked radioButton_StandardModel 服务器返回是空值!!") );
				return;
			}
			Biz::HttpResultString resultJson(NULL);
			resultJson.unserializeFromString(strRet);
			bool bRet = resultJson.ret();
			QString retmsg = resultJson.data();
			QString errormsg = resultJson.msg();
			if(!bRet ){
				
				MainApp::UIFrame::getNotifyCenterController ()->popupNotice (errormsg.isEmpty() ? QStringLiteral("设置状态错误!!"):errormsg);
				return;
			}

			ui->radioButton_StandardModel->setChecked(true);
			ui->radioButton_SupermanModel->setChecked(false);
			ui->radioButton_NodisturbModel->setChecked(false);

		}, []{});

		Biz::Session::getAccountManager()->setWorkStatus(Biz::WorkStatusData::STATUS::ST_STANDAR,mSid,callback);

	});

	connect(ui->radioButton_SupermanModel, &QRadioButton::clicked, [this](){
		Log::e("SettingDetail::onWorkStatusClicked radioButton_SupermanModel");

		auto callback = mReceiver->createCallback<QString>([this](QString strRet)
		{
			if (strRet.isEmpty())
			{
				MainApp::UIFrame::getNotifyCenterController ()->popupNotice ( QStringLiteral("设置状态错误!!"));
				Log::e(QStringLiteral("SettingDetail::onWorkStatusClicked radioButton_StandardModel 服务器返回是空值!!") );
				return;
			}
			Biz::HttpResultString resultJson(NULL);
			resultJson.unserializeFromString(strRet);
			bool bRet = resultJson.ret();
			QString retmsg = resultJson.data();
			QString errormsg = resultJson.msg();
			if(!bRet ){

				MainApp::UIFrame::getNotifyCenterController ()->popupNotice (errormsg.isEmpty() ? QStringLiteral("设置状态错误!!"):errormsg);
				return;
			}


			ui->radioButton_StandardModel->setChecked(false);
			ui->radioButton_SupermanModel->setChecked(true);
			ui->radioButton_NodisturbModel->setChecked(false);
		}, []{});

		Biz::Session::getAccountManager()->setWorkStatus(Biz::WorkStatusData::STATUS::ST_SERVICE,mSid,callback);
	});

	connect(ui->radioButton_NodisturbModel, &QRadioButton::clicked, [this](){
		Log::e("SettingDetail::onWorkStatusClicked radioButton_NodisturbModel");

		auto callback = mReceiver->createCallback<QString>([this](QString strRet)
		{
			if (strRet.isEmpty())
			{
				MainApp::UIFrame::getNotifyCenterController ()->popupNotice ( QStringLiteral("设置状态错误!!"));
				Log::e(QStringLiteral("SettingDetail::onWorkStatusClicked radioButton_StandardModel 服务器返回是空值!!") );
				return;
			}
			Biz::HttpResultString resultJson(NULL);
			resultJson.unserializeFromString(strRet);
			bool bRet = resultJson.ret();
			QString retmsg = resultJson.data();
			QString errormsg = resultJson.msg();

			if(!bRet ){

				MainApp::UIFrame::getNotifyCenterController ()->popupNotice (errormsg.isEmpty() ? QStringLiteral("设置状态错误!!"):errormsg);
				return;
			}
			ui->radioButton_StandardModel->setChecked(false);
			ui->radioButton_SupermanModel->setChecked(false);
			ui->radioButton_NodisturbModel->setChecked(true);

		}, []{});

		Biz::Session::getAccountManager()->setWorkStatus(Biz::WorkStatusData::STATUS::ST_rest,mSid, callback);
	});

}

WorkStatuswidget::~WorkStatuswidget()
{

}

void WorkStatuswidget::setTitleInfor( const QString&title )
{
	ui->label_shopname->setText(title);
}

void WorkStatuswidget::setStatus( int status )
{
	if (status == Biz::WorkStatusData::STATUS::ST_rest) //勿扰模式
	{
		this->ui->radioButton_NodisturbModel->setChecked(true);
		this->ui->radioButton_SupermanModel->setChecked(false);
		this->ui->radioButton_StandardModel->setChecked(false);
	}
	else if (status == Biz::WorkStatusData::STATUS::ST_SERVICE) //超人模式
	{
		this->ui->radioButton_NodisturbModel->setChecked(false);
		this->ui->radioButton_SupermanModel->setChecked(true);
		this->ui->radioButton_StandardModel->setChecked(false);
	}
	else if (status == Biz::WorkStatusData::STATUS::ST_STANDAR) //标准模式
	{
		this->ui->radioButton_NodisturbModel->setChecked(false);
		this->ui->radioButton_SupermanModel->setChecked(false);
		this->ui->radioButton_StandardModel->setChecked(true);
	}
	else 
	{
		this->ui->radioButton_NodisturbModel->setChecked(false);
		this->ui->radioButton_SupermanModel->setChecked(false);
		this->ui->radioButton_StandardModel->setChecked(true);
	}
}

void WorkStatuswidget::setSid( int sid )
{
	mSid = sid;
}
