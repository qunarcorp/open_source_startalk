#include "EmotionDialog.h"
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QBitmap>
#include <QScrollArea>
#include <QWheelEvent>
#include "EmotionTabDialog.h"
#include "Emotionpushbutton.h"


#include "Session.h"
#include "EmotionManager.h"

#include "diywidgit/customviews/DrawablePushbutton.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

int itemLineCount = 8;
int itemLineCountNt = 6;

const static QString innerId1 = "emotqq";
const static QString innerId2 = "xxxxx";



EmotionDialog::EmotionDialog(QWidget *parent)
    : QWidget(parent)
    , m_pGifPlayer(NULL)
	,m_itemInLine(7)
	,m_itemSize(30)
	,m_itempadding(5)
	,m_type(false)
	,mImagewidget(NULL)
	,mEmotionlabel(NULL)
	,m_previewGifPlayer(NULL)
{
    ui.setupUi(this);

	if (mImagewidget==NULL)
	{
		mImagewidget = new QWidget(this);
		mEmotionlabel = new QLabel(mImagewidget);
		QHBoxLayout *hLayout = new QHBoxLayout(mImagewidget);
		hLayout->setSpacing(0);
		hLayout->setContentsMargins(0, 0, 0, 0);
		hLayout->addWidget(mEmotionlabel);
		mImagewidget->setFixedSize(QSize(125, 125));
		//mImagewidget->setStyleSheet("background-color: rgb(170, 0, 255);");
		mEmotionlabel->setStyleSheet("background-color:#FFFAFA;");
		mImagewidget->hide();
	}
}

EmotionDialog::~EmotionDialog()
{

}
void EmotionDialog::init()
{
}


 void EmotionDialog::initEmoticonPkgIcons(const QString& pkgid)
 {
     const QList<QSharedPointer<Biz::EmotionItem>>& emotionList = Biz::Session::getEmoticonManager()->getEmotionList(pkgid);
	 
     if (emotionList.length()<=0)
     {
         return ;
     }
     

    
     int lineinpage = 8;
   

     if (pkgid == innerId1)
     {
         m_itemInLine = 14;
         m_itemSize = 30;
         lineinpage = 8;
     }
     else if (pkgid == innerId2)
     {
         m_itemInLine = 14;
         m_itemSize = 30;
         lineinpage = 8;
     }
     else
     {
       //  itemSize = 61;
         lineinpage = 4;
     }

   
  
     int linecount = (emotionList.length()/m_itemInLine/lineinpage +1)*lineinpage;
	 if (linecount < 8)
	 {
		 linecount = 8;
	 }
	 
     QGridLayout *gridLayout = ui.gridLayout;      

	 QLayoutItem *child;
	 while ((child = gridLayout->takeAt(0)) != 0) {
		 QWidget* pWidget = child->widget();
		 if (NULL!=pWidget)
		 {
			 pWidget->setParent(NULL);
			 delete pWidget;
		 }
		 delete child;
	 }

     // 要建造满行满列的
     for (int row = 0;row < linecount ; row++)
     {
         for (int column=0; column<m_itemInLine; column++ )
         {
             // 标准按钮
           
             int index = m_itemInLine*(row) + column;
             if (index >= emotionList.length())
             {
                 // 画空图
                 QWidget* pempty = new QWidget(this);
                 pempty->setStyleSheet("border:none;background-color: #FFFFFF;");

                 pempty->setFixedSize(m_itemSize,m_itemSize);
				gridLayout->addWidget(pempty,row, column);  
             }
             else
             {
                 QSharedPointer<Biz::EmotionItem> spItem = emotionList.at(index);

                 EmotionUserData* pEmotionData = new EmotionUserData();
                 pEmotionData->m_strShortKey = spItem->key;
                 pEmotionData->m_strPackageId = pkgid;
                 pEmotionData->m_strImagePath = spItem->strPath;
                 pEmotionData->m_strUrl = spItem->strUrl;
                 pEmotionData->m_bselect = false;
                 QPixmap pixmapToShow(spItem->strPath);    
                 

                 DrawablePushButton *button = new DrawablePushButton(NULL);
                 button->setFlat(true);
                 button->setFixedSize(m_itemSize,m_itemSize);
               
                 button->setIconSize(QSize(m_itemSize-m_itempadding, m_itemSize-m_itempadding));   
                 button->setToolTip(spItem->strtip);
                 button->setUserData(Qt::UserRole,pEmotionData);
                 button->installEventFilter(this);
				 
                 if (Biz::EmotionManager::sCustomPackageName != pkgid || spItem->strUrl.isEmpty())
                 {
						pixmapToShow.setDevicePixelRatio(button->devicePixelRatio());
                       button->setIcon(QIcon(pixmapToShow));
                 }
                 else
                 {
                     IDrawableInterface* drawer = (IDrawableInterface*)button;
                     ImageLoaderSingleton::getInstance()->loadImage(spItem->strUrl,drawer,"");
                     connect(button, &DrawablePushButton::sgLoadComplete,this,&EmotionDialog::onCustomEmotionLoaded);

					 if (m_type)
					 {
						 connect(button, &DrawablePushButton::clicked,this,&EmotionDialog::onCustomEmotionClicked);
					 }
					 
                 }
                 connect(button, &QPushButton::clicked, this, &EmotionDialog::onEmotionClicked);
                 gridLayout->addWidget(button,row, column);  
             }
         }
     }
 }

 void EmotionDialog::onEmotionClicked()
 {
     QPushButton* pButton = (QPushButton*)sender();
     if(pButton)
     {
         EmotionUserData* pEmotionData = dynamic_cast<EmotionUserData*>(pButton->userData(Qt::UserRole));
         if (NULL!=pEmotionData)
         {
             emit sgSelectItem(pEmotionData->m_strPackageId,pEmotionData->m_strShortKey);
         }
     }
 }

 bool EmotionDialog::eventFilter(QObject *obj, QEvent *e)
 {
     EmotionUserData* pEmotionData  = dynamic_cast<EmotionUserData*>(obj->userData(Qt::UserRole));
     if (NULL!=pEmotionData)
     {
         if (QEvent::Enter == e->type())
         {
             // 播放图片
             if (NULL!=m_pGifPlayer)
             {
                m_pGifPlayer->deleteLater();
                m_pGifPlayer->disconnect();
                m_pGifPlayer = NULL;
             }
             m_pGifPlayer = new QMovie(pEmotionData->m_strImagePath);
         
             connect(m_pGifPlayer,&QMovie::frameChanged,[obj,this]{
                QPushButton* pButton = dynamic_cast<QPushButton*>(obj);
				QPixmap pixmapToShow = m_pGifPlayer->currentPixmap();
				pixmapToShow.setDevicePixelRatio(pButton->devicePixelRatio());
				pButton->setIcon(QIcon(pixmapToShow));
             });
             m_pGifPlayer->start();

			 EmotionPreView(pEmotionData->m_strImagePath);
         }

         if (QEvent::Leave == e->type())
         {
             // 播放图片
             if (NULL!=m_pGifPlayer)
             {
                 m_pGifPlayer->deleteLater();
                 m_pGifPlayer->disconnect();
                 m_pGifPlayer = NULL;
             }
             QPushButton* pButton = dynamic_cast<QPushButton*>(obj);
			 QPixmap pixmapToShow = QPixmap(pEmotionData->m_strImagePath);
			 pixmapToShow.setDevicePixelRatio(pButton->devicePixelRatio());
			 pButton->setIcon(QIcon(pixmapToShow));
			 if (mImagewidget)
			 {
				 mImagewidget->hide();
			 }
         }
     }
     return QWidget::eventFilter(obj,e);
 }

 void EmotionDialog::onCustomEmotionLoaded(const QString& strLocalPath)
 {
     DrawablePushButton* button = dynamic_cast<DrawablePushButton*>(sender());
     if (NULL!=button)
     {
         EmotionUserData* userData = dynamic_cast<EmotionUserData*>(button->userData(Qt::UserRole));
         if (NULL!=userData)
         {
             QSharedPointer<Biz::EmotionItem> spEmotion = Biz::Session::getEmoticonManager()->findEmoticon(userData->m_strPackageId,userData->m_strShortKey);
             if (!spEmotion.isNull())
             {
                 spEmotion->strPath = strLocalPath;
                 Biz::Session::getEmoticonManager()->buildCuntomConfigration();
             }
         }
     }

 }

 void EmotionDialog::setitemInLine( int nLinecount )
 {
	 m_itemInLine = nLinecount;
 }

 void EmotionDialog::setitemSize( int size )
 {
	 m_itemSize = size;
 }

 void EmotionDialog::setitempadding( int nsize )
 {
	 m_itempadding = nsize;
 }

 void EmotionDialog::setMinandMaxSize( int nwidth, int nheight )
 {
	 ui.scrollAreaWidgetContents->setMinimumWidth(nwidth);
	 ui.scrollAreaWidgetContents->setMaximumWidth(nwidth);
	 ui.gridwidget->setMinimumWidth(nwidth);
	 ui.gridwidget->setMaximumWidth(nwidth);
	// ui.horizontalLayout->setContentsMargins(0, 0, 0, 0);
	 this->setFixedWidth(nwidth+21);
	 this->setFixedHeight( nheight - 5);
	 ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
 }

 void EmotionDialog::onCustomEmotionClicked()
 {
	 DrawablePushButton* button = dynamic_cast<DrawablePushButton*>(sender());
	 if (NULL!=button)
	 {
		 EmotionUserData* userData = dynamic_cast<EmotionUserData*>(button->userData(Qt::UserRole));
		 bool bret = button->isChecked();
		 if (!bret)
		 {
			 button->setStyleSheet("background-color: #3dbbca;");
			 userData->m_bselect = true;
		 }
		 else
		 {
			 button->setStyleSheet("background-color: #FFFFFF;");
			 userData->m_bselect = false;
		 }

		 button->setCheckable(!button->isChecked());

	 }
 }

 void EmotionDialog::deleteEmotionPkgIcons( const QString& pkgid )
 {
	 const QList<QSharedPointer<Biz::EmotionItem>>& emotionList = Biz::Session::getEmoticonManager()->getEmotionList(pkgid);
	 if (emotionList.size() <= 0)
	 {
		 return;
	 }
	 QGridLayout *gridLayout = ui.gridLayout;      

	 QLayoutItem *child = NULL;
	 QStringList BtnPixmapUrllist;
	 for (int nI = 0; nI < emotionList.size(); nI ++)
	 {
		 child = gridLayout->itemAt(nI);
		 DrawablePushButton *pButton = dynamic_cast<DrawablePushButton*> (child->widget());
		 if (NULL!=pButton)
		 {
			 EmotionUserData* userData = dynamic_cast<EmotionUserData*>(pButton->userData(Qt::UserRole));
			 if(userData->m_bselect)
			 {
				 QString strBtnUrl = userData->m_strUrl ;
				 BtnPixmapUrllist.push_back(strBtnUrl);
			 }
		 }
	 }
	 if (BtnPixmapUrllist.size() == 0 )
	 {
		 MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("未选中要删除的自定义表情，重新选择需要删除的表情"));
		 return;
	 }
	 //在数据库中先删掉
	 Biz::Session::getEmoticonManager()->DeleteEmotionList(Biz::EmotionManager::sCustomPackageName, BtnPixmapUrllist);

	 initEmoticonPkgIcons(pkgid);

 }

 void EmotionDialog::settype( bool btype )
 {
	 m_type = btype;
 }


 void EmotionDialog::EmotionPreView( const QString& filePath )
 {
	
	 if (NULL!=m_previewGifPlayer)
	 {
		 m_previewGifPlayer->deleteLater();
		 m_previewGifPlayer->disconnect();
		 m_previewGifPlayer = NULL;
	 }
	 m_previewGifPlayer = new QMovie(filePath);

	 connect(m_previewGifPlayer,&QMovie::frameChanged,[this]{
		
		 QPixmap pixmapToShow = m_previewGifPlayer->currentPixmap();
		 pixmapToShow.setDevicePixelRatio(mEmotionlabel->devicePixelRatio());
		 mEmotionlabel->setPixmap(pixmapToShow.scaled(mEmotionlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	 });
	 m_previewGifPlayer->start();

	 mImagewidget->setFixedSize(QSize(125,125));
	 //这地方判断当前鼠标的位置，如果鼠标不在预览框所在的区域，就显示在这里
	 //mImagewidget->move(this->width() - 138,11);
	 mImagewidget->show();

	 QRect rect;
	 rect.setTopLeft(QPoint(this->width() - 138,11));
	 rect.setWidth(125);
	 rect.setHeight(125);

	 QPoint ptcur = cursor().pos();
	 QPoint ptwidget = this->mapFromGlobal(ptcur);
	 if(rect.contains(ptwidget))
	 {
		 mImagewidget->move(11,11);
	 }
	 else
	 {
		  mImagewidget->move(this->width() - 138,11);
	 }
	 

 }


 void EmotionDialog::showEvent( QShowEvent * event)
 {
	 if (mImagewidget)
	 {
		 mImagewidget->setFixedSize(QSize(125,125));
		 //这地方判断当前鼠标的位置，如果鼠标不在预览框所在的区域，就显示在这里
		 mImagewidget->move(this->width() - 138,11);
	 }
	 QWidget::showEvent(event);
 }
