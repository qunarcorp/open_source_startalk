#ifndef QRCODEWIDGET_H
#define QRCODEWIDGET_H

#include <QWidget>
#include "ui_QRCodeWidget.h"
#include "localmanwidget.h"
#include "UtilHelper.h"
#include <functional>

class QRCodeWidget : public LocalManWidget
{
    Q_OBJECT
 public:
    QRCodeWidget(QWidget *parent = 0);
    ~QRCodeWidget();
public:
    void autoShow();

    virtual void showEvent(QShowEvent *);

    virtual void resizeEvent(QResizeEvent *);
    virtual void closeEvent(QCloseEvent *);
    
protected:
    void initDispacher();
    bool dealGroupData(const QString& data);
    bool dealHttpData(const QString& data);
    bool dealTextData(const QString& data);

private:
    Ui::QRCodeWidget ui;
    QPropertyAnimation* pAnimation;
	

    QList<std::function<bool (const QString&)>> mDispatch;
    public slots:
        void onGrabQRcode(int currentLoop);


};

typedef Util::SingletonTemplete<QRCodeWidget> QRCodeWidgetSingleton; 

#endif // QRCODEWIDGET_H
