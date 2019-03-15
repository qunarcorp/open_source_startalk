#include "MessageGroupRoomVideo.h"
#include "XmppMessage.h"
#include "Session.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "WebService.h"

#include "jsonobject/systemnotify.h"
#include "UserVcardManager.h"

const QString GroupRoomVideoWrap = "<div class=\"qchatnoticewarp\">%1<div class=\"qchatnoticespline\"></div> "
									"<div id = \"qchatnoticewarp_foot\" style = \" width:100%;height:100%;margin:0px;position:relative; \" >" 
									"<button class = \"qchatnoticeboot\" style = \"background-color: #D7D8DA ;margin:0 25% 0 ;\" "
									"onclick = \"gotoVideoRoom('%3')\">%2</button></div></div>";

const QString GroupRoomVideoItem = "<div class=\"qchatnoticeitem\"><div class=\"key\">%1</div><div class=\"value\">%2</div></div>";

MessageGroupRoomVideo::MessageGroupRoomVideo()
{
}

MessageGroupRoomVideo::~MessageGroupRoomVideo()
{

}

int MessageGroupRoomVideo::getMessageMediaType()
{
    return Biz::MessageMediaType::MediaTypeVideoRoom;
}

bool MessageGroupRoomVideo::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))

	QString spExternInfo = spMessage->Body();
	htmlString = spExternInfo;
	return true;
#else
	QString spExternInfo = spMessage->ExtendInfo ();
	if (!spExternInfo.isEmpty ())
	{
		Biz::GroupRoomVideoDetail roomdetail;
		roomdetail.unserializeFromString(spExternInfo);
		QString creatordiplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(
			Biz::MessageUtil::makeSureUserJid(roomdetail.creator()));
		QString grouptimes = GroupRoomVideoItem.arg(QStringLiteral("会议标题:"), roomdetail.topic());
		grouptimes += GroupRoomVideoItem.arg(QStringLiteral("创建者:"), creatordiplay);
		grouptimes += GroupRoomVideoItem.arg(QStringLiteral("创建时间:"), GetCurrentTm(roomdetail.createTime()));
		//	grouptimes += GroupRoomVideoItem.arg(QStringLiteral("开始时间:"), GetCurrentTm(roomdetail.startTime()));





		htmlString = GroupRoomVideoWrap.arg(grouptimes, QStringLiteral("进入聊天室"), spMessage->MessageID());
		return true;
	}


    
    return false;
#endif // 
}

bool MessageGroupRoomVideo::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
    body = QStringLiteral("[群视频会议]");
    return true;
}

QString MessageGroupRoomVideo::GetCurrentTm(quint64 tm)
{
	QString timeStemp;
	QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	QString timemsg = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd");

	timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd hh:mm:ss");
	

	return timeStemp;
}

MessageLiveGroupRoomVideo::MessageLiveGroupRoomVideo()
{

}

MessageLiveGroupRoomVideo::~MessageLiveGroupRoomVideo()
{

}

int MessageLiveGroupRoomVideo::getMessageMediaType()
{
	return Biz::MessageMediaType::MediaTypeSingleReceiveRtc;
}

bool MessageLiveGroupRoomVideo::getTranslatedMessage( QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString )
{
	if (spMessage.isNull())
	{
		return false;
	}
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))

	QString spExternInfo = spMessage->Body();
	htmlString = spExternInfo;
	return true;
#else
	QString spExternInfo = spMessage->ExtendInfo ();
	if (!spExternInfo.isEmpty ())
	{
		Biz::GroupRoomVideoDetail roomdetail;
		roomdetail.unserializeFromString(spExternInfo);
		QString creatordiplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(
			Biz::MessageUtil::makeSureUserJid(roomdetail.creator()));
		QString grouptimes = GroupRoomVideoItem.arg(QStringLiteral("会议标题:"), roomdetail.topic());
		grouptimes += GroupRoomVideoItem.arg(QStringLiteral("创建者:"), creatordiplay);
		grouptimes += GroupRoomVideoItem.arg(QStringLiteral("创建时间:"), GetCurrentTm(roomdetail.createTime()));
		//	grouptimes += GroupRoomVideoItem.arg(QStringLiteral("开始时间:"), GetCurrentTm(roomdetail.startTime()));





		htmlString = GroupRoomVideoWrap.arg(grouptimes, QStringLiteral("进入聊天室"), spMessage->MessageID());
		return true;
	}



	return false;
#endif // 
}

bool MessageLiveGroupRoomVideo::getShotTranslatedMessage( QSharedPointer<Biz::XmppMessage> spMessage,QString& body )
{
	body = QStringLiteral("[群视频直播]");
	return true;
}

QString MessageLiveGroupRoomVideo::GetCurrentTm( quint64 tm )
{
	QString timeStemp;
	QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	QString timemsg = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd");

	timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd hh:mm:ss");


	return timeStemp;
}
