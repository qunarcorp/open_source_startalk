#pragma once
#include <QString>
#include <QMap>
#include <QVariant>

namespace Biz
{
    extern const   QString SDParam_key_eid;
    extern const   QString SDParam_key_edatatype;
    extern const   QString SDParam_key_edata;
    extern const   QString SDParam_key_edataex;
    extern const   QString SDParam_key_ctime;

    extern const   QString SDDataType_Taketime;
    extern const   QString SDDataType_Count;


    class  StaticData
    {
    public:
        static void reportEvent(const QMap<QString,QVariant>& params);
        static void reportTakeTimeEvent(const QVariant& eid,const QVariant& edata ,const QVariant& dataex=QString());
		static void reportTakeCountEvent(const QVariant& eid,const QVariant& edata ,const QVariant& dataex=QString());
    };

    class StaticDataReporter{
        quint64 mTime;
        QVariant eid;
        QVariant dateex;
    public:
        StaticDataReporter(const QVariant& eid);
        StaticDataReporter(const QVariant& eid ,const QVariant& dataex);
        ~StaticDataReporter();
    };

    class LogReporter{
        QString key;
        quint64 time;
    public:
        LogReporter(const QString& key);
        LogReporter(const QString& key,quint64 t);
        ~LogReporter();
    };

    class LogStaticDataReporter{
    public:
        LogStaticDataReporter(const QVariant& eid);
        ~LogStaticDataReporter();
    };

}
