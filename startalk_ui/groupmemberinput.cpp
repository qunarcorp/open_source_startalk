#include "groupmemberinput.h"
#include "Session.h"
#include "Account.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
GroupMemberInput::GroupMemberInput(LocalManDialog *parent)
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

    auto titlebar = ui.titlebar;
    titlebar->setSizeable(false);
    titlebar->setMinable(false);
    titlebar->setLeftTitle(QStringLiteral("输入需要邀请的成员id或者邮箱地址,以“;”隔开"));
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, [this](bool){
        this->close();
    });

    connect(ui.ok, &QPushButton::clicked,[this](){
        chargeInput();
    });
    this->setSizeGripEnabled(true);
}

GroupMemberInput::~GroupMemberInput()
{

}

void GroupMemberInput::chargeInput()
{
    QString inputTxt = ui.textEdit->toPlainText();
    if (inputTxt.isEmpty())
    {
        this->close();
    }
    inputTxt+=";";
    QStringList errorLst;
    QStringList retLst;
    QMap<QString,QString> map;

    QStringList inputList = inputTxt.split(";");
    for (QString line:inputList)
    {
        line = line.trimmed();

        if (!line.isEmpty())
        {
            QRegExp regExp("<(.*)@.*");    
            regExp.setMinimal(true);

            QStringList xslist;
            auto pos = regExp.indexIn(line, 0);
            if (pos!=-1)
            {
                QString userId = regExp.cap(1).trimmed();
                if (!userId.isEmpty())
                {
                    QString userName = Biz::Session::currentAccount().getUserNameById(userId);
                    if (!userName.isEmpty())
                    {
                        retLst.push_back(userId);
                        map.insert(userId,userName);
                        continue;
                    }
                }
            }
            else
            {
                QString userName = Biz::Session::currentAccount().getUserNameById(line);
                if (!userName.isEmpty())
                {
                    retLst.push_back(line);
                    map.insert(line,userName);
                    continue;
                }
            }

            errorLst.append(line);
        }
    }

    mUserList.clear();
    mUserList.append(retLst);
    mUserMap.clear();
    mUserMap = map;

    if (!errorLst.isEmpty())
    {
        if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (QStringLiteral("以下用户识别失败，\r\n")+errorLst.join(";")+QStringLiteral("\r\n确认添加？")))
        {
            return;
        }
    }

    this->close();
}
