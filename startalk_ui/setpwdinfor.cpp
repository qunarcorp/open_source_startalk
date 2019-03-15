#include "setpwdinfor.h"
#include "ui_SetPwdInfor.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

setpwdInfor::setpwdInfor(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::setPwdInfor())
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	auto titlebar = ui->titlebar;
	titlebar->setSizeable(false);
	titlebar->setMinable(false);
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &setpwdInfor::onClose);

	connect(ui->Btn_Cancel, &QPushButton::clicked, this, &setpwdInfor::onBtnCancel);
	connect(ui->Btn_OK, &QPushButton::clicked, this, &setpwdInfor::onBtnOk);
	QString strTitle =  QStringLiteral("    **密码箱能够帮助你存储难记的密码,我们只帮助你记录用主密码加密过的信息, \
		切记,一定要记住你的密码箱的主密码,它是开启密码箱的钥匙,如果丢失了主密码,我们是无能力帮你 \
		恢复您记录的数据的。不要遗失你的主密码！！");

	
	ui->label->setWordWrap(true);
	ui->label->setAlignment(Qt::AlignTop);
	ui->label->setText(strTitle);

}

setpwdInfor::~setpwdInfor()
{

}

void setpwdInfor::onClose()
{
	ui->lineEdit_title->setText("");
	ui->lineEdit_desc->setText("");
	ui->lineEdit_Pwd->setText("");
	LocalManDialog::onMin(true);
}



void setpwdInfor::showPwdInfor( int type )
{
	QString title;
	if (type == 0)
	{
		title = QStringLiteral("设置主密码");
	}
	else if (type == 1)
	{
		title = QStringLiteral("设置会话密码");

		ui->lineEdit_title->setText(QStringLiteral("会话密码箱"));
		ui->lineEdit_desc->setText(QStringLiteral("端到端加密会话密码箱"));

	}
	ui->titlebar->setLeftTitle(title);
	this->show();
}

void setpwdInfor::onBtnCancel()
{
	done(ChooseCancel);
	onClose();
	
}

void setpwdInfor::onBtnOk()
{
	mtitle = ui->lineEdit_title->text();
	if (mtitle.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("标题不应为空"));
		return ;
	}
	mdesc = ui->lineEdit_desc->text();
	if (mdesc.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("描叙不应为空"));
		return ;
	}
	mpwd = ui->lineEdit_Pwd->text();
	if (mpwd.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("密码不应为空"));
		return ;
	}
	mSecpwd = ui->lineEdit_Pwd_second->text();
	if (mSecpwd.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("密码验证不应为空"));
		return ;
	}

	if (mpwd != mSecpwd)
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("密码和密码验证不相等"));
		return ;
	}

	done(ChooseOK);
	onClose();
}

QString setpwdInfor::gettitle()
{
	return mtitle;
}

QString setpwdInfor::getdescription()
{
	
	
	return mdesc;
}

QString setpwdInfor::getpwd()
{
	
	
	return mpwd;
}
