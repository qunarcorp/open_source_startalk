#include "DispathThread.h"
#include <QWaitCondition>

#define FuncEvent 10000
#include "QXmppLogger.h"
DispathThread::DispathThread(QObject *parent)
    : QThread(parent)
{
    start();
    moveToThread(this);
}

DispathThread::~DispathThread()
{

}

void DispathThread::QueueAction( const std::function<void()>& func )
{
    m_mutex.lock();
    m_funs.push(func);
    m_mutex.unlock();

    QCoreApplication::postEvent( this, new QEvent((QEvent::Type)FuncEvent), Qt::DirectConnection );
}

bool DispathThread::event( QEvent* e )
{
    if(e->type() == (QEvent::Type)FuncEvent)
    {
        m_mutex.lock();
        auto funs = std::move(m_funs);
        m_mutex.unlock();

        while(!funs.empty())
        {
            funs.front()();
            funs.pop();
        }
        return false;
    }
    //qDebug() << "action done";
    return false;
}

void DispathThread::run()
{
    exec();
}

void DispathThread::BlockQueueAction( const std::function<void()>& func )
{
    QWaitCondition q;
    m_mutex.lock();
    m_funs.push([func, &q](){
        func();
        q.wakeOne();
    });
    QCoreApplication::postEvent( this, new QEvent((QEvent::Type)FuncEvent), Qt::DirectConnection );

    q.wait(&m_mutex);
    m_mutex.unlock();
}
