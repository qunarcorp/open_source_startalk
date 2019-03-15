#include "userminiprofile.h"
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QDesktopWidget>
#include "Session.h"
#include "Account.h"
#include "portraithelper.h"
#include "QXmppUtils.h"
#include "gloableeventobject.h"

#include "UserVcardManager.h"

#include "diywidgit/customviews/qframelayout.h"
#include "userprofilewidget.h"
#include "accountmanager.h"
#include <QMovie>
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "UiHelper.h"
#include <QPalette>

UserMiniProfile* UserMiniProfile::sProfileDialog = NULL;

UserMiniProfile::UserMiniProfile(QWidget *parent)
    : QWidget(parent)
	,m_GifPlayer(new QMovie(this))
	,mDefaultpix(Biz::PortraitHelper::getUserPortrait("")) 
{

    ui.setupUi(this);
#ifdef QCHAT
	ui.id_label->setVisible(false);
	ui.jid->setVisible(false);
#endif // QCHAT


    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Window | FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	ui.moodInfo->setText("");

	QFrameLayout* pFLayout = new QFrameLayout(ui.widget_2);
	pFLayout->appendWidget(ui.header,ALINE_FILL);
	pFLayout->appendWidget(ui.namepanel,ALINE_BOTTOM|ALINE_MATCHWIDTH);//,QMargins(12,0,12,0)
	pFLayout->appendWidget(ui.downloadheadpercent, ALINE_VCENTER | ALINE_HCENTER);
	

#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    ui.header->installEventFilter(this);
	ui.webpn->setVisible(true);
	ui.downloadheadpercent->setVisible(false);
    connect(ui.sendmessage,&QPushButton::clicked,[this](bool checked){
        emit sgChatDialog(userId, dispName);
        close();
    });
	connect(ui.addfriend,&QPushButton::clicked, [this](){
		if (Biz::Session::getFriendManager()->isAlreadyFriend(userId))
		{
            MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("%1已经是好友了").arg(userId));
			
			return;
		}

        Biz::Session::getFriendManager()->getUserVerifyMode(userId);
		close();
	});

	connect(ui.pbsetting,&QPushButton::clicked, [this](){
		this->hide();
		UserProfileWidgetSingleton::getInstance()->setUser(userId)->showNormal();
		UserProfileWidgetSingleton::getInstance()->showzl();
		UserProfileWidgetSingleton::getInstance()->activateWindow();
		
	});

	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgHDPortraitUpdate,this,&UserMiniProfile::onHDPortraitUpdate);
	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgUserMoodInforChanged,this,&UserMiniProfile::onUserMoodInforChange);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgdownloadProgress, this, &UserMiniProfile::onPictureDownloadProgressDisplay );
	

	ui.header->setCursor(QCursor(Qt::PointingHandCursor));
	
}

UserMiniProfile::~UserMiniProfile()
{

}

bool UserMiniProfile::eventFilter(QObject *o, QEvent * e)
{
    
    if (this == o && QEvent::WindowActivate == e->type())
    {
        int a = 10;
        a = 20;
    }

	if (o == ui.header)
	{
		if (e->type() == QEvent::MouseButtonDblClick 
			|| e->type() == QEvent::MouseButtonPress)
		{
			this->hide();
			UserProfileWidgetSingleton::getInstance()->setUser(userId)->showNormal();
			UserProfileWidgetSingleton::getInstance()->showzl();
			UserProfileWidgetSingleton::getInstance()->activateWindow();

			return true;
		}
	}
// 	if (o == ui.jid)
// 	{
// 		if (e->type() == QEvent::MouseButtonDblClick 
// 			|| e->type() == QEvent::MouseButtonPress)
// 		{
// 			return false;
// 		}
// 	}

    return QWidget::eventFilter(o, e);

}

UserMiniProfile* UserMiniProfile::getInstance()
{
    if (NULL == sProfileDialog)
    {
        sProfileDialog = new UserMiniProfile(NULL);
    }
    return sProfileDialog;
}

void UserMiniProfile::setUserid(const QString& userid, QString strUserName, QString strEmal)
{
    if (userid.isEmpty())
    {
        return;
    }
	userId = userid;
	mDefaultpix = Biz::PortraitHelper::getUserPortrait(userid);
	ui.header->setPixmap(mDefaultpix.scaled(ui.header->size()));
	
	Biz::Session::getUserVcardManager()->getUserMoodInfobyId(userid);

	
    
	QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userid);
	if (!spPerson.isNull())
	{
		// 个人的id
		ui.jid->setText(spPerson->strUserId);
		ui.jid->setToolTip(spPerson->strUserId);

		ui.nickName->setText(spPerson->strNickName);
		ui.nickName->setToolTip(spPerson->strNickName);

		ui.webname->setText(spPerson->strWebName);
		ui.webname->setToolTip(spPerson->strWebName);

		ui.username->setText(spPerson->strNickName);

		userId = userid;
		dispName = strUserName;
		if (dispName.isEmpty())
		{
			dispName = spPerson->strNickName;
			if (dispName.isEmpty())
			{
				dispName = spPerson->strWebName;
			}
		}

		QString groupName = Biz::Session::currentAccount().getUserGroup(userid);
		if (!groupName.isEmpty())
		{
			ui.path->setText(groupName);
			ui.path->setToolTip(groupName);
		}
		else
		{
			ui.path->setText("");
			ui.path->setToolTip("");
		}
		
		setSex(userid);
	}
    else
    {
		ui.sex->setVisible(false);
        ui.jid->setText(userid);
        ui.jid->setToolTip(userid);

        ui.nickName->setText(Biz::Session::getUserVcardManager()->getUserNameByConversationId(userid));
        ui.nickName->setToolTip(Biz::Session::getUserVcardManager()->getUserNameByConversationId(userid));

        ui.webname->setText("");
        ui.webname->setToolTip("");


        ui.username->setText(Biz::Session::getUserVcardManager()->getUserNameByConversationId(userid));
        QString groupName = Biz::Session::currentAccount().getUserGroup(userid);
        if (!groupName.isEmpty())
        {
            ui.path->setText(groupName);
            ui.path->setToolTip(groupName);
        }
		else
		{
			ui.path->setText("");
			ui.path->setToolTip("");
		}

		
       
    }
	showAvatar();
}

void UserMiniProfile::autoshow()
{
    QPoint pos = QCursor::pos();
    int height=QApplication::desktop()->screenGeometry().bottom(); 

    int h = this->sizeHint().height();
    if (pos.y()+ h  < height)
    {
        this->move(pos);
    }
    else
    {
        this->move(pos.x(),pos.y()-h);
    }
    show();
    activateWindow();
	setFocus();
}

void UserMiniProfile::onHDPortraitUpdate(const QString& userjid)
{
	if (Biz::MessageUtil::compareJid(userjid,userId))
	{
		ui.header->setVisible(true);
		QPixmap pixmap = Biz::PortraitHelper::getUserPortraitWithoutDownload(userjid,ui.header->sizeHint().width());

		showAvatar();

		setSex(userjid);
	}
}

void UserMiniProfile::onUserMoodInforChange( const QString& userid, const QString& moodInfo )
{
	if (Biz::MessageUtil::compareUserId(userid,userId))
	{
		
		ui.moodInfo->setText(moodInfo);
		ui.moodInfo->setToolTip(moodInfo);
	}
}

void UserMiniProfile::hideEvent( QHideEvent * event)
{
	QString strmood = QStringLiteral("这个人很懒，什么都没留下");
	ui.moodInfo->setText(strmood);
	if (m_GifPlayer != NULL)
	{
		m_GifPlayer->setFileName("");
		m_GifPlayer->stop();
	}
	
	ui.header->setPixmap(mDefaultpix.scaled(ui.header->size()));
	ui.header->update();

	return ;
}

void UserMiniProfile::onPictureDownloadProgressDisplay( const QString&userid, const qint64 done, const qint64 total )
{
	if (!Biz::MessageUtil::compareUserId(userid,userId))
	{
		return;
	}
	ui.downloadheadpercent->setVisible(true);
	if (done == total)
	{
		ui.downloadheadpercent->setText(QString("%1%").arg(0));
		ui.downloadheadpercent->setVisible(false);
		ui.header->setVisible(true);
		ui.header->show();
	}
	else
	{
		ui.header->setVisible(false);
		ui.downloadheadpercent->setVisible(true);
		double fdone = 0 ;
		if (total!= 0)
		{
			fdone = (done *100) /total ;
		}

		ui.downloadheadpercent->setText(QString("%1%").arg(fdone));
		ui.downloadheadpercent->setVisible(true);
	}
	
}


void UserMiniProfile::showAvatar()
{
	bool bret;
	QString strAvatarPath = Biz::PortraitHelper::getUserRawPortraitPath(userId, bret);
	if (!QFile::exists(strAvatarPath))
	{
		//如果图片不存在，就用小图片
		QPixmap pixsmall = Biz::PortraitHelper::getUserPortrait(userId);
		ui.header->setPixmap(pixsmall.scaled(ui.header->size()));
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

			ui.header->setPixmap(pixmap.scaled(ui.header->size()));
			ui.header->update();
			ui.header->show();
		});
		m_GifPlayer->start();
	}
	else
	{
		QPixmap header = Biz::PortraitHelper::getUserPortraitWithoutDownload(userId/*Biz::MessageUtil::makeSureUserId(userId)*/, ui.header->sizeHint().width());
		ui.header->setPixmap(header.scaled(ui.header->size()));
	}

}

void UserMiniProfile::setSex(const QString&userid)
{
	//sexmap.load(":/Images/icon/sex_man.png");
	QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userid);
	if (!spPerson.isNull())
	{
		ui.sex->setVisible(true);
		QPixmap sexmap;
		if (spPerson->sex == 1)
		{
			sexmap.load(":/Images/icon/sex_man.png");
		}
		else
		{
			sexmap.load(":/Images/icon/sex_woman.png");
		}

		ui.sex->setPixmap(sexmap.scaled(ui.sex->size()));
	}
}

void UserMiniProfile::showEvent(QShowEvent *event)
{
    //计算网络花名那项是否存在（根据网络花名是否有值）
	showAvatar();
    QString webname = ui.webname->text();
    QSize sizewebpan = ui.webpn->size();
    if (webname.isEmpty())
    {
        ui.webpn->setVisible(false);
        ui.widget_3->setFixedHeight(sizewebpan.height()*3 + +ui.widget_5->height());
       
    }
    else
    {
        ui.webpn->setVisible(true);
        ui.widget_3->setFixedHeight( sizewebpan.height()*4 + +ui.widget_5->height());
    }

    int h1 = ui.widget_2->height();
    int h3 = ui.widget_3->height();

    int fixheight = ui.widget_2->height()+ui.widget_3->height();
    this->setFixedHeight(fixheight);

	//处理Path的问题
	QString strPath = ui.path->text();
	QFont font = ui.path->font();
	
	QString strLimitGroupName = strPath;
	strLimitGroupName=MainApp::getMaxLineCountLimitText(strLimitGroupName, ui.path->width(), 1, ui.path->font());
// 	if (textwidth > 184)
// 	{
// 		QSize sizewebpan = ui.pathpn->size();
// 		//ui.pathpn->setFixedHeight(sizewebpan.height() * 2);
// 		ui.widget_3->setFixedHeight( sizewebpan.height()*4 +ui.widget_5->height());
// 
// 		int fixheight = ui.widget_2->height()+ui.widget_3->height();
// 		this->setFixedHeight(fixheight);
// 
// 		strLimitGroupName=MainApp::getMaxLineCountLimitText(strLimitGroupName, ui.path->width(), 2, ui.path->font());
// 	}
	ui.path->setText(strLimitGroupName);

	QString strmoodinfo = ui.moodInfo->text();
	QString strlimitmoodinfo = MainApp::getMaxLineCountLimitText(strmoodinfo, ui.moodInfo->width(), 1, ui.moodInfo->font());
	ui.moodInfo->setText(strlimitmoodinfo);
	
}


