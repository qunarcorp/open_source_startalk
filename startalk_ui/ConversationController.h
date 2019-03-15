#ifndef CONVERSATIONCONTROLLER_H
#define CONVERSATIONCONTROLLER_H

#include "ControllerBase.h"
#include <QStackedWidget>
#include "conversationmanager.h"
#include "Player.h"

class BaseChatDialog;
class ChatDialog;
class MultiDialogContainer;
class RosterListWidget;
class ExtendedSessionListView;
class RecentExtendedSessionListView;
class MimeTypeMessage;
class VidioAndAudioDialog;
class ConversationListWidget;
class AtInforItem;
namespace Biz{
    class XmppMessage;
    class GroupAtInfo;
    class ImSession;
    class RobotVcard;
    class AdvDataItem;
	class ConversationParam;
	
}
namespace MainApp
{
    /*!
    * \class ConversationController
    * \brief 负责会话窗口的控制，增删改查等
    * \author q
    * \date 三月 2016
    */
	enum ChatType
	{
		NormalChatType,
		CollectionChatType
	};
	enum NotieInfoTipPosion
	{
		GlobalOfTop,    //全局提示
		AppointofBottom //指定提示
	};
    class ConversationController : public ControllerBase
    {
        Q_OBJECT

    public:
        ConversationController();
        ConversationController(QObject *parent);
        ~ConversationController();
        virtual void initController();
        virtual void unInitController();
    public:
        MultiDialogContainer* getMultiDialogContainer(){return this->m_pContainer;};
        /*!
        * 功能 : 在初始化时必须被调用
        */
		BaseChatDialog* createNewConsultDialog(const QString& conversationid);
        BaseChatDialog* createNewChatDialog(const QString& conversationId);
        BaseChatDialog* createNewGroupChatDialog(const QString& conversationId); 
        BaseChatDialog* createNewMenuChatDialog(const QString& conversationId, int type=NormalChatType);
        BaseChatDialog* createNewNewsDialog(const QString& conversationId);
        BaseChatDialog* createNewRawHtmlDialog(const QString& conversationId);

        /*!
        * 功能 :
        */
        BaseChatDialog* findConversationBaseChatDialog(const QString& conversationId);
    public:
        /*!
        * 功能 : 创建会话列表的item
        */
        void addSimpleChatRosterItem(const QString& conversationId,const QString& extendId);
		/*!
        * 功能 : 创建会话列表的 consult 消息
        */
        void addConsultChatRosterItem(const QString& conversationId,const QString& extendId,const QString& virtualid,const QString& realseat,bool isSeat);

        /*!
        * 功能 : 创建群组会话
        */
        void addGroupChatRosterItem(const QString& conversatinId,const QString& extendid);
        /*!
        * 功能 : 创建机器人会话
        */
        void addRobotChatRosterItem(const QString& conversatinId,const QString& extendid);

        /*!
        * 功能 : 创建系统通知会话
        */
        void addNewsDialogRosterItem(const QString& conversatinId,const QString& extendid);

        /*!
        * 功能 : 创建扩展面板
        */
        void addLinkedItem(const QString& extendid,const QString& extendPannelTitle,const QString& belongExtendid);

        /*!
        * 功能 : 增加使用远端html样式的窗口
        */
        void addRawHtmlItem(const QString& conversatinId,const QString& extendid);

		//众包的设置
		void setZhongbaoInfor(const QString&id,const QString&infor);

		//创建代收的会话
		void addColloctionChatRosterItem(const QString& conversatinId,const QString& extendid);

	
    public:
        /*!
        * 功能 : 打开一个扩展列表，如果bAcitiveConversation为真，同时激活这个列表内的会话窗口
        */
        void activeLinkedPannel(const QString& pannelId,bool bAcitiveConversation);

        /*!
        * 功能 : 打开一个会话窗口
        */
        void activeConversation(const QString& conversationID);

		
        /*!
        * 功能 : 打开下一个未读的会话窗口
        */
        void activeNextUnreadConversation(bool promotWithCount);


        /*!
        * 功能 : 只删除会话框
        */
        void removeBaseChatDialog(const QString& coversationID);
        /*!
        * 功能 : 移除会话，移除会话列表和聊天窗口
        */
        void removeConversation(const QString& conversationID);

        /*!
        * 功能 : 删除扩展面板
        */
        void removeLinkedPannel(const QString& linkedPannel);

        /*!
        * 功能 : 删除所有的会话、扩展、会话框
        */
        void clearAllConversation();

        /*!
        * 功能 : 获取打开的会话的个数
        */
        int  getBaseChatDialogCount();

        /*!
        * 功能 : 获取所有会话个数
        */
        int getCouversationCount();
        /*!
        * 功能 : 查看会话列表中有没有这个会话，不包括会话窗口列表
        */
        bool hasConversation(const QString& conversationId);


        /*!
        * 功能 :清除会话的未读消息
        */
        void clearConversationAllRead(const QString& conversationId);

        /*!
        * 功能 : 判断是否是置顶会话
        */
        bool isTopChatDialog(const QString& coversationId );

        /*!
        * 功能 : 获取最顶层的会话的id
        */
        QString topConversationId();

        /*!
        * 功能 : 获取最顶层会话的句柄，用于热键呼出的截图
        */
        WId topConversationWid();

        /*!
        * 功能 : 加载带有未读消息和置顶的
        */
        void loadTopAndUnreadConversations();

        /*!
        * 功能 : 加载一般的会话列表
        */
        void loadAllChattingConversation();

        /*!
        * 功能 : 将某个会话放在最上面进行排序
        */
        void moveSessionToTop(const QString& jid);

        void emitSimpleChatDialogSendFile(const QString& conversationId);

        /*!
        * 功能 : 隐藏所有二人会话的右边提示窗口
        */
        void setChatDialogRightPanelVisible(bool show);

        quint64 getConversationChatId(const QString& conversationId);

		/*!
        * 功能 : 判断userid是否在机器人列表中
        */
		bool IsUserIdInAllRobotList(const QString& userid);

		/*!
        * 功能 : 将滚动条移动到顶部
        */
		void setScolltoTop();

		/*
			更新聊天框中输入框中的数据
		*/
		void updateWillSend(const QString& conversationId, const QSharedPointer<MimeTypeMessage>& willsendmsg );
		/*
			获取将要发送的消息
		*/
		QSharedPointer<MimeTypeMessage> getWillSend(const QString& conversationId);

		// 获取转移后两个返回值
		bool  getTransferShopValuebyId(const QString& id);
		bool getTransferVisitorValuebyId(const QString& id);

		//显示at信息块
		void showAtInfoBlockByConversation(const QString& id, const QString& atmsgId);

		QString getcctextbyconversationId(const QString& conversationId);
		QString getbubyconversationId(const QString&conversationId);

		QString getProductId(const QString& conversationId);
		QString getbusinessline(const QString& conversationId);

		bool isConversationPwd();
		QString getConversationKey();

		//激活代收的聊天框
		void activeCollectionConversation(const QString& parentId,const QString& conversationId);

		//代收人的信息
		void activeCollectionUser(const QString&bindUser);
    public:

        /*!
        * 功能 : 更新二人会话的channelid
        */
        void updateConversationChannelId(const QString& conversationId,const QString& channelid);
        void updateGroupHeader(const QString& jid);
        void updateAtCount(const QString& id,int count, int type, const QString&senduser);
        void updateJidLastTimeStamp(const QString& jid,quint64 time);
        void updateSessionConfigration(const QString& jid,int configvalue);
        void updateDisplayName(const QString& conversationId,const QString& displayName);
        void updatePresence(const QString& userId, int status);
        void onRosterCardUpdate(const QString& jid);


        void increaseAtNotice(const QString& id,int count, int type, const QString&senduser="");
        void clearAtNotice(const QString& id);
		//插入at信息到内存
		void addAtInfor(const QString&groupJid, const QString&userjid, const QString&msgid);
		//获取at信息的成员列表
		QStringList getAtInforMemberList(const QString&groupjid);
		//根据groupjid 和 userjid 获取msgids
		QStringList getMsgIdFromAtInfor(const QString&groupjid, const QString&userjid);

        void setAllMessageRead();
        /*!
        * 功能 : 存在某个会话分类
        */
        bool hasExtendedListView(const QString& extendid);

        bool hasNewExtendedListView(const QString& extendid);
        /*!
        * 功能 : 根据qchat内，右侧扩展栏的需求，放大或者缩小主框的大小
        */
        void resizeMainDialogBySimpleChatRightPannel();

        /*!
        * 功能 : 绑定扩展面板的一些事件
        */
        void bindExtendViewEvents(const RecentExtendedSessionListView* pExtendView );
	
		void bindExtendListViewEvents(const ExtendedSessionListView*pExtendView);

        /*!
        * 功能 : url 协议链接等 重定向
        */
        void shouldOverrideUrlLoading(const QUrl& url);
        /*!
        * 功能 : 更新会话备注信息
        */
        void updateMarkInfo(const QString& conversation);

        void showFriendDetailInfoPage(const QString& jid, bool bret=true);

        void showEmptyPage();

		void showGroupDetailInfoPage(const QString&jid);

		void insertChatIdVerinfo(const QString&id , const QString& version);
		QString getVerinfobychatId(const QString& id);

		/*
		* 音视频框的插入
		*/
		void insertVidioChat(const QString& id, VidioAndAudioDialog* dlg);
		/*
		* 音视频框的返回
		*/
		VidioAndAudioDialog *getVidioChatById(const QString& id);

		/*
		* 音视频框的删除
		*/
		void deleteVidioChatById(const QString& id);

		/*
		* 音视频框的删除
		*/
		bool IsVidioChatExist(const QString& id);

		//插入聊天窗和虚拟账号的对应
		void insertchatingvraccount(const QString&conversaionId, const QString& vraccountId);

		//根据聊天窗口查找是否有对应的虚拟Id
		QString getvraccountbychating(const QString& conversationId);

		//收集日志，并发送
		void collectLogsandSend();
		void collectLogsandSendEmail();
		//设置回答问题的人
		void setAskIds(const QStringList& list);
		bool IsAccountInAskIds(const QString& id);

		void addEncrypt(const QString&conversationId, const QString& encryptpwd);
		void deleteEncrypt(const QString& conversationId);
		QString getEncryptPwdbyconversationId(const QString& conversationId);
		void setMainKey(const QString& strMainKey) {mMainKey = strMainKey;}
		QString getMainKey(){return mMainKey;}

		//创建一个聊天框，并知道最前面
		void doCreateChatDialog(const QString&userid, const QString&ExtendInfor);

		QString doGetZhongbaoparamByconversationId(const QString& id);

		void updateChatContent(const QString& jid, const QSharedPointer<Biz::XmppMessage>& spMsg);

		
    public:
        void registChatDialogContainer(MultiDialogContainer* pChatsContainer);
    protected:
        RecentExtendedSessionListView* getExtendedSessionListView(const QString& extendid);
        RecentExtendedSessionListView* getExtendedSessionViewByConversationId(const QString& converdationId);
        QString getConversationsExtendId(const QString& conversationId);

        void addBaseChatDialog(const QString& conversationId, BaseChatDialog* pDialog);
        void activeBaseChatDialog(BaseChatDialog* pDialog);
		void updateNoticetip(const QString& conversation, const ConversationListWidget* rosterlistwidget);
		void paramMsgToItem(const QString&jid, const QSharedPointer<Biz::XmppMessage>& spInfo);
    public:
        static const QString    sDefaultExtendPanel;
    private:
		bool mbActiveItem;
		QString mNoActiveList;
		QString mSelfConversationKey;
		QStringList m_AskerIds;
	    QStringList m_AllRobotIdList;
        QMap<QString,BaseChatDialog*> m_conversationId2DialogMap;
        QMap<QString,RecentExtendedSessionListView*> m_jid2ExtendView;
		QMap<QString,ExtendedSessionListView*>m_jid2ExtendListView;
        MultiDialogContainer* m_pContainer;

		QMap<QString, QSharedPointer<MimeTypeMessage>> m_willSendMsg; 
        /*!
        * 功能 : 存放激活顺序，在队头的是最近访问的，在队尾的是搁置了的。新增的在对头
        */
        QList <BaseChatDialog*> m_queueBaseChatDialogs;


		QMap<QString, QString> mChatidVersionInfomap;


		//语音视频聊天中一个人只能有一个视频框
		QMap<QString, VidioAndAudioDialog*> m_Vidiomapmap;

		//聊天框和虚拟账号的对应
		QMap<QString, QString> mChatidvraccountmap; // "huajun.liu@ejabhost1, it-rexian"

		//转移会话返回值的
		QMap<QString, QSharedPointer<Biz::TransReplyValue>> mTransReplayvaluemap;

		//存放at信息的地方
		QMap<QString, QList<QSharedPointer<AtInforItem>>> mAtinformap; //groupjid, at信息

		//存放的是否需要加密的一些会话
		QMap<QString, QString> mEncryptChat; // 聊天框的id 和聊天加密的密码
		QString mMainKey;

		QMap<QString, QString> mZhongbaoParam; //众包参数的对应关系， 一个聊天框对应一个众包参数

		void createSimpleChatItem(const Biz::ImSession& imsession);
		void createGroupChatItem(const Biz::ImSession& imsession);
		void doGetZhongbaoParam(const QString&conversationId);
	
signals:
		void sgTransferResult(const QString&id, const QString& transid, bool bret, int type);
        void sgUpdateRawHtmlElementStatus(const QString& vcardId,const QString& message);
        void sgCurrentConversationChange(const QString& curConversation,const QString& lastConversation);
        void sgConversationActived(const QString& curConversation);
		void sgRobotSendMsg(const QString&conversationId, const QString&msg );
		void sgGroupChatMsgFilter(const QString&conversationId, const QStringList&ids);
		void sgGroupChatMsgAtFilter(const QString&conversationId, const QStringList&ids);
		
        public slots:
			

			void onTransReplay(const QString&conversation, int type);
			void onAllRobotIdList(const QStringList& robotlist );
            void onBackToWidget(const QString& userid);
			void onCollectBackToWidget(const QString&userid);
            void onSimpleChatDialogSendFile(const QString& conversationId);
            void onGroupLeaved(const QString& groupJid);
            void onGroupDestroyed(const QString& groupjid);
            void onDestroyGroupFail(const QString& jid,int code);
            void onRecentImSessionRecv(const QList<Biz::ImSession>& imSessions);
            void onAtMessageFindInUnreadMessage(const QString& conversationID,QSharedPointer<Biz::XmppMessage> spmessage);
            void onRobotVcardUpdate(const QList<QSharedPointer<Biz::RobotVcard>>& robotVcards);

            void onSubscriptMessageRecveid(const QSharedPointer<Biz::XmppMessage>& spMessage);


            void onShowAdvWidget(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist);
            void onCloseAdvWidget();

            void onDisconnect();
            void onAllConversationMessageReaded();

            void onUpdateUnReadCount(const QMap<QString,int>& cidUnreadCntMapping);
			
            void onConversationReadedByOtherClient(const QString& conversationid,quint64 ulLastTimeInDb);
            void onAllConversationReadedByOtherClient(quint64 ulLastTimeInDb);
			void onRemoveRecentItem(const QString&jid);
			void onGroupCoverAdd(const QString&jid);
			void onSelfConversationKey(const QString&key);
			void onEncryptEvent(int type, const QString&infor , const QString& conversationId);
			void onShowEmpty(const QString& conversationId);

			void onRectChatLastMsg(const QSharedPointer<Biz::MessageListData>& listmsg);

			void onPresenceOpenChat( const QSharedPointer<Biz::ConversationParam>& spConversationParam, quint64 stime);

			void onPresenceGlobalNotice(const QString& data);
			void onPresenceAppointNotice(const QString& data);
    };
}

#endif // CONVERSATIONCONTROLLER_H
