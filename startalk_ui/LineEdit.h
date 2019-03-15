#ifndef LINEEDIT_H
#define LINEEDIT_H
#pragma message(__FILE__)
#include <QLineEdit>
#include <QMenu>
#include "LanguageHelper.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT

public:
    LineEdit(QWidget *parent);
    ~LineEdit();

    virtual void keyPressEvent( QKeyEvent * );

protected:
	virtual void mousePressEvent(QMouseEvent *event);

public slots:
	void onShowEditMenu(const QPoint&pt);
	void onEditSelectAll();
	void onEditCopy();
	void onEditPast();
signals:
    bool sgAltS_Pressed();
    bool sgCtrl_EnterPressed();
    bool sgEnter_Pressed();

    void sgPaste();
	void LineEditClicked();
private:
    QMenu *mEditMenu;
	QAction *mActionSelectAll;
	QAction *mActionCopy;
	QAction *mActionPast;
};

#endif // LINEEDIT_H
