#ifndef IXMLSERIALIZEABLE_H
#define IXMLSERIALIZEABLE_H
#include "CoreObject.h"
#include "ISerializeable.h"
#include <QtXml>

//#define Json_Property(x, y) \
//    \
//private: \
//    x m##y; \
//signals:\
//    void on##y##Changed();\
//public: \
//    void y(x v){ m##y = v; emit on##y##Changed(); } \
//    x y() const { return m##y; }

#define PROPERTY(PropertyType, Attribute) \
    Q_PROPERTY(PropertyType Attribute WRITE Attribute READ Attribute); \
private:\
    PropertyType m##Attribute;\
public:\
    PropertyType Attribute() const { return m##Attribute; }\
    void Attribute(PropertyType val) { m##Attribute = val; }



#define PROPERTY_RO(PropertyType, Attribute) \
    Q_PROPERTY(PropertyType Attribute WRITE Attribute READ Attribute); \
private:\
    PropertyType m##Attribute;\
public:\
    PropertyType Attribute() const { return m##Attribute; }\
private:\
    void Attribute(PropertyType val) { m##Attribute = val; }

#define PROPERTY_P(PropertyType, Attribute) \
    Q_PROPERTY(PropertyType Attribute WRITE Attribute READ Attribute); \
private:\
    PropertyType m##Attribute;\
private:\
    PropertyType Attribute() const { return m##Attribute; }\
public:\
    void Attribute(PropertyType val) { m##Attribute = val; }

#define DECLARATION_CHANGEMARK() \
private:\
    bool m_datachanged;\
public:\
    bool isDataChanged() const { return m_datachanged; }\
    void dataChanged(bool change) { m_datachanged = change; }

#define PROPERTY_CHANGEMARK(PropertyType, Attribute, AttributeInner) \
    Q_PROPERTY(PropertyType Attribute WRITE AttributeInner READ AttributeInner); \
private:\
    PropertyType m##Attribute;\
protected:\
    PropertyType AttributeInner() const { return m##Attribute; }\
    void AttributeInner(PropertyType val) { if(m##Attribute != val){\
    m##Attribute = val;\
    } }\
public:\
    PropertyType Attribute() const { return m##Attribute; }\
    void Attribute(PropertyType val) { if(m##Attribute != val)\
        {\
            m##Attribute = val; \
            m_datachanged=true; \
        } }

#define PROPERTY_REF(PropertyType, Attribute) \
private:\
    PropertyType m##Attribute;\
public:\
    PropertyType& Attribute() { return m##Attribute; }\
    void Attribute(PropertyType& val) { m##Attribute = val; }

class IXmlSerializeable : public ISerializeable
{
    Q_OBJECT

public:
    IXmlSerializeable(QObject *parent=0);
    ~IXmlSerializeable();
public:
    virtual QString seralizeToString();
    virtual void unserializeFromString(const QString&);
public:
    bool compare(IXmlSerializeable& other);
    QDomDocument seralizeToDocument();
    QString seralizeChangedList();
    void unserialize(QDomElement&);

private:
    void innerSerializeChangedLst(QDomDocument& doc);
    void innerSerialize(QDomDocument& doc);
    void innerUnserialize(QDomElement&);

    virtual void childSerialize(QDomDocument& doc, QDomElement& elem) const;
    virtual void childUnserialize(QDomElement& elemRoot);
protected:
    virtual void unserializeItem(const QString&, QDomElement& elem);

    void initNotifycation();
private slots:
    void onNotifycation();
private:
    QVector<QString> mChangeList;
};

#endif // IXMLSERIALIZEABLE_H
