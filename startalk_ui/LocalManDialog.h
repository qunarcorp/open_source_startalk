#ifndef LOCALMANDIALOG_H
#define LOCALMANDIALOG_H

#include <QDialog>
#include <QSizeGrip>


class LocalManDialog : public QDialog
{
    Q_OBJECT
public:
    LocalManDialog(QWidget *parent);
    ~LocalManDialog();



    void autoFlash();
    void stopFlash();

    void setMoveable(bool b) {m_moveable = b;};
	void setSizeGripEnabled(bool enabled);
public slots:
    void onMin(bool);
    void onMax(bool);
    void onClose(bool);

    virtual bool eventFilter(QObject *, QEvent *);

protected:
	virtual void resizeEvent(QResizeEvent * e);
    virtual void mouseDoubleClickEvent( QMouseEvent * e );
    virtual void mousePressEvent( QMouseEvent * );
    virtual void mouseReleaseEvent( QMouseEvent * );
    virtual void mouseMoveEvent( QMouseEvent * );
    virtual bool event(QEvent* e);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    QPoint m_gDragPos;
    QPoint m_rawPos;
    bool m_tracked;
    QSize m_normalSize;
    bool m_moveable;
	QSizeGrip *resizer;
};


#endif // LOCALMANDIALOG_H
