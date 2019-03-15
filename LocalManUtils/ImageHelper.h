#ifndef IMAGEHELPER_H
#define IMAGEHELPER_H

#include <QObject>

namespace Biz
{
	class ImageHelper : public QObject
	{
		Q_OBJECT
	public:
		static QString  getImageRealFormat(const QString& filePath);
        static QImage   loadImageFromPath(const QString& filepath);
        static void     imageToGray(QImage& img);
        static void     getImageScaleSize(int& w,int& h, const int maxwidth, const int maxheigh);
    public:
		ImageHelper(QObject *parent);
		~ImageHelper();
	
	private:
		
	};
}

#endif // IMAGEHELPER_H
