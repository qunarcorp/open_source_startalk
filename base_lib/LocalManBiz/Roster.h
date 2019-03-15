#ifndef ROSTER_H
#define ROSTER_H

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    class Roster : public IXmlSerializeable
    {
        Q_OBJECT;

        PROPERTY(QString, UserID);
        PROPERTY(QString, Username);
        PROPERTY(QString, NickName);
        PROPERTY(QString, ImageUrl);
        PROPERTY(QString, Birthday);
        PROPERTY(QString, Gender);
    public:
        Roster();
        ~Roster();

    private:

    };

}
#endif // ROSTER_H
