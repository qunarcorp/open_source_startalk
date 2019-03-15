#include "viewpager.h"
#include "qframelayout.h"
#include "../LocalManBiz/AdvData.h"
#include <QEvent>
#include <QDesktopServices>
#include <QUrl>


const QString btnStyle = 
	"QPushButton{"
    "border:1px solid #666666;"
			"border-radius:5px;"
			"background:#F5F5F5;"
			"}"
			"QPushButton:checked{"
			"background:#1ba9ba;"
			"}";


class ViewPageAdapterImp : public IViewPageAdapter
{
public:
    ViewPageAdapterImp(QObject* parent):IViewPageAdapter(parent){};
    ~ViewPageAdapterImp(){};

    virtual QWidget* createNewWidget(QWidget* parent, int index)
    {
        return NULL;
    }

    virtual int count()
    {
        return 0;
    }

    virtual void setupData(QWidget* pWidget,int index)
    {
    }

public:

};

const int ViewPager::sIndicatorSize = 10;
ViewPager::ViewPager( QWidget *parent)
	: QWidget(parent)
	, mTmDix(3)
	, mbtnShow(true)
    , mbtntool(new QWidget(this))
    , m_pButtonGroup(new QButtonGroup(this))
    , m_pIndicatorsLayout(new QHBoxLayout(mbtntool))
    , pages(new SlidingStackedWidget(this))
    , pAdapter(new ViewPageAdapterImp(this))
{
	QFrameLayout *pixLayout = new QFrameLayout(this);
    pixLayout->appendWidget(pages,ALINE_FILL);
	pixLayout->appendWidget(mbtntool,ALINE_HCENTER|ALINE_BOTTOM, QMargins(0, 0, 0, 5));

    pages->setSpeed(300);
    pages->setVerticalMode(false);
    

    connect(&timeLine,&QTimeLine::finished,[this](){
        int index = pages->currentIndex();
        int nextIndex  = (index+1)%pages->count();
        if (nextIndex != index)
        {
            switchWidget(nextIndex);
        }
    });

    m_pButtonGroup->setExclusive(true);
    connect(m_pButtonGroup,SIGNAL(buttonClicked(int)),this,SLOT(onBtnClicked(int)));

    m_pIndicatorsLayout->setContentsMargins(0,0,0,0);
    m_pIndicatorsLayout->setSpacing(3);
    mbtntool->setStyleSheet(btnStyle);
}

ViewPager::~ViewPager()
{

}

void ViewPager::createIndicators()
{
    for (QAbstractButton* pbtn : m_pButtonGroup->buttons())
    {
        m_pIndicatorsLayout->removeWidget(pbtn);
        m_pButtonGroup->removeButton(pbtn);
        pbtn->deleteLater();
    }

    for (int i=0; i< pAdapter->count(); i++)
    {
        QPushButton* pb = new QPushButton(mbtntool);
        pb->setCheckable(true);
        pb->setAutoExclusive(true);
        pb->setFlat(true);
        pb->setFixedSize(sIndicatorSize,sIndicatorSize);
        pb->show();
        m_pIndicatorsLayout->addWidget(pb);
        m_pButtonGroup->addButton(pb,i);
    }
    mbtntool->setFixedSize((sIndicatorSize+m_pIndicatorsLayout->spacing())*m_pButtonGroup->buttons().count() - m_pIndicatorsLayout->spacing(),sIndicatorSize);

    mbtntool->setVisible(mbtnShow);
}

void ViewPager::onBtnClicked(int index)
{
	timeLine.stop();
	switchWidget(index);
}


void ViewPager::setBtnChecked( int index )
{
    if (NULL!= m_pButtonGroup->button(index))
    {
        m_pButtonGroup->button(index)->setChecked(true);
    }
}




ViewPager* ViewPager::setTimeHolder(int secends)
{
    mTmDix = secends;
    timeLine.setDuration(mTmDix*1000);
    return this;
}

ViewPager* ViewPager::setIndicatorVisible(bool enable)
{
    mbtnShow = enable;
    return this;
}

void ViewPager::startUp()
{
    createIndicators();

    do 
    {
        if (pages->count()>0)
        {
            QWidget* pwidget = pages->currentWidget();
            pwidget->deleteLater();
            pages->removeWidget(pwidget);
        }
        else
        {
            break;
        }
    } while (true);

    for (int index=0; index<pAdapter->count(); index++)
    {
        QWidget* pWidget = pAdapter->createNewWidget(this,index);
        

        if (NULL!=pWidget)
        {
            pages->addWidget(pWidget);
        }
    }
  
    if (0 < pages->count())
    {
        switchWidget(0);
    }
}

void ViewPager::switchWidget(int index)
{
    if (this->pages->count() > index)
    {
        pages->slideInIdx(index,SlidingStackedWidget::RIGHT2LEFT);
        pAdapter->setupData(pages->widget(index),index);
        setBtnChecked(index);

        if (0<mTmDix)
        {
            timeLine.start();
        }
    }
}

ViewPager* ViewPager::setAdapter(IViewPageAdapter* adapter)
{
    pAdapter = adapter;
    return this;
}


