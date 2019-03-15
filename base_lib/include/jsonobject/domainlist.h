#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"
#include "httpresult.h"

namespace Biz
{
    class DomainInfo : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        DomainInfo(QObject * parent):IJsonSerializeable(parent){};
        DomainInfo():IJsonSerializeable(NULL){};
        DomainInfo(const DomainInfo& other){
            this->id (other.id ());
            this->name (other.name ());
            this->description (other.description ());
            this->url (other.url());
        };
        ~DomainInfo(){};
        JPROPERTY(QString, id);
        JPROPERTY(QString, name);
        JPROPERTY(QString, description);
        JPROPERTY(QString, url);
    };

    class DomainList : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        DomainList(const DomainList& other){
            this->version (other.version ());

            for (IJsonSerializeable* pItem : other.domains ())
            {
                DomainInfo* pDomain = static_cast<DomainInfo*>(pItem);
                DomainInfo* newDomain = new DomainInfo(*pDomain);
                mdomains.append (newDomain);
            }
        };

        DomainList(QObject* parent) :IJsonSerializeable(parent) {};
        DomainList() :IJsonSerializeable(NULL) {};
        ~DomainList(){};
        JPROPERTY(int, version);
        JPROPERTY(QList<IJsonSerializeable*>, domains);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("domains" == key)
            {
                DomainInfo* pdomain = new DomainInfo();
                pdomain->innerUnserialize(v);
                mdomains.append (pdomain);
            }
        }
    };
    class DomainListResult : public HttpResultBase
    {
        Q_OBJECT
    public:
        DomainListResult(QObject* parent=NULL) : HttpResultBase(parent){};
        ~DomainListResult(){};
        JPROPERTY(IJsonSerializeable*,    data);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                DomainList* pDomainList = new DomainList(this);
                pDomainList->innerUnserialize(v);
                data(pDomainList);
            }
        }
    };
    class DomainListInfo : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        DomainListInfo(QObject* parent) : IJsonSerializeable(parent){domains(NULL);lastupdate(0);};
        DomainListInfo() : IJsonSerializeable(NULL){domains(NULL);lastupdate(0);};
        ~DomainListInfo(){};
    public:
        JPROPERTY(IJsonSerializeable*,      domains);
        JPROPERTY(quint64,          lastupdate);
        JPROPERTY(QString,          currentSelectId);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("domains" == key)
            {
                DomainList* ptemn = new DomainList(this);
                ptemn->innerUnserialize(v);
                domains(ptemn);
            }
        }
    };

}
