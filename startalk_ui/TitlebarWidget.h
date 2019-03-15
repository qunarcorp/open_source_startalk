#ifndef TITLEBARWIDGET_H
#define TITLEBARWIDGET_H

#include <QWidget>
namespace Ui {class TitlebarWidget;};

class TitlebarWidget : public QWidget
{
    Q_OBJECT

public:
    TitlebarWidget(QWidget *parent = 0);
    ~TitlebarWidget();

    void setMaxable(bool);
    void setMinable(bool);
    void setSizeable(bool);
signals:
    void sgMaxOnClicked(bool);
    void sgMinOnClicked(bool);
    void sgCloseOnClicked(bool);
public slots:
    void onSetTitle(const QString&);
    void setLeftTitle( const QString& val );
    void setCloseable( bool v );
private:
    Ui::TitlebarWidget *ui;
};

#endif // TITLEBARWIDGET_H
