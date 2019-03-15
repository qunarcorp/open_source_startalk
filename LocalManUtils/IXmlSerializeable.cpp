#include "IXmlSerializeable.h"

const QString mainNode = "item";
const QString argsNode = "args";
const QString classNode = "className";
const QString argNode = "arg";
const QString argNode_Attribute = "attribute";
const QString argNode_Type = "type";
const QString argNode_Value = "value";

#define CompType(x, y) x.typeName() == QString::fromStdString(y)
IXmlSerializeable::IXmlSerializeable(QObject *parent)
    : ISerializeable(parent)
{

}

IXmlSerializeable::~IXmlSerializeable()
{

}

void IXmlSerializeable::initNotifycation()
{
    auto count = metaObject()->propertyCount();
    for(int i=0; i<count; ++i)
    {
        auto pro = metaObject()->property(i);
        const char *name = pro.name();
        auto signalIndex = pro.notifySignalIndex();

        auto slotIndex = metaObject()->indexOfMethod("onNotifycation()");
        auto ret = this->metaObject()->connect(this, pro.notifySignalIndex(), this, metaObject()->indexOfMethod("NotifyConnection()"));
    }
}

void IXmlSerializeable::onNotifycation()
{
    auto count = metaObject()->propertyCount();
    for(int i=0; i<count; ++i)
    {
        auto pro = metaObject()->property(i);
        if( !pro.hasNotifySignal() || pro.notifySignalIndex() != senderSignalIndex() )
            continue;
        //auto a = pro.typeName();
        //auto proName = pro.name();
        //auto proValue = pro.read(this);

        mChangeList.push_back(pro.name());
        break;
    }
}

bool IXmlSerializeable::compare( IXmlSerializeable& other )
{
    auto tmp1 = seralizeToString();
    auto tmp2 = other.seralizeToString();

    return tmp1.compare(tmp2) == 0;
}


QDomDocument IXmlSerializeable::seralizeToDocument()
{
    QDomDocument doc;
    innerSerialize(doc);

    return doc;
}

QString IXmlSerializeable::seralizeToString()
{
    return seralizeToDocument().toString();
}

QString IXmlSerializeable::seralizeChangedList()
{
    QDomDocument doc;
    innerSerializeChangedLst(doc);
    return doc.toString();
}

void IXmlSerializeable::unserializeFromString( const QString& content )
{
    QDomDocument doc;
    doc.setContent(content);

    auto elemRoot = doc.firstChildElement(mainNode);
    innerUnserialize(elemRoot);
}

void IXmlSerializeable::unserialize( QDomElement& elem )
{
    //auto elemRoot = elem.firstChildElement(mainNode);
    innerUnserialize(elem);
}

void IXmlSerializeable::innerSerializeChangedLst( QDomDocument& doc )
{
    auto elemClassName = doc.createElement(mainNode);
    elemClassName.setAttribute(classNode, metaObject()->className());

    auto elemArgs = doc.createElement(argsNode);
    foreach(auto itor, mChangeList){
        auto count = metaObject()->propertyCount();
        for(int i=0; i<count; ++i)
        {
            auto pro = metaObject()->property(i);

            auto a = pro.typeName();
            auto b = pro.read(this);
            auto c = pro.name();

            if(strcmp(pro.name(), "objectName")==0)
                continue;

            if(QString::compare(pro.name(), itor) != 0)
                continue;

            auto elemArg = doc.createElement( argNode );


            elemArg.setAttribute( argNode_Attribute, pro.name() );
            elemArg.setAttribute( argNode_Type, pro.typeName());
            if( CompType(pro, "QString") )
                elemArg.setAttribute( argNode_Value, pro.read(this).toString() );
            else if( CompType(pro, "int") )
                elemArg.setAttribute( argNode_Value, pro.read(this).toInt() );
            else if( CompType(pro, "bool") )
                elemArg.setAttribute( argNode_Value, pro.read(this).toBool() );
            else if( CompType(pro, "QUrl") )
                continue;
            else
            {
                Q_ASSERT(false);
                continue;
            }
            elemArgs.appendChild(elemArg);
        }

        elemClassName.appendChild(elemArgs);

        doc.appendChild(elemClassName);
    }
}

void IXmlSerializeable::innerSerialize( QDomDocument& doc )
{
    auto elemClassName = doc.createElement(mainNode);
    elemClassName.setAttribute(classNode, metaObject()->className());

    auto elemArgs = doc.createElement(argsNode);

    auto count = metaObject()->propertyCount();
    for(int i=0; i<count; ++i)
    {
        auto pro = metaObject()->property(i);

        auto a = pro.typeName();
        //auto b = pro.read(this);
        auto c = pro.name();

        if(strcmp(pro.name(), "objectName")==0)
            continue;

        auto elemArg = doc.createElement( argNode );


        elemArg.setAttribute( argNode_Attribute, pro.name() );
        elemArg.setAttribute( argNode_Type, pro.typeName());
        if( CompType(pro, "QString") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toString() );
        else if( CompType(pro, "int") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toInt() );
        else if( CompType(pro, "bool") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toBool() );
        else if( CompType(pro, "QUrl") )
            continue;
        else if( CompType(pro, "qreal") || CompType(pro, "double") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toDouble() );
        else if( CompType(pro, "qint64") || CompType(pro, "qlonglong") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toLongLong() );
        else if( CompType(pro, "quint64") || CompType(pro, "qulonglong") )
            elemArg.setAttribute( argNode_Value, pro.read(this).toULongLong() );
        else if( CompType(pro, "QStringList"))
        {
            auto datas = pro.read(this).toStringList();
            foreach(auto item, datas){
                auto elemListItem = doc.createElement("item");
                elemListItem.appendChild(doc.createTextNode(item));

                elemArg.appendChild(elemListItem);
            }
        }
        else if( CompType(pro, "QList<IXmlSerializeable*>")){
            auto datas = pro.read(this).value<QList<IXmlSerializeable*>>();
            //auto datas = pro.read(this).toList();

            foreach(auto item, datas){
                elemArg.appendChild(item->seralizeToDocument());
            }
        }
        else
        {
           // Q_ASSERT(false);
            continue;
        }
        elemArgs.appendChild(elemArg);
    }
    elemClassName.appendChild(elemArgs);
    doc.appendChild(elemClassName);

    childSerialize(doc, elemClassName);
}


void IXmlSerializeable::innerUnserialize( QDomElement& elemRoot )
{
    do 
    {
        auto className = metaObject()->className();
        auto xmlClassName = elemRoot.attribute(classNode);
        if(xmlClassName.isEmpty()){
            return;
        }
        if(elemRoot.attribute(classNode) != metaObject()->className())
            break;

        auto elemArgs = elemRoot.firstChildElement(argsNode);
        if(!elemArgs.isElement())
            break;

        auto elemArg = elemArgs.firstChildElement(argNode);
        while(elemArg.isElement())
        {
            auto elemType = elemArg.attribute(argNode_Attribute);

            auto count = metaObject()->propertyCount();
            for(int i=0; i<count; ++i)
            {
                auto pro = metaObject()->property(i);

                auto tn = pro.name();
                if(elemType != pro.name())
                    continue;
                auto pn = pro.typeName();
                if(CompType(pro, "QList<IXmlSerializeable*>"))
                {
                    auto itemArg = elemArg.firstChildElement(mainNode);
                    while(itemArg.isElement())
                    {
                        unserializeItem(pro.name(), itemArg);
                        itemArg = itemArg.nextSiblingElement(mainNode);
                    }
                }
				else if( CompType(pro, "QStringList"))
				{
					
				}
                else
                {
                    auto attr = elemArg.attribute(argNode_Value);
                    pro.write(this, elemArg.attribute(argNode_Value));
                }

                emit pro.notifySignalIndex();
                break;
            }
            elemArg = elemArg.nextSiblingElement();
        }
        childUnserialize(elemRoot);
        return;
    } while (false);

    Q_ASSERT(false);
}

void IXmlSerializeable::childSerialize( QDomDocument& doc, QDomElement& elem ) const
{

}

void IXmlSerializeable::childUnserialize( QDomElement& elemRoot )
{

}

void IXmlSerializeable::unserializeItem( const QString&name, QDomElement& elem )
{

}
