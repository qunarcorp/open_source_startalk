#include "TransferSessionDlg.h"
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtConcurrent/QtConcurrent>
#include "QuickReplyMsgMgrV2.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "WebService.h"

struct TransferUser : QObjectUserData {
    QString userId;  // ID
    QString domain;  // 用户名
};

TransferSessionDlg::TransferSessionDlg(QWidget *parent):LocalManWidget(parent)
{
	setupUi();
	setMoveable(false);
    mCallbackReceiver = new Biz::CallbackReceiver(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
	setAttribute(Qt::WA_TranslucentBackground, true); 
	setAutoFillBackground(true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
}

TransferSessionDlg::~TransferSessionDlg()
{

}

void TransferSessionDlg::showTranferDlg(QString &userJid){
	transferUserJid = userJid;
	this->init();
	this->show();
	this->activateWindow();		
}

void TransferSessionDlg::init() {
	
	selectUserView->setHidden(false);
	transferReasonView->setHidden(true);
	transferResultView->setHidden(true);
	transferDoing = false;
	this->loadTransferList();

}
 
void TransferSessionDlg::loadTransferList() {
	userListWidget->clear();
	/*for (int i = 0; i < 10; i++){
		QWidget *widget = createItemWidget(QString("%1").arg(i));
		QListWidgetItem *item = new QListWidgetItem(userListWidget);
		userListWidget->addItem(item);
		item->setSizeHint(QSize(0,36));
		userListWidget->setItemWidget(item,widget); 
	}
	return;*/
	auto callback = mCallbackReceiver->createCallback<QMap<QString, QVariant>>(
		[this](const QMap<QString, QVariant> &result){  
			this->userListWidget->clear();
			bool ret = result.value("ret").toBool();
			if (ret)
			{ 
				QList<QVariant> userList = result.value("data").toList();
				for (QVariant item : userList)
				{   
					QMap<QString,QVariant> dataMap = item.toMap();
					QString webName = dataMap.value("webName").toString(); 
					QString nickName = dataMap.value("nickName").toString();
					QMap<QString,QVariant> qunarNameMap = dataMap.value("qunarName").toMap();
					QWidget *widget = new QWidget;
					widget->setMinimumHeight(36);  
					QRadioButton *radioBtn = new QRadioButton(widget);
					radioBtn->setText(webName.length()>0?webName:nickName); 
					TransferUser *pUser = new TransferUser();
					pUser->userId = qunarNameMap.value("node").toString();
					pUser->domain = qunarNameMap.value("domain").toString();
					radioBtn->setUserData(Qt::UserRole, pUser);
					radioBtn->setGeometry(QRect(20,0,selectUserView->width()-40,36));
					radioGroupBtn->addButton(radioBtn); 
					QListWidgetItem *item = new QListWidgetItem(userListWidget);
					userListWidget->addItem(item);
					item->setSizeHint(QSize(0,36));
					userListWidget->setItemWidget(item,widget); 
				}  
			} else
			{
				QString errMsg = result.value("errmsg").toString(); 
				this->showErrorView(QStringLiteral("转移失败"),QStringLiteral("获取转移用户列表失败，")+errMsg);
			}
		},[]{}); 
	QStringList list = this->transferUserJid.split("|");
	if (list.length() == 2)
	{ 
		QtConcurrent::run(WebService::getSeatList,list.last(), callback);
	}
}

void TransferSessionDlg::showErrorView(const QString &title, const QString &content) {
	selectUserView->setHidden(true);
	transferReasonView->setHidden(true);
	transferResultView->setHidden(false);
	resultLabel->setText(title);
	resultContentLabel->setText(content);
}


QString TransferSessionDlg::getWillTransferUserJid(){
	TransferUser *pUser = (TransferUser *)radioGroupBtn->checkedButton()->userData(Qt::UserRole);
	return pUser->userId; 
}

void TransferSessionDlg::setupUi() {
	
	this->setObjectName(QStringLiteral("TransferSessionDlg"));
	this->resize(240, 260);

	selectUserView = new QWidget(this);
	selectUserView->setObjectName(QStringLiteral("selectUserView"));
	selectUserView->setGeometry(QRect(0, 0, this->width(), this->height()));
	selectUserView->setStyleSheet(QString::fromUtf8("QWidget#selectUserView {border: 1px solid #3A3A3A;background:#F0F0F0FF;border-radius: 5px;}"));

	userListWidget = new QListWidget(selectUserView); 
    userListWidget->setObjectName(QStringLiteral("userListWidget"));
    userListWidget->setAlternatingRowColors(true);
	userListWidget->setGeometry(QRect(0, 0, this->width(), this->height()-50));
	userListWidget->setSelectionMode(QAbstractItemView::NoSelection);
	userListWidget->setStyleSheet("QListWidget#userListWidget {outline：none;}");
	userListWidget->setFocusPolicy(Qt::NoFocus);
	/*userListWidget->setStyleSheet("QListWidget{border: none;background:#00000000;alternate-background-color: #EEF5F5F5;}\n"
	"QListWidget::item:selected {border: 1px solid #3A3A3A;color:white;background:#888dd9;}\n"
	"QListWidget::item:hover {border: 1px solid #3A3A3A;color:white;background:#888dd9;}\n"
	"QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);}\n"
	"QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);}\n"
	"QListWidget#userListWidget{background:#00000000;alternate-background-color: #EEF5F5F5;}\n");*/
	radioGroupBtn = new QButtonGroup(userListWidget);

	pbNextStepBtn = new QPushButton(selectUserView); 
    pbNextStepBtn->setObjectName(QStringLiteral("pbNextStepBtn"));
	pbNextStepBtn->setText(QStringLiteral("下一步"));
	//pbNextStepBtn->setStyleSheet("QPushButton#pbNextStepBtn {border : 1px solid #00000000;background:#1ba9ba;}");
	pbNextStepBtn->setGeometry(QRect((this->width()-120)/2.0, userListWidget->geometry().bottom()+10, 120, 28));
	connect(pbNextStepBtn, &QPushButton::clicked, this, &TransferSessionDlg::onNextStep);

	transferReasonView = new QWidget(this);
	transferReasonView->setObjectName(QStringLiteral("transferReasonView"));
	transferReasonView->setGeometry(QRect(0, 0, this->width(), this->height())); 
	transferReasonView->setHidden(true);
	transferReasonView->setStyleSheet(QString::fromUtf8("QWidget#transferReasonView {border: 1px solid #3A3A3A;background:#F0F0F0FF;border-radius: 5px;}"));

	reasonLabel = new QLabel(transferReasonView);
	reasonLabel->setObjectName(QStringLiteral("groupNameLabel"));
	reasonLabel->setGeometry(QRect(20, 15, this->width() - 40, 20)); 
	reasonLabel->setText(QStringLiteral("转移原因："));
	reasonLabel->setStyleSheet(QString::fromUtf8("QPushButton#reasonLabel {font-size:16px;}"));

	reasonTextEdit = new QTextEdit(transferReasonView); 
	reasonTextEdit->setObjectName(QStringLiteral("reasonTextEdit"));
	reasonTextEdit->setGeometry(QRect(reasonLabel->geometry().left(), reasonLabel->geometry().bottom()+10, reasonLabel->width(), this->height()-reasonLabel->geometry().bottom()-62)); 

	pbOkBtn = new QPushButton(transferReasonView);
    pbOkBtn->setObjectName(QStringLiteral("pbOkBtn"));
	pbOkBtn->setText(QStringLiteral("确定")); 
	//pbOkBtn->setStyleSheet("QPushButton#pbOkBtn {border : 1px solid #00000000;background:#1ba9ba;}");
	pbOkBtn->setGeometry(QRect(20, reasonTextEdit->geometry().bottom()+10, 90, 30));
	connect(pbOkBtn, &QPushButton::clicked, this, &TransferSessionDlg::onTransferOk);
	 
	pbCancelBtn = new QPushButton(transferReasonView);
    pbCancelBtn->setObjectName(QStringLiteral("pbCancelBtn"));
	pbCancelBtn->setText(QStringLiteral("取消")); 
	//pbCancelBtn->setStyleSheet("QPushButton#pbCancelBtn {border : 1px solid #00000000;background:#1ba9ba;}");
	pbCancelBtn->setGeometry(QRect(this->width() - 20 - 90, reasonTextEdit->geometry().bottom()+10, 90, 30));
	connect(pbCancelBtn, &QPushButton::clicked, this, &TransferSessionDlg::onTransferCancel);

	transferResultView = new QWidget(this);
	transferResultView->setObjectName(QStringLiteral("transferResultView"));
	transferResultView->setGeometry(QRect(0, 0, this->width(), this->height())); 
	transferResultView->setHidden(true);
	transferResultView->setStyleSheet(QString::fromUtf8("QWidget#transferResultView {border: 1px solid #3A3A3A;background:#F0F0F0FF;border-radius: 5px;}"));
	
	QFont rft;
	rft.setPointSize(16);
	resultLabel = new QLabel(transferResultView);
	resultLabel->setObjectName(QStringLiteral("groupNameLabel"));
	resultLabel->setGeometry(QRect(20, 15, this->width() - 40, 20)); 
	resultLabel->setText(QStringLiteral("转移失败"));
	resultLabel->setAlignment(Qt::AlignCenter); 
	resultLabel->setStyleSheet(QString::fromUtf8("QLabel#resultLabel {font-size:16px;}"));
	resultLabel->setFont(rft);

	QFont rcft;
	rcft.setPointSize(10);
	resultContentLabel = new QLabel(transferResultView); 
	resultContentLabel->setObjectName(QStringLiteral("reasonTextEdit"));
	resultContentLabel->setGeometry(QRect(reasonLabel->geometry().left(), reasonLabel->geometry().bottom()+10, reasonLabel->width(), this->height()-reasonLabel->geometry().bottom()-62)); 
	resultContentLabel->setStyleSheet(QString::fromUtf8("QLabel#resultContentLabel {font-size:12px;}"));
	resultContentLabel->setWordWrap(true);
	resultContentLabel->setAlignment(Qt::AlignTop); 
	resultContentLabel->setFont(rcft);

	pbDoneBtn = new QPushButton(transferResultView);
    pbDoneBtn->setObjectName(QStringLiteral("pbDoneBtn"));
	pbDoneBtn->setText(QStringLiteral("确定")); 
	//pbDoneBtn->setStyleSheet("QPushButton#pbDoneBtn {border : 1px solid #00000000;background:#1ba9ba;}");
	pbDoneBtn->setGeometry(QRect((this->width()-90)/2.0, resultContentLabel->geometry().bottom()+10, 90, 30));
	connect(pbDoneBtn, &QPushButton::clicked, this, &TransferSessionDlg::onTransferDone);

}

// 事件处理
void TransferSessionDlg::onNextStep() { 
	selectUserView->setHidden(true);
	transferReasonView->setHidden(false);
	transferResultView->setHidden(true);
}

void TransferSessionDlg::onTransferOk() {  
	if (!transferDoing)
	{
		transferDoing = true;
	} else
	{
		return;
	}
	auto callback = mCallbackReceiver->createCallback<QMap<QString, QVariant>>(
		[this](const QMap<QString, QVariant> &result){  
			bool ret = result.value("ret").toBool(); 
			transferDoing = false;
			if (ret)
			{  
				this->hide();
			} else
			{
				QString errMsg = result.value("errmsg").toString(); 
				this->showErrorView(QStringLiteral("转移失败"),QStringLiteral("失败原因，")+errMsg);
			}
		},[]{}); 
	QStringList list = this->transferUserJid.split("|");
	if (list.length() == 2)
	{ 
		QString userJid = this->getWillTransferUserJid();
		QString reason = this->reasonTextEdit->toPlainText();
		QtConcurrent::run(WebService::transformCsr,list.last(),userJid,list.first().split("@").first(),reason,callback);
	}
}

void TransferSessionDlg::onTransferCancel() { 
	this->hide();
}

void TransferSessionDlg::onTransferDone() {
	this->hide();
}