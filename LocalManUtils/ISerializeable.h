#pragma once
#include <QObject>
class ISerializeable : public QObject
{
	Q_OBJECT
public:
    ISerializeable(QObject *parent):QObject(parent){};
    ~ISerializeable(){};
    virtual QString seralizeToString() = 0;
    virtual void unserializeFromString(const QString&) = 0;
};

