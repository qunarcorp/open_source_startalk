#pragma once
#include <QObject>
#include "httpresult.h"
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class WechatUser : public IJsonSerializeable
    {
		Q_OBJECT
    public:
        WechatUser(QObject * parent):IJsonSerializeable(parent){};
        WechatUser():IJsonSerializeable(NULL){};
        ~WechatUser(){};
        JPROPERTY(QString, id);
        JPROPERTY(QString, name);
        JPROPERTY(QString, channelid);
    };

    class WechatUserPackage : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        WechatUserPackage(QObject * parent):IJsonSerializeable(parent){};
        WechatUserPackage():IJsonSerializeable(NULL){};
        ~WechatUserPackage(){qDeleteAll (musers.begin (),musers.end ());musers.clear ();};
        JPROPERTY(QString, packageid);
        JPROPERTY(QString, packagename);
        JPROPERTY(QList<IJsonSerializeable*>, users);
        virtual void unserializeItem (const QString& key,QVariant v){
            if ("users" == key)
            {
                WechatUser* pUser = new WechatUser();
                pUser->innerUnserialize(v);
                musers.append (pUser);
            }
        }
    };

	class WechatUserListParam : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		WechatUserListParam(QObject* parent) :IJsonSerializeable(parent) {};
		WechatUserListParam() :IJsonSerializeable(NULL) {};
		~WechatUserListParam(){qDeleteAll (mwechatlist.begin (),mwechatlist.end ());mwechatlist.clear ();};
		JPROPERTY(QString, version);
        
        JPROPERTY(QList<IJsonSerializeable*>, wechatlist);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("wechatlist" == key)
            {
                WechatUserPackage* pPackage = new WechatUserPackage();
                pPackage->innerUnserialize(v);
                mwechatlist.append (pPackage);
            }
        }
    };

    class WechatUserListResponce : public HttpResultBase
    {
        Q_OBJECT
    public:
        WechatUserListResponce(): HttpResultBase(NULL){data(NULL);};
        ~WechatUserListResponce(){};
        JPROPERTY(IJsonSerializeable*, data);
        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                WechatUserListParam* pPackage = new WechatUserListParam();
                pPackage->innerUnserialize(v);
                data (pPackage);
            }
        }
    };
}
