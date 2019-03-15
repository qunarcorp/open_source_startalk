#ifndef VIDEOROOMDIALOG_H
#define VIDEOROOMDIALOG_H

#include <QWidget>
#include "ui_videoroomdialog.h"
#include "UtilHelper.h"
#include "LocalManDialog.h"

#define  OK 1
class VideoRoomDialog : public LocalManDialog
{
	Q_OBJECT
	friend class Util::SingletonTemplete<VideoRoomDialog>;
public:
	void ShowDlg();
	QString getRoomName();
private:
	VideoRoomDialog(LocalManDialog *parent = 0);
	~VideoRoomDialog();

private:
	Ui::VideoRoomDialog *ui;
public slots:
	void onAcceptOk();
};
typedef Util::SingletonTemplete<VideoRoomDialog> VideoRoomDialogSingleton;
#endif // VIDEOROOMDIALOG_H
