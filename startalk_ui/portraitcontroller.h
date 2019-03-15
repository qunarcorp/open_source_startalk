#ifndef PORTRAITCONTROLLER_H
#define PORTRAITCONTROLLER_H

#include "ControllerBase.h"
#include "SystemDefine.h"

namespace Biz{
	class CallbackReceiver;
	class GeneralCallback;

}

namespace MainApp
{

// 	extern const int HDEAULT_IMAGE_SIZE;
 	const int DEAULT_IMAGE_SIZE = 90;
// 	extern const QString DEFAULT_PATH_ROBOT;
// 	extern const QString DEFAULT_PATH_USER;
// 	extern const QString DEFAULT_PATH_GROUP;
// 	extern const QString DEFAULT_PATH_ROBOT_NOTICE;
// 	extern const QString DEFAULT_PATH_ROBOT_SUBJECT;

	class portraitcontroller : public ControllerBase
	{
		Q_OBJECT

	public:
		portraitcontroller();
		portraitcontroller(QObject *parent);
		~portraitcontroller();
		virtual void initController();
		virtual void unInitController();

	public:
		QPixmap getSinglePixmap(const QString& id, int scaledSize = DEAULT_IMAGE_SIZE);
		QPixmap getGroupPixmap(const QString& id, int scaledSize = DEAULT_IMAGE_SIZE);

	private:
		QPixmap getSingleDefaultPixmap(int scaledSize=DEAULT_IMAGE_SIZE);
		QPixmap getGroupDefaultPixmap(int scaledSize=DEAULT_IMAGE_SIZE);


	private:
		Biz::CallbackReceiver* mReceiver;
	};
}
#endif // PORTRAITCONTROLLER_H
