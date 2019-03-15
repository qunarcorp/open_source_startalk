#ifndef ACTIONCOMMAND_H
#define ACTIONCOMMAND_H

#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

 enum ActionType { drawNotSet,drawRectangle,drawEllipse,drawPen,drawText,drawArror };

class ActionCommand : public QObject
{
    Q_OBJECT
    enum DrawState { drawInit,drawBegin,drawGoing,drawEnd };

public:
    ActionCommand(const QColor& color, int fontSize, int brushSize);
	void setdeviceRadio(int Radio) { m_Radio = Radio; };

    virtual void excute(QPainter& painter);
    virtual void undo(QPainter& painter);

    // 绘制事件必须的父控件事件
    virtual void mousePressEvent(QMouseEvent *);
    virtual bool mouseReleaseEvent(QMouseEvent *, QWidget* parent = NULL,bool forcesave=false);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *, QPaintDevice* , QPainter* painter, QWidget*);


    // encapslute fied
    ActionType Type() const { return m_Type; }
    void Type(ActionType val) { m_Type = val; }
    QPixmap LastPixmap() const { return m_lastPixmap; }
    void LastPixmap(QPixmap val) { m_lastPixmap = val; }
    QPixmap CurrentPipxmap() const { return m_currentPipxmap; }
    void CurrentPipxmap(QPixmap val) { m_currentPipxmap = val; }
    QRect TargetRect() const { return m_targetRect; }
    void TargetRect(QRect val) { m_targetRect = val; }

private:
    QRect      m_targetRect;    // 动作的目标区域
    QPixmap    m_lastPixmap;    // 动作开始前的页面快照
    QPixmap    m_currentPipxmap;// 动作完成后的页面快照
    ActionType m_Type;          // 动作类型
    QColor     m_color;
    int        m_penSize;
    int        m_fontSize;
	int        m_Radio;
private:
    QSharedPointer<QPoint> m_spBeginPoint;
    QSharedPointer<QPoint> m_spEndPoint;
    QList<QSharedPointer<QPoint>>m_lstPenPoints;
    QRect m_drawRect;
    DrawState _drawState;

    
};


#endif // ACTIONCOMMAND_H
