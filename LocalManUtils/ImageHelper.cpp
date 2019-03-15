#include "ImageHelper.h"
#include <QFile>
#include <QBuffer>
#include <QtGui/QImageReader>

#include "Log.h"

namespace Biz
{
	ImageHelper::ImageHelper(QObject *parent)
		: QObject(parent)
	{
	
	}
	
	ImageHelper::~ImageHelper()
	{
	
	}

	QString ImageHelper::getImageRealFormat(const QString& filePath)
	{
        if (!QFile::exists (filePath))
        {
            Log::e(QString("load image format error file not exist error path:%1").arg (filePath));
            return "";
        }
        QFile file (filePath);
        if (!file.open(QFile::ReadOnly))
        {
            Log::e(QString("load image format error read file error path:%1").arg (filePath));
            return "";
        }

        if (file.size() == 0)
        {
            Log::e(QString("load image format error file empty error path:%1").arg (filePath));
            file.close ();
            return "";
        }

		
        QByteArray arr = file.read(256);
        QBuffer buffer;
        buffer.setData(arr);
        buffer.open(QIODevice::ReadOnly);
        QString format = QImageReader::imageFormat(&buffer);
        buffer.close();
        file.close();
        return format;
	}


    QImage ImageHelper::loadImageFromPath( const QString& filepath )
    {
        QString format = getImageRealFormat (filepath);
        if (format.isEmpty ())
        {
            Log::e("load image error format is empty");
            return QImage();
        }
        QImage img;
        img.load(filepath, format.toStdString().c_str());
        if(!img.isNull()){
            return img;
        }

        img.load(filepath);
        return img;
    }




    void ImageHelper::imageToGray(QImage& img)
    {
        int depth = img.depth();
        if(depth != 32){
            img = img.convertToFormat(QImage::Format_RGB32);
        }

        QSize colourImgSize = img.size();   
        int width = colourImgSize.rwidth();   
        int height = colourImgSize.rheight();  
        unsigned char *data = img.bits();   
        int bytePerLine=(width*24+31)/8;//图像每行字节对齐

        unsigned char r,g,b;
        for (int i=0;i<height;i++)
        {
            for (int j=0;j<width;j++)
            {
                r = *(data+2);
                g = *(data+1);
                b = *data;
                int gray = (r*30+g*59+b*11)/100;
                *data = gray;
                *(data+1) = gray;
                *(data+2) = gray;

                data+=4;
            }
        }
    }

    void ImageHelper::getImageScaleSize(int& w,int& h, const int maxwidth, const int maxheigh)
    {
            if (w < maxwidth && h < maxheigh)
            {
                return;
            }
            else
            {
                double DixLow;
                double Dixwidth = ((double)maxwidth) / ((double)w);
                double Dixheigh = ((double)maxheigh) / ((double)h);

                DixLow = Dixwidth > Dixheigh?Dixheigh:Dixwidth;
                if (DixLow == Dixheigh)
                {
                    h = maxheigh;
                    w = w * DixLow;
                }
                else if (DixLow == Dixwidth)
                {
                    h = h * DixLow;
                    w = maxwidth;
                }
            }	
    }

}
