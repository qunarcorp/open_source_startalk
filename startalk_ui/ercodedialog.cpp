#include "ercodedialog.h"
#include "ui_ErCodeDialog.h"


ErCodeDialog* ErCodeDialog::instance = NULL;

ErCodeDialog::ErCodeDialog(QWidget *parent)
	: LocalManWidget(parent)
	,ui(new Ui::ErCodeDialog)
{
	ui->setupUi(this);

	auto remove = Qt::WindowTitleHint;
	auto add = Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint|Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	ui->titlebar->setMinable(false);
	ui->titlebar->setMaxable(false);
	ui->titlebar->setLeftTitle(QStringLiteral("群二维码"));
	connect(ui->titlebar,&TitlebarWidget::sgCloseOnClicked,this,&ErCodeDialog::onClosed);
}

ErCodeDialog::~ErCodeDialog()
{

}

void ErCodeDialog::onClosed()
{
	LocalManWidget::onClose(false);
}

ErCodeDialog* ErCodeDialog::getInstance(QWidget*parent)
{
	if (instance==NULL)
	{
		instance = new ErCodeDialog(parent);
		//instance->setModal(true);
	}
	return instance;
}

void ErCodeDialog::setErCodePixmap( const QPixmap& pixmap )
{
	QSize size(180, 180);

	QPixmap avarpixmap = pixmap;
	avarpixmap = QPixmap::fromImage(avarpixmap.toImage().scaled(size));
	ui->avarercode->setPixmap(avarpixmap);

	this->showNormal();
}