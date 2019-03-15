#ifndef XMPPIQRECEIVER_H
#define XMPPIQRECEIVER_H

#include <QObject>
#include <QTimeLine>
#include <qdom.h>
#include "CoreObject.h"
#include "BizCallback.h"
namespace Biz
{
	class TimeroutBizCallback;
	class IXmppIqReceiver
	{
	public:
		virtual bool insertIqRequst(const QString& xmppid, Biz::UnitCallback<QDomElement>* cb) = 0;
		virtual void fireIqResponce(const QDomElement& xmppiq) = 0;
	};
	class XmppIqReceiver : public QObject ,public IXmppIqReceiver
	{
		Q_OBJECT;
	public:
		XmppIqReceiver(QObject *parent);
		~XmppIqReceiver();
	public: 
		virtual bool insertIqRequst(const QString& xmppid, Biz::UnitCallback<QDomElement>* cb);
		virtual void fireIqResponce(const QDomElement& xmppiq);
	private:
		QMap<QString,QSharedPointer<Biz::TimeroutBizCallback>> mCallbackMap;
        QSharedPointer<QTimeLine> spTimerPerSencend;
	private slots:
		void onTimer();
	};
}

#endif // XMPPIQRECEIVER_H
