#ifndef VIDIOANDAUDIOMANAGE_H
#define VIDIOANDAUDIOMANAGE_H

#include "managerbase.h"
namespace Biz
{
	class VidioAndAudioManager : public ManagerBase
	{
		Q_OBJECT

	public:
		VidioAndAudioManager();
		~VidioAndAudioManager();
	public:
		virtual void initManager();
		virtual void unInitManager();
		void getVidioInfor(Biz::UnitCallback<QString>* callback);
	public slots:
	void onConnected();
signals:
	void sgVideoOrAudeoRecievPing(const QString& conversaion, int type);
	//音视频的信息
	void sgRecievedSingle(const QString&json, const QString&id);
	
	void sgStartVideoOrAudeobyRespon(const QString&json, int type);
	private:
		QString mVidioInforJson;
		CallbackReceiver *mCallreceive;

	};

}


#endif // VIDIOANDAUDIOMANAGE_H
