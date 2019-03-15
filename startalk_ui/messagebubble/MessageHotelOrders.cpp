
#include "MessageHotelOrders.h"

#include "XmppMessage.h"
#include "Session.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "WebService.h"

#include "jsonobject/hotels.h"


const QString OrdersWrapernotitle = "<div class=\"hotel_order_wrap\"> <div class=\"orders\">%2</div> </div>";
const QString OrdersWraper = "<div class=\"hotel_order_wrap\"> <div class=\"title\">%1</div> <div class=\"orders\">%2</div> </div>";
const QString Splin = "<div class=\"split\"></div>";

const QString orderItem = "<div class=\"order\" onclick=\"httpgetapicall('%3')\"><div><span class=\"subtitle\">%1 %2</span></div><div class=\"boot\" ><span class=\"left\">%4</span><span class=\"right\">%5</span></div></div>";
const QString ordermore = "<div class=\"more\" onclick=\"openNewLink('%1')\"><span>%2</span></div>";

MessageHotelOrders::MessageHotelOrders()
{

}

MessageHotelOrders::~MessageHotelOrders()
{

}

int MessageHotelOrders::getMessageMediaType()
{
    return Biz::MessageMediaType::MediaTypeHotelOrders;
}

bool MessageHotelOrders::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
    QString spExternInfo = spMessage->ExtendInfo ();
    if (!spExternInfo.isEmpty ())
    {
        Biz::HotelOrders orders;
        orders.unserializeFromString (spExternInfo);

        QString questionshtmlstring;
        for (IJsonSerializeable* pitem : orders.data ())
        {
            
            Biz::HotelOrder* pOrder = (Biz::HotelOrder*)(pitem);
            if (pOrder->actionType ().toInt () == 1)
            {
                // 订单
                if (NULL!=pOrder->properties())
                {
                    Biz::HotelOrderDetail* pDetail = (Biz::HotelOrderDetail*)pOrder->properties ();
                    QString item = orderItem.arg (
                        pDetail->productTypeName (),
                        pDetail->settlementDateInterval (),
                        pOrder->url (),
                        pDetail->money (),
                        pDetail->settlementStatusName ());

                    if (!questionshtmlstring.isEmpty ())
                        questionshtmlstring +=  Splin;

                    questionshtmlstring += item;
                }
            }
            else if (pOrder->actionType ().toInt () == 2)
            {

                QString item = ordermore.arg (
                    pOrder->url (),
                    pOrder->text ());

                if (!questionshtmlstring.isEmpty ())
                    questionshtmlstring +=  Splin;

                questionshtmlstring += item;
            }
        }

		htmlString = orders.title().isEmpty()?OrdersWrapernotitle.arg (questionshtmlstring):
			OrdersWraper.arg (orders.title (),questionshtmlstring);
        return true;
    }
    return false;
}

bool MessageHotelOrders::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
    body = QStringLiteral("[酒店 - 结算单列表]");
    return true;
}

