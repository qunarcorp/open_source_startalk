#ifndef QFRAMELAYOUT_H
#define QFRAMELAYOUT_H

#include <QLayout>
class QFrameLayoutPrivate;

enum AlinementPolicy
{
    ALINE_TOP = 1,
    ALINE_RIGHT = 2,
    ALINE_BOTTOM = 4,
    ALINE_LEFT = 8,
    ALINE_MATCHWIDTH = 10, // right+left
    ALINE_MATCHHEIGHT = 5, // top + bottom
    ALINE_FILL = 15,       // r+l+t+b 
    ALINE_TOPLEFT = 9,      // l+t
    ALINE_HCENTER = 16,
    ALINE_VCENTER = 32
};

class QFrameLayout : public QLayout
{
    Q_OBJECT
public:
    QFrameLayout(QWidget *parent);
    ~QFrameLayout();

    void appendWidget(QWidget* widget,int aline = ALINE_TOPLEFT,QMargins margins = QMargins());
    QWidget* takeWidget(QWidget* widget);
    QWidget* takeIndex(int index); 

    void setContentsMargins(int left, int top, int right, int bottom);

    virtual QSize sizeHint() const;

    virtual QSize minimumSize() const;

    virtual QSize maximumSize() const;

    virtual void setGeometry(const QRect&);

    bool isEmpty() const;

private:
    // 隐藏 void QLayout::addWidget(QWidget * w)
    void addWidget(QWidget * w){};

    virtual void addItem(QLayoutItem *);

    virtual QLayoutItem * itemAt(int index) const;

    virtual QLayoutItem * takeAt(int index);

    virtual int count() const;
    
private:
    QFrameLayoutPrivate* d;
};

#endif // QFRAMELAYOUT_H
