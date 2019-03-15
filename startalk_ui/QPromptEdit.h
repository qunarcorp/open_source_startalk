#ifndef QPROMPTEDIT_H
#define QPROMPTEDIT_H

#include <QLineEdit>

class QPromptEdit : public QLineEdit
{
    Q_OBJECT

public:
    QPromptEdit(QWidget *parent);
    ~QPromptEdit();
    void setPrompt(const QString& str, const QString& style);
private:
    void onChanged(const QString & text);
    QString mPromptStr;    
    QString mPromptStyle;    
    QString mOldStyle;
    EchoMode mOldMode;    
protected:
     void focusInEvent(QFocusEvent * e);
     void focusOutEvent(QFocusEvent * e);
     //void keyPressEvent(QKeyEvent * event);

};


class QClearableEdit : public QLineEdit
{
    Q_OBJECT
public:
    QClearableEdit(QWidget *parent);
    ~QClearableEdit();
protected:
    void focusInEvent(QFocusEvent * e);
    void focusOutEvent(QFocusEvent * e);
};

#endif // QPROMPTEDIT_H
