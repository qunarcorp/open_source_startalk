#include "Personinfor_employdialog.h"

#include "Session.h"
#include "Account.h"
#include "RosterList.h"
#include "portraithelper.h"
#include "accountmanager.h"
#include "UserVcardManager.h"

Personinfor_employDialog::Personinfor_employDialog(LocalManDialog *parent)
	: LocalManDialog(parent)
{
	ui.setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	connect(ui.pbclose, &QPushButton::clicked, this, [this](bool){this->close();});

	onGetPersonInfor();
	
	connect(ui.ButtonOK, &QPushButton::clicked, this, &Personinfor_employDialog::onButtonOk);

	ui.loginName_label->installEventFilter(this);
	ui.mobil_label->installEventFilter(this);
	ui.Email_label->installEventFilter(this);

	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgUseVcardChanged,this,&Personinfor_employDialog::onUserVcardUpdate);

}

Personinfor_employDialog::~Personinfor_employDialog()
{

}

void Personinfor_employDialog::onButtonOk()
{
	this->close();
}

void Personinfor_employDialog::onUserVcardUpdate(const QStringList& users)
{
	QString userjid = Biz::MessageUtil::makeSureUserJid( Biz::Session::getAccountManager()->accountData().UserID());
	if (users.contains(userjid))
	{
		onGetPersonInfor();
	}
}


void Personinfor_employDialog::onGetPersonInfor()
{
	QString userjid = Biz::MessageUtil::makeSureUserJid( Biz::Session::getAccountManager()->accountData().UserID());
	QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userjid);
	if (!spPerson.isNull())
	{
		ui.loginName_label->setText(QString("%1").arg(spPerson->strUserId));
		ui.mobil_label->setText(QString("%1").arg(spPerson->strmobile));
		ui.Email_label->setText(spPerson->strEmail);

		QString selurl = spPerson->strUserId;
		QPixmap header = Biz::PortraitHelper::getUserPortrait(selurl);

		ui.Image_Label->setScaledContents(true);
		ui.Image_Label->setPixmap(header);
	}
	else
	{
		Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersion(userjid);
	}

}

bool Personinfor_employDialog::eventFilter( QObject *obj, QEvent *event )
{
	if (obj == ui.loginName_label || obj == ui.mobil_label || obj == ui.Email_label)
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			QLabel* plabel = (QLabel*)obj;
			plabel->setSelection(0,plabel->text().size());
			return true;
		}
	}
	return QDialog::eventFilter(obj, event);
}

