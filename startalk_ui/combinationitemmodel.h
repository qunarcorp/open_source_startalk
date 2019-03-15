#ifndef COMBINATIONITEMMODEL_H
#define COMBINATIONITEMMODEL_H

#include <QStandardItemModel>
#include "combinationitem.h"
class CombinationItemModel : public QStandardItemModel
{
	Q_OBJECT

public:
	CombinationItemModel(QObject *parent);
	~CombinationItemModel();
	CombinationItem* getOrCreateItem(const QString& id, const QString& Name);
    void setItemIconImage(const QString&id,const QImage& image);
	void removeCombinationItem(const QString& jid);
private:
	QMap<QString, CombinationItem*> mCombinationItemMap;
};

#endif // COMBINATIONITEMMODEL_H
