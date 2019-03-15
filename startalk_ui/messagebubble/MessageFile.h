#ifndef MESSAGEFILE_H
#define MESSAGEFILE_H
#include "MessageBubbleBase.h"

namespace Biz
{
	class XmppMessage;
}



class MessageFile : public MessageDecoraterImpl<IMessageBubble>
{
public:
	MessageFile();
	~MessageFile();

	virtual int getMessageMediaType();

	virtual bool getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

	virtual bool getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body);
private:
	QString getCalcuteFileName(const QString& filename);
    bool isFileExist(const QSharedPointer<Biz::XmppMessage>& spMessage);
    bool toSendFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
    bool sendedFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
    bool unrecvFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);
    bool recvedFileFormat(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString);

};
#endif // MESSAGEFILE_H
