#include "imageviewer.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPoint>
#include <QWheelEvent>
#include <QMessageBox>
#include <QUrl>
#include <QDir>
#include <QDesktopServices>
#include <QMovie>
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include <QFileDialog>
#include <QImageReader>
#include "BizCallback.h"
#include "attachmentmanager.h"
#include "UtilHelper.h"

#include "diywidgit/customviews/qframelayout.h"
#include "portraithelper.h"
#include "ImageHelper.h"


ImageViewer::ImageViewer(QWidget *parent)
    : LocalManWidget(parent),scaleTick(1.2),maxRate(16),minRate(0.05),imagePressed(false),picIndexTimeLine(new QTimeLine(700)),bScaleable(false)
    , mGifPlayer(new QMovie(this)), bFirst(true), bresize(false)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Tool;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(QStringLiteral("图片查看器"));

    connect(ui.btnClose,&QPushButton::clicked,this,&ImageViewer::onClose);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    screenRect = desktopWidget->screenGeometry();
    minSize = QSize(screenRect.width()/3,screenRect.height()/3);
    maxSize = QSize(screenRect.width()-100,screenRect.height()-100);

    connect(picIndexTimeLine,&QTimeLine::finished,[this]{
        ui.ratetext->setVisible(false);
    });
    
    connect(ui.pre,&QPushButton::clicked,[this](bool bcheck){
        showPrePicture();
    });
    connect(ui.next,&QPushButton::clicked,[this](bool bcheck){
        showNextPicture();
    });

    connect(ui.normalsize,&QPushButton::clicked,[this](bool bcheck){
        scaledRate = 1.0;
        _scaledSize();
    });
    connect(ui.openfolder,&QPushButton::clicked,[this](bool bcheck){

        QString folder = currentFile;
        int pos = folder.lastIndexOf('\\');
        if(-1==pos)
            pos = folder.lastIndexOf("/");

        folder = folder.left(pos);
        QDir dir(folder);
        if(dir.exists())
        {
            QDesktopServices::openUrl(QUrl("file:///"+folder, QUrl::TolerantMode));
        }        
    });
    connect(ui.smaller,&QPushButton::clicked,[this](bool bcheck){
        onScrollSize(-1);
    });
    connect(ui.bigger,&QPushButton::clicked,[this](bool bcheck){
        onScrollSize(1);
    });

    connect(ui.turnright, &QPushButton::clicked,[this]{
        QMatrix matrix;
        matrix.rotate(90);
        rawPixmap = rawPixmap.transformed(matrix);
        _scaledSize();
    });
	connect(ui.saveas,&QPushButton::clicked,[this](bool bcheck){
		if (!currentFile.isEmpty())
		{
			//QString localPath = Biz::ConfigureHelper::UserTempPath(Biz::Session::currentAccount().accountData().UserID());
			QString localPath = Biz::ConfigureHelper::getDeskWindowPath();
			localPath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
			//QString localFileName = localPath + fileName;
			QFileInfo fileIfor(currentFile);
			QString localFileName = localPath + fileIfor.fileName();

			QString strextername = fileIfor.suffix();
			QString suffixname;
			if (!strextername.isEmpty())
			{
				suffixname = QString("Images (*.%1)").arg(strextername);
			}
			else
				suffixname = "Images (*.png *.xpm *.jpg)";

			QString saveFileName = QFileDialog::getSaveFileName(0, "", localFileName, suffixname);
			if (!saveFileName.isEmpty())
			{
				UtilHelper::copyFileToPath(currentFile, saveFileName, true);
			}
		}
	});

    QFrameLayout* pLayoutBk2 = new QFrameLayout(ui.bk2);
    pLayoutBk2->appendWidget(ui.bk,ALINE_FILL);

    QFrameLayout* pLayout1 = new QFrameLayout(ui.bk);
    pLayout1->appendWidget(ui.webRemoteUrl,ALINE_FILL);
    pLayout1->appendWidget(ui.btnClose,ALINE_TOP|ALINE_RIGHT,QMargins(0,10,10,0));
    pLayout1->appendWidget(ui.boolbar,ALINE_BOTTOM|ALINE_HCENTER);
    pLayout1->appendWidget(ui.miniview,ALINE_RIGHT|ALINE_BOTTOM);
    pLayout1->appendWidget(ui.next,ALINE_VCENTER|ALINE_RIGHT);
    pLayout1->appendWidget(ui.pre,ALINE_VCENTER|ALINE_LEFT);
    pLayout1->appendWidget(ui.ratetext,ALINE_VCENTER|ALINE_HCENTER);
    ui.miniview->installEventFilter(this);

	this->installEventFilter(this);
	
	this->setSizeGripEnabled(true);
}

ImageViewer::~ImageViewer()
{

}


void ImageViewer::showPicture(const QString& path, const QString& fileId)
{
    Log::e(QString("ImageViewer::showPicture %1").arg(path));

    resetSizeLimited();

    QString pixPath = path;
    if (QFile::exists(pixPath))
    {
        showLocalPicture(pixPath, fileId);
    }
    else
    {
        QUrl url(pixPath);
        if (url.isLocalFile())
        {
            pixPath = url.toLocalFile();
            showLocalPicture(pixPath, fileId);
        }
        else
        {
            // http or empty
            showRemotePicture(pixPath);
        }
    }
}
void ImageViewer::showLocalPicture(const QString& path, const QString& fileId)
{
    currentFile = path;
	currentFileId = fileId;
   // loadAllCacheFile();
	loadAllFile();

	if (NULL!=mGifPlayer)
	{
		mGifPlayer->deleteLater();
	}
	mGifPlayer = new QMovie();
    mGifPlayer->setFileName(currentFile);
    int nCount = mGifPlayer->frameCount();
	//由于有的图片有0帧，导致这个地方区分一下

	connect(mGifPlayer,&QMovie::frameChanged,[this,nCount](int frameNumber){
		QPixmap pixmap = mGifPlayer->currentPixmap();
		rawPixmap = pixmap;
		//QImage pixmapimage = mGifPlayer->currentImage();
		//rawPixmap = pixmapimage;

		_scaledSize();
	});
	mGifPlayer->start();

	QPixmap pixmap;
	if (nCount > 0)
	{
		pixmap = mGifPlayer->currentPixmap();
		if (pixmap.isNull())
		{
			bool bret = pixmap.load(path);//QPixmap(":Images/Imageloadfail.png");
			if (!bret)
			{
				pixmap = QPixmap(":Images/Imageloadfail.png");
				Log::e(QString("load QPixmap is fail %1").arg(path));
			}
			rawPixmap = pixmap;
			//rawPixmap = mGifPlayer->currentImage();
			
			_scaledSize();
		}
		
	}
	else
	{
		QString strfilePath = mGifPlayer->fileName();

		pixmap =Biz::PortraitHelper::loadPixmap(strfilePath);
		rawPixmap = pixmap;
		//rawPixmap = mGifPlayer->currentImage();
	}
	
	int nwidth = pixmap.width();
	int nheight = pixmap.height();
    resizeImageFrame(QSize(pixmap.width(),pixmap.height()));
    bScaleable = true;
    ui.lbScledPixmap->setVisible(true);
    ui.webRemoteUrl->setVisible(false);
    ui.pre->setVisible(true);
    ui.next->setVisible(true);

    this->show();
    ui.miniview->setVisible(false);
    ui.ratetext->setVisible(false);
    this->activateWindow();
	this->setFocus();
	bFirst = false;
}

void ImageViewer::showRemotePicture(const QString& path)
{
    bScaleable = false;
    ui.lbScledPixmap->setVisible(false);
    ui.webRemoteUrl->setVisible(true);
    ui.pre->setVisible(false);
    ui.next->setVisible(false);
    ui.boolbar->setVisible(false);

    QString str = QString(
        "<html><body><div style='height:100%; width:100%; display:table; text-align:center;'><span style='display:table-cell; vertical-align:middle;'><img src='%3' width='%1' height='%2'/><span></div></body></html>"
        ).arg(screenRect.width()/3/2).arg(screenRect.height()/3/2).arg(path);
    ui.webRemoteUrl->setHtml(str);
    resizeImageFrame(QSize(screenRect.width()/3,screenRect.height()/3));
    this->show();

    ui.miniview->setVisible(false);
    ui.ratetext->setVisible(false);
    this->activateWindow();
}

void ImageViewer::resizeImageFrame(const QSize& contentsize)
{
    // 计算外框大小，不超过最大狂，不小于最小框，如果在适中范围内，匹配图的大小
    QSize frameSize;
    QSize size = contentsize;
    if (this->isVisible())
    {
        frameSize = this->size();
    }
    else
    {
        frameSize = QSize(contentsize.width() + 20,contentsize.height() + 20);
    
        if (frameSize.width()<minSize.width())
        {
            frameSize.setWidth(minSize.width());
        }
        if (frameSize.width()>maxSize.width())
        {
            frameSize.setWidth(maxSize.width());
        }
        if (frameSize.height()<minSize.height())
        {
            frameSize.setHeight(minSize.height());
        }
        if (frameSize.height()>maxSize.height())
        {
            frameSize.setHeight(maxSize.height());
        }
    }

// 	if (bFirst)
// 	{
// 		//frameSize = QSize(screenRect.width() , screenRect.height());
// 	}
// 	else
// 	{
// 		frameSize = QSize(this->width(), this->height());
// 	}
	
// 	if (bresize)
// 	{
// 		frameSize = QSize(this->width(), this->height());
// 	}
		
	
	
	

    // 计算缩放比例,挑选宽高比例最严重的
    float lastScaledRage = scaledRate;
    scaledRate = 1.0;
    QSize innerFrame = QSize(frameSize.width()-2,frameSize.height()-2);
    if (size.width()>innerFrame.width())
    {
        scaledRate = innerFrame.width()*1.0/size.width();
    }

    if (size.height() > innerFrame.height())
    {
        float hr = innerFrame.height()*1.0/size.height();
        if (hr < scaledRate)
        {
            scaledRate = hr;
        }
    }

    size.setWidth((int)size.width()*scaledRate);
    size.setHeight((int)size.height()*scaledRate);

    // 按照比例将图进行缩放
    scaledPixmap = rawPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //scaledPixmap = QPixmap::fromImage(rawPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 设置各种框框尺寸和位置
//     if ((frameSize.height()+30*2)<=maxSize.height())
//     {
//         if (!this->isVisible())
//             frameSize.setHeight(frameSize.height()+30*2);
//     }

    QSize framebk(frameSize.width()-2,frameSize.height()-2); // 内接矩形

  //  this->setFixedSize(frameSize);
    //move((screenRect.width() - this->width())/2 + rawpoint.x(), (screenRect.height() - this->height())/2 + rawpoint.y());

   
	
	QDesktopWidget* desktopWidget = QApplication::desktop();
	int screenIndex = desktopWidget->screenNumber(rawpoint);
	QRect screenRecttmp = desktopWidget->screenGeometry(screenIndex);

	this->setGeometry((screenRecttmp.width() - frameSize.width())/2 + rawpoint.x() ,  (screenRecttmp.height() - frameSize.height())/2 + rawpoint.y(), frameSize.width(), frameSize.height());
    resizeImageWidget(size);

	this->activateWindow();
	this->setFocus();
}

void ImageViewer::onClose(bool b)
{
	mGifPlayer->stop();
	ui.lbScledPixmap->setPixmap(QPixmap(""));
    close();
    
}

void ImageViewer::mousePressEvent(QMouseEvent *e)
{
    if (bScaleable)
    {
        QPoint pos = e->pos();
        QRect rect = ui.lbScledPixmap->rect();
        rect.moveTo(ui.lbScledPixmap->pos());
        if (rect.contains(pos))
        {
            imagePressed = true;
            pressedPos = e->pos();
            pressedImagePos = ui.lbScledPixmap->pos();
            setCursor(Qt::OpenHandCursor);
            //return;
        }
        else 
        {
            imagePressed = false;
        }
        
    }

    return LocalManWidget::mousePressEvent(e);
	
}

void ImageViewer::mouseReleaseEvent(QMouseEvent *e)
{
    if (bScaleable)
    {
        if (imagePressed)
        {
            imagePressed = false;
            setCursor(Qt::ArrowCursor);
            //return;
        }
    }
    
    return LocalManWidget::mouseReleaseEvent(e);
	
}

void ImageViewer::mouseDoubleClickEvent(QMouseEvent *e)
{
    return LocalManWidget::mouseDoubleClickEvent(e);
	
}

void ImageViewer::mouseMoveEvent(QMouseEvent *e)
{
    if (bScaleable)
    {
        // 判断是否该移动：图片(label)小于等于大框（this）
        if (ui.lbScledPixmap->width() > this->width() || ui.lbScledPixmap->height() > this->height())
        {
        if (imagePressed)
        {
            QPoint pos = e->pos();
            moveImageWidget(pos.x()-pressedPos.x(),pos.y()-pressedPos.y());
            if (ui.miniview->isVisible())
            {
                moveImageMiniRect();
            }
            return;
        }
        }

    }
	
    
    return LocalManWidget::mouseMoveEvent(e);
}

void ImageViewer::onScrollSize(int distence)
{
    if (distence>0)
    {
        scaledRate = scaledRate*scaleTick;
        if (scaledRate > maxRate)
        {
            scaledRate = maxRate;
        }
    }
    else 
    {
        scaledRate = scaledRate/scaleTick;
        if (scaledRate < minRate)
        {
            scaledRate = minRate;
        }
    }

    ui.ratetext->setText(QString("%1%").arg((int)(scaledRate*100)));
    ui.ratetext->setVisible(true);
    picIndexTimeLine->setCurrentTime(0);
    picIndexTimeLine->start();
    _scaledSize();
}

void ImageViewer::_scaledSize(){
    QSize size = rawPixmap.size();
    size.setWidth((int)size.width()*scaledRate);
    size.setHeight((int)size.height()*scaledRate);
    // 按照比例将图进行缩放
    resizeImageWidget(size);

    if (size.width()>this->width() || size.height()>this->height())
    {
        showMiniView();
    }
    else 
    {
        ui.miniview->setVisible(false);
    }
}
void ImageViewer::wheelEvent(QWheelEvent *event)
{
    if (!bScaleable)
    {
        event->ignore();
        return;
    }
    QPoint numDegrees = event->angleDelta();
    onScrollSize(numDegrees.y());
    event->accept();
}

void ImageViewer::resizeImageWidget(const QSize& size)
{
    scaledPixmap = rawPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//QImage image = rawPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QSize currentSize = ui.lbScledPixmap->size();
     ui.lbScledPixmap->setFixedSize(size);

	QPoint pt((width() - ui.lbScledPixmap->width()) / 2, (height() - ui.lbScledPixmap->height()) / 2);
    //if (currentSize!=size)
        ui.lbScledPixmap->move((width()-ui.lbScledPixmap->width())/2,(height()-ui.lbScledPixmap->height())/2);
	

    ui.lbScledPixmap->setPixmap(/*QPixmap::fromImage(image)*/scaledPixmap);
}

void ImageViewer::moveMiniImageWidget(int disX,int disY)
{
    QPoint currentPos = ui.rectBorder->pos();
    QPoint miniRectPos(miniPressedImagePos.x()+disX,miniPressedImagePos.y()+disY);
    if (miniRectPos.x()<ui.miniimg->pos().x())
    {
        miniRectPos.setX(ui.miniimg->pos().x());
    }
    if (miniRectPos.y()<ui.miniimg->pos().y())
    {
        miniRectPos.setY(ui.miniimg->pos().y());
    }
    if (miniRectPos.x()+ui.rectBorder->width() > ui.miniimg->pos().x()+ui.miniimg->width())
    {
        miniRectPos.setX(ui.miniimg->pos().x()+ui.miniimg->width()-ui.rectBorder->width());
    }
    if (miniRectPos.y()+ui.rectBorder->height() > ui.miniimg->pos().y()+ui.miniimg->height())
    {
        miniRectPos.setY(ui.miniimg->pos().y()+ui.miniimg->height()-ui.rectBorder->height());
    }
    ui.rectBorder->move(miniRectPos);
    int dx = scaledPixmap.width()*disX/ui.miniimg->width();
    int dy = scaledPixmap.height()*disY/ui.miniimg->height();
    moveImageWidget(-dx,-dy);
}
void ImageViewer::moveImageWidget(int disX,int disY)
{
//     disX = disX * scaledRate;
//     disY = disY * scaledRate;
    QPoint currentPos = pressedImagePos;
    QPoint fixPos = currentPos;
    // 边界检查
    if (disX>0)
    {
         // 左边,在框之内的，左右不动，在框外的，移动disX位置后不能右过左边界
        if (this->rect().left() > currentPos.x())
        {
            int uidist_l = this->rect().left() - currentPos.x();
            int x = currentPos.x();
            fixPos.setX(currentPos.x() + (uidist_l>disX?disX:uidist_l));
        }
    }
    else 
    {
        // 右边界,向左移动的时候，不能左过右边界
        if (this->rect().right() < currentPos.x()+ui.lbScledPixmap->width())
        {
            int uidist_r =  this->rect().width() - (currentPos.x()+ui.lbScledPixmap->width()) ;
            fixPos.setX(currentPos.x() + (uidist_r>disX?uidist_r:disX));
        }
    }
    

    if (disY>0)
    {
        // 左边,在框之内的，左右不动，在框外的，移动disX位置后不能右过左边界
        if (this->rect().top() > currentPos.y())
        {
            int uidist_t = this->rect().top() - currentPos.y();
            fixPos.setY(currentPos.y() + (uidist_t>disY?disY:uidist_t));
        }
    }
    else 
    {
        // 右边界,向左移动的时候，不能左过右边界^
        
        if (this->rect().height() < currentPos.y()+ui.lbScledPixmap->height())
        {
            int uidist_b =  this->rect().height() - (currentPos.y()+ui.lbScledPixmap->height()) ;
            fixPos.setY(currentPos.y() + (uidist_b>disY?uidist_b:disY));
        }
    }
   
    ui.lbScledPixmap->move(fixPos);
}

void ImageViewer::showMiniView()
{
    QPoint parentBR = rect().bottomRight();

    
    // 根据原始图片的最大边算缩略度
    float scale = 1.0;
    int maxL = rawPixmap.width()>rawPixmap.height()?rawPixmap.width():rawPixmap.height();
    int miniL = ui.miniview->width();
    scale = miniL*1.0/maxL;
    QSize scSize = QSize(rawPixmap.width()*scale,rawPixmap.height()*scale);
    QPixmap pixmap = rawPixmap.scaled(scSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	// QPixmap pixmap = QPixmap::fromImage(rawPixmap.scaled(scSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui.miniimg->setFixedSize(scSize);
    ui.miniimg->move( (ui.miniview->width()-ui.miniimg->width())/2,(ui.miniview->height()-ui.miniimg->height())/2);
    ui.miniimg->setPixmap(pixmap);
    ui.miniview->setVisible(true);

    moveImageMiniRect();
}

void ImageViewer::moveImageMiniRect()
{
    // 设置小框 ，大图的pos.x : 大图的宽 = 小图的pos.x : 小图的宽 、/ 高等同

    int miniPosX = 0;
    int miniPosY = 0;

    int noticyW = ui.miniimg->width();
    int noticyH = ui.miniimg->height();

    if (ui.lbScledPixmap->pos().x()<=0)
    {
        int sPosX = qAbs(ui.lbScledPixmap->pos().x());
        int minimgw = ui.miniimg->width();
        int pw = ui.lbScledPixmap->width();
        miniPosX = sPosX*ui.miniimg->width()/ui.lbScledPixmap->width();
        noticyW = this->width()*ui.miniimg->width()/ui.lbScledPixmap->width();
    }

    if (ui.lbScledPixmap->pos().y()<=0)
    {
        int sPosY = qAbs(ui.lbScledPixmap->pos().y());
        miniPosY = sPosY*ui.miniimg->height()/ui.lbScledPixmap->height();
         noticyH = this->height()*ui.miniimg->height()/ui.lbScledPixmap->height();
    }

    ui.rectBorder->setFixedSize(QSize(noticyW,noticyH));

    QPoint pt = ui.miniimg->pos();
    ui.rectBorder->move(miniPosX+pt.x(),miniPosY+pt.y());
}

bool ImageViewer::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui.miniview)
    {
        if (event->type() == QEvent::Type::MouseButtonPress)
        {
            QMouseEvent* e = (QMouseEvent*)event;
            if (bScaleable)
            {
                QPoint pos = e->pos();
                QRect rect = ui.lbScledPixmap->rect();
                rect.moveTo(ui.lbScledPixmap->pos());
                if (rect.contains(pos))
                {
                    miniImagePressed = true;
                    miniPressedPos = e->pos();
                    miniPressedImagePos = ui.rectBorder->pos();
                    pressedImagePos = ui.lbScledPixmap->pos();
                    setCursor(Qt::ClosedHandCursor);
                    return true;
                }
                else 
                {
                    imagePressed = false;
                }
            }
        }
        if (event->type() == QEvent::Type::MouseMove)
        {
            QMouseEvent* e = (QMouseEvent*)event;
            if (bScaleable)
            {
                if (miniImagePressed)
                {
                    QPoint pos = e->pos();
                    moveMiniImageWidget(pos.x()-miniPressedPos.x(),pos.y()-miniPressedPos.y());
                    return true;
                }
            }
        }
        if (event->type() == QEvent::Type::MouseButtonRelease)
        {
            QMouseEvent* e = (QMouseEvent*)event;
            if (bScaleable)
            {
                if (miniImagePressed)
                {
                    miniImagePressed = false;
                    setCursor(Qt::ArrowCursor);
                    return true;
                }
            }
        }
    }

    return LocalManWidget::eventFilter(obj,event);
}

void ImageViewer::loadAllCacheFile()
{
    /*int leftpos = currentFile.lastIndexOf("\\");
    if (leftpos<0 || leftpos>currentFile.length())
    {
        leftpos = currentFile.lastIndexOf("/");
    }
    QString path = currentFile.left(leftpos);
    

    QDir dir(path);
    if (!dir.exists())
        return;

    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Time);
    QFileInfoList list = dir.entryInfoList();
    int i = 0;
    bool bIsDir;
    files.clear();

     while(i<list.size()){

        QFileInfo fileInfo = list.at(i);

        if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")

        {
            i++;
            continue;
        }

        bIsDir = fileInfo.isDir();

        if (bIsDir)
        {
            continue;
        }
        else
        {
            if (!fileInfo.fileName().endsWith(".tmp"))
            {
                files.append(fileInfo.filePath());
            }
        }
        i++;
    }
   */
}

void ImageViewer::enterEvent(QEvent *)
{
    if (bScaleable)
    {
        ui.boolbar->setVisible(true);
		
		QSize size = scaledPixmap.size();
		if (size.width()>this->width() || size.height()>this->height())
		{
			 ui.miniview->setVisible(true);
		}
    }
}

void ImageViewer::leaveEvent(QEvent *)
{
	if (bScaleable)
	{
		ui.boolbar->setVisible(false);
		ui.miniview->setVisible(false);
	}
        
}


void ImageViewer::resetSizeLimited()
{
    rawpoint = QCursor::pos();
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int screenIndex = desktopWidget->screenNumber(rawpoint);
    screenRect = desktopWidget->screenGeometry(screenIndex);
    minSize = QSize(screenRect.width()/3,screenRect.height()/3);
    maxSize = QSize(screenRect.width()-100,screenRect.height()-100);

    QWidget* widget = desktopWidget->screen(screenIndex);
    rawpoint = desktopWidget->screenGeometry(screenIndex).topLeft();
}

void ImageViewer::keyPressEvent(QKeyEvent *event)
{
    if (Qt::NoModifier == event->modifiers())
    {
        if (Qt::Key_Up == event->key() || Qt::Key_Left == event->key())
        {
            showPrePicture();
        }
        if (Qt::Key_Down == event->key() || Qt::Key_Right == event->key())
        {
            showNextPicture();
        }
    }
	if (event->key() == Qt::Key_Escape)
	{
		this->close();
	}
    
    return LocalManWidget::keyPressEvent(event);
	
}

void ImageViewer::showNextPicture()
{
    mGifPlayer->stop();

    // files的是按照时间倒序排列，下一张照片，应该时间增加，故游标减小
	
	if (mImagefiles.size() != 0)
	{

	
    int i =( getImageOrderbyCurrent()+1 + mImagefiles.size()  )%mImagefiles.size();
    
    showLocalPicture(getImageLocalPath(i), getImageFileId(i)/*mImagefiles.at(i).fileLocalPath, mImagefiles.at(i).fileId*/);

    // index 由0base转化为1base
    // index 按照时间倒叙一下
    QString info = QString("%1/%2").arg(mImagefiles.size()-i).arg(mImagefiles.size());

    QFontMetrics elidfont( ui.ratetext-> font());
    int nNeedWidth = elidfont.width(info);

    
    ui.ratetext->setText(info);
    ui.ratetext->setFixedWidth(qMax(nNeedWidth,ui.ratetext->width()));
    ui.ratetext->move((width()-ui.ratetext->width())/2,(height()-ui.ratetext->height())/2);
    ui.ratetext->setVisible(true);
    picIndexTimeLine->setCurrentTime(0);
    picIndexTimeLine->start();
	}
}

void ImageViewer::showPrePicture()
{
     mGifPlayer->stop();
     // files的是按照时间倒序排列，上一张照片，应该时间减小，故游标增加
	 if (mImagefiles.size() != 0)
	 {
		 int i =( getImageOrderbyCurrent() - 1 ) % mImagefiles.size();
		 // index 由0base转化为1base
		 // index 按照时间倒叙一下

		 showLocalPicture(getImageLocalPath(i), getImageFileId(i));

		 QString info = QString("%1/%2").arg(mImagefiles.size()-i).arg(mImagefiles.size());

		 QFontMetrics elidfont( ui.ratetext-> font());
		 int nNeedWidth = elidfont.width(info);
		 ui.ratetext->setText(info);
		 ui.ratetext->setFixedWidth(qMax(nNeedWidth,ui.ratetext->width()));
		 ui.ratetext->move((width()-ui.ratetext->width())/2,(height()-ui.ratetext->height())/2);
		 ui.ratetext->setVisible(true);
		 picIndexTimeLine->setCurrentTime(0);
		 picIndexTimeLine->start();
	 }
    
}

void ImageViewer::loadAllFile()
{
	if(!QFile::exists(currentFile))
	{
		return;
	}
	QFileInfo fileinfo(currentFile);
	QDir dir = fileinfo.absoluteDir();

	QString jid = dir.dirName();
	mImagefiles.clear();

	QList <QSharedPointer <Biz::ImageAttachInfor>> listimage = Biz::Session::getAttachmentManager()->getImageAttachlist(jid);

	for (QSharedPointer<Biz::ImageAttachInfor> oneattachImage: listimage)
	{
		QString strfileLocalPath = oneattachImage->LocalPath();
		ImageOrder imageorder;
		if (!strfileLocalPath.isEmpty() && QFile::exists(strfileLocalPath))
		{
			imageorder.orderId = mImagefiles.size() + 1;
			imageorder.fileId = oneattachImage->ImageId();
			imageorder.fileLocalPath = strfileLocalPath;
			//files.append(strfileLocalPath);
			//files.push_back(strfileLocalPath);
			mImagefiles.push_back(imageorder);
		}
	}
	int nsize = mImagefiles.size();
}

int ImageViewer::getImageOrderbyCurrent()
{
	int norder = 0;
	for (ImageOrder oneorder: mImagefiles)
	{
		++norder;
		if (oneorder.fileId == currentFileId && currentFile == oneorder.fileLocalPath)
		{
			return oneorder.orderId - 1; //因为从1开始的，而数组应该从0开始
		}
	}
	return mImagefiles.size() - 1;
}

QString ImageViewer::getImageLocalPath( int nIndex )
{
	
	for (ImageOrder oneorder: mImagefiles)
	{
		
		if ((oneorder.orderId - 1) == nIndex)
		{
			return oneorder.fileLocalPath;
		}
	}

    return QString::number(mImagefiles.size() - 1);
	//return mImagefiles.at(i).fileLocalPath;
}

QString ImageViewer::getImageFileId(int nIndex)
{
	
	for (ImageOrder oneorder: mImagefiles)
	{
		
		if ( (oneorder.orderId - 1) == nIndex)
		{
			return oneorder.fileId;
		}
	}
    return QString::number(mImagefiles.size() - 1);
	//return mImagefiles.at(i).fileId;
}

void ImageViewer::resizeEvent( QResizeEvent *event )
{
	LocalManWidget::resizeEvent(event);
	if(!bFirst)
	{
		QSize resizeframesize = QSize(this->width(), this->height());
		screenRect.setWidth(resizeframesize.width());
		screenRect.setHeight(resizeframesize.height());
		
		//resizeImageFrame(framesize);

		
		QSize frameSize = resizeframesize;

		//获取图片的宽和高
		if (NULL!=mGifPlayer)
		{
			mGifPlayer->deleteLater();
		}
		mGifPlayer = new QMovie();
		mGifPlayer->setFileName(currentFile);
		int nCount = mGifPlayer->frameCount();
		connect(mGifPlayer,&QMovie::frameChanged,[this,nCount](int frameNumber){
			QPixmap pixmap = mGifPlayer->currentPixmap();
			rawPixmap = pixmap;
			
			_scaledSize();
		});
		mGifPlayer->start();
		
		QPixmap pixmap;
		if (nCount > 0)
		{
			pixmap = mGifPlayer->currentPixmap();
			if (pixmap.isNull())
			{
				bool bret = pixmap.load(currentFile);//QPixmap(":Images/Imageloadfail.png");
				if (!bret)
				{
					pixmap = QPixmap(":Images/Imageloadfail.png");
					Log::e(QString("load QPixmap is fail %1").arg(currentFile));
				}
				rawPixmap = pixmap;
				//rawPixmap = mGifPlayer->currentImage();

				_scaledSize();
			}

		}
		else
		{
			QString strfilePath = mGifPlayer->fileName();

			pixmap =Biz::PortraitHelper::loadPixmap(strfilePath);
			rawPixmap = pixmap;
			//rawPixmap = mGifPlayer->currentImage();
		}
		
		int nwidth = pixmap.width();
		int nheight = pixmap.height();
		QSize size = QSize(nwidth, nheight);

		// 计算缩放比例,挑选宽高比例最严重的
		float lastScaledRage = scaledRate;
		scaledRate = 1.0;
		QSize innerFrame = QSize(frameSize.width()-2,frameSize.height()-2);
		if (size.width()>innerFrame.width())
		{
			scaledRate = innerFrame.width()*1.0/size.width();
		}

		if (size.height() > innerFrame.height())
		{
			float hr = innerFrame.height()*1.0/size.height();
			if (hr < scaledRate)
			{
				scaledRate = hr;
			}
		}

		size.setWidth((int)size.width()*scaledRate);
		size.setHeight((int)size.height()*scaledRate);

		// 按照比例将图进行缩放
		scaledPixmap = rawPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		//scaledPixmap = QPixmap::fromImage(rawPixmap.scaled(size,Qt::KeepAspectRatio, Qt::SmoothTransformation));

		// 设置各种框框尺寸和位置
// 		if ((frameSize.height()+30*2)<=maxSize.height())
// 		{
// 			if (!this->isVisible())
// 				frameSize.setHeight(frameSize.height()+30*2);
// 		}

		QSize framebk(frameSize.width()-2,frameSize.height()-2); // 内接矩形

		QDesktopWidget* desktopWidget = QApplication::desktop();
		int screenIndex = desktopWidget->screenNumber(rawpoint);
		QRect screenRecttmp = desktopWidget->screenGeometry(screenIndex);

		
		this->setGeometry( rawpoint.x() + (screenRecttmp.width() - frameSize.width())/2 ,  rawpoint.y() + (screenRecttmp.height() - frameSize.height())/2, frameSize.width(), frameSize.height());
		//resizeImageWidget(size);
		_scaledSize();

		bresize = true;
	}
	
	this->setSizeGripEnabled(true);
}


