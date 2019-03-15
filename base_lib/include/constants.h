#pragma once
#include "CoreObject.h"

namespace Constant
{
    extern const QString DATABASENAME;
    extern const QString DATABASENAME_BETA;

    extern const QString LOGINCONFIGDAT;
    extern const QString LOGINCONFIGDAT_BETA;

    extern const int    DEFAULT_PROTOBUF_PORT;

    extern const QString CACHE_KEY_AUTOAWAY;
    extern const QString CACHE_KEY_LASTONLINETIME;
    extern const QString CACHE_KEY_CURRENTPRESENCE;

	extern const int MSGAPI_MAX_TIMESTAMP_FLAG ;
	extern const quint64  INT64_MAX_T;

	class HTTP_CONSTANT {
	public:
		static QString GETMSGS_QUNAR;
		static QString GETHISTORY_QUNAR;
		static QString GETMUCMSGS_QUNAR;
		static QString GETMUCHISTORY_QUNAR;
		static QString GET_MUC_READMARK_QUNAR;
		static QString GET_SYSTEM_HISTORY_QUNAR;
		static QString GET_SYSTEM_MSGS_QUNAR;
		static QString GET_CONSULT_MSG_QUNAR;
		static QString GET_CONSULT_HISTORY_QUNAR;


		static QString DIRECTION_LESSTHEN;
		static QString DIRECTION_MORETHEN;
	};
}