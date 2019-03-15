#include "MessageParser.h"

#include "MessageNormalChat.h"
#include "MessageGroupNotice.h"
#include "MessageMapPicture.h"
#include "MessageBubbleWrapper.h"
#include "MessageNoneBubbleWrapper.h"
#include "MessageControlRevokeMessage.h"
#include "MessageRobotRichText.h"
#include "MessageRobotDeal.h"
#include "MessageFile.h"
#include "MessageVoice.h"
#include "MessageProductAd.h"
#include "MessageVote.h"
#include "MessageSystemmessage.h"
#include "MessageNoticemessage.h"
#include "MessageActionRichText.h"
#include "MessageUnknow.h"
#include "MessageLiuYan.h"
#include "MessageRedpack.h"
#include "MessageTransSession.h"
#include "MessageProductInfo.h"
#include "MessageUnreadMessageTip.h"
#include "MessageHotelQuestions.h"
#include "MessageHotelOrders.h"
#include "XmppMessage.h"
#include "MessageChatNote.h"
#include "MessageGroupRoomVideo.h"
#include "messagesinglechataudeo.h"
#include "messagesinglechatvideo.h"
#include "MessageRobotQiangdan.h"
#include "MessageVideo.h"
#include "MessageEmotion.h"
#include "MessageProblemList.h"
#include "MessageMeetingRemind.h"

class MessageTypeKey
{
public:
    MessageTypeKey(){
        nMediaType = Biz::UnKnow;
        nMessageType = Biz::MediaTypeDetault;
    };
    ~MessageTypeKey(){};
    int nMessageType;
    int nMediaType;

    bool operator<(const MessageTypeKey& others) const
    {
        if (this->nMessageType < others.nMessageType)
        {
            return true;
        }

		if (this->nMessageType > others.nMessageType)
		{
			return false;
		}
        // == 
        return this->nMediaType<others.nMediaType;
    }
};

MessageParser* MessageParser::mInstance = NULL;
QMap<int,QSharedPointer<IMessageBubble>> MessageParser::parserMap;
QMap<MessageTypeKey,QSharedPointer<IMessageBubble>> MessageParser::typedParserMap;

MessageParser* MessageParser::getInstance()
{
	if (NULL == mInstance)
	{
		mInstance = new MessageParser();
		mInstance->initParserMap();
	}
	return mInstance;
}

void MessageParser::initParserMap()
{
	// 文本消息
	QSharedPointer<MessageNormalChat> spNomalChat(new MessageNormalChat());
	QSharedPointer<MessageBubbleWrapper> spNormalBubbleWrapper(new MessageBubbleWrapper(spNomalChat));
	parserMap.insert(spNormalBubbleWrapper->getMessageMediaType(),spNormalBubbleWrapper);
	// 群组内通知 15
	QSharedPointer<MessageGroupNotice> spGroupNotice(new MessageGroupNotice());
	parserMap.insert(spGroupNotice->getMessageMediaType(),spGroupNotice);
	// 地图消息 16
	QSharedPointer<MessageMapPicture> spGroupMapPicture(new MessageMapPicture());
	QSharedPointer<MessageBubbleWrapper> spMapPictureBubbleWrapper(new MessageBubbleWrapper(spGroupMapPicture));
	parserMap.insert(spMapPictureBubbleWrapper->getMessageMediaType(),spMapPictureBubbleWrapper);
    // 文件消息
    QSharedPointer<MessageFile> spFileMessage(new MessageFile());
    QSharedPointer<MessageBubbleWrapper> spFileBubbleWrapper(new MessageBubbleWrapper(spFileMessage));
    parserMap.insert(spFileBubbleWrapper->getMessageMediaType(),spFileBubbleWrapper);

    // 语音文件
    QSharedPointer<MessageVoice> spVoiceMessage(new MessageVoice());
    QSharedPointer<MessageBubbleWrapper> spVoiceBubbleWrapper(new MessageBubbleWrapper(spVoiceMessage));
    parserMap.insert(spVoiceBubbleWrapper->getMessageMediaType(),spVoiceBubbleWrapper);

    // 产品广告
    QSharedPointer<MessageProductAd> spProductAd (new MessageProductAd());
    QSharedPointer<MessageBubbleWrapper> spProductAdBubbleWrapper(new MessageBubbleWrapper(spProductAd));
    parserMap.insert(spProductAdBubbleWrapper->getMessageMediaType(),spProductAdBubbleWrapper);

    // 投票消息
    QSharedPointer<MessageVote> spVote (new MessageVote());
    QSharedPointer<MessageBubbleWrapper> spVokeBubbleWrapper(new MessageBubbleWrapper(spVote));
    parserMap.insert(spVokeBubbleWrapper->getMessageMediaType(),spVokeBubbleWrapper);
    QSharedPointer<MessageVotePro> spVotePro (new MessageVotePro());
    QSharedPointer<MessageBubbleWrapper> spVokeProBubbleWrapper(new MessageBubbleWrapper(spVotePro));
    parserMap.insert(spVokeProBubbleWrapper->getMessageMediaType(),spVokeProBubbleWrapper);

	// 客服的note消息
	QSharedPointer<MessageChatNote> spChatNote (new MessageChatNote());
	QSharedPointer<MessageBubbleWrapper> spChatNoteBubbleWrapper(new MessageBubbleWrapper(spChatNote));
	parserMap.insert(spChatNoteBubbleWrapper->getMessageMediaType(),spChatNoteBubbleWrapper);

	//系统消息
	QSharedPointer<MessageSystemmessage> spSystemMessage (new MessageSystemmessage());
	QSharedPointer<MessageBubbleWrapper> spSystemMessageBubbleWrapper(new MessageBubbleWrapper(spSystemMessage));
	parserMap.insert(spSystemMessageBubbleWrapper->getMessageMediaType(), spSystemMessageBubbleWrapper);

	//公告消息
	QSharedPointer<MessageNoticemessage> spNoticeMessage (new MessageNoticemessage());
	parserMap.insert(spNoticeMessage->getMessageMediaType(), spNoticeMessage);

	//留言
	QSharedPointer<MessageLiuYan> spLiuyan(new MessageLiuYan);
	QSharedPointer<MessageBubbleWrapper> spLiuyanMessageBubbleWrapper(new MessageBubbleWrapper(spLiuyan));
	parserMap.insert(spLiuyanMessageBubbleWrapper->getMessageMediaType(), spLiuyanMessageBubbleWrapper);

	//红包
	QSharedPointer<MessageRedpack> spRedPack(new MessageRedpack);
	parserMap.insert(spRedPack->getMessageMediaType(), spRedPack);

	//转移
	QSharedPointer<MessageTransSession> spTransSession(new MessageTransSession);
	parserMap.insert(spTransSession->getMessageMediaType(), spTransSession);

	//产品推荐
	QSharedPointer<MessageProductInfo> spProdeuctInfo(new MessageProductInfo);
	parserMap.insert(spProdeuctInfo->getMessageMediaType(), spProdeuctInfo);


    // 酒店消息
    QSharedPointer<MessageHotelQuestions> spHotelQuestionMessage(new MessageHotelQuestions());
    QSharedPointer<MessageNoneBubbleWrapper> spHotelQuestionMessageWrapper(new MessageNoneBubbleWrapper(spHotelQuestionMessage));
    parserMap.insert(spHotelQuestionMessageWrapper->getMessageMediaType(),spHotelQuestionMessageWrapper);
    // 酒店消息
    QSharedPointer<MessageHotelOrders> spHotelOrdersMessage(new MessageHotelOrders());
    QSharedPointer<MessageNoneBubbleWrapper> spHotelOrdersMessageWrapper(new MessageNoneBubbleWrapper(spHotelOrdersMessage));
    parserMap.insert(spHotelOrdersMessageWrapper->getMessageMediaType(),spHotelOrdersMessageWrapper);
  
	//群视频会议室的消息
	QSharedPointer<MessageGroupRoomVideo> spGroupRoomVideoMessage(new MessageGroupRoomVideo());
	QSharedPointer<MessageBubbleWrapper> spGroupRoomVideoMessageWrapper(new MessageBubbleWrapper(spGroupRoomVideoMessage));
	parserMap.insert(spGroupRoomVideoMessageWrapper->getMessageMediaType(), spGroupRoomVideoMessageWrapper);

	//视频直播的消息
	QSharedPointer<MessageLiveGroupRoomVideo> spLiveGroupRoomVideoMessage(new MessageLiveGroupRoomVideo());
	QSharedPointer<MessageBubbleWrapper> spLiveGroupRoomVideoMessageWrapper(new MessageBubbleWrapper(spLiveGroupRoomVideoMessage));
	parserMap.insert(spLiveGroupRoomVideoMessageWrapper->getMessageMediaType(), spLiveGroupRoomVideoMessageWrapper);

	//二人视频会议的消息
	QSharedPointer<MessageSingleChatVideo> spSingleChatVideoMessage(new MessageSingleChatVideo());
	QSharedPointer<MessageBubbleWrapper> spSingleVideoMessageWrapper(new MessageBubbleWrapper(spSingleChatVideoMessage));
	parserMap.insert(spSingleVideoMessageWrapper->getMessageMediaType(), spSingleVideoMessageWrapper);

	//二人语音会议的消息
	QSharedPointer<MessageSingleChatAudeo> spSingleChatAudeoMessage(new MessageSingleChatAudeo());
	QSharedPointer<MessageBubbleWrapper> spSingleChatAudeoMessageWrapper(new MessageBubbleWrapper(spSingleChatAudeoMessage));
	parserMap.insert(spSingleChatAudeoMessageWrapper->getMessageMediaType(), spSingleChatAudeoMessageWrapper);

	//视频文件的消息类型
	QSharedPointer<MessageVideoFile> spVideoFileMessage(new MessageVideoFile());
	QSharedPointer<MessageBubbleWrapper> spVideoFileMessageWrapper(new MessageBubbleWrapper(spVideoFileMessage));
	parserMap.insert(spVideoFileMessageWrapper->getMessageMediaType(), spVideoFileMessageWrapper);

	//问题列表
	QSharedPointer<MessageProblemList> spProblemListMessage(new MessageProblemList());
	QSharedPointer<MessageBubbleWrapper> spProblemListMessageWrapper(new MessageBubbleWrapper(spProblemListMessage));
	parserMap.insert(spProblemListMessageWrapper->getMessageMediaType(), spProblemListMessageWrapper);
	//问题列表Hints 
	parserMap.insert(Biz::MediaTypeConsultHints, spProblemListMessage);
	parserMap.insert(Biz::MediaTypeHints, spProblemListMessage);

	//会议提醒消息 
	QSharedPointer<MessageMeetingRemind> spMeetingRemindMessage(new MessageMeetingRemind());
	QSharedPointer<MessageBubbleWrapper> spMeetingRemindMessageWrapper(new MessageBubbleWrapper(spMeetingRemindMessage));
	parserMap.insert(spMeetingRemindMessageWrapper->getMessageMediaType(), spMeetingRemindMessageWrapper);

	//30表情消息
// 	QSharedPointer<MessageEmotion> spEmotionMessage(new MessageEmotion());
// 	QSharedPointer<MessageBubbleWrapper> spEmotionMessageWrapper(new MessageBubbleWrapper(spEmotionMessage));
// 	parserMap.insert(spEmotionMessageWrapper->getMessageMediaType(), spEmotionMessageWrapper);

    /*!
     * 功能 : 增加运营抢单
     */
    QSharedPointer<MessageRobotDeal> spRobotDeal(new MessageRobotDeal());
    MessageTypeKey key;
    key.nMessageType    = spRobotDeal->getMessageType();
    key.nMediaType      = spRobotDeal->getMessageMediaType();
    typedParserMap.insert(key,spRobotDeal);

	//抢单消息
	QSharedPointer<MessageRobotQiangDan> spRobotQiangdan(new MessageRobotQiangDan());
	MessageTypeKey keyqiangdan;
	keyqiangdan.nMessageType    = spRobotQiangdan->getMessageType();
	keyqiangdan.nMediaType      = spRobotQiangdan->getMessageMediaType();
	typedParserMap.insert(keyqiangdan,spRobotQiangdan);

    /*!
     * 功能 : 增加撤销消息的解析
     */
    QSharedPointer<MessageControlRevokeMessage> spMessageRevoke(new MessageControlRevokeMessage);
     key.nMessageType       = spMessageRevoke->getMessageType();
     key.nMediaType         = spMessageRevoke->getMessageMediaType();
     typedParserMap.insert(key,spMessageRevoke);

	 //其实Note消息大类型的，但是由于之前的错误，导致出现了问题，必须兼容数据库中以前的数据（之前用的是小类型）
	 QSharedPointer<MessageChatNote> spMessageNote(new MessageChatNote);
	 QSharedPointer<MessageBubbleWrapper> spMessageChatNoteBubbleWrapper(new MessageBubbleWrapper(spMessageNote));
	 MessageTypeKey keyNote;
	 keyNote.nMessageType = spMessageNote->getMessageType();
	 keyNote.nMediaType = spMessageNote->getMessageMediaType();
	 typedParserMap.insert(keyNote, spMessageChatNoteBubbleWrapper);


	 /*!
	  * 功能 : 机器人 缓存cookie消息
	  */
	 QSharedPointer<MessageClientCookie> spMessageClientCoolie(new MessageClientCookie);
     QSharedPointer<MessageBubbleWrapper> spMessageClientCookieWrapper(new MessageBubbleWrapper(spMessageClientCoolie));
     MessageTypeKey keyClientCoolieNote;
     keyClientCoolieNote.nMessageType = spMessageClientCoolie->getMessageType();
     keyClientCoolieNote.nMediaType = spMessageClientCoolie->getMessageMediaType();
     typedParserMap.insert(keyClientCoolieNote, spMessageClientCookieWrapper);

	 /*!
	  * 功能 : 机器人 
	  */
	 QSharedPointer<MessagePostBackCookie> spPostBackCookie(new MessagePostBackCookie);
     QSharedPointer<MessageBubbleWrapper> spPostBackCookieWrapper(new MessageBubbleWrapper(spPostBackCookie));
	 MessageTypeKey postBackCookieKey;
	 postBackCookieKey.nMessageType = spPostBackCookie->getMessageType();
	 postBackCookieKey.nMediaType = spPostBackCookie->getMessageMediaType();
	 typedParserMap.insert(postBackCookieKey, spPostBackCookieWrapper);

	 /*!
	  * 功能 : 机器人相关
	  */
	 QSharedPointer<MessageRobotRichText> spRobotRichText(new MessageRobotRichText);
	 MessageTypeKey robotRichTextkey;
	 robotRichTextkey.nMessageType = spRobotRichText->getMessageType();
	 robotRichTextkey.nMediaType = spRobotRichText->getMessageMediaType();
	 typedParserMap.insert(robotRichTextkey, spRobotRichText);

	 QSharedPointer<MessageActionRichText> spActionRichText(new MessageActionRichText);
	 MessageTypeKey actionRichTextKey;
	 actionRichTextKey.nMediaType = spActionRichText->getMessageMediaType();
	 actionRichTextKey.nMessageType = spActionRichText->getMessageType();
	 typedParserMap.insert(actionRichTextKey, spActionRichText);

	QSharedPointer<MessageUnreadTip> spUnreadTip(new MessageUnreadTip());
    MessageTypeKey UnreadTipKey;
    UnreadTipKey.nMediaType     = spUnreadTip->getMessageMediaType();
    UnreadTipKey.nMessageType   = spUnreadTip->getMessageType();
    typedParserMap.insert(UnreadTipKey, spUnreadTip);


}

MessageParser::MessageParser()
{

}

MessageParser::~MessageParser()
{

}

bool MessageParser::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}

    MessageTypeKey key;
    key.nMessageType    = spMessage->MsgSourceType();
    key.nMediaType      = spMessage->MediaType();
	bool bret = false;

    if (typedParserMap.contains(key))
    {
        bret = typedParserMap.value(key)->getTranslatedMessage(spMessage,htmlString);
    } 
    else if (parserMap.contains((int)spMessage->MediaType()))
	{
		bret = parserMap.value(spMessage->MediaType())->getTranslatedMessage(spMessage,htmlString);
	}

    return bret?bret:parserMap.value(Biz::MediaTypeDetault)->getTranslatedMessage(spMessage,htmlString);
}

bool MessageParser::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if(spMessage.isNull())
		return false;
    MessageTypeKey key;
    key.nMessageType    = spMessage->MsgSourceType();
    key.nMediaType      = spMessage->MediaType();

    if (typedParserMap.contains(key))
    {
       return typedParserMap.value(key)->getShotTranslatedMessage(spMessage,body);
    }

	if (parserMap.contains((int)spMessage->MediaType()))
	{
		return parserMap.value(spMessage->MediaType())->getShotTranslatedMessage(spMessage,body);
	}

	if (parserMap.contains((int)Biz::MediaTypeDetault))
	{
		return parserMap.value(Biz::MediaTypeDetault)->getShotTranslatedMessage(spMessage,body);
	}
	return false;
}

bool MessageParser::getControlJavaScripte(QSharedPointer<Biz::XmppMessage> spMessage,QString& js)
{
	if (spMessage.isNull())
	{
		return false;
	}
    MessageTypeKey key;
    key.nMessageType    = spMessage->MsgSourceType();
    key.nMediaType      = spMessage->MediaType();

    if (typedParserMap.contains(key))
    {
        return typedParserMap.value(key)->getControlJavaScripte(spMessage,js);
    }

    if (parserMap.contains((int)spMessage->MediaType()))
    {
        return parserMap.value(spMessage->MediaType())->getControlJavaScripte(spMessage,js);
    }


    return false;
}

bool MessageParser::decorateWithTimestame(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString strUtcTime = QString("%1").arg(spMessage->UtcTime());
    body = QString("<div id='%1_framework' data-use='msgbubbletime' data-value=%3 >%2</div>").arg(spMessage->MessageID(), body, strUtcTime/*msg->UtcTime()*/);
    return true;
}

bool MessageParser::decorateWithReply(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
    if (Biz::MessageTypeOther== spMessage->MsgDirection ())
    {
        QString backinfo = spMessage->BackupInfo ();
        QJsonDocument doc = QJsonDocument::fromJson (backinfo.toUtf8 ());
        QVariantList vl = doc.toVariant ().toList ();
        for (QVariant vv:vl)
        {
            QVariantMap vm = vv.toMap ();
            if (vm.contains ("type") && 20001 == vm.value ("type").toInt ())
            {
                body = QStringLiteral("<div>%2<div style=\"margin-left: 50px\"><a href=\"javascript:replyWechatUser('%1')\">回复</a></div></div>").arg(spMessage->MessageID(),body);
                break;
            }
        }
    }
    return true;
}
