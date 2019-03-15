#include "settinghotkeydialog.h"
#include "ui_SettingHotKey.h"
#include "LanguageHelper.h"
#include <QKeyEvent>

SettingHotKeyDialog::SettingHotKeyDialog(QWidget *parent)
	: LocalManWidget(parent)
{
	ui = new Ui::SettingHotKeyDialog();
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = Qt::Tool | FramelessWindowHint | Dialog | Qt::WindowStaysOnTopHint ;
	// auto add = FramelessWindowHint | WindowMinMaxButtonsHint;//|Popup;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));



	ui->okButton->setText(T_("MessageBox_Confirm"));
	ui->cancelButton->setText(T_("MessageBox_Cancel"));

	//setModal(true);
	setWindowModality(Qt::WindowModal);


	ui->label_Infor->setText(T_("SettingHotKeyInfor"));
	ui->label_HotKey->setText(mStrHotKey);
	ui->label_HotKey->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

	//ui->label_HotKey->installEventFilter(this);
	ui->label_HotKey->setFocus();
	connect(ui->okButton, &QPushButton::clicked, this, &SettingHotKeyDialog::OnOkButton);
	connect(ui->cancelButton, &QPushButton::clicked, this, &SettingHotKeyDialog::OnCancleButton);


}

SettingHotKeyDialog::~SettingHotKeyDialog()
{

}

void SettingHotKeyDialog::SetHotKey(const QString&htkey, int type)
{
	mStrHotKey = htkey;
	ui->label_HotKey->setText(mStrHotKey);
	ntype = type;
}
QString SettingHotKeyDialog::GetHotKey()
{
	QString strHotKey = ui->label_HotKey->text();
	return strHotKey;
}

void SettingHotKeyDialog::OnOkButton()
{
	QString stremp = ui->label_HotKey->text().replace(" ", "");

	emit sgSetOkButtonInfor(stremp, ntype);
	this->close();
}
void SettingHotKeyDialog::OnCancleButton()
{
	this->close();
}

/*bool SettingHotKeyDialog::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui->label_HotKey1) 
	{
		int ntype = event->type();
		if (event->type() == QEvent::KeyPress) 
		{
			QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
			if (NULL == keyEvent)
			{
				return false;
			}
			if (keyEvent->modifiers() == (Qt::ControlModifier | Qt::AltModifier) && (keyEvent->key() <= Qt::Key_Z && keyEvent->key() >= Qt::Key_A) )
			{
				QString tmp;
				tmp.sprintf(" + %c", keyEvent->key());
				inputHotkey = "Ctrl + Alt" + tmp;
				//return true;
			}
			else if (keyEvent->modifiers() == Qt::ControlModifier && (keyEvent->key() <= Qt::Key_Z && keyEvent->key() >= Qt::Key_A) )
			{
				QString tmp;
				tmp.sprintf("+ %c", keyEvent->key());
				inputHotkey = "Ctrl" +  tmp;
				//return true;
			}
			else if(keyEvent->modifiers() == Qt::AltModifier && (keyEvent->key() <= Qt::Key_Z && keyEvent->key() >= Qt::Key_A) )
			{
				QString tmp;
				tmp.sprintf("+ %c", keyEvent->key());
				inputHotkey = "Alt" + tmp;
				//return true;
			}
			/*else
			{
				inputHotkey = QString(QStringLiteral("нч"));
			}
			
			ui->label_HotKey->setText(inputHotkey);
			return true;

		}else if(event->type() == QEvent::FocusOut)
		{
			
		}
	}
	return QWidget::eventFilter(obj, event);
}*/


void SettingHotKeyDialog::showEvent( QShowEvent * )
{
	//ui->label_HotKey->installEventFilter(this);
	ui->label_HotKey->setFocus();
	this->activateWindow();
    inputHotkey = "";
}

void SettingHotKeyDialog::keyPressEvent( QKeyEvent *event )
{
	if (event->modifiers() == (Qt::ControlModifier | Qt::AltModifier) && (event->key() <= Qt::Key_Z && event->key() >= Qt::Key_A) )
	{
		QString tmp;
		tmp.sprintf(" + %c", event->key());
		inputHotkey = "Ctrl + Alt" + tmp;
		//return true;
	}
	else if (event->modifiers() == Qt::ControlModifier && (event->key() <= Qt::Key_Z && event->key() >= Qt::Key_A) )
	{
		QString tmp;
		tmp.sprintf("+ %c", event->key());
		inputHotkey = "Ctrl" +  tmp;
		//return true;
	}
	else if(event->modifiers() == Qt::AltModifier && (event->key() <= Qt::Key_Z && event->key() >= Qt::Key_A) )
	{
		QString tmp;
		tmp.sprintf("+ %c", event->key());
		inputHotkey = "Alt" + tmp;
		//return true;
	}

    if (!inputHotkey.isEmpty())
    {
        ui->label_HotKey->setText(inputHotkey);
    }
	
}
