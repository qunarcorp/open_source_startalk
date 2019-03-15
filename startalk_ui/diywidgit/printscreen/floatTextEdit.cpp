#include "floatTextEdit.h"
#include <QDebug>
#include <QScrollBar>
QString floatTextEdit::sStyle = QString(
    "QScrollBar:vertical"
    "{"
        "height: 12px;"
        "margin: 0px 0px 0px 0px;" 
        "border-style: dotted;"
        "border-color: black;"
    "}"
    "QTextEdit"
    "{"
        "background-color: rgba(0,0,0,0);"
        "border-width: 2px;"
        "border-color: #3D74BB;" 
        "border-style: dashed;"
    "}"
    );


int floatTextEdit::wOffset = 20;
int floatTextEdit::hOffset = 14;

floatTextEdit::floatTextEdit(QWidget *parent)
    : QTextEdit(parent)
{

}

floatTextEdit::~floatTextEdit()
{

}

void floatTextEdit::InitWidget()
{
    setStyleSheet(sStyle);
    connect(this,&floatTextEdit::textChanged,this,&floatTextEdit::onTextChangeSlot);
    resize(0,0);
    setText(QString(""));
}

bool floatTextEdit::ShowOrHideEditWidget(const QRect& rect ,const QPoint& p)
{
    if (isHidden() )
    {
        posPoint = p;
        posRectLimited = rect;
        // 当前是隐藏的，或者不是隐藏的却没有焦点（新创建出来）
        InitWidget();
        setFocus();
        move(p);
        show();
    }
    else
    {
        hide();
        clearFocus();
    }

    return this->isVisible();
}

void floatTextEdit::focusOutEvent(QFocusEvent *e)
{
    QTextEdit::focusOutEvent(e);

    emit sgTextInputComplete(this->toPlainText());
}


void floatTextEdit::onTextChangeSlot()
{
    int lw = rect().width();
    int lh = rect().height();

    int w,h;
    calculateWH(w,h);
   
    updateGeometry();
    if (w!=0 && h!=0)
    {
        resize(w,h);
    } 
}

void floatTextEdit::calculateWH(int& width, int& height)
{
    if (!posRectLimited.contains(posPoint))
    {
        width = 0;
        height = 0;
        return;
    }

    int tW,tH;
    QRect textRect = this->rect();

    // 计算宽度
    QString strContent = this->toPlainText();
    tW = this->fontMetrics().width(strContent);
    int twoffset = posRectLimited.right()-this->rect().right() - posPoint.x();
    if (twoffset<=0) 
    {
        width = posRectLimited.right()-this->rect().left() - posPoint.x() +1;
    }
    else
    {
        width = tW + (twoffset>wOffset ? wOffset : twoffset);
    }

    //计算高度
    tH = this->document()->size().height();
    int tHoffset = posRectLimited.bottom()-this->rect().bottom() - posPoint.y();

    if (tHoffset <= 0)
    {
         height = posRectLimited.bottom()-this->rect().top() - posPoint.y()+1;
    } 
    else
    {
        // 末行第一个字符，新创建的行
        if (rect().height() <= this->document()->size().height()) 
        {
            height = tH + (tHoffset > hOffset ? hOffset : tHoffset);
        }
        else
        {
            height = rect().height();
        }
         
    } 
}
