#pragma once
#include <QObject>
#include <QWidget>
#ifdef _WINDOWS
    #include <wtypes.h>
#endif
#include <QRect>
#include <QPoint>
class FullScreenPrivate : public QObject
{
    Q_OBJECT
public:
    FullScreenPrivate(void);
    ~FullScreenPrivate(void);
    void InitWndRectInfos();
    QRect GetTheTopRect(const QPoint& point);
    QRect GetDestTopRect();

private:
#ifdef _WINDOWS
    friend BOOL CALLBACK MyEnumProc(HWND hwnd, LPARAM lParam );
#endif
private:
    void AddNewWindowRect(const QRect& rec);
private:
    std::vector<QRect> m_WndRects;
    
};

