#include "addnoteinfor.h"
#include "ui_NoteInfor.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

AddNoteInfor::AddNoteInfor(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::NoteInfor())
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


	connect(ui->titlebar, &TitlebarWidget::sgCloseOnClicked, this, &AddNoteInfor::onCloseclicked);
	setWindowTitle("NavManager");
	ui->titlebar->setMinable(false);

	connect(ui->pbtn_cancel, &QPushButton::clicked, this, &AddNoteInfor::onCloseclicked);
	connect(ui->pbtn_ok, &QPushButton::clicked, this, &AddNoteInfor::onButtonOk);
}

AddNoteInfor::~AddNoteInfor()
{

}

void AddNoteInfor::onCloseclicked()
{
	ui->lineEdit_notetitle->setText("");
	ui->textEdit_notedesc->setText("");
	this->close();
}

void AddNoteInfor::onButtonOk()
{
	mNoteTitle = ui->lineEdit_notetitle->text();
	mNoteDesc = ui->textEdit_notedesc->toPlainText();


	if (mNoteTitle.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("标题不能为空"));
		return;
	}

	this->accept();

	ui->lineEdit_notetitle->setText("");
	ui->textEdit_notedesc->setText("");
}

void AddNoteInfor::showNoteInfo()
{

	showNormal();
	activateWindow();
}

QString AddNoteInfor::getNoteTitle()
{
	return mNoteTitle;
}

QString AddNoteInfor::getNoteDesc()
{
	return mNoteDesc;
}
