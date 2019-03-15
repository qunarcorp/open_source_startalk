#pragma once
#include "LambdaRunnnable.h"
namespace Util
{
    namespace Executor
    {
        template <typename FunctionObject>
        void runPost(QThread* workThread, FunctionObject functionObject)
        {
            Q_ASSERT(workThread != QThread::currentThread());

            auto runable = [functionObject](){
                functionObject();
            };
            LambdaRunnnable* plr = new LambdaRunnnable(runable);
            plr->moveToThread(workThread);
            QThread* pth = plr->thread();
            emit plr->postexcute();
        }

        template <typename FunctionObject>
        void runBlock(QThread* workThread, FunctionObject functionObject)
        {
            Q_ASSERT(workThread != QThread::currentThread());

            auto runable = [functionObject](){
                functionObject();
            };
            LambdaRunnnable lr(runable);
            lr.moveToThread(workThread);
            QThread* pth = lr.thread();
            emit lr.excuteBlock();
        }

        template <typename T,typename FunctionObject>
        T runBlock(QThread* workThread, FunctionObject functionObject)
        {
            Q_ASSERT(workThread != QThread::currentThread());
            Q_ASSERT(workThread->isRunning());
            QSharedPointer<RunableResult<T>> spResult(new RunableResult<T>(T()));

            auto runable = [spResult,functionObject](){
                spResult->setResult(functionObject());
            };
            LambdaRunnnable lr(runable);
            lr.moveToThread(workThread);
             QThread* pth = lr.thread();
            emit lr.excuteBlock();
            return spResult->getResult();
        }

        template <typename T,typename FunctionObject, typename Arg1>
        T runBlock(QThread* workThread, FunctionObject functionObject, Arg1 arg1)
        {
            Q_ASSERT(workThread != QThread::currentThread());
            QSharedPointer<RunableResult<T>> spResult(new RunableResult<T>(T()));

            auto runable = [spResult,functionObject,arg1](){
                spResult->setResult(functionObject(arg1));
            };
            LambdaRunnnable lr(runable);
            lr.moveToThread(workThread);
            emit lr.excuteBlock();
            return spResult->getResult();
        }

    }
}