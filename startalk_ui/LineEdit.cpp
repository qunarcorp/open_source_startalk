#include "LineEdit.h"
#include <QKeyEvent>

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, &LineEdit::customContextMenuRequested, this, &LineEdit::onShowEditMenu);
}

LineEdit::~LineEdit()
{

}

void LineEdit::keyPressEvent( QKeyEvent * e )
{
    do 
    {
        if(e == QKeySequence::Paste){
            //拦截标准的粘贴
            emit sgPaste();
            return;
        }

        if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){
            if( (e->modifiers() & Qt::SHIFT)){
                //shift + 回车，换行
                break;
            }
            else if( e->modifiers() & Qt::CTRL) {
                // ctrl + 回车
                if( emit sgCtrl_EnterPressed() ){
                    return;
                }
                e->setModifiers( e->modifiers() & ~Qt::CTRL);
                //去掉ctrl
                break;
            }
            else {
                if( emit sgEnter_Pressed() ){
                    return;
                }
            }
        }

        //alt +S
        if ((e->modifiers()&Qt::AltModifier) && e->key()==Qt::Key_S )
        {
            if( emit sgAltS_Pressed() )
                return;
        }
    } while (false);

    QLineEdit::keyPressEvent(e);
}

void LineEdit::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit LineEditClicked();
	}
	QLineEdit::mousePressEvent(event);
}

void LineEdit::onShowEditMenu(const QPoint&pt)
{
	mEditMenu = new QMenu(this);

	mActionSelectAll = new QAction(T_("GroupTextEditMenu_item_All"), this);
	connect(mActionSelectAll, &QAction::triggered, this, &LineEdit::onEditSelectAll);
	mEditMenu->addAction(mActionSelectAll);

	mActionCopy = new QAction(T_("GroupTextEditMenu_item_copy"), this);
	connect(mActionCopy, &QAction::triggered, this, &LineEdit::onEditCopy);
	mEditMenu->addAction(mActionCopy);

	mActionPast = new QAction(T_("GroupTextEditMenu_item_past"), this);
	connect(mActionPast, &QAction::triggered, this, &LineEdit::onEditPast);
	mEditMenu->addAction(mActionPast);

	if( this->text().length() > 0 )
	{

		mActionCopy->setEnabled(true);
		mActionSelectAll->setEnabled(true);

	}else{
		mActionCopy->setEnabled(false);
		mActionSelectAll->setEnabled(false);
	}


	mEditMenu->exec(QCursor::pos());
}

void LineEdit::onEditSelectAll()
{
	emit selectAll();
}

void LineEdit::onEditCopy()
{
	emit copy();
}

void LineEdit::onEditPast()
{
	emit sgPaste();
}
