#ifndef EMOTIONPUSHBUTTON_H
#define EMOTIONPUSHBUTTON_H

#include <QPushButton>

class EmotionPushButton : public QPushButton
{
	Q_OBJECT

public:
	EmotionPushButton(QWidget *parent=0);
	~EmotionPushButton();

	virtual void enterEvent( QEvent * );
	void setImagePath(const QString&strpath);

	virtual void leaveEvent( QEvent * );

private:
	QWidget *imagewidget;
	QString strImagePath;

};

#endif // EMOTIONPUSHBUTTON_H
