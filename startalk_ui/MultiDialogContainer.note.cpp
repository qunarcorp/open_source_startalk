#include "MultiDialogContainer.h"
#include "ui_MultiDialogContainer.h"
#include <QMouseEvent>
#include <QXmppUtils.h>
#include <QImageReader>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"

#include "../LocalManBiz/SettingData.h"
#include "RecentItemView.h"
#include "LanguageHelper.h"

#include "GroupListData.h"
#include "Framework.h"
#include "SystemIcon.h"
#include "SettingDetail.h"
#include "createnewgroup.h"
#include "portraithelper.h"
#include "SystemDefine.h"
#include "CallbackReceiver.h"
#include "gloableeventobject.h"
#include "UiHelper.h"

#include "SystemConfigData.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "editablesettings.h"
#include "addnoteinfor.h"
#include "qcloudmanager.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "passwordinput.h"
#include "noteeditdialog.h"


const static char* user_data = "user_data";
const int maxWidth = 100;
int btnheigh = 30;
void MultiDialogContainer::InitNoteInfor()
{
    connect(ui->pbtn_addNote, &QPushButton::clicked, this, &MultiDialogContainer::onAddNote);
	connect(ui->pbtn_addSubNote, &QPushButton::clicked, this, &MultiDialogContainer::onAddSubNote);

}

void MultiDialogContainer::onAddNote()
{
	//先判断内存中有没有主密钥
	//如果没有，需要输入主密钥
	QString strMainKey = MainApp::UIFrame::getConversationController()->getMainKey();
	if (strMainKey.isEmpty())
	{
		//提示进行输入主密码，然后内存中保存主密码
		PasswordInput *pwd = PasswordInput::getInstance();
		if (pwd)
		{
			if (pwd->exec() == QDialog::Accepted)
			{
				QString strPwd = pwd->getPassword();
				if (!strPwd.isEmpty())
				{
					MainApp::UIFrame::getConversationController()->setMainKey(strPwd);
				}
			}
		}
	}


	AddNoteInfor *pdialog = AddNoteInforSingleton::getInstance();
	if (pdialog)
	{
		pdialog->showNoteInfo();
		if (QDialog::Accepted == pdialog->exec())
		{
			QString notetitle = pdialog->getNoteTitle();
			QString notedesc = pdialog->getNoteDesc();

			QString btnid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", ""); 

			addOneNote(notetitle, btnid);


			//这里需要请求服务器了
			auto callback = mReceiver->createCallback<QString>([this](const QString& bret)
			{
				QJsonDocument Json_Data = QJsonDocument::fromJson(bret.toUtf8());

				QVariantMap dataMap = Json_Data.toVariant().toMap();

				bool ret = dataMap["ret"].toBool();
				QString mainkey = dataMap["key"].toString();



			}, []{});

			Biz::Session::getqCloudManager()->setSaveqcloudMainInfo(notetitle, notedesc, strMainKey, Biz::qCloudType::Evenote, callback);


		}

	}
}

void MultiDialogContainer::onAddSubNote()
{
	//先判断内存中有没有主密钥
	//如果没有，需要输入主密钥
	QString strMainKey = MainApp::UIFrame::getConversationController()->getMainKey();
	if (strMainKey.isEmpty())
	{
		//提示进行输入主密码，然后内存中保存主密码
		PasswordInput *pwd = PasswordInput::getInstance();
		if (pwd)
		{
			if (pwd->exec() == QDialog::Accepted)
			{
				QString strPwd = pwd->getPassword();
				if (!strPwd.isEmpty())
				{
					MainApp::UIFrame::getConversationController()->setMainKey(strPwd);
				}
			}
		}
	}

	AddNoteInfor *pdialog = AddNoteInforSingleton::getInstance();
	if (pdialog)
	{
		pdialog->showNoteInfo();
		if (QDialog::Accepted == pdialog->exec())
		{
			QString notetitle = pdialog->getNoteTitle();
			QString notedesc = pdialog->getNoteDesc();

			NoteEditDialog *pdlg = NoteEditDialogSingleton::getInstance();
			if (pdlg)
			{
				pdlg->ShowNoteEditDialog();
				if (QDialog::Accepted == pdlg->exec())
				{
					QString content = pdlg->getContent();

					Biz::Session::getqCloudManager()->setSaveqcloudSunInfo(notetitle, notedesc, content, Biz::Evenote,NULL);

				}
				
			}
		}
	}

}

void MultiDialogContainer::addOneNote(const QString&title, const QString&id)
{
	if (title.isEmpty())
	{
		return;
	}
	QPushButton *pbtn = new QPushButton(ui->notegroup);

	pbtn->setAutoExclusive(true);
	pbtn->setFlat(true);
	pbtn->setCheckable(true);
	int nWidth = MainApp::getMaxWidthbyfont(title, maxWidth, ui->pbtn_addNote->font());
	if (nWidth < 50)
	{
		nWidth = 60;
	}
	pbtn->setFixedSize(nWidth,btnheigh);
	pbtn->move(10, 10);
	pbtn->setProperty(user_data, id);
	pbtn->setText(title);
	pbtn->show();


	ui->notegroupLayout->addWidget(pbtn);

	connect(pbtn,&QPushButton::clicked,this,&MultiDialogContainer::onNoteBtnClicked);


	//int fixwidth = nWidth+ui->notegroup->width() + ui->notegroupLayout->spacing();
	int fixwidth = (ui->notegroupLayout->count()-1)*(50 + nWidth+ui->notegroupLayout->spacing()) + 70+ui->notegroupLayout->spacing();
	ui->notegroup->setFixedWidth(fixwidth);


}

void MultiDialogContainer::onNoteBtnClicked()
{
	QPushButton* btn = dynamic_cast<QPushButton*>(sender());

	// 表情切换
	QString clickedid = btn->property(user_data).toString();
}