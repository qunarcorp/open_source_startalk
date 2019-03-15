#ifndef UTILHELPER_H
#define UTILHELPER_H

#include "CoreObject.h"



namespace Util
{
	class UtilHelper
	{
		
	public:
		static QString LocalePath(const QString& filename);
        static QString GuidPath();
		static QString GetDebugOrReleasePath(const QString& path);
		static QString  autoRepeatFileName(const QString& strPath, const QString& filename, const QString&fileMd5); 
        static QString enocdeURL(QString text, QString id="");
        static QString addMsgIdParamToUrl(const QString& url,const QString& msgid);
        static QString decopeHtmlEscaptd(const QString& text);
        static bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);
		static QString getvirtualfromID(const QString& id);
		static QString getRealIdfromID(const QString&id);
		static bool isVirtualAccountId(const QString&id, const QString&domain);
		static QString getHightLightCodeStringToJson( const QString& text, const QString& msgid, const QString& bkofclr, const QString& codeoftype);
		static QString getHightLightCodeString( const QString& text, const QString& msgid, const QString& bkofclr, const QString& codeoftype);
        static bool isContainobj(const QString& text);
		static QString getMarkdownString(const QString&in);
		
	}; 
	template <class T>  
	class SingletonTemplete
	{
	public:
		static T* getInstance()
		{
			// lock1
			if (NULL == pInstance)
			{
				// lock2
				pInstance = new T();
				// unlock2
			}
			// unlock1
			return pInstance;
		}
		static void setNULLInstance()
		{
			pInstance = NULL;
		}

		static T* resetInstance()
		{
			if (NULL!=pInstance)
			{
				QObject* pObject = dynamic_cast<QObject*>(pInstance);
				if (NULL!=pObject)
				{
					pObject->deleteLater();
				}
				else
				{
					delete pInstance;
				}
			}

			pInstance = new T();
			return pInstance;
		}
	private:
		static T* pInstance;
	};
	template <class T> 
	T* SingletonTemplete<T>::pInstance = NULL;
}

#endif // UTILHELPER_H
