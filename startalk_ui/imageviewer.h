#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QTimeLine>
#include "ui_imageviewer.h"
#include "localmanwidget.h"
#include "Player.h"
class ImageViewer : public LocalManWidget
{
    Q_OBJECT
	struct ImageOrder
	{
		int orderId;
		QString fileId;
		QString fileLocalPath;
		ImageOrder()
		{orderId = 0;}
	};
public:
    ImageViewer(QWidget *parent = 0);
    ~ImageViewer();
public:
    void showPicture(const QString& path, const QString& fileId);
protected:
    void showLocalPicture(const QString& path, const QString& fileId);
    void showRemotePicture(const QString& path);
    void resizeImageFrame(const QSize& size);
    void resizeImageWidget(const QSize& size);
    void moveImageWidget(int disX,int disY );
    void moveMiniImageWidget(int disX,int disY );
    void showMiniView();
    void moveImageMiniRect();
    
    void loadAllCacheFile();
	void loadAllFile();
    /*!
     * 功能 : 将窗口缩放到主屏的1/4,居中
     */
    void resetSizeLimited();
    protected slots:
        void onClose(bool b=false);
protected:
        virtual void mousePressEvent(QMouseEvent *);

        virtual void mouseReleaseEvent(QMouseEvent *);

        virtual void mouseDoubleClickEvent(QMouseEvent *);

        virtual void mouseMoveEvent(QMouseEvent *);

        virtual void wheelEvent(QWheelEvent *);

        virtual bool eventFilter(QObject *, QEvent *);

        virtual void enterEvent(QEvent *);

        virtual void leaveEvent(QEvent *);
        virtual void keyPressEvent(QKeyEvent *event);
		virtual void resizeEvent( QResizeEvent * );
private:
        void _scaledSize();
        void onScrollSize(int size);

        void showNextPicture();
        void showPrePicture();
		int getImageOrderbyCurrent();
		QString getImageLocalPath(int i);
		QString getImageFileId(int i);

		

private:
    Ui::ImageViewer ui;
    QPixmap rawPixmap;
	//QImage rawPixmap;
    QPixmap scaledPixmap;
    float scaledRate;    
    QSize minSize;
    QSize maxSize;
    QRect screenRect;
    float scaleTick;
    float maxRate;
    float minRate;

    bool imagePressed;
    QPoint pressedPos;
    QPoint pressedImagePos;

    bool miniImagePressed;
    QPoint miniPressedPos;
    QPoint miniPressedImagePos;

    QTimeLine* picIndexTimeLine;

    bool bScaleable;

    QString currentFile;
	QString currentFileId;
    //QStringList files;
	QList <ImageOrder> mImagefiles;

    QPoint rawpoint;//

    QMovie* mGifPlayer;
	bool bFirst;
	bool bresize;
};

#endif // IMAGEVIEWER_H
