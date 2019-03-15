#ifndef USERLOGIN_H
#define USERLOGIN_H

#include "ApiBase.h"
#include "Status.h"

namespace ApiResponse
{
    class UserInfoItem : public ApiBase {
    public:
        QString userID() const;
        QString nickName() const;
        QString gender() const;
        QString headUrl() const;
    protected:
        virtual void onAttach( QMap<QString, QVariant>& doc );
    };

    class StatusItem;
    class UserLoginItem : public ApiBase 
    {
    public:
        UserLoginItem();
        ~UserLoginItem();
    public:
        QString userID() const;
        QString host() const;
        QString userAccount() const;
        QString userToken() const;
        QString qcookie() const;

        const StatusItem& status() const;
        const UserInfoItem& userInfo() const;

    protected:
        virtual void onAttach( QMap<QString, QVariant>& doc );

        UserInfoItem mUserInfoItem;
        StatusItem mStatus;
    };

}
#endif // USERLOGIN_H
