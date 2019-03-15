#include "AboutDialog.h"
#include "LanguageHelper.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "SystemConfigData.h"

AboutDialog::AboutDialog(QDialog *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Tool | FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    //setAttribute(Qt::WA_TranslucentBackground, true); 
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    ui.pushButton->setText(T_("MinitoolBar_Ok"));
    connect(ui.pushButton, &QPushButton::clicked, this, &AboutDialog::onClose);
        
    this->setWindowTitle(T_("MainMenu_About"));

    QString strMainVerion = Biz::ConfigureHelper::appVersionInfo();

    QString strDesc = QString("%1 %2\r\n%3 %4\r\n%5 %6")
        .arg(T_("AboutDlg_Client_Ver")).arg(strMainVerion)
        .arg(T_("AboutDlg_Server_Ver")).arg(Biz::ConfigureHelper::getServerVersion())
        .arg(T_("AboutDlg_ServerHost")).arg(Biz::Session::getSystemConfig()->getXmppHost());
    ui.lblDesc->setText(strDesc);
#ifdef QCHAT
	ui.lblTitle->setText("Qunar Chat 2015");
#endif // QCHAT

}

AboutDialog::~AboutDialog()
{

}
void AboutDialog::onClose(bool)
{
    this->close();
}
