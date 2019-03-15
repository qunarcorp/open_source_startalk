#ifndef CHATDISPLAYOPTIONWIDGET_H
#define CHATDISPLAYOPTIONWIDGET_H

#include <QWidget>
#include "ui_ChatDisplayOptionWidget.h"
#include "UtilHelper.h"
#include "localmanwidget.h"
class ChatDisplayOptionWidget : public LocalManWidget
{
    Q_OBJECT

public:
    ChatDisplayOptionWidget(QWidget *parent = 0);
    ~ChatDisplayOptionWidget();
public:
    void reShow();
private:
    Ui::ChatDisplayOptionWidget ui;
signals:
    void sgSelfFontChange();
    void sgOtherFontChange();
    void sgSelfBubbleColorChange(int color);
    void sgOtherBubbleColorChange(int color);
    public slots:
        void onCurrentFontChanged(const QFont &f);
        void onCurrentTextChanged(const QString &);
        void onColorSelectBtnClicked(bool);
};

typedef Util::SingletonTemplete<ChatDisplayOptionWidget> ChatDisplayOptionWidgetSingleton; 

#endif // CHATDISPLAYOPTIONWIDGET_H
