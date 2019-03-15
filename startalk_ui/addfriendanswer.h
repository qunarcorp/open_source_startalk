#ifndef ADDFRIENDANSWER_H
#define ADDFRIENDANSWER_H

#include <QWidget>
#include "localmanwidget.h"
#include "ui_AddFriendAnswerDialog.h"
class AddFriendAnswer : public LocalManWidget
{
	Q_OBJECT

public:
	static AddFriendAnswer* instance();
	void showAddFriend(const QString& userid,int ntype, const QString& strquestion="");
private:
	static AddFriendAnswer* pInstance;
	AddFriendAnswer(QWidget *parent = 0);
	~AddFriendAnswer();
private slots:
	void onButtonOK();
private:
	Ui::AddFriendAnswerDialog *ui;
	int ntype;
	QString mUserid;
};

#endif // ADDFRIENDANSWER_H
