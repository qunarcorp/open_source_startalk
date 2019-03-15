#ifndef LOCALMANWIDGET_H
#define LOCALMANWIDGET_H

#include <QWidget>
class QSizeGrip;

namespace Biz{
    class CallbackReceiver;
}
class LocalManWidget  : public QWidget
{
public:
    LocalManWidget(QWidget *parent);
    ~LocalManWidget();
    virtual void mousePressEvent( QMouseEvent * );
    virtual void mouseReleaseEvent( QMouseEvent * );
    virtual void mouseMoveEvent( QMouseEvent * );
    virtual bool event(QEvent* e);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void windowMove(const QPoint& pos);
    void setSizeGripEnabled(bool enabled);

    void autoFlash();
    void stopFlash();

    void setMoveable(bool b) {m_moveable = b;};
protected:
    void resizeEvent(QResizeEvent * e);
   
public slots:
    void onMin(bool);
    void onMax(bool);
    void onClose(bool);

    virtual bool eventFilter(QObject *, QEvent *);

    virtual void paintEvent(QPaintEvent *);

private:
    QPoint m_gDragPos;
    QPoint m_rawPos;
    bool m_tracked;
    QSize m_normalSize;
    bool m_moveable;
    QSizeGrip *resizer;
protected:
    Biz::CallbackReceiver* mReceiver;

};

#endif // LOCALMANWIDGET_H
