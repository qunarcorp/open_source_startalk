#ifndef MORESELECTIONPANEL_H
#define MORESELECTIONPANEL_H

#include <QWidget>
#include "ui_moreselectionpanel.h"

class MoreSelectionPanel : public QWidget
{
	Q_OBJECT

public:
    MoreSelectionPanel(QWidget *parent = 0);
    ~MoreSelectionPanel();

private:
    Ui::MoreSelectionPanel ui;
};

#endif // MORESELECTIONPANEL_H
