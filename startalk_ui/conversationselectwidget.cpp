#include "conversationselectwidget.h"

#include "ui_conversationselectwidget.h"

#include "diywidgit/customviews/qframelayout.h"
#include "conversationlistwidget.h"
#include "Session.h"
#include "conversationmanager.h"
#include "RosterList.h"
#include "Account.h"
#include "SettingData.h"
#include <QtWidgets/QApplication>

#include <QDesktopWidget>


ConversationSelectWidget::ConversationSelectWidget(QWidget *parent)
    : QIMLogicDialog(parent)
	, m_pSearchUserListWidget(NULL)
{
    ui = new Ui::ConversationSelectWidget();
    ui->setupUi(this);

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

    setWindowTitle(QStringLiteral("选择会话"));


    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    titlebar->setMinable(false);
    titlebar->setMaxable(false);
    titlebar->setLeftTitle(QStringLiteral("选择会话"));

    connect(titlebar, &TitlebarWidget::sgMinOnClicked, [this]{this->setResult(0);this->close();});
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, [this]{this->setResult(0);this->close();});


	m_pSearchUserListWidget = new SearchUserListWidget();
	m_pSearchUserListWidget->setParent(this);
	m_pSearchUserListWidget->hide();
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgItemSelected, this, &ConversationSelectWidget::onSearchChatResult);
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgGroupSelected, this, &ConversationSelectWidget::onSearchGroupResult);


    m_conversationListWidget = new ConversationListWidget(ui->contentview);
    connect(m_conversationListWidget,&ConversationListWidget::conversationClicked,[this](const QString& conversationid){
        m_selectedConversationId = conversationid;
        this->setResult(0);
        this->close();
		
    });

    QFrameLayout* pContentFrame = new QFrameLayout(ui->contentview);
    pContentFrame->appendWidget(m_conversationListWidget,ALINE_FILL);
	pContentFrame->appendWidget(m_pSearchUserListWidget,AlinementPolicy::ALINE_TOPLEFT,QMargins(0,0,0,0));
    connect(ui->searchEdit, &QLineEdit::textChanged, this, &ConversationSelectWidget::onSearchEditInputChange);
	
}

ConversationSelectWidget::~ConversationSelectWidget()
{

}

void ConversationSelectWidget::setConversationDataList()
{
    m_conversationListWidget->clearData();

    m_selectedConversationId = "";

    auto getListSuccess = [this](const QList<Biz::ImSession>& imsessions){
    for(Biz::ImSession imSession:imsessions)
    {
        QString conversationId = imSession.xmppid;
        if (m_exceptConversationIds.contains(conversationId))
        {
            continue;
        }
        if (Biz::ChatMessage == imSession.chatType)
        {
#ifdef QCHAT     //这是为了兼容之前的问题
            if (Biz::MessageUtil::compareUserId("rbt-system",imSession.xmppid) 
                || Biz::MessageUtil::compareUserId("rbt-notice",imSession.xmppid) )
                continue;
#endif // QCHAT
            // 二人
            
            m_conversationListWidget->addChatDialog(conversationId);
            m_conversationListWidget->updateConversationLastTimeStamp(conversationId,imSession.lastupdateTime);
        }
        else if (Biz::GroupMessage == imSession.chatType)
        {
            // 群组
            m_conversationListWidget->addGroupChatDialog(conversationId);
            m_conversationListWidget->updateConversationLastTimeStamp(conversationId,imSession.lastupdateTime);
        } 
    }

	//拿取最后一条消息
	Biz::Session::getConverSationManager()->getChatingSessionsLastMsg();
    };

    auto getListfail = []{};
    Biz::UnitCallback<QList<Biz::ImSession>>* callback = 
        m_callbackReceiver->createCallback<QList<Biz::ImSession>>(getListSuccess,getListfail);
    Biz::Session::getConverSationManager()->getChatingSessionsWithCallback(callback);
}

void ConversationSelectWidget::onSearchEditInputChange( const QString&inputkey )
{
	if (inputkey.length() <=0)
	{
		m_pSearchUserListWidget->hide();
		return ;
	}

	auto searchUserFunc = [this,inputkey]{
		auto callback = m_callbackReceiver->createCallback<QList<Biz::SearchResulteItemGroupModule>>(
			[this,inputkey](const QList<Biz::SearchResulteItemGroupModule>& results){
				m_pSearchUserListWidget->setSearchKey(inputkey);
				m_pSearchUserListWidget->setListData(results);

				ui->searchEdit->activateWindow();
				ui->searchEdit->setFocus();        

		},[]{});

		Biz::Session::getConverSationManager()->searchUserInGlobal(inputkey,callback);
	};


	if (inputkey.length()<3) 
	{
		QTimeLine* pTimeLine = new QTimeLine(300);
		connect(pTimeLine,&QTimeLine::finished,[this,inputkey,pTimeLine,searchUserFunc]{
			pTimeLine->deleteLater();
			QString strCurentText = ui->searchEdit->text();
			if (strCurentText == inputkey)
				searchUserFunc();
		});
		pTimeLine->start();
	}
	else
	{
		searchUserFunc();
	}
	
}

void ConversationSelectWidget::onSearchChatResult( const QString& conversationId )
{
	m_selectedConversationId = conversationId;
	m_pSearchUserListWidget->hide();
	this->setResult(0);
	this->close();

}

void ConversationSelectWidget::onSearchGroupResult( const QString& conversationId )
{
	m_selectedConversationId = conversationId;
	m_pSearchUserListWidget->hide();
	this->setResult(0);
	this->close();
}
