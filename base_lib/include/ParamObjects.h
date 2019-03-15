#pragma once
#include "CoreObject.h"
namespace Biz
{
	struct RoomVcardRequestParam
	{
		
		QString domain;
		QMap<QString,int> mucPairs;
	};

	struct UserVcardRequestParam
	{
		QString domain;
		QMap<QString,int> userPairs;
	};

	struct UserStatusRequestParam
	{
		QString domain;
		QList<QString> userids;
	};

}

