#include "RecentSessionList.h"

#include "rosterItem.h"
#include <QApplication>
#include <QMenu>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QLabel>

#include "Framework.h"
#include "RecentItemView.h"

#include "UiHelper.h"
#include "rosterItemSortFilterProxyModel.h"
#include "CallbackReceiver.h"
#include "RosterList.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "QXmppUtils.h"
#include "XmppMessage.h"
#include "LanguageHelper.h"
#include "rosterItem.h"
#include "recentrosteritemmvd.h"

#include "group_setting.h"
#include "GroupListData.h"
#include "QMessageBox"
#include "GroupChatDialog.h"
#include "MultiDialogContainer.h"
#include "SystemConfigData.h"
#include "portraithelper.h"
#include <QDrag>

#include "BizCallback.h"


#include "SettingData.h"
#include "CustomDefine.h"
#include "gloableeventobject.h"
#include "UserVcardManager.h"
#include "RobotManager.h"
#include "portraithelper.h"
#include "GroupManager.h"
#include "accountmanager.h"
#include "ChatDialog.h"
#include "conversationmanager.h"

#include "RosterListItems.h"
#include "UIFrame.h"
#include "ConversationController.h"

RecentSessionList::RecentSessionList(QWidget *parent)
    : QListWidget(parent)
{
    //initTipPopLabInfor();
}



RecentSessionList::~RecentSessionList()
{

}



void RecentSessionList::resizeEvent(QResizeEvent *e)
{
    return QListWidget::resizeEvent(e);
}
