#include "popupnoticeview.h"

#include <QPushButton>

#include "ui_popupnoticeview.h"
#include "LanguageHelper.h"
#include "animationreactor.h"

#include "diywidgit/customviews/qframelayout.h"
#include "UiHelper.h"

PopupNoticeView::PopupNoticeView(QWidget *parent)
    : QWidget(parent)
    , m_deleteAtClose(false)
{
    ui = new Ui::PopupNoticeView();
    ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Qt::WindowStaysOnTopHint |Qt::Tool;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("Application_Name"));

    auto titilbar = ui->titlebar;
    titilbar->setMaxable(false);
    titilbar->setMinable(false);
    titilbar->setLeftTitle("");
    connect(titilbar, &TitlebarWidget::sgCloseOnClicked, [this]{this->close ();});

    m_autoHideTimer.setDuration (10*1000);
    connect (&m_autoHideTimer,&QTimeLine::finished,[this]{this->close ();});

    ui->content->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    ui->content->setStyleSheet("border:none;background:#00000000;");

    QFrameLayout* pLayout = new QFrameLayout(this);
    pLayout->appendWidget (ui->shadowbg,ALINE_FILL);
    this->setLayout(pLayout);

    
}

PopupNoticeView::~PopupNoticeView()
{
    delete ui;
}

void PopupNoticeView::showEvent(QShowEvent *e)
{
    AnimationReactorSingleton::getInstance ()->popupWidget (this);
    int nContentWidth = ui->content->width();
    QString string = MainApp::getMaxLineCountLimitText (m_contentText,nContentWidth,2,ui->content->font());
    ui->content->setText(string);
}

void PopupNoticeView::closeEvent(QCloseEvent *e)
{
    if (m_deleteAtClose)
        AnimationReactorSingleton::getInstance ()->opacityOutWidget (this,100);
    else
        AnimationReactorSingleton::getInstance ()->opacityOutWidget (this,100,[this]{this->deleteLater ();});
}

void PopupNoticeView::setContentText(const QString& content)
{
    m_contentText = content;
    int nContentWidth = ui->content->width();
    QString string = MainApp::getMaxLineCountLimitText (m_contentText,nContentWidth,2,ui->content->font());
    ui->content->setText(string);
    ui->content->setToolTip(m_contentText);
}

void PopupNoticeView::showStatic()
{
    this->show ();
    this->raise ();
    m_autoHideTimer.setCurrentTime (0);
    m_autoHideTimer.stop ();
}

void PopupNoticeView::showAutoHide()
{
    this->show ();
    this->raise ();
    m_autoHideTimer.setCurrentTime (0);
    m_autoHideTimer.start ();
}

void PopupNoticeView::enterEvent(QEvent *e)
{
    m_autoHideTimer.setPaused (true);
}

void PopupNoticeView::leaveEvent(QEvent *e)
{
    m_autoHideTimer.setPaused (false);

}

void PopupNoticeView::deleteAtClose(bool b)
{
    m_deleteAtClose = b;
}


ConversationPopupNoticeView::ConversationPopupNoticeView(QWidget* parent)
    : PopupNoticeView(parent)
{
    QFrameLayout* pLayout = (QFrameLayout*)this->layout ();
    QPushButton* pushButton = new QPushButton(this);
    pushButton->setObjectName ("startconversation");
    pushButton->setText (QStringLiteral("发起会话"));
    pushButton->setFixedSize (QSize(82,20));
    pushButton->setFlat (true);
    pLayout->appendWidget (pushButton,ALINE_HCENTER|ALINE_BOTTOM,QMargins(0,0,0,17));
    m_btnStartConversation = pushButton;
}

ConversationPopupNoticeView::~ConversationPopupNoticeView()
{

}

FriendVerifyNoticeView::FriendVerifyNoticeView(QWidget* parent)
    : PopupNoticeView(parent)
{
    QFrameLayout* pLayout = (QFrameLayout*)this->layout ();
    m_btnConfirm = new QPushButton(this);
    m_btnConfirm->setObjectName ("confirm");
    m_btnConfirm->setText (QStringLiteral("同意"));
    m_btnConfirm->setFixedSize (QSize(46,20));
    m_btnConfirm->setFlat (true);
    
    m_btnCancle = new QPushButton(this);
    m_btnCancle->setObjectName ("cancle");
    m_btnCancle->setText (QStringLiteral("拒绝"));
    m_btnCancle->setFixedSize (QSize(46,20));
    m_btnCancle->setFlat (true);


    pLayout->appendWidget (m_btnConfirm,ALINE_HCENTER|ALINE_BOTTOM,QMargins(0,0,46/2+6,20));
   pLayout->appendWidget (m_btnCancle,ALINE_HCENTER|ALINE_BOTTOM,QMargins(46/2+6,0,0,20));
}

FriendVerifyNoticeView::~FriendVerifyNoticeView()
{

}
