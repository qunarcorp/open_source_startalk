#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>

class MySpinBox : public QSpinBox
{
	Q_OBJECT

public:
	MySpinBox(QWidget *parent);
	~MySpinBox();
	virtual void wheelEvent(QWheelEvent *event);
private:
	
};

#endif // MYSPINBOX_H
