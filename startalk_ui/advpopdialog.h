#ifndef ADVPOPDIALOG_H
#define ADVPOPDIALOG_H

#include "localmanwidget.h"
#include "ui_AdvPopDialog.h"
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include "UtilHelper.h"
namespace Biz
{
	class AdvDataItem;
}
class AdvPopDialog : public LocalManWidget
{
	Q_OBJECT

	friend Util::SingletonTemplete<AdvPopDialog>;
public:
	void showAdvPopAnimation(const QList <QSharedPointer<Biz::AdvDataItem>> & picpathlist);
private:
	AdvPopDialog(QWidget *parent=NULL);
	~AdvPopDialog();

	void closeAnimation();
	void clearAll();
private:
	Ui::AdvPopDialog *ui; 

	QDesktopWidget desktop;
	QPropertyAnimation* animation;
	QTimer *remainTimer;
	
};
typedef Util::SingletonTemplete<AdvPopDialog> AdvPopDialogSingleton;

#endif // ADVPOPDIALOG_H
