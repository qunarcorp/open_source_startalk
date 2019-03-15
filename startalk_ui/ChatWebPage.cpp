#include "ChatWebPage.h"
#include "Session.h"
#include "SettingData.h"
#include "gloableeventobject.h"
#include "ChatDisplayOptionWidget.h"

#include "UIFrame.h"
#include "ChatBubbleController.h"
#include "UiHelper.h"
ChatWebPage::ChatWebPage(QObject *parent)
    : WebPage(parent)
{

    connect(MainApp::UIFrame::getChatBubbleController(),&MainApp::ChatBubbleController::sgChatBubbleQssChanged,this,&ChatWebPage::onCssChange);

    connect(this,&WebPage::loadFinished,this,&ChatWebPage::onLoadFinished);
    connect(ChatDisplayOptionWidgetSingleton::getInstance(),&ChatDisplayOptionWidget::sgSelfFontChange,this,&ChatWebPage::onSelfFontChange);
    connect(ChatDisplayOptionWidgetSingleton::getInstance(),&ChatDisplayOptionWidget::sgOtherFontChange,this,&ChatWebPage::onOtherFontChange);
}

ChatWebPage::~ChatWebPage()
{
}

void ChatWebPage::onCssChange(const QString& cssPath)
{
    QString str = QString("addStyle('%1')").arg(QUrl::fromLocalFile(cssPath).toString());
    runLocalJavaScript(str);
}

void ChatWebPage::onLoadFinished(bool ok)
{
    onSelfFontChange();
    onOtherFontChange();
	onSelfmsgStatusFont();
    MainApp::UIFrame::getChatBubbleController()->updateSelfDefault(Biz::Session::getSettingConfig()->SelfBubbleColor2(),Biz::Session::getSettingConfig()->SelfBubbleColorAlpha());
    MainApp::UIFrame::getChatBubbleController()->updateOtherDefault(Biz::Session::getSettingConfig()->OtherBubbleColor2(),Biz::Session::getSettingConfig()->OtherBubbleColorAlpha());
}

void ChatWebPage::onSelfFontChange()
{
    // 加载基本样式
    QString argFontFamily   = Biz::Session::getSettingConfig()->MFontFamily();
    int fontsize            = Biz::Session::getSettingConfig()->MFontSize();
    QColor color            = MainApp::intToQColor(Biz::Session::getSettingConfig()->TextColorRGB());
    QString argFontColor    = color.name();

    QString jsCommend = QString("setSelfFont('%1',%2,'%3')").arg(argFontFamily)
        .arg(fontsize)
        .arg(argFontColor);

    runLocalJavaScript(jsCommend);
    //发送改变字体信号
    if (Biz::Session::getSettingConfig()->SetFontSize())
    {
        emit GloableEventObject::getInstance()->sgFontSizeChange(fontsize);
    }
}

void ChatWebPage::onOtherFontChange()
{
    // 加载基本样式
    QString argFontFamily   = Biz::Session::getSettingConfig()->MFontFamily();
    int fontsize            = Biz::Session::getSettingConfig()->MFontSize();
    QColor color            = MainApp::intToQColor(Biz::Session::getSettingConfig()->TextColorRGBOther());

    QString argFontColor    = color.name();

    QString jsCommend = QString("setOtherFont('%1',%2,'%3')").arg(argFontFamily)
        .arg(fontsize)
        .arg(argFontColor);

    runLocalJavaScript(jsCommend);
    //发送改变字体信号
    if (Biz::Session::getSettingConfig()->SetFontSize())
    {
        emit GloableEventObject::getInstance()->sgFontSizeChange(fontsize);
    }
}

void ChatWebPage::onSelfmsgStatusFont()
{
	QString argFontFamily   = Biz::Session::getSettingConfig()->MFontFamily();
	

	QString jsCommend = QString("setStatusfontfamy('%1');").arg(argFontFamily);

	runLocalJavaScript(jsCommend);
}
