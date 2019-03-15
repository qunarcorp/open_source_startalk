#ifndef ROSTERLISTITEMS_H
#define ROSTERLISTITEMS_H

#include <QObject>
#include <QListWidgetItem>
#include <QListWidget>
#include "ListWidgetBaseAdapter.h"


enum RosterListItemData
{
    RosterListItemDataBase = ListWidgetBaseAdapterRole::ListWidgetBaseAdapterUserRoleBase,
    RosterListItemDataConversationTypeGroup,
    RosterListItemDataConversationTypeChat,
	RosterListItemDataConversationTypeConsult,
    RosterListItemDataConversationTypeNews,
    RosterListItemDataConversationTypeRobot,
    RosterListItemDataConversationTypeLinked,
    RosterListItemDataConversationTypeRawHtml,
    RosterListItemDataConversationId,
    RosterListItemDataTitle,
    RosterListItemDataMarkTitle,
    RosterListItemDataDesc,
    RosterListItemDataUnreadCount,
    RosterListItemDataIsTop,
    RosterListItemDataAtFlag,
    RosterListItemDataAtCount,
    RosterListItemDataLastTimeStamp,
    RosterListItemDataHeaderChange,
    RosterListItemDataChildData,
	RosterListItemDataNoticeTip,
	RosterListItemDataAtMsgId,
	RosterListItemDataVirtualId,
	RosterListItemDataRealJid,
	RosterListItemDataBIsSeat,
	RosterListItemDataStarPerson
};

enum RosterListItemChildData
{
    RosterListItemDataChildBase = RosterListItemData::RosterListItemDataChildData,
    RosterListItemDataLinkedId,
};

class QListWidgetItemSortable : public QListWidgetItem{
public:
    explicit QListWidgetItemSortable(QListWidget *view = 0, int type = Type);
public:
    virtual bool operator<(const QListWidgetItem &other) const;

    void setConversationId(const QString& conversationId);
    QString conversationId();
    void setTitle(const QString& title);
    QString title() const;
    void setDescription(const QString& desc);
    QString description();
    void setUnreadCount(int count);
    int unreadCount();
    bool isTop() const;
    void setTop(bool top);
    void setAtType(int type);
    int atType();
    void setAtCount(int count);
    int atCount();
    void setLastTimeStamp(qint64 time);;
    qint64 getLastTimeStamp() const; ;
	void setNoticeTip(int noticetip);
	int getNoticeTip();
	void setAtmsgId(const QString&msgid);
	QString getAtmsgId();
    void setUserImageChange(quint64 changeversion);

    void setMarkTitle(const QString& marktitle);
    QString markTitle();

	void setStarPerson(int starperson);
	int getsetStarPerson();

    virtual bool isSimpleChatItem();;
	virtual bool isConsultChatItem();
    virtual bool isGroupChatItem();;
    virtual bool isNewsChatItem();;
    virtual bool isRobotChatItem();;
    virtual bool isLinkedItem();;
    virtual bool isRawHtmlItem();
};

class SimpleChatItem : public QListWidgetItemSortable
{
public:
    SimpleChatItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeChat,true);
    };
};
class ConsultChatItem : public QListWidgetItemSortable
{
public:
	ConsultChatItem(QListWidget* parent):QListWidgetItemSortable(parent){ setData(RosterListItemDataConversationTypeConsult,true); };

	void setVirtualAccount( const QString& virtualId ) { setData(RosterListItemDataVirtualId, virtualId); }
	QString getvirtualAccount() { return data(RosterListItemDataVirtualId).toString(); }

	void setRealJid(const QString& realJid){ setData(RosterListItemDataRealJid, realJid); }
	QString getRealJid(){return data(RosterListItemDataRealJid).toString();}

	void setIsSeat(bool b) {setData(RosterListItemDataBIsSeat,b);}
	bool getIsSeat(){return data(RosterListItemDataBIsSeat).toBool();}
};


class GroupChatItem : public QListWidgetItemSortable
{
public:
    GroupChatItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeGroup,true);
    };
};

class NewsChatItem : public QListWidgetItemSortable
{
public:
    NewsChatItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeNews,true);
    };
};

class RobotChatItem : public QListWidgetItemSortable
{
public:
    RobotChatItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeRobot,true);
    };
};

class LinkedItem : public QListWidgetItemSortable
{
public:
    LinkedItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeLinked,true);
    };
    void setLinkedKey(const QString& key);
    QString linkedKey();
};

class RawHtmlItem : public QListWidgetItemSortable
{
public:
    RawHtmlItem(QListWidget* parent):QListWidgetItemSortable(parent){
        setData(RosterListItemDataConversationTypeRawHtml,true);
    };
};
#endif // ROSTERLISTITEMS_H
