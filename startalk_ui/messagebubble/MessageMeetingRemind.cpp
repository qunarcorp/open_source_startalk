#include "MessageMeetingRemind.h"

#include "Session.h"
#include "Account.h"
#include "AccountData.h"

/*
<div style="margin:-15px 0 0 -10px;">
	<span style="display:block;font-size:16px;font-weight:bold;margin-bottom:5px;">您收到一个行程邀请</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">行程发起人 : helen.liu</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">行程名称 : qtalk组例会</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">开始时间 : 2018-08-20 14:00:00</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">结束时间 : 2018-08-20 16:00:00</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">行程地点 : 维亚大厦5层人类星球</span>
	<span style="display:block;font-size:14px;margin-bottom:2px;color:#000000;">备注 : </span>
	<a href='javascript:window.Cocoa.openMeetingInfo("https://im.qunar.com/pubim/pub/mainSite/meeting/MeetingDetail.php?username=ping.xue&amp;meeting_id=136742");' style="display:block;font-size:14px;margin-top:15px;">查看详情</a>
</div>
*/

MessageMeetingRemind::MessageMeetingRemind(void) 
{

}

MessageMeetingRemind::~MessageMeetingRemind(void)
{

}

int MessageMeetingRemind::getMessageMediaType()
{
	return Biz::MeetingRemindMessage;
}

bool MessageMeetingRemind::getMeetingRemindMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString) {
	QByteArray ba;
	ba = spMessage->ExtendInfo().length() > 0?spMessage->ExtendInfo().toUtf8():spMessage->Body().toUtf8();
	QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
	if(Json_Data.isObject())
	{
		QVariant strdata = Json_Data.toVariant(); 
		QVariantList hintArr;
		if (strdata.canConvert<QVariantMap>())
		{ 
			QVariantMap meetingMap = strdata.toMap();
			QVariantMap params = meetingMap.value("params").toMap();
			QString meetingId = params.value("id").toString();
			QString title = meetingMap.value("title").toString();
			QString url = meetingMap.value("url").toString(); 
			QVariant meeting = meetingMap.value("keyValues"); 
			htmlString.append("<div style=\"display:block;margin:10px 0 10px 0;\">");
			htmlString.append(QString("<span style=\"display:block;font-size:16px;font-weight:bold;margin-bottom:5px;\">&nbsp;&nbsp;%1&nbsp;&nbsp;</span>").arg(title));
			if (meeting.canConvert<QVariantMap>())
			{
				QVariantMap meetingInfo = meeting.toMap();
				QList<QString> meetingList = meetingInfo.keys();
				for (QString key : meetingList)
				{
					QString value = meetingInfo.value(key).toString();
					htmlString.append(QString("<span style=\"display:block;font-size:14px;margin-bottom:2px;color:#000000;\">&nbsp;&nbsp;%1 : %2&nbsp;&nbsp;</span>").arg(key,value));
				}
			} else
			{
				QList<QVariant> meetingList = meeting.toList();
				for (QVariant item : meetingList)
				{ 
					QVariantMap meetingInfo = item.toMap();
					QList<QString> meetingList = meetingInfo.keys();
					for (QString key : meetingList)
					{ 
						QString value = meetingInfo.value(key).toString();
						htmlString.append(QString("<span style=\"display:block;font-size:14px;margin-bottom:2px;color:#000000;\">&nbsp;&nbsp;%1 : %2&nbsp;&nbsp;</span>").arg(key,value));
					}
				}
			}
			if (url.indexOf("?"))
			{
				url.append(QString("&username=%1&meeting_id=%2").arg(Biz::Session::currentAccount().accountData().UserID(),meetingId));
			} else { 
				url.append(QString("&username=%1&meeting_id=%2").arg(Biz::Session::currentAccount().accountData().UserID(),meetingId));
			}
			htmlString.append(QString("<span style=\"display:block;\">&nbsp;&nbsp;<a href='javascript:CLIENT_API.jsOpenMeetingInfo(\"%1\");' style=\"font-size:14px;margin-top:15px;\">%2</a>&nbsp;&nbsp;</span>").arg(url,QStringLiteral("查看详情")));
			htmlString.append("</div>"); 
			return true;
		}
	}
	return false;
}
 
bool MessageMeetingRemind::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	switch (spMessage->MediaType())
	{
	case Biz::MeetingRemindMessage:
		{
			return getMeetingRemindMessage(spMessage,htmlString);
		}
		break; 
	default:
		break;
	}
	return false;
}

bool MessageMeetingRemind::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
	body = QStringLiteral("[问题列表]");
	return true;
}