#include "statictext.h"


StaticText::StaticText(QWidget *parent)
    : QLineEdit(parent)
{

}

StaticText::~StaticText()
{
}

void StaticText::setText(const QString& text)
{
    QLineEdit::setText(text);
    this->setCursorPosition(0);
}

void StaticText::mouseDoubleClickEvent(QMouseEvent *e)
{
    this->setSelection(0,text().length());
}
