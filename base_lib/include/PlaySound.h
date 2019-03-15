#ifndef PLAYSOUND_H
#define PLAYSOUND_H
#include "qobject.h"
#include <QSound>
#include "UtilHelper.h"
#include <QSoundEffect>
#include <QMediaPlayer>
#include <functional>
#include <QAudioOutput>
class SoundPlayer :
    public QObject
{
    friend class Util::SingletonTemplete<SoundPlayer> ; 
public:
    void setMsgSourcePath(const QString&MsgvoicePath);
    void setNoteSourcePath(const QString&NotevoicePath);
    void playMsgsound(const QString& conversation, quint64 lstm=0);
    void playWelcomesound(const QString& conversation, quint64 lstm=0);
    void quiet();
public:
    static void playSound(const QString& voidPath);


    public Q_SLOTS:
        void onDefaultPlayer();

private:
    SoundPlayer(void);
    ~SoundPlayer(void);
	void setVoiceSource(const QString&conversationId, quint64 lasttm);
private:
    QMediaPlayer mEffectPlay; //普通消息的播放器
    QMediaPlayer mNoteEffectPlay; //Note消息的播放器

};

typedef Util::SingletonTemplete<SoundPlayer>  PlaySoundsingleton;

#endif // PLAYSOUND_H