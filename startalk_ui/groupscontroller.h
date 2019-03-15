#ifndef GROUPSCONTROLLER_H
#define GROUPSCONTROLLER_H

#include <QObject>
#include "ControllerBase.h"
class GroupListView;
namespace MainApp
{
class GroupsController : public ControllerBase
{
    Q_OBJECT

public:
    GroupsController();
    GroupsController(QObject *parent);
    ~GroupsController();
    virtual void initController();
    virtual void unInitController();
public:

    void registerGroupListView(GroupListView* listview);
    GroupListView* groupListView(){return m_pGroupListView;};
public:
    void createNewGroup(QStringList members,Biz::UnitCallback<QString>* callback);
    void inviteMembers(const QString& groupjid,QStringList members,Biz::UnitCallback<QStringList>*callback);
	 bool checkNewLimitedCount(int count);
private:
   
    static int sMemberMaxCount;
    static int sMemberWarningCount;

private:
    GroupListView* m_pGroupListView;
	QMap<QString, int> m_groupjidconfigmap;
    public slots:
        void onGroupListReceived(const QStringList& discoverIq);
        void onRoomListNameReceived(const QStringList& groupjids);
        void onGroupAdded(const QString& jid);
        void onGroupDelItem(const QString&jid);

        void onOpenNewGroupSession(const QString& jid);
};



}

#endif // GROUPSCONTROLLER_H
