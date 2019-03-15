#ifndef ENCRYPTCHATCONTROLLER_H
#define ENCRYPTCHATCONTROLLER_H

#include "ControllerBase.h"
#include "encryptchatdialog.h"

namespace MainApp
{
	enum ResponeInfor
	{
		ResponeWait,//等待对方应答
		ResponeArgee, //对方同意
		ResponeRefuse, //对方拒绝
		ResponeCancel,  //取消
		ResponeClose    //关闭

	};

	class EncryptChatController : public ControllerBase
	{
		Q_OBJECT

	public:
		EncryptChatController();
		~EncryptChatController();
		void showEncryptChatDialog(const QString&conversationId);

	public:
		virtual void initController();
		virtual void unInitController();

		//主密码不为空的情况下，检查这个会话密码是否为空，
		void doGetSubKey(const QString&key,const QString&subkey, const QString&conversationId);
		void doCreateMainKey(const QString&subkey, const QString& conversationId);
	private:
		
signals:
		void sgCancelEncryptChat(const QString& conversationId);
		void sgEncryptChat(const QString& conversationId);
		void sgDecryptChat(const QString& conversationId);
		void sgEncryptResponeInfor(int type, const QString& conversationId, const QString& Infor);
		void sgCloseEncryptChat(const QString&conversationId);
		void sgLocalArgeeOrRefuse(const QString&conversationId, int type);
	public slots:
		

	private:
		EncryptChatDialog * m_EncryptChatdlg;
		Biz::CallbackReceiver* mReceiver;
	};
}
#endif // ENCRYPTCHATCONTROLLER_H
