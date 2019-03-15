#pragma once
namespace MainApp{
    class ConversationController;
    class MainDialogController;
    class LoginController;
    class ChatBubbleController;
	class CombinationController;
    class GroupsController;
    class NotifyCenterController;
    class FriendsController;
	class VirtualAccountController;
	class portraitcontroller;
	class EncryptChatController;
    class UIFrame
    {
    public:
        static void initialize();
        static void unInitialize();
    
    public:
        static ConversationController*  getConversationController();
        static MainDialogController*    getMainDialogController();
        static LoginController*         getLoginController();
        static ChatBubbleController*    getChatBubbleController();
		static CombinationController*   getCombinationController();
        static GroupsController*        getGroupsController();
        static NotifyCenterController*  getNotifyCenterController();
        static FriendsController*       getFriendsController();
		static VirtualAccountController* getVirtualAccountController();
		static portraitcontroller*      getportraitcontroller();
		static EncryptChatController*   getEncryptChatcontroller();
    };
}
