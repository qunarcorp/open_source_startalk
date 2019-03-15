#ifndef ROSTERPROFILE_H
#define ROSTERPROFILE_H

#include "Status.h"
#include "ApiBase.h"

namespace ApiResponse
{
    class UserCenterInfoData : public ApiBase
    {
    public:
        QString nickName() const;
        QString headUrl() const;
        QString userID() const;
    protected:
        virtual void onAttach( QMap<QString, QVariant>& doc );
    };

    class RosterProfile : public ApiBase
    {
    public:
        const StatusItem& status() const;
        const UserCenterInfoData& userInfo() const;
    protected:
        virtual void onAttach( QMap<QString, QVariant>& doc );
    private:
        UserCenterInfoData mUserInfoItem;
        StatusItem mStatus;
    }; 
}

#endif // ROSTERPROFILE_H
