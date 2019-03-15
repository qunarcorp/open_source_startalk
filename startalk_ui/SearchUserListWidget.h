#ifndef SEARCHUSERLISTWIDGET_H
#define SEARCHUSERLISTWIDGET_H

#include <QListWidget>
#include "ListWidgetBaseAdapter.h"

namespace Biz
{
    class SearchResulteItemGroupModule;
}

class SearchUserListWidgetAdapter : public ListWidgetBaseAdapter
{
public:
    SearchUserListWidgetAdapter(QListView *parent);
    ~SearchUserListWidgetAdapter();
    virtual QWidget* CreateNewWidget(const QModelIndex& index);
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:

};


class SearchUserListWidget : public QListWidget
{
    Q_OBJECT

public:
    SearchUserListWidget(QWidget *parent = 0);
    ~SearchUserListWidget();

public:
    // 1.分组 [联系人，群组，好友，机器人]等
    // 2.头像 [存在的显示]
    // 3.双击，打开会话[联系人，好友，机器人]，群会话[群组]
    void setListData(const QList<Biz::SearchResulteItemGroupModule>& dataList);
    void setMoveDown();
    void setMoveUp();
    void selectItem();
	inline int getcount() {return count();}
    inline void setSearchKey(const QString& text){m_searchKey=text;};
protected:
    void clearData();
	void setNotSearch(int nsearch, int& height);
private:
    SearchUserListWidgetAdapter* pAdapter;
    QList<Biz::SearchResulteItemGroupModule> mDataList;

    QString m_searchKey;
signals:
    void sgItemSelected(const QString& conversationId);
    void sgGroupSelected(const QString& coversationId);
    void sgRobotSelected(const QString& conversationId);
	void sgMoreSelected(const QString& selectedid, const QString& searchkey);
	void sgHistoryRecord();
public slots:
    void onItemClicked(QListWidgetItem *item);
};

#endif // SEARCHUSERLISTWIDGET_H
