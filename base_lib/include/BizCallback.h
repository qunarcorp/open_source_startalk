#ifndef BIZCALLBACK_H
#define BIZCALLBACK_H

#include <QObject>
#include "CoreObject.h"
#include "AsyncHandler.h"

namespace Biz
{
    class BizCallback : public QObject
    {
    public:
        BizCallback(bool isSync)
            :mIsCancel(false),workThread(NULL){
            workThread = isSync ? NULL : new AsyncHandler();
            failure = []{};
        }
        ~BizCallback(){
            delete workThread;
            workThread = NULL;
        }
    public:
        void doFailure() { executeRunnable(failure); }
        void cancel() 
		{ 
			m_mutex.lock();
			mIsCancel = true; 
			m_mutex.unlock();
		}
        bool isCancel() { return mIsCancel; }

        void setOnFailure(const std::function<void()>& runnable) {
            failure = [runnable, this]{
                runnable();
                delete this;
            };
        }
    protected:
        void executeRunnable(const std::function<void()>& runnnable){
            if(isCancel()) {
                delete this;
                return;
            }
			auto runableInWorkthread = [this,runnnable]{
				if (isCancel())
				{
					delete this;
					return;
				}
				runnnable();
			};

			workThread == NULL ? runnnable() : workThread->QueueAction(runableInWorkthread);
        }
    private:
        std::function<void()> failure;
        bool mIsCancel;
        AsyncHandler* workThread;
        int reqCount;
		QMutex m_mutex;
    }; 

    class GeneralCallback : public BizCallback
    {
    public:
        GeneralCallback()
            :BizCallback(false){

        }
        ~GeneralCallback(){

        }
        void setOnCompleted(const std::function<void()>& runnable){
            completed = [this, runnable]{
                runnable();
                delete this;
            };
        }
    public:
        void doCompleted(){
            executeRunnable(completed);
        }

    private:
        std::function<void()> completed;
    };

    template<class T>
    class UnitCallback : public BizCallback
    {
    public:
        UnitCallback():
            BizCallback(false){
        }
        ~UnitCallback(){

        }
    public:
        void doCompleted(T t){
            completedObject = t;
            executeRunnable([this]{
                completedLambda(completedObject);
            });
        }
    public:
        void setOnCompleted(const std::function<void(T)>& runnable){
            completedLambda = [this, runnable](T t){
                runnable(t);
                delete this;
            };
        }
    private:
        std::function<void(T)> completedLambda;
        T completedObject;
    };

    //class SyncGeneralCallback : public BizCallback{
    //public:
    //    SyncGeneralCallback():
    //        BizCallback(true){

    //    }
    //    ~SyncGeneralCallback(){}

    //    void doCompleted(){
    //        executeRunnable(completed);
    //    }

    //    void setOnCompleted(const std::function<void()>& runnable){
    //        completed = [this, runnable]{
    //            runnable();
    //            delete this;
    //        };
    //    }
    //private:
    //    std::function<void()> completed;
    //};



    template<typename  T,typename  programType>
    class ProgressedUnitCallback : public BizCallback
    {
    public:
        ProgressedUnitCallback() 
            : BizCallback(false)
        {}

        ~ProgressedUnitCallback(){}
    public:
        void doProgramed(programType done,programType total){
            executeRunnable([this,done,total]{
                if (NULL!=programedLambda)
                {
                    programedLambda(done,total);
                }
            });
        }
        void doCompleted(T t){
            completedObject = t;
            executeRunnable([this]{
                completedLambda(completedObject);
            });
        }
    public:
        void setOnProgramed(const std::function<void(programType,programType)>& runable)
        {
            programedLambda = [this,runable](qint64 done,qint64 total){
                runable(done,total);
            };
        }
        void setOnCompleted(const std::function<void(T)>& runnable){
            completedLambda = [this, runnable](T t){
                runnable(t);
                delete this;
            };
        }
       
    private:
        std::function<void(programType,programType)> programedLambda;
        std::function<void(T)> completedLambda;
        T completedObject;
    };
}

#endif // BIZCALLBACK_H
