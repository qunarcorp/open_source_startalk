#ifndef DISPLAYTEXTBROWSER_H
#define DISPLAYTEXTBROWSER_H

#include <QTextBrowser>

class QMouseEvent;
class DisplayTextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    DisplayTextBrowser(QWidget *parent);
    ~DisplayTextBrowser();

    virtual void mouseDoubleClickEvent( QMouseEvent *e );
    virtual void mousePressEvent( QMouseEvent *e );
signals:
    void sgMouseDoubleClicked();
    void sgMouseClicked();
private:
    
};

#endif // DISPLAYTEXTBROWSER_H

