#ifndef MANAGERBASE_H
#define MANAGERBASE_H

#include <QObject>
#include "CallbackReceiver.h"
#include "BizCallback.h"
#include "XmppIqReceiver.h"
namespace Biz
{
    class ManagerBase : public CallbackReceiver, public IXmppIqReceiver
    {
        Q_OBJECT
    public:
        ManagerBase(QObject *parent);
        ~ManagerBase();
        /*
         *	生命周期为 构造 --> initmaganer --> uninitmanager -->析构
         *  initManager 合作manager的信号在这里连接
         */
        virtual void initManager()      = 0;

        /*
         *	生命周期为 构造 --> initmaganer --> uninitmanager -->析构
         *  unInitManager 合作manager的信号在这里断开连接
         */
        virtual void unInitManager()    = 0;

		virtual bool insertIqRequst(const QString& xmppid, Biz::UnitCallback<QDomElement>* cb);

		virtual void fireIqResponce(const QDomElement& xmppiq);
	private:
		XmppIqReceiver* pXmppIqReceiver;
		public slots:
			void onXmppIqResponse(const QDomElement& xmppiq);
	};
}

#endif // MANAGERBASE_H
