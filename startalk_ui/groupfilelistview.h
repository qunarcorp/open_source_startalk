#ifndef GROUPFILELISTVIEW_H
#define GROUPFILELISTVIEW_H

#include <QWidget>
#include "LocalManDialog.h"
#include "UtilHelper.h"
#include "ListWidgetBaseAdapter.h"
#include <QTreeWidgetItem>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

class GroupFileOperator;
namespace Ui {class GroupFileListView;};

namespace Biz {
    class CallbackReceiver;
    class MessageListData;
    class XmppMessage;
}

class GroupFileMessageItem : public QTreeWidgetItem
{
public:

    virtual bool operator <(const QTreeWidgetItem &other) const
    {
        return true;
    }
};


class GroupListFileItemView : public QWidget
{
    Q_OBJECT
public:
    GroupListFileItemView(QWidget* parent);
    ~GroupListFileItemView();
    QPushButton* createFuntionButton(QWidget* parent);
    void setMessage(const QSharedPointer<Biz::XmppMessage>& spMessage);
public:
    QLabel*     m_pIconLabel;
    QLabel*     m_pTitle;
    QPushButton* m_pBtnDownload;
    QPushButton* m_pBtnOpen;
    QPushButton* m_pLocaltion;
    QProgressBar* m_pProgressBar;
private:
    QSharedPointer<GroupFileOperator> m_spFileOperator;
    public slots:
        void onDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total);
        void onDownloadFileClicked(bool b);
        void onSaveAsClicked(bool b);
		void onDownloadProgressFinish(const QString&key, const QString& fileName, const QString& filePath);
};

class GroupFileListViewAdapter : public ListWidgetBaseAdapter
{
    enum GroupFileListItemType
    {
        GroupFileListItemTypePinned = 0,
        GroupFileListItemTypeData
    };
    enum GroupFileListViewAdapterData
    {
        FILELISTDATA_BASE   = ListWidgetBaseAdapterUserRoleBase,
        FILELISTDATA_TYPE,
        FILELISTDATA_ID ,
        FILELISTDATA_DISPLAY,
        FILELISTDATA_TIMESTAMP,
        FILELISTDATA_RANGE_MIN,
        FILELISTDATA_RANGE_MAX
    };
    Q_OBJECT
public:
    GroupFileListViewAdapter(QAbstractItemView* parent);
    ~GroupFileListViewAdapter();
public:
    virtual QWidget* CreateNewWidget(const QModelIndex& index);
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QTreeWidgetItem* findGroup(quint64 lasttime);
    void setMessageList(const QSharedPointer<Biz::MessageListData>& messageList);
    QMap<QString,QSharedPointer<Biz::XmppMessage>> m_messages;
};


class GroupFileListView : public LocalManDialog
{
    friend class SingletonTemplete<GroupFileListView>;
    Q_OBJECT

public:
    GroupFileListView(QWidget *parent = 0);
    ~GroupFileListView();
    void refreshFileMessage(const QString& conversationId);

protected:
    virtual void showEvent (QShowEvent *event);
protected:
private:
    GroupFileListViewAdapter* m_pAdater;
    Ui::GroupFileListView *ui;
    Biz::CallbackReceiver* m_pCallbackReceiver;
};

typedef SingletonTemplete<GroupFileListView> GroupFileListViewSingleton;
#endif // GROUPFILELISTVIEW_H
