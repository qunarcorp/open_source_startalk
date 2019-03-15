#ifndef FLOATTEXTEDIT_H
#define FLOATTEXTEDIT_H

#include <QTextEdit>

class floatTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    floatTextEdit(QWidget *parent);
    ~floatTextEdit();

    void InitWidget();
    bool ShowOrHideEditWidget(const QRect& rect ,const QPoint& p);
    void calculateWH(int& width, int& height);
    QPoint LeftTopPoint() {return posPoint;}

    virtual void focusOutEvent(QFocusEvent *e);

protected Q_SLOTS:
        void onTextChangeSlot();
signals:
        void sgTextInputComplete(const QString&);

private:
    static QString sStyle;
    static int wOffset;
    static int hOffset;
    QPoint posPoint;
    QRect  posRectLimited;
};

#endif // FLOATTEXTEDIT_H
