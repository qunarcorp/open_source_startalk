#ifndef DISPATHTHREAD_H
#define DISPATHTHREAD_H

#include <functional>
#include "CoreObject.h"
#include <queue>

class DispathThread : public QThread
{
	
public:
    DispathThread(QObject *parent = 0);
    ~DispathThread();


    void BlockQueueAction(const std::function<void()>& func);
    void QueueAction(const std::function<void()>& func);
protected:
    virtual void run();
    virtual bool event(QEvent* e);

private:
    QMutex m_mutex;
    std::queue<std::function<void()>> m_funs;
};
#endif // DISPATHTHREAD_H
