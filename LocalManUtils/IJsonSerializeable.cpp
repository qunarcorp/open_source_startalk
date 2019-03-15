#include "IJsonSerializeable.h"
#include <QList>
#include <QJsonArray>
#define CompType(x, y) x.typeName() == QString::fromStdString(y)


IJsonSerializeable::IJsonSerializeable(QObject *parent)
    : ISerializeable(parent)
{

}

IJsonSerializeable::~IJsonSerializeable()
{

}

QString IJsonSerializeable::seralizeToString()
{
    QJsonObject obj;
    innerSerialize(obj);
    QString ret = QJsonDocument(obj).toJson(QJsonDocument::Compact);
    return ret;
}

void IJsonSerializeable::innerSerialize(QJsonObject& object)
{
    auto count = metaObject()->propertyCount();
    for(int i=0; i<count; ++i)
    {
        auto pro = metaObject()->property(i);

        auto a = pro.typeName();    // 类型
        if(strcmp(pro.name(), "objectName")==0)// 内置变量过滤掉
            continue;

        auto key = pro.name();        // 变量名
        auto value = pro.read(this);

        if( CompType(pro, "QString") )
            object.insert(key,value.toString());
        if( CompType(pro, "QStringList") )
            object.insert(key,QJsonArray::fromStringList(value.toStringList()));
        else if ( CompType(pro, "int") )
            object.insert(key,value.toInt());
        else if ( CompType(pro, "qint64") || CompType(pro, "quint64") || CompType(pro, "qulonglong") || CompType(pro, "qlonglong") )
            object.insert(key,(qint64)value.toLongLong());
        else if ( CompType(pro, "double") )
            object.insert(key,value.toDouble());
        else if ( CompType(pro, "bool") )
            object.insert(key,value.toBool());
        else if ( CompType(pro, "IJsonSerializeable*") ) {
            auto datas = pro.read(this).value<IJsonSerializeable*>();
            if (NULL!=datas)
            {
                QJsonObject itemObj;
                datas->innerSerialize(itemObj);
                object.insert(key,itemObj);
            }
        }
        else  if( CompType(pro, "QList<IJsonSerializeable*>")){
            auto datas = pro.read(this).value<QList<IJsonSerializeable*>>();

            QJsonArray array;
            foreach(auto item, datas){
                QJsonObject itemObj;
                item->innerSerialize(itemObj);
                array.append(itemObj);
            }
            object.insert(key,array);
        }
        else
        {
            continue;
        }
    }
}

void IJsonSerializeable::unserializeFromString(const QString& strJson)
{
    qRegisterMetaType<QList<IJsonSerializeable*>>("QList<IJsonSerializeable*>");
    QVariant json = QJsonDocument::fromJson(strJson.toUtf8()).toVariant();
    innerUnserialize(json);
}

void IJsonSerializeable::innerUnserialize(const QVariant& object)
{
    QVariantMap qmap = object.toMap();

    auto count = metaObject()->propertyCount();
    for(int i=0; i<count; ++i)
    {
        auto pro = metaObject()->property(i);

        auto a = pro.typeName();    // 数据类型类型
        auto key = pro.name();        // 变量名
        auto value = pro.read(this);

        if(strcmp(pro.name(), "objectName")==0)// 内置变量过滤掉
            continue;

		

        if (qmap.contains(key))
        {
            if (CompType(pro, "IJsonSerializeable*"))
            {
                QVariant vl= qmap.value(key);
                unserializeItem(key, vl);
            }
            else if( CompType(pro, "QList<IJsonSerializeable*>")){
                 QVariantList vl= qmap.value(key).toList();
                for (QVariant v:vl)
                     unserializeItem(key, v);
            }
            else
            {
				if (CompType(pro,"QString") && (qmap.value(key).type() == QVariant::Map || QVariant::List == qmap.value(key).type() ))
				{
					QString ret = QJsonDocument::fromVariant(qmap.value(key)).toJson(QJsonDocument::Compact);
					pro.write(this,ret);
				} else {
					pro.write(this,qmap.value(key));
				}
            }
        }
    }
}

void IJsonSerializeable::unserializeItem(const QString& key,QVariant v)
{

}

