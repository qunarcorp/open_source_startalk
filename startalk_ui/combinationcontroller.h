#ifndef COMBINATIONCONTROLLER_H
#define COMBINATIONCONTROLLER_H

#include "ControllerBase.h"
class MultiDialogContainer;
class CombinationExtendedSessionListView;
class GroupListView;
class RosterTreeView;
class FriendsListView;
class PublicAccountListView;
class BlackNameListView;
class CombinationOfStarPersonExtendedListView;
class CombinationOfGroupExtendedListView;
class CombinationOfOrganiExtendedListView;
class CombinationOfFriendExtendedListView;
class CombinationOfPublicAccountExtendedListView;
class CombinationOfBlackNameExtendedListView;
class ExtendedSessionListView;

namespace MainApp
{
    class CombinationController : public ControllerBase
    {
        Q_OBJECT

    public:
        CombinationController();
        CombinationController(QObject *parent);
        ~CombinationController();
        virtual void initController();
        virtual void unInitController();
    public:
        void registCombinationContainer(MultiDialogContainer* pChatsContainer);
		void hideCombinationContainerOfOrganizaItem();

		void createCombinationItemOfPwd();

    public:
        static const QString  sDefaultCombinationExtendPanel;
    private:
        //组织架构的初始化
        void initRosterTreeConnect(const RosterTreeView*prostertree);



        void createCombinationItems();
		void addCombinationOfStarPersonItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfGroupItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfOrganizaItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfFriendItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfGzhItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfBlackItem(const QString& extendid,const QString& extendPannelTitle,CombinationExtendedSessionListView* belongView);
        void addCombinationOfWorkplace(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView);
        void addCombinationOfWechats(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView);

        void addCombinationExtendItem(const QString& extendid,const QString& extendPannelTitle,ExtendedSessionListView* pSubWidget,CombinationExtendedSessionListView* belongWidget);
		//密码箱
		void addCombinationOfPasswordBox(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView);

		//记事本
		void addCombinationOfNoteInfo(const QString& extendid,const QString& extendPannelTitel,CombinationExtendedSessionListView* belongView);
    private:
        MultiDialogContainer*   m_pContainer;
        RosterTreeView*         m_pAllstaffTreeView;
        CombinationExtendedSessionListView* m_pExtendedSessionListView;
        QMap<QString, std::function<void()>> m_id2CombinnationForwardAction;
signals:
        void sgCombinationbtn();
        void sgchatsbtn();



        public slots:
            void onGroupChatDialog(const QString& userID, const QString& displayName, bool autoJoin);
            void onPublicAccountItemClicked(const QString&id);
            void onChatDialog(const QString& userID, const QString& displayName);
            void onCombinationItemClicked(const QString&id);
            void ongroupItemclick();
            void onLoginStatusChange(int oldstatus,int newstatus);
			
    };
}


#endif // COMBINATIONCONTROLLER_H
