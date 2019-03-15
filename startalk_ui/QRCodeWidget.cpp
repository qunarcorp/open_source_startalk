#include "QRCodeWidget.h"
#include <QPropertyAnimation>
#include <QTimeLine>
#include "diywidgit/customviews/qframelayout.h"
#ifdef _WINDOWS
#include "QZXing.h"
#endif
#include <QApplication>
#include <QDesktopWidget>


QRCodeWidget::QRCodeWidget(QWidget *parent)
    : LocalManWidget(parent)
    , pAnimation(NULL)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
    setSizeGripEnabled(true);

    QFrameLayout* pLayoutBk = new QFrameLayout(ui.bk);
    pLayoutBk->appendWidget(ui.qrcodebk,ALINE_FILL);
    pLayoutBk->appendWidget(ui.btnClose,ALINE_TOP|ALINE_RIGHT,QMargins(0,20,20,0));

    QFrameLayout* pLayoutScan = new QFrameLayout(ui.center);
    pLayoutScan->appendWidget(ui.wtl,ALINE_TOP|ALINE_LEFT,QMargins(0,0,0,0));
    pLayoutScan->appendWidget(ui.wtr,ALINE_TOP|ALINE_RIGHT,QMargins(0,0,0,0));
    pLayoutScan->appendWidget(ui.wbl,ALINE_BOTTOM|ALINE_LEFT,QMargins(0,0,0,0));
    pLayoutScan->appendWidget(ui.wbr,ALINE_BOTTOM|ALINE_RIGHT,QMargins(0,0,0,0));
    connect(ui.btnClose,&QPushButton::clicked,[this]{
        this->onClose(true);
    });
    initDispacher();
    
}

QRCodeWidget::~QRCodeWidget()
{

}

void QRCodeWidget::autoShow()
{
    this->show();
    this->activateWindow();
}

void QRCodeWidget::showEvent(QShowEvent *)
{
    ui.splitLine->setFixedWidth(ui.center->width());
    if (NULL == pAnimation)
    {
        pAnimation = new QPropertyAnimation(ui.splitLine, "geometry");
        connect(pAnimation,&QPropertyAnimation::currentLoopChanged,this,&QRCodeWidget::onGrabQRcode);
        pAnimation->setDuration(3000);
        pAnimation->setStartValue(QRect(0,0,ui.center->width(),ui.splitLine->height()));
        pAnimation->setEndValue(QRect(0,ui.center->height(),ui.center->width(),ui.splitLine->height()));
        pAnimation->setLoopCount(-1);
    }
    pAnimation->start();
}

void QRCodeWidget::resizeEvent(QResizeEvent *e)
{
    ui.splitLine->setFixedWidth(ui.center->width());
    if (NULL!=pAnimation)
    {
        pAnimation->setStartValue(QRect(0,0,ui.center->width(),ui.splitLine->height()));
        pAnimation->setEndValue(QRect(0,ui.center->height(),ui.center->width(),ui.splitLine->height()));
    }
    LocalManWidget::resizeEvent(e);
}

#include <QMessageBox>

void QRCodeWidget::onGrabQRcode(int currentLoop)
{
#ifdef _WINDOWS
    if (currentLoop==0)
    {
        return;
    }
	QPoint ptCenterTL = ui.center->mapToGlobal(QPoint(0,0));
	int nRadio = this->devicePixelRatio();
	


    QPixmap grabPix = QPixmap::grabWindow(QApplication::desktop()->winId()
		, ptCenterTL.x()*nRadio,ptCenterTL.y()*nRadio,ui.center->width()*nRadio,ui.center->height()*nRadio); //抓取当前屏幕的图片


    QImage img = grabPix.toImage();
	//这时应该切换到业务线程中进行处理

	QString strDecode = QZXing().decodeImage(img);

	if(!strDecode.isEmpty())
    {
		
        if (NULL!=pAnimation)
            pAnimation->stop();

        for (auto mf : mDispatch) {
            if (mf(strDecode)) {
                this->close();
				
                return;
            }
        }
        // 没人能处理
        if (NULL!=pAnimation)
            pAnimation->start();
    }
#endif

}

void QRCodeWidget::closeEvent(QCloseEvent *)
{
    if (NULL!=pAnimation)
    {
        pAnimation->stop();
    }
}


void QRCodeWidget::initDispacher()
{
    mDispatch.clear();
    mDispatch 
        << std::bind(&QRCodeWidget::dealGroupData,this,std::placeholders::_1)
        << std::bind(&QRCodeWidget::dealHttpData,this,std::placeholders::_1)
        << std::bind(&QRCodeWidget::dealTextData,this,std::placeholders::_1) ;
}

#include "Session.h"
#include "GroupManager.h"
#include "UIFrame.h"
#include "ConversationController.h"
bool QRCodeWidget::dealGroupData(const QString& data)
{

    //qtalk://group?id=
    QUrl url(data);
    QString scheme = url.scheme();
    QString path = url.host()+url.path();

    if (0 == scheme.compare("qtalk",Qt::CaseInsensitive))
    {
        if (0 == path.compare("group",Qt::CaseInsensitive))
        {
            QUrlQuery quq(url);
            QString id = quq.queryItemValue("id");
            id = Biz::MessageUtil::makeSureGroupJid(id);
            if (!id.isEmpty())
            {
                Biz::Session::getGroupManager()->joinGroup(id,NULL);
                MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(id);
                MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(id,MainApp::ConversationController::sDefaultExtendPanel);
                MainApp::UIFrame::getConversationController()->activeConversation(id);
                MainApp::UIFrame::getConversationController()->moveSessionToTop(id);
                return true;
            }
        }
    }
    return false;
}

#include "Ordermanagedialog.h"
bool QRCodeWidget::dealHttpData(const QString& data)
{
    QUrl url(data);
    if (url.scheme().compare("http",Qt::CaseInsensitive)==0 || url.scheme().compare("https",Qt::CaseInsensitive)==0 )
    {
        CommentWebViewSingleton::getInstance()->openCommonUrl(data);
         return true;
    }
    return false;
}

bool QRCodeWidget::dealTextData(const QString& data)
{
	CommentWebViewSingleton::getInstance()->showHtmlContent(data);
    return true;
}
