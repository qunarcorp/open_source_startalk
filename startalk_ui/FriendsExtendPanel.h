#ifndef FRIENDSEXTENDPANEL_H
#define FRIENDSEXTENDPANEL_H

#include <QWidget>
#include "ui_FriendsExtendPanel.h"
class FriendsListView;

class FriendsExtendPanel : public QWidget
{
    Q_OBJECT

public:
    FriendsExtendPanel(QWidget *parent = 0);
    ~FriendsExtendPanel();
public:
    FriendsListView* getFriendsListView();
protected:
    virtual bool eventFilter(QObject *, QEvent *);

private:
    void animotionUp();
    void animotionDown();
private:
    Ui::FriendsExtendPanel ui;
protected slots:
    void onMoreClicked(bool bcheck);
    void onItemClicked(QListWidgetItem *item);

};

#endif // FRIENDSEXTENDPANEL_H
