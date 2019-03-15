#ifndef SETTINGDETAIL_H
#define SETTINGDETAIL_H

#include <QWidget>
#include "localmanwidget.h"
namespace Ui {class SettingDetail;};

#include "settinghotkeydialog.h"

#include "define.h"

class ProgressDialog;
namespace Biz
{
    class CallbackReceiver;
}


enum MessageNotifyOption
{
    MNO_
};

class SettingDetail : public LocalManWidget
{
    Q_OBJECT
public:
    static SettingDetail* instance();
    void showSetting(bool flag = false);
	static QString KPushInfoDic;
	
private:
    SettingDetail(QWidget *parent = 0);
    ~SettingDetail();
    static SettingDetail* pInstance;
    public slots:
        void onSyetemSetting();
        void onProfileSetting();
		void messageClicked();
		void screenClicked();
		void searchClicked();
		void onOkHotKey(const QString&strhotkey, int type);
		void onmbordHotKey();
        void onCheckUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& updateinfo);
		void onVoiceSetting();
		
signals:
        void sgClientUpdate(const QString& strCurVersion, bool autocheck);
protected:
    void loadConfigration();
    
private:
	void setPushStatus();
	void initPush();
    void innerConnect();
    void innerDisconnect();
	void SetEditHotKey(bool bRet);
	void OnSetRegisterOrUnRegister(bool bret);

    Ui::SettingDetail *ui;
	SettingHotKeyDialog *dlg;
    ProgressDialog* progressDialog;
    Biz::CallbackReceiver* mReceiver;
	
private slots:
	void onClose(bool bret);
    void onProgressDisplay(const qint64 done, const qint64 total);
    void onTabBtnClicked(bool);

    void onWorkStatusClicked(bool bcheck);
	void onCollectLogsInfo(const QString& infor);
	
};

#endif // SETTINGDETAIL_H
