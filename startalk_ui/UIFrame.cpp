#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"
#include "LoginController.h"
#include "ChatBubbleController.h"
#include "combinationcontroller.h"
#include "groupscontroller.h"
#include "NotifyCenterController.h"
#include "friendscontroller.h"
#include "virtualaccountcontroller.h"
#include "portraitcontroller.h"
#include "encryptchatcontroller.h"

namespace MainApp
{
    class UIFrameStruct
    {
    public:
        UIFrameStruct()
        {
        };

        ConversationController  s_conversationController;
        MainDialogController    s_mainDialogController;
        LoginController         s_loginController;
        ChatBubbleController    s_chatBubbleController;
		CombinationController   s_combinationController;
        GroupsController        s_groupsController;
        NotifyCenterController  s_notifyCenterController;
        FriendsController       s_friendsController;
		VirtualAccountController s_virtualController;
		portraitcontroller      s_portraitcontroller;
		EncryptChatController   s_encryptChatcontroller;
    };

    static UIFrameStruct s;

    void UIFrame::initialize()
    {
        s.s_conversationController.initController();
        s.s_mainDialogController.initController();
        s.s_loginController.initController();
        s.s_chatBubbleController.initController();
		s.s_combinationController.initController();
        s.s_groupsController.initController();
        s.s_notifyCenterController.initController ();
        s.s_friendsController.initController ();
		s.s_virtualController.initController();
		s.s_portraitcontroller.initController();
		s.s_encryptChatcontroller.initController();
    }

    void UIFrame::unInitialize()
    {
        s.s_conversationController.unInitController();
        s.s_mainDialogController.unInitController();
        s.s_loginController.unInitController();
        s.s_chatBubbleController.unInitController();
		s.s_combinationController.unInitController();
        s.s_groupsController.unInitController();
        s.s_notifyCenterController.unInitController ();
        s.s_friendsController.unInitController ();
		s.s_virtualController.unInitController();
		s.s_portraitcontroller.unInitController();
		s.s_encryptChatcontroller.unInitController();
    }

    ConversationController* UIFrame::getConversationController()
    {
        return &s.s_conversationController;
    }

    MainDialogController* UIFrame::getMainDialogController()
    {
        return &s.s_mainDialogController;
    }

    LoginController* UIFrame::getLoginController()
    {
        return &s.s_loginController;
    }

    ChatBubbleController* UIFrame::getChatBubbleController()
    {
        return &s.s_chatBubbleController;
    }
	CombinationController* UIFrame::getCombinationController()
	{
		return &s.s_combinationController;
	}

    GroupsController* UIFrame::getGroupsController()
    {
        return &s.s_groupsController;
    }

    NotifyCenterController* UIFrame::getNotifyCenterController()
    {
        return &s.s_notifyCenterController;
    }

    FriendsController* UIFrame::getFriendsController()
    {
        return &s.s_friendsController;
    }

	VirtualAccountController* UIFrame::getVirtualAccountController()
	{
		return &s.s_virtualController;
	}

	portraitcontroller* UIFrame::getportraitcontroller()
	{
		return &s.s_portraitcontroller;
	}

	EncryptChatController* UIFrame::getEncryptChatcontroller()
	{
		return &s.s_encryptChatcontroller;
	}

}
