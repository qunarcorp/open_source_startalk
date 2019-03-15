#ifndef DRAWTEXTDOCUMENTHELPER_H
#define DRAWTEXTDOCUMENTHELPER_H
#include <QPainter>
#include <QTextDocument>
#include <QTextCharFormat>
class DrawTextDocumentHelper
{
public:
    DrawTextDocumentHelper();
    ~DrawTextDocumentHelper();
public:
    // 绘制QTextDocument中的指定区域
    static void drawDocument(QPainter* painter, 
        const QTextDocument* doc,
        const QRectF& r,
        const QBrush& brush = Qt::NoBrush/*brush to draw all content.used for shadow draw*/);
private:
    // 绘制Block及其内容
    static void drawTextLayout(QPainter* painter, 
        const QTextBlock& block, 
        const QSizeF& sizeToFill,
        const QBrush& brush);
    // 绘制文本及其内外边
    static void drawText(QPainter* painter, 
        QPointF& p, 
        QString& text, 
        const QTextCharFormat& fmt,  
        const QBrush& brush);
    static qreal alignPos(Qt::Alignment a, 
        const qreal& width, 
        const qreal& textWidth);
    static bool needDrawText(const QTextCharFormat& chf);
    static void clearLetterSpacing(QTextDocument* doc, int* blockNum = NULL);
    static void adjustAlignJustify(QTextDocument* doc, qreal DocWidth, int* blockNum = NULL);

};

#endif // DRAWTEXTDOCUMENTHELPER_H
