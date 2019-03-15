#ifndef PUBLICACCOUNTLISTVIEW_H
#define PUBLICACCOUNTLISTVIEW_H

#include <QListView>
#include "diywidgit/customviews/pinnedlistview.h"
class PublicAccountListView : public PinnedListView
{
	Q_OBJECT

public:
	PublicAccountListView(QWidget *parent=NULL);
	~PublicAccountListView();
};

#endif // PUBLICACCOUNTLISTVIEW_H
