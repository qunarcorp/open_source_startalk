#ifndef IJSONSERIALIZEABLE_H
#define IJSONSERIALIZEABLE_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtCore>

#include "ISerializeable.h"
#define JPROPERTY(PropertyType, Attribute) \
    Q_PROPERTY(PropertyType Attribute WRITE Attribute READ Attribute); \
private:\
    PropertyType m##Attribute;\
public:\
    PropertyType Attribute() const { return m##Attribute; }\
    void Attribute(PropertyType val) { m##Attribute = val; }

class IJsonSerializeable : public ISerializeable
{
	Q_OBJECT
public:
    IJsonSerializeable(QObject *parent=0);
    virtual ~IJsonSerializeable();

    virtual QString seralizeToString();
    virtual void unserializeFromString(const QString&);
public:
    void innerSerialize(QJsonObject& object);
    void innerUnserialize(const QVariant& object);

    virtual void unserializeItem(const QString& key,QVariant);

	template<class T>
	static QList<T*> unserializeListFromString(const QString& strJson)
	{
		QList<T*> retList;

		qRegisterMetaType<QList<IJsonSerializeable*>>("QList<IJsonSerializeable*>");
		QVariant json = QJsonDocument::fromJson(strJson.toUtf8()).toVariant();
		if (!json.toList().isEmpty())
		{
			for (QVariant object:json.toList())
			{
				T* jsonObject = new T();
				jsonObject->innerUnserialize(object);
				retList.append(jsonObject);
			}
		}
		return retList;
	}

	static QString seralizeListToString(const QList<IJsonSerializeable*> jsons)
	{
		qRegisterMetaType<QList<IJsonSerializeable*>>("QList<IJsonSerializeable*>");

		QJsonArray ja;
		for (IJsonSerializeable* json : jsons)
		{
			if (NULL!=json)
			{
				QJsonObject jo;
				json->innerSerialize(jo);
				ja.append(jo);
			}
		}
		QString ret = QJsonDocument(ja).toJson(QJsonDocument::Compact);
		return ret;
	}

private:
    
};

#endif // IJSONSERIALIZEABLE_H
