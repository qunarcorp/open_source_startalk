#ifndef JOINGROUPFAILEDDIALOG_H
#define JOINGROUPFAILEDDIALOG_H

#include <QWidget>
#include "localmanwidget.h"

#include "ui_joingroupfaileddialog.h"


#include "ui_groupjoinfaileditem.h"

class GroupJoinFailedItem : public QWidget
{
    Q_OBJECT

public:
    GroupJoinFailedItem(QWidget *parent = 0);
    ~GroupJoinFailedItem();
    void setGroupJid(const QString& groupJid);;
    inline QString groupJid() {return this->id;};

    void reset();
    void rejoin();

private:
    Ui::GroupJoinFailedItem ui;

    QString id;
    QListWidget* pContainerLst;
signals:
    void removeItem(const QString& id);

    private slots:
        void onReJoinCliecked(bool);
        void onLeftCliecked(bool);
        void onReJoinGroup();

};


class JoinGroupFailedDialog : public LocalManWidget
{
    enum USERDATAKEY
    {
        GROUPJID = Qt::UserRole+1
    };
    Q_OBJECT
public:
    static JoinGroupFailedDialog* getInstance();

    // add a group to list
    void addJoinFailedGroup(const QString& groupJid);

private:
    JoinGroupFailedDialog(LocalManWidget *parent = 0);
    ~JoinGroupFailedDialog();

    static JoinGroupFailedDialog* pInstance;

private:
    Ui::JoinGroupFailedDialog ui;
    QMap<QString,QListWidgetItem*> items;

signals:

    private slots:
        void onGroupJoinSuccess(const QString& groupjid);
        void onGroupJoinFail(const QString& groupid);

        void rejoinAllClicked(bool);
};

#endif // JOINGROUPFAILEDDIALOG_H
