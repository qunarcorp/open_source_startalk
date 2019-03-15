#include "DealMessageBox.h"
#include "ui_DealMessageBox.h"
#include "LanguageHelper.h"
#include <QDesktopServices>
DealMessageBox* DealMessageBox::m_DealmsgBox = NULL;
DealMessageBox::DealMessageBox(QDialog *parent)
    : LocalManDialog(parent)
{
    ui = new Ui::DealMessageBox();
    ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
	auto add = Qt::Tool | FramelessWindowHint | WindowMinMaxButtonsHint | Dialog | Qt::WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    auto titlebar = ui->titlebar;
    titlebar->setMaxable(false);
    titlebar->setMinable(false);

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("Application_Name"));

    ui->confirm->setText(T_("MessageBox_Confirm"));
    ui->cancel->setText(T_("MessageBox_Cancel"));

    setModal(true);

    connect(ui->confirm, &QPushButton::clicked, this, &DealMessageBox::onConfirmClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &DealMessageBox::onCancelClicked);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &DealMessageBox::onCancelClicked);
	m_flag = false;
	connect(ui->label_2,SIGNAL(linkActivated(QString)),this,SLOT(onopenUrl(QString)));  //在.h里面定义一个槽private slots: void openUrl(QString url);
}

DealMessageBox::~DealMessageBox()
{
    delete ui;
}

void DealMessageBox::setDisplayText(const QString& text)
{
    ui->label_2->setText(text);
}

void DealMessageBox::setButton( int button )
{
    ui->confirm->setVisible(button & MessageButton_Confirm);
    ui->cancel->setVisible(button & MessageButton_Cancel);
}

void DealMessageBox::onConfirmClicked( bool )
{
	
    this->accept();
}

void DealMessageBox::onCancelClicked( bool )
{
	
    this->reject();
}

void DealMessageBox::setConfirmText(const QString& text)
{
    ui->confirm->setText(text);
}

void DealMessageBox::setCancelText(const QString& text)
{
    ui->cancel->setText(text);
}
void DealMessageBox::reject()
{
	
	//close();
	if (m_flag)
	{
		close();
	}
	else
	{
		QDialog::reject();
	}
	
}

void DealMessageBox::setmyflag(bool bret)
{
	m_flag = bret;
}

void DealMessageBox::onopenUrl( QString url )
{
	QDesktopServices::openUrl(QUrl(url));
}


DealMessageBox* DealMessageBox::getInstanc(QDialog*parent)
{
	if (NULL == m_DealmsgBox)
	{
		m_DealmsgBox = new DealMessageBox(parent);
	}
	return m_DealmsgBox;
}
