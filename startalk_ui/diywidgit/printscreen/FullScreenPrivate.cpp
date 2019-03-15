#include "FullScreenPrivate.h"
#include <QDebug>
#include <QRect>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
FullScreenPrivate::FullScreenPrivate(void)
{
}


FullScreenPrivate::~FullScreenPrivate(void)
{
}

#ifdef _WINDOWS
    BOOL CALLBACK MyEnumProc(HWND hwnd, LPARAM lParam );
#endif

void FullScreenPrivate::AddNewWindowRect(const QRect& rec)
{    
    m_WndRects.push_back(rec);
}


void FullScreenPrivate::InitWndRectInfos()
{
#ifdef _WINDOWS
     m_WndRects.clear();
     EnumWindows(MyEnumProc,(LPARAM)this);
#endif
}

QRect FullScreenPrivate::GetTheTopRect(const QPoint& point)
{
#ifdef _WINDOWS
    QRect destTopRect = GetDestTopRect();
    if (point.x()==destTopRect.right() || point.x()==destTopRect.left() ||
        point.y()==destTopRect.top() || point.y()==destTopRect.bottom() )
    {
        return destTopRect;
    }

    for each (QRect rect in m_WndRects)
    {
        if (rect.contains(point))
        {
            return rect;
        }

    }
#endif
    return QRect(0,0,0,0);
}

QRect FullScreenPrivate::GetDestTopRect() //返回的是global的坐标系
{
    static QRect destTopRect;

    if (!destTopRect.isNull())
    {
        return destTopRect;
    }
    QDesktopWidget* pDeskTopWidget = QApplication::desktop();
    int screenx = 0;
    int screeny = 0;
    int width = pDeskTopWidget->rect().width();
    int height = pDeskTopWidget->rect().height();
    for (int i =0; i<QApplication::desktop()->screenCount(); i++)
    {
        int nleftPos = pDeskTopWidget->screenGeometry(i).left();
        int nTopPos = pDeskTopWidget->screenGeometry(i).top();
        screenx = nleftPos < screenx ? nleftPos : screenx;
        screeny = nTopPos<screeny? nTopPos:screeny;
    }

    destTopRect = QRect(screenx,screeny,width,height);

    return destTopRect;
}


#ifdef _WINDOWS
BOOL CALLBACK MyEnumProc(HWND hwnd, LPARAM lParam )
{
    FullScreenPrivate* pInstance = (FullScreenPrivate*)lParam;

//     TCHAR buf[128] = {0};
//     GetWindowText(hwnd,(LPWSTR)buf,127);
    RECT wrec;
    GetWindowRect(hwnd,&wrec);


    if (IsWindowVisible(hwnd))
    {
        // 如果是最大化的，需要进步一处理。windows会在最大化的四周加个不可见边框
        if (IsZoomed(hwnd))
        {
            int padingleft = 0-wrec.left;
            int padingtop = 0-wrec.top; 
            int padingright = padingleft; // 暂且这么写
            int padingbottom = padingtop; // 暂且这么写

            wrec.left = wrec.left + padingleft;
            wrec.top = wrec.top + padingtop;
            wrec.right = wrec.right - padingright;
            wrec.bottom = wrec.bottom - padingbottom;
        }
        QRect rect(wrec.left,wrec.top,wrec.right-wrec.left,wrec.bottom-wrec.top);
        
        pInstance->AddNewWindowRect(rect);

    }
    return true;
}
#endif
