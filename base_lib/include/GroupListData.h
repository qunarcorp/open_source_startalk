#ifndef GROUPLISTDATA_H
#define GROUPLISTDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"
#include <QMutex>
namespace Biz
{
    class GroupItem;
    class GroupSetting;
    class GroupListData : public IXmlSerializeable
    {
        Q_OBJECT
	public:
        PROPERTY(QList<IXmlSerializeable*>, GroupList);
        PROPERTY(QList<IXmlSerializeable*>, GroupSettings);
    public:
        GroupListData();
        ~GroupListData();

        /*void addGroup(const QString& groupJid, bool checked);
        void removeGroup(const QString& groupJid);
        bool findGroup(const QString& groupJid);*/
        void unserializeItem(const QString&, QDomElement&);
        //void getAllGroupJid(QList<QString>& jidList);

        GroupSetting* getGroupSetting(const QString& groupjid);
        
    private:
        QMutex lock;
    };

    class GroupItem : public IXmlSerializeable
    {
        Q_OBJECT
        PROPERTY(QString, GroupJid);
        PROPERTY(bool, AutoJoin);


    public:
        GroupItem();
        ~GroupItem();
    };

    class GroupSetting : public IXmlSerializeable
    {
    public:
        enum GROUP_NOTICE_OPTION
        {
            RECV_WITH_NOTICE,
            RECV_WITHOUT_NOTICE,
            NO_RECV
        };
    private:
        Q_OBJECT
        DECLARATION_CHANGEMARK()
        PROPERTY_CHANGEMARK(QString, Name,NameInner)
        PROPERTY_CHANGEMARK(QString, Description,DescriptionInner)
        PROPERTY_CHANGEMARK(QString, Subjuct,SubjuctInner)
        PROPERTY_CHANGEMARK(QString, GroupJid,GroupJidInner)
        PROPERTY_CHANGEMARK(int, Priority,PriorityInner)
        PROPERTY_CHANGEMARK(int, GroupMsgNoticeOption,GroupMsgNoticeOptionInner)
    public:
        GroupSetting();
        ~GroupSetting();
    };



}

#endif // GROUPLISTDATA_H
