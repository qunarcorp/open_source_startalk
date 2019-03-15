#include "ProgressDialog.h"
#include "ui_ProgressDialog.h"
#include "LanguageHelper.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#ifdef _WINDOWS
#include <windows.h>
#include <windowsx.h>
#endif

ProgressDialog::ProgressDialog(QWidget *parent)
	: LocalManWidget(parent)
{
	ui = new Ui::ProgressDialog();
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = Qt::Tool | FramelessWindowHint | WindowMinMaxButtonsHint | Dialog | Qt::WindowStaysOnTopHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	//setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	ui->label_infor->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
	setWindowModality(Qt::WindowModal);

	ui->pushButtonOK->setText(T_("MessageBox_Confirm"));
	ui->pushButtonOK->hide();
	ui->label_infor->hide();
	//connect(this, &ProgressDialog::sgclose, this, &ProgressDialog::close);
	connect(ui->pushButtonOK, &QPushButton::clicked, this, &ProgressDialog::onButtonClicked);

	ui->progressBar->setRange(0, 100);
	ui->progressBar->setMaximum(100);
	
}

ProgressDialog::~ProgressDialog()
{
	delete ui;
}



void ProgressDialog::setRangeBar(qint64 done, qint64 total)
{
	double fdone = 0 ;
	if (total!= 0)
	{
		fdone = (done * 100)/total ;
	}
	
	ui->progressBar->setValue(fdone);
	
}

void ProgressDialog::onButtonClicked()
{
#ifdef _WINDOWS
    bool bret = ShellExecute(NULL,NULL,(LPWSTR)strmSavePath.utf16(),(LPWSTR)QString("/quitinstall=1").utf16(),NULL,SW_SHOW);
	if (!bret)
	{
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (T_("MessageBox_InstallFail"));
		Log::e(QString("安装包错误"));
		
		return;
	}
	qApp->quit();
#endif
}
void ProgressDialog::setSavePath(const QString &strSavePath)
{
	strmSavePath = strSavePath;

    ui->progressBar->hide();
    ui->label_infor->setText(T_("MessageBox_OkInstall"));
    ui->pushButtonOK->show();
    ui->label_infor->show();
}