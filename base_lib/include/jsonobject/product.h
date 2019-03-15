#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
	class ProductCardDesc : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ProductCardDesc(QObject * parent) :IJsonSerializeable(parent){};
		ProductCardDesc() :IJsonSerializeable(NULL){};
		~ProductCardDesc(){};
		JPROPERTY(QString, k);
		JPROPERTY(QString, v);
		JPROPERTY(QString, c);
	};

	class ProductCard : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ProductCard(QObject* parent) :IJsonSerializeable(parent) {};
		ProductCard() :IJsonSerializeable(NULL) {};
		~ProductCard(){};
		JPROPERTY(QString, titleimg);
		JPROPERTY(QString, titletxt);
		JPROPERTY(QString, productimg);
		JPROPERTY(QString, detailurl);
		JPROPERTY(QString, descdetail);
		JPROPERTY(int, openstyle);
		JPROPERTY(QList<IJsonSerializeable*>, descs);


		virtual void unserializeItem(const QString& key, QVariant v)
		{
			if ("descs" == key)
			{
				ProductCardDesc* descitem = new ProductCardDesc();
				descitem->innerUnserialize(v);
				mdescs.append(descitem);
			}
		}

	};
}
