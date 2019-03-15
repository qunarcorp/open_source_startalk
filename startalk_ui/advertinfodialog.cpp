#include "advertinfodialog.h"
#include "Account.h"
#include "Session.h"
#include "conversationmanager.h"
#include "DownloadManager.h"
#include "CallbackReceiver.h"
#include "ConfigureHelper.h"
#include "imageviewer.h"

#include "diywidgit/customviews/qframelayout.h"
#include "QDesktopServices"
#include <ImageHelper.h>

AdvertInfoDialog * AdvertInfoDialog::pInstance = NULL;
AdvertInfoDialog::AdvertInfoDialog(QWidget *parent)
	: LocalManDialog(parent),mReceiver(new Biz::CallbackReceiver(this)), mJid(""), mstrSendMsg(""), mstrUrl("")
{
	ui.setupUi(this);
	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

	//connect(ui.pbClose, &QPushButton::clicked, this, &AdvertInfoDialog::onClose);
	connect(ui.pbSearch, &QPushButton::clicked, this, &AdvertInfoDialog::onSearchProductInfo);
	connect(ui.pbCancel, &QPushButton::clicked, this, &AdvertInfoDialog::onClose);
	connect(ui.pbSend, &QPushButton::clicked, this, &AdvertInfoDialog::onSendMsg);
	this->setWindowTitle(QStringLiteral("查询相关产品及推荐"));


 	ui.titlebar->setMinable(false);
 	ui.titlebar->setMaxable(false);

	connect(ui.titlebar,&TitlebarWidget::sgCloseOnClicked,this,&AdvertInfoDialog::onClose);

	
	QFrameLayout* layout = new QFrameLayout(ui.picbk);
	layout->appendWidget(ui.productpic,AlinementPolicy::ALINE_FILL);
	layout->appendWidget(ui.tagbk,AlinementPolicy::ALINE_MATCHWIDTH|AlinementPolicy::ALINE_BOTTOM);
	ui.titlebar->setLeftTitle(QStringLiteral("查询相关产品及推荐"));

	connect(ui.label_title, &QLabel::linkActivated, this, & AdvertInfoDialog::onOpenLabel);
	connect(ui.productpic, &QLabel::linkActivated, this, & AdvertInfoDialog::onOpenLabel);

	ui.pbSend->setDisabled(true);
	ui.producttype->setVisible(false);
	ui.producttag->setVisible(false);
}

AdvertInfoDialog::~AdvertInfoDialog()
{
	if (pInstance)
	{
		delete pInstance;
	}
}

AdvertInfoDialog* AdvertInfoDialog::instance()
{
	if (pInstance==NULL)
	{
		pInstance = new AdvertInfoDialog();
	}
	return pInstance;
}

void AdvertInfoDialog::showAdvertInfoDlg()
{
	showNormal();
	activateWindow();
	ui.stackedWidget->setCurrentWidget(ui.emptyPage);
}

void AdvertInfoDialog::onSearchProductInfo()
{
	QString strProductId = ui.lineEdit_productId->text();
	QString strBusiness = "dujia";
	if (strProductId.isEmpty())
	{
		return;
	}
	QString textEdit = ui.textEdit->toPlainText();
	ui.productpic->setText(QStringLiteral("正在查询..."));

	ui.stackedWidget->setCurrentWidget(ui.contentPage);
	auto cb = mReceiver->createCallback< QVariantMap >([this, textEdit](const QVariantMap& resultmap){
		if (resultmap.size() == 0)
		{
			ui.productpic->setText(QStringLiteral("查询失败"));
			return;
		}
		ui.pbSend->setDisabled(false);
		ui.producttype->setVisible(true);
		ui.producttag->setVisible(true);
		ui.label_title->setVisible(true);
		ui.label_markprice_title->setVisible(true);
		ui.label_markprice->setVisible(true);

		ui.label_qunarprice_title->setVisible(true);
		ui.label_qunarprice->setVisible(true);
		ui.productpic->setVisible(true);

		QString strtitle = resultmap["title"].toString();
		QString strtype = resultmap["type"].toString();
		QString strtag = resultmap["tag"].toString();
		QString strimage = resultmap["imageUrl"].toString();
		QString strmarketprice = resultmap["marketPrice"].toString();
		QString strappDtlUrl = resultmap["appDtlUrl"].toString();
		QString strtouchDtlUrl = resultmap["touchDtlUrl"].toString();
		QString strwebDtlUrl = resultmap["webDtlUrl"].toString();
		QString strpice = resultmap["price"].toString();
		
		QVariantMap varnewmap = resultmap;
		varnewmap.insert("extendMsg", textEdit);

		QJsonObject obj = QJsonObject::fromVariantMap(varnewmap);
		QJsonObject obj1;

		obj1.insert("data", obj);

		QJsonDocument input(obj1);
		mstrSendMsg = input.toJson(QJsonDocument::Compact);
		mstrUrl = strtouchDtlUrl;

		auto cb = mReceiver->createCallback<QString>(
			[this, resultmap, strtouchDtlUrl, strtitle, strpice,strmarketprice, strtype, strtag, strwebDtlUrl](QString strfile)
		{
			showProductInfor(strfile, strtitle, strpice, strmarketprice, strtype, strtag, strwebDtlUrl);
		}, []{
			Log::e(QString("AdvertInfoDialog::onSearchProductInfo downloadfile callback fail"));
		});

		QString savePath = Biz::ConfigureHelper::getImageLocalSavePath(strimage,"");//Biz::Session::getDownLoadManager()->getImageLocalSavePath(strimage,"");
		QString fileName = QFileInfo(savePath).fileName();
		Biz::Session::getDownLoadManager()->downloadFile(strimage,fileName,"","",false,cb);

	},[this]{
		ui.productpic->setText(QStringLiteral("查询失败"));
		return;
	});

	Biz::Session::getServiceManager()->getHttpService()->getProductionInfo(strProductId, strBusiness, cb);
}

void AdvertInfoDialog::onSendMsg()
{
	Biz::Session::getConverSationManager()->SendProductInfo(mstrSendMsg,mstrUrl, mJid);
    onClose();
}

void AdvertInfoDialog::onClose()
{
	this->close();
	ui.lineEdit_productId->setText("");
	ui.pbSend->setDisabled(true);
	ui.producttype->setVisible(false);
	ui.producttag->setVisible(false);
	ui.productpic->setVisible(false);
	ui.label_title->setVisible(false);
	ui.label_markprice_title->setVisible(false);
	ui.label_markprice->setVisible(false);

	ui.label_qunarprice_title->setVisible(false);
	ui.label_qunarprice->setVisible(false);
}

void AdvertInfoDialog::setJid( const QString&jid )
{
	mJid = jid;
}

void AdvertInfoDialog::showProductInfor( const QString& fileName, const QString& title
										, const QString& price, const QString& markprice, const QString& type, const QString& tag, const QString& strWeburl )
{
	setPixmap(fileName, strWeburl);
	QString strtitle = title;
	if (strtitle.length() > 36)
	{
		strtitle = strtitle.left(36);
		strtitle += QStringLiteral("...");

	}
	ui.label_title->setText(QString("<font size='+2' color='#2C80C0'><b><p align='center'><a href=\"%2\" style=\"cursor:pointer\";>%1</a></p></b></font>")
		.arg(strtitle).arg(strWeburl));
	ui.label_title->setWordWrap(true); // 自动换行设置
	ui.label_title->setToolTip(title);
    ui.label_title->adjustSize();
	

	ui.label_markprice_title->setText(QStringLiteral("市场价:"));//555555
	ui.label_markprice->setText(QString("<font color='#AAAAAA' size='+1' face='Sans'><p><s>%1</s></p></font>").arg(markprice));
	ui.label_qunarprice_title->setText(QStringLiteral("去哪儿价:"));
	ui.label_qunarprice->setText(QString("<font color='#FF6600' size='+1' face='Sans'>%1</font>").arg(price));

	ui.producttag->setText(QStringLiteral("%1").arg(tag));
	ui.producttype->setText(QStringLiteral("%1").arg(type));
}

void AdvertInfoDialog::setPixmap( const QString& path, const QString& weburl )
{
	if (path.isEmpty() || weburl.isEmpty())
	{
		return;
	}
	QString str;
	QImage img = Biz::ImageHelper::loadImageFromPath (path);
	int nRet = QFile::exists(path);
	QPixmap pixMap = QPixmap::fromImage(img);   
	if (QFile::exists(path) && !pixMap.isNull())
	{

		//resizeImageFrame(QSize(pixMap.width(),pixMap.height()));
		QSize frameSize = ui.picbk->size();
 		str = QString("<a href=\"%4\" style=\"cursor:pointer;\"><img src='%1' width='%2' height='%3' /></a> ")
 			.arg(path).arg(frameSize.width()).arg(frameSize.height()).arg(weburl);
		
	}
	else
	{
		str = QStringLiteral("<font color='#5500ff' size='+1'><b><p align='center'>图片无法显示</p></b></font>");
	}

	ui.productpic->setText(str);
}

void AdvertInfoDialog::onOpenLabel( const QString& url )
{
	QDesktopServices::openUrl(QUrl(QString("%1").arg(url)));
}


