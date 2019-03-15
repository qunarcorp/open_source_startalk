#include "SystemIcon.h"
#include <QCursor>
#include "WindowTrayNotifyHelper.h"
#include "UiHelper.h"

SystemIcon::SystemIcon()
    : QSystemTrayIcon()
    , hovered(false)
{
    connect(this, &SystemIcon::activated, this, &SystemIcon::onTrayIconActivation);
    //startTimer(800);
#ifdef QCHAT
	setIcon(QIcon(":/Images/Deal_chat.ico"));
	
#else
#ifdef _DEBUG
    setIcon(QIcon(":/Images/default_header.png"));

#else
    setIcon(QIcon(":/Images/Deal.ico"));
#endif
#endif
    //setIcon(QIcon(":/Images/Deal.ico"));
    m_flashTimer.setDuration(500);
    connect(&m_flashTimer,&QTimeLine::finished,[this](){
        if (QTimeLine::Direction::Forward == m_flashTimer.direction())
        {
            m_flashTimer.setDirection(QTimeLine::Direction::Backward);
#ifdef QCHAT
            setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
#ifdef _DEBUG
            setIcon(QIcon(":/Images/default_header.png"));

#else
            setIcon(QIcon(":/Images/Deal.ico"));
#endif
#endif
            m_flashTimer.start();
        }
        else
        {
            m_flashTimer.setDirection(QTimeLine::Direction::Forward);
            setIcon(QIcon(":/Images/trayiconnotice"));
            m_flashTimer.start();
        }
    });

#ifdef _WINDOWS
    m_hoveCheckTimer.setDuration(100);
    connect(&m_hoveCheckTimer,&QTimeLine::finished,[this](){

        auto iconRect = geometry();

        do 
        {
            if(iconRect.isEmpty()) 
                break;
			QPoint pt = QCursor::pos();
            bool bInsight = iconRect.contains(QCursor::pos()*m_Ratio);
            if (bInsight && !hovered)
            {
                emit sgMouseHover(iconRect);
                hovered = !hovered;
            }

            if (!bInsight && hovered)
            {
                emit sgMouseLeave();
                hovered = !hovered;
            }
        } while (false);

        m_hoveCheckTimer.start();
    });
    
#endif

}

SystemIcon::~SystemIcon()
{

}

void SystemIcon::onTrayIconActivation( QSystemTrayIcon::ActivationReason e )
{
    if(e == QSystemTrayIcon::DoubleClick || e== QSystemTrayIcon::Trigger)
	{
       /* return;*/
    m_flashTimer.stop();
    m_hoveCheckTimer.stop();
    emit sgDoubleClick();
	}
}

static SystemIcon* _instance = NULL;
SystemIcon& SystemIcon::instance()
{
    if(!_instance)
        _instance = new SystemIcon();
    return *_instance;
}

void SystemIcon::release()
{
    delete _instance;
    _instance = NULL;
}

void SystemIcon::timerEvent( QTimerEvent * e )
{
#ifdef _WINDOWS
    auto iconRect = geometry();

    do 
    {
        if(iconRect.isEmpty()) 
            break;
        bool bInsight = iconRect.contains(QCursor::pos()*m_Ratio);
        if (bInsight && !hovered)
        {
            emit sgMouseHover(iconRect);
            hovered = !hovered;
        }

        if (!bInsight && hovered)
        {
            emit sgMouseLeave();
            hovered = !hovered;
        }
        //iconRect.contains(QCursor::pos()) ? sgMouseHover(iconRect) : sgMouseLeave();

    } while (false);
#endif
    QSystemTrayIcon::timerEvent(e);
}

void SystemIcon::setMenuAndTooltip( QMenu* menu, const QString& toolTip )
{
    setContextMenu(menu);
    setToolTip(toolTip);
}

void SystemIcon::clearMenuAndTooltip()
{
    setToolTip(QString::null);
    setContextMenu(0);
}

void SystemIcon::setTrayIconText(const QString& toolTip)
{
	setToolTip(toolTip);
}

void SystemIcon::flashTrayIcon()
{
    m_flashTimer.start();
    m_hoveCheckTimer.start();
}

void SystemIcon::stopTrayIcon()
{
	//setIcon(QIcon(":/Images/Deal.ico"));
#ifdef QCHAT
    setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
#ifdef _DEBUG
    setIcon(QIcon(":/Images/default_header.png"));

#else
    setIcon(QIcon(":/Images/Deal.ico"));
#endif
#endif
    m_flashTimer.stop();
    m_hoveCheckTimer.stop();
}

void SystemIcon::setdevicePixelRatio(int nRatio)
{
	m_Ratio = nRatio;
}

void SystemIcon::onDisconnect()
{
#ifdef QCHAT
	QImage greyImg = QPixmap(":/Images/Deal_chat.ico").toImage();
	MainApp::imageToGray(greyImg);       
	QPixmap mapts = QPixmap::fromImage(greyImg);
	setIcon(QIcon(QPixmap::fromImage(greyImg)));
#else
#ifdef _DEBUG
	setIcon(QIcon(":/Images/default_header.png"));

#else
	setIcon(QIcon(":/Images/Deal.ico"));
#endif
#endif
}

void SystemIcon::onConnected()
{
#ifdef QCHAT
	setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
#ifdef _DEBUG
	setIcon(QIcon(":/Images/default_header.png"));

#else
	setIcon(QIcon(":/Images/Deal.ico"));
#endif
#endif
}

