#include "DisplayTextBrowser.h"
#include <QMouseEvent>

DisplayTextBrowser::DisplayTextBrowser(QWidget *parent)
    : QTextBrowser(parent)
{

}

DisplayTextBrowser::~DisplayTextBrowser()
{

}

void DisplayTextBrowser::mouseDoubleClickEvent( QMouseEvent *e )
{
    emit sgMouseDoubleClicked();
    QTextBrowser::mouseDoubleClickEvent(e);
}
void DisplayTextBrowser::mousePressEvent( QMouseEvent *e )
{
     if( e->button() == Qt::LeftButton ) {
         emit sgMouseClicked();
     } 
    QTextBrowser::mousePressEvent(e);
}