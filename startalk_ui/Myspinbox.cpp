#include "Myspinbox.h"

MySpinBox::MySpinBox(QWidget *parent)
	: QSpinBox(parent)
{

}

MySpinBox::~MySpinBox()
{

}

void MySpinBox::wheelEvent(QWheelEvent *event)
{
    return QWidget::wheelEvent(event);
}