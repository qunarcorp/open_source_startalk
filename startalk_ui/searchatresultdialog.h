#ifndef SEARCHATRESULTDIALOG_H
#define SEARCHATRESULTDIALOG_H

#include <QWidget>
#include "ui_SearchAtResultDialog.h"


class SearchAtResultDialog : public QWidget
{
	Q_OBJECT
	
public:
	SearchAtResultDialog(QWidget *parent=NULL);
	~SearchAtResultDialog();
	void setList(const QMap<QString, QString>& resultmap);
	void setMoveDown();
	void setMoveUp();
	void selectItem();
	void onItemClicked(QListWidgetItem *item);
	enum ItemSize
	{
		ItemWidth = 130,
		ItemHeight = 30
	};
protected:
	virtual void enterEvent(QEvent *) override;
	virtual void leaveEvent(QEvent *) override;
private:
	Ui::SearchAtResultDialog *ui;

signals:
	void sgatItemSelected(const QString& str);


};

#endif // SEARCHATRESULTDIALOG_H
