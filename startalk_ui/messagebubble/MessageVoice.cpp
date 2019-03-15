#include "MessageVoice.h"
#include <QFileIconProvider>
#include "XmppMessage.h"
#include "ConfigureHelper.h"
#include "Session.h"
#include "Account.h"

const QString VoiceMessageTemplate_Self = "<table class='voicemessagewrap' id='%1' onclick='javascript:onVoicePlayClicked(id)'> <tr class='voicemessage'>\
                                     <td style='width:%3px;text-align:%5;'> <span class='tiemlength'>%2</span></td>\
                                     <td><img class='img' id='%1_img' src='%4' /></td>\
                                     </tr></table>";

const QString VoiceMessageTemplate_Other = "<table class='voicemessagewrap' id='%1' onclick='javascript:onVoicePlayClicked(id)'> <tr class='voicemessage'>\
                                           <td><img class='img' id='%1_img' src='%4' /></td>\
                                            <td style='width:%3px;text-align:%5;'> <span class='tiemlength'>%2</span></td>\
                                            </tr></table>";

MessageVoice::MessageVoice()
{

}

MessageVoice::~MessageVoice()
{

}

int MessageVoice::getMessageMediaType()
{
    return Biz::MediaTypeVoice;
}

bool MessageVoice::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
    if (spMessage.isNull() || spMessage->MediaType()!=Biz::MediaTypeVoice)
        return false;

    QByteArray byteary;
    byteary = spMessage->Body().toUtf8();

    int amrSeconds = 0;
    QString fileName;
    QString url;
    QJsonDocument Json_Data = QJsonDocument::fromJson(byteary);
    if(Json_Data.isObject())
    {
        QVariantMap result = Json_Data.toVariant().toMap();
        amrSeconds = result["Seconds"].toInt();
        fileName = result["FileName"].toString();
        url = result["HttpUrl"].toString();
    }

    static int nMaxBubbleWidth = 200;
    static int nMinBubbleWidth = 30;
    static int nStanderTimeLength = 20;   

    QString strTimeLength = amrSeconds>=60?QString("%1'%2\"").arg(amrSeconds/60).arg(amrSeconds%60) : QString("%1\"").arg(amrSeconds%60);
    int nTimeWidth = qMin(nMaxBubbleWidth,qMax(nMinBubbleWidth,amrSeconds*nMaxBubbleWidth/nStanderTimeLength));

    if (spMessage->MsgDirection()==Biz::MessageTypeSelf)
    {
        htmlString = QString(VoiceMessageTemplate_Self).arg(
            spMessage->MessageID(),
            strTimeLength,
            QString::number(nTimeWidth),
            "./image/out_voiceplay3.png",
            "left");
    }
    else
    {
        htmlString = QString(VoiceMessageTemplate_Other).arg(
            spMessage->MessageID(),
            strTimeLength,
            QString::number(nTimeWidth),
            "./image/in_voiceplay3.png",
            "right");
    }
    

    return true;
}

bool MessageVoice::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[语音]");
    return true;
}
