#include "MessageVote.h"
#include "XmppMessage.h"
#include "Session.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "WebService.h"

const QString VOKE_BODY_HTML_TEMPLATE=
    "<a href='%5(\"%1\")'>		"
    "<table class='voke' >                       " 
    "	<tr>                                    " 
    "		<td rowspan='2' class='vokeimg' >   " 
	"		<img  src=\"%2\" align=\"middle\" >                   " 
    "		</td>                               " 
	"		<td style=\"vertical-align:bottom;padding-top:4px;\">      " 
	"		<p><span class='voketitle'>%3</p></span>" 
	"		</td>                                   " 
    "	</tr>                                   " 
    "	<tr>                                    " 
    "	<td style=\"vertical-align:middle;padding-bottom:4px;\"><span class='vokedesc'>%4</span>    " 
    "	</td>                                   " 
    "	</tr>                                   " 
    "	</table>                                " 
    "	</a>									" ;


const QString VOKE_BODY_HTML_TEMPLATE_PRO= 
    "<a id='unlimitlink' onclick='%5(\"%1\")'> <div class='unlimitlink selectable'> <img src='%2' class='titleimg'/><span class='titletext'>%3</span><span class='desctext' >%4</span></div> </a>";

MessageVote::MessageVote()
{

}

MessageVote::~MessageVote()
{

}

int MessageVote::getMessageMediaType()
{
    return Biz::MediaTypeVote;
}

bool MessageVote::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    QString strTitle;
    QString weburl;
    QString strimgurl;
    QString strDesc;
    bool    addAuth;
    bool    userSystemWebBrowser = false;
    bool    showAs667 = false;


    QString strExenInfor = spMessage->ExtendInfo();

    QByteArray ba;
    ba = strExenInfor.toUtf8();
    QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
    if(Json_Data.isObject())
    {
        QVariantMap strdata = Json_Data.toVariant().toMap();

        strTitle    = strdata["title"].toString();
        strDesc     = strdata["desc"].toString();
        strimgurl   = strdata["img"].toString();
        weburl      = strdata["linkurl"].toString();
        addAuth     = strdata["auth"].toBool();
        userSystemWebBrowser = strdata["use_sys_bsr"].toBool();
        showAs667   = strdata["showas667"].toBool();
    }
    else
    {
        return false;
    }

    if (!weburl.isEmpty())
    {
        QUrl url(weburl);
        QUrlQuery qu(url);
        if (Biz::GroupMessage == spMessage->MsgSourceType())
            qu.addQueryItem("group_id",spMessage->ConversationID());
        else
            qu.addQueryItem("user_id",spMessage->ConversationID());

        if (addAuth)
        {
            qu.addQueryItem("rk",WebService::sSecurityKey);
            qu.addQueryItem("username",Biz::Session::getAccountManager()->accountData().UserID());
        }

        url.setQuery(qu);
        weburl = url.toEncoded();
    }
   
	//展示就先写这两种方式的形式，因为是url展示的，
	//如果url都正确，但是这张图片确实在服务器上没有了，那就瞎了
	if (strimgurl.isEmpty() || QUrl(strimgurl).scheme().isEmpty())
	{
		strimgurl = "./image/vote.png";
	}
	if (strTitle.isEmpty())
	{
		strTitle = weburl;
	}
	if (strDesc.isEmpty())
	{
		strDesc = QStringLiteral("点击查看全文 ");
	}

    QString openProxy = userSystemWebBrowser?"javascript:CLIENT_API.openUrl":"javascript:CLIENT_API.openNewLink"; 

    if (weburl.isEmpty())
        openProxy.clear();

    htmlString = QString(showAs667?VOKE_BODY_HTML_TEMPLATE_PRO:VOKE_BODY_HTML_TEMPLATE).arg(weburl,strimgurl,strTitle,strDesc,openProxy);

    return true;
}

bool MessageVote::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[分享链接]");
    return true;
}

int MessageVotePro::getMessageMediaType()
{
    return Biz::MediaTypeVotePro;
}

bool MessageVotePro::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    QString strTitle;
    QString weburl;
    QString strimgurl;
    QString strDesc;
    bool    addAuth;
    bool    userSystemWebBrowser;


    QString strExenInfor = spMessage->ExtendInfo();

    QByteArray ba;
    ba = strExenInfor.toUtf8();
    QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
    if(Json_Data.isObject())
    {
        QVariantMap strdata = Json_Data.toVariant().toMap();

        strTitle    = strdata["title"].toString();
        strDesc     = strdata["desc"].toString();
        strimgurl   = strdata["img"].toString();
        weburl      = strdata["linkurl"].toString();
        addAuth     = strdata["auth"].toBool();
        userSystemWebBrowser = strdata["use_sys_bsr"].toBool();
    }
    else
    {
        return false;
    }

    if (!weburl.isEmpty())
    {
        QUrl url(weburl);
        QUrlQuery qu(url);
        if (Biz::GroupMessage == spMessage->MsgSourceType())
            qu.addQueryItem("group_id",spMessage->ConversationID());
        else
            qu.addQueryItem("user_id",spMessage->ConversationID());

        if (addAuth)
        {
            qu.addQueryItem("rk",WebService::sSecurityKey);
            qu.addQueryItem("username",Biz::Session::getAccountManager()->accountData().UserID());
        }

        url.setQuery(qu);
        weburl = url.toEncoded();
    }
   

    if (strimgurl.isEmpty())
    {
        strimgurl = "html/image/vote.png";
    }
    if (strTitle.isEmpty())
    {
        strTitle = weburl;
    }
    if (strDesc.isEmpty())
    {
        strDesc = QStringLiteral("点击查看全文 ");
    }

    QString openProxy = userSystemWebBrowser?"javascript:CLIENT_API.openUrl":"javascript:CLIENT_API.openNewLink"; 

    if (weburl.isEmpty())
        openProxy.clear();
    
    htmlString = QString(VOKE_BODY_HTML_TEMPLATE_PRO).arg(weburl,strimgurl,strTitle,strDesc,openProxy);

    return true;
}

bool MessageVotePro::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[外部链接]");
    return true;
}

MessageVotePro::MessageVotePro()
{

}

MessageVotePro::~MessageVotePro()
{

}
