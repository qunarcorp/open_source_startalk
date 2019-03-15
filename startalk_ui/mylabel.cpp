#include "mylabel.h"
#include "diywidgit/customviews/qframelayout.h"
#include "LanguageHelper.h"
#include <QApplication>
#include <QClipboard>

const int LBSTATICWIDTH = 16;
const int LBSTATICHEIGH = 16;

StaticLabel::StaticLabel(QWidget *parent)
	: QLabel(parent)
	,mbstatic(false)
	,lbstatic(NULL)
	,mbltstatic(false)
	,ltstatic(NULL)
{
	lbstatic = new QLabel(this);
	lbstatic->setFixedSize(LBSTATICWIDTH, LBSTATICHEIGH);

	ltstatic = new QLabel(this);
	ltstatic->setFixedSize(LBSTATICWIDTH, LBSTATICHEIGH);

	QFrameLayout* pProtraitLayout = new QFrameLayout(this);
	pProtraitLayout->appendWidget(lbstatic,ALINE_BOTTOM|ALINE_RIGHT);

	pProtraitLayout->appendWidget(ltstatic, ALINE_TOP|ALINE_LEFT);

}

StaticLabel::~StaticLabel()
{

}

void StaticLabel::setlbStaticPixmap( const QPixmap& pixmap )
{
	if (mbstatic)
	{
 		lbstatic->show();
 	}
 	lbstatic->setPixmap(pixmap);
}

void StaticLabel::showStatic( bool bret )
{
	mbstatic = bret;
	mbstatic?lbstatic->show():lbstatic->hide();
}

QSize StaticLabel::getlbStaticSize()
{
	QSize size(LBSTATICWIDTH, LBSTATICHEIGH);
	if (lbstatic)
	{
		QRect rect =  lbstatic->geometry();
		size = rect.size();
	}
	return size;
}


void StaticLabel::showltStatic( bool bret )
{
	mbltstatic = bret;
	mbltstatic?ltstatic->show():ltstatic->hide();
}

void StaticLabel::setltStaticPixmap( const QPixmap& pixmap )
{
	if (mbltstatic)
	{
		ltstatic->show();
	}
	ltstatic->setPixmap(pixmap);
}

///////////////////////////////////////////////////////////
StaticRCPlabel::StaticRCPlabel(QWidget *parent)
	: QLabel(parent)
	,menu(NULL)
	,mActionCp(NULL)
	,mActionSelAll(NULL)
	,board(NULL)
{
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this,&QLabel::customContextMenuRequested,this, &StaticRCPlabel::onRMouseClicked);
}

StaticRCPlabel::~StaticRCPlabel()
{

}

void StaticRCPlabel::onRMouseClicked( const QPoint& pt)
{
	if (NULL == menu)
	{
		menu = new QMenu(this);
		mActionCp = new QAction(T_("GroupTextEditMenu_item_copy"), this);
		connect(mActionCp, &QAction::triggered, this, &StaticRCPlabel::onLabelCopy);
		menu->addAction(mActionCp);

		 menu->addSeparator();

		 mActionSelAll = new QAction(T_("GroupTextEditMenu_item_All"), this);
		 connect(mActionSelAll, &QAction::triggered, this, &StaticRCPlabel::onLabelSelAll);
		 menu->addAction(mActionSelAll);

		 
	}

	if (selectedText().length() > 0)
	{
		mActionCp->setEnabled(true);
		mActionSelAll->setEnabled(true);
	}
	else
	{
		mActionCp->setEnabled(false);
		mActionSelAll->setEnabled(true);
	}
	menu->exec(QCursor::pos());
}

void StaticRCPlabel::onLabelCopy()
{
	QString str = text();
	if(str.isEmpty())
	{
		return;
	}

	if(board == NULL)
	{
		board = QApplication::clipboard();
		board->setText(str);
	}
}

void StaticRCPlabel::onLabelSelAll()
{
	this->setSelection(0, text().length());
}

