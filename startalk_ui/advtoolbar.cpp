#include "advtoolbar.h"
#include <QDesktopServices>

#include "diywidgit/customviews/qframelayout.h"
#include "diywidgit/customviews/viewpager.h"
#include "AdvData.h"
#include "Session.h"
#include "advinformanager.h"
#include "diywidgit/imageloader/ImageLoader.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "jsonobject/adverconfiginfo.h"
#include "NotifyCenterController.h"


class WidgetUserData : public QObjectUserData
{
public:
    WidgetUserData():nIndex(0),bHasSetData(false){};
    virtual ~WidgetUserData(){};
    int nIndex;
    bool bHasSetData;
};


class AdvViewPagerAdapter : public IViewPageAdapter
{
public:
    AdvViewPagerAdapter(QObject* parent):IViewPageAdapter(parent){};
    ~AdvViewPagerAdapter(){};
    void setAdvDatas(const QList<QSharedPointer<Biz::AdvDataItem>>& datalist){datas = datalist;};

    virtual QWidget* createNewWidget(QWidget* parent, int index)
    {
        QSize size = parent->size();
        QLabel* pLabel = new QLabel(parent);
        pLabel->setGeometry(parent->geometry());
        pLabel->installEventFilter(this);
        WidgetUserData* pUserData = new WidgetUserData();
        pLabel->setUserData(Qt::UserRole,pUserData);
        return pLabel;
    }

    virtual int count()
    {
        return datas.size();
    }

    virtual void setupData(QWidget* pWidget,int index)
    {
        QLabel* pLabel = dynamic_cast<QLabel*>(pWidget);
        if (NULL != pLabel)
        {
            WidgetUserData* pUserdata = dynamic_cast<WidgetUserData*>(pWidget->userData(Qt::UserRole));
            if (NULL!=pUserdata && pUserdata->bHasSetData)
            {
                return;
            }


            QSharedPointer<Biz::AdvDataItem> spItem = datas.at(index);
            if (!spItem.isNull())
            {
                if (NULL==pLabel->pixmap())
                {
                    ImageLoaderSingleton::getInstance()->loadImage(
                        spItem->strImageLink
                        ,pLabel
                        ,""
                        , new FullSizeDecorate());
                }
             
            }
        }
    }

    virtual bool eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::MouseButtonDblClick 
            || event->type() == QEvent::MouseButtonPress)
        {
            QWidget* pwidget = dynamic_cast<QWidget*>(obj);
            widgetCliecked((pwidget));
            return true;
        }
        return QObject::eventFilter(obj,event);
    }
     void widgetCliecked(const QWidget* pWidget)
     {
         if (NULL!=pWidget)
         {
             WidgetUserData* pUserdata = dynamic_cast<WidgetUserData*>(pWidget->userData(Qt::UserRole));
             if (NULL!=pUserdata && count()>pUserdata->nIndex)
             {
                 QSharedPointer<Biz::AdvDataItem> spItem = datas.at(pUserdata->nIndex);
                 if (!spItem.isNull())
                 {
                     QDesktopServices::openUrl(QUrl(spItem->strImageLink));  
                 }
             }
         }
     }
private:
    QList<QSharedPointer<Biz::AdvDataItem>> datas;
};

AdvToolbar::AdvToolbar(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AdvToolbar)
{
	ui->setupUi(this);
    mvwImage = new ViewPager(this);
	QFrameLayout* pLayout1 = new QFrameLayout(this);
	pLayout1->appendWidget(mvwImage,ALINE_FILL);
	pLayout1->appendWidget(ui->pbclose,ALINE_TOP|ALINE_RIGHT,QMargins(0,10,10,3));

	
	connect(ui->pbclose, &QPushButton::clicked, this, &AdvToolbar::onBtnClose);
}

AdvToolbar::~AdvToolbar()
{

}


void AdvToolbar::showAllPicture(const QList <QSharedPointer<Biz::AdvDataItem>> & picpathlist )
{

    QSharedPointer<Biz::AdverConfigInfo> spConfigInfo = Biz::Session::getAdvInforManager()->getAdvConfigInfo();
    if (spConfigInfo.isNull())
        return; // 数据不足

	//根据图片的张数，生成浮动的按钮
    AdvViewPagerAdapter* pAdapter = new AdvViewPagerAdapter(mvwImage);
    pAdapter->setAdvDatas(picpathlist);
    mvwImage
        ->setAdapter(pAdapter)
        ->setTimeHolder(spConfigInfo->carousel()?spConfigInfo->carouseldelay():0)
        ->setIndicatorVisible(spConfigInfo->carousel()&&pAdapter->count()!=0)
        ->startUp();
}

void AdvToolbar::onBtnClose()
{
    QSharedPointer<Biz::AdverConfigInfo> spConfigInfo = Biz::Session::getAdvInforManager()->getAdvConfigInfo();
    if (spConfigInfo.isNull())
        return; // 数据不足
    if (!spConfigInfo->skiptips().isEmpty())
    {
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (spConfigInfo->skiptips ());

         MainApp::UIFrame::getConversationController()->onCloseAdvWidget();
    }
    else
    {
        MainApp::UIFrame::getConversationController()->onCloseAdvWidget();
    }
    
    
}

void AdvToolbar::setCloseable(bool b)
{
    ui->pbclose->setVisible(b);
}
