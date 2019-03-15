#include "Emotionpushbutton.h"

EmotionPushButton::EmotionPushButton(QWidget *parent)
	: QPushButton(parent),imagewidget(NULL),strImagePath("")
{

}

EmotionPushButton::~EmotionPushButton()
{

}

void EmotionPushButton::enterEvent( QEvent * )
{
	if (!imagewidget)
	{
		imagewidget = new QWidget(this);
		/*this->setAutoFillBackground(true);
		QPalette palette;

		QImage img;
		img.load(strImagePath);
		QPixmap pixmapToShow = QPixmap::fromImage(img);        
		palette.setBrush(QPalette::Background,QBrush(pixmapToShow));

		this->setPalette(palette);*/
		QRect rect = this->geometry();
		imagewidget->setGeometry(rect);
		imagewidget->setStyleSheet("background-color: red");
	}
	

	

}

void EmotionPushButton::setImagePath(const QString&strpath)
{
	strImagePath = strpath;
}

void EmotionPushButton::leaveEvent( QEvent * )
{
	if (imagewidget)
	{
		delete imagewidget;
		imagewidget = NULL;
	}
}
