#ifndef MAINDIALOGCONTROLLER_H
#define MAINDIALOGCONTROLLER_H

#include "ControllerBase.h"
#include <QLabel>
#include <QMovie>

class MainDialog;
class MainWidget;

namespace Biz{
    class AdvDataItem;
}
namespace MainApp
{
	class MainDialogController : public ControllerBase
	{
	    Q_OBJECT
	
	public:
	    MainDialogController();
	    ~MainDialogController();
	
		enum DISPLAYGIFSTYLE
		{
			DISPLAY_GIF_MOVIE,
			DISPLAY_GIF_NOMOVIE
		};
    public:
        void registMainDialog(MainDialog* pChatsContainer);
        void registMainWidget(MainWidget* pMainWidget);
    public:
        virtual void initController();
        virtual void unInitController();
    public:
        void setMainDialogTitle(const QString& title);
        void resizeMainDialogSize(bool bextendshow);
        void activeChatsTab();
        void showCreateGroupDialog(const QString& existMemberid);
        void closeMainDialog();
        void taskTabFlush(bool b);
        void actieMainDialog();
        bool isMainDialogVisible();
        bool isMainDialogActive();
		void showPortrait(QLabel* lab, QSharedPointer<QMovie> movie, DISPLAYGIFSTYLE nstyle=DISPLAY_GIF_MOVIE);
    private:
	    MainDialog* pMainDialog;
        MainWidget* pMainWidget;
signals:
        void sgMainDialogClosed();
        void sgMainThemeChanged();
        void sgMainDialogVisableChange(bool visable);
        void sgShowChatDialog(bool visable);
        public slots:
            void onMainDialogClosed();
            void onShowUrlAdv(const QSharedPointer<Biz::AdvDataItem>& urlItem);
			void onPopImages(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist);
			void onAddBlackName(const QString&id, int rt);
			void onCancelBlackName(const QString&id, int rt);
			void onHistoryError(const QString& errMsg);
	};
}

#endif // MAINDIALOGCONTROLLER_H
