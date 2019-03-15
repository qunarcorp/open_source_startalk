#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class SupplierInfo : public IJsonSerializeable
    {
		Q_OBJECT
    public:
        SupplierInfo(QObject * parent):IJsonSerializeable(parent){};
        SupplierInfo():IJsonSerializeable(NULL){};
        ~SupplierInfo(){};
        JPROPERTY(QString, enId);
        JPROPERTY(QString, shopName);
    };

	class ProductInfo : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ProductInfo(QObject* parent) :IJsonSerializeable(parent) {};
		ProductInfo() :IJsonSerializeable(NULL) {};
		~ProductInfo(){};
		JPROPERTY(QString, appDtlUrl);
        JPROPERTY(QString, extendMsg);
        JPROPERTY(QString, imageUrl);
        JPROPERTY(QString, marketPrice);
        JPROPERTY(QString, price);
        JPROPERTY(QString, tag);
        JPROPERTY(QString, title);
        JPROPERTY(QString, touchDtlUrl);
        JPROPERTY(QString, type);
        JPROPERTY(QString, webDtlUrl);
		JPROPERTY(QString, productId);
        JPROPERTY(IJsonSerializeable*, supplier);


        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("supplier" == key)
            {
                SupplierInfo* pSupplier = new SupplierInfo();
                pSupplier->innerUnserialize(v);
                supplier(pSupplier);
            }
        }

    };
}
