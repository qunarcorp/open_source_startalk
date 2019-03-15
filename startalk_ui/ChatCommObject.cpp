#include "ChatCommObject.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Log.h"
#include "QDesktopServices"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include <QClipboard>
#include <QApplication>
#include "SystemDefine.h"
#include "accountmanager.h"
#include "messagebubble/MessageParser.h"

#include "WebPage.h"
#include "Ordermanagedialog.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "messagebubble/MessageUnreadMessageTip.h"
#include "portraithelper.h"
#include "WebService.h"
#include "UserVcardManager.h"
#include "SettingData.h"

// enum Direction {
//     Up = 0,
//     Down = 1,
// };

// enum Self {
//     True = 1,
//     False = 0
// };

ChatCommObject::ChatCommObject(QObject* parent)
    : WebViewCommObject(parent)
{
	mStarttm = 0;
	mwebpage = NULL;
}

ChatCommObject::~ChatCommObject()
{

}

void ChatCommObject::jsShowBlankMenu()
{

}

void ChatCommObject::jsShowContentMenu()
{

}


QJsonObject innerInsertText(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
	{
		return QJsonObject();
	}
    QString body = msg->Body();
    body.replace(8232,'\n');
    // 找发送人的id
	QString senderid;
	if (msg->MsgSourceType() == Biz::collection)
	{
		if (msg->origintype() == Biz::MessageSourceType::GroupMessage)
		{
			
			 senderid = msg->Realfrom();
			 
		}
		else if (msg->origintype() == Biz::MessageSourceType::ChatMessage)
		{
			senderid = msg->originfrom();
		}
		
	}
	else
    senderid = 
        Biz::MessageSourceType::GroupMessage == msg->MsgSourceType() ?
        /*msg->ResourceUserID()*/ msg->Realfrom():
        msg->ConversationID();
    // 找发送人的头像
    QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
    auto senderHeadUrl = Biz::ConfigureHelper::user_PortraitPath(Biz::Session::getAccountManager()->accountData().UserID(), senderid);
    if( !QFile(senderHeadUrl).exists())
        senderHeadUrl = curDir+ "\\resources\\defaultportrait.png";

	//判断senderHeadUrl的图片的类型和大小
	
	senderHeadUrl = Biz::PortraitHelper::getGifCovertPng(senderHeadUrl, QSize(90, 90));

    QJsonObject obj;
    obj.insert("head", "file:///" + senderHeadUrl.replace("\\", "/")+ "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-",""));
    obj.insert("content", body);
    obj.insert("time",(qint64)msg->UtcTime());
    quint64 timet = msg->UtcTime();
    obj.insert("self",  msg->MsgDirection() == Biz::MessageTypeSelf ? 1 : 0);
    QString strmessageID;
    if (msg->MessageID().isEmpty())
    {
        strmessageID = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
    }
    else 
    {
        strmessageID = msg->MessageID();
    }
    obj.insert("msgId", msg->MessageID());

    if (msg->MsgDirection() == Biz::MessageTypeOther )
    {
        obj.insert("username", senderid);
    }
    else if (msg->MsgDirection() == Biz::MessageTypeSelf)
    {
        obj.insert("username", QString(""));
    }
    QString strMsgBody;
    if (MessageParser::getInstance()->getTranslatedMessage(msg, strMsgBody))
    {
        MessageParser::getInstance ()->decorateWithTimestame (msg,strMsgBody);
        MessageParser::getInstance ()->decorateWithReply (msg,strMsgBody);
        obj.insert("htmlContext", strMsgBody);
		
    }
    else
    {
        Log::e(QString("can not find message passer %1").arg(msg->MessageID()));
    }
    return obj;

}

QJsonObject innerInsertHistoryText(const QSharedPointer<Biz::XmppMessageMark>& msg,const QString strflag="")
{
	if (msg.isNull())
	{
		return QJsonObject();
	}
    QString body = msg->Body();
    body.replace(8232,'\n');
    // 找发送人的id
    QString senderid = 
        Biz::MessageSourceType::GroupMessage == msg->MsgSourceType() ?
        msg->SenderJid() :
        msg->ConversationID();

    QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
    QString userid = Biz::Session::getAccountManager()->accountData().UserID();

    QJsonObject obj;
    obj.insert("content", body);
    obj.insert("time", QString::number(msg->UtcTime()));
    obj.insert("self",  0);
    obj.insert("userid", senderid);
    if (msg->MsgDirection() == Biz::MessageTypeOther )
    {
        obj.insert("username", senderid);
    }
    else if (msg->MsgDirection() == Biz::MessageTypeSelf)
    {
        obj.insert("username", userid);
    }
    QString strMsgBody;
    if (MessageParser::getInstance()->getTranslatedMessage(msg,strMsgBody))
    {
        obj.insert("htmlContext", strMsgBody);
    }


    QString strmessageID;
    if (msg->MessageID().isEmpty())
    {
        strmessageID = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
    }
    else 
    {
        strmessageID = msg->MessageID();
    }
    obj.insert("msgId", msg->MessageID());
    return obj;
}

void ChatCommObject::appendMessageJavescrip(WebPage* webPage, bool isHistroy, bool hasMore, const QList<QSharedPointer<Biz::XmppMessage>>& messages, int aotuscroll /*= 0*/)
{
    if (1 == messages.size())
    {
        QSharedPointer<Biz::XmppMessage> spMessage = messages.at(0);
        if (Biz::revoke == spMessage->MsgSourceType() && !isHistroy)
        {
            QString strJs;
            bool bRet = MessageParser::getInstance()->getControlJavaScripte(spMessage, strJs);
            if (bRet)
            {
                webPage->runLocalJavaScript(strJs);
                return;
            }
        }
    }

    QJsonObject obj;
    obj.insert("hasHistory",/* hasMore ? 1 : 0*/1);
    obj.insert("direction", isHistroy ? 0 : 1);
    obj.insert("autoscroll", aotuscroll);
    QJsonArray msgs;
	Log::e("ChatCommObject::appendMessageJavescrip message size= " + QString("%1").arg(messages.size()));
    foreach(auto item, messages) {
        Log::e("ChatCommObject::appendMessageJavescrip " + item->MessageID());
        msgs.append(innerInsertText(item));
    }
    obj.insert("section", msgs);
    QJsonDocument doc(obj);

    auto a = doc.toJson().simplified();
    QString content = QString::fromUtf8(doc.toJson());
    content = QString("PAGE_API.review(") + content + QString(")");
	
    if (isHistroy)
    {
        webPage->runLocalJavaScript((QString("PAGE_API.review(") + QString::fromUtf8(doc.toJson()) + QString(")")));
		
    }
    else
    {
        webPage->runLocalJavaScript((QString("PAGE_API.receive(") + QString::fromUtf8(doc.toJson()) + QString(")")));
    }

	QString Sfont = Biz::Session::getSettingConfig()->MFontFamily();
	jsSetStatusfontfamy(webPage,Sfont);

}


void ChatCommObject::appendHistoryMessage(WebPage* webFrame,const QList<QSharedPointer<Biz::XmppMessageMark>>& messages, int aotuscroll, const QString strflag)
{
    QJsonObject obj;
    obj.insert("hasHistory", 1);
    obj.insert("direction",  0);
    obj.insert("autoscroll", aotuscroll);
    QJsonArray msgs;
    foreach(auto item, messages){
        msgs.append(innerInsertHistoryText(item,strflag));
    }
    obj.insert("section", msgs);
    QJsonDocument doc(obj);

    auto a = doc.toJson().simplified();
    QString content = QString::fromUtf8(doc.toJson());
    content = QString("PAGE_API.review(") + content  + QString(")");
    webFrame->runLocalJavaScript((QString("PAGE_API.review(") + QString::fromUtf8(doc.toJson()) + QString(")")));
}

void ChatCommObject::jsTest()
{

}

void ChatCommObject::review(quint64 timestamp, int height)
{
    emit sgQueryMore(timestamp, height);
}



void ChatCommObject::showNewMessageTip(const QString& name,const QString& messageid)
{
    emit ChatCommObject::sgShowNewMessageTip(name,messageid);
}

void ChatCommObject::jslog(QString log)
{
    Log::e(" ChatCommObject::jsDownReciv on webview" + log);
}

void ChatCommObject::scrollToEnd(WebPage* webFrame)
{
    webFrame->runLocalJavaScript( QString("PAGE_API.scrollToEnd()") );
}

void ChatCommObject::hideNewMessageTip()
{
    emit ChatCommObject::sgHideNewMessageTip();
}

void ChatCommObject::systemnotify(WebPage* webframe, QString notify )
{
    QString js =  QString(
        "PAGE_API.systemnotify(\"" + notify + "\")") ;
	// js中换行导致执行失败 将换行替换为空格
	js = js.replace("\n", "\\n");
    webframe->runLocalJavaScript(js);
    scrollToEnd(webframe);
}
void ChatCommObject::sendFileProgress(WebPage* webframe, const QString&key, qint64 done, qint64 total)
{
    float myvalue = 0.0;
    if (total == 0)
    {
        myvalue = 1.0;
    }
    else
    {
        myvalue=done/((float)total);
    }

    QString strtmp = QString("%1").arg(key);
    QJsonObject obj;
    obj.insert("sectionid", strtmp);
    obj.insert("myprovalue", myvalue);


    QJsonDocument doc(obj);

    auto a = doc.toJson().simplified();
    QString content = QString::fromUtf8(doc.toJson());

    QString content1=(QString("PAGE_API.setprogress(") + QString::fromUtf8(doc.toJson()) + QString(")"));

    webframe->runLocalJavaScript( content1 );
}

void ChatCommObject::jsCancelSend(const QString&id)
{
    emit sgCancelSend(id);
}

void ChatCommObject::jsDownReciv(const QString&sectionid, const QString&fileMd5)
{
    Log::e(" ChatCommObject::jsDownReciv on webview" +sectionid);
    Log::e(" ChatCommObject::jsDownReciv on webview" +fileMd5);

    emit sgReceivalFile(sectionid, fileMd5);

}
void ChatCommObject::RecvFileProgress(WebPage* webframe,const QString&key, const QString& fileName, qint64 done, qint64 total)
{
    QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
    QString fileIcon = "file:///" + curDir+ "/resources/aio_group_search_normal.png";
    float myvalue = 0.0;
    if (total == 0)
    {
        myvalue = 1.0;
    }
    else
    {
        myvalue =done/((float)total);
    }

    if (myvalue>1.0)
    {
        myvalue = 1.0;
    }

    QJsonObject obj;
    obj.insert("sectionid", key);
    obj.insert("myprovalue", myvalue);
    obj.insert("srcimage", fileIcon);
    obj.insert("filename", fileName);
    QJsonDocument doc(obj);

    auto a = doc.toJson().simplified();
    QString content = QString::fromUtf8(doc.toJson());

    QString content1=(QString("PAGE_API.setrecvprogress(") + QString::fromUtf8(doc.toJson()) + QString(")"));

    webframe->runLocalJavaScript( content1 );
}

void ChatCommObject::jsSearchRecivFile(const QString&msgid)
{
    Log::e(" ChatCommObject::jsSearchRecivFile on webview" +msgid);

    emit sgOpenFilePath(msgid);  
}
void ChatCommObject::jsOpenFile(const QString& msgid)
{
    Log::e(" ChatCommObject::jsOpenFile on webview" +msgid);

    emit sgOpenFile(msgid);
}
void ChatCommObject::jsSaveFile(const QString& msgid)
{
    Log::e(" ChatCommObject::jsSaveFile on webview" +msgid);

    emit sgSaveAs(msgid);
}
void ChatCommObject::jsSaveFilePic(const QString&strLocalPath)
{
    emit sgSaveAsPic(strLocalPath);
}  

void ChatCommObject::UploadOver(WebPage* webframe,const QString&key)
{
    QString strtmp = QString("%1").arg(key);
    QJsonObject obj;
    obj.insert("sectionid", strtmp);

    QJsonDocument doc(obj);


    QString content = QString::fromUtf8(doc.toJson());

    QString content1=(QString("PAGE_API.setuploadover(") + QString::fromUtf8(doc.toJson()) + QString(")"));

    webframe->runLocalJavaScript( content1 );
}


void ChatCommObject::uploadFail(WebPage* webframe,const QString&key)
{
    QString strtmp = QString("%1").arg(key);
    QJsonObject obj;
    obj.insert("sectionid", strtmp);

    QJsonDocument doc(obj);


    QString content = QString::fromUtf8(doc.toJson());

    QString content1=(QString("PAGE_API.setUploadFail(") + QString::fromUtf8(doc.toJson()) + QString(")"));

    webframe->runLocalJavaScript( content1 );
}


void ChatCommObject::jsImageClicked(QString src, QString urlsrc)
{
    emit sgImageClicked(src, urlsrc);
}

void ChatCommObject::jsImageDbClicked(QString src, QString Urlsrc)
{
	Log::e(QString("ChatCommObject::jsImageDbClicked(%1, %2)").arg(src).arg(Urlsrc));
    emit sgImageDbClicked(src, Urlsrc);
}

void ChatCommObject::jsSpaceClicked()
{
    emit sgSpaceClicked();
}


void ChatCommObject::jsSelectAll(WebPage* webFrame)
{
    QString content1=(QString("PAGE_API.selectAll()"));

    webFrame->runLocalJavaScript( content1 );
}

void ChatCommObject::jsSelectCopy(WebPage* webFrame)
{     
    QString content1=(QString("PAGE_API.selectcopy()"));

    webFrame->runLocalJavaScript( content1 );
}

void ChatCommObject::SetClipData(const QString& str)
{

}


void ChatCommObject::jsSendFile(const QString& guid,const QString& str)
{
    emit sgSendFile(guid);
}

void ChatCommObject::jsOpenVoice(const QString& guid)
{
    emit sgOpenVoice(guid);
}
void ChatCommObject::jsGroupPopMenu(const QString& resource)
{
    emit sgGroupPopMenu(resource);
}

void ChatCommObject::updateVoiceImage(WebPage* webframe,const QString& messageid, const QString& img)
{
    QString str = QString("updateVoiceImage('%1','%2')").arg(messageid).arg(img);
    webframe->runLocalJavaScript(str);
}



void ChatCommObject::jsUserIdEnter(const QString& userId)
{
    emit sgUserIdEnter(userId);
}

void ChatCommObject::jsUserIdLeave(const QString& userId)
{
    emit sgUserIdLeave(userId);
}

void ChatCommObject::jsMsgFindMao(WebPage* webframe, const QString& msgid)
{
    QString str = QString("findmsgMao('%1')").arg(msgid);
    webframe->runLocalJavaScript(str);
    str = QString("noticeat('%1')").arg(msgid);
    webframe->runLocalJavaScript(str);
}

void ChatCommObject::jsOpenUrl( const QString& url )
{
    emit sgOpenUrl(url);
}

void ChatCommObject::CheckedSysMsg(WebPage* webFrame, const QString& strmsg )
{
    webFrame->runLocalJavaScript( (QString("PAGE_API.setModeBookingState(") + strmsg + QString(")")) );
}

void ChatCommObject::jsAgreeAddFriend(const QString& str)
{
    emit sgAgreeAddFriend(str);
}
void ChatCommObject::jsRefuseAddFriend(const QString& str)
{
    emit sgRefuseAddFriend(str);
}

void ChatCommObject::jsChangeclicked( const QString&from )
{
    emit sgTransChatRecord(from);
}


void ChatCommObject::updateCardState(const QString& vcardid,const QString& messagedesc)
{
    emit MainApp::UIFrame::getConversationController()->sgUpdateRawHtmlElementStatus(vcardid,messagedesc);
}



void ChatCommObject::customCentextMenu(const QString& messageid,int selectOption)
{
    emit sgCustomCentextMenu(messageid,selectOption);
}

void ChatCommObject::frontsystemnotify( WebPage*webpage, const QString& notify )
{
    QString js =  QString(
        "PAGE_API.frontsystemnotify(\"" + notify + "\")") ;
    webpage->runLocalJavaScript(js);
}


void ChatCommObject::setVoicePlayed(WebPage* webPage,const QString& messageid)
{
    QString js =  QString(
        "setVoicePlayed(\"" + messageid + "\")") ;
    webPage->runLocalJavaScript(js);
}

void ChatCommObject::jsChangeIcon(WebPage*webframe, const QString& Jid, const QString&srcIcon )
{
    QString str = QString("changeuserIcon('%1','%2')").arg(Biz::MessageUtil::makeSureUserJid(Jid)).arg(srcIcon);
    webframe->runLocalJavaScript(str);

}

void ChatCommObject::jsChangeGroupMemberName(WebPage* webpage,const QString& jid,const QString& name)
{
    QString str = QString("changeusername('%1','%2')").arg(Biz::MessageUtil::makeSureUserJid(jid)).arg(name);
    webpage->runLocalJavaScript(str);
}

void ChatCommObject::jsInsertUnreadMessageTip(WebPage* webpage,const QSharedPointer<Biz::XmppMessage>& message)
{
    QJsonObject obj;
    obj.insert("direction", 1); // 在线消息
    QJsonArray msgs;
    msgs.append(innerInsertText(message));
    obj.insert("section", msgs);
    QJsonDocument doc(obj);

    auto a = doc.toJson().simplified();
    QString content = QString::fromUtf8(doc.toJson());

    QString jsCommend = QString("appendUnreadMesageTip(%1);").arg(content);

    webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsInsertUnreadMessageDownTip( WebPage* webpage,const QSharedPointer<Biz::XmppMessage>& message )
{
	QJsonObject obj;
	obj.insert("direction", 1); // 在线消息
	QJsonArray msgs;
	msgs.append(innerInsertText(message));
	obj.insert("section", msgs);
	QJsonDocument doc(obj);

	auto a = doc.toJson().simplified();
	QString content = QString::fromUtf8(doc.toJson());

	QString jsCommend = QString("appendUnreadMesageDownTip(%1);").arg(content);

	webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::deleteLastUnreadTip(WebPage* webpage)
{
    QString jsCommend = QString("removeElement('%1');").arg(MessageUnreadTip::sKey);
    webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::hideUpUnreadMessageTip()
{
    emit sgHideUpUnreadMessageTip();
}

void ChatCommObject::showUpUnreadMessageTip()
{
    emit sgShowUpUnreadMessageTip();
}

void ChatCommObject::updateMessageSendStatus(WebPage* webpage,const QString& messageid,int status)
{
    QString jsCommend = QString("updateMessageStatus('%1',%2);").arg(messageid,QString::number(status));
    webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsReSendMessage(const QString& message)
{
    if (!message.isEmpty())
        emit sgResendMessage(message);
}

void ChatCommObject::updateShareMessageInput(WebPage* webpage,bool visable)
{
    QString jsCommend = QString("setMessagesSelectable('%1');").arg(QString::number(visable));
    webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsShareSelectMessage(const QString&shareconversaionId,const QStringList& msgids)
{
    emit sgShareSelectMessage(shareconversaionId,msgids);
}

void ChatCommObject::shareSelectedMessages(const QString& shareconversationId,WebPage* webpage)
{
    QString jsCommend = QString("shareSelectMessages('%1');").arg(shareconversationId);
    webpage->runLocalJavaScript(jsCommend);
}


void ChatCommObject::appendMessageJavescripbyonemsg( WebPage* webPage, bool isHistroy, bool hasMore, const QList<QSharedPointer<Biz::XmppMessage>>& messages, int aotuscroll /*= 0*/ )
{
    if (1 == messages.size())
    {
        QSharedPointer<Biz::XmppMessage> spMessage = messages.at(0);
        if (Biz::revoke == spMessage->MsgSourceType())
        {
            QString strJs;
            bool bRet = MessageParser::getInstance()->getControlJavaScripte(spMessage, strJs);
            if (bRet)
            {
                webPage->runLocalJavaScript(strJs);
                return;
            }
        }
    }

    for(auto item : messages) {
        QJsonObject obj;
        obj.insert("hasHistory", /*hasMore ? 1 : 0*/1);
        obj.insert("direction", isHistroy ? 0 : 1);
        obj.insert("autoscroll", aotuscroll);
        Log::e("ChatCommObject::appendMessageJavescripbyonemsg " + item->MessageID());
        QJsonArray msgs;
        msgs.append(innerInsertText(item));
        obj.insert("section", msgs);
        QJsonDocument doc(obj);

        auto a = doc.toJson().simplified();
        QString content = QString::fromUtf8(doc.toJson());
        content = QString("PAGE_API.receive(") + content + QString(")");

        if (isHistroy)
        {
            webPage->runLocalJavaScript((QString("PAGE_API.review(") + QString::fromUtf8(doc.toJson()) + QString(")")));
        }
        else
        {
            webPage->runLocalJavaScript((QString("PAGE_API.receive(") + QString::fromUtf8(doc.toJson()) + QString(")")));
        }
    }
}

void ChatCommObject::jsShareSelectMessageCountChange(int ncount)
{
    emit sgShareSelectMessageCountChange(ncount);
}


void ChatCommObject::cleanHistroyRecordPage( WebPage* webPage )
{
	webPage->runLocalJavaScript("PAGE_API.cleanEmptyPage()");
}

void ChatCommObject::jsConversationDialogMesssageSelectedStatus(bool bshow)
{
     emit sgConversationDialogMesssageSelectedStatus(bshow);
}

void ChatCommObject::jshttpgetapicall( const QString&url )
{
	emit sghttpgetapicall(url);
}

void ChatCommObject::sendSignal(const QString& strjson, const QString& id)
{
	emit sgVideoSendSingnal(strjson, id);
	Log::e("ChatCommObject::sendSignal");
}

void ChatCommObject::closeRtcWindow(const QString&id)
{
	emit sgCloseRtcWindow(id);
	Log::e("ChatCommObject::sendSignal");
}

void ChatCommObject::WriteLocalLog(const QString&id, const QString&log)
{
	Log::wll(log);
	emit sgWriteLocalLog(id, log);
}

void ChatCommObject::jsGetScrollTop(const QString& conversationId, int pos)
{
	emit sgScrollTop(conversationId, pos);
}

void ChatCommObject::jsProblemListClick(const QString& infor)
{
	emit sgProblemLisClick(infor);
}

void ChatCommObject::jsOpenMeetingInfo(const QString& url)
{
	emit sgLookMeetingClick(url);
}

void ChatCommObject::jsProblemListMoreClick(const QString& msgId)
{
	emit sgProblemLisMoreClick(msgId);
}

void ChatCommObject::jsProblemListTakeUp(const QString& msgId)
{
	emit sgProblemListTakeUpClick(msgId);
}

void ChatCommObject::jsHintsClick(const QString&type, const QString&infor)
{
	emit sgHintsClick(type,infor);
}

void ChatCommObject::GetScrollTop(const QString& conversationId, WebPage* webPage )
{
	QString jsCommend = QString("getScrollpos('%1');").arg(conversationId);
	webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::setScollPos( int Pos, WebPage* webPage )
{
	QString jsCommend = QString("setScrollpos('%1');").arg(Pos);
	webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::updateMessageSendPicSrc( WebPage*webPage, const QString& msgid, const QString& newfilepath )
{
	QString strLocalfilePath;
	if (0 == newfilepath.indexOf("file:///",0,Qt::CaseInsensitive))
	{
		strLocalfilePath = newfilepath;
	}
	else
	{
		strLocalfilePath = "file:///" + newfilepath;
	}
	QString jsCommend = QString("updateMessageSendPicSrc('%1','%2');").arg(msgid,/*newfilepath*/strLocalfilePath);
	webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::setcounthtmlMsgCount( WebPage*webPage, int msgcount )
{
	QString jsCommend = QString("setcurrentPageMessageCount('%1')").arg(msgcount/*QString::number(msgcount)*/);
	webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsReplyWechatUser(const QString& messageid)
{
    emit sgReplyWechatUser (messageid);
}

void ChatCommObject::StartVideoSound(const QString&id)
{
	Log::e("ChatCommObject::StartVideoSound");
	emit sgStartVideoSound(id);
}
void ChatCommObject::StopVideoSound(const QString&id)
{
	Log::e("ChatCommObject::StopVideoSound");
	emit sgStopVideoSound(id);
}

void ChatCommObject::OpenUrlbyPc(const QString& url)
{
	Log::e(QString("ChatCommObject::OpenUrlbyPc url = %1").arg(url));
	emit sgOpenUrlbyPc(url);
}

void ChatCommObject::openUrl( const QString&url )
{
	//emit sgOpenUrl(url);
	emit sgOpenUrlbyPcWeb(url);
}

void ChatCommObject::TestRetParam()
{
	emit sgTestRetParam("123456");
}

void ChatCommObject::getCkey()
{
	QString strkey = WebService::getCKey();
	//emit sgsetCkey(strkey);

	QString jsCommend = QString("sgsetCkey('%1');").arg(strkey);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);

}

void ChatCommObject::getUserId()
{
	QString strNickname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(
		Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID()));
	QString userjid = Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID());
	//emit sgsetUserId(strNickname);
	QString jsCommend = QString("sgsetUserId('%1');").arg(userjid);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::getMyNick()
{
	QString strNickname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(
		Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID()));
	//emit sgsetUserId(strNickname);
	QString jsCommend = QString("sgsetMyNick('%1');").arg(strNickname);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::getRoomID()
{
	if (mRoomId.isEmpty())
	{
		return;
	}
	//emit sgsetRoomID(mRoomId);
	QString jsCommend = QString("sgsetRoomID('%1');").arg(mRoomId);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);
	mRoomId = "";
}

void ChatCommObject::getTopic()
{
	if (mTopic.isEmpty())
	{
		return;
	}
	//emit sgsetTopic(mTopic);
	QString jsCommend = QString("sgsetTopic('%1');").arg(mTopic);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);
	mTopic = "";
}

void ChatCommObject::getStartTime()
{
	Log::wll("getStartTime");
	if (mStarttm == 0)
	{
		return;
	}
	//emit sgsetStartTime(mStarttm);
	QString jsCommend = QString("sgsetStartTime(%1);").arg(mStarttm);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);
	mStarttm = 0;
}

void ChatCommObject::close_video_room(const QString& roomid)
{
	emit sgclose_video_room(roomid);
}

void ChatCommObject::jsgotoVideoRoom(const QString& msgid)
{
	if (msgid.isEmpty())
	{
		return;
	}

	emit sggotovideoRoom(msgid);
}

void ChatCommObject::getNickByUserId(const QString&id)
{
	QString strNickname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(id);
	QString jsCommend = QString("sgsetNickByUserId('%1', '%2');").arg(id, strNickname);
	if (mwebpage)
		mwebpage->runLocalJavaScript(jsCommend);


}

void ChatCommObject::enableFullScreen(const QString&roomid)
{
	emit sgfullScreen(roomid, true);


}

void ChatCommObject::cancelFullScreen(const QString&roomid)
{
	emit sgfullScreen(roomid, false);
}

void ChatCommObject::setVedioRoomParam(const QString&roomId, const QString&topic, quint64 starttm, WebPage*page)
{ 
	mRoomId = roomId; 
	mTopic = topic;  
	mStarttm = starttm; 
	mwebpage = page;
};

void ChatCommObject::setFullScreen(WebPage*webPage, bool bret)
{
	QString jsCommend = QString("setFullScreenStatus(%1);").arg(bret);
	if (webPage)
		webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::setStartVideoRoom(WebPage*webpage, const QString&roomid)
{
	QString jsCommend = QString("qtReady();");
	if (webpage)
		webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsMsgFindMaobyMsgid( WebPage *webPage, const QString& msgid, const QString& conversationId )
{
	if (msgid.isEmpty() || conversationId.isEmpty())
	{
		return;
	}

	QString jsCommend = QString("getCurrentHtmlInfobyMsgId('%1', '%2');").arg(msgid).arg(conversationId);
	if (webPage)
		webPage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsRetunfirstMsgid(const QString&msgatid, const QString&firstmsgid, const QString& conversationId )
{
	if (msgatid.isEmpty() || firstmsgid.isEmpty() || conversationId.isEmpty())
	{
		return;
	}

	emit sgReturnfirstMsgid(msgatid, firstmsgid, conversationId);
}


void ChatCommObject::loadCSS( WebPage*webpage )
{
	QString strcss = QString("/css/application.css"); 
	QString jsCommend = QString("PAGE_API.loadcss('%1');").arg(strcss);
	webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::loadJS( WebPage*webpage )
{
	QString strcss = QString("/css/application.js"); 
	QString jsCommend = QString("PAGE_API.loadjs('%1');").arg(strcss);
	webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::RobotSendMsg(const QString & conversationId, const QString& msg)
{
	//emit sgRobotSendMsg(conversationId, msg);
	MainApp::UIFrame::getConversationController()->sgRobotSendMsg(conversationId, msg);
}

void ChatCommObject::jsSetloadStatus(WebPage*webpage, int type )
{
	QString jsCommend = QString("setloadstatus(%1);").arg(type);
	if (webpage)
		webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsgetNoteEdit( const QString&infor )
{
	QString str = infor;
	emit sgSaveNote(infor);
}

void ChatCommObject::getNoteEditInfo( WebPage*webpage )
{
	QString jsCommend = QString("getData()");
	webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::appendNote( WebPage*webpage, const QString& NoteInfor )
{
	QString jsCommend = QString("appData('%1')").arg(NoteInfor);
	webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsSetMessageStatus( WebPage*webpage,const QString& msgId, const QString& statusText )
{
	QString jsCommend = QString("setMsgtatus('%1','%2');").arg(msgId).arg(statusText);
	if (webpage)
		webpage->runLocalJavaScript(jsCommend);
}

void ChatCommObject::jsSetStatusfontfamy( WebPage*webpage, const QString&fontfamy )
{
	QString jsCommend = QString("setStatusfontfamy('%1');").arg(fontfamy);
	if (webpage)
		webpage->runLocalJavaScript(jsCommend);
}

