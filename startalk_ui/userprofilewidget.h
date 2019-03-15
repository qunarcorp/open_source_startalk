#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QWidget>
#include "UtilHelper.h"
#include "LocalManDialog.h"



namespace Ui
{
    class UserProfileWidget;
}

namespace Biz
{
    class CallbackReceiver;
}

class UserProfileWidget : public LocalManDialog
{
	Q_OBJECT
        friend class Util::SingletonTemplete<UserProfileWidget> ;
public:
    UserProfileWidget* setUser(const QString& userid);
	void ShowWidget();
	void showzl();
protected:
    virtual bool eventFilter(QObject *obj, QEvent *e);
private:
    UserProfileWidget(QWidget *parent = 0);
    ~UserProfileWidget();
private:
    void resetData();
    void setData();
	void showAvatar();
	void setSex(const QString&userid);
private:
    Ui::UserProfileWidget* ui;
    Biz::CallbackReceiver* mpReceive;
    QString mJid;
	QMovie* m_GifPlayer;
    private slots:
        void onLinkClicked(const QString& link);
        void onUserVcardChange(const QStringList& userids);
        void onChangeAvatarClicked(bool bcheck);
		void onUserMoodInforChange(const QString& userid, const QString& moodinfo);
		void onUserPortraitUpdate(const QString& userid);
		void onClose(bool bret);

};

typedef Util::SingletonTemplete<UserProfileWidget>  UserProfileWidgetSingleton;

#endif // USERPROFILEWIDGET_H
