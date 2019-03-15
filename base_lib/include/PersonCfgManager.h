#ifndef PERSONCFGMANAGER_H
#define PERSONCFGMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "loginmanager.h"

namespace Biz {
    class PersonConfInfo;

    class PersonCfgManager : public ManagerBase {
    Q_OBJECT

    public:
        PersonCfgManager();

        ~PersonCfgManager();

        virtual void initManager();

        virtual void unInitManager();

        void registerPersonCfgKey(const QString &key);

        void savePersonCfgInfo(const QString &key, const QString &value);

        void savePersonCfgInfo(const QString &key, const QString &subkey, const QString &value, bool addOption = true);

        QSharedPointer<Biz::PersonConfInfo> getPersonCfgInfo(const QString &key);

        void savePersonCfgInfoToLocal(const QString &key, const QString &value);

    private:
        QStringList personCfgKeys;
    signals:

        void sgPersonCfgChange(const QStringList &changedKeys);

        void sgPersonCfgChangezhongbao();

    public slots:

        void onLoginStatusChange(LoginStatus oldstatus, LoginStatus newstatus);
    };
}

#endif // PERSONCFGMANAGER_H
