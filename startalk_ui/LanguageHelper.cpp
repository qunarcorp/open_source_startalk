#include "LanguageHelper.h"
#include "UtilHelper.h"

namespace MainApp
{
	const QString Locale_zhCN = "zhCN";
	const QString Locale_enUS = "enUS";

	static LanguageHelper* _instance = NULL;
	LanguageHelper::LanguageHelper()
	{

	}

	LanguageHelper::~LanguageHelper()
	{

    } 

    void LanguageHelper::release()
    {
        delete _instance;
        _instance = NULL;
    }

	LanguageHelper* LanguageHelper::instance()
	{
		if(!_instance){
			_instance = new LanguageHelper();
		}
		return _instance;
	}

	void LanguageHelper::locale( const QString& locale )
	{
		instance()->mLocale = locale;
		QString filePath = UtilHelper::LocalePath(locale);
		QFile f(UtilHelper::LocalePath(locale));
		if(f.open(QIODevice::ReadOnly))
		{
			auto data = QString::fromUtf8(f.readAll());
            QRegExp reg("([^=]*)=.*\"(.*)\"\r?\n");
            //QRegExp reg("([^=]*)=.*\"(.*)\"\n");
			reg.setMinimal(true);

			auto pos = 0;
			while ((pos = reg.indexIn(data, pos)) != -1) {

				auto key = reg.cap(1).trimmed();
				if (key.compare("CreateGroup") == 0)
				{
					auto value = reg.cap(2).trimmed();
				}
				auto value = reg.cap(2).trimmed();
				instance()->mTranslate[key] = value;

				pos += reg.matchedLength();
			}
		}
	}

	const QString& LanguageHelper::word( const QString& str )
	{
		return instance()->mTranslate[str];
	}

}
