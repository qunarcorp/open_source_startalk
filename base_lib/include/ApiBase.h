#ifndef APIBASE_H
#define APIBASE_H

#include "CoreObject.h"

namespace ApiResponse
{
#define returnJonValue(args) return myItem[args].value<QString>();
    class ApiBase
    {
    public:
        ApiBase();
        ~ApiBase();

        void attachTo(QMap<QString, QVariant>& doc);
    protected:
        virtual void onAttach(QMap<QString, QVariant>& doc) = 0;
        QMap<QString, QVariant> myItem;
    }; 
}

#endif // APIBASE_H
