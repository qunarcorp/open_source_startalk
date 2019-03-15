#ifndef ADVERCONFIGINFO_H
#define ADVERCONFIGINFO_H
#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"

namespace Biz
{
	class AdvlistNode : public IJsonSerializeable
	{
		Q_OBJECT
	public:
		AdvlistNode(QObject* parent):IJsonSerializeable(parent){
			adtype(0);
			imgurl("");
			linkurl("");
		};
		~AdvlistNode(){};
		JPROPERTY(int, adtype);
		JPROPERTY(QString, imgurl);
		JPROPERTY(QString, linkurl)
	};

	class AdverConfigInfo : public IJsonSerializeable
	{
		Q_OBJECT

	public:
		AdverConfigInfo(QObject *parent=NULL) : IJsonSerializeable(parent)
		{
			version(0);
			adsce(0);
			carousel(false);
			carouseldelay(0);
			shown(true);
			allowskip(false);
			skiptips("");
			LastUpdateAdvTime(0);

		};
       
         ~AdverConfigInfo(){ };


		JPROPERTY(int,version); //当前版本号
		JPROPERTY(int,adsce); //广告显示时常
		JPROPERTY(bool,carousel); //是否轮播
		JPROPERTY(int,carouseldelay); //轮播的间隔时间
		JPROPERTY(bool,shown); //是否显示 false 则跳过广告
		JPROPERTY(bool,allowskip); // 是否允许跳过
		JPROPERTY(QString,skiptips); // 允许跳过时的提示信息
		JPROPERTY(QList<IJsonSerializeable*>,adlist);
		JPROPERTY(quint64, LastUpdateAdvTime);
	protected:
		virtual void unserializeItem(const QString& key,QVariant v)
		{
			if ("adlist" == key)
			{
				AdvlistNode* ptemn = new AdvlistNode(this);
				ptemn->innerUnserialize(v);
				madlist.append(ptemn);
			}
		}

	};
}
#endif // ADVERCONFIGINFO_H
