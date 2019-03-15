#include "quickreplyedititemdlg.h"
#include "Session.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "gloableeventobject.h"

QuickReplyEditItemDlg::QuickReplyEditItemDlg(int type, QList<QSharedPointer<Biz::QuickReplyGroup>> groupInfoList,QWidget *parent)
	: LocalManDialog(parent), ntype(type),mGroupInfoList(groupInfoList)
{
	ui.setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint /*| WindowMinMaxButtonsHint*/;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	//setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));

	titlebar = ui.TitleBar;

	titlebar->setSizeable(false);
	titlebar->setMaxable(false);
	titlebar->setMinable(false);

	if (ntype == 0)
	{
		titlebar->setLeftTitle(QStringLiteral("增加"));
	}
	else if (ntype == 1)
	{
		titlebar->setLeftTitle(QStringLiteral("修改"));
		
	}

	for (QSharedPointer<Biz::QuickReplyGroup> groupItem : groupInfoList)
	{ 
		ui.comboBox_group->addItem(groupItem->GroupName(),groupItem->GroupCId());
	} 

	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &QuickReplyEditItemDlg::onClose);
	connect(ui.pb_OK, &QPushButton::clicked, this, &QuickReplyEditItemDlg::onClickedOk);
	connect(ui.pbCancel, &QPushButton::clicked, this, &QuickReplyEditItemDlg::onClickedCancle);
}

QuickReplyEditItemDlg::~QuickReplyEditItemDlg()
{

}

void QuickReplyEditItemDlg::onClose()
{
	this->close();
}


void QuickReplyEditItemDlg::onClickedCancle()
{
	this->close();
}

void QuickReplyEditItemDlg::onClickedOk()
{
	QString content = ui.textEdit->toPlainText();
	if (content.length() <= 0)
	{
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("请输入要设置的内容"));
		return;
	}
	if (mContentInfo.isNull())
	{
		QSharedPointer<Biz::QuickReplyContent> mContentInfo(new Biz::QuickReplyContent);
		QString guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
		mContentInfo->ContentCId(guid);
		QString groupCid = ui.comboBox_group->itemData(ui.comboBox_group->currentIndex()).toString();
		mContentInfo->GroupCId(groupCid);
		mContentInfo->Content(content);
		mContentInfo->ContentSeq(Biz::Session::getServiceManager()->getDaoService()->getMaxQuickReplyContentSeq(groupCid)+1);
		mContentInfo->ContentVersion(0);
		mContentInfo->optionFlag(0);
		QList<QSharedPointer<Biz::QuickReplyContent>> list;
		list.append(mContentInfo);
		bool ret = Biz::Session::getServiceManager()->getDaoService()->saveQuickReplyContentItems(list);
		if (ret)
		{
			emit GloableEventObject::getInstance()->sgQuickReplyContentChange(groupCid);
			setResult(QDialog::Accepted);
			this->done(QDialog::Accepted);
		} else
		{ 
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("创建新回复失败"));
		}
	} else
	{  
		mContentInfo->Content(content);
		QList<QSharedPointer<Biz::QuickReplyContent>> list;
		list.append(mContentInfo);
		bool ret = Biz::Session::getServiceManager()->getDaoService()->updateQuickReplyContentItems(list);
		if (ret)
		{
			setResult(QDialog::Accepted);
			this->done(QDialog::Accepted);
		} else
		{ 
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("修改内容失败"));
		}
	}

}

void QuickReplyEditItemDlg::setSelectGroupIndex(int groupIndex) {
	ui.comboBox_group->setCurrentIndex(groupIndex);
}

void QuickReplyEditItemDlg::SetModyContent(const QSharedPointer<Biz::QuickReplyContent> &contentInfo)
{
	mContentInfo = contentInfo;
	ui.textEdit->setText(contentInfo->Content()); 
}

void QuickReplyEditItemDlg::getContent( QStringList& strItem )
{
	strItem << ui.comboBox_group->currentText() << ui.textEdit->toPlainText();
}
