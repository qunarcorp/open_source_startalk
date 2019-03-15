#ifndef PRESENCECHANGEWIDGET_H
#define PRESENCECHANGEWIDGET_H

#include <QWidget>
#include "ui_presencechangewidget.h"

class PresenceChangeWidget : public QWidget
{
    Q_OBJECT

public:
    PresenceChangeWidget(QWidget *parent = 0);
    ~PresenceChangeWidget();
    
private:
    Ui::PresenceChangeWidget ui;
signals:
    void sgPresenceChange(int presence);
protected slots:
    void onPresenceSelect(bool b);

	

};

#endif // PRESENCECHANGEWIDGET_H
