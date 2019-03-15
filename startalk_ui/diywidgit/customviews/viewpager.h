#ifndef VIEWPAGER_H
#define VIEWPAGER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QMovie>
#include <QTimeLine>
#include "slidingstackedwidget.h"
#include <QButtonGroup>
#include <QHBoxLayout>
namespace Biz {
	class AdvDataItem;
}

class IViewPageAdapter : public QObject {
public:
    IViewPageAdapter(QObject* parent):QObject(parent){};
    virtual ~IViewPageAdapter(){};
public:
    virtual QWidget* createNewWidget(QWidget* parent, int index) = 0;
    virtual int      count() = 0;
    virtual void     setupData(QWidget* pWidget,int index) = 0;
};
class ViewPager : public QWidget
{
	Q_OBJECT

public:
	ViewPager( QWidget *parent=NULL);
	~ViewPager();
    ViewPager*  setAdapter(IViewPageAdapter* adapter);
    ViewPager*  setTimeHolder(int secends); // 0 is no scroll
    ViewPager*  setIndicatorVisible(bool enable);
    void        startUp();

private:
    void switchWidget(int index);
	void setBtnChecked(int index);
	void createIndicators();
private:
    IViewPageAdapter* pAdapter;
	QWidget*        mbtntool; //这上面是放按钮的
    QButtonGroup*   m_pButtonGroup;
    QHBoxLayout*    m_pIndicatorsLayout;
	QTimeLine timeLine;             // 滚动计时器
	int mTmDix;                     // 滚动间隔
    SlidingStackedWidget* pages;    //滚动容器

    bool    mbtnShow;
    const static int sIndicatorSize;
private slots:
    void onBtnClicked(int);
};

#endif // VIEWPAGER_H
