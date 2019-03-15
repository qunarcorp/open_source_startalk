#ifndef DATAAPPLICATION_H
#define DATAAPPLICATION_H

#include <QtWidgets/QApplication>

#define dataApp (static_cast<DataApplication*>(QCoreApplication::instance()))


class DataApplicationPrivate;

class DataApplication : public QApplication
{
public:
#ifdef Q_QDOC
	DataApplication(int &argc, char **argv);
#else
	DataApplication(int &argc, char **argv, int = ApplicationFlags);
#endif
	virtual ~DataApplication();
public:
	bool	mbFirstShowAdv;
	qint32 mSystemVersion; //记录的是系统类型，比如xp的系统是0x0030,win7是0x0090等情况

    bool has(const QString& key);
    QVariant value(const QString& key);
    void put(const QString& key,const QVariant& value);
private:
    DataApplicationPrivate* _d;
};

#endif // DATAAPPLICATION_H
