#include "draggablewebview.h"

DraggableWebView::DraggableWebView(QWidget *parent)
    : webview(parent)
{
    ui.setupUi(this);
    setAcceptDrops(false);
}

DraggableWebView::~DraggableWebView()
{

}



void DraggableWebView::dragEnterEvent(QDragEnterEvent* event)
{
    DraggableWebView *source =
        qobject_cast<DraggableWebView *>(event->source());
    if (source && source == this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DraggableWebView::dragMoveEvent(QDragMoveEvent* event)
{
    DraggableWebView *source =
        qobject_cast<DraggableWebView *>(event->source());
    if (source && source == this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}


void DraggableWebView::mouseMoveEvent(QMouseEvent* event)
{
    webview::mouseMoveEvent(event);

//     if (event->buttons() & Qt::LeftButton) {
//         int distance = (event->pos() - startDragPos).manhattanLength();
//         if (distance >= 2)
//         {
//             QWebHitTestResult result = this->page()->hitTestContent(startDragPos);
//             QUrl url =result.imageUrl();
//             QString str = url.url();
//             if (!str.isEmpty())
//             {
//                 startDragImage(str);
//             }
//         }
//     }
}

void DraggableWebView::mousePressEvent(QMouseEvent* event)
{
    QPoint pos = event->pos();
    startDragPos = pos;
    pdata = new QMimeData();
    pdrag = new QDrag(this);
    pdrag->setMimeData(pdata);

    webview::mousePressEvent(event);
}


void DraggableWebView::startDragImage(const QString& imagePath)
{
    pdata->setText(imagePath);
    pdrag->start(Qt::MoveAction);
}