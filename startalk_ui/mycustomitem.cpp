#include "mycustomitem.h"


myCustomItem::myCustomItem(QWidget *parent)
	: QWidget(parent)
{
	hBoxLayout = new QHBoxLayout();
	hBoxLayout->addWidget(&this->icon);
	hBoxLayout->addWidget(&this->text);
	hBoxLayout->setSpacing(1);
	this->setContentsMargins(1, 1, 1, 1);
	this->setLayout(hBoxLayout);
	//this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
}

myCustomItem::~myCustomItem()
{
	if (hBoxLayout)
	{
		delete hBoxLayout;
		hBoxLayout = NULL;
	}
}

void myCustomItem::setText(const QString&strtext)
{
	this->text.setText(strtext);
	this->icon.setStyleSheet(QStringLiteral("background-color:#000fff;"));
}
void myCustomItem::setIcon(const QIcon&ico)
{
	this->icon.setStyleSheet(QStringLiteral("background-color:#FFF000;"));
	//QPixmap pixmap(ico);
	//this->icon.setPixmap(pixmap);


}
