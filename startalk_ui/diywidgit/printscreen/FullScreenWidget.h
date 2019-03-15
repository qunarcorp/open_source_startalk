#ifndef FULLSCREENWIDGET_H
#define FULLSCREENWIDGET_H
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include "FullScreenPrivate.h"

// 功能列表
//     1 抓取全屏图片
//     2 鼠标hover时候识别窗口rect的提取
//     3 实时显示光标坐标、所在选窗口大小、提取光标位置的颜色
//     4 鼠标拖选选择窗口截图
//     5 双击选中窗口，获得所截取的部分区域图
//     6 支持显示右键菜单和功能条（需要子类实现）
//     7 只提供所截取图片的数据，如果需要保存子类实现。

// 接口列表
//     1 Start() 启动截屏窗口
//     2 showPictureEditContextMenu() 显示目录
//     3 showPictureEditBar() 显示工具条
//     4 finishPixmap() 截取完成
//     5 selectPixmap() 获取选中的pixmap



class FullScreenWidget : public QWidget{

	Q_OBJECT

public:
	FullScreenWidget(); //构造函数
    virtual ~FullScreenWidget();
	void Start();

    QPixmap& selectPixmap();
    QPainter* getPainter();


    // 子类根据需要进行重载的方法
    virtual void showPictureEditContextMenu(const QPoint& pos);
    virtual void showPictureEditBar(const QRect& rec);
    virtual void finishPixmap(const QPixmap& finishPixmap);
	bool JietuFinshed(QMouseEvent * event);
	bool JietuCancel(QMouseEvent * event);
protected:
    QRect getSelectedRect(); //获取选取
	QRect getRelativeSelectedRect(); //获取相对屏幕的Rect;
private:
    //进行截屏的状态
    enum shotState{initShot,beginSelectShot,goingSelectShot,finishSelectShot,lbclick,endShot,beginMoveShot,finishMoveShot,beginControl,finishControl,lockSelect};
    //移动选区中的8个控制点，按照顺时针方向从左上控制点到左中控制点分配编号为1～8
    enum controlPointEnum{moveControl0,moveControl1,moveControl2,moveControl3,moveControl4,moveControl5,moveControl6,moveControl7,moveControl8};

protected:
	void loadBackgroundPixmap();
	void loadBackgroundCursorPixmap();
    void cancelSelectedRect(bool checked = false); //取消选择区域
    void loadBackgroundPixmap(const QPixmap &bgPixmap, int x, int y, int width, int height); //加载背景pixmap槽函数，设置x,y,width,height
    QPixmap getFullScreenPixmap(); //获取全屏的Pixmap

	
	QRect getRect(const QPoint &beginPoint, const QPoint &endPoint); //根据两个点获取选取坐标
	void initFullScreenWidget(); //初始化抓全屏的相关参数
	bool isInSelectedRect(const QPoint &point); //判断该点是否在选中区域
	//void initSelectedMenu();//初始化右键菜单

    // 画图
	void drawTipsText(); //在屏幕上打印提示信息
	virtual void drawSelectedPixmap(void); //在屏幕上画选取的屏幕
    void drawHoverWindowPixmap(void);
    void drawXYWHInfo(void); //打印选取的x,y,h,w值信息
    void draw8ControlPoint(const QRect &rect); // 画8个控制点位
    void drawShotPictureInfo(void); // 画图片信息

	void updateBeginEndPointValue(const QRect &rect);  //当移动选取后，对beginPoint,endPoint坐标进行重新修改
	void checkMoveEndPoint(); //对移动的选区进行判断
	void updateMouseShape(const QPoint &point); //更新鼠标的当前状态
	void updateMoveControlMouseShape(controlPointEnum controlValue);
	controlPointEnum getMoveControlState(const QPoint &point); //获取移动控制点状态
	QRect getMoveAllSelectedRect(void); //获取移动整个选中的选区
	QRect getMoveControlSelectedRect(void);//获取移动控制点的选区
	int getMinValue(int num1, int num2);//获取两个数中的最小值
    QRect GetCursorInRect();
    void LockSelectRange();
    void reset();
protected:
	//重写基类方法
	void keyPressEvent(QKeyEvent *event);
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);  
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void timerEvent(QTimerEvent *);

    void contextMenuEvent(QContextMenuEvent *event);
	QRect m_toolbarrect;
private:
    FullScreenPrivate m_d;
    // 桌面大小
    QRect m_DesktopRect;

    //选区框的8个点选取
    QRect tlRect; //左上点
    QRect trRect; //右上点
    QRect blRect; //左下点
    QRect brRect; //右下点
    QRect tcRect; //上中点
    QRect bcRect; //下中点
    QRect lcRect;//左中点
    QRect rcRect; //右中点

    QPainter painter;
    QPoint beginPoint,m_endPoint,moveBeginPoint,moveEndPoint;
    QRect m_selectedRect; //选择区域
    QPixmap loadPixmap,shotPixmap;
    QPixmap catchPixmap; // 用于放大截取大图
    QImage loadImage; // 大原图，用于取色
    shotState currentShotState; //当前的截屏状态
    controlPointEnum controlValue; //记录移动控制点的值
    QAction *savePixmapAction; //保存图片行为
    QAction *cancelAction; //取消选取行为
    QAction *quitAction; //退出选取行为

    //QMenu *contextMenu; //选中区域右键菜单
    int screenwidth; //整个屏幕的宽度
    int screenheight; //整个屏幕的高度
    int screenx; //选区的X
    int screeny; //选区的Y
    int tipWidth,tipHeight,infoWidth,infoHeight,toolbarWidth,toolbarHeight; //加载初始框的宽度，高度；显示坐标信息的宽度，高度

    // 
    const static QColor s_main_qcolor;
    const static QColor s_qcolor_50trans;
    const static QColor s_black_60trans;
	QPoint mInitBeginRect, mInitEndRect;
};

#endif

