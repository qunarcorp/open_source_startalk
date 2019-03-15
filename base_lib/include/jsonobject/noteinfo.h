#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"
#include "productinfo.h"
namespace Biz
{
	class NoteInfo : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		NoteInfo(QObject* parent) :IJsonSerializeable(parent) {
            type(0);
            chatid(0);
            data(NULL);
        };
		NoteInfo() :IJsonSerializeable(NULL) {
            type(0);
            chatid(0);
            data(NULL);
        };
		~NoteInfo(){};
		JPROPERTY(QString, bu);
        JPROPERTY(int, type);
        JPROPERTY(QString, url);
        JPROPERTY(QString, ip);
        JPROPERTY(quint64, chatid);
        JPROPERTY(IJsonSerializeable*, data);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                ProductInfo* ptemn = new ProductInfo(this);
                ptemn->innerUnserialize(v);
                data(ptemn);
            }
        }

    };

	class VisitorReplyInfo : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		VisitorReplyInfo(QObject* parent) :IJsonSerializeable(parent) {

		};
		VisitorReplyInfo() :IJsonSerializeable(NULL) {
	
		};
		~VisitorReplyInfo(){};
		JPROPERTY(QString, TransReson);
		JPROPERTY(QString, realtoId);
		JPROPERTY(QString, toId);
		JPROPERTY(QString, realtoIdNickName);
		JPROPERTY(QString, realfromIdNickName);
		JPROPERTY(QString, retId);
		

		virtual void unserializeItem(const QString& key,QVariant v)
		{
			
		}

	};

	class ShopReplyInfo : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ShopReplyInfo(QObject* parent) :IJsonSerializeable(parent) {

		};
		ShopReplyInfo() :IJsonSerializeable(NULL) {

		};
		~ShopReplyInfo(){};
		JPROPERTY(QString, d);
		JPROPERTY(QString, f);
		JPROPERTY(QString, r);
		JPROPERTY(QString, u);
		JPROPERTY(QString, retId);
		JPROPERTY(QString, rt);
		JPROPERTY(QString, toId);


		virtual void unserializeItem(const QString& key,QVariant v)
		{

		}

	};

}
