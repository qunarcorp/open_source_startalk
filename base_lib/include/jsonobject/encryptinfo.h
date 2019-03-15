#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"
#include "productinfo.h"
namespace Biz
{

	class BeginEncryptInfo : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		BeginEncryptInfo(QObject* parent) :IJsonSerializeable(parent) {
			type(0);
		};
		BeginEncryptInfo() :IJsonSerializeable(NULL) {
			type(0);
		};
		~BeginEncryptInfo(){};
		JPROPERTY(int, type);
		JPROPERTY(QString, pwd);
		
		virtual void unserializeItem(const QString& key,QVariant v)
		{

		}
	};

	class EncryptInfor : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		EncryptInfor(QObject* parent) : IJsonSerializeable(parent)
		{
			MsgType(0);
		}
		EncryptInfor():IJsonSerializeable(NULL)
		{
			MsgType(0);
		}
		~EncryptInfor() {};
		JPROPERTY(int, MsgType);
		JPROPERTY(QString, Content);
		virtual void unserializeItem(const QString&key, QVariant v)
		{

		}
	};


}
