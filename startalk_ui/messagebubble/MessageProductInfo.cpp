#include "MessageProductInfo.h"
#include "XmppMessage.h"
#include "jsonobject/product.h"
enum OpenStyle
{

	OPENSTYLESYS,
	OPENSTYLEFRAME
};
MessageProductInfo::MessageProductInfo()
{

}

MessageProductInfo::~MessageProductInfo()
{

}

int MessageProductInfo::getMessageMediaType()
{
	return Biz::MediaTypeProduct;
}

bool MessageProductInfo::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& htmlString)
{
	if (spMessage.isNull())
	{
		return false;
	}
	const QString strProductTemplete = 
		"<a href='%1' class='linka'><div class='productcard'><div class='top'><img src='%2' class='titleimg' />"
		"<div class='titletxt'>%3</div></div><div class='spiderline'></div><div class='descimgtxt'><img src='%4' class='productimg' /><div class='prodectdescs'>%5</div></div></div></a>";
	const QString strProductTempleteSimple =
		"<a href='%1' class='linka'><div class='productcard'><div class='top'><img src='%2' class='titleimg' />"
		"<div class='titletxt'>%3</div></div><div class='spiderline'></div><div class='desctxtonly'><div class='prodectdescs'>%4</div></div></div></a>";
	const QString strProductDescItemTemplete = "<dl class='itempanel'><dt class='key'>%1</dt><dd class='value' %3>%2</dd></dl>";

	//QString strExtendData = QStringLiteral("{\"titleimg\":\"\",\"titletxt\":\"我的定制游订单（C1556637625417362547）\",\"productimg\":\"\",\"detailurl\":\"https://diy.dujia.qunar.com/sys/order/needsExtend.qunar?order_id=1556855165510896776\",\"openstyle\":0,\"descs\":[{\"k\":\"用户信息\",\"v\":\"开发测试(18701393371)\"},{\"k\":\"目的地\",\"v\":\"北京\"},{\"k\":\"出发日期\",\"v\":\"2017-06-06\"},{\"k\":\"行程天数\",\"v\":\"共1天\"},{\"k\":\"出行人数\",\"v\":\"1人\"},{\"k\":\"人均预算\",\"v\":\"￥655/人\"}],\"descdetail\":\"用户信息:开发测试(18701393371)\n\n订单号:C1556637625417362547\n\n目的地:北京\n\n出发日期:2017-06-06\n\n行程天数:共1天\n\n出行人数:1人\n\n人均预算:￥655/人\"}");//spMessage->ExtendInfo();
	QString strExtendData = spMessage->ExtendInfo();
	if (strExtendData.isEmpty())
	{
		return false;
	}

    Biz::ProductCard productCard;
    productCard.unserializeFromString(strExtendData);
       QString strDescHtmlCodes;
		for (IJsonSerializeable* jsonobj : productCard.descs())
		{
            Biz::ProductCardDesc* pdesc = dynamic_cast<Biz::ProductCardDesc*>(jsonobj);
            if (NULL!=pdesc)
            {
                QString color = pdesc->c();
                if (color.indexOf("#")!=0)
                    color = "";
                strDescHtmlCodes += QString(strProductDescItemTemplete).arg(pdesc->k(), pdesc->v(), color.isEmpty() ? "" : QString(" style='color:%1'").arg(color));
            }
		}
        

        QString titleImageUrl = productCard.titleimg().toHtmlEscaped();
        if (titleImageUrl.isEmpty())
        {
            titleImageUrl = "./image/producttitle.png";
        }

		QString openUrl;
		if (productCard.openstyle() == OPENSTYLEFRAME)
		{
			openUrl = QString("javascript:openNewLink(\"%1\")").arg(productCard.detailurl().toHtmlEscaped());
		}
		else
		{
			openUrl = QString("javascript:openUrl(\"%1\")").arg(productCard.detailurl().toHtmlEscaped());
		}

		if (productCard.productimg().isEmpty())
		{
			htmlString = QString(strProductTempleteSimple).arg(
				openUrl,
				titleImageUrl,
				productCard.titletxt(),
				strDescHtmlCodes);
		}
		else
		{
			htmlString = QString(strProductTemplete).arg(
				openUrl,
				titleImageUrl,
				productCard.titletxt(),
				productCard.productimg().toHtmlEscaped(),
				strDescHtmlCodes);
		}
		return true;
}

bool MessageProductInfo::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage, QString& body)
{
	body = QStringLiteral("来生意了");
	return true;
}
