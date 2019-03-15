#pragma once
#include "CoreObject.h"

namespace Biz
{
	class GroupMemberModule
	{

	public:
		GroupMemberModule(void);
		~GroupMemberModule(void);
	public:
		enum Affiliation {
			UnspecifiedAffiliation,
			OutcastAffiliation,
			NoAffiliation,
			MemberAffiliation,
			AdminAffiliation,
			OwnerAffiliation,
		};

		enum Role {
			UnspecifiedRole,
			NoRole,
			VisitorRole,
			ParticipantRole,
			ModeratorRole,
		};
	public:
		QString m_actor;
		Affiliation m_affiliation;
		QString m_roomjid;			//xxx@conference.ejabhost1/yyy
		QString m_resource;	
		QString m_resourceJid;		// yyy@ejabhost1
        QString m_remark;
        QString m_reserve;
		Role m_role;

	};
	
}
