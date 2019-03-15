#include "MessageNormalChat.h"
#include "XmppMessage.h"
#include "ImageHelper.h"
#include "SpellHelper.h"
#include "accountmanager.h"
#include "UserVcardManager.h"
#include "AccountData.h"
#include "Session.h"
#include <QUuid>
#include "GroupChatDialog.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "GroupVisitorMVD.h"
#include "Account.h"

const int sMediaType = Biz::MediaTypeText; 
MessageNormalChat::MessageNormalChat()
{

}

MessageNormalChat::~MessageNormalChat()
{
}

int MessageNormalChat::getMessageMediaType()
{
    return sMediaType;
}

bool MessageNormalChat::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (!spMessage.isNull())
    {
        htmlString = objectToHtml(spMessage);
        htmlString.replace(8232,'\n'); // --> 软回车变成硬回车
        htmlString = parseAtInfo (spMessage,htmlString);
        // 替换@信息
        return true;
    }
    return false;
}

bool MessageNormalChat::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& translatedBody)
{

    if (spMessage.isNull())
        return false;
    do 
    {
        int nMediaType = spMessage->MediaType();
        if (nMediaType == Biz::MessageMediaType::MediaTypeText)
        {
            // 过滤掉文本消息的object
            QString strResult = spMessage->Body();
            QRegExp regExp("\\[obj type=[\\\\]?\"(.*)[\\\\]?\" value=[\\\\]?\"(.*)[\\\\]?\"(.*)\\]");    
            regExp.setMinimal(true);

            QStringList xslist;

            auto pos = 0;
            while ((pos = regExp.indexIn(strResult, pos)) != -1) 
            {
                int np = pos;
                QString item = regExp.cap(0);
                QString type = regExp.cap(1);
                QString val = regExp.cap(2);        
                QString extPart = regExp.cap(3);
                if(type == "image")
                {
                    strResult = strResult.replace(item,QStringLiteral("[图片]"));
                    pos += QStringLiteral("[图片]").length();
                }else if(type == "emoticon")
                {
                    // 用表情源码
                    strResult = strResult.replace(item,val);
                    pos += val.length();

                } else if(type == "url")
                {
                    strResult = strResult.replace(item,QStringLiteral("[链接]"));
                    pos += QStringLiteral("[链接]").length();
                } else {
                    Log::e("MessageHelper::TranslateShortMsgBody error raw" +spMessage->Body() );
                    translatedBody = strResult;
                    break;
                }
            }  
            translatedBody = strResult;

            break;
        }
		if(nMediaType == Biz::MessageMediaType::MediaTypeImage)
		{
			translatedBody = QStringLiteral("[图片]");
			break;
		}

        if (nMediaType == Biz::MessageMediaType::MediaTypeVoice)
        {
            translatedBody = QStringLiteral("[声音]");
            break;
        }

        if (nMediaType == Biz::MessageMediaType::MediaTypeFile)
        {
            translatedBody = QStringLiteral("[文件]");
            break;
        }

        if (nMediaType==Biz::MessageMediaType::MediaTypeShockAndPostBackCookie)
        {
            if (spMessage->MsgSourceType()==Biz::subscription)
            {
                translatedBody = QStringLiteral("[公众账号消息]");
            }
            else
            {
                translatedBody = QStringLiteral("[震动]");
            }

        }

		if (nMediaType == Biz::MessageMediaType::MessageTypeAt)
		{
			//translatedBody = spMessage->Body();

			// 过滤掉文本消息的object
			QString strResult = spMessage->Body();
			QRegExp regExp("\\[obj type=[\\\\]?\"(.*)[\\\\]?\" value=[\\\\]?\"(.*)[\\\\]?\"(.*)\\]");    
			regExp.setMinimal(true);
			//这地方先把body 中的值给替换过来

			QString backupInfor = spMessage->BackupInfo();
			QMap <QString, QString> jidtext;

			//backupinfor 解析出来
			QJsonDocument doc = QJsonDocument::fromJson (backupInfor.toUtf8 ());
			QVariantList vl = doc.toVariant ().toList ();
			for (QVariant vv:vl)
			{
				QVariantMap vm = vv.toMap ();

				QVariantList data = vm["data"].toList();

				for (QVariant datav: data)
				{
					QVariantMap datamap = datav.toMap();
					jidtext.insert(datamap["jid"].toString(), datamap["text"].toString());
				}
			}


			for (QString strkey: jidtext.keys())
			{
				QString strText = jidtext.value(strkey);
				if (strText.compare("all",Qt::CaseInsensitive) == 0)
				{
					continue;
				}

				QString strDisplay = Biz::Session::currentAccount().getUserMarkNameByJId(strkey);

				if ((!strText.isEmpty() && !strDisplay.isEmpty()) && strText != strDisplay)
				{
					if (strResult.contains("@" + strText))
					{
						strResult.replace( "@"+strText, "@"+strDisplay);
					}
					else if (strResult.contains("＠" + strText))
					{
						strResult.replace( "＠"+strText, "＠"+strDisplay);
					}

					//spMessage->Body(strResult);
				}

			}





			QStringList xslist;

			auto pos = 0;
			while ((pos = regExp.indexIn(strResult, pos)) != -1) 
			{
				int np = pos;
				QString item = regExp.cap(0);
				QString type = regExp.cap(1);
				QString val = regExp.cap(2);        
				QString extPart = regExp.cap(3);
				if(type == "image")
				{
					strResult = strResult.replace(item,QStringLiteral("[图片]"));
					pos += QStringLiteral("[图片]").length();
				}else if(type == "emoticon")
				{
					// 用表情源码
					strResult = strResult.replace(item,val);
					pos += val.length();

				} else if(type == "url")
				{
					strResult = strResult.replace(item,QStringLiteral("[链接]"));
					pos += QStringLiteral("[链接]").length();
				} else {
					Log::e("MessageHelper::TranslateShortMsgBody error raw" +spMessage->Body() );
					translatedBody = strResult;
					break;
				}
			}  
			translatedBody = strResult;
		}

        if (nMediaType == Biz::MediaTypeRichText
            || nMediaType == Biz::MediaTypeActionsRichText
            || nMediaType == Biz::MediaTypeClientCookie)
        {
            translatedBody = QStringLiteral("[公众账号消息]");
        }

    } while (false);

    return true;
}


const static QString objectTypeImage    = "image";
const static QString objectTypeUrl      = "url";
const static QString objectTypeEmotion  = "emoticon";



QString AttachInforToJson(int w, int h, const QString& url)
{
    QString strReturn;
    QJsonObject obj;
    obj.insert("width", w);
    obj.insert("heigh", h);
    obj.insert("url", url);
    QJsonDocument doc(obj);
    strReturn = QString::fromUtf8(doc.toJson());
    return strReturn;
}



QString decodeUrl(QString body, QMap<QString,QString>& guid2htmlstring)
{

    QString strResult = body;
    QRegExp regExp("(((ftp|https?)://|www.)[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})([^ ^\"^\\[^\\]^\\r^\\n]*))");    
    auto pos = 0;
    while ((pos = regExp.indexIn(body, pos)) != -1) {
        QString url = regExp.cap(0);
        QString rawUrl = QUrl(url).toEncoded();
        QString htmlString = QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,url.toHtmlEscaped());

        QString guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
        guid2htmlstring.insert(guid,htmlString);
        strResult.replace(strResult.indexOf(url),url.length(),guid);
        pos += regExp.matchedLength();
    }    

    return strResult;    
}


#include "UtilHelper.h"
#include "ConfigureHelper.h"
#include "Player.h"
#include "SystemDefine.h"
#include "Session.h"
#include "DownloadManager.h"
#include "EmotionManager.h"
#include "attachmentmanager.h"
#include "SystemConfigData.h"

QString MessageNormalChat::objectToHtml(QSharedPointer<Biz::XmppMessage>& rawmsg)
{
	if (rawmsg.isNull())
	{
		return "";
	}
	QString strRawMsgBody = rawmsg->Body();
    QRegExp regExp("\\[obj type=[\\\\]?\"([^\"]*)[\\\\]?\" value=[\\\\]?\"([^\"]*)[\\\\]?\"(.*)\\]");    
    regExp.setMinimal(true);

    QStringList strHtmllist;
    // 把obj片段先匹配成 uuid ,然后将uuid匹配成 <a> 等标签,为了防止特殊字符带来的解析干扰
    QMap<QString,QString> item2Guid;
    QMap<QString,QString> guid2Html;

    auto pos = 0;
    while ((pos = regExp.indexIn(strRawMsgBody, pos)) != -1) 
    {
        QString item    = regExp.cap(0); // 符合条件的整个字符串  
        QString type    = regExp.cap(1); // 多媒体类型
        QString val     = regExp.cap(2); // 路径
        QString extPart = regExp.cap(3); // 宽高

        // 替换的key
        QString replaceKey = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", ""); 

        if(type == objectTypeImage) {
#pragma region imagePaser
            QSharedPointer<Biz::XmppMessageAttachment> attachInfo(new Biz::XmppMessageAttachment);
				QSharedPointer<Biz::ImageAttachInfor> imageattachInfor(new Biz::ImageAttachInfor);
            // 条件貌似写多了，只有图片才需要更改前缀，备忘。added by may
            QString strFullUrl = Biz::ConfigureHelper::makeFullUrl(val);
			//这地方不能用rawmsg->MessageID(),原因是一条消息中，可能有多张图片，这样就不对了
            QString strImageId = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
            attachInfo->URL(strFullUrl);
            attachInfo->MD5(strImageId);
			attachInfo->MessageID(rawmsg->MessageID());
	        imageattachInfor->Imagetime(rawmsg->UtcTime());
			imageattachInfor->UrlPath(strFullUrl);
			imageattachInfor->ImageId(strImageId);

            if (QFile::exists(val))
			{
                attachInfo->LOCALCOPY(strFullUrl);
				imageattachInfor->LocalPath(strFullUrl);
			}

            QString htmlString ;

            int w=0;int h=0;
            if (!extPart.isEmpty())
            {

                QRegExp regSizeExp("width=(\"?.*\"?) *height=(\"?.*\"?)");
                int regpos = regSizeExp.indexIn(extPart,0);
                if (-1!=regpos)
                {
                    w = regSizeExp.cap(1).toDouble();
                    h = regSizeExp.cap(2).toDouble();
                    Biz::ImageHelper::getImageScaleSize (w,h, maxImageWidth, maxImageHeigh);
                }
				attachInfo->WidthOfCompress(w);
				attachInfo->HeightOfCompress(h);
            }

            // 看看本地有没有
			QString savefileName = Biz::ConfigureHelper::getImageLocalSavePath(strFullUrl,Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()));
			//QString savefileName = Biz::Session::getDownLoadManager()->getImageLocalSavePath(strFullUrl,Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()));
			attachInfo->LOCALCOPY(QFile::exists(savefileName)?savefileName:"");
            imageattachInfor->LocalPath(QFile::exists(savefileName)?savefileName:"");

			//插入这些附件的信息
			Biz::Session::getAttachmentManager()->insertImageAttachInfor(rawmsg->ConversationID(), imageattachInfor);
			Biz::Session::getAttachmentManager()->downloadAttachImage(rawmsg->ConversationID(), attachInfo);
			

			QUrl ul(strFullUrl);
			QUrlQuery qu(ul);
			QString imgFormat = QFileInfo(savefileName).suffix();
			if (0!= imgFormat.compare("gif",Qt::CaseInsensitive)
				&& 0!=h
				&& 0!=w)
			{
				qu.addQueryItem("w",QString::number(w));
				qu.addQueryItem("h",QString::number(h));
			}
			qu.addQueryItem("u",Biz::Session::getServiceManager()->getHttpService()->getUser());
			qu.addQueryItem("k",Biz::Session::getServiceManager()->getHttpService()->getTkey());
			ul.setQuery(qu);
			strFullUrl = ul.toString() + "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-",""); //在url后，加上一个随机值，为了让图像展示时，不去缓存中取同一个值

			htmlString = QString("<img data-opentool='viewer' data-imgid='%2' id='%2' src='%1' onerror='LoadImgFail(id)' %3/>").arg(strFullUrl,strImageId,w>0?QString(" width='%1' height='%2' ").arg(w,h):"");

			item2Guid.insert(item,replaceKey);
			guid2Html.insert(replaceKey,htmlString);

			strHtmllist.append(htmlString);
			// 只匹配item匹配到的长度，防止重复的obj被一把替换
			strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);

#pragma endregion imagePaser
		} else if(objectTypeEmotion == type) {
            QString pkgid;
            if (!extPart.isEmpty())
            {
                QRegExp regSizeExp("width=([^ ]*)");
                int regpos = regSizeExp.indexIn(extPart,0);
                if (-1!=regpos)
                {
                    pkgid = regSizeExp.cap(1);
                }
            }

            QSharedPointer<Biz::EmotionItem> spItem = Biz::Session::getEmoticonManager()->findEmoticon(pkgid,val);
            if (!spItem.isNull())
            {
                QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
                QString htmlString = QString("<img src='file:///%1' alt='%2' />").arg(spItem->strPath + "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","")
					,spItem->shortcut);
                strHtmllist.append(htmlString);

                item2Guid.insert(item,replaceKey);
                guid2Html.insert(replaceKey,htmlString);
                strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
            }
            else
            {
                QString shutKey = val;
                shutKey.replace("[","").replace("]","").replace("/","");
                QString strUrl = QString("%1/file/v2/emo/d/e/%2/%3/%4").arg(Biz::Session::getSystemConfig()->getHttpFileHost(),
                    pkgid,
                    shutKey,
                    "org");

                QUrl ul(strUrl);
                QUrlQuery qu(ul);
                qu.addQueryItem("u",Biz::Session::getServiceManager()->getHttpService()->getUser());
                qu.addQueryItem("k",Biz::Session::getServiceManager()->getHttpService()->getTkey());
                ul.setQuery(qu);
                

                QString htmlString = QString("<img id='%3' src='%1' alt='%2' onerror='nofind(id);'>").arg(
                    QUrl(ul.toString()).toEncoded() + "?" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-",""),
                    val,
                    replaceKey
                    );

                strHtmllist.append(htmlString);
                item2Guid.insert(item,replaceKey);
                guid2Html.insert(replaceKey,htmlString);
                strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);

                QSharedPointer<Biz::XmppMessageAttachment> attachInfo(new Biz::XmppMessageAttachment);
                // 条件貌似写多了，只有图片才需要更改前缀，备忘。added by may
                QString strFullUrl = Biz::ConfigureHelper::makeFullUrl(strUrl);
                QString strImageId = Biz::ConfigureHelper::GetBufferMD5 (strUrl);
                attachInfo->URL(strFullUrl);
                attachInfo->MD5(strImageId);
                QString localDir = Biz::ConfigureHelper::UserTempPath(Biz::Session::getAccountManager()->accountData().UserID());
                QString  subDir = Biz::SpellHelper::MakeSpellCode(Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()),( Biz::SpellHelper::SpellOptions)0).trimmed();
                localDir += subDir;
                QString savefileName = QFileInfo(QDir(localDir),strImageId).absoluteFilePath ();
                attachInfo->LOCALCOPY(QFile::exists(savefileName)?savefileName:"");


                //插入这些附件的信息
                Biz::Session::getAttachmentManager()->downloadAttachImage(rawmsg->ConversationID(),attachInfo);
            }
        } else if( objectTypeUrl == type) {
#pragma region linkparser
            QString rawUrl = QUrl(val).toEncoded();
            QString htmlString = QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,val.toHtmlEscaped());
            strHtmllist.append(htmlString);

            item2Guid.insert(item,replaceKey);
            guid2Html.insert(replaceKey,htmlString);
            strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
#pragma endregion linkparser
        }
        pos += replaceKey.length();
    }  
	if (rawmsg->MediaType() != Biz::MessageTypeMarkdown)
	{
		 strRawMsgBody = decodeUrl(strRawMsgBody,guid2Html);
	}
   

	if (rawmsg->MediaType() != Biz::MessageTypeMarkdown)
	{
		strRawMsgBody = strRawMsgBody.toHtmlEscaped();
		strRawMsgBody = strRawMsgBody.replace(" ","&nbsp;");
		strRawMsgBody = strRawMsgBody.replace("\r\n","<br/>");
		strRawMsgBody = strRawMsgBody.replace("\n","<br/>");
	}
    

    foreach(QString key,guid2Html.keys()){
        strRawMsgBody.replace(key,guid2Html.value(key));
    }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))

	//这地方给判断一下是否是代码高亮
	if (rawmsg->MediaType() == Biz::MediaTypeCodeHLight)
	{
		
		QString strexterninfo= rawmsg->ExtendInfo();

		QJsonDocument Json_Data = QJsonDocument::fromJson(strexterninfo.toUtf8());
		QVariantMap result = Json_Data.toVariant().toMap();
		QString strCode = result["CodeDecode"].toString();
		QString strCodeType = result["CodeType"].toString();
		QString strCodeStyle = result["CodeStyle"].toString();


		return UtilHelper::getHightLightCodeString(strRawMsgBody, rawmsg->MessageID(), strCodeStyle, strCodeType);
	}

#endif
	
	
	
    return strRawMsgBody;
}

QString MessageNormalChat::parseAtInfo(const QSharedPointer<Biz::XmppMessage>& spMessage,const QString& htmlstr)
{
    if (spMessage.isNull () || Biz::MessageTypeSelf == spMessage->MsgDirection ())
        return htmlstr;
    QString retStr = htmlstr;
	//if (spMessage->MediaType() == Biz::MessageTypeAt) //为了兼容之前的老版本，这地方先不给判断
	{
		if (!spMessage->BackupInfo().isEmpty())
		{
			QString backupinfo = spMessage->BackupInfo();
			QJsonDocument doc = QJsonDocument::fromJson(backupinfo.toUtf8());
			QVariantList types = doc.toVariant().toList();
			QMap<QString,QVariantList> typeMaps;
			for (QVariant type:types)
			{
				QVariantMap typeMap = type.toMap();
				if (typeMap.contains("type") && !typeMap.value("data").toList().isEmpty())
				{
					typeMaps.insert(typeMap.value("type").toString(),typeMap.value("data").toList());
				}
			}

			if (typeMaps.contains(QString::number(Biz::CHATTYPEATINFO)))
			{
 				QMap<QString,QString> replaceMap;

				for (QVariant atInfo:typeMaps.value(QString::number(Biz::CHATTYPEATINFO)))
				{
					if (!atInfo.toMap().value("jid").toString().isEmpty() && !atInfo.toMap().value("text").toString().isEmpty() )
					{
						QString jid = atInfo.toMap ().value ("jid").toString ();
						if (0!=jid.compare("all",Qt::CaseInsensitive) && !Biz::MessageUtil::compareJid (jid,Biz::Session::getAccountManager()->accountData ().UserID ()))
							continue;

						QString text = atInfo.toMap ().value ("text").toString ();
						QString strValue =  Biz::Session::currentAccount().getUserMarkNameByJId(jid);
						
						if (text.compare(strValue, Qt::CaseInsensitive) != 0)
						{
							text = strValue;
						}
						if (retStr.contains ("@"+text))
						{
							
							QString replaceKey = QUuid::createUuid ().toString ();
							retStr.replace("@"+text,replaceKey);
							QString htmlcode = QString("<span data-atid='%1' data-use='at' class='atinfonomal'>%2</span>").arg (spMessage->MessageID(),"@"+text);
							replaceMap.insert (replaceKey,htmlcode);
						} else if (retStr.contains ("＠" + text))
						{
							QString replaceKey = QUuid::createUuid ().toString ();
							retStr.replace("@"+text,replaceKey);
							QString htmlcode = QString("<span data-atid='%1' data-use='at' class='atinfonomal'>%2</span>").arg (spMessage->MessageID(),"@"+text);
							replaceMap.insert (replaceKey,htmlcode);
						}

						for (QString key:replaceMap.keys ())
						{
							retStr.replace (key,replaceMap.value (key));
						}
					}
				}
			}
		}
		else
		{
			QString body = spMessage->Body();
			QString userJid = Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID()); 
			QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(userJid);

			QString fullName = Biz::Session::getAccountManager()->accountData().FullName();
			QStringList searchList;
			if (!fullName.isEmpty() && !searchList.contains(fullName))
				searchList.append(fullName);

			if (!spPerson.isNull() 
				&& !spPerson->strNickName.isEmpty() 
				&& !searchList.contains(spPerson->strNickName))
				searchList.append(spPerson->strNickName);

			if (!spPerson.isNull() 
				&& !spPerson->strWebName.isEmpty() 
				&& !searchList.contains(spPerson->strWebName))
				searchList.append(spPerson->strWebName);

			searchList.append ("all");

			QMap<QString,QString> replaceMap;

			for(QString searchText : searchList)
			{
				QString text = searchText;
				if (retStr.contains ("@"+text))
				{
					QString replaceKey = QUuid::createUuid ().toString ();
					retStr.replace("@"+text,replaceKey);
					QString htmlcode = QString("<span data-atid='%1' data-use='at' class='atinfonomal'>%2</span>").arg (spMessage->MessageID(),"@"+text);
					replaceMap.insert (replaceKey,htmlcode);
				} else if (retStr.contains ("＠" + text))
				{
					QString replaceKey = QUuid::createUuid ().toString ();
					retStr.replace("@"+text,replaceKey);
					QString htmlcode = QString("<span data-atid='%1' data-use='at' class='atinfonomal'>%2</span>").arg (spMessage->MessageID(),"@"+text);
					replaceMap.insert (replaceKey,htmlcode);
				}

				for (QString key:replaceMap.keys ())
				{
					retStr.replace (key,replaceMap.value (key));
				}
			}
		}
	}
    return retStr;
}

