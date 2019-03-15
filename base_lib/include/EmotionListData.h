#ifndef EMOTIONLISTDATA_H
#define EMOTIONLISTDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"
namespace Biz
{
	class EmotionPackageModule;
	class EmotionPackageListModule : public IXmlSerializeable
	{
		Q_OBJECT
public:
		PROPERTY(QList<IXmlSerializeable*>, EmotionPackageModules);
	
		EmotionPackageListModule();
		~EmotionPackageListModule();

		void unserializeItem(const QString&, QDomElement&);
		void addEmoticonPackageModule(const EmotionPackageModule* packageModule);
	private:

	};

	class EmotionPackageModule : public IXmlSerializeable
	{
	public:
		Q_OBJECT
		PROPERTY(QString, EmotionPackageConfigPath);
		PROPERTY(QString, EmotionPackageId);
	public:
		EmotionPackageModule();
		~EmotionPackageModule();
	};
}
#endif // EMOTIONLISTDATA_H
