#include "addfriendanswer.h"
#include "combinationcontroller.h"
#include "Session.h"
#include "SystemConfigData.h"
#include "friendsmanager.h"
AddFriendAnswer* AddFriendAnswer::pInstance = NULL;
AddFriendAnswer::AddFriendAnswer(QWidget *parent)
	: LocalManWidget(parent), ui(new Ui::AddFriendAnswerDialog())
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;//|Popup;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	connect(ui->pb_ok, &QPushButton::clicked, this, &AddFriendAnswer::onButtonOK );
	connect(ui->pb_cancel, &QPushButton::clicked, [this](bool bret){
		close();
	});

    auto title = ui->titlebar;
    title->setMaxable(false);
    title->setMinable(false);
    title->setCloseable(false);
}

AddFriendAnswer::~AddFriendAnswer()
{

}

void AddFriendAnswer::onButtonOK()
{
	QString Jid = Biz::MessageUtil::makeSureUserJid(mUserid);
	if (ntype == Biz::VeryFriendMode::FriendInformation)
	{
		
		Biz::Session::getFriendManager()->verifyInfoMode( Jid,  ui->lineEdit_answer->text());
	}
	else if (ntype == Biz::VeryFriendMode::FriendQuestAndAnswer)
	{
		Biz::Session::getFriendManager()->verify(Jid ,ui->lineEdit_answer->text());
	}
	close();
}

AddFriendAnswer* AddFriendAnswer::instance()
{
	if (pInstance==NULL)
	{
		pInstance = new AddFriendAnswer();
	}
	return pInstance;
}
void AddFriendAnswer::showAddFriend(const QString& userid,int ntype, const QString& strquestion)
{
    auto title = ui->titlebar;

	this->ntype = ntype;
	this->mUserid = userid;
	if (ntype == Biz::VeryFriendMode::FriendInformation)
	{
        title->setLeftTitle(QStringLiteral("请输入相关信息，等待好友验证"));
		ui->label_answer->setText(QStringLiteral("文本信息验证好友"));
	}
	else if (ntype == Biz::VeryFriendMode::FriendQuestAndAnswer)
	{
        title->setLeftTitle(QStringLiteral("请回答下面的提问:"));
		ui->label_answer->setText(strquestion);
	}
    ui->lineEdit_answer->setText ("");
	showNormal();
}