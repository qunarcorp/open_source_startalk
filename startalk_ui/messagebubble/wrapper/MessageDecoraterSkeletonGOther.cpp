#include "MessageDecoraterSkeletonGOther.h"

#include <QColor>

#include "XmppMessage.h"

#include "Session.h"
#include "UserVcardManager.h"
#include "accountmanager.h"
#include "portraithelper.h"
#include "MessageDecoraterBubbleWrapperOther.h"
#include "editablesettings.h"

QSharedPointer<IMessageBubble> MessageDecoraterSkeletonGOther::decorate(const QSharedPointer<IMessageBubble>& bubble)
{
     return QSharedPointer<IMessageBubble>(new MessageDecoraterSkeletonGOther(bubble));
}


MessageDecoraterSkeletonGOther::MessageDecoraterSkeletonGOther(QSharedPointer<IMessageBubble> bubble)
    :MessageDecoraterBase(bubble)
{
}

MessageDecoraterSkeletonGOther::~MessageDecoraterSkeletonGOther()
{
}

int MessageDecoraterSkeletonGOther::getMessageMediaType()
{
   return m_spDecorated->getMessageMediaType();
}

bool MessageDecoraterSkeletonGOther::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    if (!m_spDecorated->getTranslatedMessage(spMessage,htmlString))
        return false;

    // 发送者id
    QString senderid = spMessage->SenderJid();
	if (senderid.isEmpty())
		senderid = spMessage->Realfrom();

    // 发送者名称
    QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserJid(senderid));
    if (displayname.isEmpty() || displayname == senderid)
        displayname = spMessage->Resource();
    
    // 发送者名称的hash色值
    uint hashval = qHash(displayname);
    uint red = (hashval&0xFF0000)>>16;
    uint green = (hashval&0xff00)>>8;
    uint blue = (hashval&0xff);
    uint grayval = 0.299 * red + 0.587*green + 0.114*blue; 
    if (grayval>180)
    {
        red = red*0.8;
        green = green*0.8;
        blue = blue*0.8;
    }

    QString userNameColor = QColor(red,green,blue).name();

    // 发送者头像
    QString senderHeadUrl = Biz::PortraitHelper::getUserPortraitPath(senderid);

    if (senderHeadUrl.at(0) == ':')
        senderHeadUrl = "./image/default_header.png";
    else
	{
		senderHeadUrl = Biz::PortraitHelper::getGifCovertPng(senderHeadUrl, QSize(90, 90));
        senderHeadUrl = QUrl::fromLocalFile(senderHeadUrl).toString() + "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
	}

    // 发送者域
    QString tag = Biz::MessageUtil::compareJid(senderid,Biz::MessageUtil::makeSureUserId(senderid))?QStringLiteral("本域"):QStringLiteral("他域"); // 本域不显示
    // 发送端的平台信息
    static QString matypes[] = {"NA","MC","IP","PC","AP","LC"};
    QString matype = matypes[spMessage->MachineType()>5?0:spMessage->MachineType()];
    //发送端的时间戳
    QString timecurrent = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString timemsg = QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd");
    QString timeStemp = (timecurrent==timemsg)?
        QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("hh:mm:ss") :
        QDateTime::fromMSecsSinceEpoch(spMessage->UtcTime()).toString("yyyy-MM-dd hh:mm:ss");


    htmlString = QString(sHtmlcode)
        .arg(senderHeadUrl)     // %1
        .arg(displayname)       // %2
        .arg(senderid/*spMessage->Resource().toHtmlEscaped()*/)          // %3
        .arg(timeStemp)         // %4
        .arg(userNameColor)     // %5
        .arg(
        htmlString,             // %6
        "",                 // %7
        spMessage->MessageID(), // %8
        tag,                    // %9
        Biz::MessageUtil::makeSureUserId(senderid), // %10
        Biz::Session::getEditableSettings()->ShowSenderId()?"":"style=\"display:none\"", // %11
        Biz::MessageUtil::compareJid(senderid,Biz::MessageUtil::makeSureUserId(senderid))?"style=\"display:none\"":"", // %12
        senderid
        );

    return true;
}

bool MessageDecoraterSkeletonGOther::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
   return m_spDecorated->getShotTranslatedMessage(spMessage,body);
}



QString MessageDecoraterSkeletonGOther::sHtmlcode = 
    "<a name='%8' id='%8' > "
	"<table class='chat-message-left-table'>"
	"	<tr data-type='qtalk'> "
	"		<td style=\"min-width:50px;\" rowspan='2' align='center' valign='top' >"
	"			<img class='headimg' src='%1' onclick='onPopMenuClick(\"%3\")' data-resourcehead='%13'/> "
	"		</td>"
	"		<td class='title'> "
	"			<span class='tabicon' %12>%9</span> "
	"				<span data-resourcename='%13' style='color:%5'>%2</span> "
	"					<span class='tabsendid' %11>( %10 )</span>"
	"						<span class='tabtimehide'>%4</span> "
	"							<span class='matype'>%7</span> "
	"		</td>"
	"	</tr>"
	"	<tr data-type='qtalk'> "
	"		<td> %6</td>"
	"	</tr>"
	"</table>"
	"</a> ";

//<div class=' bubble9 mc-remote-sender %13'><div data-id='%8' data-user='message' class='balloon-inside'>%6</div>    </div>