#include "Mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent)
	: QComboBox(parent)
{

}

MyComboBox::~MyComboBox()
{

}

void MyComboBox::wheelEvent(QWheelEvent *e)
{
    return QWidget::wheelEvent(e);
}