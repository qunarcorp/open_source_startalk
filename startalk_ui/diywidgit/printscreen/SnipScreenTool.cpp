#include "SnipScreenTool.h"
#include "FullScreenWidget.h"
#include <QToolButton>
#include "QBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "ActionCommand.h"
#include <qdebug.h>
#include <QApplication>
#include <QClipboard>
#include "floatTextEdit.h"
#include <QApplication>
#include <QDesktopWidget>
#include "snipscreemtoolbar.h"

SnipScreenTool* SnipScreenTool::pInstance = NULL;
SnipScreenTool* SnipScreenTool::getInstance()
{
    // 仅限ui调用，不用锁了
    if (NULL == pInstance)
    {
        pInstance = new SnipScreenTool(NULL);
    }
    return pInstance;
}


SnipScreenTool::SnipScreenTool(QObject *parent)
    : FullScreenWidget()
{
	auto remove = Qt::WindowTitleHint;
	auto add = Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint|Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));


    m_Actioning = NULL;
    _beEdit = false;
    m_currentType = drawNotSet;

    m_toolbar = new SnipScreemToolBar(this);
    _fontSize = 12;
    pEdit = new floatTextEdit(this);
    connect(m_toolbar,&SnipScreemToolBar::sgColorChange,this,&SnipScreenTool::onPenColorChanged);
    connect(m_toolbar,&SnipScreemToolBar::sgPenSizeChange,this,&SnipScreenTool::onPenSizeChanged);
    connect(m_toolbar,&SnipScreemToolBar::sgToolSelect,this,&SnipScreenTool::onToolBarTypeChanged);

    connect(m_toolbar,&SnipScreemToolBar::sgOk,[this]( ){
        onSaveContext();
        // 写入剪切板
        if(m_actionStatck.empty())
        {
            QApplication::clipboard()->setImage( selectPixmap().toImage()); 
        }else{
            QApplication::clipboard()->setImage( m_actionStatck.top()->CurrentPipxmap().toImage()); 
            //清栈
            while(!m_actionStatck.empty())
                m_actionStatck.pop();
        }            

		      

        hide(); 
        emit sgFinish(mConversionId);
    });
    connect(m_toolbar,&SnipScreemToolBar::sgCancle,[this](){
        //取消截图
        hide(); 
        emit sgCancel(mConversionId);
    });

    connect(m_toolbar,&SnipScreemToolBar::sgUndo,this,&SnipScreenTool::onUndo);
}

// 组件初始化，归到初始状态
SnipScreenTool& SnipScreenTool::Init()
{
    FullScreenWidget::reset();
    pEdit->InitWidget();
    pEdit->setVisible(false);
    m_Actioning = NULL;
    _beEdit = false;
    m_currentType = drawNotSet;
    while(!m_actionStatck.empty())m_actionStatck.pop();
    m_toolbar->setVisible(false);
    m_toolbar->initToolBar();
    return *this;
}

SnipScreenTool::~SnipScreenTool()
{
}

// 显示右键菜单
void SnipScreenTool::showPictureEditContextMenu(const QPoint& pos)
{
    _beEdit = true;
}

// 显示编辑框
void SnipScreenTool::showPictureEditBar(const QRect& rec)
{
	int nRatio = this->devicePixelRatio();
    QRect rect = getSelectedRect();

	QPoint ptRight = rect.bottomRight();

	QPoint ptxd = mapToGlobal(ptRight);
	
    int nToolbarBottom =  rect.bottomRight().y() / nRatio +5;

    int screemBottom =  QApplication::desktop()->screenGeometry().bottom();
    bool b = nToolbarBottom+80 > screemBottom;

    if (b)
    {
        nToolbarBottom = nToolbarBottom - m_toolbar->getHeight();
        m_toolbar->setDirect(0);
    }
    else
    {
        m_toolbar->setDirect(1);
    }

	
	//这地方需要判断屏幕的边界
	for (int i = 0; i < QApplication::desktop()->screenCount(); i++)
	{
		QRect rectdesk;
		rectdesk.setLeft(QApplication::desktop()->screenGeometry(i).left());
		rectdesk.setTop(QApplication::desktop()->screenGeometry(i).top());
		rectdesk.setRight(QApplication::desktop()->screenGeometry(i).right());
		rectdesk.setBottom(QApplication::desktop()->screenGeometry(i).bottom());
		int rectdesktop = rectdesk.top();
		int rectdeskleft = rectdesk.left();
		int rectdeskwidth = rectdesk.width();
		int rectdeskheigh = rectdesk.height();

		int ptxdx = ptxd.x();
		int ptxdy = ptxd.y();

		if (rectdesk.contains(ptxd))
		{
			
			if (ptxd.x() - rectdesk.left() > m_toolbar->width())
			{
				//这地方判断一下toolbar是在截图框的下面，还是上面
				if (rectdesk.bottom() - rect.bottom() > m_toolbar->height())
				{
					int nx = rect.bottomRight().x() / nRatio - m_toolbar->width();
					int ny = nToolbarBottom;
					int nrecty = rect.bottomRight().x();
					m_toolbar->move(rect.bottomRight().x() / nRatio - m_toolbar->width(), rect.bottomRight().y() + 5);
				}
				else
				{
					int xd = ptxd.x();
					int nmovex = rect.bottomRight().x() / nRatio - m_toolbar->width();
					int nmovey = rect.top() - 40;
					//这里还需要判断top的问题
					if (rect.top() - rectdesk.top() > m_toolbar->height())
					{
						m_toolbar->move(rect.bottomRight().x() / nRatio - m_toolbar->width(), rect.top() - 40);
					}
					else
					{
						m_toolbar->move(rect.bottomRight().x() / nRatio - m_toolbar->width(), rect.bottom() - 40);
					}
					
					
				}
				
			}
			else
			{
				
				if (rectdesk.bottom() - rect.bottom() > m_toolbar->height())
				{

					m_toolbar->move(rect.x() / nRatio , nToolbarBottom);
				}
				else
				{
// 					int xd = ptxd.x();
// 					int nleft = rect.left();
// 					int nd = rect.bottomRight().x();
// 					int ntoolwidth = m_toolbar->width();
// 					m_toolbar->move(rect.x() / nRatio , rect.top() - 40);

					//这里还需要判断top的问题
					if (rect.top() - rectdesk.top() > m_toolbar->height())
					{
						m_toolbar->move(rect.x() / nRatio , rect.top() - 40);
					}
					else
					{
						m_toolbar->move(rect.x() / nRatio , rect.bottom() - 40);
					}
				}
				
			}
			break;
		}
		else
		{
			int a = 8;
			a = 9;
		}
	}


    //m_toolbar->move(rect.bottomRight().x()/nRatio - m_toolbar->width(),nToolbarBottom);
    m_toolbar->show();
	m_toolbarrect = m_toolbar->geometry();
}

void SnipScreenTool::mousePressEvent(QMouseEvent * event)
{
	

    if (event->button() == Qt::MouseButton::LeftButton && m_currentType == drawNotSet && !_beEdit)
    {
        return FullScreenWidget::mousePressEvent( event );
    }
    // 按下即创建命令
    if (m_Actioning==NULL )
    {
        m_Actioning = new ActionCommand(_brushColor,_fontSize,_burshSize);
		m_Actioning->setdeviceRadio(this->devicePixelRatio());
        m_Actioning->Type((ActionType)m_currentType);
        m_actionStatck.size() > 0
            ? m_Actioning->LastPixmap(m_actionStatck.top()->CurrentPipxmap())
            : m_Actioning->LastPixmap(selectPixmap()); // 设置背景图片

        m_Actioning->TargetRect(getSelectedRect()); // 设置绘制区域框
    }

    m_Actioning->mousePressEvent(event); // 坐绘制准备
    update();
}

void SnipScreenTool::mouseMoveEvent(QMouseEvent * event)
{
    // 没有点过编辑按钮
    if (!_beEdit && m_currentType == drawNotSet )
    {
        return FullScreenWidget::mouseMoveEvent(event);
    }

    if (m_Actioning!=NULL) 
    {
        m_Actioning->mouseMoveEvent(event);
        update();
    }
    event->accept();
}


void SnipScreenTool::mouseReleaseEvent(QMouseEvent * event )
{
	if (event->button() == Qt::RightButton)
	{
		 if(FullScreenWidget::JietuCancel( event))
		 {
			 emit m_toolbar->sgCancle();
		 }
	}

    if (event->button() == Qt::MouseButton::LeftButton )
    {
        // 没有点过编辑按钮
        if (!_beEdit && m_currentType == drawNotSet)
        {
           return  FullScreenWidget::mouseReleaseEvent(event);
        }

        // m_Actioning->mouseReleaseEvent 会返回是否是有效绘制
        if (m_Actioning!=NULL && m_Actioning->mouseReleaseEvent(event,this))
        {
            // 有效的前图压栈
            m_actionStatck.push(m_Actioning);
            m_Actioning = NULL;
            update();
        } 
        else
        {
           // m_Actioning = NULL;
        }
    }
}

void SnipScreenTool::mouseDoubleClickEvent(QMouseEvent * event)
{
	if(FullScreenWidget::JietuCancel(event))
	{
		emit m_toolbar->sgOk();
	}
	return FullScreenWidget::mouseDoubleClickEvent(event);
}


void SnipScreenTool::onForcus(QFocusEvent *eve){
    setCursor(Qt::ArrowCursor);
}

void SnipScreenTool::paintEvent(QPaintEvent *e)
{
    FullScreenWidget::paintEvent(e); // 间接会调用到 SnipScreenTool::drawSelectedPixmap

    if (m_Actioning != NULL)
    {
        m_Actioning->paintEvent(e,this,getPainter(),this);
    }
    
}

void SnipScreenTool::drawSelectedPixmap(void)
{
    if (m_actionStatck.size()==0)
    {
        return FullScreenWidget::drawSelectedPixmap();
    }

    // 画新图
    ActionCommand* pActionOnTopofStack = m_actionStatck.top();
    QPainter* p = getPainter();
	int nRatio = this->devicePixelRatio();
    QRect rect =  pActionOnTopofStack->TargetRect();
 	rect.setX(rect.x()/nRatio);
 	rect.setY(rect.y() / nRatio);
	if (nRatio != 1)
	{
		rect.setWidth((rect.width() - rect.x()) / nRatio);
		rect.setHeight((rect.height() - rect.y()) / nRatio);
	}
 
    p->drawRect(rect); //画选中的矩形框
    if(rect.width() > 0 && rect.height() > 0){
        p->drawPixmap(rect,pActionOnTopofStack->CurrentPipxmap()); //画选中区域的图片
    }
    draw8ControlPoint(rect);
}

void SnipScreenTool::onPenSizeChanged(int size)
{
    _burshSize = size;
}

void SnipScreenTool::onPenColorChanged(const QString& color)
{
    _brushColor = QColor(color);
}

void SnipScreenTool::onToolBarTypeChanged(SnipScreemToolBar::TOOLTYPE type)
{
    m_currentType = drawNotSet;
    m_currentType = (type==SnipScreemToolBar::TOOLTYPE::SNIP_TOOLBAR_RECT?drawRectangle:m_currentType);
    m_currentType = (type==SnipScreemToolBar::TOOLTYPE::SNIP_TOOLBAR_RING?drawEllipse:m_currentType);
    m_currentType = (type==SnipScreemToolBar::TOOLTYPE::SNIP_TOOLBAR_PEN?drawPen:m_currentType);
    m_currentType = (type==SnipScreemToolBar::TOOLTYPE::SNIP_TOOLBAR_TEXT?drawText:m_currentType);
    m_currentType = (type==SnipScreemToolBar::TOOLTYPE::SNIP_TOOLBAR_ARROW?drawArror:m_currentType);

    onSaveContext();

    FullScreenWidget::LockSelectRange();

    _beEdit = true;
}

void SnipScreenTool::onSaveContext()
{
    if (m_Actioning!=NULL && m_Actioning->mouseReleaseEvent(NULL,this,true))
    {
        // 有效的前图压栈
        m_actionStatck.push(m_Actioning);
        m_Actioning = NULL;
        update();
    } 
}

void SnipScreenTool::onUndo()
{
    onSaveContext();

    if(!m_actionStatck.empty())
    {
         m_actionStatck.pop();
         update();
    }        
}

void SnipScreenTool::keyPressEvent(QKeyEvent *keyEvent)
{
    if (NULL!=keyEvent && keyEvent->modifiers() == Qt::ControlModifier && keyEvent->key() == Qt::Key_Z)
    {
        onUndo();
    }      
    return FullScreenWidget::keyPressEvent(keyEvent);

}

void SnipScreenTool::JietuFinshed()
{
	emit sgFinish(mConversionId);
}

void SnipScreenTool::JietuCancel()
{
	emit sgCancel(mConversionId);
}


