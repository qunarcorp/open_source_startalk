#include "voicesetting.h"
#include "ui_VoiceSetting.h"
#include "Session.h"
#include <QSound>
#include <QFileDialog>
#include "SettingData.h"
#include "PlaySound.h"

VoiceSetting::VoiceSetting(QWidget *parent)
	: LocalManDialog(parent), ui(new Ui::VoiceSetting())
{
	ui->setupUi(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | Tool;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	auto titlebar = ui->widget_title;
	titlebar->setSizeable(false);
	titlebar->setMinable(false);
	setWindowTitle(QStringLiteral("声音设置"));
	this->setWindowFlags(Qt::FramelessWindowHint);
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManDialog::onMin);


	InitLineEdit();

	InitConnect();
	

}

VoiceSetting::~VoiceSetting()
{

}

void VoiceSetting::InitLineEdit()
{
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();

	QFontMetrics elidfont(ui->lineEdit_MsgVoicePath->font());
	QString path = settingconfig->MsgVoicePath();
	QString elidedText = elidfont.elidedText(path, Qt::ElideMiddle, qMax(180, ui->lineEdit_MsgVoicePath->width()));
	ui->lineEdit_MsgVoicePath->setText(elidedText);
	ui->lineEdit_MsgVoicePath->setToolTip(path);

	path = settingconfig->NoteVoicePath();
	elidedText = elidfont.elidedText(path, Qt::ElideMiddle, qMax(180, ui->lineEdit_WelVoicePath->width()));
	ui->lineEdit_WelVoicePath->setText(elidedText);
	ui->lineEdit_WelVoicePath->setToolTip(path);
}

void VoiceSetting::InitConnect()
{
	//声音试播放
	connect(ui->pb_playMsgvoice, &QPushButton::clicked, [this]{
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString strfilePath = settingconfig->MsgVoicePath();
        SoundPlayer::playSound (strfilePath);
	});

	connect(ui->pb_playWelvoice, &QPushButton::clicked, [this]{
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString strfilePath = settingconfig->NoteVoicePath();
        SoundPlayer::playSound (strfilePath);
	});

	//开启，关闭

	//查找声音
	connect(ui->pb_selectMsgFolder, &QPushButton::clicked, [this]{
		QString fileName = QFileDialog::getOpenFileName(this,"","","voice(*.wav)");
		if (!fileName.isNull())
		{
			InitLineEdit();
			Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
			settingconfig->MsgVoicePath(fileName);
			Biz::Session::saveSettingConfig();
			PlaySoundsingleton::getInstance()->setMsgSourcePath(fileName);
		}
	});

	connect(ui->pb_selectWelFolder, &QPushButton::clicked, [this]{
		QString fileName = QFileDialog::getOpenFileName(this,"","","voice(*.wav)");
		if (!fileName.isNull())
		{
			InitLineEdit();
			Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
			settingconfig->NoteVoicePath(fileName);
			Biz::Session::saveSettingConfig();
			PlaySoundsingleton::getInstance()->setMsgSourcePath(fileName);
		}
	});
}

