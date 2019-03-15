#ifndef STARTPERSONLISTVIEW_H
#define STARTPERSONLISTVIEW_H

#include "diywidgit/customviews/pinnedlistview.h"

class QMenu;
class StarPersonListView : public PinnedListView
{
	Q_OBJECT

public:
	StarPersonListView(QWidget *parent);
	~StarPersonListView();

private slots:
	void onMoveStarPerson();
	virtual void contextMenuEvent( const QString& jid );


private:
	QMenu* pMoveBlackNameMenu;	
};

#endif // STARTPERSONLISTVIEW_H
