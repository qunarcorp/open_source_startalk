#include "localmanwidget.h"
#include <QMouseEvent>
#include <QSizeGrip>
#include <QPainterPath>
#include <QPainter>
#include "Session.h"
#include "Account.h"
#include "CallbackReceiver.h"

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

LocalManWidget::LocalManWidget(QWidget *parent)
    : QWidget(parent)
    , m_tracked(false)
    , m_moveable(true) 
    , resizer(NULL)
    , mReceiver(new Biz::CallbackReceiver(this))
{
    installEventFilter(this);
}

LocalManWidget::~LocalManWidget()
{

}

void LocalManWidget::mousePressEvent( QMouseEvent * e )
{
    if (m_moveable && e->button() == Qt::LeftButton)
    {
        m_tracked = true;
        m_gDragPos = QCursor::pos();
        m_rawPos = frameGeometry().topLeft();
    }
    QWidget::mousePressEvent(e);
}

void LocalManWidget::mouseReleaseEvent( QMouseEvent * e )
{
    m_tracked = false;
        move(x(), y());

    QWidget::mouseReleaseEvent(e);
}

void LocalManWidget::mouseMoveEvent( QMouseEvent * e )
{
    if(m_moveable && m_tracked)
    {
        if(isMaximized())
        {
            showNormal();
            return QWidget::mouseMoveEvent(e);
        }
        auto gEndPos = QCursor::pos();
        auto newpos = gEndPos - m_gDragPos + m_rawPos;
        QPoint curPos = this->pos ();
        if (curPos == newpos)
        {
            return QWidget::mouseMoveEvent(e);
        }
        move(newpos);
        windowMove(newpos);
    }
    QWidget::mouseMoveEvent(e);
}

bool LocalManWidget::event(QEvent* e)
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
            // 小窗的拖拽点x:全屏的拖拽点x = 小窗宽度 ： 全屏宽度
            // 小窗拖拽点x = 全屏拖拽点x*小窗宽度/全屏宽度
            // 小窗左上x的 = 全局拖拽点x-小窗拖拽点x
            // y同
            int newX = m_gDragPos.x() - m_gDragPos.x()*curR.width()/m_normalSize.width();
            int newY = m_gDragPos.y() - m_gDragPos.y()*curR.height()/m_normalSize.height();
            m_rawPos = QPoint(newX,newY);
        }
    }

    return QWidget::event(e);
}

void LocalManWidget::onMin( bool )
{
    this->showMinimized();
}

void LocalManWidget::onMax( bool )
{
    if(isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}

void LocalManWidget::onClose( bool )
{
    this->close();
#ifdef QCHAT
	emit Biz::Session::currentAccount().sgChatWebInforClose(true);
#endif
}
void LocalManWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

bool LocalManWidget::eventFilter(QObject *o, QEvent *e)
{
    if( o == this )
    {
        if(QEvent::WindowActivate == e->type())
        {
            stopFlash();
        }
    }
    return QWidget::eventFilter(o,e);
}


void LocalManWidget::autoFlash()
{
#ifdef _WINDOWS
    FLASHWINFO fInfo={0};
    fInfo.cbSize = sizeof(FLASHWINFO);
    fInfo.hwnd = (HWND) this->winId();
    fInfo.dwFlags = FLASHW_ALL | FLASHW_TIMER;
    FlashWindowEx(&fInfo);
#else
#ifndef _MAC 
    Display *display  = QX11Info::display();
    int window = this->winId();

    XWMHints wm_hints;
    wm_hints.flags = StateHint | InputHint;
    wm_hints.input = True;
    wm_hints.initial_state =  NormalState;
    wm_hints.flags |= XUrgencyHint;

    XSetWMHints(display, window, &wm_hints);
#endif
    
#endif
}

void LocalManWidget::stopFlash()
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

void LocalManWidget::setSizeGripEnabled(bool enabled)
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

void LocalManWidget::resizeEvent(QResizeEvent * e)
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


void LocalManWidget::paintEvent(QPaintEvent *)
{
//     QPainterPath path;
//     path.setFillRule(Qt::WindingFill);
//     path.addRect(10, 10, this->width()-20, this->height()-20);
// 
//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing, true);
//     painter.fillPath(path, QBrush(Qt::white));
// 
//     QColor color(0, 0, 0, 50);
//     for(int i=0; i<10; i++)
//     {
//         QPainterPath path;
//         path.setFillRule(Qt::WindingFill);
//         path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
//         color.setAlpha(150 - qSqrt(i)*50);
//         painter.setPen(color);
//         painter.drawPath(path);
//     }
}

void LocalManWidget::windowMove(const QPoint& pos)
{

}
