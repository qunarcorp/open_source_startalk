#ifndef DRAGGABLEWEBVIEW_H
#define DRAGGABLEWEBVIEW_H

#include "webview.h"
#include "ui_draggablewebview.h"
#include "WebPage.h"
//#include <QWebFrame>
//#include <QWebHitTestResult>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

class DraggableWebView : public webview
{
    Q_OBJECT

public:
    DraggableWebView(QWidget *parent = 0);
    ~DraggableWebView();

    virtual void dragEnterEvent(QDragEnterEvent*);
    virtual void dragMoveEvent(QDragMoveEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mousePressEvent(QMouseEvent*);
    void startDragImage(const QString& imagePath);

private:
    Ui::DraggableWebView ui;
    QPoint startDragPos;
    QMimeData* pdata;
    QDrag* pdrag;
};

#endif // DRAGGABLEWEBVIEW_H
