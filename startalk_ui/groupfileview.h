#ifndef GROUPFILEVIEW_H
#define GROUPFILEVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include "BizCallback.h"

namespace Biz{
    class XmppMessage;
};

class GroupFileOperator
{
public:
    QSharedPointer<Biz::XmppMessage> m_spMessage;
    void onOpen();
    void onDownload(Biz::UnitCallback<QString>* callback);
    void onOpenDir();
    void onSaveAs(Biz::UnitCallback<QString>* callback);
    void onShare();
};

class GroupFileView : public QWidget
{
    Q_OBJECT

public:
    GroupFileView(QWidget *parent);
    ~GroupFileView();

    virtual void	enterEvent(QEvent * event);
    virtual void    leaveEvent (QEvent * event);
  
    void setMessage(const QSharedPointer<Biz::XmppMessage>& spMessage);
    QPushButton* createFuntionButton(QWidget* parent);

    QWidget*    m_pFuntionsWidget;
    QLabel*     m_pIconLabel;
    QLabel*     m_pTitle;
    QPushButton* m_pBtnDownload;
    QPushButton* m_pBtnOpen;
    QPushButton* m_pLocaltion;
    QProgressBar* m_pProgressBar;
    
private:
    QSharedPointer<GroupFileOperator> m_spFileOperator;
    private slots:
        void onDownloadFileClicked(bool b);
        void onSaveAsClicked(bool b);
        void onDownloadProgressDisplay(const QString&key, const QString& fileName, const qint64 done, const qint64 total);
		void onDownloadProgressFinish(const QString&key, const QString& fileName, const QString& filePath);
};

#endif // GROUPFILEVIEW_H
