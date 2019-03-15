#ifndef ATINFORDATA_H
#define ATINFORDATA_H


class AtInforItem
{
public:
	AtInforItem(){};
	~AtInforItem(){};
	AtInforItem(const AtInforItem& atinforitem)
	{
		this->mUserJid = atinforitem.mUserJid;
		this->mMsgId = atinforitem.mMsgId;
	};

	QString mUserJid;
	QStringList mMsgId;
}; 


#endif // ATINFORDATA_H
