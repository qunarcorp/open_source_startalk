#include "noticeinfotip.h"
#include "ui_NoticeInfoTip.h"
#include <QDesktopServices>
#include "ConversationController.h"
#include "UIFrame.h"
#include "XmppMessage.h"
#include "UiHelper.h"

#include "Session.h"
#include "conversationmanager.h"
#include "BizCallback.h"
#include "CallbackReceiver.h"
const static char* pbtn_data_type = "type_data";
const static char* pbtn_data_info = "info_data";
NoticeInfoTip::NoticeInfoTip(QWidget *parent)
	: QWidget(parent)
	,ui(new Ui::NoticeInfoTip())
	,mReceiver(new Biz::CallbackReceiver(this))
{
	ui->setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose, true);
	connect(ui->pushButton,&QPushButton::clicked,this,&NoticeInfoTip::closetip);
	//ui->pushButton->setIconSize(QSize(16,16));
	///ui->pushButton->setIcon(QIcon(QPixmap(":Images/icon_close.png")));
	//connect(ui->label, &QPushButton::clicked, this, &NoticeInfoTip::onClickedStyle);
	//ui->pushButton->setVisible(false);
	ui->scrollArea->setFrameShape(QFrame::NoFrame);
}

NoticeInfoTip::~NoticeInfoTip()
{

}

void NoticeInfoTip::setInfor( const QList <QSharedPointer<Biz::NoticeStrInfor>>& list )
{
	if (list.size() <= 0)
	{
		return;
	}
// 	int ncountfirst = ui->horizontalLayout->count();
// 	for (int nI = 0; nI < ncountfirst; nI++)
// 	{
// 		QLayoutItem *Item = ui->horizontalLayout->takeAt(ui->horizontalLayout->count() - 1);
// 		ui->horizontalLayout->removeItem(Item);
// 		if (Item)
// 		{
// 			delete Item;
// 			Item = NULL;
// 		}
// 	}
// 
// 	int ncount = ui->horizontalLayout->count();

	
	for (QSharedPointer<Biz::NoticeStrInfor> onItem: list)
	{
		if (onItem.isNull())
		{
			continue;
		}
		QString str = onItem->str();
		QString strType = onItem->type();
		QString strColor = onItem->strColor();

		QString shty = QString("QPushButton {border:none;color:%1;text-align:left center;padding-bottom:5px;}").arg(strColor);

		ItemBtn * pbtn = new ItemBtn(ui->groupbtn);
		pbtn->setAutoExclusive(true);
		pbtn->setFlat(true);
		pbtn->setCheckable(true);
		
		
		ui->horizontalLayout->addWidget(pbtn, Qt::AlignLeft);

		ui->horizontalLayout->setSpacing(0);

		connect(pbtn,&QPushButton::clicked,this,&NoticeInfoTip::onClickedStyle);

		pbtn->setStyleSheet(shty);

		
		QFontMetrics fm(ui->base->font());
		int nwidth = fm.width(str) + 17;
		//nwidth = (nwidth < 50? 60:nwidth) + 7;
		
		pbtn->setFixedSize(nwidth,30);
		//pbtn->move(5, -7);
		pbtn->setBtnData(onItem);

		QFontMetrics elidfont(ui->base->font());
		
		QString strNewInfo = elidfont.elidedText (str, Qt::ElideRight, nwidth);
		
		for (int i = 0; i <= 3; i++) {
			if (strType.compare(typeInfo[i], Qt::CaseInsensitive) == 0)
			{

				pbtn->setBtnType(i);
				break;
			}
		}
		
		pbtn->setText(strNewInfo);
		pbtn->show();

// 		int fixwidth = (ui->horizontalLayout->count()-1)*( nWidth+ui->horizontalLayout->spacing()) + nWidth + ui->horizontalLayout->spacing();
// 		ui->groupbtn->setFixedWidth(fixwidth);
	}
	ui->horizontalLayout->addStretch();
	ui->horizontalLayout->setSpacing(0);
	
}

void NoticeInfoTip::showTip()
{
	
	this->show();
}

void NoticeInfoTip::closetip()
{

	//((BaseChatDialog *)parent())->DestoryNoticeTip();
	this->close();
	
}

void NoticeInfoTip::onClickedStyle()
{
	ItemBtn * pbtn = dynamic_cast<ItemBtn*>(sender());
	if (pbtn == NULL)
	{
		return;
	}

	int clickedType = pbtn->getBtnType();
	QSharedPointer<Biz::NoticeStrInfor> noticeStrinfo = pbtn->getBtnData();
	if (noticeStrinfo.isNull())
	{
		return;
	}
	if (clickedType == Link)
	{
		QDesktopServices bs;        
		bs.openUrl(QUrl(QString("%1").arg(noticeStrinfo->url())));
		closetip();
	}
	else if (clickedType == request)
	{

		QString url = noticeStrinfo->url();
		//需要异步再调用一下这个link //MainApp::UIFrame::getConversationController ()->

		auto successcallback = [this](const QSharedPointer<Biz::NoticeStrInfor>& noticeStrinfo){

			if (noticeStrinfo.isNull())
			{
				this->closetip();
				return;
			}

			if (noticeStrinfo->type() == "link")
			{
				QDesktopServices bs;        
				bs.openUrl(QUrl(QString("%1").arg(noticeStrinfo->url())));
			}
			else if (noticeStrinfo->type() == "newChat")
			{
				bool bret = noticeStrinfo->isCouslt();

				QString from = noticeStrinfo->from();

				QString to = noticeStrinfo->to();

				QString realfrom = noticeStrinfo->realFrom();

				QString realto = noticeStrinfo->realTo();

				QString couslt = noticeStrinfo->couslt();

				QString strconversationId;
				if (bret) // consult 消息类型
				{

					if (couslt.toInt()== Biz::VistorToOnDuty) // 是客人给客服发的信息
					{
						strconversationId = Biz::XmppMessage::makeConsultConversation5Id(realfrom,from);
					}
					else if (couslt.toInt() == Biz::OnDutyToVistor) // 是客服发给客人的信息
					{
						strconversationId = Biz::XmppMessage::makeConsultConversation5Id(from,to);
					}
				}
				else // 普通消息类型
				{
					strconversationId = from;
				}
				MainApp::UIFrame::getConversationController()->doCreateChatDialog(strconversationId, "");
			}

			
			this->closetip();
		};
		auto failcallback = [this]{
			Log::e("NoticeInfoTip::onClickedStyle() is callback fial");
			this->closetip();
		};

		Biz::UnitCallback<QSharedPointer<Biz::NoticeStrInfor>>* retcallback = mReceiver->createCallback<QSharedPointer<Biz::NoticeStrInfor>>(successcallback, failcallback);
		Biz::Session::getConverSationManager()->getNoticeLinkInfo(url,retcallback);

	}
	else if (clickedType == text)
	{
		closetip();
	}
	else if (clickedType == newChat)
	{
		bool bret = noticeStrinfo->isCouslt();

		QString from = noticeStrinfo->from();

		QString to = noticeStrinfo->to();

		QString realfrom = noticeStrinfo->realFrom();

		QString realto = noticeStrinfo->realTo();

		QString couslt = noticeStrinfo->couslt();

		QString strconversationId;
		if (bret) // consult 消息类型
		{
			if (couslt.toInt()== Biz::VistorToOnDuty) // 是客人给客服发的信息
			{
				strconversationId = Biz::XmppMessage::makeConsultConversation5Id(realfrom,from);
			}
			else if (couslt.toInt() == Biz::OnDutyToVistor) // 是客服发给客人的信息
			{
				strconversationId = Biz::XmppMessage::makeConsultConversation5Id(from,to);
			}
		}
		else // 普通消息类型
		{
			strconversationId = from;
		}
		MainApp::UIFrame::getConversationController()->doCreateChatDialog(strconversationId, "");
		closetip();
	}

}
