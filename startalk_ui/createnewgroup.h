#ifndef CREATENEWGROUP_H
#define CREATENEWGROUP_H

#include <QWidget>
#include <QKeyEvent>
#include "ui_createnewgroup.h"
#include "ui_groupitem_l.h"
#include "ui_personitem_l.h"
#include "ui_personitem_r.h"
#include "ui_createnewgroupp2.h"
#include "LocalManDialog.h"
#include "CallbackReceiver.h"
#include "UtilHelper.h"
namespace Biz{
    class RosterNode;
};
class BaseItem : public QWidget
{
    Q_OBJECT
public:
    BaseItem(QWidget* parent):QWidget(parent){
        twiHolder = NULL;
    };
    inline void setJid(const QString& jid) {this->jid = jid;};
    inline QString getJid(){return this->jid;};

    inline void setTreeWidgetItemHolder(QTreeWidgetItem* item){this->twiHolder = item;};
    inline QTreeWidgetItem* getTreeWidgetItemHolder() {return this->twiHolder;};
protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void onExpandItemChild(){};

private:
    QString jid;
    QTreeWidgetItem* twiHolder;
};

class GroupItem_L : public BaseItem
{
    Q_OBJECT
public:
    GroupItem_L(QWidget* parent);
    ~GroupItem_L();

    void setHeader(const QString& headerPath);
    void setDisaplay(const QString& name);
    void setSelectable(bool able);
    void setSelectedBtnChecked(bool selected);
protected:
    virtual void onExpandItemChild();
private:
    Ui::GroupItem_L ui;
signals:
    void sgLoadItemsChild(const QString& name, QTreeWidgetItem* pItem, bool checked);
    void sgSelectMembersIn(const QString& name, QTreeWidgetItem* pItem,bool check);
};

class PersonItem_L : public BaseItem
{
    Q_OBJECT
public:
    PersonItem_L(QWidget* parent);
    ~PersonItem_L();
    void setHeader(const QString& headerPath);
    void setDisaplay(const QString& name);
    void setActive(bool active);
    void setSelectedBtnChecked(bool selected);
    void setGroupBelong(const QString& shortName,const QString& fullName );
    QString getDisplay();

	//add 选中后，点击不了
	void setSelectDisEnable();
private:
   Ui::PersonItem_L ui;
signals:
   void sgSelectPerson(PersonItem_L* personL,bool selected);
public slots:
    void onSelectBtnClick(bool cheched);
};

class PersonItem_R : public BaseItem
{
    Q_OBJECT
public:
    PersonItem_R(QWidget* parent);
    ~PersonItem_R();

    void setDisplayName(const QString& name);
    void setCloseable(bool b);
private:
    Ui::PersonItem_R ui;
signals:
    void sgDeletePerson(const QString& jid);
public slots:
    void onDeletePerson(bool ignal);
};


class CreateNewGroup : public LocalManDialog
{
    Q_OBJECT
	friend class Util::SingletonTemplete<CreateNewGroup>;
private:
	CreateNewGroup(LocalManDialog *parent = 0);
	 ~CreateNewGroup();
public:
    enum CREATE_GROUP_RESULT
    {
        CREATE_GROUP_RESULT_SUCCESS = 0x10,
        CREATE_GROUP_RESULT_FAIL = 0x11
    };
    void initGroupWidget();
    void isCreateNewGroup(bool createnew);
    void setMemberList(const QMap<QString,QString>& membermap);
    void setGroupJid(const QString& groupjid){this->groupjid = groupjid;};

    inline void setCallBack(Biz::UnitCallback<int>* callback){resultCallback = callback;};
    inline QString getGroupJid(){return this->groupjid;};
    inline QString getGroupName(){return this->groupName;};

protected:
    // 组织架构
    void initRosterTree();
    void createTreeItemChildren(const QString& groupname,QTreeWidgetItem* parent,bool checked=false);

    // 筛选条件
    void rebuildSearchList(const QList<Biz::RosterNode*>& searchResult );
	void rebuildFriendList();
    void rebuildResultList();
    void innerBuildResultList(int begin,int step);
    // 右侧列表控件添加一个条目，在最上面
    void addNewPerson2Right(const QString& jid,const QString& displayName,bool closeable = true,bool stayTop = true);
    void removePerson2Right(const QString& jid);

    void mergeHeadCount();

    // 事件复写
    virtual void keyPressEvent(QKeyEvent *);
	//判断是否有人进行创建群的时候
	void AdjuestCreateButton();

    void addPersonToRight(const QMap<QString, QString>& maplist, QTreeWidgetItem* pItem);
private:
    void searchMoveDown();
    void searchMoveUp();
    void searchSelected();

    virtual void closeEvent(QCloseEvent *);
	virtual void showEvent(QShowEvent *);
private:
    Ui::CreateNewGroup ui;
    QMap<QString,QTreeWidgetItem*> m_mapGroups; // 所有群组节点
    QMap<QString,QTreeWidgetItem*> m_mapPersonsL; // 所有个人节点
    QMap<QString,QTreeWidgetItem*> m_mapSearchPersonsL; // 搜索个人节点，随用随清

    QVector<QTreeWidgetItem*> mLstItems; // 搜索结果的线性列表

    QMap<QString,QListWidgetItem*> m_mapPersonsR; // 选中的个人节点 （不包含已经存在的）
    QMap<QString,QString> m_mapExistMembers; // 已经存在的个人节点
    QMap<QString,QString> m_mapPersonsCache; // 未绘制出来的个人节点
    int cacheIndex;
    
    QString groupjid;

    QString groupName;
	Biz::CallbackReceiver* mCallbackReceiver;

    Biz::UnitCallback<int>* resultCallback;


public slots:
    void onLoadItemsChild(const QString& name, QTreeWidgetItem* pItem,bool checked);
    void onAddMembersInGroup(const QString& name,QTreeWidgetItem* pItem,bool b);
    void onSearchEditInputChange(const QString& key);

    void onLSelectChange(PersonItem_L* personL,bool selected);

	void onFriendListSelectChange(PersonItem_L* personL,bool selected);

    void onRDeletePerson(const QString& jid);


    void onAddmember(bool);

    void onRightScrollBarValueChange(int);

    void setItemChildrenChecked(QTreeWidgetItem* pItem,bool checked);
	
    void onCreateGroupBtnClick();

    void onCreateGroupSuccess(const QString& groupid,const QString& groupname);

	void onTabButtionClicked(bool bCheck);

	

};

typedef Util::SingletonTemplete<CreateNewGroup> CreateNewGroupSingleton;



#endif // CREATENEWGROUP_H
