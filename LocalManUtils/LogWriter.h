#ifndef LOGWRITER_H
#define LOGWRITER_H

#include "CoreObject.h"

namespace Util
{
    class LogWriter : public QObject
    {
        Q_OBJECT

    public:
        LogWriter();
        ~LogWriter();

signals:
        void sgDebug(const QString&);
        void sgError(const QString&);
        void sgInfo(const QString&);
        void sgWarn(const QString&);

        void sgConsole(QtMsgType, const QString&);
        void sgXmpp(QXmppLogger::MessageType type, const QString& val);
    private:

    };

}
#endif // LOGWRITER_H
