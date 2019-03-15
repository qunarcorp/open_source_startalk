#ifndef XMPPMESSAGE_H
#define XMPPMESSAGE_H

#include <QObject>
#include "qstack.h"
#include "IXmlSerializeable.h"
#include "QXmppMessage.h"


namespace Biz
{
	enum EncryptMessageType
	{
		EncryptMessageType_Begin = 1,
		EncryptMessageType_Agree,
		EncryptMessageType_Refuse,
		EncryptMessageType_Cancel,
		EncryptMessageType_Close

	};

	enum BackupInfoType{
		CHATTYPEBASE = 10000,
		CHATTYPEATINFO = CHATTYPEBASE +1
	};
	enum consultmsgType
	{
		VistorToOnDuty = 4,
		OnDutyToVistor=5
	};
    //同步qxmppmessage type，避免外面依赖qxmpp，重写一份吧,可以和qxmppmessage互转
    enum MessageMediaType{
		MediaTypeDetault  = 1,
        MediaTypeText  = 1,
        MediaTypeVoice = 2,
        MediaTypeImage = 3,
        MediaTypeFile  = 5,
        MediaTypeAction= 6,             // 机器人专用
        MediaTypeRichText           = 7,    // 机器人专用
        MediaTypeActionsRichText    = 8,    // 机器人专用
        MediaTypeClientCookie       = 9,    // 机器人专用
        MediaTypeShockAndPostBackCookie = 10, // 机器人专用
		MessageTypeNote					= 11 ,//note消息专用
		MessageTypeAt           =12,   //@的专用消息 
		MessageTypeMarkdown    =13,    //markdown的消息
		MediaTypeGroupNotify    = 15, // 群里的通知消息
		MediaTypeMapPicutre     = 16,
        MediaTypeVote           = 666,
        MediaTypeVotePro        = 667, // 第二行的detail不限高度的。
		MediaTypeProduct		= 888,
		MediaTypeTransBase      = 1000,
		MediaTypeTransVisitor   = MediaTypeTransBase + 1,   //这是webChat的转移
		MediaTypeTransShop      = MediaTypeTransBase + 2,   //这是客户端的转移
		MediaTypeTransVisitorReply     = MediaTypeTransBase + 3, //这是webChat的回馈
		MediaTypeTransShopReply     = MediaTypeTransBase + 4, //这是客户端的回馈

        MediaTypeRobotBase      = 2000,
        MediaTypeRobotQiangDan  = MediaTypeRobotBase+1,
        MediaTypeRobotNotice    = MediaTypeRobotBase+2,
		MediaTypeRobotYYQiangDan  = MediaTypeRobotBase + 3,
		MediaTypeRobotQiangDanStatus= MediaTypeRobotBase + 4,
		MediaTypeRobotZhongbao  = MediaTypeRobotBase + 5,   //众包的类型
        MediaTypeWeiDaoYou      = 3001,
		

        MediaTypeHotelBase      = 4000,
        MediaTypeHotelQuestions = MediaTypeHotelBase+0,
        MediaTypeHotelOrders    = MediaTypeHotelBase+1,

		//音视频的小类型
		MediaTypeaudioReceiveRtc = 65535, //收到后调用调用JS的 receiveRtc()  //视频
		MediaTypeaudioReceiveRtcAudio = 131072,//收到后，调用 JS的 receiveRtcAudio() //音频
		MediaTypeSingleReceiveRtc = 65501, //视频直播的类型

		//视频的ping
		MediaTypeVideoPing = 5100,
		//音频的ping
		MediaTypeAudeoPing = 5102,
		//视频的ping相应
		MediaTypeVideoPingRespon = 5101,
		//音频的ping相应
		MediaTypeAudeoPingRespon = 5103,

		//群视频会议的消息
		MediaTypeVideoRoom = 5001,

        MediaTypeRedPackageBase = (1<<9),
        MediaTypeRedPackageNormal = MediaTypeRedPackageBase,
        MediaTypeRedPackageAA = MediaTypeRedPackageBase +1,

        MediaTypeRedPakage=(1<<10) ,//这是红包的信息
        MediaTypeProductInfo=(1<<12), //

        MediaTypeNotice = (1<< 27),
		MediaTypeSystemBase = (1<< 28), 
		MediaTypeSystem = MediaTypeSystemBase,
		MediaTypeSystemLY = MediaTypeSystemBase + 1,

        MediaTypeRevokeMessage = -1,

		MediaTypeCodeHLight = 64, 

		MediaTypeEncrypt = 404,  //这是加密的消息

		MediaTypeVideo = 32,     //这是发送视频文件的类型
		MediaTypeImageNew = 30,    //新的图片类型， 不进入输入框中的图片的发送（主要展示的时候不带气泡）

		//问题列表
		MediaTypeProblemList = 65536,
		MediaTypeConsultHints = 65537,
		MediaTypeHints = 14,

		//会议提醒
		MeetingRemindMessage = 257,

    };

    enum MessageDirection{
        MessageTypeOther = 0,
        MessageTypeSelf = 1
    };


    enum MessageSourceType{
        ChatMessage     = 0,
        GroupMessage    = 1,
		readmark        = 2,
        headline        = 3,
		subscription    = 4,
        Trans			= 5,
		Note			= 6,
        revoke          = 7,
		webrtc          = 15,
		encrypt         = 16,
		collection      = 17,
		consult         = 8,
		// consultClient	= 9,
        RevertMsgType   = 97,
        subscription_weidaoyou    = 98,
		UnKnow			= 99
    };

    // 可以和qxmppmeessage 互转
    enum MessageMachineType{
        MachineTypeNONE     = 0,
        MachineTypeMac      = 1,
        MachineTypeiOS      = 2,
        MachineTypePC       = 3,
        MachineTypeWeb      = 4,
        MachineTypeAndroid  = 5,
        MachineTypeMAX  = 6
    };

    enum ReadMarkTypeValue {
		ReadMark_all	= 0,
		ReadMark_chat	= 1,
        ReadMark_group  = 2,
		ReadMark_received = 3,
		ReadMark_chat_readed = 4 
    };

	enum SysMsgCheckStatus
	{
		UnChecked,
		Checked
	};



    class XmppMessage : public IXmlSerializeable
    {
        Q_OBJECT
    public:
        enum MessageDisplayFlag {
            MDF_DEFAULT         = 0x00,
            MDF_SHAREMESSAGE    = 0x01
        };
	public:
		const static QString MessageTypeString_GroupChat;
		const static QString MessageTypeString_Chat;
		const static QString MessageTypeString_Consult;
    public:
		static MessageSourceType messageSourceTypeValueOf(const QString& text);
		static QString messageSourceTypeTextOf( MessageSourceType value);
		static QString makeConsultConversation5Id(const QString realfrom,const QString& virtualid);
		static QPair<QString,QString> parseConsultConversation5id(const QString& conversationid);
	


        XmppMessage(const QString& peerUserID);
        ~XmppMessage();
		bool isVoicePlayed();
		bool isMessageSendSuccess();
		bool isMessageSendFail();
		bool isMessageSending();


        /*
         *	回话窗口的key，由此确定消息入哪个回话窗口
         */
        PROPERTY(QString,ConversationID); // 2ren : dui duan id; you @
        
		// 负责群消息路由的
		PROPERTY(QString,Resource);
        PROPERTY(QString,SenderJid); // 2ren : recv:zhong wen ming , sender:
        /*
         *	消息体
         */
        PROPERTY(QString,Body);
        /*
         *	公告
         */

        PROPERTY(QString,Subject);
        PROPERTY(QString,MessageID);
		PROPERTY(QString,SendFileID);//改 删除
        PROPERTY(quint64,UtcTime);
        PROPERTY(quint32,LocalFlag); // 按位做标志，0x01：发送的消息， 0x10:收到的消息，历史消息默认为0x10;
		PROPERTY(quint32,RemoteFlag);
        PROPERTY(bool,OfflineMessage);
        PROPERTY_REF(QStack<QString>, localUrls);
        /*
         *	消息的方向
         */
        PROPERTY(MessageDirection,MsgDirection);
        PROPERTY(MessageSourceType,MsgSourceType);
        PROPERTY(MessageMediaType,MediaType);
        PROPERTY(MessageMachineType,MachineType);
		PROPERTY(quint64, Chatid);
		PROPERTY(quint64, qchatid);
		//是否是已读
        PROPERTY(bool,autoReply);
		//订单类消息是否已经被处理过
		PROPERTY(SysMsgCheckStatus,Checked);

        /*
         *	阅读指针分类
         */
        PROPERTY(ReadMarkTypeValue,ReadMarkType);

        /*
         *	扩展信息
         */
        PROPERTY(QString,ExtendInfo);
		PROPERTY(QString,BackupInfo);

        /*!
         *  channenid
         */
        PROPERTY(QString,ChannelId);

        PROPERTY(int,DisplayFlag);
		//realid
		PROPERTY(QString, Realto);
		PROPERTY(QString, Realfrom);
		PROPERTY(QString, from);
		PROPERTY(QString, virtualId);
		PROPERTY(QString, cctext);
		PROPERTY(QString, bu);

		//collection
		PROPERTY(MessageSourceType, origintype);
		PROPERTY(QString, originto);
		PROPERTY(QString, originfrom);
		
		//标识该消息是否抄送
		PROPERTY(bool,MsgCarbon);
		PROPERTY(QString,rawMessage);
    }; 


    class XmppMessageMark : public XmppMessage
    {
        Q_OBJECT
    public:
        XmppMessageMark(const QString& peerUserID);
        ~XmppMessageMark();
        PROPERTY(bool,SearchMark); // 2ren : dui duan id; you @
    };

    class XmppMessageAttachment : public IXmlSerializeable
    {
        Q_OBJECT
    public:
        XmppMessageAttachment();
        ~XmppMessageAttachment();
        PROPERTY(QString,MessageID);
        PROPERTY(QString,URL);
        PROPERTY(QString,NAME);
        PROPERTY(QString,MD5);
        PROPERTY(QString,LOCALCOPY);
		//其实这两个参数一般没用，但是在gif的图片进行转换成png图片时需要用
		PROPERTY(int,WidthOfCompress); //在html上展示图片的宽度
		PROPERTY(int, HeightOfCompress); //在html上展示图片的高度

    };


    enum AtType
    {
        AtNone = 0,
        AtOne,
        AtAll
    };

    class MessageUtil
    {
    public :
        static QXmppMessage toQxmppMessage(const QSharedPointer<Biz::XmppMessage>& spMessage);
        static QSharedPointer<Biz::XmppMessage> fromQxmppMessage(const QXmppMessage& message);
		static QString makeSureUserJidByDefaultDomain(const QString& id, const QString& domain);
		static QString makeSureUserJid(const QString& jid);
		static QString makeSureGroupJid(const QString& jid,const QString& defaultDomain = "");
		static QString makeSureGroupId(const QString& jid);
		static QString makeSureGroupDomain(const QString& unknowTypeId);
		static QString makeSureGroupSingleDomain(const QString& groupjid);
		static QString makeSureGroupShortDomain(const QString& unknowTypeId);
		static QString makeSureJidResource(const QString& resource);
		static QString makeSureUserDomain(const QString& userDomain);
		static bool compareUserId(const QString& idLeft,const QString& idRight);
		static bool compareJid(const QString& idLeft,const QString& idRight);
		static QString makeSureUserId(const QString& Jid);
		static QString makeSureUserBaseJid(const QString& jid);

		static QString makeUserIdSpell(const QString& jid);
        static bool isGroupJid(const QString& jid);

        static AtType chargeIsAtNotice(const QSharedPointer<Biz::XmppMessage>& xmppMessage,bool fuzzy = true);

		static void tagMessageUnreadFlag(QSharedPointer<Biz::XmppMessage>& spmessage);
		static void tagMessageReadedFlag(QSharedPointer<Biz::XmppMessage>& spmessage);
    };




}

#endif // XMPPMESSAGE_H
