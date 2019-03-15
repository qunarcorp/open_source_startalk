#include "gloableeventobject.h"
GloableEventObject* GloableEventObject::pInstance = NULL;
GloableEventObject::GloableEventObject(QObject *parent)
    : QObject(parent)
{

}

GloableEventObject::~GloableEventObject()
{

}

GloableEventObject* GloableEventObject::getInstance()
{
    if (NULL == pInstance)
    {
        pInstance = new GloableEventObject(NULL);
    }
    return pInstance;
}
