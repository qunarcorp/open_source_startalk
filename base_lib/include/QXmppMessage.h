/*
 * Copyright (C) 2008-2012 The QXmpp developers
 *
 * Author:
 *  Manjeet Dahiya
 *
 * Source:
 *  http://code.google.com/p/qxmpp
 *
 * This file is a part of QXmpp library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */


#ifndef QXMPPMESSAGE_H
#define QXMPPMESSAGE_H

#include <QDateTime>
#include "QXmppStanza.h"

class QXmppMessagePrivate;

/// \brief The QXmppMessage class represents an XMPP message.
///
/// \ingroup Stanzas
///

class QXMPP_EXPORT QXmppMessage : public QXmppStanza
{
public:
    /// This enum described a message type.
    enum Type
    {
        Error = 0,
        Normal,
        Chat,
        GroupChat,
        Typing,
        Headline,
		Note,
		End,
		Transfer,
		readmark,
        revoke,
		subscription,
        mstat,
		AdvPush,
		consult,
		webrtc,
		encrypt,
		collection
    };

    /// This enum describes a chat state as defined by
    /// XEP-0085 : Chat State Notifications.
    enum State
    {
        None = 0,   ///< The message does not contain any chat state information.
        Active,     ///< User is actively participating in the chat session.
        Inactive,   ///< User has not been actively participating in the chat session.
        Gone,       ///< User has effectively ended their participation in the chat session.
        Composing,  ///< User is composing a message.
        Paused,     ///< User had been composing but now has stopped.
    };

    enum MessageType{
        MessageTypeRevokeMessage = -1,
        MessageTypeText     = 1,
        MessageTypeVoice    = 2,
        MessageTypeImage    = 3,
        MessageTypeFile     = 5,
        MessageTypeAction= 6,             // 机器人专用
        MessageTypeRichText           = 7,    // 机器人专用
        MessageTypeActionsRichText    = 8,    // 机器人专用
        MessageTypeClientCookie       = 9,    // 机器人专用
        MessageTypeShock   = 10,               // 机器人复用
		MessageTypeNote    = 11
    };
    enum MachineType{
        MachineTypeNone      = 0,
        MachineTypeMac      = 1,
        MachineTypeiOS      = 2,
        MachineTypePC       = 3,
        MachineTypeWeb      = 4,
        MachineTypeAndroid  = 5,
        MachineTypeLinux    = 6
    };

// 	enum SourceType{
// 		ChatMessage     = 0,
// 		GroupMessage    = 1,
// 		readmark        = 2,
// 		headline        = 3,
// 		subscription    = 4,
// 		Trans			= 5,
// 		Note			= 6,
// 		revoke          = 7,
// 		webrtc          = 15,
// 		encrypt         = 16,
// 		collection      = 17,
// 		consult         = 8,
// 		RevertMsgType   = 97,
// 		subscription_weidaoyou    = 98,
// 		UnKnow			= 99
// 	};

    QXmppMessage(const QString& from = "", const QString& to = "",
                 const QString& body = "", const QString& thread = "");
    QXmppMessage(const QXmppMessage &other);
    ~QXmppMessage();

    QXmppMessage& operator=(const QXmppMessage &other);

    QString body() const;
    void setBody(const QString&);

    bool isAttentionRequested() const;
    void setAttentionRequested(bool requested);

    bool isReceiptRequested() const;
    void setReceiptRequested(bool requested);

    QString mucInvitationJid() const;
    void setMucInvitationJid(const QString &jid);

    QString mucInvitationPassword() const;
    void setMucInvitationPassword(const QString &password);

    QString mucInvitationReason() const;
    void setMucInvitationReason(const QString &reason);

    QString receiptId() const;
    void setReceiptId(const QString &id);

    QDateTime stamp() const;
    void setStamp(const QDateTime &stamp);

    QXmppMessage::State state() const;
    void setState(QXmppMessage::State);

    QString subject() const;
    void setSubject(const QString&);

    QString thread() const;
    void setThread(const QString&);

    QXmppMessage::Type type() const;
    void setType(QXmppMessage::Type);

    QString xhtml() const;
    void setXhtml(const QString &xhtml);

    QString MessageID() const;
    void MessageID(const QString&);

    MessageType MediaType() const;
    void MediaType(MessageType type);

    MachineType MaType() const;
    void MaType(MachineType type);

    bool carbonMessage() const;

    bool offlineMessage() const;

	QString ChatId() const;
	void ChatId(const QString &id);
	QString qchatid() const;
	void qchatid(const QString&id);

    QString channelId() const;
    void channelId(const QString& id);

	//消息指针
	QString ReadType() const;
	void ReadType(const QString&rt);

	//externInfo扩展信息
	QString ExterInfor() const;
	void ExterInfor(const QString&extInf);

    bool isAutoReply() const;
    void autoReply(bool b);

	QString BackupInfo() const;
	void BackupInfo(const QString& backupinfo);

	// 毫秒时间戳，更精确
	quint64 msecTimeStamp();
	void setMsecTimeStamp(quint64 lmsecTime);
	// 群组里的个人
	QString senderJid() const;
	void setSenderJid(const QString& jid);
	//虚拟账号
	QString realfrom() const;
	void setrealfrom(const QString&realfrom);

	QString realto() const;
	void setrealto(const QString&realto);

	//新增一个新的字段
	QString cctext() const;
	void setcctext(const QString& cctxt);

	//新增一个业务线
	QString bu() const;
	void setbu(const QString& bu);

	//代收消息中证据的字段
	QXmppMessage::Type origintype() const;
	void setorigintype(QXmppMessage::Type ortype);

	QString originto() const;
	void setoriginto(const QString&orto);

	QString originfrom() const;
	void setoriginfrom(const QString&orfrom);
    /// \cond
    void parse(const QDomElement &element);
    void toXml(QXmlStreamWriter *writer) const;
    /// \endcond

	static QDateTime parseTimeStamp(const QDomElement &element);

private:
    QSharedDataPointer<QXmppMessagePrivate> d;
};

#endif // QXMPPMESSAGE_H
