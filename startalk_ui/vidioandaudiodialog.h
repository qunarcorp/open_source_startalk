#ifndef VIDIOANDAUDIODIALOG_H
#define VIDIOANDAUDIODIALOG_H

#include "LocalManDialog.h"
#include "ui_vidioandaudiodialog.h"
#include "WebPage.h"
#include "BizCallback.h"
#include "CallbackReceiver.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class ChatCommObject;

enum AudeoVidioType
{
	AUDEOTYPE,
	VIDEOTYPE
};

class VidioAndAudioDialog : public LocalManDialog
{
	Q_OBJECT

public:
	VidioAndAudioDialog(QWidget *parent = 0);
	~VidioAndAudioDialog();
	void onShowDlg(const QString& conversationId, bool bretflag=false);
	void callVidioOrAudio(int type);
	void callVidioOrAudioStart(int type);
	void setUrl(const QString& url);
	void setRoomVideoParam(const QString& uuid, const QString& topic, quint64 starttm );
	void setWindowsDefaultSize();
	void setStartVideoRoom(const QString& roomid);
	void setRoomTitle(const QString&roomtitle);
public slots:
	void onMin();
	void onClose();
	void onLoadHtmlFinish();
	void onRecievedSingle(const QString& json, const QString&id);
	void OnVideoSendSingnal(const QString&json, const QString&id);
	void OnCloseRtcWindow(const QString&id);
	void onWriteLocalLog(const QString&id, const QString&log);
	void onStartVideoSound(const QString&id);
	void onStopVideoSound(const QString&id);
	void onVideoOrAudeoRecievPing(const QString& conversation, int type);
	void OnCloseVideoRoom(const QString& roomid);
	void onFullScreenWindow(const QString&roomid, bool bflag);
private:
	void setTitle(int type);
private:
	Ui::VidioAndAudioDialog *ui;

	ChatCommObject* mwebrtcCommObject;

	WebPage *mPage;
	Biz::CallbackReceiver* mReceiver;
	QString m_conversationId;
	QMediaPlayer mEffectPlay;
	QMediaPlaylist mplaylist;
	QString mUrl;
	QString mroomid;
	QSize mdefaultsize;
protected:
	
signals:
	void sgLoadFinished(const QString&id);

	

	

};

#endif // VIDIOANDAUDIODIALOG_H
