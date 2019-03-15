#pragma  once

#include "ControllerBase.h"

class QDialog;
namespace MainApp
{
    class NotifyCenterController : public ControllerBase
    {
        Q_OBJECT
    public:
        NotifyCenterController();
        ~NotifyCenterController();
        virtual void initController();
        virtual void unInitController();
    public:
        bool alertMessage(const QString& content);
        bool alertMessage(const QString& title,const QString& content);
        bool alertMessageWithCancle (const QString& content);
		bool alertMessageWithArgee(const QString& title,const QString& content);
        bool alertMessageWithCancle (const QString& title,const QString& content);
        bool alertMessage(const QString& title,const QString& content,const QString& cancelText,const QString& confirmText);

		bool alertMessage(const QString& title,const QString& content,const QString& cancelText,const QString& confirmText, QDialog*parent);

        void popupNotice(const QString& content);
        void popupConversationNotice(const QString& content,const QString& conversationId);
        void popupAddFriendNotice(const QString& content,std::function<void()> confirmcb);
    };
}