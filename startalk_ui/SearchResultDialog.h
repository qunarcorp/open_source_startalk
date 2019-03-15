#ifndef SEARCHRESULTDIALOG_H
#define SEARCHRESULTDIALOG_H

#include <QDialog>
#include "ui_SearchResultDialog.h"

class SearchResultDialog : public QDialog
{
    Q_OBJECT

public:
    SearchResultDialog(QWidget *parent = 0);
    ~SearchResultDialog();
    void setList(const QStringList& resultList);
    void setList(const QList<QListWidgetItem*>& resultList);

#if 0
    void setList(const QStringList& resultList,const QStringList& groupList);
#endif
	void setList(const QList<QPair<QString,QString>>& resultList,const QStringList& groupList);
    void onItemClicked(QListWidgetItem *item);
    void setMoveDown();
    void setMoveUp();
    void selectItem();
private:
    Ui::SearchResultDialog ui;
signals:
    void sgItemSelected(const QString& str);
    void sgItemSelectedEx(const QListWidgetItem*);
    void sgGroupSelected(const QString& str);
private slots:
    void onLianxirenItemEnter(const QListWidgetItem* pitem);
    void onMainWidgetMoved();
};

#endif // SEARCHRESULTDIALOG_H
