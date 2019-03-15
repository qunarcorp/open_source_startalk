#include "RobotSearchedItem.h"
#include <QPushButton>
#include "diywidgit/customviews/qframelayout.h"
#include "CallbackReceiver.h"
#include "Session.h"
#include "RobotManager.h"
#include "conversationmanager.h"

#include "UIFrame.h"
#include "ConversationController.h"
#include "NotifyCenterController.h"

RobotSearchedItem::RobotSearchedItem(QWidget *parent)
	: QWidget(parent)
	, mReceiver(new Biz::CallbackReceiver(this))
{
	ui.setupUi(this);

	QFrameLayout* frameLayout = new QFrameLayout(this);
	frameLayout->appendWidget(ui.widget,ALINE_FILL);
	frameLayout->appendWidget(ui.rbtoperation,ALINE_MATCHHEIGHT|ALINE_RIGHT);
	this->setLayout(frameLayout);
	ui.rbtoperation->setVisible(false);
}

RobotSearchedItem::~RobotSearchedItem()
{

}

void RobotSearchedItem::setPixmap(const QPixmap& pixmap)
{
	//ui.robotimage->setScaledContents(true);
	QPixmap pix = pixmap;
	pix = QPixmap::fromImage(pix.toImage().scaled(ui.robotimage->size()));
	ui.robotimage->setPixmap(pix);
}

void RobotSearchedItem::setName(const QString& name)
{
	ui.robottitle->setText(name);
}

void RobotSearchedItem::setId(const QString& id)
{
	this->rbtId = id;
}

void RobotSearchedItem::setShowType(int type)
{
	if (ShowType_Search == type)
	{
		QPushButton* pAttemtion = new QPushButton(ui.rbtoperation);
		if (Biz::Session::getRobotManager()->isSubScriptedRobot(rbtId))
		{
			pAttemtion->setText(QStringLiteral("已关注"));
			pAttemtion->setEnabled(false);
		}
		else
		{
			pAttemtion->setText(QStringLiteral("关注"));
			pAttemtion->setEnabled(true);
		}
		
		pAttemtion->setFixedSize(60,36);
		
		ui.rbtBtnsGroup->addWidget(pAttemtion);
		ui.rbtoperation->setFixedSize(60,36);
		connect(pAttemtion,&QPushButton::clicked,this,&RobotSearchedItem::onAddRobotBtnClick);
	}
	if (ShowType_List == type)
	{
		QPushButton* pDetail = new QPushButton(ui.rbtoperation);
		pDetail->setText(QStringLiteral("详情"));
		pDetail->setFixedSize(40,36);
		ui.rbtBtnsGroup->addWidget(pDetail);
		QPushButton* pCancle = new QPushButton(ui.rbtoperation);
		pCancle->setText(QStringLiteral("取消订阅"));
		pCancle->setFixedSize(80,36);
		ui.rbtBtnsGroup->addWidget(pCancle);
		ui.rbtoperation->setFixedSize(120,36);
		connect(pDetail,&QPushButton::clicked,this,&RobotSearchedItem::onOpenRobotBtnClick);
		connect(pCancle,&QPushButton::clicked,this,&RobotSearchedItem::onCancelRobotBtnClick);
	}
}

void RobotSearchedItem::enterEvent(QEvent *)
{
	ui.rbtoperation->setVisible(true);
}

void RobotSearchedItem::leaveEvent(QEvent *)
{
	ui.rbtoperation->setVisible(false);
}

void RobotSearchedItem::onAddRobotBtnClick(bool bcheck)
{
	if (!rbtId.isEmpty())
	{
		auto callback = mReceiver->createCallback<QString>(
			[this](const QString& result){
				if (!result.isEmpty()&&result==rbtId)
				{
					// 订阅成功
					//Biz::Session::getRobotManager()->getAllRobot(); // -->刷新机器人列表
					Biz::Session::getRobotManager()->getRobotList();
				}
				else
				{
                     MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("订阅失败"));
				}
		}, [this](){});
		Biz::Session::getRobotManager()->subscriptRobot(rbtId,callback);
	}
}

void RobotSearchedItem::onOpenRobotBtnClick(bool bcheck)
{
    QString rbtJid = Biz::MessageUtil::makeSureUserJid(rbtId);

    MainApp::UIFrame::getConversationController()->addRobotChatRosterItem(rbtJid,"");
    MainApp::UIFrame::getConversationController()->activeConversation(rbtJid);
    MainApp::UIFrame::getConversationController()->moveSessionToTop(rbtJid);
}

void RobotSearchedItem::onCancelRobotBtnClick(bool bcheck)
{
	if (!rbtId.isEmpty())
	{
		auto callback = mReceiver->createCallback<QString>(
			[this](const QString& result){
				if (!result.isEmpty()&&result==rbtId)
				{
					// 订阅成功
					//Biz::Session::getRobotManager()->getAllRobot(); // -->刷新机器人列表
					Biz::Session::getRobotManager()->getRobotList();
                    QString rbtjid = Biz::MessageUtil::makeSureUserJid(rbtId);
                    MainApp::UIFrame::getConversationController()->removeConversation(rbtjid);
				}
				else
				{
                    MainApp::UIFrame::getNotifyCenterController ()->alertMessage(QStringLiteral("订阅失败"));
				}
		}, [this](){});
		Biz::Session::getRobotManager()->unSubscriptRobot(rbtId,callback);
	}
}
