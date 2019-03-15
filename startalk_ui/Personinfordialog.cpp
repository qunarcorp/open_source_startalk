#include "Personinfordialog.h"
#include "Session.h"
#include "Account.h"
#include "RosterList.h"
#include "portraithelper.h"
#include "GroupManager.h"
#include "accountmanager.h"
#include "UserVcardManager.h"

PersonInforDialog::PersonInforDialog(LocalManDialog *parent)
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

	//请求个人信息
	//Biz::Session::currentAccount().getPersonInfor();

	//connect(&Biz::Session::currentAccount(),&Biz::Account::sgPersonInfor,this,&PersonInforDialog::onGetPersonInfor);
	onGetPersonInfor("");
	connect(ui.pbCancle, &QPushButton::clicked, this, [this](bool){this->close();});
	connect(ui.pbSave, &QPushButton::clicked, this, &PersonInforDialog::onSavePersonInfor);
	connect(&Biz::Session::currentAccount(),&Biz::Account::sgSaveInforResult, this, &PersonInforDialog::onSaveResultInfor);

	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgUseVcardChanged,this,&PersonInforDialog::onUserVcardUpdate);

	//让几个label可以选中被复制
	ui.uin_label->installEventFilter(this);
	ui.Loginname_label->installEventFilter(this);
	ui.DepatrM_label->installEventFilter(this);

	ui.label_2->setVisible(false);
	ui.label_3->setVisible(false);
	ui.MaxNumEdit->setVisible(false);
	ui.realNameEdit->setVisible(false);
	ui.WebNameEdit->setVisible(false);
	ui.pbCancle->setVisible(false);
	ui.pbSave->setVisible(false);
	ui.label_11->setVisible(false);
	ui.label_12->setVisible(false);
}

PersonInforDialog::~PersonInforDialog()
{

}

void PersonInforDialog::onUserVcardUpdate(const QStringList& users)
{
	QString userjid = Biz::MessageUtil::makeSureUserJid( Biz::Session::getAccountManager()->accountData().UserID());
	if (users.contains(userjid))
	{
		onGetPersonInfor(userjid);
	}
}
void PersonInforDialog::onGetPersonInfor( const QString& strInfor )
{
	QString userjid = Biz::MessageUtil::makeSureUserJid( Biz::Session::getAccountManager()->accountData().UserID());
	QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userjid);
	if (!spPerson.isNull())
	{
		ui.MaxNumEdit->setText(QString("%1").arg(spPerson->nMaxtalkcount));
		ui.uin_label->setText(QString("%1").arg(spPerson->strmobile));
		ui.Loginname_label->setText(Biz::MessageUtil::makeSureUserId(spPerson->strUserId));
		ui.realNameLabel->setText(spPerson->strNickName);
		ui.WebNameLabel->setText(spPerson->strWebName);
		ui.DepatrM_label->setText(spPerson->strDepartment);

		QString selurl = spPerson->strUserId;
		QPixmap header = Biz::PortraitHelper::getUserPortrait(selurl);

		ui.Image_label->setScaledContents(true);
		ui.Image_label->setPixmap(header);
	}
	else
	{
		Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersion(userjid);
	}
}

void PersonInforDialog::onSavePersonInfor()
{
	QJsonObject obj;
	obj.insert("uin", ui.uin_label->text().toLongLong());
	obj.insert("strid", ui.Loginname_label->text());
	obj.insert("nickname", ui.realNameLabel->text());
	obj.insert("webname", ui.WebNameEdit->text());
	obj.insert("maxtalkcount", ui.MaxNumEdit->text().toInt());
	obj.insert("logourl", QString(" "));
	obj.insert("sex", 0);

	QJsonDocument doc(obj);

	QString strInfor = QString::fromUtf8(doc.toJson());

	Biz::ImSelfPerson selfInfor;
	selfInfor.nMaxtalkcount = ui.MaxNumEdit->text().toInt();
	selfInfor.strWebName = ui.WebNameEdit->text();
	selfInfor.strRealName = ui.realNameLabel->text();
	Biz::Session::currentAccount().SetSelfInfor(selfInfor);

	QString newInfor = QString("webname=%1&maxtalkcount=%2&strid=%3").arg(ui.WebNameEdit->text()).arg(ui.MaxNumEdit->text().toInt()).arg(ui.Loginname_label->text());
	Biz::Session::currentAccount().onSavePersonInfor(newInfor/*strInfor*/);


}

void PersonInforDialog::onSaveResultInfor(const QString& iqjson)
{
	int nResult;
	QString strResultReson;
	QByteArray byteary;
	byteary = iqjson.toUtf8();
	QJsonDocument Json_Data = QJsonDocument::fromJson(byteary);
	if(Json_Data.isObject())
	{
		QVariantMap result = Json_Data.toVariant().toMap();
		nResult = result["return"].toInt();
		strResultReson = result["msg"].toString();
	}

	if (nResult == 0)
	{
		ui.label_SaveResult->setText(QStringLiteral("设置成功"));
	}
	else
	{
		ui.label_SaveResult->setText(strResultReson.isEmpty()?iqjson:strResultReson);
	}
}

bool PersonInforDialog::eventFilter( QObject *obj, QEvent *event )
{
	if (obj == ui.uin_label || obj == ui.Loginname_label || obj == ui.DepatrM_label)
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

