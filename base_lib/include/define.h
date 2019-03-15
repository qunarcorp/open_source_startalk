#ifndef DEFINE
#define DEFINE

#include <qstring.h>
namespace Biz{
typedef struct _tagCheckVersionUpdate {
    QString currentVersion;
    bool   forceUpdate;
    QString downloadUrl;
    QString md5;
    QString updateMessage;
    bool recommand;
    QString lastVersion;
    QString betaurl;
	bool Rerecommand;
    bool autoUpdate;
    bool reAutoUpdate;
	QString mainChatverno;
} CheckVersionUpdate;

typedef struct _tagLoginParame
{
	bool isAutoLogin;
	bool isRemember;
	int presence;
	bool isReconnect;
} LoginParam;
}

#endif // DEFINE

