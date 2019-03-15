#pragma once
#include "WebViewCommObject.h"
class WebPage;

class InnerWebBrowserrObject : public WebViewCommObject
{
    Q_OBJECT
public:
    InnerWebBrowserrObject(QObject* parent=NULL);
    ~InnerWebBrowserrObject(void);
public:
    // native to js
    void audioDownloadProgress(WebPage* page,const QString& url,const QString& progress);
    void audioPlayerReady( WebPage* page,const QString& url);
    void audioStartPlay( WebPage* page,const QString& url);
    void audioFinishPlay( WebPage* page,const QString& url);
    void audoPlayError( WebPage* page,const QString& url,const QString& erorcode);// 0下载失败，1播放失败
public:
     Q_INVOKABLE void getUserInfoFromClient();
     Q_INVOKABLE void playAudio(const QString& url){emit sgPlayAudio (url);};
     Q_INVOKABLE void stopAudio(){emit sgStopAudio ();};
signals:
    // js to native
    void sgPlayAudio(const QString& url);
    void sgStopAudio();
   
};

