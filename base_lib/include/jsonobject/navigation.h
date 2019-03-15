#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"
#include "constants.h"

namespace Biz
{
   
        class AdNode : public IJsonSerializeable
        {
            Q_OBJECT
        public:
            AdNode(QObject* parent):IJsonSerializeable(parent){
                adsec(0);
                adurl("");
                shown(false);
            };
            ~AdNode(){};
            JPROPERTY(int, adsec);
            JPROPERTY(QString, adurl);
            JPROPERTY(bool, shown);
        };

        class BaseaddessNode : public IJsonSerializeable
        {
            Q_OBJECT
        public:
            BaseaddessNode(QObject* parent):IJsonSerializeable(parent){
                xmpp ("");
                xmppport (0);
                pbport (Constant::DEFAULT_PROTOBUF_PORT);
                domain ("");
                apiurl ("");
                fileurl ("");
            };
            ~BaseaddessNode(){};
            JPROPERTY(QString, xmpp);
            JPROPERTY(int , xmppport);
            JPROPERTY(int , pbport);
            JPROPERTY(QString ,domain);
            JPROPERTY(QString, apiurl);
            JPROPERTY(QString, fileurl);

        };

	class Navigation : public IJsonSerializeable
	{
        Q_OBJECT
    
	public:
	    Navigation(QObject* parent):IJsonSerializeable(parent){
            version(0);
            ad(NULL);
            baseaddess (NULL);
        }
	    ~Navigation(void){}
        JPROPERTY(int, version);
        JPROPERTY(IJsonSerializeable*, ad);
        JPROPERTY(IJsonSerializeable*, baseaddess);
    protected:
        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("ad" == key)
            {
                AdNode* ptemn = new AdNode(this);
                ptemn->innerUnserialize(v);
                ad (ptemn);
            }
            if ("baseaddess" == key)
            {
                BaseaddessNode* bn = new BaseaddessNode(this);
                bn->innerUnserialize (v);
                baseaddess (bn);
            }
        }
	};
}

