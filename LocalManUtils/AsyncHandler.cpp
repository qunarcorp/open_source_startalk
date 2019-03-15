#include "AsyncHandler.h"
namespace Util
{
    AsyncHandler::AsyncHandler(QObject *parent)
        : QObject(parent)
    {
        connect(this, &AsyncHandler::sgMethod, this, &AsyncHandler::onMethod);
    }

    AsyncHandler::~AsyncHandler()
    {

    }

    void AsyncHandler::QueueAction( const std::function<void()>& func )
    {
        m_mutex.lock();
        m_funs.push(func);
        m_mutex.unlock();

        emit sgMethod();
    }

    void AsyncHandler::onMethod()
    {
        m_mutex.lock();
        auto funs = std::move(m_funs);
        m_mutex.unlock();

        while(!funs.empty())
        {
            funs.front()();
            funs.pop();
        }
    }
}
