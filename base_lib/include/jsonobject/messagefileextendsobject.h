#ifndef ADVERCONFIGINFO_H
#define ADVERCONFIGINFO_H
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
	class MessageFileExtendsObject : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		MessageFileExtendsObject(QObject* parent=NULL):IJsonSerializeable(parent){};
		~MessageFileExtendsObject(){};
		JPROPERTY(QString, FILEID);
		JPROPERTY(QString, FILEMD5);
        JPROPERTY(QString, FileName);
        JPROPERTY(QString, FileSize);
        JPROPERTY(QString, HttpUrl);
	};

	
}
#endif // ADVERCONFIGINFO_H
