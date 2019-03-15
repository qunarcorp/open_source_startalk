#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>

class MyComboBox : public QComboBox
{
	Q_OBJECT

public:
	MyComboBox(QWidget *parent);
	~MyComboBox();
	virtual void wheelEvent(QWheelEvent *e);
private:
	
};

#endif // MYCOMBOBOX_H
