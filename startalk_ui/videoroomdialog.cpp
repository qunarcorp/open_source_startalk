#include "videoroomdialog.h"
#include <QPushButton>
#include "diywidgit/customviews/qframelayout.h"
#include "NotifyCenterController.h"
#include "UIFrame.h"


void VideoRoomDialog::ShowDlg()
{
	showNormal();
	activateWindow();
}

QString VideoRoomDialog::getRoomName()
{
	QString strName = ui->textEdit->toPlainText().trimmed().replace("\n", "");
	return strName;
}

VideoRoomDialog::VideoRoomDialog(LocalManDialog *parent)
	:LocalManDialog(parent)
	, ui(new Ui::VideoRoomDialog)
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

	ui->Title_bar->setMinable(false);
	ui->Title_bar->setMaxable(false);
	ui->Title_bar->setLeftTitle("");


	connect(ui->Title_bar, &TitlebarWidget::sgCloseOnClicked, [this]{
		hide();
	});

	connect(ui->cancel, &QPushButton::clicked, [this]{
		hide();
	});

	connect(ui->ok, &QPushButton::clicked, this, &VideoRoomDialog::onAcceptOk);
}

VideoRoomDialog::~VideoRoomDialog()
{

}

void VideoRoomDialog::onAcceptOk()
{
	QString strName = ui->textEdit->toPlainText();
	if (strName.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("会议室名称不能为空"));
		return;
	}

	done(OK);
}
