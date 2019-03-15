#ifndef ROSTERTREEITEMMODEL_H
#define ROSTERTREEITEMMODEL_H

#include <QStandardItemModel>
#include "PresenceStatus.h"

namespace ApiResponse{
    class RosterProfile;
}
namespace Biz{
    class RosterItem; 
    class CallbackReceiver;
}
class rosterItem;

class RosterTreeItemModel : public QStandardItemModel
{
    Q_OBJECT

public:
    RosterTreeItemModel(QObject *parent);
    ~RosterTreeItemModel();
    rosterItem* getRosterItemFromBareJid(const QString& bareJid);
    rosterItem* getGroupItemByGn(const QString& groupname);
    void bindChild(const QString& groupname,rosterItem* parent);

    QString DisplayNameToUserId(const QString& displayName);

    QStandardItem* initRosterTree();
    void onUpdatePresence(const QStringList& onlineUsers);
    void updatevCard(const QString& bareJid, const QImage& img);
    void searchRosterList(const QString& key, QStringList& resultList);
	void updateSuoxie(const QVariantList& rosterNode);

	void cleanData();
	
    
	void ShowPresenceOnline(const QStringList& onlineUsers);
private:
	void updateSumonline(const QString& userid);
	void updateSubonline(const QString& userid);
private:    
    QMap<QString, rosterItem*> m_jidRosterItemMap;
    QMap<QString, rosterItem*> m_GroupRosterItemMap;
    Biz::CallbackReceiver* mReceiver;
	//存放在线人的列表
	QStringList onlineUserlist;
    
    
private:
    
};

#endif // ROSTERTREEITEMMODEL_H
