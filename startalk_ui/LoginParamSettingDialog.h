#ifndef LOGINPARAMSETTINGDIALOG_H
#define LOGINPARAMSETTINGDIALOG_H

#include <QWidget>
#include "localmanwidget.h"
namespace Ui
{
    class LoginParamSettingDialog;
}

namespace Biz{
    class CallbackReceiver;
}

class LoginParamSettingDialog : public LocalManWidget
{
    Q_OBJECT

public:
    LoginParamSettingDialog(QWidget *parent = 0);
    ~LoginParamSettingDialog();

public:
    void autoshow(QPoint point);
private:
    void setPreViewVisible(bool visible);
    void initData();
    void _restart();
private:
    Ui::LoginParamSettingDialog* ui;
    Biz::CallbackReceiver* mReceiver;
    public slots:
        void onApplyConfig(bool);
        void onResetConfig(bool);
        void onPreviewConfig(bool);
        void onPbEnableChanged(bool);
        void onBetaEnableChanged(bool);
		void onNavManager(bool);
		void onLoginDialogClose(bool);
};

#endif // LOGINPARAMSETTINGDIALOG_H
