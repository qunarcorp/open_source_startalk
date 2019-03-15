#ifndef QUICKREPLYEDITITEMDLG_H
#define QUICKREPLYEDITITEMDLG_H

#include "LocalManDialog.h"
#include "ui_QuicklyEditItemDialog.h"
#include "Player.h"

class QuickReplyEditItemDlg : public LocalManDialog
{
	Q_OBJECT

public:
	QuickReplyEditItemDlg(int type, QList<QSharedPointer<Biz::QuickReplyGroup>> groupInfoList, QWidget *parent=NULL);
	~QuickReplyEditItemDlg();

	void setSelectGroupIndex(int groupIndex);
	void SetModyContent(const QSharedPointer<Biz::QuickReplyContent> &contentInfo);
	void getContent(QStringList& strItem);
	
private slots:
	void onClose();
	void onClickedOk();
	void onClickedCancle();

private:
	Ui::QuicklyItemEditDialog ui;
	TitlebarWidget *titlebar;
	int ntype;
	QList<QSharedPointer<Biz::QuickReplyGroup>> mGroupInfoList;
	QSharedPointer<Biz::QuickReplyContent> mContentInfo;
};

#endif // QUICKREPLYEDITITEMDLG_H
