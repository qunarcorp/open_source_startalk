#include "MessageFile.h"
#include <QFileIconProvider>
#include "XmppMessage.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "QFont"
#include "QFontMetrics"
#include "attachmentmanager.h"
#include "BizCallback.h"

 const int MYBYTE = 1024;
//<div style='height:1px;width:100%;background-color:#666666;'/>padding-left:4px;padding-top:px;
const QString FILE_RECV_MSG_HTML_TEMPLATE = 
	"<div style='background-color:#FFFFFF;border-radius:5px;border:1px soild #d1d1d1; '>"
	" <table width = 320px  style = \"table-layout: fixed;\"> "
    "     <tr> "
	"         <td rowspan='2' align='middle' style='vertical-align:middle;padding-left:5px;padding-top:5px;' width='45px' height='45px'> "
	"             <img width='40px' height='40px' style='padding:5px' src=\"%17\"/> "
    "         </td> "
	"         <td style='vertical-align:bottom;height:20px;padding-top:3px;padding-left:4px;'> "
	"             <span class='fileName' style=\"color:#000;font-size:13px;-webkit-user-select: text;\" >%11</span> "
    "         </td> "
    "     </tr> "
    "     <tr> "
    "         <td style='vertical-align:middle;padding-left:4px;'> "
    "             <span id='%3_TIP' class='fileTip' style=\"color:#000;font-size:13px;-webkit-user-select: text;\" >%2</span><progress id=\"%3_PROGRESS_BAR\" value=\"0\" max=\"1\" style=\"display:none;color:#000;font-size:13px\"/> "
    "         </td> "
    "     </tr> "
    "     <tr id='%3_SPIDERLINE' style='display:default'><td colspan='2' ><hr style=\"vertical-align:middle;height:1px;border:none;border-top:1px solid #d1d1d1;\"/></td></tr>"
	"     <tr id='%3_RECVPANEL' style='display:%9'><td colspan='2' ><table id='filecard'><tr>"
	"         <td id='%3_RECV' style='padding-right:10px; padding-left:5px;padding-bottom:3px;' onclick=%12><span style=\"font-size:11px;padding-left:8px;\">%4</span></td>"
    "         <td id='%3_IGNORE' style='padding-right:10px;padding-left:5px; padding-bottom:3px;' onclick=%13><span style=\"font-size:11px;\">%5</span></td>"
    "         </tr></table></td>"
    "     </tr>"
    "    <tr id='%3_RECVEDPANEL' style='display:%10'><td colspan='2' ><table id='filecard'><tr>"
    "        <td id='%3_OPEN' style='padding-left:8px;padding-right:10px;padding-bottom:3px;' onclick=%14 ><span style=\"font-size:11px;\">%6</span></td>"
    "        <td id='%3_OPENDIR' style='padding-right:10px;padding-bottom:3px;' onclick=%15><span style=\"font-size:11px;\">%7</span></td>"
    "        <td id='%3_SAVEOTHER' style='padding-right:10px;padding-bottom:3px;' onclick=%16><span style=\"font-size:11px;\">%8</span></td></tr></table></td>"
    "    </tr>"
    " </table> " 
	"</div>";

// 准备发送文件时的气泡
const QString FILE_SEND_MSG_HTML_TEMPLATE = 
	"<div style='background-color:#FFFFFF;border-radius:4px; border:1px soild #d1d1d1;' >"
    "<table width =320px style = \"table-layout: fixed; width: 320px max_height: 74px;\">\n"
    "    <tr> \n"
	"        <td rowspan='2' align='middle' style='vertical-align:middle;padding-left:2px;padding-top:5px;' width='45px' height='45px'> \n"
    "            <img width='40px' height='40px' src=\"%11\"/> \n"
    "        </td> \n"
    "        <td style='vertical-align:bottom;height:20px;padding-top:3px;padding-left:4px;margin-right:8px;'> \n"
    "            <span class='fileName' style='color:#000;font-size:13px;-webkit-user-select: text;'>%8</span>\n"
    "        </td> \n"
    "    </tr> \n"
    "    <tr> \n"
    "        <td style='vertical-align:middle;padding-left:4px;'> \n"
    "           <span id='%3_TIP' class='fileTip' style='color:#000;font-size:13px;-webkit-user-select: text;'>%2</span> "
    "           <span id='%3_ERR_TIP' class='fileTip' style='display: none;color:#000;font-size:13px;padding-left:8px;-webkit-user-select: text;'>%13</span>"
    "           <progress id=\"%3_PROGRESS_BAR\" value=\"0\" max=\"1\" style=\"display:none;color:#000;font-size:13px;\"/> \n"
    "        </td> \n"
    "    </tr> \n"
    "     <tr id='%3_SPIDERLINE' style='display:%7'><td colspan='2'><hr style=\"vertical-align:middle;height:1px;border:none;border-top:1px solid #d1d1d1;\"/></td></tr>\n"
    "     <tr id='%3_SENDPANEL' style='display:%6'><td colspan='2'><table id='filecard'><tr>\n"
	"         <td id='%3_SEND_BUTTON' style='padding-right:10px;padding-left:5px;padding-bottom:3px;' onclick=%9><span style=\"font-size:11px;padding-left:8px;\">%4</span></td>\n"
    "         <td id='%3_IGNORE' style='padding-right:10px;padding-left:5px;padding-bottom:3px;' onclick=%10><span style=\"font-size:11px;padding-bottom:5px;\">%5</span></td>\n"
    "         <td id='%3_RESEND_BUTTON' style='padding-right:10px;display: none;padding-bottom:3px;' onclick=%9><span style=\"font-size:11px;\">%12</span></td>\n"
    "         </tr></table></td>\n"
    "     </tr>\n"
    "</table> \n"
	"</div>";

MessageFile::MessageFile()
{

}

MessageFile::~MessageFile()
{

}

int MessageFile::getMessageMediaType()
{
    return Biz::MediaTypeFile;
}

bool MessageFile::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if(spMessage.isNull())
		return false;
    if (Biz::MessageDirection::MessageTypeSelf == spMessage->MsgDirection())
    {
        // 自己发送的文件 未发送，已发送两种状态，只能在右边
        if (spMessage->localUrls().size()==0)
        {
			if (isFileExist(spMessage))
			{
				// 已经接收了的文件
				return recvedFileFormat(spMessage,htmlString);
			}
			else
			{
				// 没有接收的文件
				return unrecvFileFormat(spMessage,htmlString);
			}
            // 已经发送了的历史消息重新加载
            // return sendedFileFormat(spMessage,htmlString);
        }
        else
        {
            // 本机的发送数据，临时的不入库
            return toSendFileFormat(spMessage,htmlString);
        }
    }
    else
    {
        // 接收来的数据，已经接收，没有接收两种状态，可能在左边也可能在右边
        if (isFileExist(spMessage))
        {
            // 已经接收了的文件
            return recvedFileFormat(spMessage,htmlString);
        }
        else
        {
            // 没有接收的文件
            return unrecvFileFormat(spMessage,htmlString);
        }
    }
    return false;
}

bool MessageFile::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[文件]");
    return true;
}

bool MessageFile::isFileExist(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString strMsgBody = spMessage->Body();

    QJsonDocument Json_Data = QJsonDocument::fromJson(strMsgBody.toUtf8());
    QVariantMap resultMap = Json_Data.toVariant().toMap();
    QString strUrl = "";
    if (resultMap.contains("HttpUrl"))
        strUrl = resultMap.value("HttpUrl").toString();
   
    if (!strUrl.isEmpty())
    {
        strUrl = Biz::ConfigureHelper::makeFullUrl(strUrl);
		//紧接着应该去 MESSAGE_ATTACHMENT 表查找是否有相应的信息，如果没有，返回false
		//QList<QSharedPointer<Biz::XmppMessageAttachment>> retlist;
		//ui线程直接取Biz线程中库里数据，存在安全问题
		//Biz::Session::getServiceManager ()->getDaoService ()->getMessageAttchment (strUrl,retlist);
		//Biz::Session::getServiceManager ()->getDaoService ()->getMessageAttchment (strUrl,retlist);
		//这个里面查找的附件是所有的附件，包括库中的附件
		//这地方必须去库里面查找，有可能重启后，内存中没有，但是库里面有，暂且这样
         QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
             Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (strUrl);
     
        if (!spAttach.isNull ())
// 		if(retlist.size()>0)
        {
            QString strfile = spAttach->LOCALCOPY ();
			//QString strfile =  retlist.at(0)->LOCALCOPY();
            strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
            return QFile::exists(strfile);
        }

		//

    }

    return false;
}

bool MessageFile::toSendFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if(spMessage.isNull())
		return false;
    QString guid        = spMessage->MessageID();
    QString localFile   = spMessage->localUrls().at(0);

    QFileInfo myfileInfo(localFile);
    qint64 qsize = myfileInfo.size();
  
    QString strfilesize;
    if (qsize < MYBYTE)
        strfilesize.sprintf("%.2fB", ((double)qsize));
    else if (qsize < MYBYTE*MYBYTE)
        strfilesize.sprintf("%.2fKB", ((double)qsize)/(MYBYTE));
    else
        strfilesize.sprintf("%.2fMB", ((double)qsize)/(MYBYTE*MYBYTE));

    QString fileName= myfileInfo.fileName();
    QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+fileName+".ico";

    QIcon fileIcon = QFileIconProvider().icon(myfileInfo);
    QPixmap iconPixmap = fileIcon.pixmap(QSize(40,40));
    if (!iconPixmap.isNull())
    {
        bool res = iconPixmap.save(fileIconSavePath);
        fileIconSavePath = QUrl::fromLocalFile(fileIconSavePath).toString();
    }

	
	
	QString elidedText = getCalcuteFileName(fileName);

    QString localname = QString(elidedText/*fileName*/).toHtmlEscaped();
    QString strSendButtonfun = QString("onSendbuttonclick(\"%1\",\"%2\")").arg(guid).arg("unused");

    QString clickfun = QString("onCancelclicked(\"%1\")").arg(guid);

    QString retString = QString(FILE_SEND_MSG_HTML_TEMPLATE)
        .arg(strfilesize)
        .arg(guid)
        .arg(QStringLiteral("发送文件"))   // 发送文案
        .arg(QStringLiteral("取消发送"))   // 取消文案
        .arg("default")
        .arg("default")
        .arg(localname, strSendButtonfun,clickfun,fileIconSavePath,
        QStringLiteral("重试"),QStringLiteral("发送失败"));
    htmlString = retString;
    return true;
}

bool MessageFile::sendedFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{

    if (spMessage.isNull())
        return false;

    QString strMsgBody = spMessage->Body();
    QJsonDocument Json_Data = QJsonDocument::fromJson(strMsgBody.toUtf8());
    QVariantMap resultMap = Json_Data.toVariant().toMap();

    if (!resultMap.contains("HttpUrl"))
        return false;

    QString strDownloadUrl  = resultMap.value("HttpUrl").toString();
    QString localFileName   = resultMap.value("FileName").toString();
    QString strSize         = resultMap.value("FileSize").toString();

    strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);

    // url  在本地的缓存文件
    QString strfile;
    QSharedPointer<Biz::XmppMessageAttachment> spAttach = 
        Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl(strDownloadUrl);
    if (!spAttach.isNull ())
    {
        strfile = spAttach->LOCALCOPY ();
        strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
    }
    


    // 算本地文件的图标计算路径
    QFileInfo myfileInfo(strfile);


    QIcon fileIcon = QFileIconProvider().icon(myfileInfo);
    QPixmap iconPixmap = fileIcon.pixmap(QSize(40,40));
    if (localFileName.isEmpty())
        localFileName = myfileInfo.fileName();
    QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+localFileName+".ico";
    if (!iconPixmap.isNull())
    {
        bool res = iconPixmap.save(fileIconSavePath);
        fileIconSavePath = QUrl::fromLocalFile(fileIconSavePath).toString();
    }

    // 算本地文件的大小
    if (strSize.isEmpty())
    {
        qint64 qsize = myfileInfo.size();
        if (qsize < MYBYTE)
            strSize.sprintf("%.2fB", ((double)qsize));
        else if (qsize < MYBYTE*MYBYTE)
            strSize.sprintf("%.2fKB", ((double)qsize)/(MYBYTE));
        else
            strSize.sprintf("%.2fMB", ((double)qsize)/(MYBYTE*MYBYTE));
    }

	

	QString elidedText = getCalcuteFileName(localFileName);

    QString localname = QString(elidedText/*localFileName*/).toHtmlEscaped();
    QString retString = QString(FILE_SEND_MSG_HTML_TEMPLATE)
        .arg(strSize) // tip
        .arg(spMessage->MessageID())
        .arg("")
        .arg("")
        .arg("none")
        .arg("none")
        .arg(localname,"","",fileIconSavePath,"","");
    htmlString = retString;
    return true;
}

bool MessageFile::unrecvFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    QString strMsgBody = spMessage->Body();
    QJsonDocument Json_Data = QJsonDocument::fromJson(strMsgBody.toUtf8());
    QVariantMap resultMap = Json_Data.toVariant().toMap();
  
    QString localFileName   = resultMap.value("FileName").toString();
    QString strSize         = resultMap.value("FileSize").toString();
    QString md5             = resultMap.value("FILEMD5").toString();

    QIcon fileIcon = Biz::ConfigureHelper::GetFileIcon(localFileName);
    QPixmap iconPixmap = fileIcon.pixmap(QSize(40,40));
 
    QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+localFileName+".ico";
    if (!iconPixmap.isNull())
    {
        bool res = iconPixmap.save(fileIconSavePath);
        fileIconSavePath = QUrl::fromLocalFile(fileIconSavePath).toString();
    }
   
	QString elidedText = getCalcuteFileName(localFileName);
    QString localname = QString(elidedText/*localFileName*/).toHtmlEscaped();
    QString downbuttonclick = QString("onDownbuttonclick(\"%1\",\"%2\")").arg(spMessage->MessageID(),md5);
    QString ignoreFun = QString("onRecvCancelclicked(\"%1\")").arg(spMessage->MessageID());
    QString searchclickfun = QString("onSearchbuttonclick(\"%1\")").arg(spMessage->MessageID()); // 打开文件夹
    QString openFile = QString("onOpenFileclick(\"%1\")").arg(spMessage->MessageID()); // 打开文件
    QString saveOther = QString("onSaveOther(\"%1\")").arg(spMessage->MessageID()); // 另存为

    QString retString = QString(FILE_RECV_MSG_HTML_TEMPLATE)
        .arg(strSize)
        .arg(spMessage->MessageID())
        .arg(QStringLiteral("接收文件"))
        .arg(QStringLiteral("忽略文件"))
        .arg(QStringLiteral("打开文件"))
        .arg(QStringLiteral("打开文件夹"))
        .arg(QStringLiteral("另存为..."))
        .arg("default")
        .arg("none")
        .arg(localname, downbuttonclick,ignoreFun,openFile,searchclickfun,saveOther,fileIconSavePath);
    htmlString = retString;
    return true;
}

bool MessageFile::recvedFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull())
        return false;

    QString strMsgBody = spMessage->Body();
    QJsonDocument Json_Data = QJsonDocument::fromJson(strMsgBody.toUtf8());
    QVariantMap resultMap = Json_Data.toVariant().toMap();

    if (!resultMap.contains("HttpUrl"))
        return false;

    QString strDownloadUrl  = resultMap.value("HttpUrl").toString();
    QString localFileName   = resultMap.value("FileName").toString();
    QString strSize         = resultMap.value("FileSize").toString();

    strDownloadUrl = Biz::ConfigureHelper::makeFullUrl(strDownloadUrl);

    // url  在本地的缓存文件
    QSharedPointer<Biz::XmppMessageAttachment> apAttach =
        Biz::Session::getAttachmentManager ()->getAttachmentInfoByUrl (strDownloadUrl);

    QString strfile;
    if (!apAttach.isNull ())
    {
        strfile = apAttach->LOCALCOPY ();
        strfile.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
    }

    // 算本地文件的图标计算路径
    QFileInfo myfileInfo(strfile);
   

    QIcon fileIcon = QFileIconProvider().icon(myfileInfo);
    QPixmap iconPixmap = fileIcon.pixmap(QSize(40,40));
    if (localFileName.isEmpty())
        localFileName = myfileInfo.fileName();
    QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+localFileName+".ico";
    if (!iconPixmap.isNull())
    {
        bool res = iconPixmap.save(fileIconSavePath);
        fileIconSavePath = QUrl::fromLocalFile(fileIconSavePath).toString();
    }

    // 算本地文件的大小
    if (strSize.isEmpty())
    {
        qint64 qsize = myfileInfo.size();
        if (qsize < MYBYTE)
            strSize.sprintf("%.2fB", ((double)qsize));
        else if (qsize < MYBYTE*MYBYTE)
            strSize.sprintf("%.2fKB", ((double)qsize)/(MYBYTE));
        else
            strSize.sprintf("%.2fMB", ((double)qsize)/(MYBYTE*MYBYTE));
    }

	QString elidedText = getCalcuteFileName(localFileName);
    QString localname       = QString(elidedText/*localFileName*/).toHtmlEscaped();
    QString msgid           = spMessage->MessageID();
    QString searchclickfun  = QString("onSearchbuttonclick(\"%1\")").arg(msgid); // 打开文件夹
    QString openFile        = QString("onOpenFileclick(\"%1\")").arg(msgid); // 打开文件
    QString saveOther       = QString("onSaveOther(\"%1\")").arg(msgid); // 另存为
    QString iconUrl         = QUrl(fileIconSavePath).toEncoded();
    QString retString       = QString(FILE_RECV_MSG_HTML_TEMPLATE)
        .arg(strSize)
        .arg(msgid)
        .arg("")
        .arg("")
        .arg(QStringLiteral("打开文件"))
        .arg(QStringLiteral("打开文件夹"))
        .arg(QStringLiteral("另存为..."))
        .arg("none")
        .arg("default")
        .arg(localname,"","",openFile,searchclickfun,saveOther,iconUrl);

    htmlString = retString;
    return true;
}

QString MessageFile::getCalcuteFileName( const QString& filename )
{
	QFont ft;
	ft.setFamily(QStringLiteral("宋体")); //默认是宋体
	ft.setPointSize(13); //html中设置的是13px号的字体
	QFontMetrics fm(ft);

	int nwidth = fm.width(filename);
	QString elidedText = fm.elidedText(filename, Qt::ElideMiddle, 300);//宽度是240
	return elidedText;
}
