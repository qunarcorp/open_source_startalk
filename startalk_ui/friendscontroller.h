#pragma once
#include "ControllerBase.h"

class FriendsListView;
class BlackNameListView;
class PublicAccountListView;
class StarPersonListView;
namespace MainApp
{
    class FriendsController : public ControllerBase
    {
        Q_OBJECT
    public:
        FriendsController();
        ~FriendsController();
    public:
        virtual void initController();
        virtual void unInitController();
    public:
        void registFriendsListView(FriendsListView* plistview);;
        inline FriendsListView* getFriendsListView(){return this->m_pFriendsList;};
        void registBlackNameListView(BlackNameListView* plistview);;
        inline BlackNameListView* getBlackListView(){return this->m_pBlackNameListView;};

        void registPublicAccountListView(PublicAccountListView* plistview);;
        inline PublicAccountListView* getPublicAccountListView(){return this->m_pPublicAccountListView;};

		void registStarPersonListView(StarPersonListView* plistview);
		inline StarPersonListView* getStarPersonListView(){ return this->m_pStarPersonListView; };
    private:
        FriendsListView* m_pFriendsList;
        BlackNameListView* m_pBlackNameListView;
        PublicAccountListView* m_pPublicAccountListView;
		StarPersonListView* m_pStarPersonListView;
        public slots:
            void onVerifyFriendModeReceive(const QString& model, const QString& question, const QString& jid);
            void onFriendVerifyResultReceive(const QString& result, const QString& reason, const QString& jid);
            void onFriendVerifyResultByReceive(const QString& reason, const QString& jid);
            void onFriendVerifyInfoReceive(const QString& id,const QString& body);
             void onAllowFriendVerifyResultByReceive(const QString& id, const QString& isAllow);

             void onOpenNewChatSession(const QString& conversationid);
             void onFriendListReceived(const QStringList& frlist);
             void onDeleteFriendReceive(const QString& reason, const QString& jid, int ntype=1);
             void onLoginStatusChange( int oldstatus,int newstatus );
             void onBlackNameListUpdate();
             void onCancelBlackName( const QString&id, int rt );
             void onRobotSubscriptedListChange();
			 void onStarPersonListUpdate();
    };
}
