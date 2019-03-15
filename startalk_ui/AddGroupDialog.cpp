#include "AddGroupDialog.h"
#include "LanguageHelper.h"
#include "SelectContactDialog.h"
#include "Session.h"
#include "Account.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"


AddGroupDialog::AddGroupDialog(QWidget *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Tool | FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    auto titlebar = ui.titlebarWidget;
    titlebar->setSizeable(false);

    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgMaxOnClicked, this, &LocalManDialog::onMax);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &AddGroupDialog::onClose);

    ui.lblGroupName->setText(T_("AddGroupDlg_groupName"));
    ui.lblMember->setText(T_("AddGroupDlg_memberlist"));
    ui.btnAdd->setText(T_("AddGroupDlg_btnAdd"));
    ui.btnRemove->setText(T_("AddGroupDlg_btnDel"));
    ui.btnOK->setText(T_("MinitoolBar_Ok"));
    ui.btnCancel->setText(T_("MinitoolBar_Cancel"));

    connect(ui.btnCancel, &QPushButton::clicked, this, &AddGroupDialog::onCancel);
    connect(ui.btnOK, &QPushButton::clicked, this, &AddGroupDialog::onOK);
    connect(ui.btnAdd, &QPushButton::clicked, this, &AddGroupDialog::onAddMember);
    connect(ui.btnRemove, &QPushButton::clicked, this, &AddGroupDialog::onRemoveMember);
    
    ui.titlebarWidget->setLeftTitle(T_("MainMenu_AddGroup"));
    this->setWindowTitle(T_("MainMenu_AddGroup"));
	connect(ui.listWidget, &QListWidget::itemClicked, this, &AddGroupDialog::onClickedItem );
	
}

AddGroupDialog::~AddGroupDialog()
{

}
void AddGroupDialog::onCancel(bool)
{
	m_strFirstOne = "";
     this->reject();
}

void AddGroupDialog::onOK(bool)
{
	m_strFirstOne="";
    if(ui.lineEdit->text().length() == 0)
    {
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage (T_("MessageBox_EmptyGroupName"));
        return;
    }
    this->accept();
}
void AddGroupDialog::onAddMember(bool)
{
    SelectContactDialog dlg;
    dlg.setGroupList(NULL);  
    if(QDialog::Accepted == dlg.exec())
    {
        resultList =  dlg.getSelectedItem();
        for(QPair<QString,QString> item : resultList)
        {
            QList<int> p;            
            if( (ui.listWidget->findItems(item.first,Qt::MatchExactly)).count() == 0 )
            {
                ui.listWidget->addItem(item.first);
            }
        }
    }
}

void AddGroupDialog::onRemoveMember(bool)
{
    if(ui.listWidget->selectedItems().count() > 0)
    {
        QString strName = ui.listWidget->selectedItems().at(0)->text();
        ui.listWidget->takeItem(ui.listWidget->row(ui.listWidget->selectedItems().at(0)));
        for(QPair<QString,QString> item : resultList)
        {
            if(item.first == strName)
            {
                resultList.removeOne(QPair<QString,QString>(item.first, item.second));
                break;
            }
        }
    }
}
QString AddGroupDialog::getGroupName()
{
    return ui.lineEdit->text();
}

QList<QPair<QString,QString>> AddGroupDialog::getSelectedItem()
{


    //return resultList;
	QList<QPair<QString,QString>> myresultList;
	int ncount = ui.listWidget->count();
	for (int nI = 0; nI < ncount; nI++)
	{
		QListWidgetItem *item = ui.listWidget->item(nI);
		QString strName = item->text();

		QString uid = Biz::Session::currentAccount().getUserIDByName(strName);
		if (uid.isEmpty())
		{ 
			uid = strName; 
		} 

		myresultList.append(QPair<QString,QString>(strName, uid) ); 
	}
	
	return myresultList;
}
void AddGroupDialog::onClose(bool)
{
    this->close();
}
void AddGroupDialog::AddOneItem(const QString& id)
{
	m_strFirstOne = id;
	 ui.listWidget->addItem(id);
}

void AddGroupDialog::SetBtnRemove(bool bret)
{
	if (bret)
	{
		ui.btnRemove->show();
	}
	else
	{
		ui.btnRemove->hide();
	}
}
void AddGroupDialog::onClickedItem(QListWidgetItem *item)
{
	QString strName = ui.listWidget->selectedItems().at(0)->text();
	if (!m_strFirstOne.isEmpty() && strName == m_strFirstOne)
	{
		SetBtnRemove(false);
	}
	else
	{
		SetBtnRemove(true);
	}

}