#ifndef QUICKREPLYGROUPMGR_H
#define QUICKREPLYGROUPMGR_H
 
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout> 
#include <QtWidgets/QHBoxLayout> 
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include "LocalManDialog.h" 
#include "TitlebarWidget.h"
#include "Player.h"

namespace Biz{
    class CallbackReceiver; 
}

class QuickReplyGroupEditDlg : public LocalManDialog
{
	Q_OBJECT 
public:
	QuickReplyGroupEditDlg(QWidget *parent,int opt);
	~QuickReplyGroupEditDlg(); 

	int optionType; // 1、新增; 2、修改;

	void setGroupInfo(const QSharedPointer<Biz::QuickReplyGroup> &groupItem);

private:
	QSharedPointer<Biz::QuickReplyGroup> editGroupItem;

private: 
	void setupUi(); 
	 
    QWidget *widget_bk;
    TitlebarWidget *titlebar;   
    QLabel *groupNameLabel;
    QTextEdit *groupNameTextEdit;
	QWidget *bottomBtnView;
	QHBoxLayout *hBoxLayout;
	QSpacerItem *bottomSpacerItem;
	QPushButton *pbSaveBtn;
	QPushButton *pbCancelBtn;
private slots:
	void onClose();
	void onSaveGroup();
	void onCancelGroup();
};

class QuickReplyGroupMgr : public LocalManDialog
{
	Q_OBJECT

public:
	QuickReplyGroupMgr(QWidget *parent = 0);
	~QuickReplyGroupMgr();
	
private: // 业务逻辑相关
	QList<QSharedPointer<Biz::QuickReplyGroup>> groupInfoList;
	void loadQuickReplyGroupData(); 
	Biz::CallbackReceiver* mCallbackReceiver;

private: // 界面相关
	void setupUi();  
    QWidget *widget_bk;
    TitlebarWidget *titlebar; 
	QListWidget *groupListWidget; 
	QWidget *rigthOptionView; 
    QVBoxLayout *verticalLayout;
    QPushButton *pbAdd;
    QPushButton *pbMody;
    QPushButton *pbDelete;
    QPushButton *pbMoveTop;
    QPushButton *pbMoveDown;
	QWidget	*bottomBtnView;
	QHBoxLayout *hBoxLayout;
	QSpacerItem *bottomSpacerItem;
	QPushButton *pbSaveBtn;
	QPushButton *pbCancelBtn;

signals:
	void sgQuickReplyGroupChange(); 

private slots:
	void onClose(); 
	void onAddGroup();
	void onModyGroup();
	void onDeleteGroup();
	void onMoveUpGroup();
	void onMoveDownGroup();
	void onSaveGroup();
	void onCancelGroup();

};

#endif // QUICKREPLYGROUPMGR_H
