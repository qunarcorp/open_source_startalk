#pragma once
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
    class ExtraInfo : public IJsonSerializeable
    {
		Q_OBJECT
    public:
        ExtraInfo(QObject * parent):IJsonSerializeable(parent){};
        ExtraInfo():IJsonSerializeable(NULL){};
        ~ExtraInfo(){};
        JPROPERTY(QString, opertext);
        JPROPERTY(QString, checkedopertext);
    };

    class ContentItemInfo : public IJsonSerializeable
    {
        Q_OBJECT
    public:
        ContentItemInfo(QObject * parent):IJsonSerializeable(parent){};
        ContentItemInfo():IJsonSerializeable(NULL){};
        ~ContentItemInfo(){};
        JPROPERTY(QString, sub_title);
        JPROPERTY(QString, sub_content);
    };

	class SystemNotifyParam : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		SystemNotifyParam(QObject* parent) :IJsonSerializeable(parent) {extra(NULL);};
		SystemNotifyParam() :IJsonSerializeable(NULL) {extra(NULL);};
		~SystemNotifyParam(){};
		JPROPERTY(QString, title);
        JPROPERTY(QString, operation_url);
        JPROPERTY(QString, prompt);
        JPROPERTY(QString, order_id);
        JPROPERTY(QString, clickprompt);
        JPROPERTY(IJsonSerializeable*, extra);
        JPROPERTY(QList<IJsonSerializeable*>, content);

        virtual void unserializeItem(const QString& key,QVariant v)
        {
            if ("extra" == key)
            {
                ExtraInfo* pExtra = new ExtraInfo();
                pExtra->innerUnserialize(v);
                extra(pExtra);
            }

            if ("content" == key)
            {
                ContentItemInfo* pContentItem = new ContentItemInfo();
                pContentItem->innerUnserialize(v);
                mcontent.append (pContentItem);
            }
        }

    };

	class GroupRoomVideoDetail : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		GroupRoomVideoDetail(QObject * parent) :IJsonSerializeable(parent){};
		GroupRoomVideoDetail() :IJsonSerializeable(NULL){};
		~GroupRoomVideoDetail(){};
		JPROPERTY(QString, roomName);
		JPROPERTY(QString, topic);
		JPROPERTY(quint64, startTime);
		JPROPERTY(quint64, createTime);
		JPROPERTY(QString, creator);
		JPROPERTY(QString, server);
	};

	class NoticeStrInfor : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		NoticeStrInfor(QObject *parent) :IJsonSerializeable(parent){};
		NoticeStrInfor():IJsonSerializeable(NULL){};
		~NoticeStrInfor(){};
		JPROPERTY(QString, str); //跳转文本
		JPROPERTY(QString, type); //类型
		JPROPERTY(QString, from); 
		JPROPERTY(QString, to);
		JPROPERTY(QString, realFrom);
		JPROPERTY(QString, realTo);
		JPROPERTY(QString, couslt);
		JPROPERTY(QString, strColor); //文本的颜色
		JPROPERTY(bool, isCouslt);
		JPROPERTY(QString, url);
	};
}
