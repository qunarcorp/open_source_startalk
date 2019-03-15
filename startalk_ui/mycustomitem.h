#ifndef MYCUSTOMITEM_H
#define MYCUSTOMITEM_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QIcon>

class myCustomItem : public QWidget
{
	Q_OBJECT

public:
	myCustomItem(QWidget *parent = 0);
	~myCustomItem();

	void setText(const QString&strtext);
	void setIcon(const QIcon&ico);


private:
	QLabel icon;
	QLabel text;
	QHBoxLayout *hBoxLayout;
};

#endif // MYCUSTOMITEM_H
