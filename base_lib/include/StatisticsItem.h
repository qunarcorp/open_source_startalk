#ifndef STATISTICSITEM_H
#define STATISTICSITEM_H

#include "CoreObject.h"

namespace Biz
{
    extern const QString StatisticsKey_LoginSucceed;
    extern const QString StatisticsKey_LoginFailure;
    extern const QString StatisticsKey_MessageSent;
    extern const QString StatisticsKey_OpenDialog;

    class StatisticsItem : public QObject
    {
        Q_OBJECT

    public:
        StatisticsItem(const QString& key);
        ~StatisticsItem();

        QString Key() const { return mKey; }
        int Count() const { return mCount; }
        void Count(int val) { mCount = val; }
        void IncCount();
    private:
        QString mKey;
        int mCount;
    }; 
}

#endif // STATISTICSITEM_H
