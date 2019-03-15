#ifndef CONFIGUREDATA_H
#define CONFIGUREDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    class UserSettingData : public IXmlSerializeable
    {
		Q_OBJECT;
        PROPERTY(QString,   QCookie);
        PROPERTY(QString,   VCookie);
        PROPERTY(QString,   TCookie);
        PROPERTY(QString,   SCookie);
        PROPERTY(QString,   LoginToken);
        PROPERTY(QString,   LoginTokenUserName);
    public:
        UserSettingData();
        ~UserSettingData();
    }; 

  
}

#endif // CONFIGUREDATA_H
