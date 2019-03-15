#ifndef TRAYICONHOVERNOTICEWIDGET_H
#define TRAYICONHOVERNOTICEWIDGET_H

#include <QWidget>
#include <QTimeLine>
#include "UtilHelper.h"
#include "ui_trayiconhovernoticewidget.h"
#include "ui_trayhovernoticeitem.h"

class QListWidgetItem;

class TrayHoverNoticeItem;

namespace Biz
{
    class XmppMessage;
}


class TrayIconHoverNoticeWidget : public QWidget
{
    Q_OBJECT
    friend Util::SingletonTemplete<TrayIconHoverNoticeWidget>;
private:
    TrayIconHoverNoticeWidget(QWidget *parent = 0);
    ~TrayIconHoverNoticeWidget();
public:
    void smartShow(const QRect& rect);
    void smartHide();
    // 来了消息晃动图标的同时，增加一个未读，有条目加数，没条目加条目，未读为1
    void addUnreadMessage(const QSharedPointer<Biz::XmppMessage>& pMsg);
    void addUnreadMessage(const QString& jid,const QSharedPointer<Biz::XmppMessage>& pMsg);

    // 删除所有条目，停止闪动
    void markAllItemRead();
	// 查看一个，删掉一个
	void markItemRead(const QString& peerid);
private:
    virtual void leaveEvent(QEvent *);
private:
    
private:
    Ui::TrayIconHoverNoticeWidget ui;
    QTimeLine hideDelay;
    QMap<QString,QListWidgetItem*> items;
signals:
    void sgOpenItem(const QString& peerid);
    private slots:
        void onItemClicked(QListWidgetItem* pItem);
};

typedef Util::SingletonTemplete<TrayIconHoverNoticeWidget> TrayIconHoverNoticeWidgetSingleton;

class TrayHoverNoticeItem : public QWidget
{
    Q_OBJECT

public:
    TrayHoverNoticeItem(QWidget *parent = 0);
    ~TrayHoverNoticeItem();

    void increseUnreadCount(int offset);
    void setDisplayName(const QString& name);
    void setJid(const QString& jid);
    inline QString getJid(){return this->jid;};
private:
    Ui::TrayHoverNoticeItem ui;
    QString jid;
};




#endif // TRAYICONHOVERNOTICEWIDGET_H
