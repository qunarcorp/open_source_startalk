#include "addnavdialog.h"
#include "ui_AddNavDialog.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

void AddNavDialog::showAddNavDialog()
{
	showNormal();
	activateWindow();
}

AddNavDialog::AddNavDialog(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::AddNavDialog())
{
	ui->setupUi(this);

	using namespace Qt;

	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Tool;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

	
	connect(ui->titlebar, &TitlebarWidget::sgCloseOnClicked, this, &AddNavDialog::onCloseclicked);
	setWindowTitle("NavManager");
	ui->titlebar->setMinable(false);

	connect(ui->pbt_cancel, &QPushButton::clicked, this, &AddNavDialog::onCloseclicked);
	connect(ui->pbt_ok, &QPushButton::clicked, this, &AddNavDialog::onButtonOk);
}

AddNavDialog::~AddNavDialog()
{

}

void AddNavDialog::onCloseclicked()
{
	ui->lineEdit_Cmpurl->setText("");
	this->close();
}

void AddNavDialog::onButtonOk()
{
	
	m_InputCompNav = ui->lineEdit_Cmpurl->text().trimmed();


	if (m_InputCompNav.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("域名不能为空"));
		return;
	}

	this->accept();
	
	ui->lineEdit_Cmpurl->setText("");
}


QString AddNavDialog::getCompanyUrl()
{
	return m_InputCompNav;
}
