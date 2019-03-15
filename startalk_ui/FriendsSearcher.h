#ifndef FRIENDSSEARCHER_H
#define FRIENDSSEARCHER_H

#include <QWidget>
#include "UtilHelper.h"

#include "localmanwidget.h"
namespace Ui{
    class FriendsSearcher;
}

namespace Biz
{
	class CallbackReceiver;
	class ImSelfPerson;
}

class FriendsSearcher : public LocalManWidget
{
    Q_OBJECT
        friend class Util::SingletonTemplete<FriendsSearcher>;
protected:
    virtual void showEvent (QShowEvent *event);
private:
    FriendsSearcher(QWidget *parent = 0);
    ~FriendsSearcher();
private:
    void buildSearchResult(const QList<QSharedPointer<Biz::ImSelfPerson>>& retList);
    void initDomainListData();
private:
    Ui::FriendsSearcher* ui;
	Biz::CallbackReceiver* receiver;

    public slots:
        void onGoSearchClicked(bool b);
		void onClose();
        void onDomainListSelectChange(const QString& selectid);

        void onFriendVerifyResponceReceive(const QString& result, const QString& reason, const QString& jid);
        void onFriendDeletedReceive(const QString&reson , const QString& jid, int ntype);
};

typedef Util::SingletonTemplete<FriendsSearcher> FriendsSearcherSingleton;

#endif // FRIENDSSEARCHER_H
