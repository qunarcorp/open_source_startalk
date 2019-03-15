#include "NotifyWindow.h"
#include "ui_NotifyWindow.h"
#include "animation.h"
#include <QDesktopWidget>
#include <QXmppUtils.h>
#include <QGraphicsDropShadowEffect>
#include "DisplayTextBrowser.h"
#include "SystemIcon.h"
#include <QMouseEvent>
#include "sysmessagedialog.h"
#include "XmppMessage.h"
#include "Session.h"
#include "Account.h"
#include "SettingData.h"
#include "messagebubble/MessageParser.h"
#include "portraithelper.h"
#include "diywidgit/customviews/qframelayout.h"
#include "UserVcardManager.h"
#include "UtilHelper.h"
#include "SystemConfigData.h"


NotifyWindow::NotifyWindow(QWidget *parent)
    : LocalManWidget(parent)
{
    auto remove = Qt::WindowTitleHint;
    auto add = Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint|Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));



    ui = new Ui::NotifyWindow;
    ui->setupUi(this);

#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	ui->Title_bar->setMinable(false);
	ui->Title_bar->setMaxable(false);
	ui->Title_bar->setLeftTitle("");
    connect(ui->Title_bar,&TitlebarWidget::sgCloseOnClicked,this,&NotifyWindow::onClosed);

    m_animIn = new Animation(this, "pos");
    m_animIn->setEasingCurve(QEasingCurve::OutQuad);
    m_animIn->setDuration(300);
    m_animIn->setLoopCount(1);



    hidePosition();
    connect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this, &NotifyWindow::onTrayIconDoubleClick);
	QPixmap pixmap = Biz::PortraitHelper::getUserPortraitPath(Util::UserNoticeMsg);
	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->content_image->size()));
	ui->content_image->setPixmap(pixmap);

	//让关闭按钮悬浮到层上面
	QFrameLayout* layout = new QFrameLayout(ui->shadowinnerbg);
	layout->appendWidget(ui->contentpanel,AlinementPolicy::ALINE_FILL);
	layout->setContentsMargins(1, 1, 1, 1);//为了出现边框
	layout->appendWidget(ui->Title_bar,AlinementPolicy::ALINE_TOP|AlinementPolicy::ALINE_RIGHT);

	
    holderLine.setDuration(10*1000);
	connect(&holderLine,&QTimeLine::finished,this,&NotifyWindow::onChangeNotifyItem);
     ui->contentpanel->installEventFilter(this);
	 ui->Title_bar->setCursor(Qt::PointingHandCursor);
}

NotifyWindow::~NotifyWindow()
{
    delete ui;
}

void NotifyWindow::hidePosition()
{
    QDesktopWidget desktopWidget;
    QRect desktop = desktopWidget.availableGeometry();
    int posY = Biz::Session::getSettingConfig()->NotifyWindowPosY();
    int lastBottom = posY +this->height();

    int screenheight = desktop.height();

    // 窗口位置是否在屏幕内
    if (lastBottom>= screenheight|| posY >= screenheight || posY <0 || lastBottom <0)
    {
        Biz::Session::getSettingConfig()->NotifyWindowPosY(200);
        posY = Biz::Session::getSettingConfig()->NotifyWindowPosY();
    }

    this->move(desktop.width() - this->width() - 20, posY);
}

void NotifyWindow::showEvent( QShowEvent * e )
{
    showAnimation();
    QWidget::showEvent(e);
}

void NotifyWindow::hideEvent( QHideEvent * e )
{
    QWidget::hideEvent(e);
#ifdef QCHAT
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal.ico"));
#endif
}

void NotifyWindow::showAnimation()
{
    m_animIn->setStartValue(QPointF(x() + 200, y()));
    m_animIn->setEndValue(QPointF(x(), y()));
    m_animIn->start();
}


void NotifyWindow::showNotifyMessage(const QString& jid, const QString& dispalyName, const QSharedPointer<Biz::XmppMessage>& msg )
{
    instance()._showNotifyMessage(jid,dispalyName,msg);
}

void NotifyWindow::_showNotifyMessage(const QString& jid, const QString& dispalyName, const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (!jid.isEmpty())
	{
		if (UtilHelper::isVirtualAccountId(jid, Biz::Session::getSystemConfig()->getXmppDomain()))
		{
			QString strRealName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(UtilHelper::getRealIdfromID(jid));
			QString strVirtualname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(UtilHelper::getvirtualfromID(jid));
#ifdef QCHAT
			QString strdisplay = QStringLiteral("%1(咨询%2店铺中产品)").arg(strRealName).arg(strVirtualname);
#else
			QString strdisplay = QString("%1-%2").arg(strVirtualname, strRealName);
#endif // QCHAT

			
			msgNoticeItem.title = strdisplay;
		}
		else
		{
			msgNoticeItem.title = dispalyName;
		}
		msgNoticeItem.spmessage = msg;
		msgNoticeItem.ConvsationJId = msg->ConversationID();


		showNotifyItems();
		
	}
}
void NotifyWindow::showNotifyItems()
{
    QSharedPointer<Biz::XmppMessage> msg = msgNoticeItem.spmessage;
    QString title = msgNoticeItem.title;

    QFontMetrics idfont(ui->content_id->font());
	title = idfont.elidedText(title, Qt::ElideRight, ui->content_id->width());
	ui->content_id->setText(title);

    QString shortBody;
    if (!MessageParser::getInstance()->getShotTranslatedMessage(msg,shortBody))
    {
    }
	//顾虑提示符号
	shortBody.replace("<br/>"," ");
	shortBody.replace("<br />"," ");
	shortBody.replace("&nbsp;"," ");

    QString sender = "";
    if (msg->MsgSourceType() == Biz::GroupMessage)
    {
        sender = Biz::MessageUtil::makeSureUserId(Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserJid(msg->SenderJid())));
        if (sender.isEmpty())
            sender = msg->Resource();
        sender += ": ";
		
		QPixmap pixmap = Biz::PortraitHelper::getUserPortraitPath(Util::GroupNoticeMsg);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->content_image->size()));
		ui->content_image->setPixmap(pixmap);
    }
	else
	{
		QPixmap pixmap = Biz::PortraitHelper::getUserPortraitPath(Util::UserNoticeMsg);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->content_image->size()));
		ui->content_image->setPixmap(pixmap);
	}

	QStringList content = calcuteContent(sender + shortBody);
	if (content.size() == 1)
	{
		ui->content_msg_1->setText(content.at(0)) ;
		ui->content_msg_2->setVisible(false);
	}
	else
	{
		ui->content_msg_2->setVisible(true);
		ui->content_msg_1->setText(content.at(0)) ;
		ui->content_msg_2->setText(content.at(1)) ;
	}
    

	
	holderLine.start();
	

 
    showPosition();
}
void NotifyWindow::onClosed( bool )
{
    holderLine.stop();
    SystemIcon::instance().stopTrayIcon();
    LocalManWidget::onClose(false);
}

void NotifyWindow::onTextClicked()
{
    this->onClosed(false);
}

NotifyWindow* _instance;
NotifyWindow& NotifyWindow::instance()
{
    if(!_instance){
        _instance = new NotifyWindow();
    }
    return *_instance;
}

void NotifyWindow::release()
{
    delete _instance;
    _instance = NULL;
}
void NotifyWindow::onTrayIconDoubleClick()
{
    //SystemIcon::instance().setIcon(QIcon(":/Images/Deal.ico"));
#ifdef QCHAT
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal.ico"));
#endif
//    emit sgOpenConversation(mUserID);
}
void NotifyWindow::onChangeNotifyItem()
{
	
	hide();
	
}

void NotifyWindow::enterEvent(QEvent *)
{
    holderLine.setPaused(true);
}

void NotifyWindow::leaveEvent(QEvent *)
{
    holderLine.setPaused(false);
}

bool NotifyWindow::eventFilter(QObject *obj, QEvent * e)
{
    if (obj == ui->contentpanel)
    {
        if (QEvent::MouseButtonPress == e->type())
        {
            
            emit sgOpenConversation(msgNoticeItem.ConvsationJId);
             
            onClosed(false);
        }
       
    }
    return LocalManWidget::eventFilter(obj,e);
}

void NotifyWindow::windowMove(const QPoint& pos)
{
    Biz::Session::getSettingConfig()->NotifyWindowPosY(pos.y());
}

QStringList NotifyWindow::calcuteContent( const QString& content )
{
	QString strContent = content;
	
	QFontMetrics msgfont(ui->content_image->font());
	int nlabelwidth = ui->content_msg_1->width();

	int contentwidth = msgfont.width(strContent.remove('\n'));
	if (contentwidth < nlabelwidth)
	{
		return QStringList(strContent);
	}

	/////////////////////////////////////////////
	QStringList newcontent;
	int nWidthSum = 0;
	int nI = 0;
	for (; nI < strContent.size(); nI++)
	{
		if (nWidthSum < nlabelwidth)
		{
			nWidthSum += msgfont.width(strContent.at(nI));
		}
		else
		{
			break;
		}
	}
	QString strbegin = strContent.left(nI - 1);
	newcontent.push_front(strbegin.remove('\n'));

	QString strend = strContent.right(strContent.size() - nI + 1);

	if (msgfont.width(strend) > nlabelwidth)
	{
		strend = msgfont.elidedText(strend, Qt::ElideRight, nlabelwidth);	
	}
	newcontent.push_back(strend.remove('\n'));
	return newcontent;
	//////////////////////////////////////////////


	//一行可以放多少个字符
	/*int ncountofline = nlabelwidth / (contentwidth/(strContent.size())); 

	QStringList newcontent;
	QString strbegin = strContent.left(ncountofline);
	
	//有可能里面有些空格，等特殊的字符，导致计算每行所容纳的字符的误差
	getlineoflaycount(msgfont, strbegin, ncountofline, nlabelwidth);
	strbegin = strContent.left(ncountofline);
	
	newcontent.push_front(strbegin.remove('\n'));

	QString strend = strContent.right(strContent.size() - ncountofline);

	if (msgfont.width(strend) > nlabelwidth)
	{
		strend = msgfont.elidedText(strend, Qt::ElideRight, nlabelwidth);	
	}
	newcontent.push_back(strend.remove('\n'));

	return newcontent;*/
}

void NotifyWindow::showPosition()
{
	QDesktopWidget desktopWidget;
	QRect desktop = desktopWidget.availableGeometry();
	int posY = Biz::Session::getSettingConfig()->NotifyWindowPosY();
	int lastBottom = posY +this->height();

	int screenheight = desktop.height();

	// 窗口位置是否在屏幕内
	if (lastBottom>= screenheight|| posY >= screenheight || posY <0 || lastBottom <0)
	{
		Biz::Session::getSettingConfig()->NotifyWindowPosY(200);
		posY = Biz::Session::getSettingConfig()->NotifyWindowPosY();
	}

	int nposx = desktop.width() - this->width() - 20;
	this->move(desktop.width() - this->width() - 20, posY);
	show();
}

void NotifyWindow::getlineoflaycount(QFontMetrics msgfont, const QString& strlinecontent,int& ncontentlenght, int nlineOfContaincount )
{
	QString strcontent = strlinecontent;

	if (msgfont.width(strlinecontent) > nlineOfContaincount)
	{
		ncontentlenght = ncontentlenght - 2;
		QString strcontent = strlinecontent.left(ncontentlenght);
		getlineoflaycount(msgfont, strcontent, ncontentlenght, nlineOfContaincount);
	}
	else
		return;
	
}



