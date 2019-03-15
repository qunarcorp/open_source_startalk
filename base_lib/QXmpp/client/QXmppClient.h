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

#ifndef QXMPPCLIENT_H
#define QXMPPCLIENT_H

#include <QObject>
#include <QAbstractSocket>

#include "QXmppConfiguration.h"
#include "QXmppLogger.h"
#include "QXmppPresence.h"

class QXmppClientExtension;
class QXmppClientPrivate;
class QXmppPresence;
class QXmppMessage;
class QXmppIq;
class QXmppStream;

// managers
class QXmppVCardManager;

/// \defgroup Core

/// \defgroup Managers

/// \brief The QXmppClient class is the main class for using QXmpp.
///
/// It provides the user all the required functionality to connect to the
/// server and perform operations afterwards.
///
/// This class will provide the handle/reference to QXmppRosterManager
/// (roster management), QXmppVCardManager (vCard manager), and
/// QXmppVersionManager (software version information).
///
/// By default, the client will automatically try reconnecting to the server.
/// You can change this a behaviour using
/// QXmppConfiguration::setAutoReconnectionEnabled().
///
/// Not all the managers or extensions have been enabled by default. One can
/// enable/disable the managers using the funtions addExtension() and
/// removeExtension(). findExtension() can be used to find reference/pointer to
/// particular instansiated and enabled manager.
///
/// List of managers enabled by default:
/// - QXmppRosterManager
/// - QXmppVCardManager
/// - QXmppVersionManager
/// - QXmppDiscoveryManager
/// - QXmppEntityTimeManager
///
/// \ingroup Core

class QXMPP_EXPORT QXmppClient : public QXmppLoggable
{
    Q_OBJECT
    Q_ENUMS(Error State)
    Q_PROPERTY(QXmppLogger* logger READ logger WRITE setLogger NOTIFY loggerChanged)
    Q_PROPERTY(State state READ state NOTIFY stateChanged)

public:
    /// An enumeration for type of error.
    /// Error could come due a TCP socket or XML stream or due to various stanzas.
    enum Error
    {
        NoError,            ///< No error.
        SocketError,        ///< Error due to TCP socket.
        KeepAliveError,     ///< Error due to no response to a keep alive.
        XmppStreamError    ///< Error due to XML stream.
    };

    /// This enumeration describes a client state.
    enum State
    {
        DisconnectedState,  ///< Disconnected from the server.
        ConnectingState,    ///< Trying to connect to the server.
        ConnectedState,     ///< Connected to the server.
    };

    QXmppClient(QObject *parent = 0);
    ~QXmppClient();

    bool addExtension(QXmppClientExtension* extension);
    bool insertExtension(int index, QXmppClientExtension* extension);
    bool removeExtension(QXmppClientExtension* extension);

    QList<QXmppClientExtension*> extensions();

    template<typename T>
    T* findExtension()
    {
        QList<QXmppClientExtension*> list = extensions();
        for (int i = 0; i < list.size(); ++i)
        {
            T* extension = qobject_cast<T*>(list.at(i));
            if(extension)
                return extension;
        }
        return 0;
    }

    void connectToServer(const QXmppConfiguration&,
                         const QXmppPresence& initialPresence =
                         QXmppPresence());
    bool isAuthenticated() const;
    bool isConnected() const;

    QXmppPresence clientPresence() const;
    void setClientPresence(const QXmppPresence &presence);

    QXmppConfiguration &configuration();
    QXmppLogger *logger() const;
    void setLogger(QXmppLogger *logger);

    QAbstractSocket::SocketError socketError();
    State state() const;
    QXmppStanza::Error::Condition xmppStreamError();

	QString getPolicyViolationReason();

	void SetReloginConfig(const QString&pwd);

signals:
    void connected();
    void disconnected();
    void error(QXmppClient::Error);
    void loggerChanged(QXmppLogger *logger);
    void messageReceived(const QXmppMessage &message);

    void presenceReceived(const QXmppPresence &presence);

    void iqReceived(const QXmppIq &iq);

    void stateChanged(QXmppClient::State state);
	void OfflinekickedbyServerclient(const QString& strmsg);

public slots:
    void connectToServer(const QString &jid,
                         const QString &password);
    void disconnectFromServer();
    bool sendPacket(const QXmppStanza&);
    bool sendMessage(const QXmppMessage& msg);
    bool sendTypingMessage(const QString& bareJid);
	bool sendTypingconsultMessage(const QString& realfromid, const QString& realtoid, const QString& to);
private slots:
    void _q_elementReceived(const QDomElement &element, bool &handled);
    void _q_reconnect();
    void _q_socketStateChanged(QAbstractSocket::SocketState state);
    void _q_streamConnected();
    void _q_streamDisconnected();
    void _q_streamError(QXmppClient::Error error);

private:
    QXmppClientPrivate * const d;
};

#endif // QXMPPCLIENT_H
