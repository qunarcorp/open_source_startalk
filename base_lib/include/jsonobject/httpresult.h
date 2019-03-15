#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class HttpResultBase : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        HttpResultBase(QObject* parent):IJsonSerializeable(parent){
            ret(false);
            ver(0);
            errcode(0);
        };
        ~HttpResultBase(){};
        JPROPERTY(bool ,    ret);
        JPROPERTY(QString,  msg);
        JPROPERTY(QString,  errmsg);
        JPROPERTY(int,      ver);
        JPROPERTY(int,      errcode);
    };

   

    class HttpResultString : public HttpResultBase
    {
        Q_OBJECT
    public:
        HttpResultString(QObject* parent):HttpResultBase(parent){
            data("");
        };
        ~HttpResultString(){};
        JPROPERTY(QString, data)
    };

    class QVTInfo : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        QVTInfo(QObject* parent) : IJsonSerializeable(parent){
            expireTime(0);
        };
        ~QVTInfo(){};
    public:
        JPROPERTY(QString, oldname);
        JPROPERTY(QString, username);
        JPROPERTY(QString, merchant);
        JPROPERTY(QString, qcookie);
        JPROPERTY(QString, scookie);
        JPROPERTY(QString, tcookie);
        JPROPERTY(QString, vcookie);
        JPROPERTY(quint64, expireTime);

    };

    class QVTPowerResult : public HttpResultBase
    {
        Q_OBJECT

    public:
        QVTPowerResult(QObject* parent=NULL) : HttpResultBase(parent){};
        ~QVTPowerResult(){};
        JPROPERTY(QList<IJsonSerializeable*>,    data);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                QVTInfo* pQvtInfo = new QVTInfo(this);
                pQvtInfo->innerUnserialize(v);
                mdata.append(pQvtInfo);
            }
        }

    };

    class TokenInfo : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        TokenInfo(QObject* parent) : IJsonSerializeable(parent){
        };
        ~TokenInfo(){};
    public:
        JPROPERTY(QString, username);
        JPROPERTY(QString, token);
    };

    class GetTokenResponse : public HttpResultBase
    {
        Q_OBJECT
    public:
        GetTokenResponse(QObject* parent=NULL) : HttpResultBase(parent){};
        ~GetTokenResponse(){};

        JPROPERTY(IJsonSerializeable*, data);
        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                TokenInfo* pTokenInfo = new TokenInfo(this);
                pTokenInfo->innerUnserialize(v);
                data(pTokenInfo);
            }
        }
    };

    class WorkStatusData : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        enum STATUS{
            ST_STANDAR     = 0, //标准模式
            ST_SERVICE  = 4, //超人模式
			ST_rest = 1  //勿扰模式
        };
    public:
        WorkStatusData(){};
        ~WorkStatusData(){};
        JPROPERTY(int,          st);
		JPROPERTY(QString,      sname);
		JPROPERTY(int,           sid);
    }; 

    class GetWorkStatusResponce: public HttpResultBase
    {
        Q_OBJECT
    public:
        GetWorkStatusResponce(QObject* parent=NULL) : HttpResultBase(parent){};
        ~GetWorkStatusResponce(){};

        JPROPERTY(QList<IJsonSerializeable*>, data);
        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("data" == key)
            {
                WorkStatusData* pdata = new WorkStatusData();
                pdata->innerUnserialize(v);
                mdata.append(pdata);
            }
        }
    };

	class ShopInfoDetail:public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ShopInfoDetail(QObject * parent):IJsonSerializeable(parent)
		{
			bType(0);
		}
		ShopInfoDetail():IJsonSerializeable(NULL) {}
		~ShopInfoDetail()
		{
			bType(0);
		}
		JPROPERTY(QString,   id);
		JPROPERTY(QString,   name);
		JPROPERTY(int,   bType);
		JPROPERTY(QString,   shopId);
		JPROPERTY(QString,   logoUrl);
		JPROPERTY(QString,   busiSupplierId);

	protected:
	private:
	};



	class ShopInforResponce:public HttpResultBase
	{
		Q_OBJECT
	public:
		ShopInforResponce(QObject* parent=NULL):HttpResultBase(parent){};
		~ShopInforResponce(){};
		 JPROPERTY(QList<IJsonSerializeable*>, data);
		virtual void unserializeItem(const QString& key,QVariant v)
		{
			if ("data" == key)
			{
				ShopInfoDetail* pdata = new ShopInfoDetail();
				pdata->innerUnserialize(v);
				mdata.append (pdata);
			}
		}
	};


	class OneMemberDetail:public IJsonSerializeable
	{
		Q_OBJECT
	public:
		OneMemberDetail(QObject * parent):IJsonSerializeable(parent)
		{
		}
		OneMemberDetail():IJsonSerializeable(NULL) {}
		~OneMemberDetail()
		{
		}
		JPROPERTY(QString,   N);
		JPROPERTY(QString,   U);
		JPROPERTY(QString,   W);
		JPROPERTY(QString,   O);

	protected:
	private:
	};



	class MemberResponce:public HttpResultBase
	{
		Q_OBJECT
	public:
		MemberResponce(QObject* parent=NULL):HttpResultBase(parent){};
		~MemberResponce(){qDeleteAll (mdata.begin (),mdata.end ());mdata.clear ();};
		JPROPERTY(QList<IJsonSerializeable*>, data);
		virtual void unserializeItem(const QString& key,QVariant v)
		{
			if ("data" == key)
			{
				OneMemberDetail* pdata = new OneMemberDetail();
				pdata->innerUnserialize(v);
				mdata.append (pdata);
			}
		}
	};


	class TransReplyInfor:public IJsonSerializeable
	{
		Q_OBJECT
	public:
		TransReplyInfor(QObject * parent):IJsonSerializeable(parent)
		{
		}
		TransReplyInfor():IJsonSerializeable(NULL) {}
		~TransReplyInfor()
		{
		}
		JPROPERTY(QString,   u);
		JPROPERTY(QString,   d);
		JPROPERTY(QString,   f);
		JPROPERTY(QString,   r);
		JPROPERTY(QString,   toId);

	protected:
	private:
	};


	class PushStatusData : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		
	public:
		PushStatusData(){};
		~PushStatusData(){};
		JPROPERTY(bool,          state);
	}; 

	class GetPushStatusResponce: public HttpResultBase
	{
		Q_OBJECT
	public:
		GetPushStatusResponce(QObject* parent=NULL) : HttpResultBase(parent){};
		~GetPushStatusResponce(){};

		JPROPERTY(IJsonSerializeable*, data);
		virtual void unserializeItem(const QString& key,QVariant v)
		{
			if ("data" == key)
			{
				PushStatusData* pdata = new PushStatusData();
				pdata->innerUnserialize(v);
				data(pdata);
			}
		}
	};

	class qcloudInforReturnData : public IJsonSerializeable
	{
		Q_OBJECT
	public:

	public:
		qcloudInforReturnData(){};
		~qcloudInforReturnData(){};
		JPROPERTY(int,          qid);
		JPROPERTY(quint64,       version);
	}; 

	class qcloudInfoResponce: public HttpResultBase
	{
		Q_OBJECT
	public:
		qcloudInfoResponce(QObject* parent=NULL) : HttpResultBase(parent){};
		~qcloudInfoResponce(){};

		JPROPERTY(IJsonSerializeable*, data);
		virtual void unserializeItem(const QString& key,QVariant v)
		{
			if ("data" == key)
			{
				qcloudInforReturnData* pdata = new qcloudInforReturnData();
				pdata->innerUnserialize(v);
				data(pdata);
			}
		}
	};
}
