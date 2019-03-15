#pragma once
#include <QObject>
#include <QAudioOutput>
#include <QSharedPointer>
#include <QMediaPlayer>
#include <functional>
#ifndef Q_NO_AMR
#include "amrgit/WavOutput.h"
#endif // Q_NO_AMR


#include "UtilHelper.h"


class VoicePlayer : public QObject
{
	Q_OBJECT
    friend class Util::SingletonTemplete<VoicePlayer> ; 
private:
    VoicePlayer(void);
    ~VoicePlayer(void);
public:
    void playLocalVoice(const QString& voicePath,const std::function<void()>& playFinish);
    void playLocalVoice(
        const QString& voicePath,
        const std::function<void()>& playFinish,
        const std::function<void(int,QString)>& playError);
    void stopCurrentPlayingVoice();
	void PlayVoiceOver(bool bret);

private:
    VoicePlayer& setFinishCallBack(const std::function<void()>& callback);
    VoicePlayer& setErrorCallBack(const std::function<void(int,QString)>& cb);
    void play(const QString& path);
    void stop();
    void reset();
private:
#ifndef Q_NO_AMR
    QSharedPointer<WavOutput> spOutputDevice;
    QSharedPointer<QAudioOutput> spAudioOutput;
#endif //Q_NO_AMR

    std::function<void()> mFinishCb;
    std::function<void(int,QString)> mErrorCb;
	bool mbStopReturn;
    protected slots:
        void onError(QMediaPlayer::Error error);
};
typedef Util::SingletonTemplete<VoicePlayer>  VoicePlayerSingleton;
