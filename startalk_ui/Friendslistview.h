#ifndef FRIENDSLISTVIEW_H
#define FRIENDSLISTVIEW_H

#include <QListView>
#include "diywidgit/customviews/pinnedlistview.h"


class FriendsListView : public PinnedListView
{
	Q_OBJECT
	
public:
	FriendsListView(QWidget *parent);
	~FriendsListView();
public:
    void insertFriendItem(const QString& jid);
protected:
    virtual void contextMenuEvent(const QString& jid);
private:
	QMenu* pDeleteFriendMenu;

    public slots:
        void onLocalDeleteFriend(bool bret);
        void onCompletelyDeleteFriend(bool bRet);
        void onFriendVcardChanged(const QStringList& userinforlist);
        void onUpdatePortrait(const QString& userJid);

};

#endif // FRIENDSLISTVIEW_H
