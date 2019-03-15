#ifndef EXTENDEDSESSIONLISTVIEW_H
#define EXTENDEDSESSIONLISTVIEW_H

#include <QWidget>

#include "RosterListWidget.h"
class CombinationListView;
class GroupListView;
class FriendsListView;
class RosterTreeView;
class PublicAccountListView;
class BlackNameListView;
class WechatUserListView;
class CollectionTreeView;
class StarPersonListView;

namespace Ui
{
	 class ExtendedSessionListView;
	 
}
class ExtendedSessionListView : public QWidget
{
    Q_OBJECT

public:
    ExtendedSessionListView(QWidget *parent = 0);
    ~ExtendedSessionListView();
public:
    QWidget* getContentView() const;;
    QString getBelongExtendid()const;;
    void setBelongExtendid(const QString& id);;

    QString getLindedId();
    void setLindedId(const QString& id);
	ExtendedSessionListView* getCombinationListView() const;
public:
    void setExtendTitle(const QString& title);
    void setExtendTitleVisable(bool visable);

protected:
	void setContentView(QWidget* pWidget);
protected:
    Ui::ExtendedSessionListView *ui;
private:
    QString beLongExtendId;
    QString lindItemId;
   
	QWidget* mpContentView;

signals:
    void sgBackButtonClicked(const QString& userid);
};

//最近会话列表
class RecentExtendedSessionListView:public ExtendedSessionListView
{
public:
	RecentExtendedSessionListView(QWidget*parent = 0);
	~RecentExtendedSessionListView();
public:
	RosterListWidget* getRosterListView() const;
	RosterListWidget* getCombinationListView() const;
};

//组合列表的第一级列表
class CombinationExtendedSessionListView:public ExtendedSessionListView
{
public:
	CombinationExtendedSessionListView(QWidget*parent = 0);
	~CombinationExtendedSessionListView();
public:
	CombinationListView* getCombinationListView() const;
};

//组合列表的第二级列表中的星标星标联系人
class CombinationOfStarPersonExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfStarPersonExtendedListView(QWidget*parent = 0);
	~CombinationOfStarPersonExtendedListView();
public:
	StarPersonListView* getCombinationListView() const;
};

//组合列表的第二级列表中的群组
class CombinationOfGroupExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfGroupExtendedListView(QWidget*parent = 0);
	~CombinationOfGroupExtendedListView();
public:
	GroupListView* getCombinationListView() const;
};

//组合列表的第二级列表中的组织架构
class CombinationOfOrganiExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfOrganiExtendedListView(QWidget*parent = 0);
	~CombinationOfOrganiExtendedListView();
public:
	RosterTreeView* getCombinationListView() const;
};

//组合列表的第二级列表中的好友
class CombinationOfFriendExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfFriendExtendedListView(QWidget*parent = 0);
	~CombinationOfFriendExtendedListView();
public:
	FriendsListView* getCombinationListView() const;
};

//组合列表中的第二级列表中的公众号
class CombinationOfPublicAccountExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfPublicAccountExtendedListView(QWidget*parent = 0);
	~CombinationOfPublicAccountExtendedListView();
public:
	PublicAccountListView* getCombinationListView() const;
};

//组合列表中的第二级列表中的黑名单
class CombinationOfBlackNameExtendedListView:public ExtendedSessionListView
{
public:
	CombinationOfBlackNameExtendedListView(QWidget*parent = 0);
	~CombinationOfBlackNameExtendedListView();
public:
	BlackNameListView* getCombinationListView() const;
};

class CombinationOfWechatsExtendedListView:public ExtendedSessionListView
{
public:
    CombinationOfWechatsExtendedListView(QWidget*parent = 0);
    ~CombinationOfWechatsExtendedListView();
public:
    WechatUserListView* getCombinationListView() const;
};

//代收的扩展
class CollectionExtendedListView:public ExtendedSessionListView
{
public:
	CollectionExtendedListView(QWidget*parent = 0);
	~CollectionExtendedListView();
public:
	CollectionTreeView* getcollectionListView() const;
	CollectionTreeView* getCombinationListView() const;
};
#endif // EXTENDEDSESSIONLISTVIEW_H
