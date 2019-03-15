#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include "LocalManDialog.h"
#include "ui_AddGroupDialog.h"

class AddGroupDialog : public LocalManDialog
{
    Q_OBJECT

public:
    AddGroupDialog(QWidget *parent = 0);
    ~AddGroupDialog();
    QString getGroupName();
    QList<QPair<QString,QString>> getSelectedItem();
	void AddOneItem(const QString& id);
	void SetBtnRemove(bool bret);
private slots:
    void onCancel(bool);
    void onOK(bool);
    void onClose(bool);
    void onAddMember(bool);
    void onRemoveMember(bool);
	void onClickedItem(QListWidgetItem *item);
	

private:
    Ui::AddGroupDialog ui;
    QList<QPair<QString,QString>>  resultList;
	QString m_strFirstOne;
};

#endif // ADDGROUPDIALOG_H
