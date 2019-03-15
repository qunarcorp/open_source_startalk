#include "BaseChatDialog.h"

#include "Log.h"

#include <QCoreApplication>
#include <QTextBlock>
#include <QKeyEvent>
#include <QComboBox>
#include <QXmppUtils.h>
#include <QAudioFormat>
#include <QFileIconProvider>
#include <QFileDialog>
#include <QClipboard> 
#include "SpellHelper.h"
#include "TextEdit.h"
#include "ui_instance.h"
#include "imageviewer.h"
#include "CallbackReceiver.h"
#include "Session.h"
#include "Account.h"
#include "ConfigureHelper.h"
#include "AccountData.h"

#ifndef Q_NO_AMR
#include "amrgit/AudioPlayer.h"
#endif //Q_NO_AMR


#include "SystemConfigData.h"
#include "LanguageHelper.h"
#include "SettingData.h"
#include <QDomDocument>
#include <QDomElement>
#include "RosterListWidget.h"
#include "UtilHelper.h"
#include "SystemDefine.h"

#include "EmotionManager.h"
#include "EmotionTabDialog.h"

#include "DownloadManager.h"
#include "attachmentmanager.h"

#include "ImageHelper.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"
#include "NotifyCenterController.h"

#include "ChatWebPage.h"
#include "ChatCommObject.h"
#include "conversationmanager.h"
#include "loginmanager.h"
#include "webview.h"
#include "MessageManager.h"
#include "messagebubble/wrapper/MessageDecoraterBubbleWrapperSelf.h"
#include "CloseableButtonView.h"

#include "conversationselectwidget.h"

#include <iostream>
using namespace std;

#include "diywidgit/htmlparser/ParserDom.h"
#include "diywidgit/htmlparser/utils.h"
#include "diywidgit/htmlparser/Node.h"
using namespace htmlcxx;

#include "Session.h"
#include "attachmentmanager.h"
#include "editablesettings.h"

#include "Ordermanagedialog.h"
#include "jsonobject/messagefileextendsobject.h"
#include "portraithelper.h"
#include "vidioandaudiodialog.h"

#include "UserVcardManager.h"
#include "aescommon.h"
#include "GroupManager.h"
#include <QDesktopServices>
#include "ChatDisplayOptionWidget.h"
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
#include <QWebPage> 
#include <QWebInspector>
#else
#include <QtWebEngineWidgets/QWebEnginePage>
#endif

#include "WebService.h"
#include "SendProductCardDialog.h"
#include "AccountManager.h"
#include <QtConcurrent/QtConcurrent>

const static QString objectTypeImage    = "image";
const static QString objectTypeUrl      = "url";
const static QString objectTypeEmotion  = "emoticon";

const int MYBYTE = 60240;
const quint32 SENDCHART = 1024*1024;


enum ThrMimeDataFormatType {
	MimeDataFormatType_Text = 0,
	MimeDataFormatType_Img  = 1
};

void BaseChatDialog::linkClicked(const QUrl &url) {
	QString urlStr = url.toString(); 
	this->onBaseOpenUrl(urlStr); 
}

BaseChatDialog::BaseChatDialog(QWidget *parent)
	: QWidget(parent)
	, currentImageSrc("")
	, currentImageurlSrc("")
	, m_sConversationID("")
	, textEdit(NULL)
	, MaxRecentMessageLimit(10)
	, mPage(NULL)
	, mPWebView(NULL)
	, mCommObject(new ChatCommObject(this))
	, mpUpUnread(new CloseableButtonView(this))
	, mpAtNotice(new CloseableButtonView(this))
	, m_bWebShereMessageSelectStatus(false)
	,mbhover(false)
	,m_bSelfWebCopy(false)
	,PastTextmimeData(NULL)
	,m_codehightlight(false)
	,mChatType(NormalChatType)
	,mMarkdown(false)
	,m_noticeInfotipGlobal(NULL)
	,m_noticeInfotipAppoint(NULL)
{
	mspline = "-------------------------";
	mActionWebViewSaveAs        = NULL;
	mWebViewMenu                = NULL;
	mActionWebViewSeleAll       = NULL;
	mActionWebViewCopy          = NULL;
	mActionWebSaveAsCustomEmoj  = NULL;
	mACtionWebReferenceMessage = NULL;

	bm_bIsSeat = false;
	m_pShareToButton = new CloseableButtonView(this);
	receiver = new Biz::CallbackReceiver(this);
	m_bWebLoadFinshed = false;
	m_voiceImagesTimer.setDuration(500);
	m_voiceImageIndex = 0;
	connect(&m_voiceImagesTimer,&QTimeLine::finished,[this](){
		onUpdateVoiceImage(m_messageid,m_voiceImagesLst.at(m_voiceImageIndex));
		m_voiceImageIndex++;
		m_voiceImageIndex = m_voiceImageIndex % m_voiceImagesLst.size();
		m_voiceImagesTimer.start();
	});


	connect(EmotionTabDialogSingleton::getInstance(), &EmotionTabDialog::sgSelectItem, this, &BaseChatDialog::onSelectEmotion);
	connect(EmotionTabDialogSingleton::getInstance(), &EmotionTabDialog::sgSendImage, this,&BaseChatDialog::onEmojImageSelected);
	connect(EmotionTabDialogSingleton::getInstance(), &EmotionTabDialog::sgSendUrlImage,this,&BaseChatDialog::onEmojUrlImageSelected);

	connect(mCommObject, &ChatCommObject::sgImageClicked, this, &BaseChatDialog::onImageClicked);
	connect(mCommObject, &ChatCommObject::sgImageDbClicked, this, &BaseChatDialog::onImageDbClicked);
	connect(mCommObject, &ChatCommObject::sgSpaceClicked, this, &BaseChatDialog::onSpaceClicked);
	connect(mCommObject, &ChatCommObject::sgOpenVoice, this, &BaseChatDialog::onVoicePlay);
	connect(mCommObject, &ChatCommObject::sgOpenFile, this, &BaseChatDialog::onOpenfile);
	connect(mCommObject, &ChatCommObject::sgOpenFilePath, this, &BaseChatDialog::onOpenfilePath);
	connect(mCommObject, &ChatCommObject::sgSaveAs, this, &BaseChatDialog::onSaveAs);
	connect(mCommObject, &ChatCommObject::sgSaveAsPic, this, &BaseChatDialog::onSaveAsPic);
	connect(mCommObject, &ChatCommObject::sgPostCopyEvent, this, &BaseChatDialog::onWebViewCopy);
	connect (mCommObject, &ChatCommObject::sgSingleImageCopy, this, &BaseChatDialog::onSingleImageCopy);
	connect (mCommObject, &ChatCommObject::sgReceivalFile,[this](const QString& msgid){
		Biz::Session::getAttachmentManager ()->dowloadAttachFile (msgid,NULL);
	});
	connect(mCommObject, &ChatCommObject::sgSendFile, this, &BaseChatDialog::onSendFileByWebClick);
	connect(mCommObject, &ChatCommObject::sgCancelSend, this, &BaseChatDialog::onCancelSendFileByWebClick);


	connect(mCommObject,&ChatCommObject::sgCustomCentextMenu,this,&BaseChatDialog::onShowCustomContextMenu);
	connect(mCommObject,&ChatCommObject::sgResendMessage, this,&BaseChatDialog::onResendMessage);
	connect(Biz::Session::getMessageManager(),&Biz::MessageManager::sgUpdateMessageSendStatus,this,&BaseChatDialog::onUpdateMessageSendStatus);
	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgConversationMessageStateChange,this,&BaseChatDialog::onConversationMessageStateChange);
	connect(mCommObject,&ChatCommObject::sgShareSelectMessage,this,&BaseChatDialog::onWebJsShareLocalMessage);
	connect(mCommObject,&ChatCommObject::sgShareSelectMessageCountChange,[this](int nCount){
		m_pShareToButton->setVisible(nCount>0);

		m_pShareToButton->setAtTipText(QStringLiteral("选择了%1条消息，分享到...").arg(nCount));
	});
	connect(mCommObject,&ChatCommObject::sgConversationDialogMesssageSelectedStatus,[this](bool bshow){
		m_bWebShereMessageSelectStatus = bshow;
	});

	connect (mCommObject,&ChatCommObject::sgOpenUrlInInnerWebBrowser,this,&BaseChatDialog::openInternalUrl);



	connect(mpUpUnread,&CloseableButtonView::sgTextClicked,[this](const QString& point){
		if (!point.isEmpty())
			mCommObject->jsMsgFindMao(mPage, point);
		if (CloseableButtonView::ShowType::ST_UPUNREAD==mpUpUnread->getShowType())
		{
			onConversationActived(conversationId());
		}

	});
	connect(mpAtNotice,&CloseableButtonView::sgTextClicked,[this](const QString& point){
		//此时，需要判断该msgid的消息，是否在当前显示的页面中
		//如果不在，则需要获取并加载当前页面中第一条消息和point 消息之间的所有消息

		QString strid = MainApp::UIFrame::getConversationController()->topConversationId();
		if (!point.isEmpty())
			//     mCommObject->jsMsgFindMao(mPage, point);
				mCommObject->jsMsgFindMaobyMsgid(mPage, point, strid);


		MainApp::UIFrame::getConversationController()->clearAtNotice(strid);
	});



	connect(mpAtNotice,&CloseableButtonView::sgCancel,[this](){
		QString strid = MainApp::UIFrame::getConversationController()->topConversationId();
		MainApp::UIFrame::getConversationController()->clearAtNotice(strid);

	});

	connect(m_pShareToButton,&CloseableButtonView::sgTextClicked,[this](const QString& unused){
		Q_UNUSED(unused);
		onWebViewShareSelectedMessages(conversationId());
	});


	connect(m_pShareToButton,&CloseableButtonView::sgCancel,[this]{
		m_pShareToButton->setVisible(false);
		mCommObject->updateShareMessageInput(mPage,false);
	});

	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgConversationReadedByOtherClient, 
		this, &BaseChatDialog::onConversationReadedByOtherClient);
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgAllConversationReadedByOtherClient, 
		this, &BaseChatDialog::onAllConversationReadedByOtherClient);


	//上传和下载的时候进度条的变化
	connect(Biz::Session::getAttachmentManager(), &Biz::AttachmentManager::sgUploadProgressDisplay, this, &BaseChatDialog::onUploadFileProgress);
	connect(Biz::Session::getAttachmentManager(), &Biz::AttachmentManager::sgUploadProgressOver, this, &BaseChatDialog::onUploadFileOver);
	connect(Biz::Session::getAttachmentManager(), &Biz::AttachmentManager::sgDownloadProgressDisplay, this, &BaseChatDialog::onRecvFileProgressDisplay);



	m_pShareToButton->setAtTipText(QStringLiteral("分享到..."));
	m_pShareToButton->setVisible(false);
	m_pShareToButton->setAutoHid(false);
	mpUpUnread->setVisible(false);
	mpAtNotice->setVisible(false);
	mpAtNotice->setAutoHid (false);

	//替换图片
	connect(Biz::Session::getAttachmentManager(), &Biz::AttachmentManager::sgUpdateReplaceImage, this, &BaseChatDialog::onUpdateReplaceImage);
	//设置html页面里展示的消息条数
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgHistoryMsgCount, 
		this, &BaseChatDialog::onSetHistoryMsgCount);

	connect(mCommObject, &ChatCommObject::sgOpenUrl, this, &BaseChatDialog::onBaseOpenUrl);
	connect(mCommObject, &ChatCommObject::sgOpenUrlbyPcWeb, this, &BaseChatDialog::onOpenUrlbyPcWeb);
	connect(ChatDisplayOptionWidgetSingleton::getInstance(),&ChatDisplayOptionWidget::sgSelfFontChange,this,&BaseChatDialog::onSelfFontChange);

	connect(mCommObject, &ChatCommObject::sgProblemLisClick, this, &BaseChatDialog::onProblemListClick); 
	connect(mCommObject, &ChatCommObject::sgHintsClick, this, &BaseChatDialog::onHintsClick);

	connect(mCommObject, &ChatCommObject::sgLookMeetingClick, this, &BaseChatDialog::onLookMeetingClick);
	 
}

BaseChatDialog::~BaseChatDialog()
{
	//销毁的时候，需要告诉
#ifndef Q_NO_AMR
	VoicePlayerSingleton::getInstance ()->PlayVoiceOver(false);
#endif //Q_NO_AMR
}

void BaseChatDialog::updateCurrentTick(qint64 tick) {
	MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(conversationId(),tick);
}

void BaseChatDialog::onHintsClick(const QString& type, const QString& infor)
{
	if (type == "transfer") { 
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("暂不支持转人工客服"));
	} else {
		QByteArray infoData = QByteArray::fromBase64(infor.toUtf8());
		QJsonDocument Json_Data = QJsonDocument::fromJson(infoData);
		if (Json_Data.isObject())
		{
			QVariantMap infoMap = Json_Data.toVariant().toMap();
			QString url = infoMap["linkData"].toMap()["url"].toString(); 
			onBaseOpenUrl(url);
		}
	}
}

void BaseChatDialog::onLookMeetingClick(const QString& url)
{ 
	CommentWebViewSingleton::getInstance()->openMeetingInfo(QUrl(url).toEncoded());
}

void BaseChatDialog::onSendProductCard(void) {
	SendProductCardDialog dlg(0);
	if (dlg.exec() == QDialog::Accepted)
	{  
		QString jsonStr = dlg.getProductCardJson();  

		QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
		message->ExtendInfo(jsonStr);
		message->Body(jsonStr); 
		message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
		message->MediaType(Biz::MediaTypeProductInfo);
		message->MsgDirection(Biz::MessageTypeSelf);
		if (Util::UtilHelper::isVirtualAccountId(conversationId(), Biz::Session::getSystemConfig()->getXmppDomain()))
		{
			message->MsgSourceType(Biz::consult); 
			QString realtoId = Util::UtilHelper::getRealIdfromID(conversationId());
			QString virtualId = UtilHelper::getvirtualfromID(conversationId());
			message->Realto(realtoId);
			message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
			message->ConversationID(conversationId());
			message->from(Biz::Session::getAccountManager()->accountData().userJid());
			message->virtualId(virtualId);
			message->qchatid(bm_bIsSeat ? Biz::consultmsgType::OnDutyToVistor : Biz::consultmsgType::VistorToOnDuty);
			message->Chatid(message->qchatid());
		}
		else
		{
			message->MsgSourceType(Biz::ChatMessage);
		} 
		QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
		message->MessageID(uuid);
		message->cctext(m_cctext);
		message->bu(m_bu);
		message->Realfrom(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
		auto callback = receiver->createCallback([]{}, [this](){
			// 发送图片失败 
		});
		auto presendcallback = receiver->createCallback([this, message](){   
			appendMessage(false, false, message);
		},[this](){}); 
		Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);
	}
}

void BaseChatDialog::onProblemListClick(const QString& infor)
{
	QByteArray infoData = QByteArray::fromBase64(infor.toUtf8());
	QJsonDocument Json_Data = QJsonDocument::fromJson(infoData);
	if (Json_Data.isObject())
	{
		QVariantMap infoMap = Json_Data.toVariant().toMap();
		QString itemText = infoMap["text"].toString();
		QString eventType = infoMap["type"].toString();
		QString url = infoMap["url"].toString();
		QString afterClickSendMsg = infoMap["msgText"].toString();
		if (eventType.toLower() == "interface")
		{
			QString wid = conversationId();
			int nSource = Biz::MessageUtil::isGroupJid(wid)?Biz::GroupMessage:Biz::ChatMessage;
			// 发消息 检查连接
			if (afterClickSendMsg.length() > 0)
			{
				onSendMessageByType(afterClickSendMsg,Biz::MediaTypeText,nSource,wid);
			} else
			{ 
				onSendMessageByType(itemText,Biz::MediaTypeText,nSource,wid);
			}
			if (url.length() > 0)
			{
				
			}
		} 
		else if (eventType.toLower() == "forward")
		{
			// 打开浏览器
			onBaseOpenUrl(url);
		}
	}
}

void BaseChatDialog::onProblemListMoreClick(const QString& msgId)
{
	
}

void BaseChatDialog::onProblemListTakeUpClick(const QString& msgId)
{

}

void BaseChatDialog::onImageClicked(QString str, QString urlstr)
{
	// url存储，等待空格事件
	currentImageSrc = str;
	currentImageurlSrc = urlstr;
}

void BaseChatDialog::onImageDbClicked(QString strImageUrl, QString fileId)
{
	Q_UNUSED(strImageUrl);
	Log::e(QString("BaseChatDialog::onImageDbClicked(%1,%2)").arg(strImageUrl).arg(fileId));

	// 根据fileId 在 mAttachInfomap 进行查找，每条消息追加的时候，会生成一个fileid,保存下来,但是不一定会有本地文件
	// 保证每个结构体里有网络路径
	// 保证每个结构体里面有文件id,可以是临时的，在会话的生存周期内是有效的
	// 不保证每个结构体里面有本地路径
	// 如果没有本地文件，进行下载
	QString strImgUrlInCache; 
	QString strLocalcopy;
	QSharedPointer<Biz::XmppMessageAttachment> attInfo =
		Biz::Session::getAttachmentManager()->getAttachmemtInfoByFileId(fileId);

	if (!attInfo.isNull())
	{
		strImgUrlInCache = attInfo->URL ();
		strLocalcopy = attInfo->LOCALCOPY ();
	}

	auto downloadImage = [this,strImgUrlInCache,strImageUrl,fileId]{
		QString strDownLoadUrl = strImgUrlInCache.isEmpty()?strImageUrl:strImgUrlInCache;
		QUrl url(strDownLoadUrl);
		QUrlQuery queryurl(url);
		QString filename;
		queryurl.removeQueryItem("w");
		queryurl.removeQueryItem("h");
		url.setQuery(queryurl);
		strDownLoadUrl = url.toString();

		auto callbackOrgin = receiver->createCallback<QString>([this,fileId,strImageUrl](QString localPath)
		{
			// 照片查看器
			if (!localPath.isEmpty())
			{
				QSharedPointer<Biz::ImageAttachInfor> spImageattachInf = Biz::Session::getAttachmentManager()->getImageAttachInforByImageId(conversationId(), fileId);
				if (!spImageattachInf.isNull())
				{
					spImageattachInf->LocalPath(localPath);
				}
				//这地方判断localPath 的文件名是否空，如果空，则从新进行下载然后展示
				if (!Biz::ConfigureHelper::IsValidFile(localPath))
				{
					QString filePath = Biz::ConfigureHelper::getImageLocalSavePath(strImageUrl,Biz::MessageUtil::makeUserIdSpell(conversationId()));
					UIInstance::getInstance()->getImageViewerDlg()->showPicture(filePath, fileId);
				}
				else
					UIInstance::getInstance()->getImageViewerDlg()->showPicture(localPath, fileId);
			}

			QSharedPointer<Biz::XmppMessageAttachment> spAttachInfo = 
				Biz::Session::getAttachmentManager()->getAttachmemtInfoByFileId(fileId);
			if (!spAttachInfo.isNull())
			{
				spAttachInfo->LOCALCOPY(localPath);
			}
		}, []{});

		QString filePath = Biz::ConfigureHelper::getImageLocalSavePath(strDownLoadUrl,Biz::MessageUtil::makeUserIdSpell(conversationId()));//Biz::Session::getDownLoadManager()->getImageLocalSavePath(strDownLoadUrl,Biz::MessageUtil::makeUserIdSpell(conversationId()));
		//这地方应该用md5值作为图片的名称
		QString strName = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", ""); 
		QString fileName = strName  + QString(".") + QFileInfo(filePath).suffix();

		Biz::Session::getDownLoadManager()->downloadFile(strDownLoadUrl,fileName,Biz::MessageUtil::makeUserIdSpell(conversationId()),"",false,callbackOrgin);
	};

	if (!strLocalcopy.isEmpty())
	{
		//判断原图文件夹中原图是否存在，如果存在，直接在照片查看器中查看
		//否则就要利用urlsrc进行下载
		QString strFileFiler;
		QString strFileName;
		QString strAbsolutePath = Biz::ConfigureHelper::getOrginFromPath(strLocalcopy, strFileName, strFileFiler);
		Q_UNUSED(strFileFiler);
		Q_UNUSED(strFileName);

		if(!QFile::exists(strAbsolutePath))
			strAbsolutePath = QUrl(strAbsolutePath).toLocalFile();

		if (QFile::exists(strAbsolutePath))//不存在，下载
		{
			if (!Biz::ConfigureHelper::IsValidFile(strAbsolutePath))
			{
				QString filePath = Biz::ConfigureHelper::getImageLocalSavePath(strImageUrl,Biz::MessageUtil::makeUserIdSpell(conversationId()));
				UIInstance::getInstance()->getImageViewerDlg()->showPicture(filePath, fileId);
			}
			else
				UIInstance::getInstance()->getImageViewerDlg()->showPicture(strAbsolutePath,fileId);
		}
		else
			downloadImage();
	}
	else
		downloadImage();

}

void BaseChatDialog::onSpaceClicked()
{

	if (!currentImageurlSrc.isEmpty() && !currentImageurlSrc.isEmpty())
	{
		onImageDbClicked(currentImageSrc, currentImageurlSrc);
	}

}

void BaseChatDialog::innerPlayVoice(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
		return;
	QString body = msg->Body();
	QByteArray byteary;
	byteary = body.toUtf8();

	QString amrUrl;
	QString amrFileName;
	QJsonDocument Json_Data = QJsonDocument::fromJson(byteary);
	if(Json_Data.isObject())
	{
		QVariantMap result = Json_Data.toVariant().toMap();
		amrUrl = result["HttpUrl"].toString();
		amrFileName = result["FileName"].toString();
	}

	QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());


	QString savefileName = localPath + amrFileName;

	if (!QFile::exists(savefileName))
	{
		Biz::Session::currentAccount().downLoadVoiceAttachment(msg);
	}
	else
	{
		auto end    = [msg,this]{
			onVoicePlayEnd(msg->MessageID(),msg->MsgDirection()==Biz::MessageTypeSelf);
		};
#ifndef Q_NO_AMR
		VoicePlayerSingleton::getInstance ()->PlayVoiceOver(true);
		VoicePlayerSingleton::getInstance ()->playLocalVoice (savefileName,end);
#endif //Q_NO_AMR
		onVoicePlayStart(msg->MessageID (),msg->MsgDirection()==Biz::MessageTypeSelf);

		mCommObject->setVoicePlayed(mPage,msg->MessageID());
	}

}

void BaseChatDialog::onVoicePlay(const QString& guid)
{
	auto callback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this,guid](QSharedPointer<Biz::XmppMessage> msg)
	{
		innerPlayVoice(msg);
	}, []{});
	Biz::Session::getMessageManager()->getMessageById(guid,callback);
}

void BaseChatDialog::onVoicePlayStart(const QString& guid,bool self)
{
	if (self)
	{
		m_voiceImagesLst.clear();
		m_voiceImagesLst.push_back("./image/out_voiceplay1.png");
		m_voiceImagesLst.push_back("./image/out_voiceplay2.png");
		m_voiceImagesLst.push_back("./image/out_voiceplay3.png");
	}
	else
	{
		m_voiceImagesLst.clear();
		m_voiceImagesLst.push_back("./image/in_voiceplay1.png");
		m_voiceImagesLst.push_back("./image/in_voiceplay2.png");
		m_voiceImagesLst.push_back("./image/in_voiceplay3.png");
	}
	m_voiceImageIndex = 0;
	m_messageid = guid;

	m_voiceImagesTimer.start();
}

void BaseChatDialog::onVoicePlayEnd(const QString& guid,bool self)
{
	if (!guid.isEmpty())
	{
		onUpdateVoiceImage(guid,self?"./image/out_voiceplay3.png":"./image/in_voiceplay3.png");
		Biz::Session::getConverSationManager()->setVoicePlayed(guid);
		m_voiceImagesTimer.stop();

		QTimeLine* pTimeLine = new QTimeLine(200);
		connect(pTimeLine,&QTimeLine::finished,[pTimeLine,guid,this]{
			pTimeLine->deleteLater();
			if (receiver!= NULL)
			{
				auto callback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this](const QSharedPointer<Biz::XmppMessage>& spMessage){
					if (!spMessage.isNull())
					{
						if (!spMessage->isVoicePlayed())
						{
							innerPlayVoice(spMessage);
						}
					}
				},[]{});
				Biz::Session::getConverSationManager()->getNextUnPlayedMessage(conversationId(),guid,callback);
			}

		});
		pTimeLine->start();
	}
}
QString BaseChatDialog::getSelectImagePath()
{
	return currentImageSrc;
}

void BaseChatDialog::onLoadRosterDisplayname(const QString& userID, const QString& displayName)
{

}

void BaseChatDialog::getImageSize(int& w,int& h)
{
	//w = 0; h = 0;
	int maxheigt = 300;
	int maxwidth = 300;
	w = (w > maxwidth && w > h) ? maxwidth:w;
	h = (h > maxheigt && h > w) ? maxheigt:h;
}

void BaseChatDialog::onOpenfile(const QString& msgid)
{
	std::cout << "test";
	auto callback = receiver->createCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>(
		[this,msgid](const QList<QSharedPointer<Biz::XmppMessageAttachment>>& list){
			if (list.size()>0)
			{
				QString localPath = list.at(0)->LOCALCOPY();
				localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
				QProcess::startDetached("explorer \""+localPath+"\"");
			}
			else
			{
				MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("附件表中无该文件记录"));

				QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());
				localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
				QProcess::startDetached("explorer \""+localPath+"\"");
				Log::e(QString("local file cann't find msgid %1").arg(msgid));
			}
	},[](){});
	Biz::Session::getAttachmentManager ()->getFileLocalPathByMessageId (msgid,callback);
}

void BaseChatDialog::onOpenfilePath(const QString& msgid)
{
	auto callback = receiver->createCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>(
		[this,msgid](const QList<QSharedPointer<Biz::XmppMessageAttachment>>& list){
			if (list.size()>0)
			{
				QString localPath = list.at(0)->LOCALCOPY();
				QString filename = list.at(0)->NAME();
#ifdef _WINDOWS
				localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
				QString cmd = "explorer /select,\\" + localPath;
				// QProcess::startDetached("explorer /select,\""+localPath+"\"");
				QProcess::startDetached("explorer /select," + localPath);
#else
				localPath.replace("\\", "/");
				QProcess::execute("nautilus " +  localPath + "\"");
#endif
			}
			else
			{
				QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());
#ifdef _WINDOWS
				localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
				QProcess::startDetached("explorer /select,\""+localPath+"\"");
				Log::e(QString("local file cann't find msgid %1").arg(msgid));
#else
				localPath.replace("\\", "/");
				QProcess::execute("nautilus "+ localPath + +"\"");
#endif
			}
	},[](){});
	Biz::Session::getAttachmentManager ()->getFileLocalPathByMessageId (msgid,callback);
}

void BaseChatDialog::onSaveAs(const QString& msgid)
{
	auto callback = receiver->createCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>(
		[this,msgid](const QList<QSharedPointer<Biz::XmppMessageAttachment>>& list){
			if (list.size()>0)
			{
				QString localPath = list.at(0)->LOCALCOPY();
				QString filename = list.at(0)->NAME();
#ifdef _WINDOWS
				localPath.replace("/","\\");
#else
				localPath.replace("\\", "/");
#endif
				QString saveAsPath = Biz::Session::getEditableSettings()->DefaultSaveAsPath();
				if (saveAsPath.isEmpty())
				{
					Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
					QString localDeskPath = settingconfig->UserSaveAsPath();//Biz::ConfigureHelper::getDeskWindowPath();
					if (localDeskPath.isEmpty())
					{
						localDeskPath = Biz::ConfigureHelper::getDeskWindowPath();
						settingconfig->UserSaveAsPath(localDeskPath);
						Biz::Session::saveSettingConfig();
					}
					if (localDeskPath.right(1) != "/")
					{
						localDeskPath += "/";
					}

					saveAsPath = localDeskPath;

				}


#ifdef _WINDOWS
				saveAsPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#else
				saveAsPath.replace("\\","/");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif
				//QString localFileName = localPath + fileName;
				QFileInfo fileInfor(localPath);
				QString localFileName = QFileInfo(QDir(saveAsPath),fileInfor.fileName()).absoluteFilePath();

				QString strextername = fileInfor.suffix();
				QString suffixname;
				if (!strextername.isEmpty())
				{
					suffixname = QString("Files (*.%1)").arg(strextername);
				}
				else
					suffixname = "All files(*.*)";


				QString saveFileName = QFileDialog::getSaveFileName(0, "Save File", localFileName, suffixname);
				if (!localPath.isNull() && !saveFileName.isEmpty())
				{
					UtilHelper::copyFileToPath(localPath, saveFileName, true);
					QString newSaveAdDir = QFileInfo(saveFileName).absoluteDir().absolutePath();
					QString lastSaveAsDir = QFileInfo(localFileName).absoluteDir().absolutePath();
					if (newSaveAdDir.compare(lastSaveAsDir,Qt::CaseInsensitive)!=0)
					{
						Biz::Session::getEditableSettings()->DefaultSaveAsPath(newSaveAdDir);
						Biz::Session::saveEditableSettings();
					}

#ifdef _WINDOWS
					saveFileName.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
					QString cmd = "explorer /select,\\" + saveFileName;
					QProcess::startDetached("explorer /select," + saveFileName);
#else
					saveFileName.replace("\\", "/");
					QProcess::execute("nautilus " +  saveFileName + "\"");
#endif
				}
			}
			else
			{
				Log::e(QString("local file cann't find msgid %1").arg(msgid));
			}
	},[](){});

	Biz::Session::getAttachmentManager ()->getFileLocalPathByMessageId (msgid,callback);
}

void BaseChatDialog::onSaveAsPic(const QString& filename)
{
	QString saveAsPath = Biz::Session::getEditableSettings()->DefaultSaveAsPath();
	if (saveAsPath.isEmpty())
	{
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString localDeskPath = settingconfig->UserSaveAsPath();//Biz::ConfigureHelper::getDeskWindowPath();
		if (localDeskPath.isEmpty())
		{
			localDeskPath = Biz::ConfigureHelper::getDeskWindowPath();
			settingconfig->UserSaveAsPath(localDeskPath);
			Biz::Session::saveSettingConfig();
		}
		if (localDeskPath.right(1) != "/")
		{
			localDeskPath += "/";
		}

		saveAsPath = localDeskPath;

	}


#ifdef _WINDOWS
	saveAsPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#else
	saveAsPath.replace("\\","/");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
#endif
	//QString localFileName = localPath + fileName;
	QFileInfo fileInfor(filename);
	QString localFileName = QFileInfo(QDir(saveAsPath),fileInfor.fileName()).absoluteFilePath();
	QString strextername = fileInfor.suffix();
	QString suffixname;
	if (!strextername.isEmpty())
	{
		suffixname = QString("Images (*.%1)").arg(strextername);
	}
	else
		suffixname = "Images (*.png *.xpm *.jpg)";

	QString saveFileName = QFileDialog::getSaveFileName(this, "Save File", localFileName, suffixname);
	if (!filename.isNull() && !saveFileName.isEmpty())
	{
		UtilHelper::copyFileToPath(filename, saveFileName, true);
		QString newSaveAdDir = QFileInfo(saveFileName).absoluteDir().absolutePath();
		QString lastSaveAsDir = QFileInfo(localFileName).absoluteDir().absolutePath();
		if (newSaveAdDir.compare(lastSaveAsDir,Qt::CaseInsensitive)!=0)
		{
			Biz::Session::getEditableSettings()->DefaultSaveAsPath(newSaveAdDir);
			Biz::Session::saveEditableSettings();
		}
	}
}

QString BaseChatDialog::ChangeCharactor(const QString& strval)
{
	static QMap<QString,QString> sTransferString;
	if (sTransferString.isEmpty())
	{
		sTransferString.insert("%5C","\\\\");
		sTransferString.insert("%22","\\\"");
		sTransferString.insert("%27","\\\'");
		sTransferString.insert("%25", "%");
	}
	QString rawUrl = strval;
	QMap<QString,QString>::const_iterator citer = sTransferString.constBegin();
	for (; citer!= sTransferString.constEnd(); citer++)
	{
		rawUrl = rawUrl.replace(citer.key(),citer.value());
	}

	return rawUrl;
}

// reimpl
void BaseChatDialog::showAtNotice( const QString& sender,const QString& msg, const QString &msgid )
{

}

void BaseChatDialog::loadChatHtml(webview *webview, const QString& strhtml)
{
	quint64 beginloadhtmlticked = QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("BaseChatDialog::loadChatHtml begin %1 groupjid=%2").arg(beginloadhtmlticked).arg(conversationId()));

	QString strDirHtml = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + strhtml;
	QUrl url = QUrl::fromLocalFile(strDirHtml);
	webview->load(url);


}

QString BaseChatDialog::getLocalCopyByUrl( const QString& url )
{
	QString localcopy;

	QUrl qurl(url);
	if (qurl.isLocalFile())
	{
		localcopy = qurl.toLocalFile();
	}
	else
	{
		QSharedPointer<Biz::XmppMessageAttachment> spAttachInfo = 
			Biz::Session::getAttachmentManager()->getAttachmentInfoByUrl(url);

		if (!spAttachInfo.isNull())
		{
			localcopy = spAttachInfo->LOCALCOPY ();

			if (localcopy.isEmpty())
			{
				QString newurl = url;
				QUrl tUrl(newurl);
				newurl = tUrl.toLocalFile();
				newurl.trimmed();
				newurl = newurl.split("\r\n").first();
				bool b = QFile::exists(newurl);
				if (b)
				{
					localcopy = newurl;
				}
			}
		}
	}
	return localcopy;
}

void BaseChatDialog::onSelectEmotion(const QString& wid,const QString& pkgid, const QString &shortcut)
{
	if (wid == conversationId())
	{
		if(pkgid == "qq" || pkgid == "yahoo" || pkgid == "emotionone" )
		{
			textEdit->addAnimation(pkgid,shortcut);
			textEdit->setFocus();
			return;
		}

		//这里直接用30的小类型发送出去
		QSharedPointer<Biz::EmotionItem> spItem = Biz::Session::getEmoticonManager()->findEmoticon(pkgid,shortcut);
		if (spItem.isNull())
		{
			return;
		}

		QString localfile = spItem->strPath;
		QPixmap pix(localfile);
		QSize size = pix.size();
		QString body;
		QString url = spItem->strUrl;
		//if (pkgid == "_custom")
		if(!url.isEmpty())
		{

			body =  QString("[obj type=\"image\" value=\"%1\" width=%2 height=%3]").arg(url.trimmed()).arg(size.width()).arg(size.height());
		}
		else
		{
			body =  QString("[obj type=\"emoticon\" value=\"%1\" width=%3 height=%3]").arg(shortcut,pkgid, pkgid);
		}

		int nSource = Biz::MessageUtil::isGroupJid(wid)?Biz::GroupMessage:Biz::ChatMessage;
		onSendMessageByType(body, Biz::MediaTypeImageNew, nSource, wid);

	}
}

void BaseChatDialog::onEmojUrlImageSelected(const QString& wid,const QString& pkgid, const QString &shortcut)
{
	if( wid == conversationId() && NULL!=textEdit)
	{         
		textEdit->addUrledAnimation(pkgid,shortcut);
		textEdit->setFocus();
	}
}

void BaseChatDialog::onEmojImageSelected(const QString& wid,const QString& imagepath)
{
	if( wid == conversationId() && NULL!=textEdit)
	{         
		textEdit->insertImage(imagepath);
		textEdit->setFocus();
	}

}

void BaseChatDialog::setCounversationId(const QString& conversationId)
{
	Q_ASSERT(conversationId.contains("@"));
	m_sConversationID = conversationId;
}


void BaseChatDialog::keyPressEvent(QKeyEvent *event)
{
	if (event->modifiers()==Qt::CTRL && NULL!=textEdit)
	{
		if (event->key() == Qt::Key_Up )
		{
			if (m_recentSendMessage.size()>0)
			{
				textEdit->setMimeTypeMessage(m_recentSendMessage.last());
				QSharedPointer<MimeTypeMessage> spLastOne = m_recentSendMessage.last();
				m_recentSendMessage.removeLast();
				m_recentSendMessage.push_front(spLastOne);
				return;
			}

		}
		if (event->key() == Qt::Key_Down)
		{
			if (m_recentSendMessage.size()>0)
			{
				textEdit->setMimeTypeMessage(m_recentSendMessage.first());
				QSharedPointer<MimeTypeMessage> spFirstOne = m_recentSendMessage.first();
				m_recentSendMessage.removeFirst();
				m_recentSendMessage.push_back(spFirstOne);
				return;
			}
		}
	}

	if (event->key() == Qt::Key_Escape)
	{
		Biz::AllUserSettingData *psetting = Biz::Session::getSettingConfig();
		if(psetting->EscHideChat())
			MainApp::UIFrame::getMainDialogController()->closeMainDialog();
	}
	QWidget::keyPressEvent(event);
}

void BaseChatDialog::appendRecentMessage(const QSharedPointer<MimeTypeMessage>& spMtMsg)
{
	if (0 == m_recentSendMessage.size() 
		|| (!m_recentSendMessage.last().isNull() && !spMtMsg.isNull() &&  !m_recentSendMessage.last()->compare(*spMtMsg.data())))
	{
		m_recentSendMessage.append(spMtMsg);
		if (m_recentSendMessage.size()>MaxRecentMessageLimit)
		{
			m_recentSendMessage.removeFirst();
		}
	}
}

bool BaseChatDialog::onAltS_Pressed()
{
	onSendClick (false);
	return true;
}

bool BaseChatDialog::onCtrl_EnterPressed()
{
	QString strtype = Biz::Session::getSettingConfig()->MSendHotKey();
	if (strtype.compare("Ctrl+Enter", Qt::CaseInsensitive) == 0)
	{
		onSendClick (false);
		return true;
	}

	return false;
}

bool BaseChatDialog::onEnter_Pressed()
{
	QString strtype = Biz::Session::getSettingConfig()->MSendHotKey();
	if (strtype.compare("Enter", Qt::CaseInsensitive) == 0)
	{
		QString text = textEdit->toPlainText();
		if (text == "/markdown")
		{
			textEdit->setText("");
			QString enterafter = "<span style='color:#FF4500;font-size:15px;font-weight:bold;'>MarkDown></span>" ;
			textEdit->insertHtml(enterafter);

			textEdit->moveCursor(QTextCursor::WordRight);
			// 往历史输入一个消息提示的信息
			ShowTipMessageOnHistory();
			mMarkdown = true;
			return false;
		}
		else if (text == ":quit" || text== ":q")
		{

			mMarkdown = false;
			textEdit->setText("");
			return false;
		}



		onSendClick (false);
		return true;
	}
	return false;
}


bool BaseChatDialog::onShift_EnterPressed()
{
	QString strtype = Biz::Session::getSettingConfig()->MSendHotKey();
	if (strtype.compare("Shift+Enter", Qt::CaseInsensitive) == 0)
	{
		onSendClick (false);
		return true;
	}
	return false;
}

void BaseChatDialog::initWebContextMenu(webview* view)
{
	if (NULL==mWebViewMenu)
	{
		mWebViewMenu = new QMenu(view);
		mActionWebRevoke = new QAction(QStringLiteral("撤销"), mWebViewMenu);
		connect(mActionWebRevoke, &QAction::triggered, this, &BaseChatDialog::onWebRevokeMessage);
		mWebViewMenu->addAction(mActionWebRevoke);


		mActionWebViewCopy = new QAction(T_("GroupTextEditMenu_item_copy"), mWebViewMenu);
		//connect(mActionWebViewCopy, &QAction::triggered, [this]{this->mPWebView->triggerPageAction(WebPage::Copy);});
		connect(mActionWebViewCopy, &QAction::triggered, this, &BaseChatDialog::onWebViewCopyMenu);
		mWebViewMenu->addAction(mActionWebViewCopy);


		mActionWebViewSeleAll = new QAction(T_("GroupTextEditMenu_item_All"), mWebViewMenu);
		connect(mActionWebViewSeleAll, &QAction::triggered, this, &BaseChatDialog::onWebSelectAllPage);
		mWebViewMenu->addAction(mActionWebViewSeleAll);

		mActionWebViewSaveAs = new QAction(T_("GroupTextEditMenu_item_Saveas"), mWebViewMenu);
		connect(mActionWebViewSaveAs, &QAction::triggered, this, &BaseChatDialog::onWebViewSaveAs);
		mWebViewMenu->addAction(mActionWebViewSaveAs);

		mActionWebSaveAsCustomEmoj = new QAction(QStringLiteral("收藏为表情"), mWebViewMenu);
		connect(mActionWebSaveAsCustomEmoj, &QAction::triggered,this,&BaseChatDialog::onWebViewSaveCustomEmoj);
		mWebViewMenu->addAction(mActionWebSaveAsCustomEmoj);

		mWebViewMenu->addSeparator();

		mACtionWebShareOneMessage = new QAction(QStringLiteral("转发"),mWebViewMenu);
		connect(mACtionWebShareOneMessage, &QAction::triggered,this,&BaseChatDialog::onWebViewShareOnMessage);
		mWebViewMenu->addAction(mACtionWebShareOneMessage);

		mACtionWebReferenceMessage = new QAction(QStringLiteral("引用"), mWebViewMenu);
		connect(mACtionWebReferenceMessage, &QAction::triggered,this,&BaseChatDialog::onWebViewReferenceOnMessage);
		mWebViewMenu->addAction(mACtionWebReferenceMessage);

		mWebViewMenu->addSeparator();

		QAction* aciton = new QAction(QStringLiteral("清屏"),mWebViewMenu);
		connect(aciton,&QAction::triggered,this,&BaseChatDialog::onWebClearContents);
		mWebViewMenu->addAction(aciton);
	}

}


void BaseChatDialog::onShowCustomContextMenu(const QString& msgid,int option)
{
	// 这里直接弹菜单会阻塞webview的消息，这里用qtimeline做个简单的线程切换，实现postevent的东西
	QTimeLine* pTmpTimerLine = new QTimeLine(50);
	connect(pTmpTimerLine,&QTimeLine::finished,[this,msgid,option,pTmpTimerLine]{
		pTmpTimerLine->deleteLater();
		strTmpCustomContextMenuMsgId = msgid;
		webview *webView = mPWebView;
		if (NULL!=webView)
		{
			initWebContextMenu(webView);

			if( webView->selectedText().length() > 0 || (webView->selectedText().length() == 0 && !getSelectImagePath().isEmpty()) )
			{
				mActionWebViewCopy->setEnabled(true);
				mACtionWebReferenceMessage->setEnabled(true);

			}else{
				mActionWebViewCopy->setEnabled(false);
				//mACtionWebReferenceMessage->setEnabled(false);
			}

			if (getSelectImagePath().isEmpty())
			{
				mActionWebViewSaveAs->setEnabled(false);
				mActionWebSaveAsCustomEmoj->setEnabled(false);
				mACtionWebReferenceMessage->setEnabled(true);
			}
			else
			{
				//mACtionWebReferenceMessage->setEnabled(false);
				mActionWebViewSaveAs->setEnabled(true);
				mActionWebSaveAsCustomEmoj->setEnabled(true);
			}

			mActionWebRevoke->setVisible(!msgid.isEmpty() && (BubbleDirectionSelf==(BubbleDirectionSelf&option)));

			mWebViewMenu->exec(QCursor::pos());
		}
	});
	pTmpTimerLine->start();
}



void BaseChatDialog::innerParseClipboardData()
{
	// 兼容5.6 不能用 selecthtml()
	const QMimeData* pClipboardData= QApplication::clipboard ()->mimeData ();
	if (NULL==pClipboardData)
		return;
	QMimeData* pmimidata = innerParseClipboardData (pClipboardData);
	if (NULL == pmimidata)
		return;

	QClipboard *board = QApplication::clipboard();
	board->setMimeData(pmimidata);
	// attention:
	// setMimeData的时候，新的mimeData被设置后，旧的mimeData会被自动delete,因此不要操作旧的mimeData
	// setMimeData失败之后，新的mimeDate也会被delete,因此不要在setMimeData后面再调用关于mimeData的任何方法。
}

QMimeData* BaseChatDialog::innerParseClipboardData(const QMimeData* sourceMime)
{
	// 兼容5.6 不能用 selecthtml()
	if (NULL==sourceMime)
		return NULL;
	QString text1 = mPage->selectedText();
	QString text = sourceMime->text ();
	QString html = sourceMime->html();
	QMimeData* pmimidata = new QMimeData();

	QStringList formats = sourceMime->formats ();
	for (QString format : formats)
	{
		pmimidata->setData (format,sourceMime->data (format));
	}
	if (!html.isEmpty())
	{
		QString qchatCopyData;
		QString wechatCopyData;
		QString qqCopyData;
		QXmlStreamWriter qchatWriter(&qchatCopyData);
		QXmlStreamWriter wechatWriter(&wechatCopyData);
		QXmlStreamWriter qqWriter(&qqCopyData);

		qchatWriter.writeStartElement("QChatRichEditFormat");
		wechatWriter.writeStartElement("WeChatRichEditFormat");
		qqWriter.writeStartElement("QQRichEditFormat");
		qqWriter.writeStartElement("Info");
		qqWriter.writeAttribute("version", "1001");
		qqWriter.writeEndElement();

		HTML::ParserDom parser;
		std::string sHtml = html.toStdString();
		const tree<HTML::Node>& dom = parser.parseTree(sHtml);


		tree<HTML::Node>::iterator it = dom.begin();
		tree<HTML::Node>::iterator end = dom.end();
		bool bret = false;
		bool spanbret = false;
		for (; it != end; ++it)
		{

			QString tagName = QString::fromStdString(it->tagName());
			if (0 == tagName.compare("div", Qt::CaseInsensitive) || 0 == tagName.compare("span", Qt::CaseInsensitive))
			{
				it->parseAttributes();
				QString strClass = QString::fromStdString(it->attribute("class").second);
				if (strClass.compare("other", Qt::CaseInsensitive) == 0 || 0 == strClass.compare("self", Qt::CaseInsensitive))
				{
					if (!qchatCopyData.contains ("EditElement"))
					{
						continue;
					}
					qchatWriter.writeStartElement("EditElement");
					qchatWriter.writeAttribute("type", "0");
					qchatWriter.writeCDATA("\r\n");
					qchatWriter.writeEndElement();

					wechatWriter.writeStartElement("EditElement");
					wechatWriter.writeAttribute("type", "0");
					wechatWriter.writeCDATA("\r\n");
					wechatWriter.writeEndElement();

					qqWriter.writeStartElement("EditElement");
					qqWriter.writeAttribute("type", "0");
					qqWriter.writeCDATA("\r\n");
					qqWriter.writeEndElement();
				}
			}

			if (0 == tagName.compare("img", Qt::CaseInsensitive))
			{
				it->parseAttributes();
				QString strSrc = QString::fromStdString(it->attribute("src").second);
				QString strClass = QString::fromStdString(it->attribute("class").second);

				if (strClass.contains("headimg"))
					continue;
				// 网络地址本地地址转换
				QUrl url;
				if (QFile::exists(strSrc))
					url = QUrl::fromLocalFile(strSrc);
				else
					url = QUrl(strSrc);

				QString localImagePath;

				QString scheme = url.scheme();
				if (url.scheme().isEmpty())
					localImagePath = strSrc;
				else if (url.scheme().compare("file", Qt::CaseInsensitive) == 0)
					localImagePath = url.toLocalFile();
				else
				{
					QSharedPointer<Biz::XmppMessageAttachment> spAttachInfo =
						Biz::Session::getAttachmentManager()->getAttachmentInfoByUrl(strSrc);
					if (!spAttachInfo.isNull())
					{
						QString strLocalPic = spAttachInfo->LOCALCOPY ();
						if (!strLocalPic.isEmpty())
							localImagePath = strLocalPic;
					}

				}

				Log::assertl(!localImagePath.isEmpty(), "can not find image attachment " + strSrc);

				if (QFile::exists (localImagePath))
				{

#ifdef _WINDOWS
					localImagePath = localImagePath.replace("/", "\\");
#endif
					qchatWriter.writeStartElement("EditElement");
					qchatWriter.writeAttribute("type", "1");
					qchatWriter.writeAttribute("filepath", localImagePath);
					qchatWriter.writeEndElement();

					wechatWriter.writeStartElement("EditElement");
					wechatWriter.writeAttribute("type", "1");
					wechatWriter.writeAttribute("filepath", localImagePath);
					wechatWriter.writeEndElement();

					qqWriter.writeStartElement("EditElement");
					qqWriter.writeAttribute("type", "1");
					qqWriter.writeAttribute("filepath", localImagePath);
					qqWriter.writeEndElement();
				}
			}
			//有空行的情况
			if (0 == tagName.compare("br", Qt::CaseInsensitive))
			{
				bret = false;
				qchatWriter.writeStartElement("EditElement");
				qchatWriter.writeAttribute("type", "0");
				qchatWriter.writeCDATA("\n");
				qchatWriter.writeEndElement();

				wechatWriter.writeStartElement("EditElement");
				wechatWriter.writeAttribute("type", "0");
				wechatWriter.writeCDATA("\n");
				wechatWriter.writeEndElement();

				qqWriter.writeStartElement("EditElement");
				qqWriter.writeAttribute("type", "0");
				qqWriter.writeCDATA("\n");
				qqWriter.writeEndElement();

			}

			if ((!it->isTag()) && (!it->isComment()))
			{
				QString parentIterTagName;
				tree<HTML::Node>::iterator parentIter = dom.parent(it);
				if (parentIter!= dom.end() && NULL != parentIter.node)
				{
					parentIterTagName = QString::fromStdString(parentIter->tagName());
					if (0 == parentIterTagName.compare("meta", Qt::CaseInsensitive) ||
						0 == parentIterTagName.compare("script", Qt::CaseInsensitive) ||
						0 == parentIterTagName.compare("title", Qt::CaseInsensitive) ||
						0 == parentIterTagName.compare("style", Qt::CaseInsensitive) ||
						0 == parentIterTagName.compare("link", Qt::CaseInsensitive))
						continue;
					if (0 == parentIterTagName.compare("span", Qt::CaseInsensitive))
					{
						spanbret = true;
						parentIter->parseAttributes();
						QString strClass = QString::fromStdString(parentIter->attribute("class").second);
						if (strClass.compare("time", Qt::CaseInsensitive) == 0)
							continue;
					}
				}

				QString strText = QString::fromStdString(it->text()).trimmed();
				if (!strText.isEmpty())
				{
					bret = true;
					qchatWriter.writeStartElement("EditElement");
					qchatWriter.writeAttribute("type", "0");
					qchatWriter.writeCDATA(strText);
					qchatWriter.writeEndElement();

					wechatWriter.writeStartElement("EditElement");
					wechatWriter.writeAttribute("type", "0");
					wechatWriter.writeCDATA(strText);
					wechatWriter.writeEndElement();

					qqWriter.writeStartElement("EditElement");
					qqWriter.writeAttribute("type", "0");
					qqWriter.writeCDATA(strText);
					qqWriter.writeEndElement();
				}
				else
				{
					if(bret&&!spanbret)
					{
						qchatWriter.writeStartElement("EditElement");
						qchatWriter.writeAttribute("type", "0");
						qchatWriter.writeCDATA("\n");
						qchatWriter.writeEndElement();

						wechatWriter.writeStartElement("EditElement");
						wechatWriter.writeAttribute("type", "0");
						wechatWriter.writeCDATA("\n");
						wechatWriter.writeEndElement();

						qqWriter.writeStartElement("EditElement");
						qqWriter.writeAttribute("type", "0");
						qqWriter.writeCDATA("\n");
						qqWriter.writeEndElement();
					}
				}




				if (0 == parentIterTagName.compare("div", Qt::CaseInsensitive)
					|| 0 == parentIterTagName.compare("span", Qt::CaseInsensitive))
				{
					tree<HTML::Node>::iterator parentIter = dom.parent(it);
					if (parentIter == dom.end ())
						continue;

					parentIter->parseAttributes();
					QString strClass = QString::fromStdString(parentIter->attribute("class").second);
					if (strClass.compare("namehide", Qt::CaseInsensitive) == 0)
					{
						qchatWriter.writeStartElement("EditElement");
						qchatWriter.writeAttribute("type", "0");
						qchatWriter.writeCDATA(" ");
						qchatWriter.writeEndElement();

						wechatWriter.writeStartElement("EditElement");
						wechatWriter.writeAttribute("type", "0");
						wechatWriter.writeCDATA(" ");
						wechatWriter.writeEndElement();

						qqWriter.writeStartElement("EditElement");
						qqWriter.writeAttribute("type", "0");
						qqWriter.writeCDATA(" ");
						qqWriter.writeEndElement();
					}
					if (strClass.compare("tabtimehide", Qt::CaseInsensitive) == 0)
					{
						qchatWriter.writeStartElement("EditElement");
						qchatWriter.writeAttribute("type", "0");
						qchatWriter.writeCDATA("\r\n");
						qchatWriter.writeEndElement();

						wechatWriter.writeStartElement("EditElement");
						wechatWriter.writeAttribute("type", "0");
						wechatWriter.writeCDATA("\r\n");
						wechatWriter.writeEndElement();

						qqWriter.writeStartElement("EditElement");
						qqWriter.writeAttribute("type", "0");
						qqWriter.writeCDATA("\r\n");
						qqWriter.writeEndElement();
					}
				}

			}
		}

		qchatWriter.writeEndElement();
		wechatWriter.writeEndElement();
		qqWriter.writeEndElement();

		pmimidata->setData("QChat_RichEdit_Format", qchatCopyData.toUtf8());
		pmimidata->setData("WeChat_RichEdit_Format", wechatCopyData.toUtf8());
		pmimidata->setData("QQ_Unicode_RichEdit_Format", qqCopyData.toUtf8());
	}

	if (!text.isEmpty())
	{
		pmimidata->setText(text);
	}

	QStringList sl = pmimidata->formats ();
	Log::e ("the new mime data : " + QString::number (sl.size ()));
	return pmimidata;
}

void BaseChatDialog::onClipBoardSelectChanged()
{
	QObject* pObject = sender ();

	disconnect(QApplication::clipboard(), &QClipboard::changed, this, &BaseChatDialog::onClipBoardSelectChanged);
	innerParseClipboardData();
}

void BaseChatDialog::onWebViewCopy()
{
#if 0
	// 如果想从qtalk里拷贝东西到微信或者QQ，需要在将这里的功能打开
	// 遇到问题，QClipboard::setMimeData的时候可能引起 ole 写入失败的问题，导致ctrlcv消失，体验不好，故先注释掉，保留接口
	Log::e ("BaseChatDialog::onWebViewCopy");
	connect(QApplication::clipboard(), &QClipboard::changed, this, &BaseChatDialog::onClipBoardSelectChanged);
#endif
}


void BaseChatDialog::onSingleImageCopy()
{
	Log::e ("BaseChatDialog::onSingleImageCopy");

	QString imgPath = getLocalCopyByUrl(getSelectImagePath());
	if (!imgPath.isEmpty())
	{
		QMimeData* pmimidata = new QMimeData();

		QUrl url(imgPath);
		if (url.isLocalFile())
		{
			imgPath = url.toLocalFile();
		}
		if (QFile::exists(imgPath))
		{
			QString qchatCopyData;
			QString wechatCopyData;
			QString qqCopyData;
			QXmlStreamWriter qchatWriter(&qchatCopyData);
			QXmlStreamWriter wechatWriter(&wechatCopyData);
			QXmlStreamWriter qqWriter(&qqCopyData);

			qchatWriter.writeStartElement("QChatRichEditFormat");
			wechatWriter.writeStartElement("WeChatRichEditFormat");
			qqWriter.writeStartElement("QQRichEditFormat");
			qqWriter.writeStartElement("Info");
			qqWriter.writeAttribute("version", "1001");
			qqWriter.writeEndElement();

			Log::assertl(!imgPath.isEmpty(), "can not find image attachment " + getSelectImagePath());
#ifdef _WINDOWS
			imgPath = imgPath.replace("/", "\\");
#endif

			qchatWriter.writeStartElement("EditElement");
			qchatWriter.writeAttribute("type", "1");
			qchatWriter.writeAttribute("filepath", imgPath);
			qchatWriter.writeEndElement();

			wechatWriter.writeStartElement("EditElement");
			wechatWriter.writeAttribute("type", "1");
			wechatWriter.writeAttribute("filepath", imgPath);
			wechatWriter.writeEndElement();

			qqWriter.writeStartElement("EditElement");
			qqWriter.writeAttribute("type", "1");
			qqWriter.writeAttribute("filepath", imgPath);
			qqWriter.writeEndElement();

			qchatWriter.writeEndElement();
			wechatWriter.writeEndElement();
			qqWriter.writeEndElement();

			pmimidata->setData("QChat_RichEdit_Format", qchatCopyData.toUtf8());
			pmimidata->setData("WeChat_RichEdit_Format", wechatCopyData.toUtf8());
			pmimidata->setData("QQ_Unicode_RichEdit_Format", qqCopyData.toUtf8());

			//QImage image = Biz::PortraitHelper::getUserPortraitImage(imgPath);//Biz::ImageHelper::loadImageFromPath(imgPath);
			QImage image = Biz::ImageHelper::loadImageFromPath(imgPath);
			pmimidata->setImageData(image);
		}


		QClipboard *board = QApplication::clipboard();

		QStringList sl = pmimidata->formats ();
		Log::e (" set image clip data : " + QString::number (sl.size ()));

		board->setMimeData(pmimidata);
		// attention:
		// setMimeData的时候，新的mimeData被设置后，旧的mimeData会被自动delete,因此不要操作旧的mimeData
		// setMimeData失败之后，新的mimeDate也会被delete,因此不要在setMimeData后面再调用关于mimeData的任何方法。
	}
}

void BaseChatDialog::onWebClearContents()
{
	this->onClearContents();
}

void BaseChatDialog::onWebSelectAllPage()
{
	mCommObject->jsSelectAll(mPage);
}

void BaseChatDialog::onWebViewSaveAs()
{
	QString text = mPage->selectedText();
	if (text.isEmpty())
	{
		QString imgLocalPath = getLocalCopyByUrl(getSelectImagePath());

		if(!imgLocalPath.isEmpty())
		{
			if (QUrl(imgLocalPath).isLocalFile())
			{
				imgLocalPath = QUrl(imgLocalPath).toLocalFile();
			}
			if (QFile::exists(imgLocalPath))
			{
				mCommObject->jsSaveFilePic(imgLocalPath);
				return;
			}

		}

		auto callbackOrgin = receiver->createCallback<QString>([this](QString localPath)
		{
			mCommObject->jsSaveFilePic(localPath);
		}, []{});

		QString fileName =Biz::ConfigureHelper::getImageLocalSaveName(getSelectImagePath()); /*Biz::Session::getDownLoadManager()->getImageLocalSaveName(getSelectImagePath());*/
		if(!getSelectImagePath().isEmpty() && !fileName.isEmpty())
		{
			Biz::Session::getDownLoadManager()->downloadFile(getSelectImagePath(), fileName,Biz::MessageUtil::makeUserIdSpell(conversationId()),"",false,callbackOrgin);
		}
		else
		{
			Log::e("download img fail " + getSelectImagePath() + " " + fileName);
		}
	}
	else
	{
		Log::e(" select text is not empty " + text);
	}
}

void BaseChatDialog::onWebViewSaveCustomEmoj()
{
	QString text = mPage->selectedText();
	if (text.isEmpty())
	{
		QString imgPath = getLocalCopyByUrl(getSelectImagePath());
		QString strFileFiler;
		QString strFileName;
		QString strNewFilePath = Biz::ConfigureHelper::getOrginFromPath(imgPath, strFileName, strFileFiler);
		if (QFile::exists(strNewFilePath)) //存在
		{
			Biz::Session::getEmoticonManager()->saveCustomEmojicon(strNewFilePath);
		}
		else //如果不存在，下载后，保存
		{

			auto callbackOrgin = receiver->createCallback<QString>([this](QString localPath)
			{
				Biz::Session::getEmoticonManager()->saveCustomEmojicon(localPath);
				return;
			}, []{});

			QString fileName = Biz::ConfigureHelper::getImageLocalSaveName(getSelectImagePath());//Biz::Session::getDownLoadManager()->getImageLocalSaveName(getSelectImagePath());
			if(!getSelectImagePath().isEmpty() || fileName.isEmpty())
			{
				Biz::Session::getDownLoadManager()->downloadFile(getSelectImagePath(), fileName,Biz::MessageUtil::makeUserIdSpell(conversationId()),"",false,callbackOrgin);
			}
			else
			{
				Log::e("download img fail " + getSelectImagePath() + " " + fileName);
			}
		}
	}
	else
	{
		Log::e(" onWebviewSaveCustomEmoj select text is not empty " + text);
	}
}

void BaseChatDialog::onWebRevokeMessage()
{
	auto revokeCallback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>(
		[this](const QSharedPointer<Biz::XmppMessage>& spMessage){
			if (!spMessage.isNull())
			{
				this->onMessageReceived(spMessage);
				MainApp::UIFrame::getConversationController()->updateChatContent(spMessage->ConversationID(), spMessage);
			}

	},[this]{
		mCommObject->systemnotify(mPage,QStringLiteral("超过2分钟的消息不可以撤销"));
	});
	Biz::Session::getConverSationManager()->sendRevokeMessage(strTmpCustomContextMenuMsgId,revokeCallback);
}

void BaseChatDialog::appendLocalFile(const QString& filepath)
{
	if (filepath.isEmpty())
		return;
	QFileInfo fInfor(filepath);
	if (fInfor.isDir())
		return;
	sendFile(filepath);
}

void BaseChatDialog::appendLocalPicture(const QString& picpath)
{
	if (picpath.isEmpty())
	{
		return;
	}
	QFileInfo fInfor(picpath);
	if (fInfor.isDir())
	{
		return;
	}

	if ( Biz::ConfigureHelper::IsPicFile(picpath))
	{
		//然后判断图片的大小，如果大于150M,则不让发送，则弹出一个提示
		int LimitedSize = 150;
		QFileInfo fileinfo(picpath);
		int sizeM = fileinfo.size()/1024/1024 +1;
		if (sizeM < LimitedSize)
		{
			textEdit->insertImage(picpath);
			textEdit->setFocus();
			textEdit->ensurePolished();
			textEdit->ensureCursorVisible();
		}
		else
		{
			QString strTitleInfor = QStringLiteral("<h3>图片超过了%1M,需要以文件的形式发送，是否需要继续发送？</h3>").arg(LimitedSize);
			if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",strTitleInfor,QStringLiteral("取消"),QStringLiteral("确定")))
			{
				sendFile(picpath);
			}
		}
	}
	else
	{
		sendFile(picpath);
	}

}



void BaseChatDialog::appendUnreadTipMessageDown( const QSharedPointer<Biz::XmppMessage>& spMessage )
{
	if (spMessage.isNull())
	{
		return;
	}
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(""));
	message->MsgSourceType(Biz::MessageSourceType::RevertMsgType);
	message->MediaType(Biz::MessageMediaType::MediaTypeText);
	message->UtcTime(spMessage->UtcTime());
	mCommObject->jsInsertUnreadMessageDownTip(mPage,message);
}

void BaseChatDialog::onTextEditPaste()
{
	// 由于没有对copy 时的 clip的二次转换，需要添加一次本地的二次转会
	const QMimeData* mimeDatasource = QApplication::clipboard()->mimeData();
	bool b = QApplication::clipboard ()->ownsClipboard ();
	const QMimeData* mimeData = b ? innerParseClipboardData (mimeDatasource) : mimeDatasource;

	if (NULL == mimeData)
		return;

	QStringList formats = mimeData->formats ();
	do 
	{
		// 先解析url --- 在发文件
		if (mimeData->hasUrls())
		{
			bool bSelectedfile = false;
			bool bPastUrl = false;
			QList<QUrl> urls = mimeData->urls();
			for (QUrl url:urls)
			{
				if (url.isLocalFile ())
				{
					//在这里判断是否是图片的文件，和普通文件
					QString strLocalPath = url.toLocalFile ();
					if (Biz::ConfigureHelper::IsPicFile(strLocalPath))
					{
						textEdit->insertImage(strLocalPath);
					}
					else
						appendLocalFile(strLocalPath);
					bSelectedfile = true;
				}
				else  //粘贴的
				{
					bPastUrl = true;
					QString plainText = mimeData->text();
					textEdit->insertPlainText (plainText + " ");
					break;
				}
			}
			if (bSelectedfile || bPastUrl)
			{
				break;
			}
		}

		// 图片和文本判定
		if (mimeData->hasImage() && mimeData->hasText())
		{
			// 用户选择
			//弹一个菜单出来，是粘贴成文本，还是粘贴成图片
			PastTextmimeData = (QMimeData*)mimeData;
			QMenu *selectmenu = new QMenu(textEdit);
			QAction *textAction = selectmenu->addAction(QStringLiteral("文本"));
			connect(textAction, &QAction::triggered, this, &BaseChatDialog::onInsertTextPast);
			QAction *imageAction = selectmenu->addAction(QStringLiteral("图片"));
			connect(imageAction, &QAction::triggered, this, &BaseChatDialog::onInsertImagePast);
			selectmenu->exec(QCursor::pos());
			//             if (false)
			//             {
			//                 QString plainText = mimeData->text();
			//                 textEdit->insertPlainText (plainText);
			//                 break;
			//             }
			//             else
			//             {
			//                 QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
			//                 QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
			//                 QApplication::clipboard()->pixmap().save(fileName, "PNG");
			//                 textEdit->insertImage(fileName);
			//                 break;
			//             }
		}
		else
		{
			// 在解析image
			if (mimeData->hasImage())
			{
				QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
				QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
				QApplication::clipboard()->pixmap().save(fileName, "PNG");

				textEdit->insertImage(fileName);
				break;
			}
			// 判断多媒体
			QStringList mimeFormatList;
			mimeFormatList << "application/x-qt-windows-mime;value=\"QChat_RichEdit_Format\""
				<< "application/x-qt-windows-mime;value=\"WeChat_RichEdit_Format\""
				<< "application/x-qt-windows-mime;value=\"QQ_Unicode_RichEdit_Format\""
				<< "QChat_RichEdit_Format"
				<< "WeChat_RichEdit_Format"
				<< "QQ_Unicode_RichEdit_Format";

			QStringList formats = mimeData->formats ();

			Log::e ("copy from clip data : " + QString::number (formats.size ()));
			bool bParsed = false;
			for (QString format : formats)
			{
				if (mimeFormatList.contains (format))
				{
					QByteArray data = mimeData->data (format);
					QDomDocument doc;
					int errRow = 0;
					int errCol = 0;
					QString errMessage;
					bool currentvalue = false;

					doc.setContent (data,false,&errMessage,&errRow,&errCol);
					QString rootTagName = doc.documentElement ().tagName ();
					QDomElement element = doc.documentElement ().firstChildElement ("EditElement");
					do 
					{
						if (element.isNull ())
							break;

						int type = element.attribute ("type").toInt ();
						if (ThrMimeDataFormatType::MimeDataFormatType_Text == type)
						{
							QString text = element.firstChild ().toCDATASection ().nodeValue ();
							text = UtilHelper::decopeHtmlEscaptd(text);
							if (!text.isEmpty())
							{
								textEdit->insertPlainText (text);
							}
							else
							{
								currentvalue = true;
							}
						}
						else if (ThrMimeDataFormatType::MimeDataFormatType_Img == type)
						{
							QString filePath = element.attribute ("filepath");
							if (QFile::exists (filePath))
							{

								textEdit->insertImage (filePath);
							} else if (QUrl(filePath).isLocalFile ())
							{

								textEdit->insertImage (filePath);
							}
						}
						element = element.nextSiblingElement ("EditElement");
						if (!element.isNull() && currentvalue)
						{
							textEdit->insertPlainText("\n");
						}

					} while (true);


					bParsed = true;
					break;
				}
			}

			if (bParsed)
				break;

			if (mimeData->hasHtml () && !mimeData->html ().isEmpty ())
			{
				QString html = mimeData->html();
				HTML::ParserDom parser;
				std::string sHtml = html.toStdString();
				const tree<HTML::Node>& dom = parser.parseTree(sHtml);

				tree<HTML::Node>::iterator it = dom.begin();
				tree<HTML::Node>::iterator end = dom.end();
				for (; it != end; ++it)
				{
					QString tagName = QString::fromStdString(it->tagName());
					if (0 == tagName.compare("li", Qt::CaseInsensitive) || 0 == tagName.compare("tr", Qt::CaseInsensitive) || 0 == tagName.compare("br", Qt::CaseInsensitive))
					{
						textEdit->insertPlainText ("\r\n");
					}

					if (0 == tagName.compare("img", Qt::CaseInsensitive))
					{
						it->parseAttributes();
						QString strSrc = QString::fromStdString(it->attribute("src").second);

						if (QFile::exists (strSrc))
						{
							textEdit->insertImage (strSrc);
						}
						else
						{
							strSrc = QUrl(strSrc).toLocalFile();
							textEdit->insertImage (strSrc);
						}
					}


					if ((!it->isTag()) && (!it->isComment()))
					{
						QString parentIterTagName;
						tree<HTML::Node>::iterator parentIter = dom.parent(it);
						if (parentIter!=dom.end() && NULL != parentIter.node)
						{
							parentIterTagName = QString::fromStdString(parentIter->tagName());
							if (0 == parentIterTagName.compare("meta", Qt::CaseInsensitive) ||
								0 == parentIterTagName.compare("script", Qt::CaseInsensitive) ||
								0 == parentIterTagName.compare("title", Qt::CaseInsensitive) ||
								0 == parentIterTagName.compare("style", Qt::CaseInsensitive) ||
								0 == parentIterTagName.compare("link", Qt::CaseInsensitive))
								continue;
						}

						//想在这里加入一个函数进行过滤，但是时间紧迫，没时间搞了，暂时这样处理
						QString strText = QString::fromStdString(it->text()).trimmed();
						strText = strText.replace("&nbsp;"," ");
						strText = strText.replace("&amp;", "&");
						strText = strText.replace("&quot;", "\"");
						strText = strText.replace("&lt;", "<");
						strText = strText.replace("&gt;", ">");
						strText = strText.replace("&#160;"," ");
						strText = strText.replace("&#38;", "&");
						strText = strText.replace("&#34;", "\"");
						strText = strText.replace("&#60;", "<");
						strText = strText.replace("&#62;", ">");
						strText = strText.replace("&#32;", " ");
						textEdit->insertPlainText(strText);

						//textEdit->insertPlainText (strText);
					}
				}
				break;
			}

			// 判断文本
			if (mimeData->hasText())
			{
				QString plainText = mimeData->text();
				textEdit->insertPlainText (plainText);
				break;
			}
		}
	} while (false);

	textEdit->setFocus();
	textEdit->ensurePolished();
	textEdit->ensureCursorVisible();
}

void BaseChatDialog::appendUnreadTipMessage(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (spMessage.isNull())
	{
		return;
	}
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(""));
	message->MsgSourceType(Biz::MessageSourceType::RevertMsgType);
	message->MediaType(Biz::MessageMediaType::MediaTypeText);
	message->UtcTime(spMessage->UtcTime());
	mCommObject->jsInsertUnreadMessageTip(mPage,message);
}

void BaseChatDialog::onUpdateMessageSendStatus(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (conversationId() == spMessage->ConversationID())
	{
		int sendfail = MessageDecoraterBubbleWrapperSelf::MessageStatus::SendSuccess;
		QString messageStatue = T_("MessageState_UnReaded");
		if (spMessage->isMessageSendSuccess())
			sendfail = MessageDecoraterBubbleWrapperSelf::MessageStatus::SendSuccess;

		if (spMessage->isMessageSendFail()){
			messageStatue = QStringLiteral("发送失败");
			sendfail = MessageDecoraterBubbleWrapperSelf::MessageStatus::SendFail;
		}

		if (spMessage->isMessageSending()){
			messageStatue = QStringLiteral("发送中");
			sendfail = MessageDecoraterBubbleWrapperSelf::MessageStatus::Sending;
		}


		mCommObject->updateMessageSendStatus(mPage,spMessage->MessageID(),sendfail);
		// 不是有效值
		if (spMessage->RemoteFlag() <= 0)
		{
			mCommObject->jsSetMessageStatus(mPage,spMessage->MessageID(),messageStatue);
		}
	}
}

void BaseChatDialog::onResendMessage(const QString& message)
{
	if (message.isNull())
	{
		return;
	}
	if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",QStringLiteral("重新发送此消息？"),QStringLiteral("取消"),QStringLiteral("确认")))
	{
		auto callback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this,message](QSharedPointer<Biz::XmppMessage> msg)
		{
			auto callback = receiver->createCallback([]{},[this,message]{
				mCommObject->updateMessageSendStatus(mPage,message,MessageDecoraterBubbleWrapperSelf::MessageStatus::SendFail);
			});
			auto prePostcallback = receiver->createCallback([this,message]{
				mCommObject->updateMessageSendStatus(mPage,message,MessageDecoraterBubbleWrapperSelf::MessageStatus::Sending);
			},[]{});
			msg->cctext(m_cctext); //这个时候从库里拿的消息，肯定没cctext 这里加上
			msg->bu(m_bu);
			Biz::Session::currentAccount().doSendMessage(msg,callback,prePostcallback);
		}, []{});
		Biz::Session::getMessageManager()->getMessageById(message,callback);
	}
}


/*!
* 功能 : 当界面处于不激活状态，item被点击了，那么会触发这个逻辑
*/
void BaseChatDialog::onCurrentConversationChange(const QString& curConversationID,const QString& lastConversationId)
{
	if (conversationId()==curConversationID)
	{
		curConversationID.contains("conference.")?
			Biz::Session::getConverSationManager()->setGroupConversationMessageRead(conversationId()):
			Biz::Session::getConverSationManager()->setConversationMessageRead(conversationId());
	}

	if (conversationId()==lastConversationId)
	{
		mCommObject->deleteLastUnreadTip(mPage);
		mpUpUnread->hide();
	}
	//看看如果是虚拟账号，需要进行session,获取realid
	// 	if (MainApp::UIFrame::getVirtualAccountController()->IsVirtualAccount(Biz::MessageUtil::makeSureUserId(curConversationID)))
	// 	{
	// 		Biz::Session::getVirtualManager()->getRealAccountbyVirtualAccount(Biz::MessageUtil::makeSureUserId(curConversationID));
	// 	}

}

void BaseChatDialog::onConversationActived(const QString& curConversationID)
{
	if (curConversationID!=conversationId())
		return;
	auto getAllUnreadMessageCallback = receiver->createCallback<QSharedPointer<Biz::MessageListData>>([this, curConversationID](const QSharedPointer<Biz::MessageListData>& unreadmessage )
	{
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("BaseChatDialog::onConversationActived end %1 groupjid=%2 getMessageListsize=%3").arg(getmsgendticked).arg(curConversationID).arg(unreadmessage->getMessageList().size()));

		if (!unreadmessage->getMessageList().isEmpty())
		{
			conversationId().contains("conference.")?
				Biz::Session::getConverSationManager()->setGroupConversationMessageRead(conversationId()):
				Biz::Session::getConverSationManager()->setConversationMessageRead(conversationId());
		}
		else
		{
			QMap<QString,int> params;
			params.insert(conversationId(),0);
			emit Biz::Session::getConverSationManager()->sgConversationUnreadCountChange(params);
		}
	}, []{ });
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("BaseChatDialog::onConversationActived begin %1 groupjid=%2").arg(getmsgendticked).arg(curConversationID));
	Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);





}

void BaseChatDialog::onMainDialogVisableChange(bool visibility)
{
	if (!visibility)
	{
		if (MainApp::UIFrame::getConversationController()->topConversationId()==conversationId())
		{
			auto getAllUnreadMessageCallback = receiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& unreadmessage )
			{
				if (!unreadmessage.isNull() && unreadmessage->getMessageList().isEmpty())
				{
					mCommObject->deleteLastUnreadTip(mPage);
					mpUpUnread->hide();
				}
			}, []{ });
			Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);
		}
	}
}

void BaseChatDialog::cancelAnyNotice()
{
	QTimeLine* pCancleUnreadTip = new QTimeLine(5000,this);
	connect(pCancleUnreadTip,&QTimeLine::finished,[this,pCancleUnreadTip]{
		pCancleUnreadTip->deleteLater();
		this->mpUpUnread->setVisible(false);
		this->mpAtNotice->setVisible(false);
		QString strid = MainApp::UIFrame::getConversationController()->topConversationId();
		MainApp::UIFrame::getConversationController()->clearAtNotice(strid);
	});
	pCancleUnreadTip->start();
}


void BaseChatDialog::setupTextEdit(TextEdit* pTextEdit)
{
	if (NULL!=textEdit)
		textEdit->disconnect ();
	textEdit = pTextEdit;
	connect(textEdit, &TextEdit::sgAltS_Pressed, this, &BaseChatDialog::onAltS_Pressed);
	connect(textEdit, &TextEdit::sgCtrl_EnterPressed, this, &BaseChatDialog::onCtrl_EnterPressed);
	connect(textEdit, &TextEdit::sgEnter_Pressed, this, &BaseChatDialog::onEnter_Pressed);
	connect(textEdit, &TextEdit::sgShift_EnterPressed, this, &BaseChatDialog::onShift_EnterPressed);
	connect(textEdit, &TextEdit::sgPaste, this, &BaseChatDialog::onTextEditPaste);
}


void BaseChatDialog::sendVidioOrAutioMessage(int type)
{
	if (conversationId().isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));

	message->Body(type == AudeoVidioType::AUDEOTYPE ? QStringLiteral("实时语音聊天"):QStringLiteral("实时视频聊天"));

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(type == AudeoVidioType::AUDEOTYPE ? Biz::MediaTypeaudioReceiveRtcAudio : Biz::MediaTypeaudioReceiveRtc);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->cctext(m_cctext);
	message->bu(m_bu);
	if (Util::UtilHelper::isVirtualAccountId(conversationId(), Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		message->MsgSourceType(Biz::consult);

		QString realtoId = Util::UtilHelper::getRealIdfromID(conversationId());
		QString virtualId = UtilHelper::getvirtualfromID(conversationId());
		message->Realto(realtoId);
		message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
		message->ConversationID(virtualId);
		message->from(Biz::Session::currentAccount().accountData().UserID());


	}
	else
	{
		message->MsgSourceType(Biz::ChatMessage);
	}



	auto callback = receiver->createCallback([]{}, [this](){

	});
	auto presendcallback = receiver->createCallback([this, message](){
		appendMessage(false, false, message);
	}, [this](){});

	messageSendPrepare(message);

	Biz::Session::currentAccount().doSendMessage(message, callback, presendcallback);


	updateCurrentTick(message->UtcTime());


}

void BaseChatDialog::setupWebView(webview* pWebView)
{
	if (NULL!=mPWebView)
	{
		mPWebView->disconnect();
	}

	mPWebView = pWebView;
	connect (mPWebView,&webview::copyEventActionRequested,[this]{
		// onClipBoardSelectChanged();
	});
	mPWebView->installEventFilter(this);
}

void BaseChatDialog::openInternalUrl(const QString& url)
{
	QMap<QString,QString> contextInfo;
	contextInfo.insert ("fromjid",conversationId());
	contextInfo.insert ("chattype",conversationId().contains ("@conference.")?"1":"0");
	CommentWebViewSingleton::getInstance()->openCommonUrlWithCookie(QUrl(url).toEncoded(),contextInfo);
}

void BaseChatDialog::sendRequestUrl(const QString& url)
{
	int chatType = this->getChatType();
	if (Util::UtilHelper::isVirtualAccountId(conversationId(),Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		QString realtoId = Util::UtilHelper::getRealIdfromID(conversationId());
		QString virtualId = Util::UtilHelper::getvirtualfromID(conversationId());
		if (chatType == 8)
		{
			chatType = 5;
		}
		QtConcurrent::run(WebService::sendTPRequest,url,virtualId,realtoId,chatType);
	} else
	{
		QString realtoId = conversationId();
		QString virtualId = conversationId();
		QtConcurrent::run(WebService::sendTPRequest,url,virtualId,realtoId,chatType);
	} 
}

void BaseChatDialog::onBtnActionShareLocalMessage()
{
	// 将页面职位可选状态
	mCommObject->updateShareMessageInput(mPage,true);
}

// 单条消息直接转发
void BaseChatDialog::onWebViewShareOnMessage()
{
	// strTmpCustomContextMenuMsgId
	if (strTmpCustomContextMenuMsgId.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未选中消息，请在消息气泡上右击，重新选择消息"));
		return;
	}

	ConversationSelectWidgetSingleton::getInstance()->setConversationDataList();
	ConversationSelectWidgetSingleton::getInstance()->setExceptConversationIds(QStringList(conversationId()));
	ConversationSelectWidgetSingleton::getInstance()->exec();

	QString sendToConversationId = ConversationSelectWidgetSingleton::getInstance()->conversationId();
	if (!sendToConversationId.isEmpty())
	{
		//这地方加一个二次却的按钮
		QString strDisplay;
		QString strTitleInfo;
		if (sendToConversationId.contains("@conference."))
		{
			strDisplay = Biz::Session::getGroupManager()->getGroupNickName(sendToConversationId);
			if (strDisplay.isEmpty())
			{
				strDisplay = sendToConversationId;
			}
			strTitleInfo = QStringLiteral("你确定要转发给群[%1]吗？").arg(strDisplay);
		}
		else
		{
			strDisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(sendToConversationId);
			if (strDisplay.isEmpty())
			{
				strDisplay = sendToConversationId;
			}
			strTitleInfo = QStringLiteral("你确定要转发给[%1]吗？").arg(strDisplay);
		}


		if (MainApp::UIFrame::getNotifyCenterController()->alertMessage("",strTitleInfo,QStringLiteral("取消"),QStringLiteral("确定")))
		{
			if (!sendToConversationId.isEmpty())
			{
				auto getMessageByIdCallback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this,sendToConversationId](const QSharedPointer<Biz::XmppMessage>& spMessage){
					if (!spMessage.isNull())
					{
						QString oldid = spMessage->MessageID();

						spMessage->MessageID("");
						spMessage->ConversationID(sendToConversationId);
						spMessage->MsgDirection(Biz::MessageTypeSelf);
						spMessage->UtcTime(Biz::Session::getLoginManager()->getServerTimeWithOffset());
						spMessage->MsgSourceType(sendToConversationId.contains("conference")?Biz::GroupMessage:Biz::ChatMessage);
						spMessage->cctext(m_cctext);
						spMessage->bu(m_bu);

						spMessage->Realfrom(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
						auto callback = receiver->createCallback([this,sendToConversationId]()
						{
							//if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",QStringLiteral("转发成功，是否跳转到新会话?"),QStringLiteral("取消"),QStringLiteral("确定")))
							{
								MainApp::UIFrame::getConversationController()->activeConversation(sendToConversationId);
								MainApp::UIFrame::getConversationController()->moveSessionToTop(sendToConversationId);
								emit Biz::Session::getConverSationManager()->sgReloadConversationMsg(sendToConversationId);
							}

						}, [this,spMessage,sendToConversationId,oldid]{
							QString nenwid = spMessage->MessageID();
							Log::e(QStringLiteral("转发失败 send msg %1 (to:%3) to conversation %2").arg(sendToConversationId,oldid,nenwid));
						});

						Biz::Session::currentAccount().doSendMessage(spMessage,callback,NULL);
					}

				},[]{});
				Biz::Session::getMessageManager()->getMessageById(strTmpCustomContextMenuMsgId,getMessageByIdCallback);
			}
		}
	}

}

// action at onWebJsShareLocalMessage
void BaseChatDialog::onWebViewShareSelectedMessages(const QString&sharecoversationId)
{
	mCommObject->shareSelectedMessages(sharecoversationId,mPage);
}


QString bdecodeUrl(QString body, QMap<QString,QString>& guid2htmlstring)
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

QString bgetobjectbyMsg(const QSharedPointer<Biz::XmppMessage>& rawmsg)
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
	guid2Html.insert("&nbsp;"," ");
	guid2Html.insert("<br/>","\n");


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

			}

			QString strFullUrl = Biz::ConfigureHelper::makeFullUrl(val);
			QString savefileName = Biz::ConfigureHelper::getImageLocalSavePath(strFullUrl,Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()));

			if (QFile::exists(savefileName))
			{
				QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
				QString htmlString = QString("<img src='file:///%1'  />").arg(savefileName + QString("?w=%1&h=%2&").arg(w).arg(h) 
					+ QUuid::createUuid().toString().replace("{","").replace("}","").replace("-",""));
				strHtmllist.append(htmlString);

				item2Guid.insert(item,replaceKey);
				guid2Html.insert(replaceKey,htmlString);
				strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
			}
			else
			{
				QSharedPointer<Biz::XmppMessageAttachment> attachInfo(new Biz::XmppMessageAttachment);

				QString strImageId = Biz::ConfigureHelper::GetBufferMD5 (val);
				attachInfo->URL(strFullUrl);
				attachInfo->MD5(strImageId);
				QString  subDir = Biz::SpellHelper::MakeSpellCode(Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()),( Biz::SpellHelper::SpellOptions)0).trimmed();
				attachInfo->LOCALCOPY(QFile::exists(savefileName)?savefileName:"");
				//插入这些附件的信息
				Biz::Session::getAttachmentManager()->downloadAttachImage(rawmsg->ConversationID(),attachInfo);



				QString curDir = Biz::ConfigureHelper::GetDebugOrReleasePath(QCoreApplication::applicationDirPath());
				// 					QString htmlString = QString("<img src='%1'  />").arg(strFullUrl + "?w=%2&h=%3&" + QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","")
				// 						,w,h);
				QString htmlString = QString("<img src='file:///%1'  />").arg(savefileName);

				strHtmllist.append(htmlString);

				item2Guid.insert(item,replaceKey);
				guid2Html.insert(replaceKey,htmlString);
				strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
			}


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

				// 					QSharedPointer<Biz::XmppMessageAttachment> attachInfo(new Biz::XmppMessageAttachment);
				// 					// 条件貌似写多了，只有图片才需要更改前缀，备忘。added by may
				// 					QString strFullUrl = Biz::ConfigureHelper::makeFullUrl(strUrl);
				// 					QString strImageId = Biz::ConfigureHelper::GetBufferMD5 (strUrl);
				// 					attachInfo->URL(strFullUrl);
				// 					attachInfo->MD5(strImageId);
				// 					QString localDir = Biz::ConfigureHelper::UserTempPath(Biz::Session::getAccountManager()->accountData().UserID());
				// 					QString  subDir = Biz::SpellHelper::MakeSpellCode(Biz::MessageUtil::makeSureUserId(rawmsg->ConversationID()),( Biz::SpellHelper::SpellOptions)0).trimmed();
				// 					localDir += subDir;
				// 					QString savefileName = QFileInfo(QDir(localDir),strImageId).absoluteFilePath ();
				// 					attachInfo->LOCALCOPY(QFile::exists(savefileName)?savefileName:"");


				//插入这些附件的信息
				//Biz::Session::getAttachmentManager()->downloadAttachImage(rawmsg->ConversationID(),attachInfo);
			}
		} else if( objectTypeUrl == type) {
#pragma region linkparser
			QString rawUrl = QUrl(val).toEncoded();
			QString htmlString = val.toHtmlEscaped();/*QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,val.toHtmlEscaped());*/
			strHtmllist.append(htmlString);

			item2Guid.insert(item,replaceKey);
			guid2Html.insert(replaceKey,htmlString);
			strRawMsgBody.replace(strRawMsgBody.indexOf(item),item.length(),replaceKey);
#pragma endregion linkparser
		}
		pos += replaceKey.length();
	}  

	strRawMsgBody = bdecodeUrl(strRawMsgBody,guid2Html);

	strRawMsgBody = strRawMsgBody.toHtmlEscaped();
	strRawMsgBody = strRawMsgBody.replace(" ","&nbsp;");
	strRawMsgBody = strRawMsgBody.replace("\r\n","<br/>");
	strRawMsgBody = strRawMsgBody.replace("\n","<br/>");

	foreach(QString key,guid2Html.keys()){
		strRawMsgBody.replace(key,guid2Html.value(key));
	}

	return strRawMsgBody;
}

void BaseChatDialog::onWebViewReferenceOnMessage( )
{ 
	if (strTmpCustomContextMenuMsgId.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未选中消息，请在消息气泡上右击，重新选择消息"));
		return;
	}


	auto getMessageByIdCallback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this](const QSharedPointer<Biz::XmppMessage>& spMessage){

		if (!spMessage.isNull())
		{
			QString oldid = spMessage->MessageID();

			QString conversationId = spMessage->ConversationID();
			int Direction = spMessage->MsgDirection();
			int sourceType = spMessage->MsgSourceType();
			int mediatype  = spMessage->MediaType();
			QString strDisplay;
			QString strbody = spMessage->Body();

			//对body 根据类型对body 需要处理一下
			QString bodydata = bgetobjectbyMsg(spMessage);

			if (Biz::MessageDirection::MessageTypeOther == Direction)
			{
				if (Biz::MessageSourceType::GroupMessage == sourceType)
				{
					// 暂时 处理方法
					QString strUserId ;
					if(!spMessage->SenderJid().isEmpty())
					{
						strUserId = spMessage->SenderJid();
					}
					else if(!spMessage->Realfrom().isEmpty())
					{
						strUserId = spMessage->Realfrom();
					}
					else
					{
						// nothing
					}

					if(!strUserId.isEmpty())
					{
						QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(strUserId);
						// 引用默认显示昵称 不显示备注
						if (!spPerson.isNull() && !spPerson->strNickName.isEmpty())
						{
							strDisplay = spPerson->strNickName;
						}
					}
				} 
				else if (Biz::MessageSourceType::consult == sourceType)
				{
					strDisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(spMessage->Realfrom());
				}
				else
				{
					strDisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
				}

			} else {
				QString selfid = Biz::Session::currentAccount().accountData().UserID();
				strDisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(selfid);
			}

			QString newMessage;
			if(bodydata.contains("<img src="))

			{
				newMessage = QStringLiteral(" 「%1:%2」<br/>\n %3 \n<br/> ").arg(strDisplay).arg(bodydata).arg(mspline);
			}
			else
			{
				newMessage = QStringLiteral(" 「%1:%2」\n %3 \n").arg(strDisplay).arg(bodydata).arg(mspline);
			}

			textEdit->setText(newMessage);
			QTextCursor cursor = textEdit->textCursor();
			cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
			textEdit->setTextCursor(cursor);
			textEdit->setFocus(Qt::MouseFocusReason);
		}


	},[]{});
	Biz::Session::getMessageManager()->getMessageById(strTmpCustomContextMenuMsgId,getMessageByIdCallback);
}

// request at onWebViewShareSelectedMessages
void BaseChatDialog::onWebJsShareLocalMessage(const QString& shareconversaionId,const QStringList& messageids)
{
	if (messageids.isEmpty())
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("没勾选任何消息，请确认消息列表"));
		return;
	}

	ConversationSelectWidgetSingleton::getInstance()->setConversationDataList();
	ConversationSelectWidgetSingleton::getInstance()->setExceptConversationIds(QStringList(conversationId()));
	int nResult = ConversationSelectWidgetSingleton::getInstance()->exec();

	QString sendtoConversationId = ConversationSelectWidgetSingleton::getInstance()->conversationId();

	QString strDisplay;
	QString strTitleInfo;
	if (!sendtoConversationId.isEmpty())
	{
		if (sendtoConversationId.contains("@conference."))
		{
			strDisplay = Biz::Session::getGroupManager()->getGroupNickName(sendtoConversationId);
			if (strDisplay.isEmpty())
			{
				strDisplay = sendtoConversationId;
			}
			strTitleInfo = QStringLiteral("你确定要转发给群[%1]吗？").arg(strDisplay);
		}
		else
		{
			strDisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(sendtoConversationId);
			if (strDisplay.isEmpty())
			{
				strDisplay = sendtoConversationId;
			}
			strTitleInfo = QStringLiteral("你确定要转发给[%1]吗？").arg(strDisplay);
		}


		if (MainApp::UIFrame::getNotifyCenterController()->alertMessage("",strTitleInfo,QStringLiteral("取消"),QStringLiteral("确定")))
		{


			if (!sendtoConversationId.isEmpty())
			{
				auto getMessageByIdsCallback = receiver->createCallback<QString>([this,messageids,sendtoConversationId,shareconversaionId](const QString& url){

					auto callback = receiver->createCallback([this,sendtoConversationId]()
					{
						//if (MainApp::UIFrame::getNotifyCenterController ()->alertMessage ("",QStringLiteral("转发成功，是否跳转到新会话?"),QStringLiteral("取消"),QStringLiteral("确定")))
						{
							MainApp::UIFrame::getConversationController()->activeConversation(sendtoConversationId);
							MainApp::UIFrame::getConversationController()->moveSessionToTop(sendtoConversationId);
							emit Biz::Session::getConverSationManager()->sgReloadConversationMsg(sendtoConversationId);
						}

					}, [this,sendtoConversationId]{
						Log::e(QStringLiteral("转发失败 send msg to conversation %1").arg(sendtoConversationId));
					});

					Biz::Session::getConverSationManager()->sendShareMessage(shareconversaionId,sendtoConversationId,url,callback);
				},[]{});
				Biz::Session::getMessageManager()->getMessageListByIds(messageids,getMessageByIdsCallback);


				mCommObject->updateShareMessageInput(mPage,false);
				m_pShareToButton->setVisible(false);
			}
			else
			{
				mCommObject->updateShareMessageInput(mPage,false);
			}
		}
		else
		{
			mCommObject->updateShareMessageInput(mPage,false);
		}
	}
	else
	{
		mCommObject->updateShareMessageInput(mPage,false);
	}

}



void BaseChatDialog::appendMessage( 
	bool isHistory, 
	bool hasMore, 
	const QList<QSharedPointer<Biz::XmppMessage>>& messages, int ntype)
{	
	//存放的是附件信息
	QList<QSharedPointer<Biz::XmppMessage>> messageToBeShow;
	for(QSharedPointer<Biz::XmppMessage> msg : messages)
	{
		if (msg.isNull())
		{
			continue;
		}
		bool bShow = true;
		if (msg->MediaType() == Biz::MediaTypeEncrypt)
		{
			QString EncryptKey = MainApp::UIFrame::getConversationController()->getEncryptPwdbyconversationId(conversationId());
			if (!EncryptKey.isEmpty())
			{


				QString body = msg->ExtendInfo();
				QString dencybody;
				bool bret = Aes_CbC_PKCS7_Decrypt(EncryptKey, body, dencybody);
				if (bret)
				{
					QJsonDocument Json_Data = QJsonDocument::fromJson(dencybody.trimmed().toUtf8());

					QVariantMap dataMap = Json_Data.toVariant().toMap();
					int mediatype = dataMap["MsgType"].toInt();
					QString content = dataMap["Content"].toString();

					msg->MediaType((Biz::MessageMediaType)mediatype);
					msg->Body(content.isEmpty()?QStringLiteral("[解密失败]"):content);
					msg->MsgSourceType(Biz::ChatMessage);
				}
				else
				{
					msg->Body(QStringLiteral("[解密失败]"));
				}
			}
		}
		if (msg->MediaType() == Biz::MessageTypeMarkdown)
		{
			QString body = msg->Body();
			QString content = UtilHelper::getMarkdownString(body);
			if (!content.isEmpty())
			{
				msg->Body(content);
			}

		}
		if (msg->MediaType() == Biz::MessageTypeAt)
		{
			//
			dochangeBodyAtInofr(msg);
		}

		preFormatMessageToHtml(msg,isHistory,hasMore,bShow);
		if (m_bWebShereMessageSelectStatus)
			msg->DisplayFlag(msg->DisplayFlag()|Biz::XmppMessage::MessageDisplayFlag::MDF_SHAREMESSAGE);
		if(msg->MsgSourceType() == Biz::subscription && msg->MediaType()== Biz::MediaTypeRobotQiangDanStatus)
		{
			continue;
		}
		if(msg->MsgSourceType() == Biz::encrypt 
			&& (msg->MediaType()== Biz::EncryptMessageType::EncryptMessageType_Begin
			||  msg->MediaType()== Biz::EncryptMessageType::EncryptMessageType_Agree
			|| msg->MediaType()== Biz::EncryptMessageType::EncryptMessageType_Close 
			|| msg->MediaType()== Biz::EncryptMessageType::EncryptMessageType_Cancel  )  )
		{

			continue;

		}
		if (bShow)
			messageToBeShow.append(msg);
	}

	mCommObject->appendMessageJavescrip(mPage, isHistory, hasMore, messageToBeShow, ntype/* nouse*/);

	for(QSharedPointer<Biz::XmppMessage> msg : messages)
	{
		afterFormatShowMessage(msg,isHistory,hasMore);
	}

}

void BaseChatDialog::appendMessage( 
	bool isHistory, 
	bool hasMore, 
	const QSharedPointer<Biz::XmppMessage>& message, int ntype)
{
	QList<QSharedPointer<Biz::XmppMessage>> list;
	list.append(message);
	appendMessage(isHistory, hasMore, list, ntype);
}

void BaseChatDialog::onConversationReadedByOtherClient(const QString& conversationid,quint64 ulLastTimeInDb)
{
	Q_UNUSED(ulLastTimeInDb);

	if (conversationId()!=conversationid) return;

	mCommObject->deleteLastUnreadTip(mPage);
	mpUpUnread->hide();

	mpAtNotice->setVisible(false);
}

void BaseChatDialog::onAllConversationReadedByOtherClient(quint64 ulLastTimeInDb)
{
	Q_UNUSED(ulLastTimeInDb);
	mCommObject->deleteLastUnreadTip(mPage);
	mpUpUnread->hide();
}

void BaseChatDialog::onSendFileByWebClick(const QString& guid)
{
	if(conversationId().isEmpty())
		return;

	// 由guid去获取本地的发送缓存
	auto callback = receiver->createCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>(
		[this,guid](const QList<QSharedPointer<Biz::XmppMessageAttachment>>& lst ){
			if (lst.isEmpty())
			{
				Log::e("get send file local path fail");
				return;
			}

			QString localPath = lst.at(0)->LOCALCOPY();
			QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
			message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
			message->MediaType(Biz::MediaTypeFile);
			message->MsgDirection(Biz::MessageTypeSelf);
			message->MsgSourceType(Biz::UnKnow);
			QStack<QString> mstack;
			mstack.append(localPath);
			message->localUrls(mstack);
			message->SendFileID(guid);
			message->MessageID(guid);
			message->Realfrom(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
			message->cctext(m_cctext);
			message->bu(m_bu);

			//先上传后显示
			auto callback = receiver->createCallback([this, message]()
			{
				if(message->ConversationID() != conversationId()){
					return;
				}
				//需要展示在最后一条消息处
				MainApp::UIFrame::getConversationController()->updateChatContent(conversationId(), message);
				Biz::Session::currentAccount().doSendCancelFile( "", false);
			}, [this,guid]{
				mCommObject->uploadFail(mPage,guid);
			});
			//这地方应该把发送完的内容给清掉
			cleanWillSendMsg();

			messageSendPrepare (message);
			Biz::Session::currentAccount().doSendMessage(message, callback,NULL);

	},[this](){});
	Biz::Session::getAttachmentManager ()->getFileLocalPathByUrl (guid,callback);
}

void BaseChatDialog::onCancelSendFileByWebClick( const QString& msgid )
{
	if(conversationId().isEmpty())
		return;

	// 由guid去获取本地的发送缓存
	auto callback = receiver->createCallback<QList<QSharedPointer<Biz::XmppMessageAttachment>>>(
		[this,msgid](const QList<QSharedPointer<Biz::XmppMessageAttachment>>& lst ){
			if (lst.isEmpty())
			{
				Log::e("get send file local path fail");
				return;
			}

			QString localPath = lst.at(0)->LOCALCOPY();



			Biz::Session::currentAccount().doSendCancelFile( conversationId(), true);




	},[this](){});
	Biz::Session::getAttachmentManager ()->getFileLocalPathByUrl (msgid,callback);
}

void BaseChatDialog::onSendClick(bool)
{
	if(conversationId().isEmpty())
		return;
	QString text;
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
	if (mMarkdown)
	{
		text = textEdit->toPlainText();
		text = text.replace("MarkDown>", "");
		text = UtilHelper::getMarkdownString(text);
	}
	else
	{
		text = textEdit->getText(message->localUrls(), conversationId());
		if(text.trimmed().isEmpty()){
			return;
		}
	}
	if (text.contains(mspline) && (text.contains("[obj type=\"emoticon\"") || text.contains("[obj type=\"image\"") ))
	{
		//QString newline = QString("\n %1 \n").arg(mspline);
		text = text.replace(mspline, "\n"+mspline+"\n");
	}
	int nlength = text.length();
	if (nlength > MYBYTE*10)
	{
		UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("发送的字符太长，请分多次发送"));
		return;
	}

	QString EncryptKey = MainApp::UIFrame::getConversationController()->getEncryptPwdbyconversationId(conversationId());
	if (!EncryptKey.isEmpty())
	{

		//进行加密
		QString contentdata;
		QJsonObject obj;
		obj.insert("MsgType", Biz::MediaTypeText);
		obj.insert("Content",text);

		QString paramValue = QJsonDocument(obj).toJson (QJsonDocument::Compact);

		bool bret = Aes_CbC_PKCS7_Encrypt(EncryptKey, paramValue, contentdata);
		message->ExtendInfo(contentdata);
		message->Body(QStringLiteral("[加密消息]"));

		message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
		message->MediaType(Biz::MediaTypeEncrypt);
		message->MsgDirection(Biz::MessageTypeSelf);
		message->MsgSourceType(Biz::UnKnow);

	}
	else
	{
		message->Body(text);
		message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
		if (mMarkdown)
		{
			message->MediaType(Biz::MessageTypeMarkdown);
		}
		else
			message->MediaType(Biz::MediaTypeText);
		message->MsgDirection(Biz::MessageTypeSelf);
		message->MsgSourceType(Biz::UnKnow);


	}
	QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->MessageID(uuid);
	message->cctext(m_cctext);
	message->bu(m_bu);
	message->Realfrom(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
	//是否发送code
	if (m_codehightlight)
	{

		QString stylecode = QString("language-%1 hljs").arg(m_codeType);
		QString strextenInf = UtilHelper::getHightLightCodeStringToJson(text,uuid, m_codeStyle, stylecode);

		message->ExtendInfo(strextenInf);

		message->MediaType(Biz::MediaTypeCodeHLight);
	}

	auto callback = receiver->createCallback([]{}, [this](){
		// 发送图片失败
		QString sendAttachmentFail = T_("sendMessageFail");
		mCommObject->systemnotify(mPage,sendAttachmentFail);
		mCommObject->scrollToEnd(mPage);
		cleanWillSendMsg();
	});
	auto presendcallback = receiver->createCallback([this, message](){

		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("BaseChatDialog::onSendClick end %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));
		appendMessage(false,false,message);
		MainApp::UIFrame::getConversationController()->updateChatContent(conversationId(), message);
	},[this](){});

	messageSendPrepare (message);
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("BaseChatDialog::onSendClick begin %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));
	int media = message->MediaType();
	Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);


	QSharedPointer<MimeTypeMessage> mimeTypeMessage = textEdit->getMimeTypeMessage();
	appendRecentMessage(mimeTypeMessage);

	textEdit->clear();
	textEdit->clearAnimation();
	updateCurrentTick(message->UtcTime());

	cancelAnyNotice();
	media = message->MediaType();

	//发送完后，code的checkbox 设置成为未勾选
	if (message->MediaType() == Biz::MediaTypeCodeHLight)
	{
		afterSendCode();
	}
}
void BaseChatDialog::setScrollPos( int pos )
{
	mCommObject->setScollPos(pos, mPage);
}

bool BaseChatDialog::appendRawMessage( const QSharedPointer<Biz::XmppMessage>& message )
{
	if (!message.isNull() && Biz::MediaTypeWeiDaoYou == message->MediaType())
	{
		QString strExtendInfo = message->ExtendInfo();
		QJsonParseError err;
		QVariantMap dataMap = QJsonDocument::fromJson(strExtendInfo.toUtf8(),&err).toVariant().toMap();
		if (dataMap.contains("htmlcontent"))
		{
			QString strHtml = dataMap.value("htmlcontent").toString();


			QJsonObject paramJson;
			paramJson.insert("htmlcontent",strHtml);
			paramJson.insert("time",QString::number(message->UtcTime()));
			QString str = QString("pushMessage(%1)").arg(QString(QJsonDocument(paramJson).toJson(QJsonDocument::Compact)));
			mPage->runLocalJavaScript(str);

			return true;
		}
	}
	if (!message.isNull() && Biz::MediaTypeRobotQiangDanStatus == message->MediaType())
	{

		QString strExtendInfo = message->ExtendInfo();
		QJsonParseError err;
		QVariantMap dataMap = QJsonDocument::fromJson(strExtendInfo.toUtf8(),&err).toVariant().toMap();
		QString strdealid = dataMap.value("dealId").toString();
		int nStatus = dataMap.value("status").toInt();
		QString strDisplay = dataMap.value("btnDisplay").toString();
		QString DealId = QString("%1_btndeal").arg(strdealid);
		bool bret = false;

		QString str = QString("QiangdanMessageStatus(\'%1\',\'%2\',\'%3\')").arg(DealId, "false", strDisplay);
		mPage->runLocalJavaScript(str);

		return true;

	}

	return false;
}

void BaseChatDialog::onSnapFinish( const QString&wid )
{
	if(conversationId() != wid)
		return;
	QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
	QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
	QApplication::clipboard()->pixmap().save(fileName, "PNG");


	textEdit->insertImage(fileName);
	//发送图片
	//SendPic(fileName);
	textEdit->setFocus();

	//如果隐藏了，就显示出来
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
	if (settingconfig->SetJietu())
	{
		emit GloableEventObject::getInstance()->sgShowMainWidge();
	}
}

void BaseChatDialog::onSnapCancel( const QString& wid )
{
	if(conversationId() != wid)
		return;
	textEdit->setFocus();
}

void BaseChatDialog::sendSayHelloMessage()
{
	if (conversationId().isEmpty())
	{
		Log::e("BaseChatDialog::sendSayHelloMessage peeris isempty");
		return;
	}

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
	message->Body("#sayhello#");
	quint64 nTimecurrent = QDateTime::currentDateTime().toMSecsSinceEpoch();
	quint64 nDextime = Biz::Session::currentAccount().getTimeOffsetFromServer();
	message->UtcTime(nTimecurrent-nDextime);
	message->MediaType(Biz::MediaTypeAction);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::subscription);
	message->ExtendInfo("sayhello");

	Biz::Session::currentAccount().doSendMessage(message,NULL,NULL);
}


void BaseChatDialog::preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore, bool& bShow)
{
	Q_UNUSED(spMessage);Q_UNUSED(isHistory);Q_UNUSED(hasMore);
}

void BaseChatDialog::afterFormatShowMessage(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore)
{
	Q_UNUSED(spMessage);Q_UNUSED(isHistory);Q_UNUSED(hasMore);
}

void BaseChatDialog::afterSendCode()
{

}

void BaseChatDialog::sendFile(const QString& fileFullPath)
{
	if(conversationId().isEmpty() || fileFullPath.isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(Biz::MediaTypeFile);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::UnKnow);

	QStack<QString> mstack;
	mstack.append(fileFullPath);
	message->localUrls(mstack);
	auto guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->SendFileID(guid);
	message->MessageID(guid);
	message->LocalFlag(Biz::MESSAGESTATE_LOCAL_SENDSUCCESS);

	messageSendPrepare (message);

	//显示发送提示框 没有进行发送
	auto callback = receiver->createCallback([this,message](){
		appendMessage(false, false, message);
	},[](){});

	// 用一个临时的gui形成一个 键值对，这个guid被带入到html，当点击发送的时候，再从数据库里查找这个guid对应的本地路径，防止本地路径从html里绕一圈出来之后被各种转义的问题。
	QSharedPointer<Biz::XmppMessageAttachment> spXMA(new Biz::XmppMessageAttachment);
	spXMA->URL(guid);
	spXMA->LOCALCOPY(fileFullPath);
	Biz::Session::getAttachmentManager ()->saveMessageAttchmentInfo (spXMA,callback);
}

void BaseChatDialog::sendPicutre(const QString& picFullPath)
{
	if(conversationId().isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());

	message->MediaType(Biz::MediaTypeText);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::UnKnow);
	message->cctext(m_cctext);
	message->bu(m_bu);
	QStack<QString> mstack;
	mstack.append(picFullPath);
	message->localUrls(mstack);
	QImage img(picFullPath);

	//如果发送图片，则要在body中带上
	QString strLocalFileName=QString("[obj type=\"image\" value=\"%1\" width=%2 height=%3]").arg(picFullPath).arg(img.width()).arg(img.height());
	message->Body(strLocalFileName);


	auto callback = receiver->createCallback([]{}, [this](){
		// 发送图片失败
		QString sendAttachmentFail = T_("sendMessageFailOnly");
		mCommObject->systemnotify(mPage,sendAttachmentFail);
		mCommObject->scrollToEnd(mPage);
	});
	auto presendcallback = receiver->createCallback([this, message](){
		appendMessage(false,false,message);
	},[this](){});

	messageSendPrepare (message);

	Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);
}

void BaseChatDialog::onUploadFileProgress(const QString&key, qint64 done, qint64 total)
{
	if (NULL!=mCommObject && NULL!=mPage)
	{
		mCommObject->sendFileProgress(mPage,key, done, total);
	}
}

void BaseChatDialog::onUploadFileOver(const QString& key)
{
	if (NULL!=mCommObject && NULL!=mPage)
	{
		QString strMd5 = Biz::ConfigureHelper::GetBufferMD5(key);
		mCommObject->UploadOver(mPage,strMd5);

		QSharedPointer<Biz::XmppMessage> spMessage (new Biz::XmppMessage(""));
		spMessage->MessageID(key);
		spMessage->LocalFlag(spMessage->LocalFlag()|Biz::MESSAGESTATE_LOCAL_SENDSUCCESS);
		spMessage->LocalFlag(spMessage->LocalFlag() & ~Biz::MESSAGESTATE_LOCAL_SENDING);
		onUpdateMessageSendStatus(spMessage);
	}
}

void BaseChatDialog::onRecvFileProgressDisplay(const QString& key, const QString&filename,qint64 done, qint64 total)
{
	if (NULL!=mCommObject && NULL!=mPage)
	{
		mCommObject->RecvFileProgress(mPage,key, filename, done, total);
	}
}

void BaseChatDialog::onUpdateReplaceImage( const QString& msgid, const QString& newfilepath )
{
	if (NULL!=mCommObject && NULL!=mPage)
	{
		mCommObject->updateMessageSendPicSrc(mPage,msgid, newfilepath);
	}
}

void BaseChatDialog::onInsertTextPast()
{
	if (PastTextmimeData)
	{
		QString plainText = PastTextmimeData->text();
		textEdit->insertPlainText (plainText);
	}


}

void BaseChatDialog::onInsertImagePast()
{
	QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
	QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
	QApplication::clipboard()->pixmap().save(fileName, "PNG");
	textEdit->insertImage(fileName);
}


void BaseChatDialog::appendWillSendMsg()
{
	//这时候需要保存，输入的字符
	QSharedPointer<MimeTypeMessage> mimeTypeMessage = textEdit->getMimeTypeMessage();
	MainApp::UIFrame::getConversationController()->updateWillSend(conversationId(), mimeTypeMessage);
}

void BaseChatDialog::ShowInputWillSendMsg()
{
	//这里显示输入框中即将要发送的消息
	textEdit->setMimeTypeMessage(MainApp::UIFrame::getConversationController()->getWillSend(conversationId()));
}

void BaseChatDialog::cleanWillSendMsg()
{
	QSharedPointer<MimeTypeMessage> mimeTypeMessage(new MimeTypeMessage);
	MainApp::UIFrame::getConversationController()->updateWillSend(conversationId(), mimeTypeMessage);
}

void BaseChatDialog::onSetHistoryMsgCount( int ncount )
{
	mCommObject->setcounthtmlMsgCount(mPage, ncount);
}

void BaseChatDialog::onBaseOpenUrl( const QString& url )
{
	onOpenUrl(url);

}

void BaseChatDialog::SendPingByVideoAndAudeo( int Mediatype )
{
	if (conversationId().isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));

	message->Body("");

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(Mediatype == Biz::MediaTypeaudioReceiveRtc ? Biz::MediaTypeVideoPing : Biz::MediaTypeAudeoPing);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::webrtc);
	message->cctext(m_cctext);
	message->bu(m_bu);

	auto callback = receiver->createCallback([]{}, [this](){

	});
	auto presendcallback = receiver->createCallback([this, message](){
		//appendMessage(false, false, message);
	}, [this](){});

	messageSendPrepare(message);

	Biz::Session::currentAccount().doSendMessage(message, callback, presendcallback);


	updateCurrentTick(message->UtcTime());
}


void BaseChatDialog::SendGroupRoomVideoMessage(const QString&json, const QString&groupjid)
{
	if (groupjid.isEmpty())
	{
		return;
	}

	if (conversationId().isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(groupjid));

	message->Body(QStringLiteral("[当前客户端不支持此消息,请升级客户端]"));

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(Biz::MediaTypeVideoRoom);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::GroupMessage);
	message->ExtendInfo(json);
	message->cctext(m_cctext);
	message->bu(m_bu);

	auto callback = receiver->createCallback([]{}, [this](){

	});
	auto presendcallback = receiver->createCallback([this, message](){
		appendMessage(false, false, message);
	}, [this](){});

	messageSendPrepare(message);

	Biz::Session::currentAccount().doSendMessage(message, callback, presendcallback);


	updateCurrentTick(message->UtcTime());
}

void BaseChatDialog::onOpenUrlbyPcWeb( const QString& url )
{
	QDesktopServices::openUrl(QUrl(url));
}

void BaseChatDialog::showAtBlock( const QString&conversationId, const QString&msgid )
{

}

void BaseChatDialog::onSendFile( const QString&filePath )
{

}

void BaseChatDialog::onCodeHightLight( bool bret, const QString& style, const QString&type )
{
	m_codehightlight = bret;
	m_codeStyle = style;
	m_codeType = type;

	if (bret)
	{
		mCommObject->loadCSS(mPage);
		mCommObject->loadJS(mPage);
	}
}

void BaseChatDialog::onCodeStyle( const QString& style )
{
	m_codeStyle = style;
}

void BaseChatDialog::onCodeType( const QString& type )
{
	m_codeType = type;
}

void BaseChatDialog::onSendMessage( const QString& body, int type, const QString&conversationId )
{
	if(conversationId.isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId));
	QString text = body;
	if(text.trimmed().isEmpty()){
		return;
	}
	message->Body(text);

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType((Biz::MessageMediaType)type);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::encrypt);
	QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->MessageID(uuid);
	message->cctext(m_cctext);
	message->bu(m_bu);

	auto callback = receiver->createCallback([]{}, [this](){

	});
	auto presendcallback = receiver->createCallback([this, message,conversationId](){

		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("BaseChatDialog::onSendClick end %1 conversationId=%2").arg(getmsgendticked).arg(conversationId));

	},[this](){});

	message->MsgSourceType(Biz::encrypt);
	Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);
}



void BaseChatDialog::SetParentId( const QString& id )
{
	mparentId = id;
}

QString BaseChatDialog::getParentId()
{
	return mparentId;
}

void BaseChatDialog::SetChatType( int type )
{
	mChatType = type;
}

int BaseChatDialog::getChatType()
{
	return mChatType;
}


void BaseChatDialog::ShowTipMessageOnHistory()
{
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(Biz::MessageUtil::makeSureUserJid(Util::TIP_TIP_ID)/*conversationId()*/));


	message->Body(QStringLiteral("markdown提示信息\n 输入 :quit 退出该模式 \n /markdown 开始markdown的字符发送"));
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(Biz::MediaTypeText);
	message->MsgDirection(Biz::MessageTypeOther);
	message->MsgSourceType(Biz::UnKnow);



	QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->MessageID(uuid);
	message->cctext(m_cctext);
	message->bu(m_bu);

	QString sendid = Biz::MessageUtil::makeSureUserJid(Util::TIP_TIP_ID);
	message->SenderJid(sendid);
	message->Realfrom(sendid);


	appendMessage(false, false, message);
}

void BaseChatDialog::setLastInforItem( const QList<QSharedPointer<Biz::XmppMessage>>& messagelist )
{
	if (messagelist.size() <= 0)
	{
		return;
	}


	QSharedPointer <Biz::XmppMessage> msg = messagelist.at(messagelist.size() - 1);

	MainApp::UIFrame::getConversationController()->updateChatContent(conversationId(), msg);

}

void BaseChatDialog::onSendMessageByType( const QString& body, int mediatype, int sourcetype,const QString&conversationId )
{
	if(conversationId.isEmpty())
		return;

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId));
	QString text = body;
	if(text.trimmed().isEmpty()){
		return;
	}
	message->Body(text);

	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType((Biz::MessageMediaType)mediatype);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType((Biz::MessageSourceType)sourcetype);
	QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->MessageID(uuid);
	message->cctext(m_cctext);
	message->bu(m_bu);

	auto callback = receiver->createCallback([]{}, [this](){

	});
	auto presendcallback = receiver->createCallback([this, message,conversationId](){

		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("BaseChatDialog::onSendClick end %1 conversationId=%2").arg(getmsgendticked).arg(conversationId));
		appendMessage(false,false,message);
		MainApp::UIFrame::getConversationController()->updateChatContent(conversationId, message);
	},[this](){});

	message->MsgSourceType((Biz::MessageSourceType)sourcetype);

	messageSendPrepare (message);


	Biz::Session::currentAccount().doSendMessage(message, callback,presendcallback);
}

void BaseChatDialog::onSelfFontChange()
{
	QTextCursor cursor = textEdit->textCursor();
	textEdit->selectAll();
	QString text = Biz::Session::getSettingConfig()->MFontFamily();
	textEdit->setTextCursor( cursor );
	textEdit->setStyleSheet(QString("	font-size:%1px;\n"
		"   font-family:'%2';")
		.arg(Biz::Session::getSettingConfig()->MFontSize() < Biz::Session::getSettingConfig()->MInputFontSize() ? Biz::Session::getSettingConfig()->MInputFontSize():Biz::Session::getSettingConfig()->MFontSize())
		.arg(Biz::Session::getSettingConfig()->MFontFamily()));

}


void BaseChatDialog::setTextEditStyle()
{

	textEdit->setStyleSheet(QString("	font-size:%1px;\n"
		"   font-family:'%2';")
		.arg(Biz::Session::getSettingConfig()->MFontSize() < Biz::Session::getSettingConfig()->MInputFontSize() ? Biz::Session::getSettingConfig()->MInputFontSize():Biz::Session::getSettingConfig()->MFontSize() )
		.arg(Biz::Session::getSettingConfig()->MFontFamily()));
	/*QTextCursor cursor = ui->textEdit->textCursor();
	ui->textEdit->selectAll();
	QString text = Biz::Session::getSettingConfig()->MFontFamily();
	ui->textEdit->setFontPointSize(Biz::Session::getSettingConfig()->MFontSize());
	ui->textEdit->setFontFamily(Biz::Session::getSettingConfig()->MFontFamily());
	ui->textEdit->setStyleSheet(QString("	font-size:%1px;\n"
	"   font-family:'%2';"
	"	color:#FF0000;\n")
	.arg(Biz::Session::getSettingConfig()->MFontSize())
	.arg(Biz::Session::getSettingConfig()->MFontFamily()));
	ui->textEdit->setTextCursor( cursor );*/
	/*QFont font;
	font.setFamily(Biz::Session::getSettingConfig()->MFontFamily());
	font.setPointSize(Biz::Session::getSettingConfig()->MFontSize());
	ui->textEdit->setFont(font);

	QTextCharFormat format;//文本字符格式

	format.setFontFamily(Biz::Session::getSettingConfig()->MFontFamily());
	format.setFontPointSize(Biz::Session::getSettingConfig()->MFontSize());
	//format.setForeground(Qt::red);


	QTextCursor cursor = ui->textEdit->textCursor();//获取文本光标
	cursor.mergeCharFormat(format);//光标后的文字就用该格式显示
	ui->textEdit->setCurrentCharFormat(format);*/
	//ui->textEdit->mergeCurrentCharFormat(fmt);//textEdit使用当前的字符格式
}

void BaseChatDialog::onWebViewCopyMenu()
{
	if (strTmpCustomContextMenuMsgId.isEmpty())
	{
		//MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未选中消息，请在消息气泡上右击，重新选择消息"));
		this->mPWebView->triggerPageAction(WebPage::Copy);
		return;
	}


	auto getMessageByIdCallback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this](const QSharedPointer<Biz::XmppMessage>& spMessage){
		if (!spMessage.isNull())
		{
			if (spMessage->MediaType() == Biz::MediaTypeVote)
			{
				QString strbody = spMessage->ExtendInfo();
				QVariantMap map = QJsonDocument::fromJson(strbody.toUtf8()).toVariant().toMap();
				QString strlink = map["linkurl"].toString();
				//把这个值写进剪贴板
				QClipboard *border = QApplication::clipboard();
				border->setText(strlink);

			}
			else
			{
				this->mPWebView->triggerPageAction(WebPage::Copy);
			}
		}
		else
			this->mPWebView->triggerPageAction(WebPage::Copy);

	},[]{});
	Biz::Session::getMessageManager()->getMessageById(strTmpCustomContextMenuMsgId,getMessageByIdCallback);

}

void BaseChatDialog::onConversationMessageStateChange(const QString& cid,QMap<QString,QPair<int,int>> msgStatus)
{
	if (cid == conversationId())
	{
		foreach(QString messageid , msgStatus.keys()){
			QString text = (Biz::MESSAGESTATE_REMOTE_READED != (Biz::MESSAGESTATE_REMOTE_READED& msgStatus.value(messageid).first)) ?
				QStringLiteral("未读"): QStringLiteral("已读");
			if (!Biz::Session::getSystemConfig()->NAV_ABILITI_ShowMsgStat())
				text = "";

			mCommObject->jsSetMessageStatus(mPage,messageid,text);
		}
	}
}

QString BaseChatDialog::conversationId()
{
	return m_sConversationID;
}

void BaseChatDialog::sendMessageComplete(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (NULL!=spMessage.data())
	{
		updateCurrentTick(spMessage->UtcTime());
	}

	QSharedPointer<MimeTypeMessage> mimeTypeMessage = textEdit->getMimeTypeMessage();
	appendRecentMessage(mimeTypeMessage);

	textEdit->clear();
	textEdit->clearAnimation();

	cancelAnyNotice();
}

void BaseChatDialog::sendMessageResult(bool isSuccess)
{
	if (!isSuccess)
	{
		QString sendAttachmentFail = T_("sendMessageFail");
		mCommObject->systemnotify(mPage,sendAttachmentFail);
		mCommObject->scrollToEnd(mPage);
		cleanWillSendMsg();
	}
}

void BaseChatDialog::dochangeBodyAtInofr( const QSharedPointer<Biz::XmppMessage>&msg )
{
	if (msg.isNull())
	{
		return;
	}

	if (Biz::MessageUtil::isGroupJid(msg->ConversationID())&& !msg->BackupInfo().isEmpty() && msg->MediaType() == Biz::MessageTypeAt)
	{
		QString backupInfor = msg->BackupInfo();
		QString body = msg->Body();
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
				if (body.contains("@" + strText))
				{
					body.replace( "@"+strText, "@"+strDisplay);
				}
				else if (body.contains("＠" + strText))
				{
					body.replace( "＠"+strText, "＠"+strDisplay);
				}

				msg->Body(body);
			}

		}
	}
}

void BaseChatDialog::showDebugView() {  
	/*
	QWebSettings *settings = QWebSettings::globalSettings();
	settings->setAttribute(QWebSettings::PluginsEnabled,true);
	settings->setAttribute(QWebSettings::JavaEnabled,true);
	settings->setAttribute(QWebSettings::JavascriptEnabled,true);
	settings->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
	settings->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
	settings->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
	settings->setAttribute(QWebSettings::SpatialNavigationEnabled,true);
	settings->setAttribute(QWebSettings::LinksIncludedInFocusChain,true);
	settings->setAttribute(QWebSettings::AcceleratedCompositingEnabled,true);
	settings->setAttribute(QWebSettings::AutoLoadImages,true);
	if (inspector == NULL)
	{ 
		inspector = QSharedPointer<QWebInspector>(new QWebInspector());
	} 
	inspector->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Dialog);
	inspector->setMinimumSize(800, 800);
	inspector->setPage(this->mPage);
	inspector->show();  
	*/
}