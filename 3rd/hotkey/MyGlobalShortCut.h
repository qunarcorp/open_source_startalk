#pragma once
#include <QApplication>
#ifdef _WINDOWS
    #include <windows.h>
#endif
#include "MyWinEventFilter.h"
#include <QKeySequence>
#include <QHash>

class MyGlobalShortCut : public QObject
{
    Q_OBJECT
public:


    MyGlobalShortCut(QString key,QObject* app);
    ~MyGlobalShortCut();
    void activateShortcut();
    bool registerHotKey();
    bool unregisterHotKey();
    QHash<QPair<quint32, quint32>, MyGlobalShortCut*> shortcuts;
private:
    QApplication *m_app;
    MyWinEventFilter *m_filter;
    QKeySequence m_key;
    Qt::Key key;
    Qt::KeyboardModifiers mods;
    static quint32 nativeKeycode(Qt::Key keycode);
    static quint32 nativeModifiers(Qt::KeyboardModifiers modifiers);
signals:
    void activated();

};
