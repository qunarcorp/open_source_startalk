#include "MessageHotelQuestions.h"
#include "XmppMessage.h"
#include "Session.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "WebService.h"

#include "jsonobject/hotels.h"


const QString QuestionWrap = "<div class=\"hotel_questions_wrap\"><div class=\"title\">%1</div><div class=\"questions\"><div class=\"subtitle\" >%2</div>%3</div></div>";

const QString QuestionItem = "<div class=\"split\"></div><div class=\"question\" onclick=\"httpgetapicall('%1')\">%2</div>";

MessageHotelQuestions::MessageHotelQuestions()
{
}

MessageHotelQuestions::~MessageHotelQuestions()
{

}

int MessageHotelQuestions::getMessageMediaType()
{
    return Biz::MessageMediaType::MediaTypeHotelQuestions;
}

bool MessageHotelQuestions::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString spExternInfo = spMessage->ExtendInfo ();
    if (!spExternInfo.isEmpty ())
    {
        Biz::HotelQuestions questions;
        questions.unserializeFromString (spExternInfo);

        QString questionshtmlstring;
        for (IJsonSerializeable* pitem : questions.data ())
        {
            Biz::HotelQuestion* pQuestion = (Biz::HotelQuestion*)(pitem);
            QString item = QuestionItem.arg (pQuestion->url (),pQuestion->text ());
            questionshtmlstring += item;
        }
        
        htmlString = QuestionWrap.arg (questions.title (),questions.subtitle ().isEmpty ()?QStringLiteral("常见问题"):questions.subtitle (),questionshtmlstring);
        return true;
    }
    return false;
}

bool MessageHotelQuestions::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[酒店 - 常见问题列表]");
    return true;
}
