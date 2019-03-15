#include "MainDialogController.h"
#include "MainDialog.h"
#include "MainWidget.h"

#include "ChatDisplayOptionWidget.h"

#include "Session.h"
#include "advinformanager.h"

#include "jsonobject/adverconfiginfo.h"
#include "Ordermanagedialog.h"
#include "AdvData.h"
#include "advpopdialog.h"
#include "Account.h"
#include "UserVcardManager.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "groupquitview.h"
#include "MessageManager.h"
#include "Framework.h"
#include "LoginController.h"

namespace MainApp
{
	MainDialogController::MainDialogController()
	    : ControllerBase(NULL)
        , pMainDialog(NULL)
        , pMainWidget(NULL)
	{
	
	}
	
	MainDialogController::~MainDialogController()
	{
	
	}

    void MainDialogController::initController()
    {
        connect(this,&MainDialogController::sgMainDialogClosed,this,&MainDialogController::onMainDialogClosed);
        connect(Biz::Session::getAdvInforManager(),&Biz::AdvInforManager::sgShowAdvUrl,this,&MainDialogController::onShowUrlAdv);
		connect(Biz::Session::getAdvInforManager(),&Biz::AdvInforManager::sgPopImages, this, &MainDialogController::onPopImages);

		connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgAddBlackName, this, &MainDialogController::onAddBlackName);
		connect(Biz::Session::getFriendManager(), &Biz::FriendsManager::sgCancelBlackName, this, &MainDialogController::onCancelBlackName);
		connect(Biz::Session::getMessageManager(),&Biz::MessageManager::sgHistoryError,this,&MainDialogController::onHistoryError);
    }

	void MainDialogController::onHistoryError(const QString& errMsg) { 
		MainApp::Framework::onLogout(); 
		MainApp::UIFrame::getLoginController()->setErrorTipsAtNormalLoginDialog(errMsg);
	}

    void MainDialogController::unInitController()
    {
    }

    void MainDialogController::registMainDialog(MainDialog* pChatsContainer)
    {
        if (pChatsContainer!=NULL)
        {
            pMainDialog = pChatsContainer;
        }
    }
    void MainDialogController::registMainWidget(MainWidget* pMainWidget)
    {
        if (NULL!=pMainWidget)
        {
            this->pMainWidget = pMainWidget;
        }
    }

    void MainDialogController::setMainDialogTitle(const QString& title)
    {
        if (NULL!=pMainDialog)
        {
            pMainDialog->setTitle(title);
        }
    }

    void MainDialogController::resizeMainDialogSize(bool bextendshow)
    {
        if (NULL!=pMainDialog)
        {
            pMainDialog->resizeMainwidget(bextendshow);;
        }
    }

    void MainDialogController::activeChatsTab()
    {
        if (NULL!=pMainWidget)
        {
            pMainWidget->activeChatsBtn();
        }
    }

    void MainDialogController::showCreateGroupDialog(const QString& existMemberid)
    {
        if (NULL!=pMainWidget)
        {
            pMainWidget->showAddGroup(existMemberid);
        }
    }

    void MainDialogController::closeMainDialog()
    {
        if (NULL!=pMainDialog)
        {
            pMainDialog->onClose(false);
        }
    }

    bool MainDialogController::isMainDialogVisible()
    {
        if (NULL!=pMainDialog)
        {
            return pMainDialog->isVisible();
        }
        return false;
    }

    void MainDialogController::taskTabFlush(bool b)
    {
        if (NULL!=pMainDialog)
        {
            b? pMainDialog->autoFlash():pMainDialog->stopFlash();
        }
    }

    void MainDialogController::actieMainDialog()
    {
        if (NULL!=pMainDialog)
        {
            if (pMainDialog->isMaximized ())
                pMainDialog->showMaximized ();
            else
                pMainDialog->showNormal();

            pMainDialog->activateWindow();
        }
    }

    void MainDialogController::onMainDialogClosed()
    {
        ChatDisplayOptionWidgetSingleton::getInstance()->close();
        GroupQuitViewSingleton::getInstance ()->close ();
    }

    void MainDialogController::onShowUrlAdv(const QSharedPointer<Biz::AdvDataItem>& urlItem)
    {
        QSharedPointer<Biz::AdverConfigInfo> spConfigInfo = Biz::Session::getAdvInforManager()->getAdvConfigInfo();
        if (spConfigInfo.isNull())
            return; // 数据不足
        if (!spConfigInfo->shown())
            return; // 无广告
        if (!urlItem.isNull() && !urlItem->strLinkUrl.isEmpty())
        {
            CommentWebViewSingleton::getInstance()->openCommonUrl(urlItem->strLinkUrl);
        }
    }

	void MainDialogController::onPopImages( const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist )
	{
		AdvPopDialog *pdialog = AdvPopDialogSingleton::getInstance();
		if (pdialog)
		{
			pdialog->showAdvPopAnimation(imagelist);
		}
	}

	void MainDialogController::onAddBlackName( const QString&id, int rt )
	{
		if (id.isEmpty())
		{
			return;
		}
		QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserId(id));
		if (displayname.isEmpty())
		{
			displayname = Biz::MessageUtil::makeSureUserId(id);
		}
		QString strTitle;
		if (rt == Biz::FriendsManager::RESULTSUCCESS)
		{
			strTitle = QStringLiteral("[%1]加入黑名单成功！").arg(displayname);
		}
		else if(rt == Biz::FriendsManager::RESULTFAIL)
		{

			strTitle = QStringLiteral("[%1]加入黑名单失败！").arg(displayname);
		}
        MainApp::UIFrame::getNotifyCenterController ()->popupNotice (strTitle);

	}

	void MainDialogController::onCancelBlackName( const QString&id, int rt )
	{
		if (id.isEmpty())
		{
			return;
		}
		QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserId(id));
		if (displayname.isEmpty())
		{
			displayname = Biz::MessageUtil::makeSureUserId(id);
		}
		QString strTitle;
		if (rt == Biz::FriendsManager::RESULTSUCCESS)
		{
			strTitle = QStringLiteral("[%1]移出黑名单成功！").arg(displayname);
		}
		else if(rt == Biz::FriendsManager::RESULTFAIL)
		{

			strTitle = QStringLiteral("[%1]移出黑名单失败！").arg(displayname);
		}
        // tudo
// 		PopMessageBoxSingleton::getInstance()->setWidgetInScreen((QWidget*)pMainWidget);
// 		PopMessageBoxSingleton::getInstance()->setDisplayText(strTitle);
// 		PopMessageBoxSingleton::getInstance()->setButton(PopMessageBox::MessageButton_Confirm);
// 		PopMessageBoxSingleton::getInstance()->showPopAnimation();
	}

    bool MainDialogController::isMainDialogActive()
    {
        if (NULL!=pMainDialog)
        {
            return pMainDialog->isActiveWindow();
        }
        return false;
    }

	void MainDialogController::showPortrait( QLabel* lab, QSharedPointer<QMovie> movie, DISPLAYGIFSTYLE nstyle )
	{
		if (lab == NULL || movie.isNull())
		{
			return;
		}
		int ncount = movie->frameCount();
		if (ncount != 0)
		{
			connect(movie.data(), &QMovie::frameChanged, [this, lab, movie, nstyle](int frameNumber){
				QPixmap pixmap = movie->currentPixmap();

				QPixmap  scaledPix = pixmap.scaled(lab->size());

				lab->setPixmap(scaledPix);
				if (nstyle == DISPLAY_GIF_NOMOVIE)
				{
					movie->stop();
				}
			});

			movie->start();


		}
		else
		{
			QString strPath = movie->fileName();
		
			QPixmap pixmap(strPath);

			QPixmap  scaledPix = pixmap.scaled(lab->size());

			lab->setPixmap(scaledPix);
		}
		
	}
}
