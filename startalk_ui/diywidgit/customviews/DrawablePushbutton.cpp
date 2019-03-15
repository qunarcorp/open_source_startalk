#include "DrawablePushbutton.h"

void DrawablePushButton::draw(const QString& localpath,const QString& remotePath)
{
    EmotionUserData* userData = dynamic_cast<EmotionUserData*>(this->userData(Qt::UserRole));
    if (NULL!=userData)
    {
        userData->m_strImagePath = localpath;
        QPixmap pixmapToShow(userData->m_strImagePath);    
        pixmapToShow.setDevicePixelRatio(1.0);
        this->setIcon(QIcon(pixmapToShow));
       

        if (localpath.isEmpty())
        {
            this->setText(QStringLiteral("加载失败"));
            this->setEnabled(false);
        }

        emit sgLoadComplete(localpath);
       
    }
}

void DrawablePushButton::preLoad()
{
    this->setText(QStringLiteral("加载中"));
    this->setEnabled(false);
}

void DrawablePushButton::afterLoad()
{
    this->setText("");
    this->setEnabled(true);
}

void DrawablePushButton::drawDefault(const QString& defaultpic)
{
}

void DrawablePushButton::selected()
{
	bool bret = this->isChecked();
	if (bret)
	{
		this->setStyleSheet("background-color: rgb(170, 0, 255);");
	}
}
