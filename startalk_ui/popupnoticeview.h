#ifndef POPUPNOTICEVIEW_H
#define POPUPNOTICEVIEW_H

#include <QWidget>
#include <QTimeLine>
#include <QPushButton>
namespace Ui {class PopupNoticeView;};

class PopupNoticeView : public QWidget
{
    Q_OBJECT

public:
    PopupNoticeView(QWidget *parent = 0);
    ~PopupNoticeView();
    void setContentText(const QString& content);
    void showStatic();
    void showAutoHide();
    void deleteAtClose(bool b);
protected:
    virtual void showEvent (QShowEvent *e);
    virtual void closeEvent (QCloseEvent *e);
    virtual void enterEvent (QEvent *e);
    virtual void leaveEvent (QEvent *e);
    
private:
    Ui::PopupNoticeView *ui;

    QTimeLine       m_autoHideTimer;
    bool            m_deleteAtClose;
    QString         m_contentText;
};

class ConversationPopupNoticeView : public PopupNoticeView
{
public:
    ConversationPopupNoticeView(QWidget* parent=NULL);
    ~ConversationPopupNoticeView();
    QPushButton*    m_btnStartConversation;
};

class FriendVerifyNoticeView : public PopupNoticeView
{
public:
    FriendVerifyNoticeView(QWidget* parent=NULL);
    ~FriendVerifyNoticeView();
    QPushButton*    m_btnConfirm;
    QPushButton*    m_btnCancle;
};

#endif // POPUPNOTICEVIEW_H
