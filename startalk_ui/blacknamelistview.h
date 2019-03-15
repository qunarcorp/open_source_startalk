#ifndef BLACKNAMELISTVIEW_H
#define BLACKNAMELISTVIEW_H

#include "diywidgit/customviews/pinnedlistview.h"

class QMenu;
class BlackNameListView : public PinnedListView
{
	Q_OBJECT

public:
	BlackNameListView(QWidget *parent);
	~BlackNameListView();
	
private slots:
	
		void onMoveBlackName();
        		virtual void contextMenuEvent( const QString& jid );

private:
	QMenu* pMoveBlackNameMenu;
};

#endif // BLACKNAMELISTVIEW_H
