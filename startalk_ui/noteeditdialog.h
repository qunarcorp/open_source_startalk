#ifndef NOTEEDITDIALOG_H
#define NOTEEDITDIALOG_H

#include "LocalManDialog.h"
#include "UtilHelper.h"
#include "ChatWebPage.h"
#include "ChatCommObject.h"

namespace Ui
{
	class NoteEditDialog;
}

class NoteEditDialog : public LocalManDialog
{
	Q_OBJECT
	friend class Util::SingletonTemplete<NoteEditDialog>;
public:
	void ShowNoteEditDialog();
	QString getContent();
private:
	NoteEditDialog(LocalManDialog *parent=NULL);
	~NoteEditDialog();

	void LoadHtml();
	
public slots:
	void onLoadHtmlFinish(bool bret);
	void onNoteEditOK();
	void onSaveNote(const QString&);
private:
	Ui::NoteEditDialog *ui;
	ChatWebPage*    mPage;
	ChatCommObject* mCommObject;
	QString mContent; //收到的内容
};

typedef Util::SingletonTemplete<NoteEditDialog> NoteEditDialogSingleton;
#endif // NOTEEDITDIALOG_H
