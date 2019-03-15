#include "SendProductCardDialog.h"
#include <qjsondocument.h>
#include "UIFrame.h"
#include "NotifyCenterController.h"

SendProductCardDialog::SendProductCardDialog(QWidget *parent)
	: LocalManDialog(parent)
{
	this->initUI();
	
	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint /*| WindowMinMaxButtonsHint*/;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	//setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add)); 
	//setWindowIcon(QIcon(":/Images/Deal_chat.ico")); 
	//setWindowTitle(QStringLiteral("发送产品卡片"));
	titlebar->setSizeable(false);
	titlebar->setMaxable(false);
	titlebar->setMinable(false);
	titlebar->setLeftTitle(QStringLiteral("发送产品卡片"));
	
	connect(this->pbSendBtn, &QPushButton::clicked, this, &SendProductCardDialog::onClickedOk);
	connect(this->pbCancelBtn, &QPushButton::clicked, this, &SendProductCardDialog::onClickedCancle);
}

SendProductCardDialog::~SendProductCardDialog()
{

}

QString SendProductCardDialog::getProductCardJson() {
	return this->productContentTextEdit->toPlainText();
}

void SendProductCardDialog::initUI() {
	this->setObjectName(QStringLiteral("QuickReplyGroupEditDlg"));
    this->resize(300, 300);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
	
	widget_bk = new QWidget(this);
    widget_bk->setObjectName(QStringLiteral("widget_bk"));
	widget_bk->setGeometry(QRect(0, 0, this->width(), this->height()));
	
	titlebar = new TitlebarWidget(widget_bk);
    titlebar->setObjectName(QStringLiteral("titlebar"));
    titlebar->setGeometry(QRect(0, 0, this->width(), 30));

	productTitleLabel = new QLabel(widget_bk);
	productTitleLabel->setObjectName(QStringLiteral("productTitleLabel"));
	productTitleLabel->setGeometry(QRect(20, titlebar->geometry().bottom() + 5, this->width() - 40, 30)); 
	productTitleLabel->setText(QStringLiteral("产品卡片Json："));

	productContentTextEdit = new QTextEdit(widget_bk);
	productContentTextEdit->setObjectName(QStringLiteral("productContentTextEdit"));
	productContentTextEdit->setGeometry(QRect(productTitleLabel->geometry().left(), productTitleLabel->geometry().bottom(), productTitleLabel->width(), this->height()-productTitleLabel->geometry().bottom()-62)); 
	//productContentTextEdit->setMinimumSize(QSize(210, 93));
    //productContentTextEdit->setMaximumSize(QSize(210, 93));

	QRect bottomViewFrame;
	bottomViewFrame.setLeft(productContentTextEdit->geometry().left());
	bottomViewFrame.setWidth(this->width() - 30);
	bottomViewFrame.setTop(productContentTextEdit->geometry().bottom() + 10);
	bottomViewFrame.setHeight(40);
	bottomBtnView = new QWidget(widget_bk); 
    bottomBtnView->setObjectName(QStringLiteral("bottomBtnView"));
	bottomBtnView->setGeometry(bottomViewFrame); 
	 
	hBoxLayout = new QHBoxLayout(bottomBtnView);
    hBoxLayout->setObjectName(QStringLiteral("hBoxLayout"));

	bottomSpacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
	hBoxLayout->addItem(bottomSpacerItem);
	   
	pbSendBtn = new QPushButton(bottomBtnView);
    pbSendBtn->setObjectName(QStringLiteral("pbSaveBtn"));
	pbSendBtn->setText(QStringLiteral("发送"));
	hBoxLayout->addWidget(pbSendBtn);

	pbCancelBtn = new QPushButton(bottomBtnView);
    pbCancelBtn->setObjectName(QStringLiteral("pbCancelBtn"));
	pbCancelBtn->setText(QStringLiteral("取消"));
	hBoxLayout->addWidget(pbCancelBtn);
}

void SendProductCardDialog::onClickedOk() { 
	QString productStr = this->productContentTextEdit->toPlainText();
	if (productStr.length() <= 0)
	{
		return;
	}
	QJsonParseError Json_Parse_Error;
	QJsonDocument Json_Data = QJsonDocument::fromJson(productStr.toUtf8().data(), &Json_Parse_Error);
	if (Json_Parse_Error.error == QJsonParseError::NoError)
	{
		QMap<QString, QVariant> productMap = Json_Data.toVariant().toMap();
		QMap<QString, QVariant> dataMap = productMap.value("data").toMap();
		QString title = dataMap.value("title").toString();
		if (title.length() <= 0)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未设置产品卡片标题"));
			return;
		}
		QString imageUrl = dataMap.value("imageUrl").toString();
		if (imageUrl.length() <= 0)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未设置产品卡片图片"));
			return;
		}
		QString appDtlUrl = dataMap.value("appDtlUrl").toString();
		QString touchDtlUrl = dataMap.value("touchDtlUrl").toString();
		if (appDtlUrl.length() <= 0 && touchDtlUrl.length() <= 0)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未设置产品卡片链接地址"));
			return;
		}
		
	} else
	{ 
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("无效的Json字符串"));
		return;
	}
	setResult(QDialog::Accepted);
	this->done(QDialog::Accepted);
}

void SendProductCardDialog::onClickedCancle() { 
	this->close();
}