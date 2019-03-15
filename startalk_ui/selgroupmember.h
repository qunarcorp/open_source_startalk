#ifndef SELGROUPMEMBER_H
#define SELGROUPMEMBER_H

#include <QWidget>
#include "LocalManDialog.h"
#include "ui_selgroupmember.h"
#include "UtilHelper.h"
#include "ui_groupitem_l.h"
#include "ui_personitem_l.h"
#include "ui_personitem_r.h"

class PersonItem_L;

class SelGroupMember : public LocalManDialog
{
	Q_OBJECT
	friend class Util::SingletonTemplete<SelGroupMember>;
private:
	SelGroupMember(LocalManDialog *parent = 0);
	~SelGroupMember();
public:
		void initGroupMember(const QMap<QString, QString>& membermap);
		void setGroupJid(const QString&jid);


private:
	Ui::SelGroupMember *ui;

	QString mGroupJid;

	QVector<QTreeWidgetItem*> mLstItems; // 搜索结果的线性列表

	QMap<QString, QListWidgetItem*> m_mapPersonsR; // 选中的个人节点 （不包含已经存在的）
	QMap<QString, QString> m_mapExistMembers; // 已经存在的个人节点
	QMap<QString, QString> m_mapPersonsCache; // 未绘制出来的个人节点

	QMap<QString, QString> m_mapTotalMembers;//所有的群组成员

	QMap<QString, QTreeWidgetItem*> m_mapPersonsL; // 所有个人节点
	QMap<QString, QTreeWidgetItem*> m_mapSearchPersonsL; // 搜索个人节点，随用随清

	int cacheIndex;
private:
	void rebuildSearchList(const QMap<QString, QString>& membermap);
	// 右侧列表控件添加一个条目，在最上面
	void addNewPerson2Right(const QString& jid, const QString& displayName, bool closeable = true, bool stayTop = true);
	void removePerson2Right(const QString& jid);

	//判断是否有人进行创建群的时候
	void AdjuestCreateButton();

	void mergeHeadCount();

	void innerBuildResultList(int begin, int step);
public slots:
	void onSearchEditInputChange(const QString& key);
	void onselmember();
	void onRightScrollBarValueChange(int dex);
	void onMemberSelectChange(PersonItem_L* personL, bool selected);
	void onRDeletePerson(const QString& jid);
};

typedef Util::SingletonTemplete<SelGroupMember> SelGroupMemberSingleton;
#endif // SELGROUPMEMBER_H
