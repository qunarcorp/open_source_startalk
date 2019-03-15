#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "lrucache_q.hpp"
#include "BizCallback.h"
#include "UtilHelper.h"
namespace Biz
{
    class CallbackReceiver;
}
typedef QString FILECACHEMD5ID;
typedef QString FILELOCALPATH;

#pragma region 装饰器
class IDecorateInterface
{
public:
    virtual void decorate( QObject* obj,const QPixmap& pixmap) = 0;
};

class FullSizeDecorate : public IDecorateInterface
{
public:
    virtual void decorate( QObject* obj,const QPixmap& pixmap);
};
#pragma endregion 装饰器

class IDrawableInterface
{
public:
    virtual void draw(const QString& localpath,const QString& remotePath)   = 0;
    virtual void drawDefault(const QString& defaultpic) = 0;
    virtual void preLoad(){};
    virtual void afterLoad(){};
	virtual void selected(){};
};

class ImageLoader : public QObject
{
public:
    ImageLoader();
    ~ImageLoader();

public:
    void loadImage(const QString& url, QPushButton* image, const QString& defaultPic);
    void loadImage(const QString& url, QAction* action, const QString& defaultPic);
    void loadImage(const QString& url, QLabel* label, const QString& defaultPic); 
    void loadImage(const QString& url, QLabel* label, const QString& defaultPic, IDecorateInterface* scalePolicy); 
    void loadImage(const QString& url, IDrawableInterface* pDrawable,const QString& defaultPic);
private:
    void    loadPixmap(const QString& url,Biz::UnitCallback<QPixmap>* callback);
    void    loadPixmapPath(const QString& url,Biz::UnitCallback<QString>* callback);
    QPixmap postProcessPixmap(const QPixmap& pixmap);
    void    cachePixmapInMemory(const QString& key, const QPixmap& pixmap);
    QPixmap preProcessPixmap(const QPixmap& pixmap);
    QPixmap decode2Pixmap(const QString& localpath);
    void    cachePixmapInDisk(const QString& key,const QString& localpath);
private:
    cache::lru_cache_q<QString,QPixmap>* memoryCache;
    cache::lru_cache_q<QString,QString>* diskCache;
private:
    Biz::CallbackReceiver* mReceiver;
};

typedef Util::SingletonTemplete<ImageLoader> ImageLoaderSingleton; 

#endif // IMAGELOADER_H
