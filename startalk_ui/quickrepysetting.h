#ifndef QUICKREPYSETTING_H
#define QUICKREPYSETTING_H

#include "LocalManDialog.h"
#include "ui_QuickReplySetting.h"
#include "QuickReplyMsgMgr.h"
#include "Player.h"

namespace Biz{
    class CallbackReceiver; 
}
class QuickRepySetting : public LocalManDialog
{
	Q_OBJECT

public:
	static QuickRepySetting* Inistance();
	void ShowQuickReplySetting();

private:
	QList<QuickReplyMsgItem*> ReadJsonText(const QString& strFilePath);
	void WriteJsonText(const QList<QStringList>& list, const QString& strFilePath);
	static QuickRepySetting* pInstance;
	QuickRepySetting(QWidget *parent=NULL);
	~QuickRepySetting(); 
	Biz::CallbackReceiver* mCallbackReceiver;

private slots:
	void onClose();
	void onAddItem();
	void onModyItem();
	void onDeleteItem();
	void onExportReply();
	void onImportReply();
	void onContentMoveUp();
	void onContentMoveDown();

	void onClickedOk();
	void onClickedCancel();
	void onClickedReply();
	void onClickedGroupMgr();

	void groupSelectChange(const QModelIndex& index);
	void contentSelectChange(const QModelIndex& index);
	void quickReplyGroupDataChange();
	void quickReplyContentDataChange(const QString &groupCid); 

private:
	Ui::QuickRepySettingDialog ui;
	void Init();
	QStringList strAllGroups;
	QString strGroupItem;
	QString strItem;

	QList<QSharedPointer<Biz::QuickReplyGroup>> groupList;
	QList<QSharedPointer<Biz::QuickReplyContent>> contentList;
};

#endif // QUICKREPYSETTING_H
