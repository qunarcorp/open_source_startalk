#ifndef SINGLEPROGRESOBJECT_H
#define SINGLEPROGRESOBJECT_H

#include <QObject>
#ifdef _LINUX
#include <QDBusConnection>
#endif // _LINUX


class SingleProgresObject : public QObject
{
    Q_OBJECT
public:
    explicit SingleProgresObject(QObject *parent = 0);
    ~SingleProgresObject();

#ifdef _LINUX
    void setupQBus(QDBusConnection connection);
#endif // _LINUX
    

signals:

public slots:
    void onShowWindows();
};

#endif // SINGLEPROGRESOBJECT_H
