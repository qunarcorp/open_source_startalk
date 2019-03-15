#include "minichatinfo.h"
#include "Account.h"
#include "Session.h"
MiniChatInfo::MiniChatInfo(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //connect(&Biz::Session::currentAccount(),&Biz::Account::sgChatDialogUnreadChange,this,&MiniChatInfo::onChatDialogUnreadChange);

}

MiniChatInfo::~MiniChatInfo()
{
    //disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgChatDialogUnreadChange,this,&MiniChatInfo::onChatDialogUnreadChange);
}

void MiniChatInfo::setDisplayName(const QString& string)
{
    ui.title->setText(string);
}

QString MiniChatInfo::getDisplayName()
{
    return ui.title->text();
}

void MiniChatInfo::setDescription(const QString& string)
{
    ui.desc->setText(string);
}

void MiniChatInfo::setUnReadCount(int count)
{
    if (0 == count)
    {
        ui.unread->setVisible(false);
        return;
    }
    ui.unread->setVisible(true);
    ui.unread->setText(QString("%1").arg(count));
}

void MiniChatInfo::setHeaderIcon(const QPixmap& pixmap)
{
    //ui.header->setScaledContents(true);
	QPixmap pix = pixmap;
	pix = QPixmap::fromImage(pix.toImage().scaled(ui.header->size()));
    ui.header->setPixmap(pix);
}


void MiniChatInfo::onRoomListNameReceived(const QMap<QString, QString>& mapData)
{
    if (IsGroupId() && mapData.contains(id))
    {
        setDisplayName(mapData.value(id));
    }
}

void MiniChatInfo::setLastTimeStamp(const QString timestr)
{
    ui.time->setText(timestr);
}

void MiniChatInfo::onChatDialogUnreadChange(const QString& jid,int unread)
{
    if (id == jid)
    {
        setUnReadCount(unread);
    }
}
