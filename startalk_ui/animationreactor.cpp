#include "animationreactor.h"
#include <QGraphicsOpacityEffect>
#include <QDesktopWidget>
#include <QApplication>

AnimationReactor::AnimationReactor()
    : QObject(NULL)
{

}

AnimationReactor::~AnimationReactor()
{

}

void AnimationReactor::opacityInWidget(QWidget* pWidget,quint64 animationDuration)
{
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect(pWidget);
    pWidget->setGraphicsEffect (opacity);
    opacity->setOpacity (1);
    QPropertyAnimation* animation = new QPropertyAnimation(opacity,"opacity",opacity);
    animation->setStartValue (0);
    animation->setEndValue (1);
    animation->setDuration (animationDuration);
    animation->setEasingCurve (QEasingCurve::Linear);
    animation->start (QAbstractAnimation::DeleteWhenStopped);
}

void AnimationReactor::opacityOutWidget(QWidget* pWidget,quint64 animationDuration)
{
    opacityOutWidget(pWidget,animationDuration,[]{});
}

void AnimationReactor::opacityOutWidget(QWidget* pWidget,quint64 animationDuration,std::function<void()> finishcb)
{
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect(pWidget);
    pWidget->setGraphicsEffect (opacity);
    opacity->setOpacity (1);
    QPropertyAnimation* animation = new QPropertyAnimation(opacity,"opacity",opacity);
    animation->setStartValue (1);
    animation->setEndValue (0);
    animation->setDuration (animationDuration);
    animation->setEasingCurve (QEasingCurve::Linear);

    connect (animation,&QPropertyAnimation::finished,finishcb);

    animation->start (QAbstractAnimation::DeleteWhenStopped);
}

void AnimationReactor::popupWidget(QWidget* pWidget)
{
    // 在鼠标所在得屏幕的工作区弹出窗口
    QDesktopWidget* pDesktop = QApplication::desktop ();
    QRect availabeGeometry  = pDesktop->availableGeometry (QCursor::pos ());
    QRect screenGeometry    = pDesktop->screenGeometry (QCursor::pos ());

    QPoint startPos;
    QPoint endPos;

    if (availabeGeometry.height () == screenGeometry.height ())
    {
        // 左右结构
        if (availabeGeometry.left () == screenGeometry.left ())
        {
            startPos.setX (availabeGeometry.right ()-pWidget->width ());
            endPos.setX (availabeGeometry.right ()-pWidget->width ());

            startPos.setY (screenGeometry.bottom ());
            endPos.setY (screenGeometry.bottom ()-pWidget->height ());
        }
        else
        {
            startPos.setX (availabeGeometry.left ());
            endPos.setX (availabeGeometry.left ());
            startPos.setY (screenGeometry.bottom ());
            endPos.setY (screenGeometry.bottom ()-pWidget->height ());
        }
    }
    else
    {
        // 上下结构
        if (availabeGeometry.top () == screenGeometry.top ())
        {
            // 从下向上生长
            startPos.setX (screenGeometry.right ()-pWidget->width ());
            endPos.setX (screenGeometry.right ()-pWidget->width ());
            startPos.setY (screenGeometry.bottom ());
            endPos.setY (availabeGeometry.bottom ()-pWidget->height ());
        }
        else
        {
            // 由上向上生长
            startPos.setX (screenGeometry.right ()-pWidget->width ());
            endPos.setX (screenGeometry.right ()-pWidget->width ());
            startPos.setY (screenGeometry.top ()-pWidget->height ());
            endPos.setY (availabeGeometry.top ());
        }
    }

    pWidget->raise ();
    pWidget->show ();

    QPropertyAnimation* animation=new QPropertyAnimation(pWidget,"pos");
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->setDuration(300);
    pWidget->move (startPos);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->start(QAbstractAnimation::DeletionPolicy::DeleteWhenStopped);
}
