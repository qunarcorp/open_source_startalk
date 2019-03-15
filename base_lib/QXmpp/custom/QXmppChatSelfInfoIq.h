#pragma once
#include "QXmppIq.h"
#include <QDomElement>
class QXMPP_EXPORT QXmppChatSelfInfoIq : public QXmppIq
{
public:
// 	class QXMPP_EXPORT Item
// 	{
// 	public:
// 		QString host() const;
// 		void setHost(const QString &host);
// 
// 		QString name() const;
// 		void setName(const QString &name);
// 
// 	private:
// 		QString m_uin;
// 		QString m_nickname;
// 		QString m_strid;
// 		QString m_sex;
// 		QString m_webname;
// 		QString department;
// 	};
public:
	QXmppChatSelfInfoIq(void);
	~QXmppChatSelfInfoIq(void);
	static bool isChatSelfInfoIq(const QDomElement &element);
	QString GetJsoninfor() const ;
	void setSaveInfor(const QString & strSaveInfor);
protected:
	/// \cond
	void parseElementFromChild(const QDomElement &element);
	void toXmlElementFromChild(QXmlStreamWriter *writer) const;
	/// \endcond
private:
	QString strJsoninfor;
	QString strJsonSaveInfor;
};

