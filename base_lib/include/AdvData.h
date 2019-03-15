#ifndef ADVDATA_H
#define ADVDATA_H



namespace Biz
{
    class AdvDataItem
    {
    public:
        AdvDataItem(){};
		~AdvDataItem(){};
		AdvDataItem(const AdvDataItem& advitem)
		{
			this->strLinkUrl = advitem.strLinkUrl;
			this->strImageLink = advitem.strImageLink;
		}

        QString strLinkUrl;
        QString strImageLink;
    }; 
}

#endif // ADVDATA_H
