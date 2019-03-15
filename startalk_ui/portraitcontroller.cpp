#include "portraitcontroller.h"
#include "portraitmanager.h"
#include "Session.h"
#include <QPixmap>

namespace MainApp
{
	portraitcontroller::portraitcontroller(QObject *parent)
		: ControllerBase(parent)
		,mReceiver(new CallbackReceiver(this))
	{

	}

	portraitcontroller::portraitcontroller()
		: ControllerBase(NULL)
		,mReceiver(new CallbackReceiver(this))
	{

	}

	portraitcontroller::~portraitcontroller()
	{
		delete mReceiver;
		mReceiver = NULL;
	}

	void portraitcontroller::initController()
	{

	}

	void portraitcontroller::unInitController()
	{

	}

	QPixmap portraitcontroller::getSinglePixmap(const QString& id,int scaledSize )
	{
		//然后异步获取图片
		auto getsuccessportraint = [this](const QPixmap pixmap){
			if (!pixmap.isNull())
			{
				emit ;
			}
		};

		auto getfailportraint = [this]{};



 		auto callback = mReceiver->createCallback<QPixmap>(getsuccessportraint, getfailportraint);
 		Biz::Session::getPortraitManager()->getPixmap(id, scaledSize, callback);

		//直接给返回一个默认的图片
		return getSingleDefaultPixmap(scaledSize);
	}

	QPixmap portraitcontroller::getGroupPixmap( const QString& id, int scaledSize )
	{
		return QPixmap("");
	}

	QPixmap portraitcontroller::getSingleDefaultPixmap( int scaledSize/*=DEAULT_IMAGE_SIZE*/ )
	{
		return  QPixmap(QString::fromUtf8(":/Images/default_header.png"));
	}

	QPixmap portraitcontroller::getGroupDefaultPixmap( int scaledSize/*=DEAULT_IMAGE_SIZE*/ )
	{
		return  QPixmap(QString::fromUtf8(":/Images/im_default_header.png"));
	}

}