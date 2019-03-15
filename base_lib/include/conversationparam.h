#pragma once
#include <QObject>
#include "httpresult.h"
#include "../LocalManUtils/IJsonSerializeable.h"
#include "MessageListData.h"
namespace Biz
{

	class ConversationParam : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		ConversationParam(QObject * parent):IJsonSerializeable(parent){};
		ConversationParam():IJsonSerializeable(NULL){};
		~ConversationParam(){};
		JPROPERTY(QString, id);
		JPROPERTY(quint64, timestamp);
		JPROPERTY(QString, realjid);
		JPROPERTY(QString, type);
		JPROPERTY(quint64, qchatid);
	};
}
