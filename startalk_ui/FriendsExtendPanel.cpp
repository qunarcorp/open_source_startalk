#include "FriendsExtendPanel.h"
#include "Friendslistview.h"

#include <QPropertyAnimation>
#include "diywidgit/customviews/qframelayout.h"
#include "FriendsSearcher.h"

const static QString findFriendKey = QStringLiteral("查找好友");
FriendsExtendPanel::FriendsExtendPanel(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QStringList items;
    items << findFriendKey;
    
    ui.menuItems->addItems(items);

    ui.menuItems->setFixedHeight(ui.menuItems->count()*32);
    ui.menupanel->setFixedHeight(17+ui.menuItems->count()*32);

    ui.pushButton->setCheckable(true);
    ui.pushButton->setChecked(false);

    ui.menupanel->installEventFilter(this);

    onMoreClicked(false);

    QFrameLayout* frameLayout = new QFrameLayout(ui.widget);
    frameLayout->appendWidget(ui.listView,ALINE_FILL);
    frameLayout->appendWidget(ui.menupanel,ALINE_MATCHWIDTH|ALINE_BOTTOM,QMargins(0,0,0,-ui.menuItems->count()*32));
    ui.widget->setLayout(frameLayout);

    connect(ui.menuItems,&QListWidget::itemClicked,this,&FriendsExtendPanel::onItemClicked);
}

FriendsExtendPanel::~FriendsExtendPanel()
{

}

 void FriendsExtendPanel::onItemClicked(QListWidgetItem *item)
 {
     if (NULL!=item && item->text() == findFriendKey)
     {
         FriendsSearcherSingleton::getInstance()->showNormal();
         FriendsSearcherSingleton::getInstance()->activateWindow();
     }

     ui.menuItems->clearSelection();

     ui.pushButton->setChecked(false);
     onMoreClicked(false);
 }
FriendsListView* FriendsExtendPanel::getFriendsListView()
{
    return ui.listView;
}

void FriendsExtendPanel::animotionUp()
{
    int fromY = this->height()-17;

    int offsetY = ui.menuItems->count()*32;
    QPropertyAnimation* popanimation = new QPropertyAnimation(ui.menupanel, "geometry" );
    popanimation->setDuration(100);
    popanimation->setStartValue(QRect(0,fromY,ui.menupanel->width(),17));
    popanimation->setEndValue(QRect(0,fromY-offsetY,ui.menupanel->width(),17+offsetY));
    popanimation->start();
}

void FriendsExtendPanel::animotionDown()
{
    ui.menupanel->move(0,this->height()-17);
}

void FriendsExtendPanel::onMoreClicked(bool bcheck)
{
    ui.pushButton->isChecked()?animotionUp():animotionDown();
}

bool FriendsExtendPanel::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui.menupanel)
    {
        int etype = e->type();
        if (e->type() == QEvent::Leave && ui.pushButton->isChecked())
        {
            ui.pushButton->setChecked(false);
            onMoreClicked(false);
        }
        if (e->type() == QEvent::Enter && !ui.pushButton->isChecked())
        {
            ui.pushButton->setChecked(true);
            onMoreClicked(false);
        }
    }
    return QWidget::eventFilter(obj,e);
}


