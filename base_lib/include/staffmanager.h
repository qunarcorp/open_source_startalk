#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H

#include "managerbase.h"



namespace Biz
{
	class StaffManager : public ManagerBase
	{
		Q_OBJECT
	
	public:
	    StaffManager();
	    ~StaffManager();

        virtual void initManager();

        virtual void unInitManager();

    public:
        void getUserLeader(const QString& userjid, Biz::UnitCallback<QString>* callback );
        void getUserMobildPhone(const QString& userJid, Biz::UnitCallback<QString>* callback);
		void getUserWorkspaceWaitCount();
	private:
signals:
		void sgWorkSpaceWaitCount(int count);
	};
}

#endif // STAFFMANAGER_H
