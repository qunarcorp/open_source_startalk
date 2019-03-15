#include "sysmessagedialog.h"
#include "LanguageHelper.h"
#include "XmppMessage.h"

SysMessageDialog::SysMessageDialog(QWidget *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("SysMessageDlg_Title"));
    
    ui.titlebarWidget->setLeftTitle(T_("SysMessageDlg_Title"));
    ui.titlebarWidget->setMaxable(false);
    ui.titlebarWidget->setMinable(false);

    ui.btnClose->setText(T_("recent_item_action4"));
    connect(ui.btnClose, &QPushButton::clicked, this, &SysMessageDialog::onClosed);
    connect(ui.titlebarWidget, &TitlebarWidget::sgCloseOnClicked, this, &SysMessageDialog::onClosed);

}

SysMessageDialog::~SysMessageDialog()
{

}

void SysMessageDialog::setMessage( const QSharedPointer<Biz::XmppMessage>& msg)
{
    ui.txtSubject->setText(msg->Subject());
    ui.txtBody->setText(msg->Body());
}
void SysMessageDialog::onClosed(bool)
{
    this->close();
}