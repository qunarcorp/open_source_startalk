#include "newsdialog.h"
#include "MultiDialogContainer.h"
#include "CallbackReceiver.h"
#include "ChatCommObject.h"
#include "ChatWebPage.h"
#include "SystemDefine.h"
#include "LanguageHelper.h"
#include "portraithelper.h"
#include "Session.h"
#include "Account.h"
#include "MessageListData.h"
#include "SystemConfigData.h"
#include "QXmppUtils.h"
#include "Ordermanagedialog.h"
#include "StaticData.h"
#include "RosterListWidget.h"
#include "AccountData.h"
#include "friendsmanager.h"
#include "MessageManager.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "ConfigureHelper.h"
#include "ui_ChatDialog.h"
#include "conversationmanager.h"

NewsDialog::NewsDialog(MultiDialogContainer* cntainer,int type, QWidget *parent/*=0*/)
	:ChatDialog(cntainer,parent)
{
	
	ui->trace->setVisible(false);
	ui->pushButton_muc->setVisible(false);
	ui->sendmail->setVisible(false);
	ui->leNotice->setText("");
	ui->leJid->setText("");
	//headimageµÄÍ¼Æ¬ÏÔÊ¾
	QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(conversationId());

	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));

	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));
	m_bInhertAttribute = false;
	ui->headerimage->setPixmap(pixmap);
	ui->name->setCursor(QCursor(Qt::ArrowCursor));
	ui->status->setVisible(false);

	ui->headerimage->setCursor(QCursor(Qt::ArrowCursor));
	ui->platformIcon->setVisible(false);

}

NewsDialog::~NewsDialog()
{
}

void NewsDialog::onLoadRoster( const QString& userID, const QString& displayName )
{
	this->setWindowTitle(displayName);

	Q_ASSERT(!displayName.isEmpty());
	ui->name->setText(displayName);


	setCounversationId(Biz::MessageUtil::makeSureUserJid(userID));
	
	doSetHeaderImage();

	QSharedPointer<Biz::XmppMessage> msg (new Biz::XmppMessage(conversationId()));
	msg->MsgSourceType(Biz::headline);
	Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
}


void NewsDialog::getHistoryByPage(int count, quint64 timestamp, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback)
{
	Biz::Session::getMessageManager()->getHistorySystemMsgList(conversationId(),count,timestamp,callback);
}

void NewsDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{

}
