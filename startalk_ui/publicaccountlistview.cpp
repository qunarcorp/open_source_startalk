#include "publicaccountlistview.h"
#include "UIFrame.h"
#include "friendscontroller.h"

PublicAccountListView::PublicAccountListView(QWidget *parent)
	: PinnedListView(parent)
{
	MainApp::UIFrame::getFriendsController ()->registPublicAccountListView (this);
}

PublicAccountListView::~PublicAccountListView()
{

}
