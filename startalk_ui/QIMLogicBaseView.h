#pragma once
#include "LocalManDialog.h"
#include "localmanwidget.h"
namespace Biz{
    class CallbackReceiver;
}
class QIMLogicDialog : public LocalManDialog
{
    Q_OBJECT
public:
    QIMLogicDialog(QWidget* parent);
    ~QIMLogicDialog(void);
protected:
    Biz::CallbackReceiver* m_callbackReceiver;
};

