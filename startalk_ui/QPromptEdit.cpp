#include "QPromptEdit.h"

QPromptEdit::QPromptEdit(QWidget *parent)
    : QLineEdit(parent)
{    
    mOldMode = EchoMode(-1);
    connect(this, &QPromptEdit::textChanged, this, &QPromptEdit::onChanged);
}

QPromptEdit::~QPromptEdit()
{

}
void QPromptEdit::onChanged(const QString & text)
{
   if(text.length() > 0)   
   {
       if( mOldStyle.length() > 0)
            setStyleSheet(mOldStyle);
       if(  (int)mOldMode > 0)
        setEchoMode(mOldMode);
   }
   
}
void QPromptEdit::setPrompt(const QString& str, const QString& style)
{
    mPromptStr = str;
    mPromptStyle = style;

    if(text().length() == 0 && mPromptStr.length() > 0)
    {
        setText(mPromptStr);       
        if(mOldStyle.isNull())       
            mOldStyle = this->styleSheet();
        if(  (int)mOldMode == -1)
            mOldMode = this->echoMode();
        setEchoMode(QLineEdit::Normal);
        setStyleSheet(mPromptStyle);
    }
}
void QPromptEdit::focusInEvent(QFocusEvent * e)
{        
    if(this->text() == mPromptStr)
    {

        setText("");
    }
    QLineEdit::focusInEvent(e);
}
void QPromptEdit::focusOutEvent(QFocusEvent * e)
{

    if(text().length() == 0 && mPromptStr.length() > 0 )
    {
        setText(mPromptStr);       
        if(mOldStyle.isNull())       
            mOldStyle = this->styleSheet();           
        if((int)mOldMode == -1)
            mOldMode = this->echoMode();
        setEchoMode(QLineEdit::Normal);
        setStyleSheet(mPromptStyle);
    }
    QLineEdit::focusOutEvent(e);
}
// void QPromptEdit::keyPressEvent(QKeyEvent * event)
// {
//     QLineEdit::keyPressEvent(event);
// }

QClearableEdit::QClearableEdit(QWidget *parent)
    : QLineEdit(parent)
{

}

QClearableEdit::~QClearableEdit()
{

}

void QClearableEdit::focusInEvent(QFocusEvent * e)
{
    setClearButtonEnabled(true);
    QLineEdit::focusInEvent(e);
}

void QClearableEdit::focusOutEvent(QFocusEvent * e)
{
    setClearButtonEnabled(false);
    QLineEdit::focusOutEvent(e);
}
