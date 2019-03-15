#ifndef ASYNCHANDLER_H
#define ASYNCHANDLER_H

#include "CoreObject.h"
#include <functional>
#include <queue>

namespace Util
{
    class AsyncHandler : public QObject
    {
        Q_OBJECT;
    public:
        AsyncHandler(QObject *parent=0);
        ~AsyncHandler();

        void QueueAction(const std::function<void()>& func);
    signals:
        void sgMethod();
    private slots:
        void onMethod();
    private:
        QMutex m_mutex;
        std::queue<std::function<void()>> m_funs;

    };
}


#endif // ASYNCHANDLER_H
