#include "QZXing.h"

#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/Binarizer.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/DecodeHints.h>
#include "CameraImageWrapper.h"
#include "imagehandler.h"
#include <QTime>
#include <QUrl>
#include <zxing/qrcode/ErrorCorrectionLevel.h>
#include <QColor>

using namespace zxing;

QZXing::QZXing(QObject *parent) : QObject(parent)
{
    decoder = new MultiFormatReader();
    /*setDecoder(DecoderFormat_QR_CODE |
               DecoderFormat_DATA_MATRIX |
               DecoderFormat_UPC_E |
               DecoderFormat_UPC_A |
               DecoderFormat_EAN_8 |
               DecoderFormat_EAN_13 |
               DecoderFormat_CODE_128 |
               DecoderFormat_CODE_39 |
               DecoderFormat_ITF |
               DecoderFormat_Aztec);*/
    imageHandler = new ImageHandler();
}

QZXing::~QZXing()
{
    if (imageHandler)
        delete imageHandler;

    if (decoder)
        delete decoder;
}

QZXing::QZXing(QZXing::DecoderFormat decodeHints, QObject *parent) : QObject(parent)
{
    decoder = new MultiFormatReader();
    imageHandler = new ImageHandler();

    setDecoder(decodeHints);
}

QString QZXing::decoderFormatToString(int fmt)
{
    switch (fmt) {
      case 1:
          return "AZTEC";

      case 2:
          return "CODABAR";

      case 3:
          return "CODE_39";

      case 4:
          return "CODE_93";

      case 5:
          return "CODE_128";

      case 6:
          return "DATA_MATRIX";

      case 7:
          return "EAN_8";

      case 8:
          return "EAN_13";

      case 9:
          return "ITF";

      case 10:
          return "MAXICODE";

      case 11:
          return "PDF_417";

      case 12:
          return "QR_CODE";

      case 13:
          return "RSS_14";

      case 14:
          return "RSS_EXPANDED";

      case 15:
          return "UPC_A";

      case 16:
          return "UPC_E";

      case 17:
          return "UPC_EAN_EXTENSION";
    } // switch
    return QString();
}

QString QZXing::foundedFormat() const
{
    return foundedFmt;
}

QString QZXing::charSet() const
{
    return charSet_;
}

void QZXing::setDecoder(const uint &hint)
{
    unsigned int newHints = 0;

    if(hint & DecoderFormat_Aztec)
        newHints |= DecodeHints::AZTEC_HINT;

    if(hint & DecoderFormat_CODABAR)
        newHints |= DecodeHints::CODABAR_HINT;

    if(hint & DecoderFormat_CODE_39)
        newHints |= DecodeHints::CODE_39_HINT;

    if(hint & DecoderFormat_CODE_93)
        newHints |= DecodeHints::CODE_93_HINT;

    if(hint & DecoderFormat_CODE_128)
        newHints |= DecodeHints::CODE_128_HINT;

    if(hint & DecoderFormat_DATA_MATRIX)
        newHints |= DecodeHints::DATA_MATRIX_HINT;

    if(hint & DecoderFormat_EAN_8)
        newHints |= DecodeHints::EAN_8_HINT;

    if(hint & DecoderFormat_EAN_13)
        newHints |= DecodeHints::EAN_13_HINT;

    if(hint & DecoderFormat_ITF)
        newHints |= DecodeHints::ITF_HINT;

    if(hint & DecoderFormat_MAXICODE)
        newHints |= DecodeHints::MAXICODE_HINT;

    if(hint & DecoderFormat_PDF_417)
        newHints |= DecodeHints::PDF_417_HINT;

    if(hint & DecoderFormat_QR_CODE)
        newHints |= DecodeHints::QR_CODE_HINT;

    if(hint & DecoderFormat_RSS_14)
        newHints |= DecodeHints::RSS_14_HINT;

    if(hint & DecoderFormat_RSS_EXPANDED)
        newHints |= DecodeHints::RSS_EXPANDED_HINT;

    if(hint & DecoderFormat_UPC_A)
        newHints |= DecodeHints::UPC_A_HINT;

    if(hint & DecoderFormat_UPC_E)
        newHints |= DecodeHints::UPC_E_HINT;

    if(hint & DecoderFormat_UPC_EAN_EXTENSION)
        newHints |= DecodeHints::UPC_EAN_EXTENSION_HINT;

    enabledDecoders = newHints;

    emit enabledFormatsChanged();
}

QString QZXing::decodeImage(QImage &image, int maxWidth, int maxHeight, bool smoothTransformation)
{
    QTime t;
    t.start();
    Ref<Result> res;
    emit decodingStarted();

    if(image.isNull())
    {
        emit decodingFinished(false);
        processingTime = t.elapsed();
        return "";
    }

    CameraImageWrapper *ciw = NULL;
    try {
        if ((maxWidth > 0) || (maxHeight > 0))
            ciw = CameraImageWrapper::Factory(image, maxWidth, maxHeight, smoothTransformation);
        else
            ciw = new CameraImageWrapper(image);

        Ref<LuminanceSource> imageRef(ciw);
        GlobalHistogramBinarizer *binz = new GlobalHistogramBinarizer(imageRef);

        Ref<Binarizer> bz(binz);
        BinaryBitmap *bb = new BinaryBitmap(bz);

        Ref<BinaryBitmap> ref(bb);

        res = decoder->decode(ref, DecodeHints((int)enabledDecoders));

        QString string = QString(res->getText()->getText().c_str());
        if (!string.isEmpty() && (string.length() > 0)) {
            int fmt = res->getBarcodeFormat().value;
            foundedFmt = decoderFormatToString(fmt);
            charSet_ = QString::fromStdString(res->getCharSet());
            if (!charSet_.isEmpty()) {
                QTextCodec *codec = QTextCodec::codecForName(res->getCharSet().c_str());
                if (codec)
                    string = codec->toUnicode(res->getText()->getText().c_str());
            }
            emit tagFound(string);
            emit tagFoundAdvanced(string, foundedFmt, charSet_);
        }
        processingTime = t.elapsed();
        emit decodingFinished(true);
        return string;
    }
    catch(zxing::Exception &e)
    {
        emit error(QString(e.what()));
        emit decodingFinished(false);
        processingTime = t.elapsed();
        return "";
    }
}

QString QZXing::decodeImageFromFile(const QString& imageFilePath, int maxWidth, int maxHeight, bool smoothTransformation)
{
    // used to have a check if this image exists
    // but was removed because if the image file path doesn't point to a valid image
    // then the QImage::isNull will return true and the decoding will fail eitherway.
    QUrl imageUrl(imageFilePath);
    QImage tmpImage = QImage(imageUrl.toLocalFile());
    return decodeImage(tmpImage, maxWidth, maxHeight, smoothTransformation);
}

QString QZXing::decodeImageQML(QObject *item)
{
    return decodeSubImageQML(item);
}

QString QZXing::decodeSubImageQML(QObject *item,
                                  const double offsetX, const double offsetY,
                                  const double width, const double height)
{
    if(item  == NULL)
    {
        processingTime = 0;
        emit decodingFinished(false);
        return "";
    }

    QImage img = imageHandler->extractQImage(item, offsetX, offsetY, width, height);

    return decodeImage(img);
}

QString QZXing::decodeImageQML(const QUrl &imageUrl)
{
    return decodeSubImageQML(imageUrl);
}

QString QZXing::decodeSubImageQML(const QUrl &imageUrl,
                                  const double offsetX, const double offsetY,
                                  const double width, const double height)
{
    QString imagePath = imageUrl.path();
    imagePath = imagePath.trimmed();
    QFile file(imagePath);
    if (!file.exists()) {
        qDebug() << "[decodeSubImageQML()] The file" << file.fileName() << "does not exist.";
        emit decodingFinished(false);
        return "";
    }
    QImage img(imageUrl.path());
    if(!(offsetX == 0 && offsetY == 0 && width == 0 && height == 0)) {
        img = img.copy(offsetX, offsetY, width, height);
    }
    return decodeImage(img);
}

int QZXing::getProcessTimeOfLastDecoding()
{
    return processingTime;
}

uint QZXing::getEnabledFormats() const
{
    return enabledDecoders;
}

QPixmap QZXing::encodeString(const QString& data)
{
    return encodeString(data,QPixmap(),100);
}

QPixmap QZXing::encodeString(const QString& data,int nSize)
{
    return encodeString(data,QPixmap(),nSize);
}

QPixmap QZXing::encodeString(const QString& data,const QPixmap& centericon)
{
    return encodeString(data,centericon,100);
}

#include "qrencode/qrencode.h"
#include <QPainter>
QPixmap QZXing::encodeString(const QString& data,const QPixmap& centericon,int nSize)
{
    //NOTE: I have hardcoded some parameters here that would make more sense as variables.  
    QRcode *qr = QRcode_encodeString(data.toStdString().c_str(), 1, QR_ECLEVEL_M, QR_MODE_8, 1);  
    QPixmap retPixMap(nSize,nSize);
    QPainter painter(&retPixMap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor("white"));  
    painter.setPen(Qt::NoPen);  
    painter.drawRect(0,0,nSize,nSize);  


    if(0!=qr){  
        QColor fg("black");  
      
        
        const int s=qr->width>0?qr->width:1;  
        const double w=nSize;  
        const double h=nSize;  
        const double aspect=w/h;  
        const double lfscale=((aspect>1.0)?h:w)/s;
        int scale = qAbs(lfscale);
        QPixmap rcode(scale*s,scale*s);
        QPainter painter2(&rcode);
        painter2.setBrush(QColor("white"));  
        painter2.setPen(Qt::NoPen);  
        painter2.drawRect(0,0,scale*s,scale*s);  
        painter2.setBrush(QColor("black"));  
        painter2.setPen(Qt::NoPen);  

        for(int y=0;y<s;y++){  
            const int yy=y*s;  
            for(int x=0;x<s;x++){  
                const int xx=yy+x;  
                const unsigned char b=qr->data[xx];  
                if(b &0x01){  
                    const double rx1=x*scale, ry1=y*scale;  
                    QRectF r(rx1, ry1, scale, scale);  
                    painter2.drawRects(&r,1);  
                }  
            }  
        }  
        QRcode_free(qr);  

        painter.drawPixmap((nSize-scale*s)/2,(nSize-scale*s)/2,scale*s,scale*s,rcode);

// 
//         if (!centericon.isNull())
//         {
//             int nCenterSize = nSize/4;
//             painter.setPen(Qt::NoPen);  
//             painter.drawPixmap((nSize-nCenterSize)/2,(nSize-nCenterSize)/2,nCenterSize,nCenterSize,centericon);
//         }
    }  

    qr=0;  
    return retPixMap;
}


