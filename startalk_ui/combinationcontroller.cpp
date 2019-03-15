#include "combinationcontroller.h"
#include "rostertreeview.h"
#include "SystemDefine.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "friendscontroller.h"
#include "MultiDialogContainer.h"
#include "GroupListView.h"
#include "GroupManager.h"
#include "FriendsExtendPanel.h"
#include "addfriendanswer.h"
#include "userminiprofile.h"
#include "NotifyCenterController.h"
#include "ExtendedSessionListView.h"
#include "slidingstackedwidget.h"
#include "combinationlistview.h"
#include "RobotManager.h"
#include "publicaccountlistview.h"
#include "blacknamelistview.h"
#include "accountmanager.h"
#include "UserVcardManager.h"
#include "loginmanager.h"
#include "jsonobject/wechatuserlist.h"
#include "portraithelper.h"
#include "wechatuserlist.h"
#include "staffmanager.h"

namespace MainApp
{
    const QString  CombinationController::sDefaultCombinationExtendPanel = "6f69e0fbb9ea43eab045873558ca9966";

    CombinationController::CombinationController(QObject *parent)
        : ControllerBase(parent)
        ,m_pContainer(NULL)
        ,m_pAllstaffTreeView(NULL)
        , m_pExtendedSessionListView(NULL)
    {

    }

    CombinationController::CombinationController()
        :ControllerBase(NULL)
        ,m_pContainer(NULL)
        ,m_pAllstaffTreeView(NULL)
        , m_pExtendedSessionListView(NULL)

    {

    }

    CombinationController::~CombinationController()
    {

    }

    void CombinationController::initController()
    {
        connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginStatusChange,this,&CombinationController::onLoginStatusChange);
    }

    void CombinationController::unInitController()
    {

    }

    void CombinationController::registCombinationContainer( MultiDialogContainer* pChatsContainer )
    {
        this->m_pContainer = pChatsContainer;
        createCombinationItems();
        connect(UserMiniProfile::getInstance(), &UserMiniProfile::sgChatDialog, this, &CombinationController::onChatDialog);
		
    }

	void CombinationController::initRosterTreeConnect(const RosterTreeView*prostertree)
    {

        if (NULL == prostertree)
        {
            return;
        }
        RosterTreeView *rostertree = (RosterTreeView*)prostertree;

		rostertree->setExpandsOnDoubleClick(false);

		connect(&Biz::Session::currentAccount(), &Biz::Account::sgRosterListChanged, rostertree, &RosterTreeView::onRosterListChanged );


		connect(rostertree, &RosterTreeView::sgChatDialog, this, &CombinationController::onChatDialog);


		connect(m_pContainer,&MultiDialogContainer::sgTracertUser,[this,rostertree](const QString& userid){
			emit sgCombinationbtn();
			RosterTreeView* treeview = rostertree;
			treeview->onTraceItem(userid);
			onCombinationItemClicked( Util::OrganizationId );
		});

		//connect(item->btn,&QPushButton::clicked,mRecentChatMultiDialog.data(),&MultiDialogContainer::onJiagouTabShow);
		connect(rostertree, &RosterTreeView::sgGroupAttached,m_pContainer,&MultiDialogContainer::onJiagouGroupAttached);
		connect(rostertree, &RosterTreeView::sgUserAttached,m_pContainer,&MultiDialogContainer::onJiagouUserAttached);

		connect(&Biz::Session::currentAccount(), &Biz::Account::sgCleanData,[this,rostertree](){
			RosterTreeView* treeview = rostertree;

			treeview->oncleanData();
		});

    }

	void CombinationController::onChatDialog( const QString& userID, const QString& displayName )
	{
		//发送信号，展示最近会话列表
		emit sgchatsbtn();
		QString conversationId = Biz::MessageUtil::makeSureUserJid(userID);
		// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
		UIFrame::getConversationController()->createNewChatDialog(conversationId);
		UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
		UIFrame::getConversationController()->activeConversation(conversationId);
		UIFrame::getConversationController()->moveSessionToTop(userID);
	}

    void CombinationController::onGroupChatDialog( const QString& groupJid, const QString& displayName, bool autoJoin )
    {
		//发送信号，展示最近会话列表
		emit sgchatsbtn();
		MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupJid);
		MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupJid,MainApp::ConversationController::sDefaultExtendPanel);
		MainApp::UIFrame::getConversationController()->activeConversation(groupJid);
		MainApp::UIFrame::getConversationController()->moveSessionToTop(groupJid);
	}

	

    void CombinationController::onCombinationItemClicked( const QString&id )
    {
        if (m_id2CombinnationForwardAction.contains (id))
        {
            m_id2CombinnationForwardAction.value (id)();
        }
    }

    void CombinationController::createCombinationItems()
    {

        CombinationExtendedSessionListView* pDefaultCombinationExtendView = new CombinationExtendedSessionListView(m_pContainer->getCombinationExtendPanelStacked());
        pDefaultCombinationExtendView->setLindedId(sDefaultCombinationExtendPanel);

        m_pExtendedSessionListView = pDefaultCombinationExtendView;

        m_pContainer->getCombinationExtendPanelStacked()->addWidget(pDefaultCombinationExtendView);
        m_pContainer->getCombinationExtendPanelStacked()->setCurrentWidget(pDefaultCombinationExtendView);

        connect(pDefaultCombinationExtendView->getCombinationListView(), &CombinationListView::sgcombinationItemClicked, this, &CombinationController::onCombinationItemClicked);

		//星标联系人
		addCombinationOfStarPersonItem(Util::StarPersonId, Util::StarPersonName, pDefaultCombinationExtendView);
        
		//群组
        addCombinationOfGroupItem(Util::GroupsId, Util::GroupsName, pDefaultCombinationExtendView);

        //组织架构
        addCombinationOfOrganizaItem(Util::OrganizationId, Util::OrganizationName, pDefaultCombinationExtendView);


        //好友
        addCombinationOfFriendItem(Util::FriendsId, Util::FriendsName, pDefaultCombinationExtendView);

        //公众号
        addCombinationOfGzhItem(Util::SUBSCRIPTIONNUM_ID, Util::strGzh, pDefaultCombinationExtendView);

        //黑名单
        addCombinationOfBlackItem(Util::BlackFriendsId, Util::BlackFriendsName, pDefaultCombinationExtendView);

#ifndef QCHAT

		// 工作区
		addCombinationOfWorkplace (Util::WorkPlaceId, Util::WorkPlaceName, pDefaultCombinationExtendView);

	//	addCombinationOfPasswordBox(Util::PassWordBoxId, Util::PassWordBoxName, pDefaultCombinationExtendView);

#endif // !QCHAT

        //记事本
		//addCombinationOfNoteInfo(Util::NoteInforId, Util::NoteInforName, pDefaultCombinationExtendView);

    }


	//   添加星标联系人
	void CombinationController::addCombinationOfStarPersonItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView)
	{
		if ( extendid.isEmpty() || NULL == belongView)
			return;
		CombinationOfStarPersonExtendedListView* pStarPersonExtendView = new CombinationOfStarPersonExtendedListView(m_pContainer);
		addCombinationExtendItem(extendid,extendPannelTitle,pStarPersonExtendView,belongView);
	}

	void CombinationController::addCombinationOfGroupItem( const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView)
    {

        if (extendid.isEmpty() || NULL==belongView)
            return;

        CombinationOfGroupExtendedListView* pGroupExtendView = new CombinationOfGroupExtendedListView(m_pContainer);
        addCombinationExtendItem(extendid,extendPannelTitle,pGroupExtendView,belongView);
    }

    void CombinationController::addCombinationOfOrganizaItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView )
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;

        // 先创建一个扇出对象
        CombinationOfOrganiExtendedListView* pExtendView = new CombinationOfOrganiExtendedListView(m_pContainer);
        m_pAllstaffTreeView = pExtendView->getCombinationListView ();
        initRosterTreeConnect(pExtendView->getCombinationListView());
        addCombinationExtendItem(extendid,extendPannelTitle,pExtendView,belongView);
    }

    void CombinationController::addCombinationOfFriendItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView)
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;
        CombinationOfFriendExtendedListView* pExtendView = new CombinationOfFriendExtendedListView(m_pContainer);
        addCombinationExtendItem(extendid,extendPannelTitle,pExtendView,belongView);
    }

    void CombinationController::addCombinationOfGzhItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView)
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;

        // 先创建一个扇出对象
        CombinationOfPublicAccountExtendedListView* pExtendView = new CombinationOfPublicAccountExtendedListView(m_pContainer);
        addCombinationExtendItem(extendid,extendPannelTitle,pExtendView,belongView);
    }

    void CombinationController::addCombinationOfBlackItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView)
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;

        // 先创建一个扇出对象
        CombinationOfBlackNameExtendedListView* pExtendView = new CombinationOfBlackNameExtendedListView(m_pContainer);
        addCombinationExtendItem(extendid,extendPannelTitle,pExtendView,belongView);
    }

    void CombinationController::ongroupItemclick()
    {
        m_pContainer->showEmptyChatdialog();
    }



    void CombinationController::onPublicAccountItemClicked( const QString&id )
    {
        m_pContainer->showEmptyChatdialog();
    }





    void CombinationController::addCombinationOfWorkplace(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView)
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;

        belongView->getCombinationListView()->addOneItem(extendid,extendPannelTitel);
        belongView->getCombinationListView ()->setItemExtendable (extendid,false);
		//belongView->getCombinationListView()->setItemUnReadIconable(extendid, true);
		

        m_id2CombinnationForwardAction.insert (extendid,[this]{
            // jump to empty page
			Biz::Session::getStaffManager()->getUserWorkspaceWaitCount();
            m_pContainer->showWorkPlaceWidget ();
        });
    }

    void CombinationController::addCombinationExtendItem(const QString& extendid,const QString& extendPannelTitle,ExtendedSessionListView* pExtendView,CombinationExtendedSessionListView* belongWidget)
    {
        QString belongId = belongWidget->getLindedId ();
        m_pContainer->getCombinationExtendPanelStacked()->addWidget(pExtendView);
        pExtendView->setBelongExtendid(belongId);
        pExtendView->setLindedId(extendid);
        pExtendView->setExtendTitleVisable(true);
        pExtendView->setExtendTitle(extendPannelTitle);
        m_id2CombinnationForwardAction.insert (extendid,[this,pExtendView, extendid]{
            if (m_pContainer->getCombinationExtendPanelStacked()->currentWidget()!=pExtendView)
            {
				//这地方也需要区分一下是点击的群还是其他的item
				if (extendid == Util::GroupsId)
				{
					//这地方调用一下，拉取全量的群列表
					auto callback = createCallback<QStringList>([this, pExtendView](const QStringList& list){

						m_pContainer->getCombinationExtendPanelStacked()->slideInWidget(pExtendView, SlidingStackedWidget::RIGHT2LEFT);
						m_pContainer->showEmptyChatdialog();

					},[]{});

					Biz::Session::getGroupManager()->getJoinedRoomListOnLogin(callback);
				}
				else
				{
					m_pContainer->getCombinationExtendPanelStacked()->slideInWidget(pExtendView, SlidingStackedWidget::RIGHT2LEFT);
					m_pContainer->showEmptyChatdialog();
				}

				
               
            }
        });

        connect(pExtendView, &ExtendedSessionListView::sgBackButtonClicked,[this,belongWidget]{
            m_pContainer->getCombinationExtendPanelStacked()->slideInWidget(belongWidget, SlidingStackedWidget::LEFT2RIGHT);
        } );

        belongWidget->getCombinationListView()->addOneItem(extendid,extendPannelTitle);
    }

	void CombinationController::addCombinationOfWechats(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView)
    {
        if (extendid.isEmpty() || NULL==belongView)
            return;
        CombinationOfFriendExtendedListView* pExtendView = new CombinationOfFriendExtendedListView(m_pContainer);
        addCombinationExtendItem(extendid,extendPannelTitel,pExtendView,belongView);
    }

    void CombinationController::onLoginStatusChange(int oldstatus,int newstatus)
    {
        MainApp::UIFrame::getFriendsController ()->getFriendsListView ()->clearAll ();

        if (NULL!=m_pExtendedSessionListView)
        {
            if (newstatus == Biz::LoginStatus_Connect)
            {
#ifdef QCHAT
				auto callback = createCallback<QSharedPointer<Biz::WechatUserListParam>>([this](const QSharedPointer<Biz::WechatUserListParam>& wechatUserListParam){

					if (NULL!=m_pExtendedSessionListView && !wechatUserListParam.isNull ())
					{
						for (IJsonSerializeable* pPackage : wechatUserListParam->wechatlist())
						{
							Biz::WechatUserPackage* wechatPackage = (Biz::WechatUserPackage*)pPackage;
							if (!wechatPackage->packageid ().isEmpty())
							{
								CombinationOfWechatsExtendedListView* pExtendView = new CombinationOfWechatsExtendedListView(m_pContainer);

								for (IJsonSerializeable* puser : wechatPackage->users ())
								{
									Biz::WechatUser* user = (Biz::WechatUser*)puser;
									if(!user->id ().isEmpty())
									{
										WechatUserListView* wechatList = pExtendView->getCombinationListView ();
										wechatList->setWechatUserInfo (user);

										QString userjid = Biz::MessageUtil::makeSureUserJid (user->id ());
										QString strdisply = user->name ();
										QSharedPointer<Biz::ImSelfPerson> spPerson(new Biz::ImSelfPerson);
										spPerson->strUserId = userjid;
										spPerson->strNickName = strdisply;
										spPerson->nUserType = Biz::ImSelfPerson::UserSaveType::UserSaveType_Local;
										Biz::Session::getUserVcardManager()->addUserVcard(spPerson,false);
									}
								}
								addCombinationExtendItem(wechatPackage->packageid (),wechatPackage->packageid (),pExtendView,m_pExtendedSessionListView);
								m_pExtendedSessionListView->getCombinationListView ()->setItemImage (wechatPackage->packageid (),Biz::PortraitHelper::loadCombinationImage (wechatPackage->packageid (),":/Images/icon/extendicon/wechat.png"));
								connect (pExtendView->getCombinationListView (),&PinnedListView::sgItemDoubleClicked,[pExtendView](const QString& userID){
									QString conversationId = Biz::MessageUtil::makeSureUserJid(userID);

									// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
									UIFrame::getConversationController()->createNewChatDialog(conversationId);
									UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
									UIFrame::getConversationController()->activeConversation(conversationId);
									UIFrame::getConversationController()->moveSessionToTop(conversationId);

									WechatUserListView* wechatList = pExtendView->getCombinationListView ();
									if (NULL!=wechatList)
									{
										QString channelID = wechatList->getChannelId (conversationId);
										QJsonParseError Json_Parse_Error;
										QJsonDocument Json_Data = QJsonDocument::fromJson(channelID.toUtf8(),&Json_Parse_Error);
										if(Json_Parse_Error.error == QJsonParseError::NoError)
										{
											QJsonObject object  =  QJsonObject::fromVariantMap (Json_Data.toVariant().toMap());
											object.insert ("d",QString("send"));
											channelID = QJsonDocument(object).toJson (QJsonDocument::Compact);
											UIFrame::getConversationController ()->updateConversationChannelId(conversationId,channelID);
										}
									}
								});
							}
						}
					}

				},[]{});

				Biz::Session::getFriendManager ()->getWechatUserList (callback);
#endif // QCHAT      
            }
        }
    }

	void CombinationController::hideCombinationContainerOfOrganizaItem()
	{
		//CombinationExtendedSessionListView* pDefaultCombinationExtendView = new CombinationExtendedSessionListView(m_pContainer->getCombinationExtendPanelStacked());
		 if(m_pExtendedSessionListView)
		 {

			m_pExtendedSessionListView->getCombinationListView()->deleteOneItem(Util::OrganizationId, Util::OrganizationName);
			 
		 }
	}


	void CombinationController::createCombinationItemOfPwd()
	{
		addCombinationOfPasswordBox(Util::PassWordBoxId, Util::PassWordBoxName, m_pExtendedSessionListView);
	}

	void CombinationController::addCombinationOfPasswordBox( const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView )
	{
		if (extendid.isEmpty() || NULL==belongView)
			return;

		belongView->getCombinationListView()->addOneItem(extendid,extendPannelTitel);
		belongView->getCombinationListView ()->setItemExtendable (extendid,false);
		


		m_id2CombinnationForwardAction.insert (extendid,[this]{
			// jump to empty page
			
			m_pContainer->showEmptyChatdialog();
		});
	}

	void CombinationController::addCombinationOfNoteInfo( const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView )
	{
		if (extendid.isEmpty() || NULL==belongView)
			return;

		belongView->getCombinationListView()->addOneItem(extendid,extendPannelTitel);
		belongView->getCombinationListView ()->setItemExtendable (extendid,false);
		


		m_id2CombinnationForwardAction.insert (extendid,[this]{
			// jump to empty page
			m_pContainer->showNoteInfor ();
		});
	}


}

