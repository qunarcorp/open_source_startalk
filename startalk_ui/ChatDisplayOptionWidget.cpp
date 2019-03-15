#include "ChatDisplayOptionWidget.h"
#include <QColorDialog>

#include "Session.h"
#include "UserSettingData.h"
#include "SettingData.h"

#include "UIFrame.h"
#include "ChatBubbleController.h"
#include "MainDialogController.h"
#include "UiHelper.h"

ChatDisplayOptionWidget::ChatDisplayOptionWidget(QWidget *parent)
    : LocalManWidget(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint /*| Popup*/;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
    this->setSizeGripEnabled(false);

    auto titlebar = ui.titlebar;
    titlebar->setSizeable(false);
    titlebar->setWindowTitle(QStringLiteral("展示选项"));
    setWindowTitle(QStringLiteral("展示选项"));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    titlebar->setMinable(false);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManWidget::onClose);

    connect(ui.btnOtherFontColor,&QPushButton::clicked,this,&ChatDisplayOptionWidget::onColorSelectBtnClicked);
    connect(ui.btnFontColor,&QPushButton::clicked,this,&ChatDisplayOptionWidget::onColorSelectBtnClicked);
    connect(ui.btnMyColor,&QPushButton::clicked,this,&ChatDisplayOptionWidget::onColorSelectBtnClicked);
    connect(ui.btnOtherColor,&QPushButton::clicked,this,&ChatDisplayOptionWidget::onColorSelectBtnClicked);
    connect(ui.cbFontFamily,&QFontComboBox::currentFontChanged, this, &ChatDisplayOptionWidget::onCurrentFontChanged);
    connect(ui.cbFontSize,&QComboBox::currentTextChanged, this, &ChatDisplayOptionWidget::onCurrentTextChanged);
    ui.btnFontColor->setIconSize(ui.btnFontColor->size());
    ui.btnMyColor->setIconSize(ui.btnMyColor->size());
    ui.btnOtherColor->setIconSize(ui.btnOtherColor->size());
    ui.btnOtherFontColor->setIconSize(ui.btnOtherFontColor->size());
}

ChatDisplayOptionWidget::~ChatDisplayOptionWidget()
{

}

void ChatDisplayOptionWidget::reShow()
{
    // 兼容
    static QList<QColor> colorList;
    colorList << QColor(184,217,245);//blue
    colorList << QColor(221,204,186);//coffee
    colorList << QColor(184,224,189);//green
    colorList << QColor(195,197,199);//gray
    colorList << QColor(224,201,235);//purple
    colorList << QColor(233,197,197);//red
    colorList << QColor(255,255,255);//white
    colorList << QColor(223,221,195);//yellow

    Biz::AllUserSettingData* pSettingData = Biz::Session::getSettingConfig();

    QPixmap pixmap(ui.btnFontColor->size());
    QColor color = MainApp::intToQColor(pSettingData->TextColorRGB());
    pixmap.fill(color);
    ui.btnFontColor->setIcon(QIcon(pixmap));

    QPixmap pixmapL(ui.btnOtherFontColor->size());
    QColor colorL = MainApp::intToQColor(pSettingData->TextColorRGBOther());
    pixmapL.fill(colorL);
    ui.btnOtherFontColor->setIcon(QIcon(pixmapL));

    QColor tempColor;
    QPixmap pixmap1(ui.btnMyColor->size());
   
    if (Biz::AllUserSettingData::sSelfColorDefaultValue == Biz::Session::getSettingConfig()->SelfBubbleColor2()
        && Biz::Session::getSettingConfig()->SelfBubbleColor()<colorList.size())
    {
        tempColor = colorList.at(Biz::Session::getSettingConfig()->SelfBubbleColor());
        MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
    }
    else
    {
        tempColor = MainApp::intToQColor(pSettingData->SelfBubbleColor2());
        tempColor.setAlphaF(pSettingData->SelfBubbleColorAlpha());
    }
    QString colorname = tempColor.name(QColor::HexArgb);

    pixmap1.fill(tempColor);
    ui.btnMyColor->setIcon(QIcon(pixmap1));

    QPixmap pixmap2(ui.btnOtherColor->size());
    if (Biz::AllUserSettingData::sOhterColorDefaultValue == Biz::Session::getSettingConfig()->OtherBubbleColor2()
        && Biz::Session::getSettingConfig()->OtherBubbleColor()<colorList.size())
    {
        tempColor = colorList.at(Biz::Session::getSettingConfig()->OtherBubbleColor());
        MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
    }
    else
    {
        tempColor = MainApp::intToQColor(pSettingData->OtherBubbleColor2());
        tempColor.setAlphaF(pSettingData->OtherBubbleColorAlpha());
    }
    pixmap2.fill(tempColor);
    ui.btnOtherColor->setIcon(QIcon(pixmap2));
    colorname = tempColor.name();
    QString family = Biz::Session::getSettingConfig()->MFontFamily();
    QFont f(family);
    family = f.family();
    ui.cbFontFamily->setCurrentFont(QFont(Biz::Session::getSettingConfig()->MFontFamily()));
	int nfontsize = Biz::Session::getSettingConfig()->MFontSize();
    ui.cbFontSize->setCurrentText(QString::number(Biz::Session::getSettingConfig()->MFontSize()));

    this->showNormal();
	this->activateWindow();
}

void ChatDisplayOptionWidget::onColorSelectBtnClicked(bool)
{
    int initcolor    = 0;
    qreal inialpha   = 0;
    QPushButton* pSender = dynamic_cast<QPushButton*>(sender());

    QColor color;

    if (pSender == ui.btnFontColor)
    {
        initcolor = Biz::Session::getSettingConfig()->TextColorRGB();
        inialpha  = Biz::Session::getSettingConfig()->SelfTextColorAlpha();
        QColor curColor = MainApp::intToQColor(initcolor);
        color = QColorDialog::getColor(curColor,this);
    }

    if (pSender == ui.btnOtherFontColor)
    {
        initcolor = Biz::Session::getSettingConfig()->TextColorRGBOther();
        QColor curColor = MainApp::intToQColor(initcolor);
        color = QColorDialog::getColor(curColor,this);
    }

    if (pSender == ui.btnMyColor)
    {
        initcolor = Biz::Session::getSettingConfig()->SelfBubbleColor2();
        inialpha  = Biz::Session::getSettingConfig()->SelfBubbleColorAlpha();
        QColor curColor = MainApp::intToQColor(initcolor);
        curColor.setAlphaF(inialpha);
        color = QColorDialog::getColor(curColor,this,"",QColorDialog::ShowAlphaChannel);
    }
    if (pSender == ui.btnOtherColor)
    {
        initcolor = Biz::Session::getSettingConfig()->OtherBubbleColor2();
        inialpha  = Biz::Session::getSettingConfig()->OtherBubbleColorAlpha();
        QColor curColor = MainApp::intToQColor(initcolor);
        curColor.setAlphaF(inialpha);
        color = QColorDialog::getColor(curColor,this,"",QColorDialog::ShowAlphaChannel);
    }

    if (color.isValid()) {
        int i = MainApp::QColorToInt(color);
        qreal newAlpha = color.alphaF();
       
        if (NULL!=pSender)
        {
            if (pSender == ui.btnFontColor)
            {
                Biz::Session::getSettingConfig()->TextColorRGB(i);
                Biz::Session::getSettingConfig()->SelfTextColorAlpha(newAlpha);
                Biz::Session::saveSettingConfig();
                MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
                emit sgSelfFontChange();
            }

            if (pSender == ui.btnOtherFontColor)
            {
                Biz::Session::getSettingConfig()->TextColorRGBOther(i);
                Biz::Session::saveSettingConfig();
                MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
                emit sgOtherFontChange();
            }

            if (pSender == ui.btnMyColor)
            {
                Biz::Session::getSettingConfig()->SelfBubbleColor2(i);
                Biz::Session::getSettingConfig()->SelfBubbleColorAlpha(newAlpha);
                MainApp::UIFrame::getChatBubbleController()->updateSelfDefault(i,newAlpha);
                Biz::Session::saveSettingConfig();
                MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
                emit sgSelfBubbleColorChange(i);
            }
            if (pSender == ui.btnOtherColor)
            {
                Biz::Session::getSettingConfig()->OtherBubbleColor2(i);
                Biz::Session::getSettingConfig()->OtherBubbleColorAlpha(newAlpha);
                MainApp::UIFrame::getChatBubbleController()->updateOtherDefault(i,newAlpha);
                Biz::Session::saveSettingConfig();
                MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
                emit sgOtherBubbleColorChange(i);
            }

            QPixmap pixmap(pSender->size());
            pixmap.fill(color);
            pSender->setIconSize(pSender->size());
            pSender->setIcon(QIcon(pixmap));
        }
    }
}

void ChatDisplayOptionWidget::onCurrentFontChanged(const QFont &f)
{
    QString argFontFamily = f.family();
    if (Biz::Session::getSettingConfig()->MFontFamily() != argFontFamily)
    {
        Biz::Session::getSettingConfig()->MFontFamily(argFontFamily);
        emit sgSelfFontChange();
        emit sgOtherFontChange();
        Biz::Session::saveSettingConfig();
        MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
    }
}

void ChatDisplayOptionWidget::onCurrentTextChanged(const QString & numberic)
{
    int size = numberic.toInt();
    if (size != Biz::Session::getSettingConfig()->MFontSize())
    {
        Biz::Session::getSettingConfig()->MFontSize(size);
        emit sgSelfFontChange();
        emit sgOtherFontChange();
        Biz::Session::saveSettingConfig();
        MainApp::UIFrame::getChatBubbleController()->saveConfigeToRemote();
    }
}
