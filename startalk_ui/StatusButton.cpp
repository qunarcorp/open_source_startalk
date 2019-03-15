#include "StatusButton.h"
#include <QPainter>

StatusButton::StatusButton(QWidget *parent)
    : QAbstractButton(parent),mMessageCount(0), mEnableImage(NULL), mDisableImage(NULL)
{
    mTip = QImage(":/Images/tipsIcon.png");
    mHover = false;
    //setCheckable(true);
}

StatusButton::~StatusButton()
{

}

void StatusButton::paintEvent( QPaintEvent * pe)
{
    QColor unreadColor(Qt::GlobalColor::white);
    QColor selectedColor(QColor(27, 169, 186));
    QColor unselectedColor(QColor(177, 177, 177));

    QPainter painter;
    painter.begin(this);
    //painter.setRenderHint(QPaint)
    auto geom = this->geometry();

    // mod by wangzheng 14/8/22 for 更换图标大小由32变为30
    auto imageWidth = 30;  
    auto imageHeight = 30;
    // mod end
    {
        // 画图
        auto rect = QRect((geom.width() - imageWidth) / 2, 0, imageWidth, imageHeight); 
        if( /*mHover 取消了hover效果*/ 0)
            painter.drawImage(rect, mHoverImage);
        else 
            painter.drawImage(rect, isChecked() ? mEnableImage:mDisableImage);
    }
    {
        auto rect = QRect(0, imageHeight + 2, geom.width(), 12); 
        // 画文本
        QFont font;
        painter.setPen(isChecked() ? selectedColor : unselectedColor);
        painter.drawText(rect, Qt::AlignCenter, text());
    }
    if(mMessageCount > 0)
    {
        int unread = 0;
        if(mMessageCount > 99){
            unread = 99;
        }else{
            unread = mMessageCount;
        }
        auto rect = QRect((geom.width() - 2) / 2, 0, 17, 17); 
        // 画未读消息
        painter.drawImage(rect, mTip);
        QFont font;
        //font.setFamily("Arial");
        font.setPixelSize(12);
        painter.setPen(unreadColor);
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, QString("%1").arg(unread));
    }

        //auto a = text();

        //if(mMessageCount > 0){

        //    rect.setWidth(16);
        //    rect.setHeight(16);
        //    painter.setPen(QColor(Qt::GlobalColor::transparent));
        //    painter.setBrush(QBrush(unreadBg));
        //    painter.drawEllipse(0, 0, 8, 8);
        //    auto unread = mMessageCount;
        //    if(unread > 99){
        //        unread = 99;
        //    }
        //    QFont font;
        //    font.setFamily("Arial");
        //    font.setPixelSize(10);
        //    painter.setFont(font);
        //    painter.setPen(unreadColor);
        //    auto unreadStr = QRect(0, 0, 16, 16 );
        //    painter.drawText(unreadStr, Qt::AlignCenter, QString("%1").arg(unread));
        //}

        // 画未读消息

    painter.end();
}

void StatusButton::enablePixmap( const QString& val )
{
    mEnableImage = QImage(val);
}

void StatusButton::disablePixmap( const QString& val )
{
    mDisableImage = QImage(val);
}
void StatusButton::hoverPixmap(const QString& val)
{
    mHoverImage = QImage(val);
}
void StatusButton::onMessageCountChanged( int val )
{
    if(val == mMessageCount)
        return;

    mMessageCount = val;
    this->update();
}
void StatusButton::enterEvent(QEvent * event)
{
    mHover = true;   
}
void StatusButton::leaveEvent(QEvent * event)
{
    mHover = false;
}