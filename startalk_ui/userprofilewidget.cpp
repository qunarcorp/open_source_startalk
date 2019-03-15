#include "userprofilewidget.h"
#include "ui_userprofilewidget.h"

#include <QObjectUserData>
#include <QKeyEvent>
#include "XmppMessage.h"

#include "Session.h"
#include "UserVcardManager.h"
#include "accountmanager.h"
#include "staffmanager.h"
#include "Account.h"
#include "portraithelper.h"
#include "CallbackReceiver.h"
#include "BizCallback.h"
#include "DealMessageBox.h"

#include "diywidgit/customviews/qframelayout.h"

#include "AccountData.h"
#include "conversationmanager.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"
class LeaderUserData : public  QObjectUserData
{
public:
    QString qtalk_id;
};


UserProfileWidget::UserProfileWidget(QWidget *parent)
    : LocalManDialog(parent)
    , mpReceive(new Biz::CallbackReceiver(this))
    , ui(new Ui::UserProfileWidget())
	,m_GifPlayer(new QMovie(this))
{
    ui->setupUi(this);
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Tool | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    setWindowTitle(QStringLiteral("个人资料"));
	
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));

#endif
	ui->leBoom->installEventFilter(this);
	ui->leMark->installEventFilter(this);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &UserProfileWidget::onClose);


    connect(ui->lbLeaderLink,&QLabel::linkActivated,this,&UserProfileWidget::onLinkClicked);
    connect(ui->lbMobileLink,&QLabel::linkActivated,this,&UserProfileWidget::onLinkClicked);

    //connect(ui->btnAvatar,&QPushButton::clicked,this,&UserProfileWidget::onChangeAvatarClicked);
#ifndef QCHAT

	ui->btnAvatar->installEventFilter(this);

#endif // QCHAT

    connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgUseVcardChanged,this,&UserProfileWidget::onUserVcardChange);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUserMoodInforChanged, this, &UserProfileWidget::onUserMoodInforChange);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &UserProfileWidget::onUserPortraitUpdate);

}

UserProfileWidget::~UserProfileWidget()
{

}

UserProfileWidget* UserProfileWidget::setUser(const QString& userid)
{

	//这个时候去拿这个人的名片信息
	Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(Biz::MessageUtil::makeSureUserJid(userid)));

    resetData();
    mJid = Biz::MessageUtil::makeSureUserJid(userid);

    setData();

    return this;
}

void UserProfileWidget::resetData()
{
    mJid = "";
    ui->leBoom->setText("");
    ui->leMark->setText("");
    ui->lbLeaderLink->setText("");
    ui->lbMobileLink->setText(QStringLiteral("<a href='http://undef'><span style=' text-decoration: underline; color:#0000ff;'>点击查看</span></a>"));
    ui->name->setText("");
    ui->id->setText("");
    ui->dep->setText("");
}

void UserProfileWidget::setData()
{
	
    bool bself = Biz::MessageUtil::compareUserId(mJid,Biz::Session::getAccountManager()->accountData().UserID());
    //ui->btnAvatar->setEnabled(bself);
#ifndef QCHAT
	ui->btnAvatar->setToolTip(bself?QStringLiteral("点击修改头像"):"");
	
// 	ui->leBoom->setEnabled(bself);
 	if (bself)
	{
		//ui->leBoom->setFocus(Qt::OtherFocusReason);
		ui->btnAvatar->setCursor(QCursor(Qt::PointingHandCursor));
	}
	else
	{
		ui->leBoom->setFocusPolicy(Qt::NoFocus);
		
		ui->btnAvatar->setCursor(QCursor(Qt::ArrowCursor));
	}
#else
	ui->btnAvatar->setToolTip("");
#endif
    

	ui->sex->setVisible(false);

    
	showAvatar();
	
	

    QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(mJid);
    if (!spPerson.isNull())
    {
        
        ui->leMark->setText(spPerson->strMarkName);
		ui->name->setText(spPerson->strNickName);
    }
    
	setSex(mJid);
	//在这里先请求一下心情短语
	Biz::Session::getUserVcardManager()->getUserMoodInfobyId(mJid);
     QString strName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(mJid);
    
    ui->id->setText(Biz::MessageUtil::makeSureUserId(mJid));
    ui->dep->setText(Biz::Session::currentAccount().getUserGroup(Biz::MessageUtil::makeSureUserId(mJid)));

   
    //ui->leBoom->setText(strName);
    ui->lbLeaderLink->setText("");
    ui->lbLeaderLink->setEnabled(false);
    Biz::UnitCallback<QString>* detailStr = mpReceive->createCallback<QString>([this](const QString& result){
        ui->lbLeaderLink->setEnabled(true);
        QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
        QVariantMap root = doc.toVariant().toMap();

        if (root.contains("errcode"))
        {
            int nError = root.value("errcode").toInt();
            if (0==nError)
            {
                if (root.contains("data"))
                {
                    QVariantMap dataMap = root.value("data").toMap();
                    if (dataMap.contains("leader"))
                    {
                        QString leaderLink = QString("<a href='http://undef'><span style='text-decoration: underline; color:#0000ff;'>%1 (%2)</span></a>").arg(dataMap.value("leader").toString(),dataMap.value("qtalk_id").toString());
                        ui->lbLeaderLink->setText(leaderLink);
                    }

                    if (dataMap.contains("qtalk_id"))
                    {
                        LeaderUserData* userData = new LeaderUserData();
                        userData->qtalk_id = dataMap.value("qtalk_id").toString();
                        ui->lbLeaderLink->setUserData(Qt::UserRole,userData);
                    }
                }
            }
            else
            {
                MainApp::UIFrame::getNotifyCenterController ()->alertMessage (root.contains("msg")?root.value("msg").toString():QStringLiteral("请求失败:%1").arg(nError));
            }
        }

        
    },[]{});
   
    Biz::Session::getStaffManager()->getUserLeader(mJid,detailStr);
    
}

bool UserProfileWidget::eventFilter(QObject *obj, QEvent *e)
{
    if (this == obj)
    {
        if (QEvent::MouseButtonPress == e->type())
        {
            ui->leEmpty->setFocus();
        }
    }

	if (obj == ui->leBoom)
	{
		if (e->type() == QEvent::FocusOut)
		{
			Biz::Session::getUserVcardManager()->setUserMoodInfo(mJid, ui->leBoom->text());
		}
		if (e->type() == QEvent::MouseButtonPress && Biz::MessageUtil::compareUserId(mJid,Biz::Session::getAccountManager()->accountData().UserID()))
		{
			ui->leBoom->setFocus();
		}

	}
	if (obj == ui->leMark)
	{
		if (e->type() == QEvent::FocusOut 
#ifdef QCHAT
			|| (e->type() == QEvent::KeyPress 
				&& (((QKeyEvent*)e)->key() == Qt::Key_Enter 
				|| ((QKeyEvent*)e)->key() == Qt::Key_Return))
#endif // QCHAT
			)
		{
			// 保存备注
			QSharedPointer<Biz::ConversationMarkInfo> spInfo(new Biz::ConversationMarkInfo);
			spInfo->conversationId(mJid);
			spInfo->markTitle(ui->leMark->text());
			Biz::Session::getConverSationManager()->saveConversationMarkInfo(spInfo);
			//漫游给个人配置
			Biz::Session::getConverSationManager()->updateMarkupName(spInfo->conversationId(), spInfo->markTitle());

			// 同步到会话
			MainApp::UIFrame::getConversationController()->updateMarkInfo(spInfo->conversationId());
		}
	}
	if (obj == ui->btnAvatar)
	{
		if (e->type() == QEvent::MouseButtonDblClick || e->type() == QEvent::MouseButtonPress)
		{
			if (Biz::MessageUtil::compareUserId(mJid,Biz::Session::getAccountManager()->accountData().UserID()))
			{
				onChangeAvatarClicked(true);
			}
			
		}
	}
    return LocalManDialog::eventFilter(obj,e);
}

void UserProfileWidget::onLinkClicked(const QString& link)
{
    QObject* object = sender();
    if (ui->lbLeaderLink == object)
    {
        LeaderUserData* pUserData = dynamic_cast<LeaderUserData*>(object->userData(Qt::UserRole));
        if (NULL!=pUserData && !pUserData->qtalk_id.isEmpty())
        {
            this->setUser(Biz::MessageUtil::makeSureUserJid(pUserData->qtalk_id));
        }
    }

    if (ui->lbMobileLink == object)
    {
        Biz::UnitCallback<QString>* mobileStr = mpReceive->createCallback<QString>([this](const QString& result){
            ui->lbMobileLink->setEnabled(true);

            QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
            QVariantMap root = doc.toVariant().toMap();

            if (root.contains("errcode"))
            {
                int nError = root.value("errcode").toInt();
                if (0==nError)
                {
                    if (root.contains("data"))
                    {
                        QVariantMap dataMap = root.value("data").toMap();
                        if (dataMap.contains("phone"))
                        {
                            QString phone = dataMap.value("phone").toString();
                            ui->lbMobileLink->setText(phone);
                        }
                    }
                }
                else
                {
                    MainApp::UIFrame::getNotifyCenterController ()->alertMessage(root.contains("msg")?root.value("msg").toString():QStringLiteral("请求失败:%1").arg(nError));
                }
            }

           
        },[]{});
        ui->lbMobileLink->setEnabled(false);
        Biz::Session::getStaffManager()->getUserMobildPhone(mJid,mobileStr);
    }
}

void UserProfileWidget::onUserVcardChange(const QStringList& userids)
{
    if (userids.contains(mJid) || userids.contains(Biz::MessageUtil::makeSureUserId(mJid)))
    {
		QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(mJid);
		if (!spPerson.isNull())
		{

			ui->leMark->setText(spPerson->strMarkName);
		}
    }
}

#include <QFileDialog>
void UserProfileWidget::onChangeAvatarClicked(bool bcheck)
{
    QString fileName = QFileDialog::getOpenFileName(this,"","","Images(*.png *.jpeg *.jpg *.tiff *.gif)");
    if (!fileName.isNull())
    {
		QFileInfo infor(fileName);
		if ( (infor.suffix().compare("gif", Qt::CaseInsensitive) == 0) &&  infor.size() > SizeOfGifImage )
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("上传的gif图片不能大于1M"));
			return;
		}
		m_GifPlayer->stop();
		m_GifPlayer->setFileName("");

         Biz::Session::currentAccount().updateAvatar(Biz::Session::currentAccount().accountData().UserID(), fileName); 

//          QPixmap pixmap = Biz::PortraitHelper::loadPixmap(fileName);
//          ui->btnAvatar->setPixmap(pixmap.scaled(ui->btnAvatar->size()));
	//	MainApp::UIFrame::getMainDialogController()->showPortrait(ui->btnAvatar, Biz::PortraitHelper::getUserPortraitMovie(Biz::Session::getAccountManager()->accountData().UserID()));
    }
}

void UserProfileWidget::onUserMoodInforChange( const QString& userid, const QString& moodinfo )
{
	if (Biz::MessageUtil::compareUserId(mJid,userid))
	{

		ui->leBoom->setText(moodinfo);
	}
}

void UserProfileWidget::ShowWidget()
{
#ifdef QCHAT
	ui->btnBasic->setVisible(false);
	//ui->infopanel->setVisible(false);
	showzl();
#endif // QCHAT

}

void UserProfileWidget::showzl()
{
#ifdef QCHAT
	ui->id->setVisible(false);
	ui->lbLeader->setVisible(false);
	ui->lbLeaderLink->setVisible(false);
	ui->lbMobile->setVisible(false);
	ui->lbMobileLink->setVisible(false);
	ui->lbBoom->setVisible(false);
	ui->leBoom->setVisible(false);
#endif // QCHAT
}

void UserProfileWidget::onUserPortraitUpdate( const QString& userid )
{
	if (userid != mJid)
	{
		return;
	}
	showAvatar();
	
	setSex(userid);
}

void UserProfileWidget::showAvatar()
{
	QString strAvatarPath = Biz::PortraitHelper::getUserPortraitPath(mJid);
	if (!QFile::exists(strAvatarPath))
	{
		return;
	}
	if (NULL != m_GifPlayer)
	{
		m_GifPlayer->deleteLater();
	}
	m_GifPlayer = new QMovie();
	m_GifPlayer->setFileName(strAvatarPath);
	int nCount = m_GifPlayer->frameCount();
	if (nCount > 0)
	{
		connect(m_GifPlayer,&QMovie::frameChanged,[this,nCount](int frameNumber){
			QPixmap pixmap = m_GifPlayer->currentPixmap();

			ui->btnAvatar->setPixmap(pixmap.scaled(ui->btnAvatar->size()));
		});
		m_GifPlayer->start();
	}
	else
	{
		QPixmap header = Biz::PortraitHelper::getUserPortraitWithoutDownload(Biz::MessageUtil::makeSureUserId(mJid), ui->btnAvatar->sizeHint().width());
		ui->btnAvatar->setPixmap(header);
	}
}

void UserProfileWidget::setSex( const QString&userid )
{
	QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userid);
	if (!spPerson.isNull())
	{
		ui->sex->setVisible(true);
		QPixmap sexmap;
		if (spPerson->sex == 1)
		{
			sexmap.load(":/Images/icon/sex_man.png");
		}
		else
		{
			sexmap.load(":/Images/icon/sex_woman.png");
		}

		ui->sex->setPixmap(sexmap.scaled(ui->sex->size()));
	}
}

void UserProfileWidget::onClose( bool bret )
{
	if (m_GifPlayer != NULL)
	{
		m_GifPlayer->setFileName("");
		m_GifPlayer->stop();
	}
	LocalManDialog::onMin(bret);
}
