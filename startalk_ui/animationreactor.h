#pragma  once
#include <QObject>
#include <QWidget>
#include <functional>
#include "UtilHelper.h"

class AnimationReactor : public QObject
{
    friend Util::SingletonTemplete<AnimationReactor>;
public:
    void opacityInWidget    (QWidget* pWidget,quint64 animationDuration);
    void opacityOutWidget   (QWidget* pWidget,quint64 animationDuration);
    void opacityOutWidget   (QWidget* pWidget,quint64 animationDuration,std::function<void()> finishcb);

    void popupWidget(QWidget* pWidget);

private:
    AnimationReactor();
    ~AnimationReactor();
};

typedef Util::SingletonTemplete<AnimationReactor> AnimationReactorSingleton;