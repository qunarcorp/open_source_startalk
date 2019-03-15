#include "friendscontroller.h"


#include "Friendslistview.h"

#include "Session.h"
#include "friendsmanager.h"
#include "UserVcardManager.h"
#include "loginmanager.h"
#include "RobotManager.h"

#include "UIFrame.h"
#include "ConversationController.h"
#include "NotifyCenterController.h"

#include "addfriendanswer.h"
#include "blacknamelistview.h"
#include "publicaccountlistview.h"
#include "portraithelper.h"
#include "StarPersonListView.h"

namespace MainApp
{

    FriendsController::FriendsController():ControllerBase(NULL), m_pFriendsList(NULL),m_pBlackNameListView(NULL)
    {
    }

    FriendsController::~FriendsController()
    {
    }

    void FriendsController::initController()
    {
    }

    void FriendsController::unInitController()
    {
    }

    void FriendsController::registFriendsListView(FriendsListView* plistview)
    {
        this->m_pFriendsList = plistview;

        if (plistview == NULL)
            return;

        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgFriendsList ,this, &FriendsController::onFriendListReceived);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgVerifyFriendModeReceive ,this, &FriendsController::onVerifyFriendModeReceive);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgFriendVerifyResultReceive ,this, &FriendsController::onFriendVerifyResultReceive);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgFriendVerifyResultByReceive ,this, &FriendsController::onFriendVerifyResultByReceive);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgFriendVerifyInfoReceive, this, &FriendsController::onFriendVerifyInfoReceive);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgDelFriendRecieve ,this, &FriendsController::onDeleteFriendReceive);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgAllowVerifyFriendReceive, this, &FriendsController::onAllowFriendVerifyResultByReceive);
        connect(m_pFriendsList, &FriendsListView::sgItemDoubleClicked,this,&FriendsController::onOpenNewChatSession);
        connect (m_pFriendsList, &FriendsListView::sgItemClicked,[this](const QString& jid){
            MainApp::UIFrame::getConversationController ()->showFriendDetailInfoPage(jid);
        });
    }

    // 获取到好友的验证模式
    void FriendsController::onVerifyFriendModeReceive( const QString& model, const QString& question, const QString& jid )
    {
        if (model.isEmpty() || jid.isEmpty())
            return;

        int Model = model.toInt();

        do 
        {
            if (Biz::VeryFriendMode::FriendRefuse == Model)
            {
                // 拒绝被加为好友
                MainApp::UIFrame::getNotifyCenterController ()->popupNotice (QStringLiteral("拒绝被任何人加为好友!"));
                break;
            }

            if (Biz::VeryFriendMode::FriendInformation == Model)
            {
                AddFriendAnswer::instance()->showAddFriend (jid,Biz::VeryFriendMode::FriendInformation);
                break;
            }

            if (Biz::VeryFriendMode::FriendQuestAndAnswer == Model)
            {
                AddFriendAnswer::instance()->showAddFriend (jid,Biz::VeryFriendMode::FriendQuestAndAnswer, question);
                break;
            }

            if (Biz::VeryFriendMode::FriendDirectAdd == Model)
            {
                Biz::Session::getFriendManager()->verify(Biz::MessageUtil::makeSureUserJid(jid));
                break;
            }

        } while (true);
    }

    // 加别人好友
    void FriendsController::onFriendVerifyResultReceive( const QString& result, const QString& reason, const QString& jid )
    {
        //同意还是拒绝
        if (result == "success")
        {
            m_pFriendsList->insertFriendItem (jid);
            MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (QStringLiteral("成功加[%1]为好友!").arg(jid),jid);
        }
        else
        {
            MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("加[%1]为好友失败，%2").arg(jid,reason));
        }
    }

    // 被别人加为好友
    void FriendsController::onFriendVerifyResultByReceive( const QString& reason, const QString& jid )
    {
        MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (QStringLiteral("你被[%1]加为好友!").arg(jid),jid);
        m_pFriendsList->insertFriendItem (jid);
    }

    // 别人加我好友，我出的提示
    void FriendsController::onFriendVerifyInfoReceive( const QString& jid,const QString& body )
    {
        QString displayName = Biz::Session::getUserVcardManager ()->getUserNameByConversationId (jid);
        if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",
            QStringLiteral("是否加[%1]为好友,附加信息：%2").arg(displayName,body),
            QStringLiteral("拒绝加入"),
            QStringLiteral("同意加入")))
            Biz::Session::getFriendManager()->allowVerify(jid);
        else
            Biz::Session::getFriendManager()->deniedVerify(jid);
    }

    // 被我加的人有了反馈。
    void FriendsController::onAllowFriendVerifyResultByReceive(const QString& id, const QString& isAllow)
    {
        //同意还是拒绝
        if (isAllow == "allow")
        {
            m_pFriendsList->insertFriendItem (id);
            MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (QStringLiteral("[%1]同意被你加为好友!").arg(id),id);
        }
        else if(isAllow == "denied")
        {
            MainApp::UIFrame::getNotifyCenterController ()->popupNotice (QStringLiteral("[%1]拒绝被你加为好友!").arg(id));
        }
    }

    void FriendsController::onOpenNewChatSession(const QString& userID)
    {
        QString conversationId = Biz::MessageUtil::makeSureUserJid(userID);
        // 创建新的会话窗口,先有会话，additem的时候才能自动置顶
        UIFrame::getConversationController()->createNewChatDialog(conversationId);
        UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
        UIFrame::getConversationController()->activeConversation(conversationId);
        UIFrame::getConversationController()->moveSessionToTop(userID);
    }

    void FriendsController::onFriendListReceived(const QStringList& frlist)
    {
        if (NULL!=m_pFriendsList)
        {
            foreach (QString str, frlist)
                m_pFriendsList->insertFriendItem(str);
            Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(frlist);
        }
    }

    void FriendsController::onDeleteFriendReceive(const QString& reason, const QString& jid, int ntype/*=1*/)
    {
        if (NULL!=m_pFriendsList)
        {
            MainApp::UIFrame::getNotifyCenterController ()->popupNotice (QStringLiteral("删除好友[%1]成功!").arg(jid));
            m_pFriendsList->deleteItem(jid);
        }
    }

    void FriendsController::registBlackNameListView(BlackNameListView* plistview)
    {
        m_pBlackNameListView = plistview;

        connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginStatusChange,this,&FriendsController::onLoginStatusChange);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgManagerBlackNameListUpdate, this, &FriendsController::onBlackNameListUpdate);
        connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgCancelBlackName, this, &FriendsController::onCancelBlackName);
        connect(m_pBlackNameListView, &BlackNameListView::sgListEmpty, []{
            MainApp::UIFrame::getConversationController ()->showEmptyPage ();
        });
        connect (m_pBlackNameListView, &FriendsListView::sgItemClicked,[this](const QString& jid){
            MainApp::UIFrame::getConversationController ()->showFriendDetailInfoPage(jid, false);
        });

    }

	void FriendsController::registStarPersonListView(StarPersonListView* plistview)
	{
		m_pStarPersonListView = plistview;
		connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginStatusChange,this,&FriendsController::onLoginStatusChange);
		connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgManagerStarPersonListUpdate, this, &FriendsController::onStarPersonListUpdate);
		connect(m_pStarPersonListView, &StarPersonListView::sgItemDoubleClicked,this,&FriendsController::onOpenNewChatSession);
		connect (m_pStarPersonListView, &StarPersonListView::sgItemClicked,[this](const QString& jid){
			MainApp::UIFrame::getConversationController ()->showFriendDetailInfoPage(jid);
		});
		
		/*		connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgCancelBlackName, this, &FriendsController::onCancelBlackName);
		connect(m_pBlackNameListView, &BlackNameListView::sgListEmpty, []{
			MainApp::UIFrame::getConversationController ()->showEmptyPage ();
		});
		connect (m_pBlackNameListView, &FriendsListView::sgItemClicked,[this](const QString& jid){
			MainApp::UIFrame::getConversationController ()->showFriendDetailInfoPage(jid, false);
		});*/
	}

    void FriendsController::onBlackNameListUpdate()
    {
        QStringList accountlist = Biz::Session::getFriendManager()->getBlackNameInfoList();
        for (QString jid: accountlist)
        {
            if (jid.isEmpty())
                return;

            QString userjid = Biz::MessageUtil::makeSureUserJid (jid);
            QString strdisply = Biz::Session::getUserVcardManager()->getUserNameByConversationId (jid);
            m_pBlackNameListView->insertItem (userjid,strdisply);
            const QImage& image = Biz::PortraitHelper::getUserPortraitImage(userjid);
            m_pBlackNameListView->setItemImage (userjid,image);
        }
    }


    void FriendsController::onLoginStatusChange( int oldstatus,int newstatus )
    {
        if (m_pBlackNameListView!=NULL)
        {
            m_pBlackNameListView->clearAll();
            if (newstatus == Biz::LoginStatus_Connect)
            {
                // 读缓存
                onBlackNameListUpdate();
                onRobotSubscriptedListChange();
            }
        }
    }



    void FriendsController::onCancelBlackName( const QString&id, int rt )
    {
        if (m_pBlackNameListView!=NULL)
        {
            if (id.isEmpty())
                return;
            if (rt == Biz::FriendsManager::RESULTSUCCESS)
            {
                m_pBlackNameListView->deleteItem (id);
                MainApp::UIFrame::getConversationController ()->showEmptyPage ();
            }
        }
    }

    void FriendsController::registPublicAccountListView(PublicAccountListView* plistview)
    {
        m_pPublicAccountListView = plistview;
        connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgRobotSubscriptedListChange,this,&FriendsController::onRobotSubscriptedListChange);
        connect(m_pPublicAccountListView, &BlackNameListView::sgListEmpty, []{
            MainApp::UIFrame::getConversationController ()->showEmptyPage ();
        });
        connect (m_pPublicAccountListView, &FriendsListView::sgItemClicked,[this](const QString& jid){
            MainApp::UIFrame::getConversationController ()->showFriendDetailInfoPage(jid);
        });

        connect (m_pPublicAccountListView,&FriendsListView::sgItemDoubleClicked,[this](const QString& jid){
            QString rbtJid = Biz::MessageUtil::makeSureUserJid(jid);
            MainApp::UIFrame::getConversationController()->addRobotChatRosterItem(rbtJid,"");
            MainApp::UIFrame::getConversationController()->activeConversation(rbtJid);
            MainApp::UIFrame::getConversationController()->moveSessionToTop(rbtJid);
        });

    }




    void FriendsController::onRobotSubscriptedListChange()
    {
        QStringList accountlist = Biz::Session::getRobotManager()->getSubscriptedRobotList();
        for (QString strid: accountlist)
        {
            QString strDispName = Biz::Session::getUserVcardManager ()->getUserNameByConversationId (strid);
            m_pPublicAccountListView->insertItem (strid,strDispName);
            QImage image = Biz::PortraitHelper::getUserPortraitImage (strid);
            m_pPublicAccountListView->setItemImage (strid,image);
        }
    }

	void FriendsController::onStarPersonListUpdate()
	{
		m_pStarPersonListView->clearAll();
		QStringList accountlist = Biz::Session::getFriendManager()->getStarPersonInfoList();	
		for (QString jid: accountlist)
		{
			if (jid.isEmpty())
				return;

			QString userjid = Biz::MessageUtil::makeSureUserJid (jid);
			QString strdisply = Biz::Session::getUserVcardManager()->getUserNameByConversationId (jid);
			m_pStarPersonListView->insertItem (userjid,strdisply);
			const QImage& image = Biz::PortraitHelper::getUserPortraitImage(userjid);
			m_pStarPersonListView->setItemImage (userjid,image);
		}
	}

}