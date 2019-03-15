#ifndef USERMINIPROFILE_H
#define USERMINIPROFILE_H

#include <QWidget>
#include "ui_userminiprofile.h"

class UserMiniProfile : public QWidget
{
	Q_OBJECT

private:
    UserMiniProfile(QWidget *parent = 0);
    ~UserMiniProfile();
public:
    static UserMiniProfile* getInstance();
    void setUserid(const QString& userid, QString strUserName="", QString strEmal=""/*Biz::WebUserInfor webInfor=*/);
    void autoshow();

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    virtual void showEvent(QShowEvent *event);
public:

private:
    static UserMiniProfile* sProfileDialog;
	void showAvatar();
	void setSex(const QString&userid);
private:
    Ui::UserMiniProfile ui;
    QString userId;
    QString dispName;
	QMovie *m_GifPlayer;
	QPixmap mDefaultpix;
signals:
    void sgChatDialog( const QString& userID, const QString& displayName );
    void sgSendFile( const QString& userID);
	public slots:
		void onHDPortraitUpdate(const QString& userjid);
		void onUserMoodInforChange(const QString& userid, const QString& moodInfo);

		virtual void hideEvent( QHideEvent * );
		void onPictureDownloadProgressDisplay(const QString&userid, const qint64 done, const qint64 total);

		




};

#endif // USERMINIPROFILE_H
