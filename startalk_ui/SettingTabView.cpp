#include "SettingTabView.h"
#include "ui_SettingTabView.h"
#include "LanguageHelper.h"

SettingTabView::SettingTabView(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::SettingTabView();
    ui->setupUi(this);

    ui->SettingTab_ListItem_2->setText(T_("SettingWindow_Tab1"));
    //ui->SettingTab_ListItem->setText(T_("SettingWindow_Tab2"));
    buttons.append(ui->SettingTab_ListItem_2);
    //buttons.append(ui->SettingTab_ListItem);

    foreach(auto item, buttons){
        connect(item, &QToolButton::clicked, this, &SettingTabView::onClicked);
    }

    ui->SettingTab_ListItem_2->click();
}

SettingTabView::~SettingTabView()
{
    delete ui;
}

void SettingTabView::onClicked( bool )
{
    auto item = (QToolButton*)sender();

    if(item == ui->SettingTab_ListItem_2){
        emit sgSyetemSetting();
    }
//     else if(item == ui->SettingTab_ListItem){
//         emit sgProfileSetting();
//     }

//     foreach(auto itor, buttons){
//         if(itor == ui->SettingTab_ListItem){
//             itor->setChecked(false);
//             continue;
//         }
//         itor->setChecked(true);
        //itor->setChecked(item == itor);
    //}
}

