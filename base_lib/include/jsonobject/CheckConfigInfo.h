#ifndef CheckConfigInfo_H
#define CheckConfigInfo_H
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class Ability : public IJsonSerializeable
    {
        Q_OBJECT

        JPROPERTY(QStringList,group);
        JPROPERTY(QStringList,base);
        
    public:
        Ability(QObject* parent):IJsonSerializeable(parent){};
        ~Ability(){};
     
    };

    class OtherConfig : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        OtherConfig(QObject* parent):IJsonSerializeable(parent){};
        ~OtherConfig(){};
        JPROPERTY(QString,cachefileurl);
        JPROPERTY(QString,redpackageurl);
        JPROPERTY(QString,balanceurl);
        JPROPERTY(QString,thanksurl);
        JPROPERTY(QString,aacollectionurl);
        JPROPERTY(QString,myredpackageurl);
    };

    class TrdExtendMsgNode : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        TrdExtendMsgNode(QObject* parent):IJsonSerializeable(parent){
            client(0);
            support(0);
            type(0);
            scope(0);
        };
        ~TrdExtendMsgNode(){};
        JPROPERTY(int, client);
        JPROPERTY(int, support);
        JPROPERTY(int, type);
        JPROPERTY(int, scope);
        JPROPERTY(int, linkType);
        JPROPERTY(QString, title);
        JPROPERTY(QString, icon);
        JPROPERTY(QString, linkurl)
    };

	class CheckConfigInfo : public IJsonSerializeable
	{
        Q_OBJECT
	public:
        CheckConfigInfo(QObject *parent=NULL){
            version(0);
            exists(true);
            ability(NULL);
            otherconfig(NULL);
        };
        ~CheckConfigInfo(){ };
	    JPROPERTY(int,version);
        JPROPERTY(QString,company);
        JPROPERTY(bool,exists);
        JPROPERTY(IJsonSerializeable*,ability);
        JPROPERTY(IJsonSerializeable*,otherconfig);
        JPROPERTY(QList<IJsonSerializeable*>,trdextendmsg);

    protected:
        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("ability" == key)
            {
                Ability* pability = new Ability(this);
                pability->innerUnserialize(v);
                ability(pability);
            }
            if ("otherconfig" == key)
            {
                OtherConfig* poc = new OtherConfig(this);
                poc->innerUnserialize(v);
                otherconfig(poc);
            }
            if ("trdextendmsg" == key)
            {
                TrdExtendMsgNode* ptemn = new TrdExtendMsgNode(this);
                ptemn->innerUnserialize(v);
                mtrdextendmsg.append(ptemn);
            }
        }
	};
}


#endif
