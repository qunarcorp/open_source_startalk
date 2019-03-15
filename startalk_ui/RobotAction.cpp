#include "RobotAction.h"

#include <QVBoxLayout>
#include <QButtonGroup>


#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "Ordermanagedialog.h"

RobotAction::RobotAction(void)
{

}


RobotAction::~RobotAction(void)
{
}

QSharedPointer<RobotAction> RobotAction::CreateActions(QVariant info)
{
    QSharedPointer<RobotAction> spAction;
    do 
    {
        QVariantMap actionMap = info.toMap();
        QString key = actionMap.value("action").toString();
        QVariant val = actionMap.value("value");

        if (key.compare("openurl",Qt::CaseInsensitive) == 0)
        {
            spAction = QSharedPointer<RobotAction>(new RobotActionOpenUrl(val.toString()));
            break;
        }
        if (key.compare("sendmsg",Qt::CaseInsensitive) == 0)
        {
            spAction = QSharedPointer<RobotAction>(new RobotActionSendMessage(val.toString()));
            break;
        }

    } while (false);
    return spAction;
}

/*
 *	open url
 */
void RobotActionOpenUrl::doAction()
{
    CommentWebViewSingleton::getInstance()->openCommonUrl(mUrl);
}
RobotActionOpenUrl::RobotActionOpenUrl(const QString& url) : mUrl(url){}
RobotActionOpenUrl::~RobotActionOpenUrl(){}


/*
 *	send message 例如选择项
 */
void RobotActionSendMessage::doAction()
{
    QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(mPeerId));
    message->Body(mMessageBody);
    message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
    message->MediaType(Biz::MediaTypeAction);
    message->MsgDirection(Biz::MessageTypeSelf);
    message->MsgSourceType(Biz::subscription);
    Biz::Session::currentAccount().doSendMessage(message,NULL,NULL);
}
RobotActionSendMessage::RobotActionSendMessage(const QString& message): mMessageBody(message){}
RobotActionSendMessage::~RobotActionSendMessage(){}


/*
 *	other
 */
void RobotActionQrcode::doAction()
{
}

void RobotActionBarcode::doAction()
{
}

void RobotActionPostbackcookie::doAction()
{
}

/*
 *	主按钮
 */
MainActionBtn::MainActionBtn(QWidget* parent,QList<QPushButton*>* btnGroup) : QPushButton(parent)
{
    btnGroup->push_back(this);
    setFlat(true);
    //setAutoExclusive(true);
    setCheckable(true);
    setChecked(false);

    //connect(this,&QPushButton::toggled,this,&MainActionBtn::onCheckStatusChange);
    connect(this,&QPushButton::clicked,[this,btnGroup](bool bcheck){
        for (QPushButton* pbtn : *btnGroup)
        {
            if (pbtn==this)
            {
                bool ischeck = isChecked();
                bool ischeckable = isCheckable();
                pbtn->setChecked(this->isCheckable()&& this->isChecked()&&bcheck);
            }
            else
            {
                pbtn->setChecked(false);
            }
            if (pbtn->isCheckable())
            {
                 ((MainActionBtn*)pbtn)->onCheckStatusChange(pbtn->isChecked());
            }
        }

        if (!mAction.isNull())
        {
            mAction->doAction();
        }
    });


    mSubActionPanel = QSharedPointer<SubActionPtnPanal>(new SubActionPtnPanal(parent));
	mSubActionPanel->setVisible(false);
   

    setStyleSheet(
        "QPushButton                   "
        "{                             "
        "    color:#666666;            "
        "    background-color:#FFFFFF; "
        "    border: none ;              "
        "	 max-height:46px;           "
        "    min-height:46px;          "
        "}                             "
        "                              "
        "QPushButton:hover             "
        "{                             "
        "    background-color:#f5f5f5; "
        "}                             "
        "QPushButton:pressed           "
        "{                             "
        "    background-color:#EBEBEB; "
        "}                             "
        "QPushButton:checked           "
        "{                             "
        "    background-color:#EBEBEB; "
        "}                             "
        );
}

MainActionBtn::~MainActionBtn()
{

}

void MainActionBtn::onCheckStatusChange(bool check)
{
    if (!mSubActionPanel.isNull())
    {
        bool visable = check && mSubActionPanel->hasChild();
        QString name = this->text();
        mSubActionPanel->setVisible(visable);
        if (check)
        {
            moveSubPanel();
        }
    }
}

void MainActionBtn::addSubActionBtn(SubActionBtn* btn)
{
    connect(btn,&QPushButton::clicked,[this](bool b){
        emit this->clicked(false);
    });

    mSubActionPanel->addSubActionBtn(btn);

    QSize size = mSubActionPanel->size();
    size = this->size();
}

void MainActionBtn::resizeEvent(QResizeEvent *)
{
   moveSubPanel();
}

void MainActionBtn::moveSubPanel()
{
    mSubActionPanel->setFixedWidth(this->width());
    QWidget* parent = (QWidget*)mSubActionPanel->parent();
    QPoint p1 = mapToGlobal(QPoint(0,0));
    QPoint p2 = parent->mapToGlobal(QPoint(0,0));
    QPoint p3 = QPoint(p1.x(),p1.y()-mSubActionPanel->height()- 6);
    QPoint p4 = parent->mapFromGlobal(p3);
    mSubActionPanel->move(p4); // 在父窗口中的位置
}

SubActionPtnPanal::SubActionPtnPanal(QWidget* parent) : QWidget(parent)
{
    pLayout = new QVBoxLayout(this);
    pLayout->setSpacing(1);
    pLayout->setContentsMargins(11, 11, 11, 11);
    pLayout->setContentsMargins(1, 1, 1, 1);

    setStyleSheet(
        "QWidget                   "
        "{                             "
        "    color:#666666;            "
        "    background-color:#EBEBEB; "
        "    border: none ;            "
        "}                             "
        );

}

void SubActionPtnPanal::addSubActionBtn(SubActionBtn* btn)
{
    pLayout->addWidget(btn);
    setFixedSize(QSize(200,47*pLayout->count()+1));
}

SubActionPtnPanal::~SubActionPtnPanal()
{

}

bool SubActionPtnPanal::hasChild()
{
    return pLayout->count() != 0;
}

SubActionBtn::SubActionBtn(QWidget* parent) : QPushButton(parent)
{
    setFlat(true);
    setAutoExclusive(true);
    setCheckable(false);
    setChecked(false);

    setStyleSheet(
        "QPushButton                   "
        "{                             "
        "    color:#666666;            "
        "    background-color:#FFFFFF; "
        "    border: none ;              "
        "	 max-height:46px;           "
        "    min-height:46px;          "
        "}                             "
        "                              "
        "QPushButton:hover             "
        "{                             "
        "    background-color:#f5f5f5; "
        "}                             "
        "QPushButton:pressed           "
        "{                             "
        "    background-color:#EBEBEB; "
        "}                             "
        "QPushButton:checked           "
        "{                             "
        "    background-color:#EBEBEB; "
        "}                             "
        );

    connect(this,&QPushButton::clicked,[this](bool bchecked){
        if (!mAction.isNull())
        {
            mAction->doAction();
        }
    });
}

SubActionBtn::~SubActionBtn()
{

}
