#include "QIMLogicBaseView.h"
#include "CallbackReceiver.h"

QIMLogicDialog::QIMLogicDialog(QWidget* parent)
    : LocalManDialog(parent)
{
    m_callbackReceiver = new Biz::CallbackReceiver(this);
}

QIMLogicDialog::~QIMLogicDialog(void)
{

}
