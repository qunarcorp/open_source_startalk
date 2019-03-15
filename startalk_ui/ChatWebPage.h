#ifndef CHATWEBPAGE_H
#define CHATWEBPAGE_H

#include "WebPage.h"
class ChatWebPage : public WebPage
{
    Q_OBJECT

public:
    ChatWebPage(QObject *parent);
    ~ChatWebPage();
private:
    QString localCSSPath;
private slots :
    void onCssChange(const QString& cssPath);
    void onLoadFinished(bool ok);
    void onSelfFontChange();
    void onOtherFontChange();
	void onSelfmsgStatusFont();
};


#endif // WEBPAGE_H
