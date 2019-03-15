#include "TitlebarWidget.h"
#include "ui_TitlebarWidget.h"
#include <QPushButton>
#include "UiHelper.h"

TitlebarWidget::TitlebarWidget(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::TitlebarWidget();
    ui->setupUi(this);

    connect(ui->Titlebar_Max, &QPushButton::clicked, this, &TitlebarWidget::sgMaxOnClicked);
    connect(ui->Titlebar_Min, &QPushButton::clicked, this, &TitlebarWidget::sgMinOnClicked);
    connect(ui->Titlebar_Close, &QPushButton::clicked, this, &TitlebarWidget::sgCloseOnClicked);
#ifdef QCHAT
	//ui->TitleBar_title->setText("Qunar Chat");
	setLeftTitle("Qunar Chat");
#endif // QCHAT
}

TitlebarWidget::~TitlebarWidget()
{
    delete ui;
}

void TitlebarWidget::onSetTitle( const QString& val )
{
    ui->TitleBar_title->setText(val);
}

void TitlebarWidget::setLeftTitle( const QString& val )
{
    ui->leftTitle->setText(val);
}

void TitlebarWidget::setSizeable( bool v )
{
    ui->Titlebar_Max->setVisible(v);
}

void TitlebarWidget::setMaxable( bool v )
{
    ui->Titlebar_Max->setVisible(v);
}

void TitlebarWidget::setMinable( bool v )
{
    ui->Titlebar_Min->setVisible(v);
}
void TitlebarWidget::setCloseable( bool v )
{
    ui->Titlebar_Close->setVisible(v);
}

