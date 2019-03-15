#ifndef BIZCALLBACKRECEIVER_H
#define BIZCALLBACKRECEIVER_H

#include "CoreObject.h"
#include "BizCallback.h"
#include <functional>

namespace Biz
{
    class CallbackReceiver : public QObject
    {
		Q_OBJECT
    public:
        CallbackReceiver(QObject* parent);
        ~CallbackReceiver();

    public:
        template<class T>
        Biz::UnitCallback<T>* createCallback(const std::function<void(T)>& completed, const std::function<void()>& failure){
            auto callback = new Biz::UnitCallback<T>;

            callback->setOnCompleted([completed, callback, this](T t){
				
				if (callback)
				{
					mCallbackList.removeOne(callback);
				}
				
				
                
                completed(t);
            });

            callback->setOnFailure([failure, callback, this](){
				if (callback)
				{
					mCallbackList.removeOne(callback);
				}
				
				
                failure();
            });

            registerCallback(callback);
            return callback;
        }

        template<class T,class progType>
        Biz::ProgressedUnitCallback<T,progType>* createProgressCallback(
            const std::function<void(T)>& completed, 
            const std::function<void(progType,progType)>& progress,
            const std::function<void()>& failure){
            auto callback = new Biz::ProgressedUnitCallback<T,progType>;

            callback->setOnCompleted([completed, callback, this](T t){
                mCallbackList.removeOne(callback);
                completed(t);
            });

            callback->setOnProgramed([progress,callback,this](progType done,progType total){
                progress(done,total);
            });

            callback->setOnFailure([failure, callback, this](){
                mCallbackList.removeOne(callback);
                failure();
            });

            registerCallback(callback);
            return callback;
        }


        Biz::GeneralCallback* createCallback(const std::function<void()>& completed, const std::function<void()>& failure){
            auto callback = new Biz::GeneralCallback;

            callback->setOnCompleted([completed, callback, this](){
                mCallbackList.removeOne(callback);
                completed();
            });

            callback->setOnFailure([failure, callback, this](){
                mCallbackList.removeOne(callback);
                failure();
            });

            registerCallback(callback);
            return callback;
        }


    private:
        void registerCallback(Biz::BizCallback* callback);

        QList<Biz::BizCallback*> mCallbackList;
    }; 
}

#endif // BIZCALLBACKRECEIVER_H
