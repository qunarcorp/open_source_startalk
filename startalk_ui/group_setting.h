#ifndef _GROUP_SETTING_H_
#define _GROUP_SETTING_H_
#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include "LocalManDialog.h"
#include "GroupListData.h"
#include "CallbackReceiver.h"
namespace Ui{
    class GroupSetting;
}

class GroupSettingDialog : public LocalManDialog
{
    Q_OBJECT
    enum DSOption
    {
        DSO_INFO = 0x01,
        DSO_LIST = 0x02,
        DSO_SETTING = 0x04,
        DSO_ALL = DSO_INFO | DSO_LIST |DSO_SETTING,
        DSO_SHORT = DSO_INFO | DSO_LIST
    };
public:
    static GroupSettingDialog* getInstance();
private:
    static GroupSettingDialog* instance;
    GroupSettingDialog(QWidget* parent);
    ~GroupSettingDialog();
public:
    void initUi();
    void setupData(const Biz::GroupSetting* const data);
    void setupData(const QString& jid);
    void setOption(DSOption op);
	void setGroupCreator(const QString&creator);
public slots:
    void onQuit(bool b);
    void onCancle(bool b);
    void onTab(bool b);
    void onModifySubject(bool b); 
    void onDestroyGroup(bool);
	void onClickedOkChange();
	void onQuitGroup();
	void updateAvatarGroupHeader(const QString& groupjid);
protected:
    virtual void mousePressEvent(QMouseEvent *);


    virtual bool eventFilter(QObject *, QEvent *);

	void onErCodeShow();
private:
    Ui::GroupSetting* ui;
    QString lastGSubject;
    QString lastPassword;
	QString lastGroupName;
	Biz::CallbackReceiver* mCallbackReceiver;
	QString mGroupCreatorId;
};

#endif