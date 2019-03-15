#include "group_setting.h"
#include "ui_group_setting.h"
#include "GroupListData.h"
#include "UiHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "GroupListData.h"
#include "portraithelper.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "../QXmpp/QXmppRoomNegative.h"

#include "GroupManager.h"
#ifdef _WINDOWS
#include "QZXing.h"
#else 
#include "../modules/QZxing/QZXing.h"
#endif // _WINDOWS

#include "diywidgit/customviews/qframelayout.h"

#include "conversationmanager.h"
#include "UserVcardManager.h"
#include "ercodedialog.h"
GroupSettingDialog::GroupSettingDialog(QWidget* parent)
    : LocalManDialog(parent)
    , ui(new Ui::GroupSetting()),lastGroupName("")
{
    ui->setupUi(this); 

    using namespace Qt;
    auto remove = WindowTitleHint;
	// WindowStaysOnTopHint add by wangchao // 子窗口默认显示在父窗口上
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    

    ui->titlebarWidget->setSizeable(false);

    ui->gsubject->installEventFilter(this);
	ui->gname->installEventFilter(this);
	mCallbackReceiver = new Biz::CallbackReceiver(this);

	ui->ok_change->setEnabled(false);
	connect(ui->gname, &QLineEdit::textChanged,[this](const QString& text){

		ui->ok_change->setEnabled(true);
	});

	connect(ui->ok_change, &QPushButton::clicked, this, &GroupSettingDialog::onClickedOkChange);

    QFrameLayout* pRootLayout = new QFrameLayout(ui->bks);
    pRootLayout->appendWidget(ui->bg1,ALINE_FILL,QMargins(0,27,0,0));
    pRootLayout->appendWidget(ui->navbar,ALINE_MATCHWIDTH|ALINE_TOP,QMargins(0,27,0,0));
    pRootLayout->appendWidget(ui->titlebarWidget,ALINE_MATCHWIDTH|ALINE_TOP);
	ui->avatar->setFocus();

	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,this,&GroupSettingDialog::updateAvatarGroupHeader);

	ui->avatar->installEventFilter(this);
	ui->avatar->setCursor(QCursor(Qt::PointingHandCursor));
	ui->avatar->setToolTip(QStringLiteral("点击显示二维码"));


	
}

GroupSettingDialog::~GroupSettingDialog()
{
}

void GroupSettingDialog::initUi()
{

	connect(ui->cancle ,&QPushButton::clicked,this,&GroupSettingDialog::onCancle);
	connect(ui->exit ,&QPushButton::clicked,this,&GroupSettingDialog::onQuitGroup);
	connect(ui->baseinfo,&QPushButton::clicked,this,&GroupSettingDialog::onTab );
	connect(ui->list,&QPushButton::clicked,this,&GroupSettingDialog::onTab );

	connect(ui->titlebarWidget, &TitlebarWidget::sgMinOnClicked, this, &GroupSettingDialog::onCancle);
	connect(ui->titlebarWidget, &TitlebarWidget::sgCloseOnClicked, this, &GroupSettingDialog::onQuit);


	connect(ui->pushButton,&QPushButton::clicked,this,&GroupSettingDialog::onModifySubject);
	connect(ui->distroy,&QPushButton::clicked,this,&GroupSettingDialog::onDestroyGroup);
	// 默认第一个
    ui->baseinfo->click(); 
    /*ui->setting->hide();*/



}

void GroupSettingDialog::onQuit(bool b)
{
    this->close();
}
void GroupSettingDialog::onQuitGroup()
{
    if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (QStringLiteral("退出群之后将无法接收群消息，是否退出？")))
    {
        return;
    }

	Biz::Session::getGroupManager()->leaveGroup(ui->gid->text()); 
	this->close();
}

void GroupSettingDialog::updateAvatarGroupHeader( const QString& groupjid )
{
	if (groupjid != ui->gid->text())
	{
		return;
	}
	ui->avatar->setScaledContents(true);
	
	QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(groupjid);

	ui->avatar->setPixmap(pixmap);

// 	ui->avatar->setScaledContents(true);
// 	QString groupIdRcode = QString("qtalk://group?id=")+groupjid;
// 	QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(groupjid);
// 
// 	QPixmap rcodePixmap = QZXing::encodeString(groupIdRcode,pixmap);
// 
// 	ui->avatar->setPixmap(rcodePixmap);

}

//群名称的修改
void GroupSettingDialog::onClickedOkChange()
{
	QString jid = ui->gid->text();
	QString groupname = ui->gname->text();
	if (groupname.compare(lastGroupName,Qt::CaseInsensitive)!=0)
	{
		Biz::GroupListData* gld  = Biz::Session::currentAccount().getGroupsData();
		Biz::GroupSetting* setting = gld->getGroupSetting(jid);
		setting->Name(ui->gname->text());
		//Biz::Session::currentAccount().updateMucVcard();
        Biz::Session::currentAccount().setUpdateMucVCard(jid, setting->Name(), setting->Subjuct(), NULL);
	}
	Biz::Session::currentAccount().saveGroupListData();
	lastGroupName = groupname;
}

void GroupSettingDialog::onCancle(bool b)
{
    this->close();
}

void GroupSettingDialog::onTab(bool b){
    QPushButton* s = (QPushButton*)sender();
    ui->baseinfo->setChecked(s==ui->baseinfo);
    ui->list->setChecked(s==ui->list);

    int curr = ui->stackedWidget->currentIndex();
    curr = s==ui->baseinfo?0:curr;
    curr = s==ui->list?1:curr;
    ui->stackedWidget->setCurrentIndex(curr);
}

void GroupSettingDialog::setupData(const QString& jid)
{
    disconnect(ui->cancle ,&QPushButton::clicked,this,&GroupSettingDialog::onQuit);
	disconnect(ui->exit ,&QPushButton::clicked,this,&GroupSettingDialog::onQuitGroup);
    disconnect(ui->baseinfo,&QPushButton::clicked,this,&GroupSettingDialog::onTab );
    disconnect(ui->list,&QPushButton::clicked,this,&GroupSettingDialog::onTab );

    disconnect(ui->titlebarWidget, &TitlebarWidget::sgMinOnClicked, this, &GroupSettingDialog::onCancle);
    disconnect(ui->titlebarWidget, &TitlebarWidget::sgCloseOnClicked, this, &GroupSettingDialog::onQuit);

   
    disconnect(ui->pushButton,&QPushButton::clicked,this,&GroupSettingDialog::onModifySubject);
    disconnect(ui->distroy,&QPushButton::clicked,this,&GroupSettingDialog::onDestroyGroup);
    disconnect(this,0,0,0);

    // 开辟存储位置
    QString gjid = ui->gid->text();
    Biz::GroupListData* gld  = Biz::Session::currentAccount().getGroupsData();
    Biz::GroupSetting* setting = gld->getGroupSetting(jid);
    setupData(setting);
}


void GroupSettingDialog::setupData(const Biz::GroupSetting* const data)
{
    // ----------------- page1 ----------------------
    ui->avatar->setScaledContents(true);
   // QString groupIdRcode = QString("qtalk://group?id=")+data->GroupJid();
    QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(data->GroupJid());

   // QPixmap rcodePixmap = QZXing::encodeString(groupIdRcode,pixmap);
	
    ui->avatar->setPixmap(pixmap);

    ui->gname->setText(data->Name());
	ui->ok_change->setEnabled(false);

    ui->gsubject->setText(data->Subjuct()); lastGSubject = data->Subjuct();
    ui->gid->setText(data->GroupJid());
	ui->gid->setToolTip(data->GroupJid());
    //bool bAutoJoin = Biz::Session::currentAccount().FindGroupJoin(data->GroupJid());
    ui->autojoin->setChecked(false);

    QString nickname = Biz::Session::currentAccount().accountData().FullName();
    ui->nickname->setText(nickname);

    // ----------------- page3 可见 ------------------
    int p = data->Priority();
    // v3 群组没有了设置页
    if(/*QXmppRoomNegative::Action::ConfigurationAction == (QXmppRoomNegative::Action::ConfigurationAction&p)*/false){
        setOption(DSO_ALL);
    } else {
        setOption(DSO_SHORT);
    }

    // ----------------- page3 ----------------------
 
	lastGroupName = data->Name();
   
}



//群公告的修改
void GroupSettingDialog::onModifySubject(bool b)
{
    QString jid = ui->gid->text();
    QString subject = ui->gsubject->toPlainText();
    if (lastGSubject.compare(subject,Qt::CaseInsensitive)!=0)
    {
        // Biz::Session::currentAccount().setSubject(jid,subject);

		Biz::GroupListData* gld  = Biz::Session::currentAccount().getGroupsData();
		Biz::GroupSetting* setting = gld->getGroupSetting(jid);

        auto cb = mCallbackReceiver->createCallback<QString>([this, subject, jid, setting](QString groupname)
        {
			//返回成功，就往本地缓存文件中写数据
// 			setting->Subjuct(subject);
// 			lastGSubject = subject;
// 			if (setting->isDataChanged())
// 			{
// 				Biz::Session::currentAccount().saveGroupListData();
// 			}

        },[](){});

        Biz::Session::currentAccount().setUpdateMucVCard(jid, setting->Name(), subject, cb);

    }    
  
}


void GroupSettingDialog::setOption(DSOption op)
{
   
    ui->list->hide();
}

void GroupSettingDialog::setGroupCreator( const QString&creatorid )
{
	mGroupCreatorId = creatorid;
}

void GroupSettingDialog::mousePressEvent(QMouseEvent * e)
{
    QPoint p = e->pos();

    if ( ui->gsubject->hasFocus() && !ui->gsubject->rect().contains(p) )
    {
        ui->gsubject->clearFocus();
    }

    LocalManDialog::mousePressEvent(e);
}


bool GroupSettingDialog::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::FocusOut)
    {
        if (o == ui->gsubject)
        {
            onModifySubject(false);
        }
    
		if (o == ui->gname)
		{
			QString jid = ui->gid->text();
			QString groupname = ui->gname->text();
			if (groupname.compare(lastGroupName,Qt::CaseInsensitive)!=0)
			{
				Biz::GroupListData* gld  = Biz::Session::currentAccount().getGroupsData();
				Biz::GroupSetting* setting = gld->getGroupSetting(jid);
				setting->Name(ui->gname->text());
				//Biz::Session::currentAccount().updateMucVcard();
				Biz::Session::currentAccount().setUpdateMucVCard(jid, setting->Name(), setting->Subjuct(), NULL);
                if (setting->isDataChanged())
                {
                    Biz::Session::currentAccount().saveGroupListData();
                }
			}
			lastGroupName = groupname;
		}
    }


	if (o == ui->avatar)
	{
		if (e->type() == QEvent::MouseButtonDblClick
			|| e->type() == QEvent::MouseButtonPress)
		{
			onErCodeShow();
		}
	}

    return LocalManDialog::eventFilter(o,e);
}

void GroupSettingDialog::onErCodeShow()
{
	QString groupjid = ui->gid->text();
	ui->avatar->setScaledContents(true);
	QString groupIdRcode = QString("qtalk://group?id=")+groupjid;
	QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(groupjid);

	QPixmap rcodePixmap = QZXing::encodeString(groupIdRcode,pixmap);
	ErCodeDialog *code = ErCodeDialog::getInstance(this);
	code->setErCodePixmap(rcodePixmap);

	
}

GroupSettingDialog* GroupSettingDialog::instance = NULL;
GroupSettingDialog* GroupSettingDialog::getInstance()
{
    if (instance==NULL)
    {
        instance = new GroupSettingDialog(NULL);
        instance->setWindowTitle(QStringLiteral("群设置"));
        //instance->setModal(true);
    }
    return instance;
}

void GroupSettingDialog::onDestroyGroup(bool)
{
	showNormal();
	activateWindow();
	QString strDisplay = ui->gname->text();
	QString strTitleInfor = QStringLiteral("你确定要销毁群[%1]？").arg(strDisplay);
	if (!mGroupCreatorId.isEmpty() && !Biz::MessageUtil::compareUserId(mGroupCreatorId, Biz::Session::currentAccount().accountData().UserID()))
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("非群主，无法销毁群"));
		return;
	}
	if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",strTitleInfor,QStringLiteral("取消"),QStringLiteral("确定")))
	{
		QString gjid = ui->gid->text();
		Biz::Session::getGroupManager()->destroyGroup(gjid);
		Biz::Session::getConverSationManager()->removeChartingImSession(gjid);
		this->close();
	}
	else
	{
		showNormal();
		activateWindow();
	}

    
}




