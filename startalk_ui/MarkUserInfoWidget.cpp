#include "MarkUserInfoWidget.h"
#include "ui_MarkUserInfoWidget.h"
#include "Player.h"
#include "CallbackReceiver.h"

#include "Session.h"
#include "conversationmanager.h"

#include "UIFrame.h"
#include "ConversationController.h"

MarkUserInfoWidget::MarkUserInfoWidget(QWidget *parent)
    : LocalManWidget(parent)
    , ui(new Ui::MarkUserInfoWidget)
{
    ui->setupUi(this);

    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    titlebar->setMinable(false);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
    setWindowTitle(QStringLiteral("用户备注"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
    titlebar->setWindowTitle(QStringLiteral("用户备注"));
    setWindowTitle(QStringLiteral("用户备注"));
#endif
    titlebar->setLeftTitle(QStringLiteral("用户备注"));
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManWidget::onClose);
   
    connect(ui->btnOk, &QPushButton::clicked,this,&LocalManWidget::onClose);

}

MarkUserInfoWidget::~MarkUserInfoWidget()
{

}

void MarkUserInfoWidget::closeEvent(QCloseEvent *)
{
    // 保存备注
    QSharedPointer<Biz::ConversationMarkInfo> spInfo(new Biz::ConversationMarkInfo);
    spInfo->conversationId(ui->lbConversationId->text());
    spInfo->markTitle(ui->lbMarkTitle->text());
    spInfo->markInfo(ui->lbMarkInfo->toPlainText());
    Biz::Session::getConverSationManager()->saveConversationMarkInfo(spInfo);
    // 同步到会话
    MainApp::UIFrame::getConversationController()->updateMarkInfo(spInfo->conversationId());
}

void MarkUserInfoWidget::setData(const QString& conversationId)
{
    ui->lbConversationId->setText(conversationId);
    ui->lbMarkTitle->setText("");
    ui->lbMarkInfo->setText("");
    auto callback = mReceiver->createCallback<QSharedPointer<Biz::ConversationMarkInfo>>([this,conversationId](const QSharedPointer<Biz::ConversationMarkInfo>& spInfo){
        if (!spInfo.isNull())
        {
            ui->lbConversationId->setText(conversationId);
            ui->lbMarkTitle->setText(spInfo->markTitle());
            ui->lbMarkInfo->setText(spInfo->markInfo());
        }
    },[]{});
    Biz::Session::getConverSationManager()->getConversationMarkInfo(conversationId,callback);
}
