#include "MessageAddFriends.h"
#include "XmppMessage.h"

MessageAddingFriend::MessageAddingFriend()
{

}

MessageAddingFriend::~MessageAddingFriend()
{

}

int MessageAddingFriend::getMessageMediaType()
{
	return 0;
}

bool MessageAddingFriend::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	#if 0
	代码备份，暂时无实际功能，2016年7月13日10:23:37
if (msg.isNull())
	{
		return false;
	}


	QString body = msg->Body();
	QString strRefusebody = QStringLiteral("你已拒绝[%1]加为好友").arg(msg->SenderUserID());
	QString strAgreebody = QStringLiteral("你已同意[%1]加为好友").arg(msg->SenderUserID());
	QString strMsgid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	int status = msg->Flag();
	QString timeStemp /*= GetCurrentTm(msg->UtcTime())*/;
	QString displaystyle = "inline_block";
	int nMsgDirection = msg->MsgDirection();
	if (nMsgDirection == Biz::ADDDIRECTION) // 自己主动添加别人为好友
	{
		displaystyle = "none"; //不要下面的展示

	}
	else if (nMsgDirection == Biz::BYADDDIRECTION) //别人邀请我，我要标题
	{
		//displaystyle = "inline_block";
		if (status == Biz::WAITSTATUS)
		{
			displaystyle = "inline_block";
		}
		else if (status == Biz::REFUSESTATUS)
		{
			displaystyle = "none";
		}
		else if (status == Biz::AGREESTATUS)
		{
			displaystyle = "none";
		}
	}


	QString userid = msg->ConversationID();
	QString clickagreefun = QString("onAgree(\"%1\",\"%2\")").arg(strMsgid).arg(userid);
	QString clickrefusefun = QString("onRefuse(\"%1\",\"%2\")").arg(strMsgid).arg(userid);

	htmlString = QString(AddFRIENDSINFO_BODY_HTML_TEMPLATE).arg(timeStemp).arg(strMsgid).arg(QStringLiteral("微软雅黑")).
		arg(body, displaystyle, QStringLiteral("同意"), QStringLiteral("拒绝"), clickagreefun, clickrefusefun, strAgreebody, strRefusebody);

#endif


	return false;
}

bool MessageAddingFriend::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	return false;
}
