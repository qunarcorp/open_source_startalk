#include "FullScreenWidget.h"
#include <QAction>
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QToolButton>
#include <qdebug.h>
#include <QProcess>

#define T_ 

const QColor FullScreenWidget::s_main_qcolor =  QColor(27,169,186);
const QColor FullScreenWidget::s_qcolor_50trans =  QColor(27,169,186,127);
const QColor FullScreenWidget::s_black_60trans =  QColor(0,0,0,153);

FullScreenWidget::FullScreenWidget()
{
    setMouseTracking(true);
    using namespace Qt;
    auto remove = WindowTitleHint;
	auto add = Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint|Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	
    tipWidth = 300; //温馨提示框的宽度
    tipHeight = 100; //温馨提示框的高度
    infoWidth = 120; //坐标信息框的宽度
    infoHeight = 50; //坐标信息框的高度

    screenx = 0;
    screeny = 0;
    screenwidth = 0;
    screenheight = 0;
    initFullScreenWidget();
    setAttribute(Qt::WA_DeleteOnClose, true);
    startTimer(1000/25);
}


void FullScreenWidget::reset()
{
    initFullScreenWidget();
}


FullScreenWidget::~FullScreenWidget()
{

}
void FullScreenWidget::initFullScreenWidget()
{
    currentShotState = initShot;
    controlValue = moveControl0;
    beginPoint =QPoint(0,0);
    m_endPoint = QPoint(0,0);
    moveBeginPoint = QPoint(0,0);
    moveEndPoint = QPoint(0,0);
    m_selectedRect = QRect();

    tlRect = QRect(0,0,0,0); //左上点
    trRect = QRect(0,0,0,0); //上右点
    blRect = QRect(0,0,0,0); //左下点
    brRect = QRect(0,0,0,0); //右下点
    tcRect = QRect(0,0,0,0); //上中点
    bcRect = QRect(0,0,0,0); //下中点
    lcRect = QRect(0,0,0,0); //左中点
    rcRect = QRect(0,0,0,0); //右中点

    setCursor(Qt::ArrowCursor);
}

void FullScreenWidget::loadBackgroundPixmap()
{
    int width = QApplication::desktop()->size().width();
    int height = QApplication::desktop()->size().height();

    for (int i =0; i<QApplication::desktop()->screenCount(); i++)
    {
        int nleftPos = QApplication::desktop()->screenGeometry(i).left();
        int nTopPos = QApplication::desktop()->screenGeometry(i).top();
        screenx = nleftPos < screenx ? nleftPos : screenx;
        screeny = nTopPos<screeny? nTopPos:screeny;
    }

    screenx = screenx;
    screeny = screeny;

    screenwidth = width;
    screenheight = height;
    m_DesktopRect = QApplication::desktop()->rect();

#ifdef _WINDOWS
    QPixmap result = QPixmap::grabWindow(QApplication::desktop()->winId(),screenx,screeny,m_DesktopRect.width(),m_DesktopRect.height()); //抓取当前屏幕的图片
#else
    QStringList args;

    args << "--file=/tmp/1.png" ;

    QProcess::execute("gnome-screenshot",args);

    QPixmap result("/tmp/1.png");
#endif

    loadBackgroundPixmap(result,0,0,width,height);
    //    this->setGeometry(screenx,screeny,screenwidth,screenheight);
    this->resize(screenwidth,screenheight);
    this->move(screenx,screeny);
}



/*
*	加载覆盖屏幕大小的大图，28 18是为了获取四倍放大图所用的透明边框
*/
void FullScreenWidget::loadBackgroundPixmap(const QPixmap &bgPixmap, int x, int y, int width, int height)
{
    loadPixmap = bgPixmap;
	loadPixmap.setDevicePixelRatio(this->devicePixelRatio());
    loadImage = loadPixmap.toImage();
    catchPixmap = QPixmap(loadPixmap.width()+28,loadPixmap.height()+18);
    catchPixmap.fill(QColor(0,255,0,0));
    QPainter p(&catchPixmap);
    p.drawPixmap(14,9,loadPixmap);
    initFullScreenWidget();
}


void FullScreenWidget::loadBackgroundCursorPixmap()
{
	int width = 0;
	int height = 0;
	QPoint pt = QCursor::pos();

	for (int i = 0; i < QApplication::desktop()->screenCount(); i++)
	{
		QDesktopWidget* pDeskTop = QApplication::desktop();
		QWidget *pdes = pDeskTop->screen(i);
		QRect pScreenRect = pdes->geometry();
		if (pScreenRect.contains(pt))
		{
			m_DesktopRect = pScreenRect;
			int nleftPos = pScreenRect.left();
			int ntopPos = pScreenRect.top();
			screenx = nleftPos;
			screeny = ntopPos;
			width = pScreenRect.width()* pdes->devicePixelRatio();
			height = pScreenRect.height()* pdes->devicePixelRatio();
		}


	}
	screenwidth = width;
	screenheight = height;
	m_DesktopRect = QRect(screenx, screeny, width, height);

	QPixmap result = QPixmap::grabWindow(QApplication::desktop()->winId(), screenx, screeny, width, height); //抓取当前屏幕的图片
	//result.save(QString("C:\\Users\\qunar\\AppData\\Roaming\\Qunar\\result_%1_%2_(%4,%5)_%3.png").arg(screenwidth).arg(screenheight).arg(QDateTime::currentDateTime().toString("yyyyMMddHHmmss")).arg(screenx).arg(screeny));
	loadBackgroundPixmap(result, 0, 0, width, height);
	//    this->setGeometry(screenx,screeny,screenwidth,screenheight);
	this->resize(screenwidth, screenheight);
	this->move(screenx, screeny);
}

/*
*	抓取大图
*/
QPixmap FullScreenWidget::getFullScreenPixmap()
{
    QPixmap result = QPixmap();
    m_DesktopRect = QApplication::desktop()->rect();
    result = QPixmap::grabWindow(QApplication::desktop()->winId(),screenx,screeny,m_DesktopRect.width(),m_DesktopRect.height()); //抓取当前屏幕的图片
    return result;
}

void FullScreenWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this); //进行重绘

    QBrush bush(QColor(0,174,255));
    painter.setPen(QPen(bush,2,Qt::SolidLine,Qt::FlatCap));//设置画笔
	loadPixmap.setDevicePixelRatio(this->devicePixelRatio());
    painter.drawPixmap(0,0,loadPixmap); //将背景图片画到窗体上
    painter.fillRect(0,0,screenwidth,screenheight,s_black_60trans); //画影罩效果




 switch(currentShotState){
    case initShot:
        drawHoverWindowPixmap();
        drawShotPictureInfo(); // 绘制坐标信息跟踪窗口
        break;
    case beginSelectShot:
		{
			m_selectedRect = getRect(mInitBeginRect/*beginPoint*/,mInitEndRect/*m_endPoint*/); //获取选区
			drawSelectedPixmap();
			drawShotPictureInfo(); // 绘制坐标信息跟踪窗口
		}
		break;
    case goingSelectShot:
        {
            m_selectedRect = getRect(beginPoint,m_endPoint); //获取选区
            drawSelectedPixmap();
            drawShotPictureInfo(); // 绘制坐标信息跟踪窗口
        }
        break;
    case lockSelect:
    case finishSelectShot:
        {
            m_selectedRect = getRect(beginPoint,m_endPoint); //获取选区
            drawSelectedPixmap();
//            drawShotPictureInfo(); // 绘制坐标信息跟踪窗口?
            showPictureEditBar(m_selectedRect);
        }
        break;
    case lbclick:
        {
            if (m_selectedRect.isNull())
            {
                // 点击了当前选择窗口
#if _WINDOWS
                m_selectedRect = GetCursorInRect();
#else
                m_selectedRect = m_d.GetDestTopRect();
#endif
            }
            beginPoint = m_selectedRect.topLeft();
            m_endPoint = m_selectedRect.bottomRight();
            drawSelectedPixmap();
            showPictureEditBar(m_selectedRect);
        }
        break;
    case beginMoveShot:
    case finishMoveShot:
        {
            m_selectedRect = getMoveAllSelectedRect(); //获取选区
            drawSelectedPixmap();
            showPictureEditBar(m_selectedRect);
        }
        break;
    case beginControl:
        {
            m_selectedRect = getMoveControlSelectedRect();
            drawSelectedPixmap();
            showPictureEditBar(m_selectedRect);
        }
        break;
    case finishControl:
        {
            m_selectedRect = getMoveControlSelectedRect();			
            drawSelectedPixmap();
            showPictureEditBar(m_selectedRect);

            controlValue = moveControl0;
        }
        break;
    default:
        break;
    }  

    drawXYWHInfo(); //打印坐标信息


    painter.end();  //重绘结束

    if(currentShotState == finishMoveShot || currentShotState == finishControl){
        updateBeginEndPointValue(m_selectedRect); //当移动完选区后，更新beginPoint,endPoint;为下一次移动做准备工作
    }

    //     this->setFocus();
    //     this->activateWindow();

    QWidget::paintEvent(event);
}

void FullScreenWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        initFullScreenWidget();
        //m_miniToolBar->setVisible(false);
        hide();
    }

    QWidget::keyPressEvent(event);
}

void FullScreenWidget::mousePressEvent(QMouseEvent *event)
{
    //当开始进行拖动进行选择区域时,确定开始选取的beginPoint坐标
    if(event->button() == Qt::LeftButton && currentShotState == initShot){
        currentShotState = beginSelectShot; //设置当前状态为beginShot状态
        beginPoint = event->pos();
		beginPoint = beginPoint * this->devicePixelRatio();
		int a = 9;
    }

    //移动选区改变选区的所在位置
    if(event->button() == Qt::LeftButton && isInSelectedRect(event->pos()*this->devicePixelRatio()) && 
        getMoveControlState(event->pos()) == moveControl0){
            currentShotState = beginMoveShot; //启用开始移动选取选项,beginMoveShot状态
            moveBeginPoint = event->pos();
			moveBeginPoint = moveBeginPoint * this->devicePixelRatio();
			int a = 10;
    }
    //移动控制点改变选区大小
    if(event->button() == Qt::LeftButton && getMoveControlState(event->pos()) != moveControl0){
        currentShotState = beginControl; //开始移动控制点
        controlValue = getMoveControlState(event->pos());
        moveBeginPoint = event->pos();
		moveBeginPoint = moveBeginPoint*this->devicePixelRatio();
		int a = 10;
    }
	
    QWidget::mousePressEvent(event);
}

void FullScreenWidget::mouseReleaseEvent(QMouseEvent *event)
{
    // 点击了hover窗口
    if(event->button() == Qt::LeftButton && currentShotState == beginSelectShot ){
        currentShotState = lbclick;
        updateMouseShape(event->pos()*this->devicePixelRatio());
        //update();	
    }

    if(event->button() == Qt::LeftButton && currentShotState == goingSelectShot ){
        m_endPoint = event->pos();
		m_endPoint = m_endPoint *this->devicePixelRatio();
        currentShotState = finishSelectShot;
        //update();	
    }



    if(event->button() == Qt::LeftButton && currentShotState == beginMoveShot){
        currentShotState = finishMoveShot;
        moveEndPoint = event->pos();
		moveEndPoint = moveEndPoint*this->devicePixelRatio();
       // update();

    }

    //当前状态为beginControl状态时，设置状态为finishControl
    if(event->button() == Qt::LeftButton && currentShotState == beginControl){
        currentShotState = finishControl;		
        moveEndPoint = event->pos();
		moveEndPoint = moveEndPoint*this->devicePixelRatio();
    }

    // 右键释放状态
    if (event->button() == Qt::RightButton)
    {
        if (currentShotState == initShot)
        {
            this->hide();
        }
        else 
        {
            if (m_selectedRect.contains(event->pos()))
            {
                // menu
                showPictureEditContextMenu(event->pos());
            }
            else
            {
                currentShotState = initShot;
               // update();
            }
        }
    }
	
// 	QRect rec = getSelectedRect();
// 	QString str= QString("rect.x=%1, rect.y=%2, rect.width=%3, rect.height=%4, pt.x=%5, pt.y=%6")
// 		.arg(rec.x()).arg(rec.y()).arg(rec.width()).arg(rec.height()).arg(event->pos().x()).arg(event->pos().y());
// 
// 	if( (event->button()== Qt::RightButton) && rec.contains(event->pos()))
// 	{
// 		JietuCancel();
// 	}
	update();
    QWidget::mouseReleaseEvent(event);
}

void FullScreenWidget::mouseMoveEvent(QMouseEvent *event)
{
    
    //当拖动时，动态的更新所选择的区域
    if(currentShotState == beginSelectShot || currentShotState == goingSelectShot){ 
        m_endPoint = event->pos();
		m_endPoint = m_endPoint*this->devicePixelRatio();
        currentShotState = goingSelectShot;
        //update();		
    }

    //当确定选区后，对选区进行移动操作
    if(currentShotState == beginMoveShot || currentShotState == beginControl){
        moveEndPoint = event->pos();
		moveEndPoint = moveEndPoint*this->devicePixelRatio();
        update();		
    }

    updateMouseShape(event->pos()*this->devicePixelRatio()); //修改鼠标的形状
    setMouseTracking(true);
	update();
    QWidget::mouseMoveEvent(event);
   
}

void FullScreenWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(currentShotState == finishSelectShot 
        || currentShotState == beginMoveShot 
        || currentShotState == finishControl
        || currentShotState == lbclick){
            finishPixmap(shotPixmap);
            //hide();
			
    }
	
	
    QWidget::mouseDoubleClickEvent(event);
}

QRect FullScreenWidget::getRect(const QPoint &beginPoint, const QPoint &endPoint)
{
    int x,y,width,height;
    width = qAbs(beginPoint.x() - endPoint.x()) +1 ;
    height = qAbs(beginPoint.y() - endPoint.y()) + 1;
    x = beginPoint.x() < endPoint.x() ? beginPoint.x() : endPoint.x();
    y = beginPoint.y() < endPoint.y() ? beginPoint.y() : endPoint.y();

    return QRect(x,y,width,height);
}



bool FullScreenWidget::isInSelectedRect(const QPoint &point)
{
    int x,y;
    QRect selectedRect;
    if(currentShotState == initShot || currentShotState == beginSelectShot)
        return false;

    selectedRect = getSelectedRect();
    x = point.x();
    y = point.y();

    return selectedRect.contains(x,y);
}

void FullScreenWidget::cancelSelectedRect(bool checked /*= false*/)
{
    initFullScreenWidget();
    //update(); //进行重绘，将选取区域去掉
    // m_miniToolBar->setVisible(false);
    this->hide();
}

void FullScreenWidget::drawTipsText()
{
//     int x = (screenwidth - tipWidth)/2;
//     int y = (screenheight - tipHeight)/2;
//     QColor color = QColor(100,100,100,200);
//     QRect rect = QRect(x,y,tipWidth,tipHeight);
//     QString strTipsText = QString(tr("温馨提示\n鼠标拖动进行截屏;截屏区域内右键保存;\n截屏区域外右键取消;ESC退出;"));
// 
//     painter.fillRect(rect,color); 
//     painter.setPen(QPen(Qt::white));//设置画笔的颜色为白色
//     painter.drawText(rect,Qt::AlignCenter,strTipsText);  

}

QRect FullScreenWidget::getSelectedRect()
{
    if(currentShotState == beginMoveShot){
        return getMoveAllSelectedRect();
    }
    else if(currentShotState == beginControl){
        return getMoveControlSelectedRect();
    }
    else{
        return getRect(beginPoint,m_endPoint);
    }
}

QRect FullScreenWidget::getRelativeSelectedRect()
{
	return QRect(0, 0, 0, 0);
}

void FullScreenWidget::updateBeginEndPointValue(const QRect &rect)
{
    beginPoint = rect.topLeft();
//    m_endPoint = QPoint(rect.bottomRight().x()+1,rect.bottomRight().y()+1);
    m_endPoint = rect.bottomRight();

    moveBeginPoint = QPoint(0,0);
    moveEndPoint = QPoint(0,0);
}

void FullScreenWidget::checkMoveEndPoint()
{
    int x,y;
    QRect selectedRect = getRect(beginPoint, m_endPoint);
    QPoint bottomRightPoint = selectedRect.bottomRight();
    x = moveEndPoint.x() - moveBeginPoint.x();
    y = moveEndPoint.y() - moveBeginPoint.y();

    if(x + selectedRect.x() < 0){ //当移动后X坐标小于零时，则出现选区丢失，则计算出moveEndPoint的X最大坐标值，进行赋值
        moveEndPoint.setX(qAbs(selectedRect.x()-moveBeginPoint.x()));
    }

    if(y + selectedRect.y() < 0){ //当移动后Y坐标小于零时，则出现选区丢失，则计算出moveEndPoint的Y最大坐标值，进行赋值
        moveEndPoint.setY(qAbs(selectedRect.y() - moveBeginPoint.y()));
    }

    if(x + bottomRightPoint.x() > screenwidth){ //当移动选区后，出现超出整个屏幕的右面时，设置moveEndPoint的X的最大坐标
        moveEndPoint.setX(screenwidth/this->devicePixelRatio() - bottomRightPoint.x() + moveBeginPoint.x());
    }

    if(y + bottomRightPoint.y() > screenheight){ //当移动选区后，出现超出整个屏幕的下面时，设置moveEndPoint的Y的最大坐标值
        moveEndPoint.setY(screenheight/this->devicePixelRatio() - bottomRightPoint.y() + moveBeginPoint.y());
    }
}

void FullScreenWidget::draw8ControlPoint(const QRect &rect)
{
    int x,y;
    QColor color= s_main_qcolor; //画点的颜色设置
    QPoint tlPoint = rect.topLeft(); //左上点
    QPoint trPoint = rect.topRight(); //右上点
    QPoint blPoint = rect.bottomLeft(); //左下点
    QPoint brPoint = rect.bottomRight(); //右下点

    x = (tlPoint.x()+trPoint.x())/2;
    y = tlPoint.y();
    QPoint tcPoint = QPoint(x,y); 

    x = (blPoint.x()+brPoint.x())/2;
    y = blPoint.y();
    QPoint bcPoint = QPoint(x,y); 

    x = tlPoint.x();
    y = (tlPoint.y()+blPoint.y())/2;
    QPoint lcPoint = QPoint(x,y); 

    x = trPoint.x();
    y = (trPoint.y()+brPoint.y())/2;
    QPoint rcPoint = QPoint(x,y); 

    tlRect = QRect(tlPoint.x()-2,tlPoint.y()-2,6,6); //左上点
    trRect = QRect(trPoint.x()-2,trPoint.y()-2,6,6); //右上点
    blRect = QRect(blPoint.x()-2,blPoint.y()-2,6,6); //左下点
    brRect = QRect(brPoint.x()-2,brPoint.y()-2,6,6); //右下点
    tcRect = QRect(tcPoint.x()-2,tcPoint.y()-2,6,6); //上中点
    bcRect = QRect(bcPoint.x()-2,bcPoint.y()-2,6,6); //下中点
    lcRect = QRect(lcPoint.x()-2,lcPoint.y()-2,6,6);//左中点
    rcRect = QRect(rcPoint.x()-2,rcPoint.y()-2,6,6); //右中点

    painter.fillRect(tlRect,color);
    painter.fillRect(trRect,color);
    painter.fillRect(blRect,color);
    painter.fillRect(brRect,color);
    painter.fillRect(tcRect,color);
    painter.fillRect(bcRect,color);
    painter.fillRect(lcRect,color);
    painter.fillRect(rcRect,color);
}

void FullScreenWidget::updateMouseShape(const QPoint &point)
{
    switch(currentShotState){
    case initShot:
    case beginSelectShot:
        setCursor(Qt::ArrowCursor);
        break;
    case beginMoveShot:
        setCursor(Qt::OpenHandCursor);
        break;
    
    case finishSelectShot:
    case lbclick:
    case finishMoveShot:
    case finishControl:
        {

            int padding = 20;
            QRect rec = getSelectedRect();
            QRect recPadding10px = QRect(rec.left()+padding,rec.top()+padding,rec.width()-2*padding,rec.height()-2*padding);
            QPoint pt = point;
//             pt = QCursor::pos();
//              pt = mapFromGlobal(pt);
            if(rec.contains(pt))
            {
                setCursor(Qt::OpenHandCursor);
            }
            else
                updateMoveControlMouseShape(getMoveControlState(pt/this->devicePixelRatio()));
        }

        break;
    case beginControl:
        updateMoveControlMouseShape(controlValue); //调用函数对移动8个控制点进行鼠标状态的改变
        break;
    case goingSelectShot:
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void FullScreenWidget::updateMoveControlMouseShape(controlPointEnum controlValue){
    switch(controlValue){
    case moveControl1:
    case moveControl5:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case moveControl2:
    case moveControl6:
        setCursor(Qt::SizeVerCursor);
        break;
    case moveControl3:
    case moveControl7:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case moveControl4:
    case moveControl8:
        setCursor(Qt::SizeHorCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

FullScreenWidget::controlPointEnum FullScreenWidget::getMoveControlState(const QPoint &point)
{
    FullScreenWidget::controlPointEnum result = moveControl0;
    if(currentShotState == initShot || currentShotState == beginSelectShot)  {
        result = moveControl0;
    }
    else if(tlRect.contains(point)){
        result = moveControl1;
    }
    else if(tcRect.contains(point)){
        result = moveControl2;
    }
    else if(trRect.contains(point)){
        result = moveControl3;
    }
    else if(rcRect.contains(point)){
        result = moveControl4;
    }
    else if(brRect.contains(point)){
        result = moveControl5;
    }
    else if(bcRect.contains(point)){
        result = moveControl6;
    }
    else if(blRect.contains(point)){
        result = moveControl7;
    }
    else if(lcRect.contains(point)){
        result = moveControl8;
    }
    else{
        result = moveControl0;
    }

    return result;
}

QRect FullScreenWidget::getMoveAllSelectedRect(void)
{
    QRect result;
    QPoint tmpBeginPoint,tmpEndPoint;
    int moveX,moveY;
    checkMoveEndPoint(); //对移动选区进行判断，当移动的选区超出边界，则停止移动
    moveX = moveEndPoint.x() - moveBeginPoint.x();
    moveY = moveEndPoint.y() - moveBeginPoint.y();

    tmpBeginPoint.setX(beginPoint.x() + moveX);
    tmpBeginPoint.setY(beginPoint.y() + moveY);
    tmpEndPoint.setX(m_endPoint.x() + moveX);
    tmpEndPoint.setY(m_endPoint.y() + moveY);

    result = getRect(tmpBeginPoint, tmpEndPoint);
    return result;  
}

QRect FullScreenWidget::getMoveControlSelectedRect(void)
{
    int x,y,w,h;
    QRect rect = getRect(beginPoint,m_endPoint);
    QRect result;
    switch(controlValue){
    case moveControl1:
        result = getRect(rect.bottomRight(),moveEndPoint);
        return result;
        break;
    case moveControl2:
        x = rect.x();
        y = getMinValue(moveEndPoint.y(),rect.bottomLeft().y());
        w = rect.width();
        h = qAbs(moveEndPoint.y() - rect.bottomRight().y());
        break;
    case moveControl3:
        result = getRect(rect.bottomLeft(),moveEndPoint);
        return result;
        break;
    case moveControl4:
        x = getMinValue(rect.x(),moveEndPoint.x());
        y = rect.y();
        w = qAbs(rect.bottomLeft().x() - moveEndPoint.x());
        h = rect.height();
        break;
    case moveControl5:
        result = getRect(rect.topLeft(),moveEndPoint);
        return result;
        break;
    case moveControl6:
        x = rect.x();
        y = getMinValue(rect.y(),moveEndPoint.y());
        w = rect.width();
        h = qAbs(moveEndPoint.y() - rect.topLeft().y());
        break;
    case moveControl7:
        result = getRect(moveEndPoint,rect.topRight());
        return result;
        break;
    case moveControl8:
        x = getMinValue(moveEndPoint.x(),rect.bottomRight().x());
        y = rect.y();
        w = qAbs(rect.bottomRight().x() - moveEndPoint.x());
        h = rect.height();
        break;
    default:
        result = getRect(beginPoint,m_endPoint);
        return result;
        break;
    }

    return QRect(x,y,w,h); //获取选区
}

int FullScreenWidget::getMinValue(int num1, int num2)
{
    return num1<num2?num1:num2;
}


/*
 *	获取顶层的自适应窗口
 */
QRect FullScreenWidget::GetCursorInRect()
{
    QRect ret;
    QPoint glCurser = QCursor::pos();
	QPoint newglcurser = glCurser*this->devicePixelRatio();
    QRect glRec = m_d.GetTheTopRect(/*glCurser*/newglcurser);
    QPoint frameRectTopLeft = mapFromGlobal(glRec.topLeft());
    ret = QRect(frameRectTopLeft.x(),frameRectTopLeft.y(),glRec.width(),glRec.height()); // 变成窗口矩阵
    return ret;
}

void FullScreenWidget::drawHoverWindowPixmap(void)
{
    QRect rec = GetCursorInRect();
	int nRatio = this->devicePixelRatio();

    static QRect sLastRec;
    if (rec != sLastRec)
    {
        sLastRec = rec;
		sLastRec.setTopLeft(QPoint(sLastRec.x() / nRatio, sLastRec.y() / nRatio));
		if (nRatio != 1)
		{
			sLastRec.setWidth((sLastRec.width() - sLastRec.x()) / nRatio);
			sLastRec.setHeight((sLastRec.height() - sLastRec.y()) / nRatio);
		}
        m_selectedRect = rec;
        beginPoint = rec.topLeft();
        m_endPoint = rec.bottomRight();
		
    }
	mInitBeginRect = rec.topLeft();
	mInitEndRect = rec.bottomRight();
	//重置一下sLastRect
	QRect rectnew = rec;


    painter.drawRect(sLastRec); //画选中的矩形框
    shotPixmap = loadPixmap.copy(rectnew/*sLastRec*/);  //更新选区的Pixmap

    // shotpixmap是截取的 slastrec 在 loadpixmap所在的区域中的片区，如果lastrec有超出loadpixmap的部分不会被截取
    //　所以在还原的时候，需要重新计算ｌａｓｔｒｅｃ的值
    QRect shotRect = m_DesktopRect & sLastRec;
	if (shotRect.width() == 0)
	{
		shotRect = sLastRec;
	}


    if(sLastRec.width() > 0 && sLastRec.height()){
		
        painter.drawPixmap(shotRect.topLeft(),shotPixmap); //画选中区域的图片
    }

    QPen pen;
    QBrush bush(s_main_qcolor);
    painter.setPen(QPen(bush,3,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
    painter.drawRect(shotRect);
}


void FullScreenWidget::drawSelectedPixmap(void)
{
//    painter.drawRect(m_selectedRect); //画选中的矩形框
//     shotPixmap = loadPixmap.copy(m_selectedRect);  //更新选区的Pixmap
//     if(m_selectedRect.width() > 0 && m_selectedRect.height()){
//         painter.drawPixmap(m_selectedRect.topLeft(),shotPixmap); //画选中区域的图片
//     }
//     draw8ControlPoint(m_selectedRect); //画出选区的8个控制点

	int nRatio = this->devicePixelRatio();
	QRect rectdraw = m_selectedRect;
	rectdraw.setTopLeft(QPoint(rectdraw.x() / nRatio, rectdraw.y() / nRatio));
	if (nRatio != 1)
	{
		rectdraw.setWidth((rectdraw.width() - rectdraw.x()) / nRatio);
		rectdraw.setHeight((rectdraw.height() - rectdraw.y()) / nRatio);
	}
	


	painter.drawRect(rectdraw); //画选中的矩形框
	shotPixmap = loadPixmap.copy(m_selectedRect);  //更新选区的Pixmap

	if (/*m_selectedRect.width()*/ rectdraw.width() > 0 && rectdraw.height()/*m_selectedRect.height()*/) {
		QPoint pt;
		pt = rectdraw.topLeft();
		painter.drawPixmap(/*m_selectedRect.topLeft()*/rectdraw.topLeft(), shotPixmap); //画选中区域的图片
	}
// 
 	draw8ControlPoint(/*m_selectedRect*/rectdraw); //画出选区的8个控制点
}

void FullScreenWidget::drawXYWHInfo(void)
{
    int x,y;
    QColor color = QColor(38,38,38,200);//设置颜色为灰黑色
    QRect rect;
    QString strTipsText;
    switch(currentShotState){
    case beginSelectShot:
    case goingSelectShot:
    case finishSelectShot:
    case beginMoveShot:
    case finishMoveShot:
    case beginControl:
    case finishControl:
    case lbclick:
	{
		int mx = m_toolbarrect.left();
		int my = m_toolbarrect.top();
		
		
		int nRatio = this->devicePixelRatio();
		x = m_selectedRect.x() / nRatio;
		y = m_selectedRect.y() / nRatio > (infoHeight + 5) ? (m_selectedRect.y() / nRatio - infoHeight - 3) : m_selectedRect.y() / nRatio + 3;
		rect = QRect(x, y, infoWidth, infoHeight);
		//判断一下toolbar和大小信息框的
		if (m_toolbarrect.contains(rect))
		{
			int mx = m_toolbarrect.left();
			int my = m_toolbarrect.top();
			rect = QRect(x, m_toolbarrect.top() - infoHeight - 3, infoWidth,infoHeight);
		}
		strTipsText = QStringLiteral(" 区域:%1 x %2 \n ESC 取消截图\n 鼠标双击完成截图").arg(m_selectedRect.width(), 4).arg(m_selectedRect.height());
		painter.fillRect(rect, color);
        QFont font;
        font.setPixelSize(12);
        painter.setFont(font);
		painter.setPen(QPen(Qt::white));//设置画笔的颜色为白色
		painter.drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, strTipsText);
		break;
	}
		
    default:
        break;
    }
}



void FullScreenWidget::Start()
{
    m_d.InitWndRectInfos();
    loadBackgroundPixmap();
	//loadBackgroundCursorPixmap();
    showNormal();
    activateWindow();
	
}

/*
 *	鼠标停留的信息预览框
 */
void FullScreenWidget::drawShotPictureInfo(void)
{
    QPoint glCurser = QCursor::pos(); //当前屏幕坐标
    QPoint frameCurser = mapFromGlobal(glCurser); // 屏幕坐标转换成窗口坐标
    QColor color = loadImage.pixel(frameCurser); //  光标所在位置色彩信息
    QString pos = QStringLiteral("位置: %1,%2").arg(glCurser.x()).arg(glCurser.y());
    QString size = QStringLiteral("大小: %3 x %4").arg(m_selectedRect.width()).arg(m_selectedRect.height());
    QString colorval = QStringLiteral("颜色: (%1,%2,%3)").arg(color.red()).arg(color.blue()).arg(color.green());

    // 画图片区域边框双边框 外层黑边1px，次外层白边2px

    // 信息框的大小是122*125像素，做屏幕边缘自适应。据鼠标位置的上、下、左、右15像素。边缘感知10像素
    int wholeRectX = frameCurser.x()+147>screenwidth/this->devicePixelRatio() ? frameCurser.x()-137 : frameCurser.x()+15;
    int wholeRextY = frameCurser.y()+145>screenheight/this->devicePixelRatio() ? frameCurser.y()-135 : frameCurser.y()+15;

    QRect rec1stBorder(wholeRectX,wholeRextY,121,81);  // 最外层一个1像素黑边
    QRect rec2ndBorder(rec1stBorder.x()+2,rec1stBorder.y()+2,118,78); // 次外层2像素白边
    QRect rec3rdFill(rec1stBorder.x(),rec1stBorder.y()+82,122,43);  // 信息面板

    painter.setPen(QPen(QBrush(QColor(0,0,0)),1,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
    painter.drawRect(rec1stBorder); //外圈
    painter.setPen(QPen(QBrush(QColor(255,255,255)),2,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin)); 
    painter.drawRect(rec2ndBorder); //内圈

    QFont font;
    font.setPixelSize(12);
    painter.setFont(font);

    painter.fillRect(rec3rdFill,QColor(0,0,0)); // 位置，大小，颜色区域
    painter.drawText(rec1stBorder.x()+6,rec1stBorder.y()+96,pos);
    painter.drawText(rec1stBorder.x()+6,rec1stBorder.y()+108,size);
    painter.drawText(rec1stBorder.x()+6,rec1stBorder.y()+120,colorval);



    // 最头疼的画图来了
    QRect cacheRect(frameCurser.x(),frameCurser.y(),29,19);  // 框内的图像缩小四倍
    QPixmap cacheFragment = catchPixmap.copy(cacheRect);
    QImage scaleFragment = cacheFragment.toImage().scaled(116,76,Qt::KeepAspectRatio);
    painter.drawImage(rec2ndBorder.x()+1,rec2ndBorder.y()+1,scaleFragment);

    // 画对焦十字
    painter.setPen(QPen(QBrush(QColor(0,255,0,100)),4,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin));
    painter.drawLine(QPoint(rec2ndBorder.x()+1,rec2ndBorder.y()+39),QPoint(rec2ndBorder.x()+117,rec2ndBorder.y()+39));
    painter.drawLine(QPoint(rec2ndBorder.x()+59,rec2ndBorder.y()+1),QPoint(rec2ndBorder.x()+59,rec2ndBorder.y()+77));
}

void FullScreenWidget::timerEvent(QTimerEvent *)
{
}

void FullScreenWidget::contextMenuEvent(QContextMenuEvent *event)
{
    // 不能进行重载了,不区分焦点的位置。
}

void FullScreenWidget::showPictureEditContextMenu(const QPoint& pos)
{
    // need reload
}

void FullScreenWidget::showPictureEditBar(const QRect& rec)
{
    // need reload
}

void FullScreenWidget::finishPixmap(const QPixmap& finishPixmap)
{
	
}

QPixmap& FullScreenWidget::selectPixmap()
{
    return shotPixmap;
}
QPainter* FullScreenWidget::getPainter()
{
    return &painter;
}

void FullScreenWidget::LockSelectRange()
{
    currentShotState = lockSelect;
    updateMouseShape(QPoint());
}



bool FullScreenWidget::JietuFinshed( QMouseEvent * event )
{
	QRect rec = getSelectedRect();
	if (rec.contains(event->pos()))
	{
		return true;
	}
	return false;
}


bool FullScreenWidget::JietuCancel( QMouseEvent * event )
{
	QRect rec = getSelectedRect();
	if (rec.contains(event->pos()))
	{
		return true;
	}
	return false;
}
