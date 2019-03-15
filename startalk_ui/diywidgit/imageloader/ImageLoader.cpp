#include "ImageLoader.h"
#include "CallbackReceiver.h"
#include "BizCallback.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "DownloadManager.h"
#include "UiHelper.h"
#include "ImageHelper.h"
ImageLoader::ImageLoader()
    : QObject(NULL)
{
    QHash<QString,QPixmap>  pixmaphash;
    cache::lru_cache_q<int,int>* pint= new cache::lru_cache_q<int,int>(100);
    memoryCache = new cache::lru_cache_q<QString,QPixmap>(100);
    diskCache   = new cache::lru_cache_q<QString,QString>(2000);
    mReceiver = new Biz::CallbackReceiver(this);
}

ImageLoader::~ImageLoader()
{

}


void ImageLoader::loadImage(const QString& url, QPushButton* image, const QString& defaultPic)
{

}

void ImageLoader::loadImage(const QString& url, QAction* action, const QString& defaultPic)
{

}

void ImageLoader::loadImage(const QString& url, QLabel* label, const QString& defaultPic)
{
    if (NULL!=label)
    {
        // 先显示默认图片
        QPixmap defaultPixmap;
        defaultPixmap.load(defaultPic);
        label->setPixmap(defaultPixmap);

        auto callback = mReceiver->createCallback<QPixmap>([this,label](const QPixmap& pixmap){
            if (!pixmap.isNull())
            {
                label->setPixmap(pixmap);
            }
        },[]{});
        
        loadPixmap(url,callback);
    }
}


void ImageLoader::loadImage(const QString& url, QLabel* label, const QString& defaultPic, IDecorateInterface* scalePolicy)
{
    if (NULL == scalePolicy)
    {
        return loadImage(url,label,defaultPic);
    }

    if (NULL!=label)
    {
        // 先显示默认图片
        QPixmap defaultPixmap;
        defaultPixmap.load(defaultPic);
        scalePolicy->decorate(label,defaultPixmap);

        auto callback = mReceiver->createCallback<QPixmap>([this,label,scalePolicy](const QPixmap& pixmap){
           scalePolicy->decorate(label,pixmap);
        },[]{});

        loadPixmap(url,callback);
    }
}

void ImageLoader::loadImage(const QString& url, IDrawableInterface* pDrawable,const QString& defaultPic)
{
    if (NULL!=pDrawable)
    {
        // 先显示默认图片
        pDrawable->drawDefault(defaultPic);
        pDrawable->preLoad();

        auto callback = mReceiver->createCallback<QString>([this,pDrawable,url](const QString& localpath){
            pDrawable->afterLoad();
           pDrawable->draw(localpath,url);
          
        },[]{});

        loadPixmapPath(url,callback);
    }
}


QPixmap ImageLoader::postProcessPixmap(const QPixmap& pixmap)
{
    return pixmap;
}

void ImageLoader::cachePixmapInMemory(const QString& key, const QPixmap& pixmap)
{
    memoryCache->put(key,pixmap);
}

QPixmap ImageLoader::preProcessPixmap(const QPixmap& pixmap)
{
    return pixmap;
}

QPixmap ImageLoader::decode2Pixmap(const QString& localpath)
{
    QImage img = Biz::ImageHelper::loadImageFromPath (localpath);
    return QPixmap::fromImage(img);
}

void ImageLoader::cachePixmapInDisk(const QString& key,const QString& localpath)
{
    diskCache->put(key,localpath);
}

void ImageLoader::loadPixmap(const QString& url,Biz::UnitCallback<QPixmap>* callback)
{
    try
    {
        if (NULL==callback) return;

        // 本地文件保存原则为url的md5值
        FILECACHEMD5ID urlmd5 = Biz::ConfigureHelper::GetBufferMD5(url); 
		
		
        // 1 如果内存缓存中有次文件 后处理->显示
        if (memoryCache->exists(urlmd5))
        {
            QPixmap retvalue = memoryCache->get(urlmd5);
            retvalue = postProcessPixmap(retvalue);
            callback->doCompleted(retvalue);
            return;
        }
        // 2 如果文件缓存中有此文件 加载本地文件 -> 预处理pixmap ->内存缓存->后处理->显示
        if (diskCache->exists(urlmd5))
        {
            QString localfilepaht = diskCache->get(urlmd5);
            if (QFile::exists(localfilepaht))
            {
                QPixmap retvalue = decode2Pixmap(localfilepaht);
                retvalue = preProcessPixmap(retvalue);
                cachePixmapInMemory(urlmd5,retvalue);
                retvalue = postProcessPixmap(retvalue);
                callback->doCompleted(retvalue);
                return;
            }
        }
        // 3 都没有,下载文件 -> 文件缓存 -> 加载本地文件 -> 预处理pixmap ->内存缓存->后处理->显示
        Biz::UnitCallback<QString>* downCb = mReceiver->createCallback<QString>([this,urlmd5,callback](const QString& localPath){
            cachePixmapInDisk(urlmd5,localPath);
            QPixmap retvalue = decode2Pixmap(localPath);
            retvalue = preProcessPixmap(retvalue);
            cachePixmapInMemory(urlmd5,retvalue);
            retvalue = postProcessPixmap(retvalue);
            callback->doCompleted(retvalue);
        },[]{});

        Biz::Session::getDownLoadManager()->downloadFile(url,urlmd5,"","",false,downCb);
    }
    catch (...)
    {

    }

}

void ImageLoader::loadPixmapPath(const QString& url,Biz::UnitCallback<QString>* callback)
{
    try
    {
        if (NULL==callback) return;

        // 本地文件保存原则为url的md5值
        FILECACHEMD5ID urlmd5 = Biz::ConfigureHelper::GetBufferMD5(url); 
		QString fileName = Biz::ConfigureHelper::getImageLocalSaveName(url);
        // 2 如果文件缓存中有此文件 加载本地文件 -> 预处理pixmap ->内存缓存->后处理->显示
        if (diskCache->exists(urlmd5))
        {
            QString localfilepaht = diskCache->get(urlmd5);
            if (QFile::exists(localfilepaht))
            {
                callback->doCompleted(localfilepaht);
                return;
            }
        }
        // 3 都没有,下载文件 -> 文件缓存 -> 加载本地文件 -> 预处理pixmap ->内存缓存->后处理->显示
        Biz::UnitCallback<QString>* downCb = mReceiver->createCallback<QString>([this,urlmd5,callback](const QString& localPath){
            cachePixmapInDisk(urlmd5,localPath);
            callback->doCompleted(localPath);
        },[callback]{
                callback->doCompleted("");
        });
        Biz::Session::getDownLoadManager()->downloadFile(url,fileName,"","",false,downCb);
    }
    catch (...)
    {

    }
}

void FullSizeDecorate::decorate( QObject* obj,const QPixmap& pixmap)
{
    QLabel* playbol = dynamic_cast<QLabel*>(obj);
    if (NULL!=playbol && !pixmap.isNull())
    {
        playbol->setScaledContents(true);
        playbol->setPixmap(pixmap);
    }
}
