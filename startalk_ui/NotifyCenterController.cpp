
#include "NotifyCenterController.h"
#include "UIFrame.h"
#include "ConversationController.h"

#include "popupnoticeview.h"

#include "DealMessageBox.h"
#include <QDialog>

namespace MainApp{
    void NotifyCenterController::initController()
    {
    }

    void NotifyCenterController::unInitController()
    {
    }

    NotifyCenterController::NotifyCenterController()
        : ControllerBase(NULL)
    {

    }

    NotifyCenterController::~NotifyCenterController()
    {

    }

    void NotifyCenterController::popupNotice(const QString& content)
    {
        PopupNoticeView* pPopview= new PopupNoticeView();
        pPopview->setContentText (content);
        pPopview->deleteAtClose (true);
        pPopview->showAutoHide ();
    }

    void NotifyCenterController::popupConversationNotice(const QString& content,const QString& conversationId)
    {
        ConversationPopupNoticeView* pConversationView = new ConversationPopupNoticeView();
        pConversationView->setContentText (content);
        connect(pConversationView->m_btnStartConversation,&QPushButton::clicked,[pConversationView,this,conversationId]{
            MainApp::UIFrame::getConversationController()->createNewChatDialog(conversationId);
            MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
            MainApp::UIFrame::getConversationController()->activeConversation(conversationId);
            pConversationView->close ();
        } );

        pConversationView->deleteAtClose (true);
        pConversationView->showAutoHide ();
    }

    void NotifyCenterController::popupAddFriendNotice(const QString& content,std::function<void()> confirmcb)
    {
        FriendVerifyNoticeView* pPopView = new FriendVerifyNoticeView();
        pPopView->setContentText (content);
        pPopView->deleteAtClose (true);
        
        connect (pPopView->m_btnConfirm,&QPushButton::clicked,[pPopView,confirmcb]{
            confirmcb();
            pPopView->close ();
        });

        connect (pPopView->m_btnCancle,&QPushButton::clicked,[pPopView]{
            pPopView->close ();
        });

        pPopView->deleteAtClose (true);
        pPopView->showStatic ();
    }

    bool NotifyCenterController::alertMessage(const QString& content)
    {
        return alertMessage ("",content,"",QStringLiteral("确定"));
    }

	bool NotifyCenterController::alertMessageWithCancle(const QString& content)
    {
         return alertMessage ("",content,QStringLiteral("取消"),QStringLiteral("确定"));
    }

    bool NotifyCenterController::alertMessageWithCancle(const QString& title,const QString& content)
    {
         return alertMessage (title,content,QStringLiteral("取消"),QStringLiteral("确定"));
    }

	bool NotifyCenterController::alertMessageWithArgee(const QString& title,const QString& content )
	{
		return alertMessage (title,content,QStringLiteral("拒绝"),QStringLiteral("同意"));
	}

	bool NotifyCenterController::alertMessage(const QString& title,const QString& content)
    {
        return alertMessage (title,content,"",QStringLiteral("确定"));
    }

    bool NotifyCenterController::alertMessage(const QString& title,const QString& content,const QString& cancelText,const QString& confirmText)
    {
        DealMessageBox box;
        
        int nButton = 0;
        if (!cancelText.isEmpty ())
            nButton |= DealMessageBox::MessageButton_Cancel;
        if (!confirmText.isEmpty ())
            nButton |= DealMessageBox::MessageButton_Confirm;

        if (0!=nButton)
        {
            box.setButton (nButton);
            box.setDisplayText (content);
            box.setCancelText (cancelText);
            box.setConfirmText (confirmText);
            return box.exec ();
        }

        // QDialog::Rejected	0
        // QDialog::Accepted	1

        return false;
    }

	bool NotifyCenterController::alertMessage( const QString& title,const QString& content,const QString& cancelText,const QString& confirmText, QDialog*parent )
	{
		
		DealMessageBox *box = DealMessageBox::getInstanc(parent);
		
		box->setModal(true);
		
		int nButton = 0;
		if (!cancelText.isEmpty ())
			nButton |= DealMessageBox::MessageButton_Cancel;
		if (!confirmText.isEmpty ())
			nButton |= DealMessageBox::MessageButton_Confirm;

		if (0!=nButton)
		{
			box->setButton (nButton);
			box->setDisplayText (content);
			box->setCancelText (cancelText);
			box->setConfirmText (confirmText);
			return box->exec();
		}

		return false;
	}


}

