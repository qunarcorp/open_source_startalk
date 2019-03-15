#include "MessageProblemList.h"
#include "XmppMessage.h"


/*<div style='margin: -10px 0;' id='problem_list_23EB0B3F82104E53A4986F02670F1AF4'>
	<SPAN class='ProblemListTitle'>请看供应商管理后台右下角，有运营联系方式</SPAN>
	<DIV id='ZD_DIV_23EB0B3F82104E53A4986F02670F1AF4' class='listAreaDiv'>
		<span class='listAreaTips'>您是否还想问?</span>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IuWVhuaIt+euoeeQhuezu+e7n+S4iuayoeacieaIkeS7rOeahOW8gOaIt+mTtuihjCJ9")'>商户管理系统上没有我们的开户银行</a>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IueJueS7t+S6p+WTgSJ9")'>特价产品</a>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IuaOqOiNkOeahOS6p+WTgSJ9")'>推荐的产品</a>
		<a class='ProblemListMore' onclick='window.Cocoa.problemListMoreClick("23EB0B3F82104E53A4986F02670F1AF4")'>查看更多内容<img style='margin-bottom:4px;' src='file:///Users/admin/Library/Developer/Xcode/DerivedData/qunar-qim-mac-aalckwdcuouxsmdlngqypeauqojq/Build/Products/Debug/QChat.app/Contents/Resources/arrow-down.png'/></a>
	</DIV>
	<DIV id='TU_DIV_23EB0B3F82104E53A4986F02670F1AF4' class='listAreaDiv' style='display:none;'>
		<span class='listAreaTips'>您是否还想问?</span>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IuWVhuaIt+euoeeQhuezu+e7n+S4iuayoeacieaIkeS7rOeahOW8gOaIt+mTtuihjCJ9")'>商户管理系统上没有我们的开户银行</a>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IueJueS7t+S6p+WTgSJ9")'>特价产品</a>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6IuaOqOiNkOeahOS6p+WTgSJ9")'>推荐的产品</a>
		<a class='ProblemListItem' onclick='window.Cocoa.problemListItemClick("eyJ0eXBlIjoiaW50ZXJmYWNlIiwidXJsIjoiIiwibXNnVGV4dCI6Iue6uOi0qOeJiOi1hOi0qOmcgOimgeebluWFrOeroOS5iCJ9")'>纸质版资质需要盖公章么</a>
		<a class='ProblemListMore' onclick='window.Cocoa.problemListTakeUp("23EB0B3F82104E53A4986F02670F1AF4")'>收起<img style='margin-bottom:4px;' src='file:///Users/admin/Library/Developer/Xcode/DerivedData/qunar-qim-mac-aalckwdcuouxsmdlngqypeauqojq/Build/Products/Debug/QChat.app/Contents/Resources/arrow-up.png'/></a>
	</DIV>
</div> */

const QString PROBLEM_LIST_DIV = "overflow:hidden;padding:10px;white-space:nowrap;font-size:16px;line-height:18px;color:#737373;background:#42CF94;margin: 5px 5px 5px -5px;border-radius:5px;";
const QString PROBLEM_LIST_AREA = "border-radius:5px;overflow:auto;padding:10px;white-space:nowrap;font-size: 16px;line-height:18px;color:#737373;background:#ffffff;margin-bottom:10px;";
const QString PROBLEM_LIST_AREA_TIPS = "display:block;font-size:14px;color:#999999;margin-bottom:5px;"; 
const QString PROBLEM_LIST_TITLE = "display:block;padding:10px 0;color:#FFF;font-size:16px;font-weight:200;width:auto;word-wrap:break-word;word-break:break-all;white-space:pre-wrap!important;overflow:hidden;";
const QString PROBLEM_LIST_ITEM = "display:block;padding:5px 0;border-bottom: 1px solid #d1d1d1;color: #42CF94;font-size:13px;font-weight:200;";
const QString PROBLEM_LIST_MORE = "display: block;color: #1397d4;font-size:13px;font-weight:200;margin-top:15px;margin-bottom:-8px;"; 
const QString HINTS_SPAN_STYLE = "display:block;color:#999999;font-size:12px;text-align:center;";
const QString HINTS_LINK_STYLE = "color:#20bcd2;text-decoration:none;";

MessageProblemList::MessageProblemList(void)
{
}

MessageProblemList::~MessageProblemList(void)
{
}

int MessageProblemList::getMessageMediaType()
{
	return Biz::MediaTypeProblemList;
}

bool MessageProblemList::getHintsTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{ 
	QByteArray ba;
	ba = spMessage->ExtendInfo().length() > 0?spMessage->ExtendInfo().toUtf8():spMessage->Body().toUtf8();
	QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
	if(Json_Data.isObject())
	{
		QVariant strdata = Json_Data.toVariant(); 
		QVariantList hintArr;
		if (strdata.canConvert<QVariantMap>())
		{
			QVariantMap hintMap = strdata.toMap();
			hintArr = hintMap["hints"].toList();
		} else
		{
			hintArr = strdata.toList();
		}
		htmlString.append(QString("<span style=\"%1\">").arg(HINTS_SPAN_STYLE));
		for (int index = 0, iLen = hintArr.length() ; index < iLen; index++)
		{
			QVariantMap hintMap = hintArr.at(index).toMap();
			bool isLink = false;
			if (spMessage->MediaType() == Biz::MediaTypeConsultHints) {
				QString type = hintMap["event"].toMap()["type"].toString();
				isLink = type.length() > 0 && !(type == "text"); 
			} else {
				isLink = hintMap["isLink"].toBool();
			}
			QString text = hintMap["text"].toString();
			if (isLink) {
				QString type = "normal";
				if (spMessage->MediaType() == Biz::MediaTypeConsultHints)
				{
					type = "transfer";
				}  
				QByteArray eventByteArray = QJsonDocument::fromVariant(hintMap).toJson();
				QString eventJsonStr = QString(eventByteArray);
				QString eventBase64Str = QString(eventByteArray.toBase64());
				htmlString.append(QString("<a style=\"%1\" href='javascript:CLIENT_API.jsHintsClick(\"%2\",\"%3\")'>%4</a>").arg(HINTS_LINK_STYLE,type,eventBase64Str,text));
			} else { 
				htmlString.append(text);
			}
		}
		htmlString.append("</span>"); 
		return true;
	}
	return false;
}

bool MessageProblemList::getProblemListTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{ 
	int initCount = 3;  
	QByteArray ba;
	ba = spMessage->ExtendInfo().toUtf8();
	QJsonDocument Json_Data = QJsonDocument::fromJson(ba);
	if(Json_Data.isObject())
	{
		QVariantMap strdata = Json_Data.toVariant().toMap(); 
		htmlString.append(QString("<div style=\"%1\">").arg(PROBLEM_LIST_DIV));
		htmlString.append(QString("<div style='margin: -10px 0;' id='problem_list_%1'>").arg(spMessage->MessageID()));

		QString title = strdata["content"].toString();
		QRegExp regExp("\\[obj type=[\\\\]?\"(.*)[\\\\]?\" value=[\\\\]?\"(.*)[\\\\]?\"(.*)\\]");    
		regExp.setMinimal(true); 
		QStringList xslist; 
		auto pos = 0;
		while ((pos = regExp.indexIn(title, pos)) != -1) 
		{
			int np = pos;
			QString item = regExp.cap(0);
			QString type = regExp.cap(1);
			QString val = regExp.cap(2);        
			QString extPart = regExp.cap(3);
			if(type == "image")
			{
				title = title.replace(item,QStringLiteral("[图片]"));
				pos += QStringLiteral("[图片]").length();
			}else if(type == "emoticon")
			{
				// 用表情源码
				title = title.replace(item,val);
				pos += val.length();

			} else if(type == "url")
			{  
				QString rawUrl = QUrl(val).toEncoded();
				QString htmlString = QString("<a href='javascript:openUrl(\"%1\")'>%2</a>").arg(rawUrl,val.toHtmlEscaped()); 
				title = title.replace(item,htmlString);
				pos += htmlString.length();
			} else {
				Log::e("MessageHelper::TranslateShortMsgBody error raw" +spMessage->Body() );
				title += title;
				break;
			}
		}  
		htmlString.append(QString("<SPAN style=\"%1\">%2</SPAN>").arg(PROBLEM_LIST_TITLE,title));

		QString listTips = strdata["listTips"].toString();
		QVariantMap listArea = strdata["listArea"].toMap();
		QString type = listArea["type"].toString();
		if (type == "list")
		{
			QList<QVariant> listItems = listArea["items"].toList();
			if (listItems.count() > initCount)
			{
				{ // 折叠起来的Div
					QString listAreaHtmlString;
					if (listTips.length() > 0)
					{ 
						listAreaHtmlString.append(QString("<span style=\"%1\">%2</span>").arg(PROBLEM_LIST_AREA_TIPS,listTips));
					}
					for (int i = 0, iLen = std::min(listItems.count(), initCount); i < iLen; i++)
					{
						QVariantMap itemData = listItems.at(i).toMap();
						QString text = itemData["text"].toString();
						QVariantMap eventData = itemData["event"].toMap();
						QByteArray eventByteArray = QJsonDocument::fromVariant(eventData).toJson();
						QString eventJsonStr = QString(eventByteArray);
						QString eventBase64Str = QString(eventByteArray.toBase64());
						listAreaHtmlString.append(QString("<a style=\"%1\" href='javascript:CLIENT_API.jsProblemListClick(\"%2\")'>%3</a>").arg(PROBLEM_LIST_ITEM,eventBase64Str,text));
					}
					listAreaHtmlString.append(QString("<a style=\"%1\"  href='javascript:onProblemListMoreClick(\"%2\")'>%3<img style='margin-left:4px;margin-bottom:8px;' src='./image/arrow_down.png'/></a>").arg(PROBLEM_LIST_MORE,spMessage->MessageID(),QStringLiteral("查看更多内容")));
					QString listAreaHtml;
					listAreaHtml.append(QString("<DIV id='ZD_DIV_%1' style=\"%2\">%3</div>").arg(spMessage->MessageID(), PROBLEM_LIST_AREA, listAreaHtmlString));
					htmlString.append(listAreaHtml);
				}
				{ // 展开的Div 
					QString listAreaHtmlString;
					if (listTips.length() > 0)
					{
						listAreaHtmlString.append(QString("<span style=\"%1\">%2</span>").arg(PROBLEM_LIST_AREA_TIPS, listTips));
					}
					for (int i = 0, iLen = listItems.count(); i < iLen; i++)
					{
						QVariantMap itemData = listItems.at(i).toMap();
						QString text = itemData["text"].toString();
						QVariantMap eventData = itemData["event"].toMap();
						QByteArray eventByteArray = QJsonDocument::fromVariant(eventData).toJson();
						QString eventJsonStr = QString(eventByteArray);
						QString eventBase64Str = QString(eventByteArray.toBase64());
						listAreaHtmlString.append(QString("<a style=\"%1\"  href='javascript:CLIENT_API.jsProblemListClick(\"%2\")'>%3</a>").arg(PROBLEM_LIST_ITEM,eventBase64Str,text));
					}

					listAreaHtmlString.append(QString("<a style=\"%1\"  href='javascript:onProblemListTakeUp(\"%2\")'>%3<img style='margin-left:4px;margin-bottom:8px;' src='./image/arrow_up.png'/></a>").arg(PROBLEM_LIST_MORE,spMessage->MessageID(),QStringLiteral("收起")));
					QString listAreaHtml;
					listAreaHtml.append(QString("<DIV id='TU_DIV_%1' style=\"%2;display:none;\">%3</div>").arg(spMessage->MessageID(),PROBLEM_LIST_AREA,listAreaHtmlString));
					htmlString.append(listAreaHtml);
				}
			} else
			{
				QString listAreaHtmlString;
				if (listTips.length() > 0)
				{
					listAreaHtmlString.append(QString("<span style=\"%1\">%2</span>").arg(PROBLEM_LIST_AREA_TIPS, listTips));
				}
				for (int i = 0, iLen = std::min(listItems.count(), initCount); i < iLen; i++)
				{
					QVariantMap itemData = listItems.at(i).toMap();
					QString text = itemData["text"].toString();
					QVariantMap eventData = itemData["event"].toMap();
					QByteArray eventByteArray = QJsonDocument::fromVariant(eventData).toJson();
					QString eventJsonStr = QString(eventByteArray);
					QString eventBase64Str = QString(eventByteArray.toBase64());
					listAreaHtmlString.append(QString("<a style=\"%1\" href='javascript:CLIENT_API.jsProblemListClick(\"%2\")'>%3</a>").arg(PROBLEM_LIST_ITEM,eventBase64Str,text));
				}
				QString listAreaHtml;
				listAreaHtml.append(QString("<DIV id='ZD_DIV_%1' style=\"%2\">%3</div>").arg(spMessage->MessageID(),PROBLEM_LIST_AREA,listAreaHtmlString));
				htmlString.append(listAreaHtml);
			}
		}
		htmlString.append("</div></div>");
		return true;
	}
	else
	{
		return false;
	} 
} 

bool MessageProblemList::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	switch (spMessage->MediaType())
	{
	case Biz::MediaTypeProblemList:
		{
			return getProblemListTranslatedMessage(spMessage,htmlString);
		}
		break;
	case Biz::MediaTypeConsultHints:
	case Biz::MediaTypeHints:
		{
			return getHintsTranslatedMessage(spMessage, htmlString);
		}
		break;
	default:
		break;
	}
	return false;
}

bool MessageProblemList::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
	body = QStringLiteral("[问题列表]");
	return true;
}