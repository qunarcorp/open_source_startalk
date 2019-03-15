#include "AudioPlayer.h"

#include <QFile>
#include "VoiceHelper.h"




VoicePlayer::VoicePlayer(void)
{
	mbStopReturn = true;
}

VoicePlayer::~VoicePlayer(void)
{

}

VoicePlayer& VoicePlayer::setFinishCallBack(const std::function<void()>& callback)
{
    mFinishCb = callback;
    return *this;
}

void VoicePlayer::onError(QMediaPlayer::Error error)
{
    
}

VoicePlayer& VoicePlayer::setErrorCallBack(const std::function<void(int,QString)>& cb)
{
    mErrorCb = cb;
    return *this;
}


void VoicePlayer::play(const QString& filePath)
{
#ifndef Q_NO_AMR
    QFile amrfile(filePath);
    if (!amrfile.open(QIODevice::ReadOnly))
    {
        mErrorCb(-1,"");
        return;
    }
    
    QByteArray m_buffer = amrfile.readAll();
    QSharedPointer<QByteArray> spArrData(new QByteArray);

    if(VoiceHelper::amrBufferToWavBuffer((unsigned char*)m_buffer.data(), m_buffer.size(), *spArrData.data()))
    {
        if (spArrData->size()==0)
        {
            mErrorCb(-1,"");
            return;
        }
        QAudioFormat format;  
        format.setSampleRate(8000);  
        format.setChannelCount(1);  
        format.setSampleSize(16); 
        format.setCodec("audio/pcm");  
        format.setByteOrder(QAudioFormat::LittleEndian); 
        format.setSampleType(QAudioFormat::UnSignedInt);  
        if (!spOutputDevice.isNull())
        {
            spOutputDevice->disconnect();
        }

        spAudioOutput.reset(new QAudioOutput(format));
        spOutputDevice.reset(new WavOutput(spArrData.data ()));

        WavOutput* od = spOutputDevice.data();
        connect(od,&WavOutput::sgFinish,[this,od,spArrData](){
			//之前的聊天框是否销毁，如果没销毁，播完了后，再返回去播放
			//如果销毁，就不要回去了
			if (mbStopReturn)
			{
				mFinishCb();
			}
            
        });
        spAudioOutput->start(spOutputDevice.data());
    }
#endif //Q_NO_AMR
}

void VoicePlayer::stop()
{
#ifndef Q_NO_AMR
    if (!spAudioOutput.isNull ())
    {
        spAudioOutput->stop ();
        mFinishCb();
    }
#endif //Q_NO_AMR
}

void VoicePlayer::reset()
{
#ifndef Q_NO_AMR
    if (!spAudioOutput.isNull ())
    {
        spAudioOutput->disconnect ();
    }
#endif //Q_NO_AMR
}

void VoicePlayer::playLocalVoice(const QString& voicePath,const std::function<void()>& playFinish)
{
    reset ();
    setFinishCallBack (playFinish);
    play (voicePath);
}

void VoicePlayer::playLocalVoice(const QString& voicePath, const std::function<void()>& playFinish, const std::function<void(int,QString)>& playError)
{
    reset ();
    setFinishCallBack (playFinish);
    setErrorCallBack (mErrorCb);
    play (voicePath);
}

void VoicePlayer::stopCurrentPlayingVoice()
{
    stop ();
    mFinishCb();
}

void VoicePlayer::PlayVoiceOver( bool bret )
{
	mbStopReturn = bret;
}

