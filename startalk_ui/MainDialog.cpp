#include "MainDialog.h"
#include "ui_MainDialog.h"
#include <QGraphicsDropShadowEffect>
#ifdef _WINDOWS
#include <windows.h>
#include <windowsx.h>
#endif
#include "Account.h"
#include "Session.h"
#include "loginmanager.h"
#include "MainWidget.h"
#include "Framework.h"
#include "UserLogin.h"
#include "AccountData.h"
#include "LogWriter.h"
#include "LogProcess.h"
#include "UserSettingData.h"
#include "LanguageHelper.h"
#include "NotifyWindow.h"
#include "qevent.h"

#include "gloableeventobject.h"
#include "UIFrame.h"
#include "MainDialogController.h"
#include "SettingData.h"
#include "CustomDefine.h"
#include "QuitOnCloseNotice.h"
#include "diywidgit/customviews/qframelayout.h"

#include "UiHelper.h"
#include "conversationmanager.h"
#include <QClipboard>
const int MainDialog::sExtendWidth = 200;

MainDialog::MainDialog(QWidget *parent)
    : LocalManWidget(parent)
    , ui(new Ui::MainDialog)
    , mMainWidget(NULL)
    , shakeTimer(new QTimeLine)
    , bExtendModeShow(false)
{
	ui->setupUi(this);
    //   mConsoleDialog = new ConsoleDialog(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef _WINDOWS
    LogProcess::Instance()->setHwnd((HWND)this->winId());
// #else
// 	setWindowFlags(Qt::WindowStaysOnTopHint);
#endif

    connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgAllMessageUnreadCountChanged,this,&MainDialog::onUnreadMsgChanged);
    connect(&NotifyWindow::instance(), &NotifyWindow::sgOpenConversation, this, &MainDialog::onNodifyWindowClicked);
    setDefaultWindow();
    showMainWidget();


    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    titlebar->setLeftTitle("");
    titlebar->setMaxable(false);
    titlebar->setFixedWidth(100);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, [this](bool bcheck){
        this->onMin(bcheck);
        emit MainApp::UIFrame::getMainDialogController()->sgMainDialogVisableChange(false);
    });

    connect(titlebar, &TitlebarWidget::sgCloseOnClicked,[this]{

#ifndef _WINDOWS
        this->onMin(true);
        emit MainApp::UIFrame::getMainDialogController()->sgMainDialogVisableChange(false);

#else

        emit MainApp::UIFrame::getMainDialogController()->sgMainDialogVisableChange(false);

        if (Biz::QuitOnCloseOption::QOC_NOTSET == Biz::Session::getSettingConfig()->QuitOnClose())
        {
            QuitOnCloseNotice dialog;
            dialog.exec();
        }

        emit MainApp::UIFrame::getMainDialogController()->sgMainDialogClosed();

        if (Biz::QuitOnCloseOption::QOC_QUIT==Biz::Session::getSettingConfig()->QuitOnClose())
            qApp->quit();
        else
            this->onClose(false);
        #endif
    });

	connect(titlebar, SIGNAL(sgMinOnClicked()), this,  SIGNAL(GloableEventObject::sgMainDlgMin()));
    connect(GloableEventObject::getInstance(),&GloableEventObject::sgShake,this,&MainDialog::onShake);

    shakeTimer->setDuration(400);
    shakeTimer->setFrameRange(0,100);
    connect(shakeTimer,&QTimeLine::frameChanged,this,&MainDialog::onShakeMove);
    connect(shakeTimer,&QTimeLine::finished,this,&MainDialog::onShakeOver);
	connect(GloableEventObject::getInstance(),&GloableEventObject::sgHideMainWidge,this,&MainDialog::onHideMainWidge);
	connect(GloableEventObject::getInstance(),&GloableEventObject::sgShowMainWidge,this,&MainDialog::onShowMainWidge);
	
    MainApp::UIFrame::getMainDialogController()->registMainDialog(this);

    QFrameLayout* pFrameLayout = new QFrameLayout(ui->shadowinnerbg3);
    pFrameLayout->appendWidget(ui->pannel,ALINE_FILL);
    pFrameLayout->appendWidget(ui->titlebar,ALINE_TOP|ALINE_RIGHT,QMargins(0,0,0,0));
    pFrameLayout->appendWidget(ui->extendbar,ALINE_TOP|ALINE_RIGHT,QMargins(0,0,67,0));
    
    intThemeButton();

}

MainDialog::~MainDialog()
{
    delete ui;
    ui = NULL;
    if(mMainWidget)
        delete mMainWidget;
    mMainWidget = NULL;
}

void MainDialog::showMainWidget()
{    
    if(mMainWidget == NULL)
    {
        mMainWidget = new MainWidget;
        connect(mMainWidget, &MainWidget::sgMin, this, &MainDialog::onMin);
        connect(mMainWidget, &MainWidget::sgClose, [this](bool check){
            this->onClose(false);
        }
        );
        connect(mMainWidget, &MainWidget::sgSystemIconChanged, this, &MainDialog::onSystemIconChanged);
       
        ui->pannelLayout->addWidget(mMainWidget);
    }
}

bool MainDialog::nativeEvent(const QByteArray & eventType, void * message, long * result) 
{  
    return QWidget::nativeEvent("", message, result);
}

void MainDialog::onSystemIconChanged( const QString& path, const QString& userID, const QString& userNickName, const QString& message )
{
    if( this->isActiveWindow() ){
        return;
    }

#ifdef _WINDOWS
    FlashWindow((HWND)this->winId(), true);
#endif
}

void MainDialog::setDefaultWindow()
{
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("Application_Name"));
}

void MainDialog::onNodifyWindowClicked( const QString& userID )
{
    this->show();
    this->activateWindow();
}


void MainDialog::Logout()
{
    if(mMainWidget)
        mMainWidget->doLogout();
}


void MainDialog::setTitle(const QString& title)
{
    setWindowTitle(title);
}

void MainDialog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->onClose(false);
        return;
    }
    
    return LocalManWidget::keyPressEvent(event);
}


void MainDialog::mouseDoubleClickEvent(QMouseEvent * e)
{

    QPoint pt = e->pos();
    // 上边菜单68px,左侧菜单区域60px
    if (pt.y()>68 && pt.x() > 60)
    {
        return;
    }

    if (this->isMaximized())
    {
        this->showNormal();
    }
    else
    {
        this->showMaximized();
    }
}



void MainDialog::onShake()
{
    QPoint point = this->pos();
    wndpose = point;
    //wndpose = mapToGlobal(point);
    shakeTimer->start();
}

void MainDialog::onShakeMove(int framevalue)
{
    static QMap<int,QPair<int,int>> mapOffset;
    if (mapOffset.isEmpty())
    {
        int offsetvalue = 4; 
        mapOffset.insert(0,QPair<int,int>(offsetvalue,0)); // 向右
        mapOffset.insert(1,QPair<int,int>(0,-offsetvalue)); // 向上
        mapOffset.insert(2,QPair<int,int>(-offsetvalue,0)); // 向左
        mapOffset.insert(3,QPair<int,int>(0,offsetvalue)); // 向下
        mapOffset.insert(4,QPair<int,int>(offsetvalue,0)); // 向右
        mapOffset.insert(5,QPair<int,int>(0,-offsetvalue)); // 向上
        mapOffset.insert(6,QPair<int,int>(-offsetvalue,0)); // 向左
        mapOffset.insert(7,QPair<int,int>(0,offsetvalue)); // 向下
    }

    int direction = (framevalue/12)%8;
    move(wndpose.x()+mapOffset.value(direction).first,wndpose.y()+mapOffset.value(direction).second);
}

void MainDialog::onShakeOver()
{
    move(wndpose);
}



QPixmap makeUnreadNoticeIcon(const QString& file,const QString& text ,int size)
{
    QImage iconImage(file);

    int maxWidth = qMax(iconImage.width(),iconImage.height());

    QPixmap retPixMap(maxWidth,maxWidth);
    retPixMap.fill(Qt::transparent);
    QPainter painter(&retPixMap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QColor("#00000000"));

    // 画个底图
    QRect rect((maxWidth-iconImage.width())/2,(maxWidth-iconImage.height())/2,iconImage.width(),iconImage.height());
    painter.drawImage(rect,iconImage);

    int round = 26;
    painter.setBrush(QBrush(QColor("#CC333333")));
    painter.drawRoundedRect(QRect(0,0,maxWidth,maxWidth),round,round);

    QPixmap retpixmap2(size,size);
    retpixmap2.fill(Qt::transparent);
    QPainter painter2(&retpixmap2);
    painter2.setRenderHint(QPainter::Antialiasing, true);
    painter2.setPen(QColor("#00000000"));
    painter2.drawPixmap(QRect(0,0,size,size),retPixMap);

    int fontsize = 20;
    if (size == 24)
    {
        fontsize = 10;
    }
    if (size == 32)
    {
        fontsize = 12;
    }
    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(fontsize);
    font.setBold(true);
    painter2.setFont(font);

    QRect txtRect = painter2.fontMetrics().boundingRect(text);   // 文本需要的大小
    txtRect.setWidth(txtRect.width());


    // 写个字字号大小是传入的最大值的
    txtRect.moveTo((size-txtRect.width())/2,(size-txtRect.height())/2);
	int nclr = Biz::Session::getSettingConfig()->TaskTextClr();
	QColor color = MainApp::intToQColor(nclr);
    painter2.setPen(color);//QColor("#FFFFFF")
	//painter2.setPen(QColor("#FF0000"));
    painter2.drawText(txtRect,text);
    return retpixmap2;
}

QPixmap makeUnreadNoticeTipIcon(const QString& file,int size)
{
	QImage iconImage(file);

	int maxWidth = qMax(iconImage.width(),iconImage.height());

	QPixmap retPixMap(maxWidth,maxWidth);
	retPixMap.fill(Qt::transparent);
	QPainter painter(&retPixMap);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QColor("#00000000"));

	// 画个底图
	QRect rect((maxWidth-iconImage.width())/2,(maxWidth-iconImage.height())/2,iconImage.width(),iconImage.height());
	painter.drawImage(rect,iconImage);

	int round = 26;
	painter.setBrush(QBrush(QColor("#CC333333")));
	painter.drawRoundedRect(QRect(0,0,maxWidth,maxWidth),round,round);

	QPixmap retpixmap2(size,size);
	retpixmap2.fill(Qt::transparent);
	QPainter painter2(&retpixmap2);
	painter2.setRenderHint(QPainter::Antialiasing, true);
	painter2.setPen(QColor("#00000000"));
	painter2.drawPixmap(QRect(0,0,size,size),retPixMap);

	int fontsize = 20;
	if (size == 24)
	{
		fontsize = 10;
	}
	if (size == 32)
	{
		fontsize = 12;
	}
	QFont font;
	font.setFamily("Arial");
	font.setPixelSize(fontsize);
	font.setBold(true);
	painter2.setFont(font);

	//QRect txtRect = painter2.fontMetrics().boundingRect(text);   // 文本需要的大小
	QRect txtRect;
	txtRect.setWidth(8);


	// 写个字字号大小是传入的最大值的
	txtRect.moveTo((size-txtRect.width())/2,(size-txtRect.height())/2);
	
	
	painter2.setPen(Qt::red);//QColor("#FFFFFF")
	painter2.setBrush(Qt::red);
	//painter2.setPen(QColor("#FF0000"));
	//painter2.drawText(txtRect,text);
	painter2.drawEllipse(txtRect.center(), 4, 4);
	return retpixmap2;
}


QPixmap makeUnreadNoticeIcon_old(const QString& text ,int size)
{
    int maxWidth = size;
    QPixmap retPixMap(maxWidth,maxWidth);
    retPixMap.fill(Qt::transparent);
    QPainter painter(&retPixMap);
    painter.setPen(QColor("#00000000"));

    // 画个底图
    QImage paintedImg;
#ifdef QCHAT
    paintedImg = QImage(":/Images/emptychat.png");
#else
    paintedImg = QImage(":/Images/empticon.png");
#endif // QCHAT

    
    QRect rect(0,0,maxWidth,maxWidth);
    painter.drawImage(rect,paintedImg);


    QFont font;
    int textsize = maxWidth/4.5;
    font.setPointSize(textsize);
    font.setBold(true);
    painter.setFont(font);

    QRect txtRect = painter.fontMetrics().boundingRect(text);   // 文本需要的大小
    txtRect.setWidth(txtRect.width()+2);

    // 左圆+矩形+右圆组成圆角矩形，圆角矩形要比文本大小多半径，高度与文本半径相同
    int d = txtRect.height()*1.414; // 半径是单数
    int bkHeight = d;
    int bkwidth = (txtRect.width()+d*0.3)>d?(txtRect.width()+d*0.3):d;

    QRect rectLeft(maxWidth-bkwidth,0,d,d);
    QRect rectCenter(maxWidth-bkwidth+d/2,0,bkwidth-d,d);
    QRect rectRight(maxWidth-d,0,d,d);
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(rectLeft);
    painter.drawRect(rectCenter);
    painter.drawEllipse(rectRight);

//     txtRect.moveTo(maxWidth-bkwidth+(bkwidth-txtRect.width())/2,(d-txtRect.height())/2);
//     painter.setBrush(QBrush(Qt::black));
//     painter.drawRect(txtRect);

    // 写个字字号大小是传入的最大值的
    txtRect.moveTo(maxWidth-bkwidth+(bkwidth-txtRect.width())/2,(d-txtRect.height())/2);
    painter.setPen(QColor("#FFFFFF"));
    painter.drawText(txtRect,text);
    return retPixMap;
}

void MainDialog::onUnreadMsgChanged(int count,bool hasNoCountUnreadMsg)
{
#ifdef QCHAT
	QString emptyIconPath = ":/Images/emptychat.png";
	QString nomarlIconPath = ":/Images/Deal_chat.ico";
#else
	QString emptyIconPath = ":/Images/empticon.png";
	QString nomarlIconPath = ":/Images/Deal.ico";
#endif // QCHAT

	// 未读数优先
    static int currentCount = 0;
	static bool shasNoCountUnreadMsg = false;

	// 没发生变化什么都不做
	if (currentCount==count && shasNoCountUnreadMsg == hasNoCountUnreadMsg)
		return;

	if (0 == count)
	{
		// 是否是变为0，变为0 之后要考虑显示红点提示
		if (!hasNoCountUnreadMsg)
		{
			if (shasNoCountUnreadMsg!=hasNoCountUnreadMsg)
			{
				 setWindowIcon(QIcon(nomarlIconPath));
			}
			else{
				// 保持原样
			}
		}
		else{
			QPixmap px = makeUnreadNoticeTipIcon(":/Images/empticon.png",32);
			setWindowIcon(QIcon(px));
		}
	} else {
		// 没变成0，需要展示数字提示,由于数字提示优先级高，所以判断出数字变化了，才进行新图的绘制
		if (currentCount!= count)
		{
			QPixmap px = makeUnreadNoticeIcon(emptyIconPath,count>99?"99+":QString("%1").arg(count),32);
			 setWindowIcon(QIcon(px));
		}
		else{
			// 保持原样
		}
	}

	currentCount = count;
	shasNoCountUnreadMsg = hasNoCountUnreadMsg;

}


void MainDialog::onHideMainWidge()
{
	MainDialog::onMin(true);
}

void MainDialog::onShowMainWidge()
{
	MainDialog::showNormal();
}

void MainDialog::resizeMainwidget(bool bExtendModeShow)
{
	QRect rect = this->geometry();
    if (this->bExtendModeShow!=bExtendModeShow)
    {
         this->bExtendModeShow = bExtendModeShow;
         this->resize(bExtendModeShow? (rect.width() + sExtendWidth):(rect.width()-sExtendWidth) ,
             rect.height());
    }
}

void MainDialog::intThemeButton()
{
   
    QMenu* pTheme = new QMenu(ui->btnTheme);
  
     connect(pTheme,&QMenu::triggered,[pTheme](QAction *action){
         if (NULL!=action)
         {
             QString text = action->text().toLower();
             
             if (text.compare(Biz::Session::getSettingConfig()->themeName(),Qt::CaseInsensitive) != 0)
             {
                 MainApp::changeTheme(text);
                 emit MainApp::UIFrame::getMainDialogController()->sgMainThemeChanged();
                 Biz::Session::getSettingConfig()->themeName(text);
                 Biz::Session::saveSettingConfig();
             }

             for (QAction* action: pTheme->actions())
             {
                 if (NULL!=action)
                 {
                     action->setChecked(Biz::Session::getSettingConfig()->themeName().compare(action->text(),Qt::CaseInsensitive)==0);
                 }
             }
         }
     });

    QAction* pAction = NULL;
    pAction = pTheme->addAction(QStringLiteral("Dark"));
    pAction->setCheckable(true);
    pAction = pTheme->addAction(QStringLiteral("Light"));
    pAction->setCheckable(true);
    

    for (QAction* action: pTheme->actions())
    {
        if (NULL!=action)
        {
            action->setChecked(Biz::Session::getSettingConfig()->themeName().compare(action->text(),Qt::CaseInsensitive)==0);
        }
    }

    ui->btnTheme->setMenu(pTheme);
}

void MainDialog::resizeEvent(QResizeEvent *e)
{
    Biz::Session::getSettingConfig()->MainDlgWidth(this->width());
    Biz::Session::getSettingConfig()->MainDlgHeight(this->height());
    return LocalManWidget::resizeEvent(e);
}

void MainDialog::moveEvent(QMoveEvent *e)
{
    Biz::Session::getSettingConfig()->MainDlgX(this->x());
    Biz::Session::getSettingConfig()->MainDlgY(this->y());
  
    return LocalManWidget::moveEvent(e);
}

