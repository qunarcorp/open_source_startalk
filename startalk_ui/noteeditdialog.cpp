#include "noteeditdialog.h"
#include "ui_NoteEditDialog.h"
#include "ConfigureHelper.h"


NoteEditDialog::NoteEditDialog(LocalManDialog *parent)
	: LocalManDialog(parent)
	,ui(new Ui::NoteEditDialog)
	,mCommObject(new ChatCommObject(this))
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags((Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

	ui->titlebar->setMinable(false);
	ui->titlebar->setMaxable(false);
	ui->titlebar->setLeftTitle("Note");


	connect(ui->titlebar, &TitlebarWidget::sgCloseOnClicked, [this]{
		hide();
	});

	connect(ui->pbt_cancel, &QPushButton::clicked, [this]{
		hide();
	});

	connect(ui->pbt_ok, &QPushButton::clicked, this, &NoteEditDialog::onNoteEditOK);

	LoadHtml();

	connect(mCommObject, &ChatCommObject::sgSaveNote, this, &NoteEditDialog::onSaveNote);
}

NoteEditDialog::~NoteEditDialog()
{

}

void NoteEditDialog::LoadHtml()
{
	 mPage = new ChatWebPage(this);
	connect(ui->webView, &webview::loadFinished, this,&NoteEditDialog::onLoadHtmlFinish);

	ui->webView->setContextMenuPolicy(Qt::CustomContextMenu);

	mPage->addChatChannelToHtml("client_api", mCommObject);
	ui->webView->setPage(mPage);
	//loadChatHtml(ui->webView, "/html/dialog.html");
	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath())
		+ "/html/NoteEdit/indexEdit.html";
	QUrl url = QUrl::fromLocalFile(strDirHtml);
	ui->webView->load(url);
}

QString NoteEditDialog::getContent()
{
	return mContent;
}

void NoteEditDialog::onLoadHtmlFinish( bool bret )
{
	//test 放一段文本到里面
	mCommObject->appendNote(mPage, "<p><strong><em>123456</em></strong></p>");
}

void NoteEditDialog::ShowNoteEditDialog()
{
	showNormal();
	activateWindow();
}

void NoteEditDialog::onNoteEditOK()
{
	mCommObject->getNoteEditInfo(mPage);
}

void NoteEditDialog::onSaveNote(const QString& content)
{
	mContent = content;

	this->accept();
}