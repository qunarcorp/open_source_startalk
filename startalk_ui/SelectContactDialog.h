#ifndef SELECTCONTACTDIALOG_H
#define SELECTCONTACTDIALOG_H

#include "ui_SelectContactDialog.h"
#include "LocalManDialog.h"
#include "SearchResultDialog.h"
#include "GroupVisitorMVD.h"

namespace Biz{
    class CallbackReceiver;
    class RosterItem;
}
class VisitorItem;
class GroupVisitorModel;
class SelectContactDialog : public LocalManDialog
{
    Q_OBJECT

public:
    SelectContactDialog(QWidget *parent = 0);
    ~SelectContactDialog();
    void setGroupList(GroupVisitorModel* pData);
    QList<QPair<QString,QString>> getSelectedItem();
	
	virtual void mouseMoveEvent(QMouseEvent *event);
private slots:
    void onClose(bool);
    void onLeftSelectChanged(const QModelIndex &index);
    void onLeftItemDBClicked(const QModelIndex &index);
    void onRightSelectChanged();
    void onRightItemDBClicked(QListWidgetItem *item);
    void onAddClicked(bool);
    void onDelClicked(bool);
    void onOK(bool);    
    void onCancel(bool);
    void onSearchResult(const QString& text);
    void onSearchTextChanged(const QString & text);

private:
    bool eventFilter(QObject *obj, QEvent *event);
    void AddItem(QString strText);
    void SearchMoveDown();
    void SearchMoveUp();
    void SearchSelected();
    void addNodeToRight(Biz::RosterGroup* rosterGroup);
private:
    Ui::SelectContactDialog ui;
    Biz::CallbackReceiver* mReceiver;
    QMap<QString,QString> mMapNameJid;
    QMap<QString,QString> mMapPinYinName;
    QList<QString> mSelectedList;//save 
    SearchResultDialog* searchResultDlg;

};

#endif // SELECTCONTACTDIALOG_H
