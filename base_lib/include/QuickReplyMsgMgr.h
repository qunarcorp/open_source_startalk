#pragma once
#include "CoreObject.h"
#include <QList>
#include <QString>
#include <QMap>
#include <QDomDocument>

class QuickReplyMsgItem : public QObject
{
    Q_OBJECT
public:
    QuickReplyMsgItem(){}
    QuickReplyMsgItem(const QuickReplyMsgItem &other)
    {
        id = other.id;
        group = other.group;
        key = other.key;
        content = other.content;
    }
    QString id;
    QString group;
    QString key;
    QString content;
};
Q_DECLARE_METATYPE(QuickReplyMsgItem);

class QuickReplyMsgListmap
{
public:
	QList<QuickReplyMsgItem*> quickrelyList;
	QMap<QString, QuickReplyMsgItem*>  quickreplyMap;

	QuickReplyMsgListmap(){}
	QuickReplyMsgListmap(const QuickReplyMsgListmap &other)
	{
		quickrelyList  = other.quickrelyList;
		quickreplyMap = other.quickreplyMap;
	}
	const QuickReplyMsgListmap& operator=(const QuickReplyMsgListmap &other)
	{
		
		quickrelyList  = other.quickrelyList;
		quickreplyMap = other.quickreplyMap;

		return *this;
	}

};


class QuickReplyMsgMgr : public QObject
{
    Q_OBJECT
public:
    ~QuickReplyMsgMgr(void);
   
	QList<QuickReplyMsgItem*>& getQuickReplyList();

    void SaveQuickReplyFile(const QString& filePath, const QList<QuickReplyMsgItem*>&);
    static QuickReplyMsgMgr* GetInstance(const QString& strPath)
    {
        static QuickReplyMsgMgr _inst(strPath);
        return &_inst;
    }
private:
    QuickReplyMsgMgr(const QString strFilePath);
    QuickReplyMsgMgr(const QuickReplyMsgMgr&);
    QuickReplyMsgMgr& operator= (const QuickReplyMsgMgr&);  

	void loadQuickReplyFile(const QString& filePath, QList<QuickReplyMsgItem*>&);
	
	
private:
    QList<QuickReplyMsgItem*> QuickReplyMsgList;
};

