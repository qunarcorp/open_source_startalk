#include "passwordinput.h"

PasswordInput* PasswordInput::instalce = NULL;
PasswordInput::PasswordInput(LocalManDialog *parent)
    : LocalManDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    //ui.label->setScaledContents(true);
	QPixmap pix(":/Images/im_default_header.png");
	pix = QPixmap::fromImage(pix.toImage().scaled(ui.label->size()));
    ui.label->setPixmap(pix);


    auto titlebar = ui.widget;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &PasswordInput::onMin);
    connect(titlebar, &TitlebarWidget::sgMaxOnClicked, this, &PasswordInput::onMax);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &PasswordInput::onClose);

    connect(ui.join,&QPushButton::clicked,this,&PasswordInput::onJoin);
}

void PasswordInput::onClose(bool)
{
    this->close();
}

PasswordInput::~PasswordInput()
{

}

void PasswordInput::onJoin(bool)
{
    setResult(QDialog::Accepted);
    this->done(QDialog::Accepted);
}
