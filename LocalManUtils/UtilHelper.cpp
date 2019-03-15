#include "UtilHelper.h"
#include "SystemDefine.h"
#include <QDir>
#include "Markdown.h"


const static QString objectTypeImage    = "image";
const static QString objectTypeUrl      = "url";
const static QString objectTypeEmotion  = "emoticon";

namespace Util
{
	//高亮代码的模板style='max-width:380px;
	QString TEMPLATE = "<div  data-user=\"contentcode\" class=\"file-content code\" style=\"width:%5px\">"
		"<div class=\"highlighted-data %1\">"
		"<div class=\"line-numbers\">%2</div>"
		"<div class='highlight' style=\"focus\" tabindex=\"-1\" id=\"focus\">"
		"<pre>"
		"<code class='%3' style=\"-webkit-user-select: text;\" 'id=\"codecontent\" >%4</code>"
		"</pre>"
		"</div>"
		"</div>"
		"</div>";

		bool _Blank_line(std::string &Line, QString& out)
		{
			if (Line == "\r" || Line.empty()) {
				out += QString("\n<br>\n");
				return true; 
			}
			return false;
		}

		bool _Dividing_line(std::string &Line, QString& out)
		{
			int count = 0;

			while (Line[count++] == '-' && count < (int)Line.size());

			if (count == Line.size() && (count - 1) >= 3) {
				//out << "\n<hr>\n";
				out += QString("\n<hr>\n");
				return true;
			}

			return false;
		}



	QString UtilHelper::LocalePath( const QString& filename )
	{
		return GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/language/" + filename;
	}

    QString UtilHelper::GuidPath()
    {
        return GetDebugOrReleasePath(QCoreApplication::applicationDirPath()) + "/config.ini";
    }



	QString UtilHelper::GetDebugOrReleasePath(const QString& path)
	{
		QString strRtPath = path + "/commonresource";
        QDir dir(strRtPath);
        if (dir.exists(strRtPath))
        {
            return strRtPath;
        }
        else
        {
            QString strPath = path;
            int pos = strPath.lastIndexOf("/");
            strRtPath = strPath.left(pos) + "/commonresource";
            return strRtPath;
        }
        return strRtPath;
#ifdef _DEBUG
		QString strPath = path;
		int pos = strPath.lastIndexOf("/");
		strRtPath = strPath.left(pos) + "/commonresource";
#else
		strRtPath = path + "/commonresource";
#endif // DEBUG
		return strRtPath;
	}

	

	QString UtilHelper::autoRepeatFileName(const QString& strPath, const QString& filename, const QString&fileMd5)
	{
		
		QString strFilePath  = QFileInfo(QDir(strPath),filename).absoluteFilePath();
		QFileInfo fileMysave(strFilePath);
		QString strName= fileMysave.baseName(); // 第一个点之前的都是文件名
		QString strExtern = fileMysave.completeSuffix(); // 第一个点之后的都是后缀名 tar.gz may be ""

		QString strMyName = QFileInfo(strFilePath).fileName();

		int nI = 0;
		do 
		{
			if (QFileInfo::exists(strFilePath))
			{
				++nI;
				strMyName= QString("%1(%2).%3").arg(strName).arg(nI).arg(strExtern);
				strFilePath = strPath + strMyName;
				continue;
			}
			else
			{
				break;
			}
		} while (true);

		return strMyName;
	}


    QString UtilHelper::enocdeURL(QString text, QString id)
    {
        text = text.replace(0xa0,0x20);
        text = text.replace(0xc2a0,0x20);

        QString strResult = text;
        //QRegExp regExp("((http[s]{0,1}|ftp)://[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*+?:_/=]*)?)|(www.[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*+?:_/=]*)?)");
        //QRegExp regExp("((http[s]{0,1}|ftp)://[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*+,?:_/={}\\[\\]\\(\\)`~|]*)?)|(www\\.[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*,+?:_/={}\\[\\]\\(\\)`~|]*)?)");    
        //QRegExp regExp("((([a-zA-Z]+):[//]{0,0})?[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*,+?:_/={}\\[\\]\\(\\)`~|]*)?|(([a-zA-Z]+):[//]{2,2})?[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*,+?:_/={}\\[\\]\\(\\)`~|]*)?)");
        //QRegExp regExp("((([a-zA-Z]+):[//]{2,2})?[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*,+?:_/={}\\[\\]\\(\\)`~|]*)?)");
        //int i = 0;

        //QRegExp regExp("((http[s]{0,1}|ftp)://[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?([^ ]*)?)|(www\\.[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?([^ ]*)?)");    
        //QRegExp regExp("((http[s]{0,1}|ftp)://[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?([^ ^\"^\\]^\\[]*)?)|(www\\.[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?([^ ^\"^\\]^\\[]*)?)");

#ifdef QCHAT
		QRegExp regExp("(((ftp|https?|qunariphone|qunaraphone)://|www.)[a-zA-Z0-9\\.\\-]+([^ ^\"^\\[^\\]^\\r^\\n]*))");
#else
		QRegExp regExp("(((ftp|https?)://|www.)[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})([^ ^\"^\\[^\\]^\\r^\\n]*))");
#endif // QCHAT

        auto pos = 0;
        auto replacePos = 0;
        while ((pos = regExp.indexIn(text, pos)) != -1) {
            QString url = regExp.cap(0);
			if (!id.isEmpty())
			{
				QString newurl;
				QUrl Url(url);
				QUrlQuery queryurl(Url);

				////////////////////////////////////
				//从url中看一下是否包含filter关键字
				QVariantList paramlist = QJsonDocument::fromJson(id.toUtf8()).toVariant().toList();
				QString filterItemchar;
				for(QVariant item : paramlist)
				{
					QVariantMap mapItem = item.toMap();
					QPair<QString, QString> pair;
					pair.first = mapItem.value("filter").toString();

					QString strkey = queryurl.queryItemValue(pair.first);
					if (url.contains(pair.first) && strkey.isEmpty())
					{
						QList <QPair<QString, QString>> list= queryurl.queryItems();
						if (list.size() > 0  || !filterItemchar.isEmpty())
						{
// 							QString secondvalue = mapItem.value("param").toString();
// 							QVariantList secondlist = QJsonDocument::fromJson(secondvalue.toUtf8()).toVariant().toList();
							QVariantList secondlist = mapItem["param"].toList();
							for (QVariant secondItem: secondlist)
							{
								QVariantMap secondItemMap = secondItem.toMap();
								QString value = secondItemMap["it"].toString();

							//	QString strkeysecond = queryurl.queryItemValue("it");
								if(!queryurl.hasQueryItem("it"))
								{
									if (url.right(1) == "&")
									{
										filterItemchar += ( value);
									}
									else
									filterItemchar += ("&" + value);
								}
								else
								{
									queryurl.removeQueryItem("it");
									queryurl.addQueryItem("it", value);
								}
							}

							
						}
						else
						{
							//QString secondvalue = mapItem.value("param").toString();
						//	QVariantList secondlist = QJsonDocument::fromJson(secondvalue.toUtf8()).toVariant().toList();
							QVariantList secondlist = mapItem["param"].toList();
							for (QVariant secondItem: secondlist)
							{
								QVariantMap secondItemMap = secondItem.toMap();
								QString value = secondItemMap["it"].toString();


								if(!queryurl.hasQueryItem("it"))
								{
									if (url.right(1) == "?")
									{
										filterItemchar += (value);
									}
									else
									filterItemchar += ("?" + value);
								}
								else
								{
									queryurl.removeQueryItem("it");
									queryurl.addQueryItem("it", value);
								}

							}

						}
					}



// 					QString secondvalue = mapItem.value("param").toString();
// 					QVariantList secondlist = QJsonDocument::fromJson(secondvalue.toUtf8()).toVariant().toList();
// 					for (QVariant secondItem: secondlist)
// 					{
// 						QVariantMap secondItemMap = secondItem.toMap();
// 						QString value = secondItemMap["it"].toString();
// 						
// 						QString strkeysecond = queryurl.queryItemValue("it");
// 						if(strkeysecond.isEmpty())
// 						{
// 
// 						}
// 						else
// 						{
// 
// 						}
// 					}





// 					pair.second = mapItem.value("param").toString();
// 					QString strkey = queryurl.queryItemValue(pair.first);
// 					if (url.contains(pair.first) && strkey.isEmpty())
// 					{
// 						
// 						QList <QPair<QString, QString>> list= queryurl.queryItems();
// 						if (list.size() > 0  || !filterItemchar.isEmpty())
// 						{
// 							filterItemchar += ("&" + pair.second);
// 						}
// 						else
// 						{
// 							filterItemchar += ("?" + pair.second);
// 						}
// 					}
					
				}
				///////////////////////////////////////
			
				newurl = QUrl::	fromPercentEncoding(Url.toString().toUtf8()) + filterItemchar ;

				QString obj = QString("[obj type=\"url\" value=\"%1\"]").arg(newurl);
				replacePos = strResult.indexOf(url,replacePos);
				strResult.replace(replacePos,url.length(),obj);
				replacePos += obj.length();

				pos +=regExp.matchedLength();
			}
			else
			{
				QString obj = QString("[obj type=\"url\" value=\"%1\"]").arg(url);
				replacePos = strResult.indexOf(url,replacePos);
				strResult.replace(replacePos,url.length(),obj);
				replacePos += obj.length();

				pos +=regExp.matchedLength();
			}
        }    
        return strResult;    
    }




    // see also QTextHtmlParser.cpp
    #define MAX_ENTITY_U 258
    static const struct HtmlEntity_u { const char *name; quint16 code; } entities[MAX_ENTITY_U]= {
        { "AElig", 0x00c6 },
        { "AMP", 38 },
        { "Aacute", 0x00c1 },
        { "Acirc", 0x00c2 },
        { "Agrave", 0x00c0 },
        { "Alpha", 0x0391 },
        { "Aring", 0x00c5 },
        { "Atilde", 0x00c3 },
        { "Auml", 0x00c4 },
        { "Beta", 0x0392 },
        { "Ccedil", 0x00c7 },
        { "Chi", 0x03a7 },
        { "Dagger", 0x2021 },
        { "Delta", 0x0394 },
        { "ETH", 0x00d0 },
        { "Eacute", 0x00c9 },
        { "Ecirc", 0x00ca },
        { "Egrave", 0x00c8 },
        { "Epsilon", 0x0395 },
        { "Eta", 0x0397 },
        { "Euml", 0x00cb },
        { "GT", 62 },
        { "Gamma", 0x0393 },
        { "Iacute", 0x00cd },
        { "Icirc", 0x00ce },
        { "Igrave", 0x00cc },
        { "Iota", 0x0399 },
        { "Iuml", 0x00cf },
        { "Kappa", 0x039a },
        { "LT", 60 },
        { "Lambda", 0x039b },
        { "Mu", 0x039c },
        { "Ntilde", 0x00d1 },
        { "Nu", 0x039d },
        { "OElig", 0x0152 },
        { "Oacute", 0x00d3 },
        { "Ocirc", 0x00d4 },
        { "Ograve", 0x00d2 },
        { "Omega", 0x03a9 },
        { "Omicron", 0x039f },
        { "Oslash", 0x00d8 },
        { "Otilde", 0x00d5 },
        { "Ouml", 0x00d6 },
        { "Phi", 0x03a6 },
        { "Pi", 0x03a0 },
        { "Prime", 0x2033 },
        { "Psi", 0x03a8 },
        { "QUOT", 34 },
        { "Rho", 0x03a1 },
        { "Scaron", 0x0160 },
        { "Sigma", 0x03a3 },
        { "THORN", 0x00de },
        { "Tau", 0x03a4 },
        { "Theta", 0x0398 },
        { "Uacute", 0x00da },
        { "Ucirc", 0x00db },
        { "Ugrave", 0x00d9 },
        { "Upsilon", 0x03a5 },
        { "Uuml", 0x00dc },
        { "Xi", 0x039e },
        { "Yacute", 0x00dd },
        { "Yuml", 0x0178 },
        { "Zeta", 0x0396 },
        { "aacute", 0x00e1 },
        { "acirc", 0x00e2 },
        { "acute", 0x00b4 },
        { "aelig", 0x00e6 },
        { "agrave", 0x00e0 },
        { "alefsym", 0x2135 },
        { "alpha", 0x03b1 },
        { "amp", 38 },
        { "and", 0x22a5 },
        { "ang", 0x2220 },
        { "apos", 0x0027 },
        { "aring", 0x00e5 },
        { "asymp", 0x2248 },
        { "atilde", 0x00e3 },
        { "auml", 0x00e4 },
        { "bdquo", 0x201e },
        { "beta", 0x03b2 },
        { "brvbar", 0x00a6 },
        { "bull", 0x2022 },
        { "cap", 0x2229 },
        { "ccedil", 0x00e7 },
        { "cedil", 0x00b8 },
        { "cent", 0x00a2 },
        { "chi", 0x03c7 },
        { "circ", 0x02c6 },
        { "clubs", 0x2663 },
        { "cong", 0x2245 },
        { "copy", 0x00a9 },
        { "crarr", 0x21b5 },
        { "cup", 0x222a },
        { "curren", 0x00a4 },
        { "dArr", 0x21d3 },
        { "dagger", 0x2020 },
        { "darr", 0x2193 },
        { "deg", 0x00b0 },
        { "delta", 0x03b4 },
        { "diams", 0x2666 },
        { "divide", 0x00f7 },
        { "eacute", 0x00e9 },
        { "ecirc", 0x00ea },
        { "egrave", 0x00e8 },
        { "empty", 0x2205 },
        { "emsp", 0x2003 },
        { "ensp", 0x2002 },
        { "epsilon", 0x03b5 },
        { "equiv", 0x2261 },
        { "eta", 0x03b7 },
        { "eth", 0x00f0 },
        { "euml", 0x00eb },
        { "euro", 0x20ac },
        { "exist", 0x2203 },
        { "fnof", 0x0192 },
        { "forall", 0x2200 },
        { "frac12", 0x00bd },
        { "frac14", 0x00bc },
        { "frac34", 0x00be },
        { "frasl", 0x2044 },
        { "gamma", 0x03b3 },
        { "ge", 0x2265 },
        { "gt", 62 },
        { "hArr", 0x21d4 },
        { "harr", 0x2194 },
        { "hearts", 0x2665 },
        { "hellip", 0x2026 },
        { "iacute", 0x00ed },
        { "icirc", 0x00ee },
        { "iexcl", 0x00a1 },
        { "igrave", 0x00ec },
        { "image", 0x2111 },
        { "infin", 0x221e },
        { "int", 0x222b },
        { "iota", 0x03b9 },
        { "iquest", 0x00bf },
        { "isin", 0x2208 },
        { "iuml", 0x00ef },
        { "kappa", 0x03ba },
        { "lArr", 0x21d0 },
        { "lambda", 0x03bb },
        { "lang", 0x2329 },
        { "laquo", 0x00ab },
        { "larr", 0x2190 },
        { "lceil", 0x2308 },
        { "ldquo", 0x201c },
        { "le", 0x2264 },
        { "lfloor", 0x230a },
        { "lowast", 0x2217 },
        { "loz", 0x25ca },
        { "lrm", 0x200e },
        { "lsaquo", 0x2039 },
        { "lsquo", 0x2018 },
        { "lt", 60 },
        { "macr", 0x00af },
        { "mdash", 0x2014 },
        { "micro", 0x00b5 },
        { "middot", 0x00b7 },
        { "minus", 0x2212 },
        { "mu", 0x03bc },
        { "nabla", 0x2207 },
        { "nbsp", 0x00a0 },
        { "ndash", 0x2013 },
        { "ne", 0x2260 },
        { "ni", 0x220b },
        { "not", 0x00ac },
        { "notin", 0x2209 },
        { "nsub", 0x2284 },
        { "ntilde", 0x00f1 },
        { "nu", 0x03bd },
        { "oacute", 0x00f3 },
        { "ocirc", 0x00f4 },
        { "oelig", 0x0153 },
        { "ograve", 0x00f2 },
        { "oline", 0x203e },
        { "omega", 0x03c9 },
        { "omicron", 0x03bf },
        { "oplus", 0x2295 },
        { "or", 0x22a6 },
        { "ordf", 0x00aa },
        { "ordm", 0x00ba },
        { "oslash", 0x00f8 },
        { "otilde", 0x00f5 },
        { "otimes", 0x2297 },
        { "ouml", 0x00f6 },
        { "para", 0x00b6 },
        { "part", 0x2202 },
        { "percnt", 0x0025 },
        { "permil", 0x2030 },
        { "perp", 0x22a5 },
        { "phi", 0x03c6 },
        { "pi", 0x03c0 },
        { "piv", 0x03d6 },
        { "plusmn", 0x00b1 },
        { "pound", 0x00a3 },
        { "prime", 0x2032 },
        { "prod", 0x220f },
        { "prop", 0x221d },
        { "psi", 0x03c8 },
        { "quot", 34 },
        { "rArr", 0x21d2 },
        { "radic", 0x221a },
        { "rang", 0x232a },
        { "raquo", 0x00bb },
        { "rarr", 0x2192 },
        { "rceil", 0x2309 },
        { "rdquo", 0x201d },
        { "real", 0x211c },
        { "reg", 0x00ae },
        { "rfloor", 0x230b },
        { "rho", 0x03c1 },
        { "rlm", 0x200f },
        { "rsaquo", 0x203a },
        { "rsquo", 0x2019 },
        { "sbquo", 0x201a },
        { "scaron", 0x0161 },
        { "sdot", 0x22c5 },
        { "sect", 0x00a7 },
        { "shy", 0x00ad },
        { "sigma", 0x03c3 },
        { "sigmaf", 0x03c2 },
        { "sim", 0x223c },
        { "spades", 0x2660 },
        { "sub", 0x2282 },
        { "sube", 0x2286 },
        { "sum", 0x2211 },
        { "sup", 0x2283 },
        { "sup1", 0x00b9 },
        { "sup2", 0x00b2 },
        { "sup3", 0x00b3 },
        { "supe", 0x2287 },
        { "szlig", 0x00df },
        { "tau", 0x03c4 },
        { "there4", 0x2234 },
        { "theta", 0x03b8 },
        { "thetasym", 0x03d1 },
        { "thinsp", 0x2009 },
        { "thorn", 0x00fe },
        { "tilde", 0x02dc },
        { "times", 0x00d7 },
        { "trade", 0x2122 },
        { "uArr", 0x21d1 },
        { "uacute", 0x00fa },
        { "uarr", 0x2191 },
        { "ucirc", 0x00fb },
        { "ugrave", 0x00f9 },
        { "uml", 0x00a8 },
        { "upsih", 0x03d2 },
        { "upsilon", 0x03c5 },
        { "uuml", 0x00fc },
        { "weierp", 0x2118 },
        { "xi", 0x03be },
        { "yacute", 0x00fd },
        { "yen", 0x00a5 },
        { "yuml", 0x00ff },
        { "zeta", 0x03b6 },
        { "zwj", 0x200d },
        { "zwnj", 0x200c }
    };

#if defined(Q_CC_MSVC) && _MSC_VER < 1600
    static bool operator<(const HtmlEntity_u &e1, const HtmlEntity_u &e2)
    {
        return QLatin1String(e1.name) < QLatin1String(e2.name);
    }
#endif

    static bool operator<(const QString &str, const HtmlEntity_u &e)
    {
        return str < QLatin1String(e.name);
    }

    static bool operator<(const HtmlEntity_u &e, const QString &str)
    {
        return QLatin1String(e.name) < str;
    }

    static QChar resolveEntity(const QString &entity)
    {
        const HtmlEntity_u *start = &entities[0];
        const HtmlEntity_u *end = &entities[MAX_ENTITY_U];
        const HtmlEntity_u *e = std::lower_bound(start, end, entity);
        if (e == end || (entity < *e))
            return QChar();
        return e->code;
    }
    // parses an entity after "&", and returns it
    QString parseEntity(const QString& txt,int& pos)
    {
        int recover = pos;
        QString entity;
        while (pos < txt.length ()) {
            QChar c = txt.at(pos++);
            if (c.isSpace() || pos - recover > 9) {
                goto error;
            }
            if (c == QLatin1Char(';'))
                break;
            entity += c;
        }
        {
            QChar resolved = resolveEntity(entity);
            if (!resolved.isNull())
                return QString(resolved);
        }
error:
        pos = recover;
        return QLatin1String("&");
    }

    QString UtilHelper::decopeHtmlEscaptd(const QString& text)
    {
        QString retValue;
        int pos = 0;
        int len = text.length ();
        while (pos < len) {
            QChar c = text.at(pos++);
           if (c == QLatin1Char('&'))
                retValue += parseEntity(text,pos);
            else
                retValue += c;
        }

        return retValue;
    }

    bool UtilHelper::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
    {

#ifdef _WINDOWS
		sourceDir.replace("/","\\");
		toDir.replace("/","\\");
#else
		sourceDir.replace("\\", "/");
		toDir.replace("\\", "/");
#endif

        if (sourceDir == toDir){  
            return true;  
        }  

        if (!QFile::exists(sourceDir)){  
            return false;  
        }  
        QDir *createfile     = new QDir;  
        bool exist = createfile->exists(toDir);  
        if (exist){  
            if(coverFileIfExist){  
                createfile->remove(toDir);  
            }  
        }//end if  
        if(!QFile::copy(sourceDir, toDir))  
        {  
            return false;  
        }  
        return true;  
    }

	QString UtilHelper::getvirtualfromID( const QString& id )
	{
		if (id.isEmpty())
		{
			return QString("");
		}

		QStringList strlist = id.split("|");
		if (strlist.isEmpty() || strlist.size() < 2)
		{
			return QString("");
		}

		QString strvirtual = strlist.at(1);
		return strvirtual;
	}

	QString UtilHelper::getRealIdfromID( const QString&id )
	{
		if (id.isEmpty())
		{
			return QString("");
		}

		QStringList strlist = id.split("|");
		if (strlist.isEmpty() || strlist.size() < 2)
		{
			return QString("");
		}

		QString strvirtual = strlist.at(0);
		return strvirtual;
	}

	bool UtilHelper::isVirtualAccountId( const QString&id, const QString&domain )
	{
		if (id.isEmpty())
			return false;

		QStringList strlist = id.split("|");
		if (strlist.isEmpty() || strlist.size() < 2)
			return false;
		if (strlist.at(0)==strlist.at(1))
		{
			return false;
		}
		return true;
	}

	QString UtilHelper::addMsgIdParamToUrl(const QString& url,const QString& msgid)
    {
        QUrl baseUrl(url);
        QUrlQuery baseUrlQuery(baseUrl);
        baseUrlQuery.addQueryItem("msgid",msgid);
        baseUrl.setQuery(baseUrlQuery);
        QString newUrl = baseUrl.toString();
        return newUrl;
    }

	QString UtilHelper::getHightLightCodeStringToJson( const QString& text, const QString& msgid, const QString& bkofclr, const QString& codeoftype )
	{
		if (text.isEmpty() || msgid.isEmpty())
		{
			return QString("");
		}

		//拆text 计算text的行数
		QStringList strlist = text.split("\n");
		QString strline;
		for (int nI = 0; nI < strlist.size(); nI++)
		{
			strline += QString("<a href='#%1L%2' id='%1L%2' rel='#L%2'><i class='icon-link'> </i> %2 </a>").arg(msgid, QString::number(nI));
		}

		QString html = TEMPLATE.arg(bkofclr.toLower(), strline, codeoftype.toLower(), text);

		QJsonObject obj;
		obj.insert("CodeDecode", QString(""));
		obj.insert("CodeType", codeoftype);
		obj.insert("CodeStyle", bkofclr);
		obj.insert("Code", text);

		QJsonDocument doc(obj);

		QString retString = doc.toJson(QJsonDocument::Compact);


		return retString;
	}

	QString UtilHelper::getHightLightCodeString( const QString& text, const QString& msgid, const QString& bkofclr, const QString& codeoftype)
	{
		if (text.isEmpty() || msgid.isEmpty())
		{
			return QString("");
		}

		//拆text 计算text的行数
		QStringList strlist = text.split("<br/>");
		int nmaxWidth = 360;
		QString strline;
		for (int nI = 0; nI < strlist.size(); nI++)
		{
			strline += QStringLiteral("<a href='#%1L%2' id='%1L%2' rel='#L%2'><i class='icon-link'> </i> %2 </a>").arg(msgid, QString::number(nI));
		}
		int nMaxWidth = nmaxWidth > 360?360:nmaxWidth;
		QString html = TEMPLATE.arg(bkofclr.toLower(), strline, codeoftype.toLower(), text, QString::number(nMaxWidth));

		QString strreturn = QStringLiteral("%1").arg(html);

		return strreturn;
	}

	bool UtilHelper::isContainobj( const QString& text )
	{
		QRegExp regExp("\\[obj type=[\\\\]?\"([^\"]*)[\\\\]?\" value=[\\\\]?\"([^\"]*)[\\\\]?\"(.*)\\]");    
		regExp.setMinimal(true);


		auto pos = 0;
		if ((pos = regExp.indexIn(text, pos)) != -1) 
		{
			return true;
		}
		else
			return false;
	}

	QString UtilHelper::getMarkdownString( const QString&in )
	{
		Markdown markdown;
		markdown.setConverInfor(in);
		return markdown.CovertMarkdown();
	}

}