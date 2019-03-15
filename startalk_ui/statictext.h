#ifndef STATICTEXT_H
#define STATICTEXT_H

#include <QLineEdit>
class StaticText : public QLineEdit
{
    Q_OBJECT

public:
    StaticText(QWidget *parent = 0);
    ~StaticText();

    // ! 将QLineEdit的方法隐藏了
    void setText(const QString& text);

    virtual void mouseDoubleClickEvent(QMouseEvent *);

};

#endif // TITLEBARWIDGET_H
