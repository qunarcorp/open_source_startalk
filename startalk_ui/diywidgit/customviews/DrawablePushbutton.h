#pragma  once
#include <QPushButton>
#include "diywidgit/imageloader/ImageLoader.h"

class EmotionUserData : public QObjectUserData
{
public:
    QString m_strShortKey;
    QString m_strPackageId;

    QString m_strImagePath;
    QString m_strUrl;

	bool m_bselect;
};



class DrawablePushButton : public QPushButton , public IDrawableInterface  {
	Q_OBJECT
public:
    DrawablePushButton(QWidget* parent):QPushButton(parent){};
    virtual ~DrawablePushButton(){};

    virtual void draw(const QString& localpath,const QString& remotePath);

    virtual void preLoad();

    virtual void afterLoad();

    virtual void drawDefault(const QString& defaultpic);
	virtual void selected();
public:
signals:
    void sgLoadComplete(const QString& localpath);
 
};

