#include "singleprogresobject.h"
#ifdef _LINUX
#include "singleprogress_adaptor.h"
#include "singleprogress_interface.h"
#endif // _LINUX



#include <QMessageBox>
#include "UIFrame.h"
#include "MainDialogController.h"
#include "SystemIcon.h"

SingleProgresObject::SingleProgresObject(QObject *parent) : QObject(parent)
{
}

SingleProgresObject::~SingleProgresObject()
{

}

#ifdef _LINUX
void SingleProgresObject::setupQBus(QDBusConnection connection)
{
    new SingleprogressAdaptor(this);
    connection.registerObject("/", this);

    org::qim::singleprogress *Iface
        = new org::qim::singleprogress(QString(), QString(), connection,this);
    connection.connect(QString(), QString(), "org.qim.singleprogress","showwindows",this,SLOT(onShowWindows()));
}
#endif // _LINUX



void SingleProgresObject::onShowWindows()
{
    emit SystemIcon::instance().sgDoubleClick();
}

