#include "DrawTextDocumentHelper.h"
#include <QTextFrame>
#include <QTextLayout>

DrawTextDocumentHelper::DrawTextDocumentHelper()
{

}

DrawTextDocumentHelper::~DrawTextDocumentHelper()
{

}

// 第一步 绘制 Document
void DrawTextDocumentHelper::drawDocument(QPainter* painter, 
                  const QTextDocument* doc,
                  const QRectF& r,
                  const QBrush& brush)
{
    
    if(doc->isEmpty())
        return;

    painter->save();

    // 按区域绘制
    if (r.isValid())
        painter->setClipRect(r, Qt::IntersectClip);

    QSizeF size = doc->size();
    QTextFrameFormat fmt = doc->rootFrame()->frameFormat();
    size.setWidth(size.width() - fmt.leftMargin() - fmt.rightMargin());
    for (QTextBlock bl = doc->begin(); bl != doc->end(); bl = bl.next())
    {
        // 因为每个QTextDocument 中包含一个QTextLayout
        drawTextLayout(painter, bl, size , brush);
    }

    painter->restore();
}

//第二步 绘制 Layout 
void DrawTextDocumentHelper::drawTextLayout(QPainter* painter, const QTextBlock& block, const QSizeF& sizeToFill, const QBrush& brush)
{
    if (!block.isValid())
        return;
    QTextLayout* layout = block.layout();
    if(!layout)
        return;
    if (layout->lineCount() < 1)
        return;

    // 基线，每绘制一行则Y下移一行的位置，X不变
    QPointF baseLine = layout->position();
    baseLine.setY(baseLine.y() + layout->lineAt(0).ascent());

    // 输出位置，以基线Pos为基础，往右移动，每次换行，重置X位置
    QPointF outPos = baseLine;

    // QTextLayout 下一级是 QTextBlock..
    // QTextBlock 的下一级又是QTextFragment..
    QTextBlock::iterator it;
    for (it = block.begin(); !(it.atEnd()); ++it) 
    {	
        QTextFragment fragment = it.fragment();
        if (!fragment.isValid())
            continue;
        // 获取文本
        QString text = fragment.text();
        if (text.isEmpty())
            continue;
        // 获取文本格式
        QTextCharFormat chf = fragment.charFormat();
        int lineNoBegin = layout->lineForTextPosition(fragment.position() - block.position()).lineNumber();
        int lineNoEnd = layout->lineForTextPosition(fragment.position() + fragment.length() - 1 - block.position()).lineNumber();
        int j = fragment.position();
        for (int i = lineNoBegin; i <= lineNoEnd; i++)
        {
            QTextLine line = layout->lineAt(i);
            // 计算输出位置X
            qreal offset = alignPos(layout->textOption().alignment(), sizeToFill.width(), line.naturalTextWidth());
            outPos.setX(outPos.x() + offset);
            outPos.setY(baseLine.y());
            // 获取属于本行的文本
            QString textOnLine;
            while(j < fragment.position() + fragment.length())
            {
                int c = block.position();
                int d = line.textStart() + line.textLength();
                if (j < c + d)
                    textOnLine.append(text[j - fragment.position()]);
                else
                    break;
                j++;
            }
            // 绘制属于本行的Fragment中的文本
            drawText(painter, outPos, textOnLine, chf, brush);
            // 有换行的话，要更新BaseLine的Y及outPos的X
            if(i < lineNoEnd)
            {
                // 更新基线位置Y
                baseLine.setY(baseLine.y() + line.height());
                outPos.setX(baseLine.x());
            }
        }
    }
}

// 第三步 绘制文字
void DrawTextDocumentHelper::drawText(QPainter* painter, QPointF& p, QString& text, const QTextCharFormat& fmt,  const QBrush& brush)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::TextAntialiasing, true);
    QFont f = fmt.font();
    f.resolve(QFont::AllPropertiesResolved);

    // 获得第个文字的大小。。
    QFontMetricsF fm(f);
    QRectF textBoundingRect = fm.boundingRect(text);
    // draw text
    if(needDrawText(fmt) || brush.style() != Qt::NoBrush)
    {		
        painter->setFont(f);
        QPen pen;
        if(brush.style() == Qt::NoBrush)
        {
            QBrush t = fmt.foreground();
            if (t.style() == Qt::NoBrush)
                pen.setBrush(QBrush(QColor(255,255,255)));
            else if(t.style() != Qt::SolidPattern)
                pen = QPen(t,0);
            else
            {
                QColor c = t.color();
                QColor cc = c.toRgb();
                pen.setBrush(QBrush(cc));
            }
        }
        else
        {
            if (brush.style() != Qt::SolidPattern)
                pen = QPen(brush, 0);
            else
            {	
                pen.setBrush(brush);
            }
        }
        painter->setPen(pen);
        // draw text.
        QPointF limitedOPoint = painter->clipBoundingRect().topLeft();
        painter->drawText(p.x()+limitedOPoint.x(),p.y()+limitedOPoint.y(), text);
    }

    p += QPointF(textBoundingRect.width(), 0);
}
qreal DrawTextDocumentHelper::alignPos(Qt::Alignment a, const qreal& width, const qreal& textWidth)
{
    if(a & Qt::AlignRight)
        return  width - textWidth;
    else if(!(a & Qt::AlignLeft))
        return (width - textWidth) / 2;
    return 0;
}
bool DrawTextDocumentHelper::needDrawText(const QTextCharFormat& chf)
{
    return true;
}

void DrawTextDocumentHelper::clearLetterSpacing(QTextDocument* doc, int* blockNum)
{
    bool bAllBlock = !blockNum ? true : false;
    QVector<QTextBlock> blocks;
    if (bAllBlock)
    {
        for(QTextBlock block = doc->begin(); block != doc->end(); block = block.next())
            blocks.push_back(block);
    }
    else
    {
        blocks.push_back(doc->findBlockByNumber(*blockNum));
    }
    // 清空所有文字的字间距
    for(int idx = 0; idx < blocks.size(); idx++)	
    {
        QTextCursor cursor(blocks[idx]);
        for (int i = 0; i < blocks[idx].layout()->lineCount(); i++)
        {
            cursor.select(QTextCursor::LineUnderCursor);
            QTextCharFormat fmt;
            fmt.setFontLetterSpacing(100);
            cursor.mergeCharFormat(fmt);
            cursor.movePosition(QTextCursor::Down);
        }
    }
}
// 将QTextDocument中的指定Block置为发散对其方式，DocWidth为限定宽度,注意本函数会破坏原有的字符间距
void DrawTextDocumentHelper::adjustAlignJustify(QTextDocument* doc, qreal DocWidth, int* blockNum)
{
    // 清空文字的字间距
    clearLetterSpacing(doc, blockNum);
    // 获取要发散对其的Block
    bool bAllBlock = !blockNum ? true : false;
    QVector<QTextBlock> blocks;
    if (bAllBlock)
    {
        for(QTextBlock block = doc->begin(); block != doc->end(); block = block.next())
            blocks.push_back(block);
    }
    else
    {
        blocks.push_back(doc->findBlockByNumber(*blockNum));
    }
    // 获取Layout的Margin
    QTextFrameFormat frame = doc->rootFrame()->frameFormat();
    // 发散对齐,计算字间距
    for(int idx = 0; idx < blocks.size(); idx++)	
    {
        QTextCursor cursor(blocks[idx]);
        for (int i = 0; i < blocks[idx].layout()->lineCount(); i++)
        {
            QTextLine line = blocks[idx].layout()->lineAt(i);
            // 计算最后一个字的宽度
            cursor.setPosition(blocks[idx].position() + line.textStart() + line.textLength() - 1);
            cursor.setPosition(cursor.position() + 1, QTextCursor::KeepAnchor);
            QString text = cursor.selectedText();
            if (text.isEmpty())
            {
                cursor.movePosition(QTextCursor::Down);
                continue;
            }
            QFontMetricsF m(cursor.charFormat().font());
            qreal lastCharWidth = m.width(text[0]);
            // 	计算字符间距
            qreal widthOfLayout = DocWidth - (frame.leftMargin() + frame.rightMargin()) - lastCharWidth;
            qreal widthOfText = line.naturalTextRect().width() - lastCharWidth; 
            qreal percentOfSpacing = widthOfLayout / widthOfText * 100;
            if (percentOfSpacing > 100.0f)
            {
                // 选择第一个字到最后一个字的前一个字，设置这些字的字间距
                cursor.setPosition(blocks[idx].position());
                int pos = blocks[idx].position() + line.textStart() + line.textLength() - 1;
                cursor.setPosition(pos,  QTextCursor::KeepAnchor);
                QTextCharFormat fmt;
                fmt.setFontLetterSpacing(percentOfSpacing);
                cursor.mergeCharFormat(fmt);
            }
            cursor.movePosition(QTextCursor::Down);
        }
    }
}