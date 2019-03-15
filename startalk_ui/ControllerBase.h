#ifndef CONTROLLERBASE_H
#define CONTROLLERBASE_H

#include <QObject>
#include "CallbackReceiver.h"
#include "BizCallback.h"

namespace MainApp
{
	class ControllerBase : public Biz::CallbackReceiver 
	{
	    Q_OBJECT
	
	public:
	    ControllerBase(QObject *parent);
	    ~ControllerBase();
        /*
         *	生命周期为 构造 --> initController --> unInitController -->析构
         */
        virtual void initController()      = 0;

        /*
         *	生命周期为 构造 --> initController --> unInitController -->析构
         */
        virtual void unInitController()    = 0;
	
	private:
	    
	};
}

#endif // CONTROLLERBASE_H
