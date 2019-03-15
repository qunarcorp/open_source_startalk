#ifndef GROUPITEMMODEL_H
#define GROUPITEMMODEL_H

#include <QStandardItemModel>
#include <QItemDelegate>
class VisitorItem;



class VisitorItem : public QObject, public QStandardItem {
    Q_OBJECT
public:
    enum Status
    {
        NONE,
        OFFLINE,
        ONLINE
    };

    VisitorItem(const QString& jid, const QString& gpName, bool autoJoin, int ntype);
    ~VisitorItem();
    void setPresence(Status status);
    void setMemberJid(const QString& memberJid);
	void setEmailAddress(const QString& email);
	QString emailAddress();
    QString MemberJid();

    void updateData(const QString& jid);
    VisitorItem::Status getStatus();
	void setDisplayname(const QString& dislayname);
	void setFontSize(int nsize);
	QString nickName();
    enum DataKeys
    {
        UserJid = Qt::UserRole + 1,	// 唯一值
        NickNamePY,					// nickname的拼音简拼，用于排序
        Presence,					// 群成员在线状态
		UserAffiliationType,		// 群成员的权限
        Email,						// 群成员的邮箱
        REPAINT,
		GroupFontSize
    };
}; 

class GroupVisitorModel : public QStandardItemModel
{
    Q_OBJECT
public:
    GroupVisitorModel(QObject *parent);
    ~GroupVisitorModel();
    VisitorItem* getItemFromBareJid(const QString& bareJid);
    void createItem(const QString& userID, int aff, const QString& gpName, VisitorItem::Status status);
    void removeItem(const QString& jid);
    void updatePresence(const QString& jid, VisitorItem::Status status);
    void updateAffic(const QString& jid, int aff);
    void updateData(const QString& jid);
	QMap<QString, VisitorItem*> GetGroupItemMap();
	
    VisitorItem::Status getStatus(const QString& jid);
	int GetCountItem();
	void wheelMove();
    int  getOnlineMemberCount();
    void updateDisplayName(const QString& userid, const QString& displayname);
	void setItemFontSize(int nsize);
private:
private:    
    /*QMap<QString, VisitorItem*> m_jidGroupItemMap;*/
	QMap<QString,QString> mResouceToJid;
};


class VisitorItemDelegate : public QItemDelegate
{
public:
    VisitorItemDelegate();
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
    const int AVATER_HEIGHT;
    const int AVATER_WIDTH;
    const int JOINPIC_SIZE;  

};
#endif // GROUPITEMMODEL_H
