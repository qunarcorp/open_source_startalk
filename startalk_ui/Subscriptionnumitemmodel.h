#ifndef SUBSCRIPTIONNUMITEMMODEL_H
#define SUBSCRIPTIONNUMITEMMODEL_H

#include <QStandardItemModel>

class SubscriptionNumItem;

class SubScriptionNumItemModel : public QStandardItemModel
{
	Q_OBJECT

public:
	SubScriptionNumItemModel(QObject *parent);
	~SubScriptionNumItemModel();
	SubscriptionNumItem *getOrCreateItem(const QString& userID, const QString& gpName=NULL);
private:
	QMap<QString, SubscriptionNumItem*> mjidSubScriptionItemMap;
};

#endif // SUBSCRIPTIONNUMITEMMODEL_H
