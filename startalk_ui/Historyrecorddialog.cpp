#include "Historyrecorddialog.h"
//#include <QWebPage>
#include "Historyrecordmodel.h"
#include "TitlebarWidget.h"

#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "XmppMessage.h"
#include "LanguageHelper.h"
#include <QClipboard>
#include "ConfigureHelper.h"
#include "ChatWebPage.h"

HistoryRecordDialog *HistoryRecordDialog::pInstance = NULL;
HistoryRecordDialog::HistoryRecordDialog(const QString& struseid,QWidget *parent)
    : BaseChatDialog(parent),ui(new Ui::HistoryRecordDialog),strCurrentSelectUserid(""),mCurrentGroupid(struseid)
    ,tableView(NULL),bfindSearch(false),lasttm(-1),begintm(-1),FindRet(false)
	,bFirst(true)
{
    nPageIndex = 0;
    ui->setupUi(this);
    setupWebView(ui->webView);
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    //setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	setWindowTitle(QStringLiteral("历史记录查询"));
    auto titlebar = ui->titleBar;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &HistoryRecordDialog::onMin);

    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &HistoryRecordDialog::onClose);

	QStringList header;
	header << QStringLiteral("联系人") << QStringLiteral("群名") << QStringLiteral("最后会话时间") << QStringLiteral("信息条数");
	ui->tableView->SetHeaderList(header);

	int nwidth = ui->tableView->width();
// 	ui->tableView->head->resizeSection(0, 160);
// 	ui->tableView->head->resizeSection(1, 300);
// 	ui->tableView->head->resizeSection(2, 150);
// 	ui->tableView->head->resizeSection(3, 70);

	ui->tableView->head->resizeSection(0, nwidth*0.20);
	ui->tableView->head->resizeSection(1, nwidth*0.45);
	ui->tableView->head->resizeSection(2, nwidth*0.25);
	ui->tableView->head->resizeSection(3, nwidth*0.10);


	mPage = new ChatWebPage(this);
	ui->webView->setPage(mPage);
	
    mPage->addChatChannelToHtml("CLIENT_API", mCommObject);

	loadChatHtml(ui->webView, "/html/groupdialog.html");

    ui->splitter->setStretchFactor(0, 3);
    ui->splitter->setStretchFactor(1, 7);

    //connect(ui->webView, &QWebView::customContextMenuRequested, this, &ChatDialog::ShowWebViewMenu);
    connect(ui->tableView, &TableView::updateCount, this, &HistoryRecordDialog::updateCount);
    connect(this, &HistoryRecordDialog::sgshowDefaultMsg, this, &HistoryRecordDialog::onShowDefaultMsg);
    //tableView = ui->tableView;
    connect(ui->tableView, &QTableView::clicked, this, &HistoryRecordDialog::onSelecRowClick);

    connect(ui->pushbtn_search, &QPushButton::clicked, this, &HistoryRecordDialog::onSearchFind);
    connect(ui->pushbtn_clear, &QPushButton::clicked, this, &HistoryRecordDialog::onSearchClean);
    connect(ui->pbBegin, &QPushButton::clicked, this, &HistoryRecordDialog::onBegin);
    connect(ui->pbnext, &QPushButton::clicked, this, &HistoryRecordDialog::onNext);
    connect(ui->pbblow, &QPushButton::clicked, this, &HistoryRecordDialog::onBlow);
    connect(ui->pbEnd, &QPushButton::clicked, this, &HistoryRecordDialog::onEnd);
    connect(ui->PbSearchAbove, &QPushButton::clicked, this, &HistoryRecordDialog::onSearchAbove);
    connect(ui->PbSearchNext, &QPushButton::clicked, this, &HistoryRecordDialog::onSearchNext);

    connect(this, &HistoryRecordDialog::sgShowFlagMsg, this, &HistoryRecordDialog::onShowFlagMsg);

    ui->PbSearchAbove->setVisible(false);
    ui->PbSearchNext->setVisible(false);

    ui->pushbtn_clear->setVisible(false);

    mReceiver = new Biz::CallbackReceiver(this);
    InitData();
}

HistoryRecordDialog::~HistoryRecordDialog()
{

}

HistoryRecordDialog* HistoryRecordDialog::instance(const QString&struserid)
{
	if (pInstance==NULL)
	{
		pInstance = new HistoryRecordDialog(struserid);
	}
	return pInstance;
}
void HistoryRecordDialog::showHistoryRecordDlg(const QString& strGroupJid)
{
	showNormal();
	activateWindow();


	if (!bFirst)
	{
		showMsg(strGroupJid,"",PAGE_DIRECTIO_END); // 憕_?%?憃%?^?_噑,憃??Z????

		int nI = 0;
		for (Biz::RecordInfor infor: mlistInfor)
		{
			if (infor.strgroupjid == strGroupJid)
			{
				ui->tableView->selectRow(nI);
				QModelIndex index = ui->tableView->currentIndex();
				emit ui->tableView->clicked(index);
				break;
			}
			nI++;
		}
	}
	bFirst =false;

	ui->tableView->clear();
	GetPeerId();
}

void HistoryRecordDialog::onMin()
{
    this->hide();
}
void HistoryRecordDialog::onClose()
{
    this->close();
}
void HistoryRecordDialog::InitData()
{
   
    GetPeerId();
}
void HistoryRecordDialog::GetPeerId()
{
	QString strtmp = mCurrentGroupid;
 auto cb = mReceiver->createCallback< QList<Biz::RecordInfor> >([this,strtmp](const QList<Biz::RecordInfor>& listInfor){

     int i = 0;
	 int ncurrentselect = 0;

	 //把当前群入口放在第一个位置

     for (Biz::RecordInfor infor: listInfor)
     {
         QString strgroupjid = infor.strgroupjid;
         QString strgroupNickName = infor.strgroupnickName;
         QSharedPointer<Biz::MessageListData> messagelistdata = infor.messagelistdata;
         int ncount = infor.msgcount;
         QString strcount = QString("%1").arg(ncount);

         QString chatTime = QDateTime::fromMSecsSinceEpoch(infor.msgtime).toString("yyyy-MM-dd hh:mm:ss");
         //timeStemp = QDateTime::fromMSecsSinceEpoch(msg->UtcTime()).toString("yyyy-MM-dd hh:mm:ss");
         if (!strgroupNickName.isEmpty())
         {
			 
			 
             //model->setData(strgroupjid, strgroupjid, chatTime, strcount);
             QStringList strList;
             strList << strgroupNickName << strgroupjid << chatTime << strcount;

			 if (strgroupNickName.compare(strtmp,Qt::CaseInsensitive) == 0/*mCurrentGroupid*/)
			 {
				 ncurrentcount = i;
				 ui->tableView->addRowInFront(strList);
			 }
			 else
			 {
				  ui->tableView->addRow(strList);
			 }

            
             mlistInfor.append(infor);
         }

         i++;
     }
	 //看默认选中的行是当前入口处的groupid

     ui->tableView->selectRow(0);
	 ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); 
     QModelIndex index = ui->tableView->currentIndex();
	 //ui->tableView->selectRow(0);
     emit ui->tableView->clicked(index);

     //emit sgshowDefaultMsg(0);

 },[]{}
 );
 Biz::Session::currentAccount().getMessagePeerIdList(cb);

}

void HistoryRecordDialog::updateCount(int count)
{

}


void HistoryRecordDialog::onShowDefaultMsg(int n)
{
     Biz::RecordInfor infor = mlistInfor.at(0);
     showMsg(infor.strgroupjid,"",PAGE_DIRECTIO_END);

}

void HistoryRecordDialog::onSelecRowClick()
{
    lasttm = -1;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex(); 

    QString strid=index.sibling(curRow,1).data().toString();
    strCurrentSelectUserid = strid;


    if (bfindSearch)
    {
		FindRet = true;
        ncurrentcount = 0;
        showMsg(strid, ui->Edit_Msg->text(),PAGE_DIRECTIO_END);
		

    }
    else
    {
        showMsg(strid,"",PAGE_DIRECTIO_END); // 憕_?%?憃%?^?_噑,憃??Z????

    }
}

void HistoryRecordDialog::showMsg(const QString& strid, const QString strflag, int direction/*=false*/)
{

//     connect(ui->webView, &webview::customContextMenuRequested, this, &HistoryRecordDialog::ShowWebViewMenu);
    auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this, strid, strflag,direction](const QSharedPointer<Biz::MessageListData>& messageList )
    {
        ShowHtml(messageList, strflag);
        updatePageNumber(direction);
		//廌IE€OU骜€鳲3OO娅AED奜鲦帋UEY
		if (!strflag.isEmpty() && FindRet)
		{
			if (strlistmsgid.count() > 0)
			{
				onSearchNext();
			}
			else
			{
				//OUEy_Y▋橠齻OO湭帋O疘oИOD齻OO鎺1O瑏x欐帋UEY
				getBeginAndEndTime(strid, strflag);
			}
			
		}

		FindRet = false;
		
    }, []{ });

    for (Biz::RecordInfor infor: mlistInfor)
    {
        if (infor.strgroupjid == strid)
        {
            if (!strid.isEmpty())
            {
                switch (direction)
                {
                case PAGE_DIRECTIO_BEGIN:{
                    Biz::Session::currentAccount().getHistoryRecordMessageList(strid,infor.msgcount%30, 0,callback,0);
                    break;
                                         }
                case PAGE_DIRECTIO_LAST:{
                    Biz::Session::currentAccount().getHistoryRecordMessageList(strid,30, begintm,callback,0);
                    break;
                                        }
                case PAGE_DIRECTIO_NEXT:{
                    Biz::Session::currentAccount().getHistoryRecordMessageList(strid,30, lasttm,callback,1);
                    break;
                                        }
                case PAGE_DIRECTIO_END:{
                    Biz::Session::currentAccount().getHistoryRecordMessageList(strid,30, -1,callback,1);
                    break;
                                       }
                default:
                    break;
                }

				break;
            }
        }
    }
}

QString getTextOnlyMsgBody(const QString& body)
{
    QString msg = body;
    QString strResult = body;
    QRegExp regExp("\\[obj type=[\\\\]?\"(.*)[\\\\]?\" value=[\\\\]?\"(.*)[\\\\]?\"(.*)\\]");    
    regExp.setMinimal(true);

    QStringList xslist;

    auto pos = 0;
    while ((pos = regExp.indexIn(msg, pos)) != -1) 
    {
        QString item = regExp.cap(0);
        QString type = regExp.cap(1);
        QString val = regExp.cap(2);
        QString extPart = regExp.cap(3);
        if(type == "url")
        {
            QString xs = QString("<a href='javascript:openUrl(\"%1\")'>%1</a>").arg(val);
            xslist.append(xs);
            strResult.replace(item, xs);
        }
        else
        {
            strResult.replace(item, "");
        }
        pos += regExp.matchedLength();
        msg = strResult;
    }  

    return msg;
}

#include "messagebubble/MessageParser.h"

void HistoryRecordDialog::ShowHtml(const QSharedPointer<Biz::MessageListData> messageList, const QString strflag)
{
    int ncount = messageList->getMessageList().count();
    if (ncount > 0)
    {
        lasttm = messageList->getMessageList().at(ncount - 1)->UtcTime();
        begintm = messageList->getMessageList().at(0)->UtcTime();
    }

    strlistmsgid.clear();

    QList<QSharedPointer<Biz::XmppMessageMark>> markmsglst;
    for(QSharedPointer<Biz::XmppMessage> msg : messageList->getMessageList())
    {
        QString strMsg = msg->Body();
        QString rawBody = msg->Body();

		QString strmsgid = msg->MessageID();
		
//         QString strHtmlBody;
//         if (MessageParser::getInstance()->getTranslatedMessage(msg,strHtmlBody))
//         {
//             msg->Body(strHtmlBody);
//         }

        QSharedPointer<Biz::XmppMessageMark> spMsgMark(new Biz::XmppMessageMark(""));

        spMsgMark->ConversationID(msg->ConversationID());
        spMsgMark->SenderJid(msg->SenderJid());
        spMsgMark->Body(msg->Body());
        spMsgMark->Subject(msg->Subject());
        spMsgMark->MessageID(msg->MessageID());
        spMsgMark->SendFileID(msg->SendFileID());
        spMsgMark->UtcTime(msg->UtcTime());
        spMsgMark->OfflineMessage(msg->OfflineMessage());
        spMsgMark->MsgDirection(msg->MsgDirection());
        spMsgMark->MsgSourceType(msg->MsgSourceType());
        spMsgMark->MediaType(msg->MediaType());
        spMsgMark->MachineType(msg->MachineType());



        if (!strflag.isEmpty())
        {
            QString shortBody = getTextOnlyMsgBody(rawBody);
            if(shortBody.contains(strflag))
            {
                strlistmsgid.append(msg->MessageID());
                spMsgMark->SearchMark(true);
            }
        }
        markmsglst.push_back(spMsgMark);
        

    }
    mCommObject->appendHistoryMessage(mPage,markmsglst, 1, strflag);
}

void HistoryRecordDialog::onSearchFind()
{
    ui->PbSearchAbove->setVisible(true);
    ui->PbSearchNext->setVisible(true);
    mlistInfor.clear();
    ncurrentcount = 0;
    bfindSearch = true;
    QString strRelationPson;
    strRelationPson = ui->Edit_Relation->text();
    QString strMsg;
    strMsg = ui->Edit_Msg->text();
    ui->tableView->clear();

     auto cb = mReceiver->createCallback< QList<Biz::RecordInfor> >([this, strMsg](const QList<Biz::RecordInfor>& listInfor)
     {

         int i = 0;
         for (Biz::RecordInfor infor: listInfor)
         {
             QString strgroupjid = infor.strgroupjid;
             QString strgroupNickName = infor.strgroupnickName;
             QSharedPointer<Biz::MessageListData> messagelistdata = infor.messagelistdata;
             int ncount = infor.msgcount;
             QString strcount = QString("%1").arg(ncount);

             QString chatTime = QDateTime::fromMSecsSinceEpoch(infor.msgtime).toString("yyyy-MM-dd hh:mm:ss"); 
             if (!strgroupNickName.isEmpty())
             {
                 QStringList strList;
                 strList << strgroupNickName << strgroupjid << chatTime << strcount;

                 ui->tableView->addRow(strList);
                 mlistInfor.append(infor);

             }
            i++;
        }
        ui->tableView->selectRow(0);
        QModelIndex index = ui->tableView->currentIndex(); 

        emit ui->tableView->clicked(index);
     },[]{}
     );


     Biz::Session::currentAccount().getMessagePeerIdList(cb, strMsg, strRelationPson);


}
void HistoryRecordDialog::onNext()
{
    int nI = 0;
    if (bfindSearch)
    {

        showMsg(strCurrentSelectUserid, ui->Edit_Msg->text(),PAGE_DIRECTIO_NEXT);
    }
    else
    {
        showMsg(strCurrentSelectUserid,"",PAGE_DIRECTIO_NEXT);
    }

}
void HistoryRecordDialog::onSearchClean()
{
    bfindSearch = false;
}
void HistoryRecordDialog::onBegin()
{
    lasttm = -1;
    if (bfindSearch)
    {
        showMsg(strCurrentSelectUserid, ui->Edit_Msg->text(),PAGE_DIRECTIO_BEGIN);
    }
    else
    {
        showMsg(strCurrentSelectUserid,"",PAGE_DIRECTIO_BEGIN);
    }


}
void HistoryRecordDialog::onBlow()
{
    if (bfindSearch)
    {
        showMsg(strCurrentSelectUserid, ui->Edit_Msg->text(),PAGE_DIRECTIO_LAST);
    }
    else
    {
        showMsg(strCurrentSelectUserid,"",PAGE_DIRECTIO_LAST);
    }
}
void HistoryRecordDialog::onEnd()
{
    if (bfindSearch)
    {
        showMsg(strCurrentSelectUserid, ui->Edit_Msg->text(),PAGE_DIRECTIO_END);
    }
    else
    {
        showMsg(strCurrentSelectUserid,"",PAGE_DIRECTIO_END);
    }
}
void HistoryRecordDialog::onSearchAbove()
{
    if (ncurrentcount > 0)
    {
        strCurrentmsgid = strlistmsgid.at(--ncurrentcount);
        mCommObject->jsMsgFindMao(mPage, strCurrentmsgid);
    }

}
void HistoryRecordDialog::onSearchNext()
{
    //static int nI = 0;
    if (ncurrentcount < strlistmsgid.count())
    {
        strCurrentmsgid = strlistmsgid.at(ncurrentcount++);
        if (!strCurrentmsgid.isEmpty())
        {
            mCommObject->jsMsgFindMao(mPage, strCurrentmsgid);
        }
    }


}
void HistoryRecordDialog::onShowFlagMsg(int n,const QString& msg)
{
    //嗰??%?-姯O噑,msg
	Biz::RecordInfor infor = mlistInfor.at(n);
	showMsg(infor.strgroupjid, msg,PAGE_DIRECTIO_END);
}

void HistoryRecordDialog::updatePageNumber(int direction, int currentPage)
{
    for (Biz::RecordInfor infor: mlistInfor)
    {
        if (infor.strgroupjid == strCurrentSelectUserid)
        {
            int nTotalPage = infor.msgcount/30;
            int nDix = infor.msgcount%30;
            nTotalPage += (nDix==0?0:1);

			if (currentPage == -1)
			{

			
            switch (direction)
            {
            case PAGE_DIRECTIO_BEGIN:{
                nPageIndex = 1;
                break;
                                     }
            case PAGE_DIRECTIO_LAST:{
                nPageIndex--;
                break;
                                    }
            case PAGE_DIRECTIO_NEXT:{
                nPageIndex++;
                break;
                                    }
            case PAGE_DIRECTIO_END:{
                nPageIndex = nTotalPage;
                break;
                                   }
            default:
                break;
            }
			}
			else{
				nPageIndex = currentPage;
			}



            ui->labelInfor->setText(QStringLiteral("当前页%2/%1").arg(nTotalPage).arg(nPageIndex));

            ui->pbnext->setEnabled(nPageIndex < nTotalPage && (nTotalPage>=1));
            ui->pbEnd->setEnabled(nPageIndex<nTotalPage && (nTotalPage>=1));

            ui->pbBegin->setEnabled(nPageIndex>1 && (nTotalPage>=1));
            ui->pbblow->setEnabled(nPageIndex>1 && (nTotalPage>=1));
			
            break;
        }
    }
}

void HistoryRecordDialog::getBeginAndEndTime(const QString& strid, const QString strflag)
{
    auto cb = mReceiver->createCallback< Biz::RecordInforBegEndTmList >([this, strid, strflag](const  Biz::RecordInforBegEndTmList& listInfor)
	{
        const QList<Biz::RecordInforBegEndTm>& tmlist = listInfor.getRecordInforList();
        quint64 currentfindtm = listInfor.getcontainsmsgtime();
		quint64 findtm = 0;
		int PageId = 0;
		for (Biz::RecordInforBegEndTm tm: tmlist)
		{
			if (tm.uBeginTm <= currentfindtm && tm.uEndTm >= currentfindtm)
			{
				findtm = tm.uBeginTm;
				break;
			}
			++PageId;
		}

		//IOE_
		if (findtm == 0)
		{
			return;
		}
		else
		{
			DisplayfindTm(strid, strflag, findtm, PageId);
		}
		

	},[]{}
	);

	for (Biz::RecordInfor infor: mlistInfor)
	{
		if (infor.strgroupjid == strCurrentSelectUserid)
		{
			
			Biz::Session::currentAccount().getHistoryRecordContainsFind(strid, strflag, infor.msgcount, cb);
		}
	}
}

void HistoryRecordDialog::DisplayfindTm(const QString& strid, const QString&strflag ,quint64 findtm, int nPageid)
{
	
	loadChatHtml(ui->webView, "/html/groupdialog.html");

//	ui->webView->setContextMenuPolicy(Qt::CustomContextMenu);
	auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this, strid, strflag, nPageid](const QSharedPointer<Biz::MessageListData>& messageList )
	{
		ShowHtml(messageList, strflag);
		updatePageNumber(PAGE_DIRECTIO_LAST, nPageid);
		

	}, []{ });
	Biz::Session::currentAccount().getHistoryRecordMessageList(strid,30, findtm,callback,PAGE_DIRECTIO_LAST);
}


void HistoryRecordDialog::setcurrentgroupid(const QString& strgroupid)
{
	mCurrentGroupid = strgroupid;
}

void HistoryRecordDialog::resizeEvent( QResizeEvent *event )
{
	int nwidth = ui->tableView->width();

	ui->tableView->head->resizeSection(0, nwidth*0.20);
	ui->tableView->head->resizeSection(1, nwidth*0.45);
	ui->tableView->head->resizeSection(2, nwidth*0.25);
	ui->tableView->head->resizeSection(3, nwidth*0.10);
	BaseChatDialog::resizeEvent(event);
}

void HistoryRecordDialog::onMessageReceived(const QSharedPointer<Biz::XmppMessage>&)
{
}

void HistoryRecordDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{

}
