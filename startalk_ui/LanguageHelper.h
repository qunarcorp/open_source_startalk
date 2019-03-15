#ifndef LANGUAGEHELPER_H
#define LANGUAGEHELPER_H

#include "CoreObject.h"


namespace MainApp
{
	extern const QString Locale_zhCN;
	extern const QString Locale_enUS;

	class LanguageHelper : public QObject
	{
	public:
		static LanguageHelper* instance();
        static void release();

		static void locale(const QString& locale);
		static const QString& word(const QString&);
	private:
		LanguageHelper();
		virtual ~LanguageHelper();

		QMap<QString, QString> mTranslate;
		QString mLocale;
	}; 
}

using namespace MainApp;
#define T_(x) LanguageHelper::word(x)

#endif // LANGUAGEHELPER_H
