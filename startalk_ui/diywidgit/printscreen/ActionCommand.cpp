#include "ActionCommand.h"
#include <QDebug>
#include <QWidget>
#include <QTextEdit>
#include <functional>
#include "floatTextEdit.h"
#include "DrawTextDocumentHelper.h"
#include "SnipScreenTool.h"
#include "math.h"

ActionCommand::ActionCommand(const QColor& color, int fontSize, int brushSize)
{
    m_spBeginPoint.reset();
    m_spEndPoint.reset();

    _drawState = drawInit;

    m_penSize = brushSize;
    m_color = color;
    m_fontSize = fontSize;

	m_Radio = 1;
}

void ActionCommand::excute(QPainter& painter)
{
}

void ActionCommand::undo(QPainter& painter)
{

}

void ActionCommand::mousePressEvent(QMouseEvent * e)
{
    QPoint p = e->pos();
	QRect targetRect = m_targetRect;
	targetRect.setX(targetRect.x() / m_Radio);
	targetRect.setY(targetRect.y() / m_Radio);
	targetRect.setWidth(targetRect.width() / m_Radio);
	targetRect.setHeight(targetRect.height() / m_Radio);

    if (!targetRect.contains(e->pos()))
    {
        // 起点不在方框内部，不处理
        return;
    }
    if (_drawState==drawInit)
    {
        QPoint pt = e->pos();
		
        m_spBeginPoint.reset(new QPoint(pt.x(),pt.y()));
        _drawState = drawBegin;
    }

    m_lstPenPoints.push_back(m_spBeginPoint);
}

void ActionCommand::mouseMoveEvent(QMouseEvent * e)
{
    // 看看是不是移动到外面去了
    if (_drawState==drawBegin||_drawState==drawGoing)
    {
        _drawState = drawGoing;

        QPoint p = e->pos();
        int x,y;
        do 
        {
            if (p.x() < m_targetRect.left()/m_Radio) {x = m_targetRect.left()/m_Radio;break;}
            if (p.x() > m_targetRect.right()/m_Radio) {x = m_targetRect.right()/m_Radio;break;}
            x = p.x();
        } while (0);

        do 
        {
            if (p.y() < m_targetRect.top()/m_Radio) {y = m_targetRect.top()/m_Radio;break;}
            if (p.y() > m_targetRect.bottom()/m_Radio) {y=m_targetRect.bottom()/m_Radio;break;}
            y = p.y();
        } while (0);

        m_spEndPoint.reset(new QPoint(x,y));

        m_drawRect = QRect(*m_spBeginPoint.data(),*m_spEndPoint.data());
        

        m_lstPenPoints.push_back(QSharedPointer<QPoint>(new QPoint(x,y)));
    }
}

bool ActionCommand::mouseReleaseEvent(QMouseEvent * e, QWidget* parent,bool forcesave)
{
    // 如果不是画文本，则不判定有效区域
    if (m_Type!=drawText && (m_spBeginPoint.data()==NULL || m_spEndPoint.data()==NULL))
    {
        // 无效区域
        _drawState = drawInit;
        m_spBeginPoint.reset();
        m_spEndPoint.reset();
        return false;
    }

    if (m_Type==drawText && (!forcesave&&m_spBeginPoint.data()==NULL))
    {
        // 无效区域
        _drawState = drawInit;
        m_spBeginPoint.reset();
        m_spEndPoint.reset();
        return false;
    }

    if (drawRectangle==m_Type || drawEllipse == m_Type)
    {
         m_drawRect = QRect(*m_spBeginPoint.data(),*m_spEndPoint.data());

    }

    bool bNeedPushStack = true;
    _drawState = drawEnd;


    // 区域有效说明是拖拽，拖拽结束，在画布上画下最终的数据

  QPixmap tempPixmap = m_lastPixmap;
 
    switch (m_Type)
    {
    case drawRectangle:
        {
            QPainter p(&tempPixmap);
            p.setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            QRect rect(*m_spBeginPoint.data(),*m_spEndPoint.data());
            rect.moveTopLeft(QPoint(rect.x()-m_targetRect.x()/m_Radio,rect.y()-m_targetRect.y() / m_Radio));
            p.drawRect(rect);
        }
        break;
    case drawEllipse:
        {
            QPainter p(&tempPixmap);
            QRect rect(*m_spBeginPoint.data(),*m_spEndPoint.data());
            p.setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            rect.moveTopLeft(QPoint(rect.x()-m_targetRect.x()/m_Radio,rect.y()-m_targetRect.y()/m_Radio));
            p.drawEllipse(rect);
        }
        break;
    case drawText:
        {
            floatTextEdit* pEdit = SnipScreenTool::getInstance()->getTextEdit();
            if (!pEdit->ShowOrHideEditWidget(m_targetRect,*m_spBeginPoint.data())) 
            {
                QString strContent = pEdit->toPlainText();
                QPainter p(&tempPixmap);
                QPoint piLeftTop = pEdit->LeftTopPoint();
                QRect rect(piLeftTop.x(),piLeftTop.y(),pEdit->rect().width(),pEdit->rect().height());
                rect.moveTopLeft(QPoint(rect.x()-m_targetRect.x()/m_Radio+2,rect.y()-m_targetRect.y() / m_Radio +2)); // 边框有1像素，修一下
                DrawTextDocumentHelper::drawDocument(&p,pEdit->document(),rect,QBrush(m_color));
            }
            else
            {
                bNeedPushStack = false;
            }
        }
        break;
    case  drawPen:
        {
            QPainter p(&tempPixmap);
            QRect rect(*m_spBeginPoint.data(),*m_spEndPoint.data());
            p.setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
           // rect.moveTopLeft(QPoint(rect.x()-m_targetRect.x(),rect.y()-m_targetRect.y()));

            for (int i=0;i<m_lstPenPoints.size()-1;i++)
            {
                QPoint p1 = *m_lstPenPoints[i].data();
                QPoint p2 = *m_lstPenPoints[i+1].data();
                p1 = QPoint(p1.x()-m_targetRect.x() / m_Radio,p1.y()-m_targetRect.y() / m_Radio);
                p2 = QPoint(p2.x()-m_targetRect.x() / m_Radio,p2.y()-m_targetRect.y() / m_Radio);
                if (!p1.isNull()&&!p2.isNull())
                {
                    p.drawLine(p1,p2);
                }
            }
            break;
        }
    case drawArror:
        {
            QPainter p(&tempPixmap);
            QPointF pBegin = QPointF(m_spBeginPoint->x()-m_targetRect.x() / m_Radio,m_spBeginPoint->y()-m_targetRect.y() / m_Radio);
            QPointF pEnd = QPointF(m_spEndPoint->x()-m_targetRect.x() / m_Radio,m_spEndPoint->y()-m_targetRect.y() / m_Radio);

            const qreal angleSize = 4;

            qreal distanceY = pEnd.y() - pBegin.y(); // 正负自适应
            qreal distanceX = pEnd.x() - pBegin.x();
            qreal distanceXY = sqrt(distanceY*distanceY + distanceX*distanceX);

            QPointF pMid,pLeft,pRight;
            pMid.setY(pBegin.y()+(distanceXY-angleSize)*distanceY/distanceXY);
            pMid.setX(pBegin.x()+(distanceXY-angleSize)*distanceX/distanceXY);

            pRight.setX(pMid.x() + (angleSize*distanceY/distanceXY));
            pRight.setY(pMid.y() - (angleSize*distanceX/distanceXY));

            pLeft.setX(pMid.x() - (angleSize*distanceY/distanceXY));
            pLeft.setY(pMid.y() + (angleSize*distanceX/distanceXY));
            
            
            p.setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            p.drawLine(pBegin,pMid);
            QPointF p3[] = {pEnd,pRight,pLeft};
            p.drawPolygon(p3,3);
        }
        break;
    default:
        break;
    }

    m_currentPipxmap = tempPixmap;

    _drawState = drawInit;

    m_spBeginPoint.reset();
    m_spEndPoint.reset();

    return bNeedPushStack;
}



void ActionCommand::paintEvent(QPaintEvent * e, QPaintDevice* parent, QPainter* painter, QWidget* pps)
{
    if (_drawState==drawInit || _drawState==drawBegin)
    {
        return;
    }
    
    // 界面画图
   // bool b = painter->begin(parent);
    bool b = painter->begin((QPaintDevice*)pps);
    switch (m_Type)
    {
    case drawRectangle:
        {
            painter->setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            painter->drawRect(m_drawRect);
        }
        break;
    case drawEllipse:
        {
            painter->setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            painter->drawEllipse(m_drawRect);
        }
        break;
    case drawText:
        {
        }
        break;
    case drawPen:
        {
            if (m_lstPenPoints.size()>1)
            {
                painter->setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
                for (int i=0;i<m_lstPenPoints.size()-1;i++)
                {
                    QPoint p1 = *m_lstPenPoints[i].data();
                    QPoint p2 = *m_lstPenPoints[i+1].data();
                    if (!p1.isNull()&&!p2.isNull())
                    {
                        painter->drawLine(p1,p2);
                    }
                }
            }
        }
        break;
    case drawArror:
        {
            const qreal angleSize = 4;

            qreal distanceY = m_spEndPoint->y() - m_spBeginPoint->y(); // 正负自适应
            qreal distanceX = m_spEndPoint->x() - m_spBeginPoint->x();
            qreal distanceXY = sqrt(distanceY*distanceY + distanceX*distanceX);

            QPointF pMid,pLeft,pRight;
            pMid.setY(m_spBeginPoint->y()+(distanceXY-angleSize)*distanceY/distanceXY);
            pMid.setX(m_spBeginPoint->x()+(distanceXY-angleSize)*distanceX/distanceXY);

            pRight.setX(pMid.x() + (angleSize*distanceY/distanceXY));
            pRight.setY(pMid.y() - (angleSize*distanceX/distanceXY));

            pLeft.setX(pMid.x() - (angleSize*distanceY/distanceXY));
            pLeft.setY(pMid.y() + (angleSize*distanceX/distanceXY));
            
            
            painter->setPen(QPen(QBrush(m_color),m_penSize,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
            painter->drawLine(*m_spBeginPoint.data(),pMid);
            QPointF p[] = {*m_spEndPoint.data(),pRight,pLeft};
            painter->drawPolygon(p,3);
        }
        break;
    default:
        break;
    }
    painter->restore ();
    painter->end();
    
}