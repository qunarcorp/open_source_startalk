#include "MessageSystemmessage.h"
#include "XmppMessage.h"
#include "ConversationController.h"
#include "UIFrame.h"
#include "MessageListData.h"
#include "UiHelper.h"

#include "jsonobject/systemnotify.h"

#include "colorset.h"

const QString SYSNEWS_BODY_HTML_TEMPLATE = 
    "<div class='qchatnoticewarp'>                                                                                 "
    "    <div id='qchatnoticewarp_header' class='qchatnoticeheader' onclick=\"onOpenUrl('%1')\"><div class='first'>%2</div><div class='secend'>%3</div></div>  "
    "    <div class='qchatnoticespline'></div>                                                                     "
    "     %4                                                                                                       "
    "    <div class='qchatnoticespline'></div>                                                                     "
    "    <div id='qchatnoticewarp_foot' class='qchatnoticeboot' onclick=\"onOpenUrl('%1')\">                                                                             "
    "       <div id ='%1_Left' class='left' style='color:%7'>%5</div>"
    "       <div id ='%1_Right' class='right'style='color:%8'>%6</div>"
    "    </div>                "
    "</div>                                                                                                      "; 
const QString SYSNEWS_BODY_HTML_TEMPLATE_ITEM = "<div class='qchatnoticeitem' ><div class='key'>%1</div><div class='value'>%2</div></div>";

MessageSystemmessage::MessageSystemmessage()
{

}

MessageSystemmessage::~MessageSystemmessage()
{

}

int MessageSystemmessage::getMessageMediaType()
{
    return Biz::MediaTypeSystem;
}

bool MessageSystemmessage::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> msg,QString& htmlString)
{
	if (msg.isNull())
		return false;

    QString jsonString = msg->Body ();
    Biz::SystemNotifyParam snp;
    snp.unserializeFromString (jsonString);
    QString strItemHtmlContent;

    if (!snp.order_id ().isEmpty ())
    {
        QString orderItem = QString(SYSNEWS_BODY_HTML_TEMPLATE_ITEM).arg (QStringLiteral("订单号"),snp.order_id ());
        strItemHtmlContent += orderItem;
    }

    for (IJsonSerializeable* item: snp.content ())
    {
        Biz::ContentItemInfo* pContent = (Biz::ContentItemInfo*)item;
        QString orderItem = QString(SYSNEWS_BODY_HTML_TEMPLATE_ITEM).arg (pContent->sub_title (),pContent->sub_content ());
        strItemHtmlContent += orderItem;
    }

    QString timeStemp = GetCurrentTm(msg->UtcTime());
    QString leftPromot = snp.prompt ();
    if (msg->Checked () && !snp.clickprompt ().isEmpty ())
        leftPromot = snp.clickprompt ();

    Biz::ExtraInfo* pExtraInfo = (Biz::ExtraInfo*)snp.extra ();
    QString rightPromot = !msg->Checked () ?
        (NULL == pExtraInfo?QStringLiteral("现在去处理->"):pExtraInfo->opertext ())
        :(NULL==pExtraInfo?QStringLiteral("已处理"):(pExtraInfo->checkedopertext ()));

    QString leftcoColor = msg->Checked () ? ColorSetSingleton::getInstance ()->qchat_notice_promo_checked():ColorSetSingleton::getInstance ()->qchat_notice_promo_normal();
    QString rightColor  = msg->Checked () ? ColorSetSingleton::getInstance ()->qchat_notice_option_checked():ColorSetSingleton::getInstance ()->qchat_notice_option_normal();


    

	htmlString = QString(SYSNEWS_BODY_HTML_TEMPLATE)
        .arg(msg->MessageID(),snp.title (),timeStemp,strItemHtmlContent,leftPromot,rightPromot,leftcoColor,rightColor);
       
        return true;

}

bool MessageSystemmessage::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString jsonString = spMessage->Body ();
    Biz::SystemNotifyParam snp;
    snp.unserializeFromString (jsonString);
    body = QStringLiteral("[%1]").arg(snp.title ());
    return true;
}


QString MessageSystemmessage::GetCurrentTm( quint64 tm )
{
	QString timeStemp;
	QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	QString timemsg = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd");
	if (timecurrent == timemsg)
	{
		timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("hh:mm:ss");
	}
	else
	{
		timeStemp = QDateTime::fromMSecsSinceEpoch(tm).toString("yyyy-MM-dd hh:mm:ss");
	}

	return timeStemp;
}

