#include "snipscreemtoolbar.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>


SnipScreemToolBar::SnipScreemToolBar(QWidget *parent)
    : QWidget(parent)
{
    m_nDirect = 0;

    ui.setupUi(this);

    m_lstColorValue.push_back("#000000");
    m_lstColorValue.push_back("#808080");
    m_lstColorValue.push_back("#800000");
    m_lstColorValue.push_back("#F7883A");
    m_lstColorValue.push_back("#308430");
    m_lstColorValue.push_back("#385AD3");
    m_lstColorValue.push_back("#800080");
    m_lstColorValue.push_back("#009999");

    m_lstColorValue.push_back("#FFFFFF");
    m_lstColorValue.push_back("#C0C0C0");
    m_lstColorValue.push_back("#FF0000");
    m_lstColorValue.push_back("#FFFF00");
    m_lstColorValue.push_back("#99cc00");
    m_lstColorValue.push_back("#3894E4");
    m_lstColorValue.push_back("#F31BF3");
    m_lstColorValue.push_back("#16DCDC");

    m_lstPenSizeValue.push_back(2);
    m_lstPenSizeValue.push_back(4);
    m_lstPenSizeValue.push_back(8);

    m_nCurPensize = m_lstPenSizeValue.at(0);
    m_strCurColor = m_lstColorValue.at(10);
    

    connect(ui.tool_rec,&QPushButton::clicked,this,&SnipScreemToolBar::onEditToolSelected);
    connect(ui.tool_ring,&QPushButton::clicked,this,&SnipScreemToolBar::onEditToolSelected);
    connect(ui.tool_pen,&QPushButton::clicked,this,&SnipScreemToolBar::onEditToolSelected);
    connect(ui.tool_text,&QPushButton::clicked,this,&SnipScreemToolBar::onEditToolSelected);
    connect(ui.tool_arrow,&QPushButton::clicked,this,&SnipScreemToolBar::onEditToolSelected);

    connect(ui.tool_select,&QPushButton::clicked,[this](bool b){
        emit sgOk();
		QString str = "sgOK";
		str = "success";
    }
    );

    connect(ui.tool_cancle,&QPushButton::clicked,[this](bool b){
        emit sgCancle();
    }
    );

    connect(ui.tool_undo,&QPushButton::clicked,[this](bool b){
        emit sgUndo();
    }
    );
    //ui.tool_undo->setVisible(false);

    // 笔触大小按钮设置监听
    m_lstDownPenSize.push_back(ui.point_down_rect_2);
    m_lstDownPenSize.push_back(ui.point_down_rect_4);
    m_lstDownPenSize.push_back(ui.point_down_rect_8);
    m_lstUpPenSize.push_back(ui.point_up_rect_2);
    m_lstUpPenSize.push_back(ui.point_up_rect_4);
    m_lstUpPenSize.push_back(ui.point_up_rect_8);
    
    foreach(QWidget* w,m_lstDownPenSize){
        w->installEventFilter(this);
    }
    foreach(QWidget* w,m_lstUpPenSize){
        w->installEventFilter(this);
    }

    // 默认选择2笔触
    onPenSizeChanged(ui.point_down_rect_2);

    // 颜色按钮
    m_lstDownColorRect.push_back(ui.color_down_f0);
    m_lstDownColorRect.push_back(ui.color_down_f1);
    m_lstDownColorRect.push_back(ui.color_down_f2);
    m_lstDownColorRect.push_back(ui.color_down_f3);
    m_lstDownColorRect.push_back(ui.color_down_f4);
    m_lstDownColorRect.push_back(ui.color_down_f5);
    m_lstDownColorRect.push_back(ui.color_down_f6);
    m_lstDownColorRect.push_back(ui.color_down_f7);
    m_lstDownColorRect.push_back(ui.color_down_f0_2);
    m_lstDownColorRect.push_back(ui.color_down_f1_2);
    m_lstDownColorRect.push_back(ui.color_down_f2_2);
    m_lstDownColorRect.push_back(ui.color_down_f3_2);
    m_lstDownColorRect.push_back(ui.color_down_f4_2);
    m_lstDownColorRect.push_back(ui.color_down_f5_2);
    m_lstDownColorRect.push_back(ui.color_down_f6_2);
    m_lstDownColorRect.push_back(ui.color_down_f7_2);
    m_lstDownColor.push_back(ui.color_down_c0);
    m_lstDownColor.push_back(ui.color_down_c1);
    m_lstDownColor.push_back(ui.color_down_c2);
    m_lstDownColor.push_back(ui.color_down_c3);
    m_lstDownColor.push_back(ui.color_down_c4);
    m_lstDownColor.push_back(ui.color_down_c5);
    m_lstDownColor.push_back(ui.color_down_c6);
    m_lstDownColor.push_back(ui.color_down_c7);
    m_lstDownColor.push_back(ui.color_down_c0_2);
    m_lstDownColor.push_back(ui.color_down_c1_2);
    m_lstDownColor.push_back(ui.color_down_c2_2);
    m_lstDownColor.push_back(ui.color_down_c3_2);
    m_lstDownColor.push_back(ui.color_down_c4_2);
    m_lstDownColor.push_back(ui.color_down_c5_2);
    m_lstDownColor.push_back(ui.color_down_c6_2);
    m_lstDownColor.push_back(ui.color_down_c7_2);

    m_lstUpColorRect.push_back(ui.color_up_f0);
    m_lstUpColorRect.push_back(ui.color_up_f1);
    m_lstUpColorRect.push_back(ui.color_up_f2);
    m_lstUpColorRect.push_back(ui.color_up_f3);
    m_lstUpColorRect.push_back(ui.color_up_f4);
    m_lstUpColorRect.push_back(ui.color_up_f5);
    m_lstUpColorRect.push_back(ui.color_up_f6);
    m_lstUpColorRect.push_back(ui.color_up_f7);
    m_lstUpColorRect.push_back(ui.color_up_f0_2);
    m_lstUpColorRect.push_back(ui.color_up_f1_2);
    m_lstUpColorRect.push_back(ui.color_up_f2_2);
    m_lstUpColorRect.push_back(ui.color_up_f3_2);
    m_lstUpColorRect.push_back(ui.color_up_f4_2);
    m_lstUpColorRect.push_back(ui.color_up_f5_2);
    m_lstUpColorRect.push_back(ui.color_up_f6_2);
    m_lstUpColorRect.push_back(ui.color_up_f7_2);
    m_lstUpColor.push_back(ui.color_up_c0);
    m_lstUpColor.push_back(ui.color_up_c1);
    m_lstUpColor.push_back(ui.color_up_c2);
    m_lstUpColor.push_back(ui.color_up_c3);
    m_lstUpColor.push_back(ui.color_up_c4);
    m_lstUpColor.push_back(ui.color_up_c5);
    m_lstUpColor.push_back(ui.color_up_c6);
    m_lstUpColor.push_back(ui.color_up_c7);
    m_lstUpColor.push_back(ui.color_up_c0_2);
    m_lstUpColor.push_back(ui.color_up_c1_2);
    m_lstUpColor.push_back(ui.color_up_c2_2);
    m_lstUpColor.push_back(ui.color_up_c3_2);
    m_lstUpColor.push_back(ui.color_up_c4_2);
    m_lstUpColor.push_back(ui.color_up_c5_2);
    m_lstUpColor.push_back(ui.color_up_c6_2);
    m_lstUpColor.push_back(ui.color_up_c7_2);

    foreach(QWidget* w,m_lstDownColorRect){
        w->installEventFilter(this);
    }
    foreach(QWidget* w,m_lstUpColorRect){
        w->installEventFilter(this);
    }
}

SnipScreemToolBar::~SnipScreemToolBar()
{

}
//////////////////////////////////////////////////////////////////////////
// 主工具条距离屏幕下缘不足以放下下部子工具条，那么需要做工具条翻转，如果能存下就不需要了
// 
void SnipScreemToolBar::showSubToolBar()
{
    ui.extbar_down->setVisible(!m_nDirect==0);
    ui.extbar_up->setVisible(m_nDirect==0);


}


void SnipScreemToolBar::initToolBar()
{
    emit sgColorChange(m_strCurColor);
    emit sgPenSizeChange(m_nCurPensize);
    //emit sgToolSelect(m_tyCurrentType);
    ui.selected_color_down->setStyleSheet(QString("QLabel#selected_color_down{border:1px solid #00000000;background-color:%1;}").arg(m_strCurColor));
    ui.selected_color_up->setStyleSheet(QString("QLabel#selected_color_up{border:1px solid #00000000;background-color:%1;}").arg(m_strCurColor));

    ui.extbar_down->setVisible(false);
    ui.extbar_up->setVisible(false);

    ui.tool_rec->setChecked(false);
    ui.tool_ring->setChecked(false);
    ui.tool_pen->setChecked(false);
    ui.tool_text->setChecked(false);
    ui.tool_arrow->setChecked(false);

}


void SnipScreemToolBar::onEditToolSelected(bool checked)
{
    ui.tool_rec->setChecked(ui.tool_rec==sender() && checked);
    ui.tool_ring->setChecked(ui.tool_ring==sender() && checked);
    ui.tool_pen->setChecked(ui.tool_pen==sender() && checked);
    ui.tool_text->setChecked(ui.tool_text==sender() && checked);
    ui.tool_arrow->setChecked(ui.tool_arrow==sender() && checked);

    if (checked)
    {
        TOOLTYPE type = SNIP_TOOLBAR_NONE;
        type = (ui.tool_rec==sender()? SNIP_TOOLBAR_RECT : type);
        type = (ui.tool_ring==sender()? SNIP_TOOLBAR_RING : type);
        type = (ui.tool_pen==sender()? SNIP_TOOLBAR_PEN : type);
        type = (ui.tool_text==sender()? SNIP_TOOLBAR_TEXT : type);
        type = (ui.tool_arrow==sender()? SNIP_TOOLBAR_ARROW : type);
        emit sgToolSelect(type);
        m_tyCurrentType = type;
        showSubToolBar();
    }
    else
    {
        m_tyCurrentType = SNIP_TOOLBAR_NONE;
        emit sgToolSelect(SNIP_TOOLBAR_NONE);
        ui.extbar_down->setVisible(false);
        ui.extbar_up->setVisible(false);
    }

}

void SnipScreemToolBar::onPenSizeChanged(QWidget* pwidget)
{
    int nPenSize = 2;
    QString str = pwidget->objectName();

    if (m_lstDownPenSize.contains(pwidget))
    {
        foreach(QWidget* w,m_lstDownPenSize)
        {
            QWidget* pPartener = m_lstUpPenSize.at(m_lstDownPenSize.indexOf(w));
            setPenSizeStyle(w,w==pwidget);
            setPenSizeStyle(pPartener,w==pwidget);
        }

        nPenSize = m_lstPenSizeValue.at(m_lstDownPenSize.indexOf(pwidget));
    }
    if (m_lstUpPenSize.contains(pwidget))
    {
        foreach(QWidget* w,m_lstUpPenSize)
        {
            QWidget* pPartener = m_lstDownPenSize.at(m_lstUpPenSize.indexOf(w));
            setPenSizeStyle(pPartener,w==pwidget);
            setPenSizeStyle(w,w==pwidget);
        }
        nPenSize = m_lstPenSizeValue.at(m_lstUpPenSize.indexOf(pwidget));
    }

    if (m_nCurPensize!=nPenSize)
    {
        m_nCurPensize = nPenSize;
        emit sgPenSizeChange(nPenSize);
    }
}

void SnipScreemToolBar::onPenColorHovered(QWidget* pwidget,bool hovered)
{
    if (m_lstDownColorRect.contains(pwidget))
    {
        int index = m_lstDownColorRect.indexOf(pwidget);

        setPenColorStyle(
            pwidget,
            m_lstDownColor.at(index),
            m_lstColorValue.at(index),
            hovered);
        setPenColorStyle(
            m_lstUpColorRect.at(index),
            m_lstUpColor.at(index),
            m_lstColorValue.at(index),
            hovered);
    }
    if (m_lstUpColorRect.contains(pwidget))
    {
        int index = m_lstUpColorRect.indexOf(pwidget);
        setPenColorStyle(
            pwidget,
            m_lstUpColor.at(index),
            m_lstColorValue.at(index),
            hovered);
        setPenColorStyle(
            m_lstDownColorRect.at(index),
            m_lstDownColor.at(index),
            m_lstColorValue.at(index),
            hovered);
    }
}


void SnipScreemToolBar::onPenColorSelected(QWidget* pwidget)
{
    int index = 0;
    QString color = "";
    if (m_lstDownColorRect.contains(pwidget))
    {
         index = m_lstDownColorRect.indexOf(pwidget);
         color = m_lstColorValue.at(index);
    }
    if (m_lstUpColorRect.contains(pwidget))
    {
         index = m_lstUpColorRect.indexOf(pwidget);
         color = m_lstColorValue.at(index);
    }

    ui.selected_color_down->setStyleSheet(QString("QLabel#selected_color_down{border:1px solid #00000000;background-color:%1;}").arg(color));
    ui.selected_color_up->setStyleSheet(QString("QLabel#selected_color_up{border:1px solid #00000000;background-color:%1;}").arg(color));

    if (color.compare(m_strCurColor,Qt::CaseInsensitive)!=0)
    {
        m_strCurColor = color;
        emit sgColorChange(color);
    }
}


bool SnipScreemToolBar::eventFilter(QObject * obj, QEvent *event)
{
    if (QEvent::Type::MouseButtonPress == event->type())
    {
        event->accept();
        return true;
    }


    QString objName = obj->objectName();
    QEvent::Type ty = event->type();
    
    if (QEvent::Type::MouseButtonRelease == event->type())
    {
        QWidget* pwidget = (QWidget*)obj;
        if (m_lstDownPenSize.contains(pwidget)||m_lstUpPenSize.contains(pwidget))
        {
            onPenSizeChanged(pwidget);
            event->ignore();
            return true;
        }

        if (m_lstDownColorRect.contains(pwidget)||m_lstUpColorRect.contains(pwidget))
        {
            onPenColorSelected(pwidget);
            event->ignore();
            return true;
        }

    }

    if (QEvent::Type::Enter == event->type())
    {
        QWidget* pwidget = (QWidget*)obj;
        if (m_lstDownColorRect.contains(pwidget)||m_lstUpColorRect.contains(pwidget))
        {
            onPenColorHovered(pwidget,true);
            return true;
        }
    }

    if (QEvent::Type::Leave == event->type())
    {
        QWidget* pwidget = (QWidget*)obj;
        if (m_lstDownColorRect.contains(pwidget)||m_lstUpColorRect.contains(pwidget))
        {
            onPenColorHovered(pwidget,false);
            return true;
        }
    }
   return QWidget::eventFilter(obj,event);
}

void SnipScreemToolBar::setPenSizeStyle(QWidget* pw,bool bselected)
{
    QString objName = pw->objectName();
    QString selectedTempleted = QString("QWidget#%1{border:1px solid #1BA9BA;}").arg(objName);
    QString normalTempleted = QString("QWidget#%1{border:none;}").arg(objName);
    pw->setStyleSheet(bselected?selectedTempleted:normalTempleted);
}


void SnipScreemToolBar::setPenColorStyle(QWidget* pRect,QLabel* pContent,QString contentColor,bool bSelected)
{
    if (pRect==NULL || NULL == pContent || contentColor.isEmpty())
    {
        return;
    }

    // 设置外框的颜色
    QString rectName = pRect->objectName();
    QString selectedTempleted = QString("QWidget#%1{border:1px solid #1BA9BA;background-color:#00000000;}").arg(rectName);
    QString normalTempleted = QString("QWidget#%1{border:1px solid #FEFEFE;background-color:#00000000;}").arg(rectName);
    pRect->setStyleSheet(bSelected?selectedTempleted:normalTempleted);

    // 设置里面内容的颜色
    rectName = pContent->objectName();
    selectedTempleted = QString("QLabel#%1{border:1px solid #FEFEFE;background-color:%2;}").arg(rectName).arg(contentColor);
    normalTempleted = QString("QLabel#%1{border:1px solid %2;background-color:%2;}").arg(rectName).arg(contentColor);
    pContent->setStyleSheet(bSelected?selectedTempleted:normalTempleted);
}

void SnipScreemToolBar::enterEvent(QEvent *)
{
    setCursor(Qt::ArrowCursor);
}

int SnipScreemToolBar::getHeight()
{
    int height = 0;
    if (ui.basebar->isVisible())
    {
        height += ui.basebar->height();
    }

    if (ui.extbar_down->isVisible())
    {
        height += ui.extbar_down->height();
    }
    if (ui.extbar_up->isVisible())
    {
        height += ui.extbar_up->height();
    }
    return height;
}


