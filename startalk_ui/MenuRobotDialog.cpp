#include "MenuRobotDialog.h"
#include "ui_MenuRobotDialog.h"
#include <time.h>
#include <QClipboard>
#include <QPalette>
#include <QTextBlock>
#include <QDesktopServices>
#include "Account.h"
#include "Session.h"
#include "XmppMessage.h"
#include "UserSettingData.h"
#include "RosterProfile.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "CallbackReceiver.h"
#include "SettingData.h"
#include "WebPage.h"
#include "ChatCommObject.h"
#include "LanguageHelper.h"
#include "StatisticsItem.h"
#include "diywidgit/printscreen/SnipScreenTool.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QSplitter>
#include <QXmppUtils.h>
#include <QImageReader>
#include <QImage>
#include <QColorDialog>
#include "AddGroupDialog.h"
#include "UiHelper.h"
#include "portraithelper.h"
#include "Historyrecorddialog.h"
#include "SystemConfigData.h"
#include "gloableeventobject.h"
#include "RecentItemView.h"
#include "userminiprofile.h"
#include "Ordermanagedialog.h"
#include "UserVcardManager.h"
#include "RobotManager.h"
#include "RobotAction.h"
#include "StaticData.h"
#include "DownloadManager.h"
#include "Session.h"
#include "accountmanager.h"
#include "conversationmanager.h"
#include "MessageManager.h"

#include "UIFrame.h"
#include "ConversationController.h"
#include "diywidgit/customviews/qframelayout.h"
#include "messagebubble/MessageParser.h"


#include "ChatDisplayOptionWidget.h"
#include "ChatWebPage.h"

#include "colorset.h"


#include "jsonobject/systemnotify.h"
#include "ui_ChatDialog.h"

namespace Biz
{
    enum SystemEnum
    {
        NOTSET,
        SYSDIALOG,
        NOTICEDIALOG,
        NEWSDIALOG,
        FRIENDSDIALOG
    };
};


MenuRobotDialog::MenuRobotDialog(MultiDialogContainer* cntainer,QWidget *parent)
    : ChatDialog(cntainer, parent)
     ,mMsgFilterMenu(NULL)
	 ,pBtnList(NULL)
{

    ui->menupanel->setVisible(true);
    ui->editPanel->setVisible(ui->menupanel->isVisible());

    connect(ui->down,&QPushButton::clicked,[this](bool b){
        ui->menupanel->setVisible(true);
        ui->editPanel->setVisible(!ui->menupanel->isVisible());
        mCommObject->scrollToEnd(mPage);

    });
// 
    connect(ui->up,&QPushButton::clicked,[this](bool b){
        ui->menupanel->setVisible(false);
        ui->editPanel->setVisible(!ui->menupanel->isVisible());
        mCommObject->scrollToEnd(mPage);
    });



     ui->textEdit->setFocus();
 
    ui->textEdit->setAcceptDrops(false);
    ui->frametextedit->setAcceptDrops(true);
    ui->frametextedit->installEventFilter(this);
    ui->webviewFrame->setAcceptDrops(true);
    ui->webviewFrame->installEventFilter(this);
	ui->platformIcon->setVisible(false);
	m_bInhertAttribute = false;
	ui->name->setCursor(QCursor(Qt::ArrowCursor));

	ui->headerimage->setCursor(QCursor(Qt::ArrowCursor));
	ui->platformIcon->setVisible(false);


// 
    textEdit = ui->textEdit;
    ui->btnfilter->setVisible(false);
// 
	
     connect(ui->btnfilter, &QPushButton::clicked, this, &MenuRobotDialog::onBtnMsgFilter );
     ui->btnfilter->setToolTip(QStringLiteral("过滤显示系统消息"));
 
    connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgUpdateRawHtmlElementStatus,
        this,&MenuRobotDialog::onUpdateRawHtmlElementStatus);

	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgConverSationMenuRobotType, this, &MenuRobotDialog::onConverStationMenuRobotType);

	int nToolBarDisableMask = ui->toolbar->getBtnEnableMask();
	nToolBarDisableMask = nToolBarDisableMask & ~(BTN_HISTORY|BTN_HISTORYLOCAL);
	ui->toolbar->setEnabled(nToolBarDisableMask);

	ui->sendmail->setVisible(false);
	ui->showProduct->setVisible(false);
	ui->pushButton_muc->setVisible(false);
	ui->trace->setVisible(false);

	ui->status->setVisible(false);
}

void MenuRobotDialog::getRobotInfo()
{
	ui->border->setVisible(true);
    QSharedPointer<Biz::RobotVcard> spRbtInfo = 
        Biz::Session::getRobotManager()->getRobotVcard(Biz::MessageUtil::makeSureUserId(conversationId()));

    auto initWithRbtVcart = [this]{
        mspRobotInfo = Biz::Session::getRobotManager()->getRobotVcard(Biz::MessageUtil::makeSureUserId(conversationId()));

        if (!mspRobotInfo.isNull())
        {
            // 设置名称
            QString strName = mspRobotInfo->RbtName().isEmpty()?mspRobotInfo->RbtId():mspRobotInfo->RbtName();
            ui->name->setText(strName);
            QString rawData = mspRobotInfo->RbtRawInfo();
            QJsonDocument doc = QJsonDocument::fromJson(rawData.toUtf8());
            QVariantMap paramMap = doc.toVariant().toMap().value("rbt_body").toMap();
            QVariantList actionList = paramMap.value("actionlist").toList();
			QString strRobotDesc = paramMap.value("robotDesc").toString();
			ui->leJid->setText(strRobotDesc);
			
			ui->leJid->setToolTip(strRobotDesc);
			bool bret = actionList.isEmpty();
            ui->down->setVisible(!actionList.isEmpty());
            ui->menupanel->setVisible(!actionList.isEmpty());
            ui->editPanel->setVisible(actionList.isEmpty());
			

            if (paramMap.contains("replayable"))
            {
                ui->editPanel->setVisible(paramMap.value("replayable").toBool());
                ui->up->setVisible(paramMap.value("replayable").toBool());
            }
            if (paramMap.contains("rawhtml") && paramMap.value("rawhtml").toBool())
                loadRawHtml();
            else
                loadNormalHtml();
				//onClearContents();

            //QList<QPushButton*>* pBtnList = new QList<QPushButton*>();
			
			if (pBtnList != NULL && pBtnList->size() > 0)
			{
				QPushButton *pb = NULL;
				int nsize = pBtnList->size();
				for (int i = 0; i < nsize; i++)
				{
					pb = pBtnList->at(i);
					if (pb)
					{
						delete pb;
						pb = NULL;
					}
				}
				for (int i = 0; i < nsize; i++)
				{
					pBtnList->removeAt(i);
				}
				delete pBtnList;
				pBtnList = NULL;
			}
			pBtnList = new QList<QPushButton*>();
            for (QVariant mainaction : actionList)
            {
                QVariantMap actionMap = mainaction.toMap();
                QString name = actionMap["mainaction"].toString();
                MainActionBtn* pBtn = NULL;
				pBtn = new MainActionBtn(this,pBtnList);
                pBtn->setText(QStringLiteral("请使用移动端查看"));

                if (actionMap.contains("subactions"))
                {
                    QVariantList subActions = actionMap["subactions"].toList();
                    for (QVariant subItem : subActions)
                    {
                        QVariantMap subItemMap = subItem.toMap();
                        QString subName = subItemMap["subaction"].toString();
                        SubActionBtn* psbtn = NULL;
						psbtn = new SubActionBtn(this);
                        psbtn->setText(QStringLiteral("请使用移动端查看"));
                        QSharedPointer<RobotAction> spAction = RobotAction::CreateActions(subItemMap["actioncontent"]);
                        if (NULL!=spAction)
                        {
                            spAction->setPeerid(conversationId());
                            psbtn->setText(subName);
                        }
                        psbtn->setAction(spAction);
                        psbtn->setEnabled(!spAction.isNull());
                        pBtn->addSubActionBtn(psbtn);
                    }
                }
                else
                {
                    pBtn->setCheckable(false);
                    QSharedPointer<RobotAction> spAction = RobotAction::CreateActions(actionMap["actioncontent"]);
                    if (NULL!=spAction)
                    {
                        spAction->setPeerid(conversationId());
                        pBtn->setText(name);
                    }
                    pBtn->setAction(spAction);
                    pBtn->setEnabled(!spAction.isNull());
                }
                ui->robotMenuHlayout->addWidget(pBtn);
            }
        }
        else
        {
            ui->editPanel->setVisible(false);
            ui->menupanel->setVisible(false);
        }

		if (Util::PlatfromCode::PLATFROM_QCHAT == Util::nPlatformType)
		{
			if (getChatType() == NormalChatType)
			{
				sendSayHelloMessage();
			}
		}
    };

    if (spRbtInfo.isNull())
    {
        auto cb = receiver->createCallback<QSharedPointer<Biz::RobotVcard>>(
            [this,initWithRbtVcart](const QSharedPointer<Biz::RobotVcard>& vcard){
                Q_UNUSED(vcard);
                initWithRbtVcart();
        },[]{});

        Biz::Session::getRobotManager()->getRobotVcardOnline(Biz::MessageUtil::makeSureUserId(conversationId()),cb);
    }
    else
        initWithRbtVcart();

}
//应放在第二层，这个函数的作用就是ui上显示名片信息
void MenuRobotDialog::onLoadRoster( const QString& userID, const QString& displayName )
{

	if (Biz::MessageUtil::compareJid(Util::NEWS_DIALOG_ID,conversationId()))
	{
		return;
	}
    ui->toolbar->setConversationId(userID); 

    this->setWindowTitle(displayName);

    Q_ASSERT(!displayName.isEmpty());
    ui->name->setText(displayName);

    setCounversationId(userID);


    QString groupName = Biz::Session::currentAccount().getUserGroup(userID);
   // ui->leNotice->setText(groupName);
	//setTextInWidget(ui->leNotice, Biz::MessageUtil::makeSureUserId(userID), 350);
    if (Biz::MessageUtil::compareJid(conversationId(), Util::SYSTEMNEWS_DIALOG_ID))
    {
        doGetSystemMsgTableCount();
    }

    doSetHeaderImage();

    QSharedPointer<Biz::XmppMessage> msg (new Biz::XmppMessage(conversationId()));
    msg->MsgSourceType(Biz::subscription);
	if (mChatType != CollectionChatType)
	{
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
	}
    

	
	getRobotInfo();
	
    
}


//放在第一层base层，主要展示历史消息
// void MenuRobotDialog::onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList )
// {
//     appendMessage(true, messageList->HasMore(), messageList->getMessageList());
// }
//放到第一层base层，主要是消息接收的
void MenuRobotDialog::onMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	QString conid = conversationId();

    if(msg->ConversationID() != conversationId()){
        return;
    }

    if (appendRawMessage(msg))
        return;

    if (!m_bWebLoadFinshed)
    {
        m_lstMsgCatch.push_back(msg);
        Log::e("MenuRobotDialog::onMessageReceived push to msgcatch" + msg->MessageID());
        return;
    }

    updateCurrentTick(msg->UtcTime());

    // 回话消息
    appendMessage(false, false, msg);
}

void MenuRobotDialog::onCollectionMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	
	QString strconversationId;
	if (msg->origintype() == Biz::MessageSourceType::GroupMessage)
	{
		strconversationId = QXmppUtils::jidToBareJid(msg->originfrom());
	}
	else if (msg->origintype() == Biz::MessageSourceType::ChatMessage)
	{
		strconversationId = msg->originfrom();
	}

	if (msg->originto() != mparentId)
	{
		return;
	}
	if(strconversationId != conversationId() ){
		return;
	}

// 	if (appendRawMessage(msg))
// 		return;

	
	if (!m_bWebLoadFinshed)
	{
		m_lstMsgCatch.push_back(msg);
		Log::e("MenuRobotDialog::onMessageReceived push to msgcatch" + msg->MessageID());
		return;
	}

	updateCurrentTick(msg->UtcTime());

	// 回话消息
	appendMessage(false, false, msg);
}

//重写基类的方法
 void MenuRobotDialog::preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool& toBeShow /*default 1*/)
{
    toBeShow = (Biz::MediaTypeRobotNotice == spMessage->MediaType()?false:true);
}


void MenuRobotDialog::afterFormatShowMessage(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore)
{
     parseRobotWeChatNotice(spMessage,isHistory);
}




//放到第一层base层，主要是历史框进行请求历史消息，给展示,webView
void MenuRobotDialog::onGetMore( quint64 timestamp, int count, bool firstcall )
{
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
    QString strMsgFilter = settingconfig->SystemMsgType();
    QStringList strList = strMsgFilter.split("|");
    QStringList strNewlist; 

    //去掉QStringList中的空字符串
    for (QString str: strList)
    {
        if (!str.isEmpty())
        {
            strNewlist.append(str);
        }
    }



    auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this, firstcall, strNewlist](const QSharedPointer<Biz::MessageListData>& messageList )
    {
        if (messageList.isNull())
        {
            return;
        }
        onHistoryAppend(messageList);
        Log::e("MenuRobotDialog::onGetMore callback" );
        if (firstcall)
        {
            doMergeMessageCache(messageList);
        }

    }, []{});

    count = timestamp==0?5:count;
    timestamp = timestamp==0?-1:timestamp;

    if (firstcall)
    {
        mGetHistoryMessageTimerout.stop();
        mGetHistoryMessageTimerout.start();
    }

    if (Biz::MessageUtil::compareJid(conversationId(), Util::SYSTEMNEWS_DIALOG_ID))
    {
        if (strNewlist.isEmpty())
        {
            auto cq = mReceiver->createCallback<QStringList>([this, timestamp, callback](const QStringList &strmsgtypelist)
            {

                Biz::Session::getAccountManager()->getSystemMsgbyMsgType(strmsgtypelist, timestamp, callback);

            }, []{});
            Biz::Session::getAccountManager()->getSystemMsgType(cq);
        }
        else if (strNewlist == QStringList(SELFSETEMPTY))
        {
            //往界面的顶上发送一条提示信息
            mCommObject->frontsystemnotify(mPage, QStringLiteral("请手动设置过滤条件进行查看系统消息"));
        }
        else
        {
            Biz::Session::getAccountManager()->getSystemMsgbyMsgType(strNewlist, timestamp, callback);
        }



    }
    else
    {
		Biz::Session::getMessageManager()->getHistoryMessageList(conversationId(), count, timestamp, callback);
    }

}


void MenuRobotDialog::doSetHeaderImage()
{
    if (conversationId().isEmpty() || conversationId() == Util::NEWS_DIALOG_ID)
    {
        return;
    }

    QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(conversationId());
	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));

	ui->headerimage->setPixmap(pixmap);

}

MenuRobotDialog::~MenuRobotDialog()
{

}

void MenuRobotDialog::setInputAreaVisable(bool b)
{
    ui->editPanel->setVisible(b);
}

void MenuRobotDialog::setMenuAreaVisable(bool b)
{
    ui->menupanel->setVisible(b);
}



void MenuRobotDialog::onOpenUrl( const QString &id )
{
	int npos = id.indexOf("http");
	if (npos == 0)
	{
		CommentWebViewSingleton::getInstance()->openCommonUrl(id);
	}
	else
    GetUrlbyMsgid(id);
}

void MenuRobotDialog::GetUrlbyMsgid( const QString& strid )
{
    auto callback = mReceiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this, strid](QSharedPointer<Biz::XmppMessage> msg)
    {
        if (msg.isNull())
        {
            return;
        }

        do 
        {
            if (msg->MsgSourceType()==Biz::subscription)
            {
                if (msg->MediaType() == Biz::MediaTypeSystem)
                {

                    QString jsonString = msg->Body ();
                    Biz::SystemNotifyParam snp;
                    snp.unserializeFromString (jsonString);


                    QString leftPromot = snp.prompt ();
                    if (!snp.clickprompt ().isEmpty ())
                        leftPromot = snp.clickprompt ();

                    Biz::ExtraInfo* pExtraInfo = (Biz::ExtraInfo*)snp.extra ();
                    QString rightPromot = (NULL==pExtraInfo?QStringLiteral("已处理"):pExtraInfo->checkedopertext ());

                    CommentWebViewSingleton::getInstance()->showSystemOrNoticeUrl(snp.operation_url ());
                    SetChecked(strid, leftPromot,rightPromot);
                    Biz::Session::getAccountManager()->updateSystemMessageById(strid, 1);
                    Biz::StaticData::reportTakeCountEvent("10018",1,"GetSystemClicked");
                    break;
                }
                if (msg->MediaType() == Biz::MediaTypeNotice || msg->MediaType() == Biz::MediaTypeSystemLY)
                {
                    QVariantMap bodyJson = QJsonDocument::fromJson(msg->Body().toUtf8()).toVariant().toMap();
                    QString strUrl = bodyJson.value("link_url_pc").toString();
                    if (strUrl.isEmpty())
                        strUrl = bodyJson.value("linkurl").toString();

                    CommentWebViewSingleton::getInstance()->showSystemOrNoticeUrl(strUrl);
                    break;
                }
                break;
            }

        } while (false);
    }, []{});


    if(!strid.isEmpty())
        Biz::Session::getMessageManager()->getMessageById(strid, callback);

}

void MenuRobotDialog::SetChecked(const QString& strid, const QString& leftPromot,const QString& rightPromot)
{
    //在这里组一个json串,然后调用html中的函数
    QJsonObject obj;
    obj.insert("msgid", strid);

     QString leftColor  = ColorSetSingleton::getInstance ()->qchat_notice_promo_checked();
    QJsonObject objleft;
    objleft.insert("text", leftPromot);
    objleft.insert("clr", leftColor);
    obj.insert("left", objleft);

    QString rightColor  = ColorSetSingleton::getInstance ()->qchat_notice_option_checked();
    QJsonObject objright;
    objright.insert("text", rightPromot);
    objright.insert("clr", rightColor);
    obj.insert("right", objright);


    QJsonDocument doc(obj);


    mCommObject->CheckedSysMsg( mPage,QString::fromUtf8(doc.toJson()));
}


void MenuRobotDialog::InitMsgTypeMenu()
{
    if (mMsgFilterMenu)
    {
        mMsgFilterMenu->deleteLater();
        mMsgFilterMenu = NULL;
    }
    if (NULL == mMsgFilterMenu)
    {
        auto callback = mReceiver->createCallback<QStringList>([this](const QStringList &strmsgtypelist)
        {
            if (strmsgtypelist.size() >0)
            {

                mMsgFilterMenu = new QMenu(ui->btnfilter);
                Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
                QString strlist = settingconfig->SystemMsgType();
                QStringList strnewtypelist;
                foreach (QString strtype, strmsgtypelist)
                {
                    auto act = mMsgFilterMenu->addAction(strtype);
                    act->setCheckable(true);
                    if (strlist.isEmpty())
                    {
                        act->setChecked(true);
                        strnewtypelist.push_back(strtype);
                    }
                    else if (strlist.compare(SELFSETEMPTY, Qt::CaseInsensitive) == 0)
                    {

                    }
                    else
                    {
                        strlist.split("|").contains(strtype)?act->setChecked(true):act->setChecked(false);
                    }


                    connect(act, &QAction::changed, this, &MenuRobotDialog::onMsgTypeChanged);

                }
                if (strnewtypelist.size()>0)
                {
                    settingconfig->SystemMsgType(strnewtypelist.join("|"));
                    Biz::Session::saveSettingConfig();
                }


                mMsgFilterMenu->exec(QCursor::pos());

            }

        }, []{});
        Biz::Session::getAccountManager()->getSystemMsgType(callback);

    }
}

void MenuRobotDialog::onBtnMsgFilter()
{
    InitMsgTypeMenu();
}

void MenuRobotDialog::doShowQueryMsg( const QStringList& msgtype )
{
    onClearContents();

    //延迟1秒是临时方案
    //reload接口需要调整很多html种的全局变量，涉及很多问题
    QTimeLine* ptime = new QTimeLine(1000);
    connect(ptime,&QTimeLine::finished,[this,msgtype]{

        auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& messageList )
        {
            //先清除
            if (messageList.isNull())
            {
                return;
            }
            onHistoryAppend(messageList);
            mCommObject->scrollToEnd(mPage);

        }, []{});
        QStringList strnewlist;
        for (QString str: msgtype)
        {
            if (!str.isEmpty())
            {
                strnewlist.append(str);
            }
        }
        Biz::Session::getAccountManager()->getSystemMsgbyMsgType(strnewlist, -1, callback);

    });
    ptime->start();

}

void MenuRobotDialog::onMsgTypeChanged()
{
    auto action = (QAction*)sender();

    QString strText = action->text();
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
    QString strtmp = settingconfig->SystemMsgType();
    QStringList strlist = strtmp.split("|").filter("");
    bool bret = action->isChecked();

    if (!action->isChecked() && strlist.contains(strText))
    {
        strlist.removeOne(strText);

    }
    if(action->isChecked() && !strlist.contains(strText)) 
    {
        strlist.push_back(strText);
    }
    if (strlist.join("|").isEmpty())
    {
        settingconfig->SystemMsgType(SELFSETEMPTY);
    }
    else
    {
        settingconfig->SystemMsgType(strlist.join("|"));
    }
    doShowQueryMsg(strlist);
    Biz::Session::saveSettingConfig();

}

void MenuRobotDialog::doGetSystemMsgTableCount()
{
    auto callback = mReceiver->createCallback<int>([this](const int count )
    {
        if (count > 0)
        {
            ui->btnfilter->setVisible(true);
        }

    }, []{});

    Biz::Session::getAccountManager()->getSystemMsgTableRecordCount(callback);
}

void MenuRobotDialog::setRobotDealBlock(int timeout,const QString& dealKey)
{
    QTimeLine* timeLine = new QTimeLine(timeout*1000);
    timeLine->setFrameRange(0,timeout);
    timeLine->setCurveShape(QTimeLine::LinearCurve);

    connect(timeLine,&QTimeLine::frameChanged,[this,timeLine,timeout,dealKey](int frame){
        if (ui->dealingpanel->property("dealkey").toString() == dealKey)
        {
            QString waitingText = QStringLiteral("多位导游同时抢答<br>筛选中...(%1)").arg(timeout-frame);
            ui->dealing->setText(waitingText);
        }
        else
        {
            timeLine->stop();
            timeLine->deleteLater();
        }
    });
    connect(timeLine,&QTimeLine::finished,[this,timeLine,dealKey]{
        if (ui->dealingpanel->property("dealkey").toString() == dealKey)
        {
            ui->dealing->setText("");
            ui->dealingpanel->setVisible(false);
        }
        timeLine->deleteLater();
    });
    QString waitingText = QStringLiteral("多位导游同时抢答<br>筛选中...(%1)").arg(timeout);
    ui->dealing->setText(waitingText);
    ui->dealingpanel->setVisible(true);
    ui->dealingpanel->setProperty("dealkey",dealKey);
    timeLine->start();
}

void MenuRobotDialog::parseRobotWeChatNotice(const QSharedPointer<Biz::XmppMessage>& msg,bool ishistory)
{
    if (msg.isNull())
        return;
    QString notice = msg->ExtendInfo();

    QJsonDocument doc = QJsonDocument::fromJson(notice.toUtf8());
    QVariantMap paramMap = doc.toVariant().toMap();
    if (paramMap.contains("result"))
    {
        bool bResult = paramMap.value("result").toBool();
        QString reusltText = paramMap.value("errorinfo").toString();

        QString dealid = paramMap.value("dealid").toString();
        QString js;
        js += "modeRobotDealBtnState(\"";
        js += dealid+"_btndeal";
        js += "\",";
        js += "true";
        js += ",\"";
        js += reusltText;
        js += "\")" ;
        mPage->runLocalJavaScript(js);


        if (bResult)
        {
            // 解析出临时名片，存储起来,并且发起会话
            QString userjid = paramMap.value("sessionid").toString();

            if (!userjid.isEmpty())
            {
                userjid = Biz::MessageUtil::makeSureUserJid(userjid);
                QString displayName = paramMap.value("nickname").toString();
                QSharedPointer<Biz::ImSelfPerson> spPerson(new Biz::ImSelfPerson);
                spPerson->strUserId = userjid;
                spPerson->strNickName = displayName;
                Biz::Session::getUserVcardManager()->addUserVcard(spPerson);
            }
        }

        // 取消block屏幕
        ui->dealing->setText("");
        ui->dealingpanel->setVisible(false);
    }
}

//第一层，主要是加载html页面
void MenuRobotDialog::loadRawHtml()
{

    loadChatHtml(ui->webView, "/html/MicroTourRoot.html");
    connect(ui->webView, &webview::loadFinished, this,&MenuRobotDialog::onLoadHtmlFinish);
    mPage->addChatChannelToHtml("ClientApi", mCommObject);
    ui->webView->setContextMenuPolicy(Qt::CustomContextMenu);
}


void MenuRobotDialog::onUpdateRawHtmlElementStatus(const QString& vcardId,const QString& message)
{
    QString str = QString("updateMessage('%1','%2')").arg(vcardId,message);
    mPage->runLocalJavaScript(str);
}

void MenuRobotDialog::onConverStationMenuRobotType( const QString& Robotid )
{
	if (Robotid != conversationId())
	{
		return;
	}

	getRobotInfo();
}



void MenuRobotDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
    Biz::Session::getConverSationManager()->setConversationMessageRead(conversationId());
   
    spMessage->MsgSourceType(Biz::subscription);
}
