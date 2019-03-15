#ifndef APIRESPONSE_H
#define APIRESPONSE_H

#include "ApiBase.h"

namespace ApiResponse
{
    class StatusItem : public ApiBase
    {
    public:
        StatusItem();
        ~StatusItem();
        StatusItem(const StatusItem&);

        QString Code() const;
        QString Desc() const;

    protected:
        virtual void onAttach( QMap<QString, QVariant>& doc );

    }; 
}

#endif // APIRESPONSE_H
