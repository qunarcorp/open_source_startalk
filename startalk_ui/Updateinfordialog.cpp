#include "Updateinfordialog.h"
#include <QDesktopServices>
#include "LanguageHelper.h"
#include <qglobal.h>
#include "ConfigureHelper.h"
#include "CallbackReceiver.h"

#include "Session.h"
#include "Account.h"
#include "SystemDefine.h"
#include "attachmentmanager.h"


#ifdef _WINDOWS
#include <windows.h>
#endif


UpdateInforDialog::UpdateInforDialog(QDialog *parent)
    : LocalManDialog(parent)
{
    ui = new Ui::UpdateInforNewDialog();
    ui->setupUi(this);


    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Tool | FramelessWindowHint | WindowMinMaxButtonsHint | Dialog | Qt::WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("Application_Name"));
    setModal(true);

    connect(ui->pushButton_once, &QPushButton::clicked, this, &UpdateInforDialog::onOnceClicked);
    connect(ui->pushButton_later, &QPushButton::clicked, this, &UpdateInforDialog::onLaterClicked);
	disconnect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &UpdateInforDialog::onProgressDisplay );
	connect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &UpdateInforDialog::onProgressDisplay );
	

    this->setSizeGripEnabled(false);

    ui->Title_bar->setMinable(false);
    ui->Title_bar->setMaxable(false);
    ui->Title_bar->setLeftTitle(T_("UpdateInfor_Title"));

    connect(ui->Title_bar,&TitlebarWidget::sgCloseOnClicked,this,&LocalManDialog::onMin);
}

UpdateInforDialog::~UpdateInforDialog()
{

}

void UpdateInforDialog::setButton(int button)
{
    ui->pushButton_once->setVisible(button & MessageButton_Once);
    ui->pushButton_later->setVisible(button & MessageButton_Later);
}
void UpdateInforDialog::setEditStringText(const QString& strtdisplay)
{
    QString strVerion = _checkVersionUpdate->currentVersion;

    QString strbuf = QStringLiteral("需要升级到版本：") + strVerion;
    QString strtmp = strtdisplay;
    QStringList strlist;
    strlist = strtmp.split(";");

    //QString strDisply = "<div><img src=:/Images/22.png/></div>";

    //strDisply.sprintf("<div><img src=\"%s\"/></div>", strimage);
    QString strDisply = "<div><b><font size=\"6\" color=red>";
    strDisply += strbuf;
    strDisply += "</font></b></div>";
    foreach (QString str, strlist)
    {
        QString strtp;
        strtp = "<div>";
        strtp += str;
        strtp += "</div>";
        strDisply += strtp;
    }

	ui->label_msg->setText(strDisply);
}

void UpdateInforDialog::onOnceClicked(bool)
{
	done(UpdateUserChooseOnce);
}
void UpdateInforDialog::onLaterClicked(bool)
{
    done(UpdateUserChooseLater);
}
void UpdateInforDialog::setOnceText(const QString& text)
{
    ui->pushButton_once->setText(text);
}
void UpdateInforDialog::setLaterText(const QString& text)
{
    ui->pushButton_later->setText(text);
}

void UpdateInforDialog::setCheckVersionUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& update)
{
    _checkVersionUpdate = update;
}

void UpdateInforDialog::onProgressDisplay(const qint64 done, const qint64 total)
{
	//dlg->setRangeBar(done, total);
}


