#pragma once
#include <QObject>
#include "httpresult.h"
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class HotelQuestion : public IJsonSerializeable
    {
		Q_OBJECT
    public:
        HotelQuestion(QObject * parent):IJsonSerializeable(parent){};
        HotelQuestion():IJsonSerializeable(NULL){};
        ~HotelQuestion(){};
        JPROPERTY(QString, text);
        JPROPERTY(QString, url);
    };

    class HotelQuestions : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        HotelQuestions(QObject * parent):IJsonSerializeable(parent){};
        HotelQuestions():IJsonSerializeable(NULL){};
        ~HotelQuestions(){qDeleteAll (mdata.begin (),mdata.end ());mdata.clear ();};
        JPROPERTY(QString, title);
        JPROPERTY(QString, subtitle);
        JPROPERTY(QList<IJsonSerializeable*>, data);
        virtual void unserializeItem (const QString& key,QVariant v){
            if ("data" == key)
            {
                HotelQuestion* pQuestion = new HotelQuestion();
                pQuestion->innerUnserialize(v);
                mdata.append (pQuestion);
            }
        }
    };


    class HotelOrderDetail : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        HotelOrderDetail(QObject * parent):IJsonSerializeable(parent){};
        HotelOrderDetail():IJsonSerializeable(NULL){};
        ~HotelOrderDetail(){};
        JPROPERTY(QString, settlementOrderId);
        JPROPERTY(QString, productTypeId);
        JPROPERTY(QString, productTypeName);
        JPROPERTY(QString, settlementDateInterval);
        JPROPERTY(QString, money);
        JPROPERTY(QString, settlementStatusName);
    };


    class HotelOrder : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        HotelOrder(QObject * parent):IJsonSerializeable(parent){};
        HotelOrder():IJsonSerializeable(NULL){};
        ~HotelOrder(){};
        JPROPERTY(QString, actionType);
        JPROPERTY(QString, text);
        JPROPERTY(QString, url);
        JPROPERTY(IJsonSerializeable*, properties);

        virtual void unserializeItem (const QString& key,QVariant v){
            if ("properties" == key)
            {
               HotelOrderDetail* pinfo = new HotelOrderDetail(this);
               pinfo->innerUnserialize (v);
               properties(pinfo);
            }
        }
    };

    class HotelOrders : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        HotelOrders(QObject * parent):IJsonSerializeable(parent){};
        HotelOrders():IJsonSerializeable(NULL){};
        ~HotelOrders(){qDeleteAll (mdata.begin (),mdata.end ());mdata.clear ();};
        JPROPERTY(QString, title);
        JPROPERTY(QList<IJsonSerializeable*>, data);
        virtual void unserializeItem (const QString& key,QVariant v){
            if ("data" == key)
            {
                HotelOrder* pOrder = new HotelOrder();
                pOrder->innerUnserialize(v);
                mdata.append (pOrder);
            }
        }
    };


	class QiangdanContentDetail:public IJsonSerializeable
	{
		Q_OBJECT
	public:
		QiangdanContentDetail(QObject * parent):IJsonSerializeable(parent){budgetinfo(""); OrderTime("");Remarks("");};
		QiangdanContentDetail():IJsonSerializeable(NULL){budgetinfo(""); OrderTime("");Remarks("");};
		~QiangdanContentDetail(){};
		JPROPERTY(QString, budgetinfo);
		JPROPERTY(QString, OrderTime);
		JPROPERTY(QString, Remarks);
		
	};

	class Qiangdan : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		Qiangdan(QObject * parent):IJsonSerializeable(parent){};
		Qiangdan():IJsonSerializeable(NULL){};
		~Qiangdan(){};
		JPROPERTY(QString, title);
		JPROPERTY(QString, dealid);
		JPROPERTY(QString, dealurl);
		JPROPERTY(IJsonSerializeable*, detail);
		virtual void unserializeItem (const QString& key,QVariant v){
			if ("detail" == key)
			{
				QiangdanContentDetail* pdetail = new QiangdanContentDetail(this);
				pdetail->budgetinfo("");
				pdetail->OrderTime("");
				pdetail->Remarks("");

				pdetail->innerUnserialize(v);
				detail(pdetail);
			}
		}
	};
}
