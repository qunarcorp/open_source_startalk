#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMenu>

class StaticLabel : public QLabel
{
	Q_OBJECT

public:
	StaticLabel(QWidget *parent);
	~StaticLabel();
	void showStatic(bool bret);
	void setlbStaticPixmap(const QPixmap& pixmap);
	QSize getlbStaticSize();
	void showltStatic(bool bret);
	void setltStaticPixmap(const QPixmap& pixmap);
private:
	QLabel *lbstatic; //右下角的状态
	QLabel *ltstatic; //左上角的标识
	bool mbstatic;
	bool mbltstatic;
};

class StaticRCPlabel : public QLabel
{
	Q_OBJECT

public:
	StaticRCPlabel(QWidget *parent);
	~StaticRCPlabel();

private:
	QMenu *menu;
	QAction *mActionCp;
	QAction *mActionSelAll;
	QClipboard *board;
public slots:
	void onRMouseClicked(const QPoint&);
	void onLabelCopy();
	void onLabelSelAll();


};


#endif // MYLABEL_H
