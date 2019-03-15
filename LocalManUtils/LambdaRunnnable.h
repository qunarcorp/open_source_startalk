#ifndef RUNNNABLE_H
#define RUNNNABLE_H

#include "CoreObject.h"
#include <functional>

namespace Util
{
    template <class T>
    class RunableResult
    {
    public:
        RunableResult(T result)
        {
            this->result = result;
        };

        inline T getResult()
        {
            return this->result;
        };
        inline void setResult(const T& that){
            this->result = that;
        }
    private:
        T result;
    };


    class LambdaRunnnable :public QObject
    {
		Q_OBJECT
    public:
        LambdaRunnnable(const std::function<void()>& runnable):QObject(NULL),mRunnable(runnable)
        {
            QObject::connect(this,&LambdaRunnnable::excuteBlock,this,&LambdaRunnnable::onBlock,Qt::BlockingQueuedConnection);
            QObject::connect(this,&LambdaRunnnable::postexcute,this,&LambdaRunnnable::onRun,Qt::QueuedConnection);
        }

        ~LambdaRunnnable()
        {
        }
    private:
        std::function<void()> mRunnable;

        protected slots:
            void onBlock(){
                mRunnable();
            }
            void onRun(){
                mRunnable();
                this->deleteLater();
            }
    signals:
            void excuteBlock();
            void postexcute();
    };



}
#endif // RUNNNABLE_H
