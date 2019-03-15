#include "LocalManDialog.h"
#include <QMouseEvent>
#include <QCoreApplication>
#ifdef _WINDOWS
#include <windows.h>
#else
#ifdef _MAC
#else
#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif
#endif

LocalManDialog::LocalManDialog(QWidget *parent)
    : QDialog(parent), m_tracked(false),m_moveable(true),resizer(NULL)
{
    installEventFilter(this);
}

LocalManDialog::~LocalManDialog()
{

}


void LocalManDialog::mouseDoubleClickEvent( QMouseEvent * e )
{
    QDialog::mouseDoubleClickEvent(e);
}


void LocalManDialog::mousePressEvent( QMouseEvent * e )
{
    if (m_moveable && e->button() == Qt::LeftButton)
    {
        m_tracked = true;
        m_gDragPos = QCursor::pos();
        m_rawPos = frameGeometry().topLeft();
    }
    QDialog::mousePressEvent(e);
}

void LocalManDialog::mouseReleaseEvent( QMouseEvent * e )
{
    m_tracked = false;
    move( x(), y());

    QDialog::mouseReleaseEvent(e);
}

void LocalManDialog::mouseMoveEvent( QMouseEvent * e )
{
    if(m_moveable && m_tracked)
    {
        if(isMaximized())
        {
            showNormal();
            return QWidget::mouseMoveEvent(e);
        }
        auto gEndPos = QCursor::pos();

        auto pos = gEndPos - m_gDragPos + m_rawPos;
        QPoint curPos = this->pos ();
        if (curPos == pos)
            return QWidget::mouseMoveEvent (e);

         move (pos);
    }
    QDialog::mouseMoveEvent(e);
}

bool LocalManDialog::event(QEvent* e)
{
    if(e->type() == QEvent::WindowStateChange)
    {
        auto changeEvent = (QWindowStateChangeEvent*)e;
        if (windowState() == Qt::MaximumSize)
        {
            m_normalSize.setWidth( frameGeometry().width() );
            m_normalSize.setHeight( frameGeometry().height() );
        }

        if (changeEvent->oldState() == Qt::WindowMaximized)
        {
            QSize curR = frameGeometry().size();
            int newX = m_gDragPos.x() - m_gDragPos.x()*m_normalSize.width()/curR.width();
            int newY = m_gDragPos.y() - m_gDragPos.y()*m_normalSize.height()/curR.height();
            m_rawPos = QPoint(newX,newY);
        }
    }

    return QDialog::event(e);
}

void LocalManDialog::onMin( bool )
{
    this->hide();
}

void LocalManDialog::onMax( bool )
{
    if(isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}

void LocalManDialog::onClose( bool )
{
    this->showMinimized();
    QCoreApplication::instance()->exit();
}
void LocalManDialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
       break;
    default:
        QDialog::keyPressEvent(event);
    }
}

bool LocalManDialog::eventFilter(QObject *o, QEvent *e)
{
    if( o == this )  
    {  
        if(QEvent::WindowActivate == e->type())  
        {  
            stopFlash();
        }  
    }  
    return QDialog::eventFilter(o,e);
}


void LocalManDialog::autoFlash()
{
#ifdef _WINDOWS
    FLASHWINFO fInfo={0};
    fInfo.cbSize = sizeof(FLASHWINFO);
    fInfo.hwnd = (HWND) this->winId();
    fInfo.dwFlags = FLASHW_ALL | FLASHW_TIMER;
    FlashWindowEx(&fInfo);
#else
//#ifndef
    Display *display  = QX11Info::display();
    int window = this->winId();

    XWMHints wm_hints;
    wm_hints.flags = StateHint | InputHint;
    wm_hints.input = True;
    wm_hints.initial_state =  NormalState;
    wm_hints.flags |= XUrgencyHint;

    XSetWMHints(display, window, &wm_hints);
#endif
//#endif
}

void LocalManDialog::stopFlash()
{
#ifdef _WINDOWS
    FLASHWINFO fInfo={0};
    fInfo.cbSize = sizeof(FLASHWINFO);
    fInfo.hwnd = (HWND) this->winId();
    fInfo.dwFlags = FLASHW_STOP;
    FlashWindowEx(&fInfo);
#else
//    Display *display  = QX11Info::display();

//    XWMHints* wm_hints = XGetWMHints(display, this->winId());
//    if (wm_hints->flags & XUrgencyHint)
//            wm_hints->flags &= ~XUrgencyHint;
//    XSetWMHints(display, this->winId(), wm_hints);
//    XFree(wm_hints);
#endif // _WINDOWS
}

void LocalManDialog::resizeEvent(QResizeEvent * e)
{
	if (NULL == resizer)
	{
		return;
	}
	QPoint pt(e->size().width(), e->size().height());
	if (isRightToLeft())
		resizer->move(pt - resizer->rect().bottomLeft());
	else
		resizer->move(pt- resizer->rect().bottomRight());
	QWidget::resizeEvent(e);
}
void LocalManDialog::setSizeGripEnabled(bool enabled)
{
	if (enabled)
	{
		resizer = new QSizeGrip(this);
		// adjustSize() processes all events, which is suboptimal
		resizer->resize(resizer->sizeHint());
		if (isRightToLeft())
			resizer->move(rect().bottomLeft() - resizer->rect().bottomLeft());
		else
			resizer->move(rect().bottomRight()- resizer->rect().bottomRight());
		resizer->raise();
		resizer->show();
	} else {
		delete resizer;
		resizer = 0;
	}
}
