#ifndef ACCOUNTLISTWIDGET_H
#define ACCOUNTLISTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "AccountData.h"
#include <QListWidgetItem>
#include "ListWidgetBaseAdapter.h"

namespace Ui
{
	class AccountListWidget;
}

class QDeleteButton:public QPushButton
{
	Q_OBJECT
public:
	QDeleteButton(QWidget *widget=NULL):QPushButton(widget)
	{m_Index=0; installEventFilter(this);};
	~QDeleteButton() {};
	void setIndex(int index) {m_Index = index;}
protected:
	 bool eventFilter(QObject *obj, QEvent *event);
signals:
	 void sgdeleteclick(int nIndex);
private:
	int m_Index;

};

class AccountItemView:public QWidget
{
	Q_OBJECT
public:
	AccountItemView();
	~AccountItemView();
	AccountItemView(const AccountItemView&account);
	QLabel *m_plabel;
	/*QPushButton*m_pb;*/
	QDeleteButton *m_pb;
	int nIndex;
};

class AccountListWidgetAdapter :public ListWidgetBaseAdapter
{
	Q_OBJECT
public:
	
	enum GroupQuitItemData
	{
		AccountItemDataBase = ListWidgetBaseAdapterUserRoleBase,
		AccountItemDataRangeID,
		AccountItemDataRangeLoginAccount,
		AccountItemDataRangesavedPassword,
		AccountItemDataRangeUserID,
		AccountItemDataRangeIsSaveAccount,
		AccountItemDataRangeIsAutoLogin,
		AccountItemDataRangeDomain,
		AccountItemDataRangeNAVAddr,
		AccountItemDataRangeLastTime,
		AccountItemDataRangeIndex
	};
public:
	AccountListWidgetAdapter(QAbstractItemView* parent);
	~AccountListWidgetAdapter();
	virtual QWidget* CreateNewWidget(const QModelIndex& index);
	virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);

	void setList(const QList<QSharedPointer<Biz::LoginAccountConfigInfo>>& accountlist);
	void deleteItem(const QString& id);
	void setClear();
signals:
	void sgLoginAccountDelete(const QString&, const QString&, const QString&);
private:
	QList <AccountItemView*> mpAccountItemlist;
};

class AccountListWidget : public QWidget
{
	Q_OBJECT

public:
	AccountListWidget(QWidget *parent=NULL);
	~AccountListWidget();
	void setItemSize(const QSize& size);
	void setList(const QList<QSharedPointer<Biz::LoginAccountConfigInfo>>& accountlist);
protected:
	virtual void showEvent( QShowEvent * );

public slots:
	void onItemClicked(QListWidgetItem *item);
	void onLoginAccountDelete(const QString&loginaccount , const QString&loginpwd, const QString&navaddr);
signals:
	void sgAccountItemSelected(const QSharedPointer<Biz::LoginAccountConfigInfo>& loginaccount);
private:
	Ui::AccountListWidget *ui;
	int m_ItemWidth;
	int m_ItemHeight;

	AccountListWidgetAdapter* m_pAdapter;
};

#endif // ACCOUNTLISTWIDGET_H
