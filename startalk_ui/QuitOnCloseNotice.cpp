#include "QuitOnCloseNotice.h"
#include "CustomDefine.h"
#include "Session.h"
#include "SettingData.h"

QuitOnCloseNotice::QuitOnCloseNotice(QWidget *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
    this->setSizeGripEnabled(false);

    auto titlebar = ui.titblebar;
    titlebar->setSizeable(false);
    titlebar->setMinable(false);
    titlebar->setWindowTitle(QStringLiteral("提示"));
    setWindowTitle(QStringLiteral("提示"));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    auto closeOption = [this]{
        bool bMin = ui.cbMinOnClose->isChecked();
        int nCloseOption = bMin?Biz::QuitOnCloseOption::QOC_IGNORE:Biz::QOC_QUIT;
        Biz::Session::getSettingConfig()->QuitOnClose(nCloseOption);
        Biz::Session::saveSettingConfig();
    };
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked,closeOption);
    connect(ui.cbMinOnClose,&QCheckBox::stateChanged,closeOption);

}

QuitOnCloseNotice::~QuitOnCloseNotice()
{

}
