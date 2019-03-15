#ifndef SETTINGTABVIEW_H
#define SETTINGTABVIEW_H

#include <QWidget>
#include <QToolButton>
namespace Ui {class SettingTabView;};

class SettingTabView : public QWidget
{
    Q_OBJECT

public:
    SettingTabView(QWidget *parent = 0);
    ~SettingTabView();

signals:
    void sgSyetemSetting();
    void sgProfileSetting();
private slots:
    void onClicked(bool);
private:
    Ui::SettingTabView *ui;
    QList<QToolButton*> buttons;
};

#endif // SETTINGTABVIEW_H
