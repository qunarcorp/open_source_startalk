#ifndef MARKUSERINFOWIDGET_H
#define MARKUSERINFOWIDGET_H

#include <QWidget>
#include "localmanwidget.h"
#include "UtilHelper.h"

namespace Ui{
    class MarkUserInfoWidget;
}
class MarkUserInfoWidget : public LocalManWidget
{
    Q_OBJECT

public:
    MarkUserInfoWidget(QWidget *parent = 0);
    ~MarkUserInfoWidget();
public:
    void setData(const QString& conversationId);
protected:
    virtual void closeEvent(QCloseEvent *);
private:
    Ui::MarkUserInfoWidget* ui;
    
};

typedef Util::SingletonTemplete<MarkUserInfoWidget> MarkUserInfoWidgetSingleton;

#endif // MARKUSERINFOWIDGET_H
