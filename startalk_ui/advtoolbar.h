#ifndef ADVTOOLBAR_H
#define ADVTOOLBAR_H

#include <QWidget>
#include "ui_AdvToolbar.h"
class ViewPager;

namespace Biz
{
	class AdvDataItem;
}

class AdvToolbar : public QWidget
{
	Q_OBJECT

public:
	AdvToolbar(QWidget *parent=NULL);
	~AdvToolbar();
public:
    void setCloseable(bool b);
    void showAllPicture(const QList <QSharedPointer<Biz::AdvDataItem>> & picpathlist);
private slots:
	
	void onBtnClose();
private:
	Ui::AdvToolbar *ui;
	ViewPager *mvwImage;
};

#endif // ADVTOOLBAR_H
