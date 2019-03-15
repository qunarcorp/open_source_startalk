#ifndef ADDNOTEINFOR_H
#define ADDNOTEINFOR_H

#include "LocalManDialog.h"
#include "UtilHelper.h"
namespace Ui
{
	class NoteInfor;
}

class AddNoteInfor : public LocalManDialog
{
	Q_OBJECT
	friend Util::SingletonTemplete<AddNoteInfor>;
public:
	void showNoteInfo();
	QString getNoteTitle();
	QString getNoteDesc();
private:
	AddNoteInfor(QWidget *parent=NULL);
	~AddNoteInfor();
	
public slots:
	void onCloseclicked();
	void onButtonOk();
private:
	Ui::NoteInfor *ui;
	QString mNoteTitle;
	QString mNoteDesc;
};
typedef Util::SingletonTemplete<AddNoteInfor> AddNoteInforSingleton;
#endif // ADDNOTEINFOR_H
