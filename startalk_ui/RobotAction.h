#pragma once

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QVariant>

class RobotAction
{
public:
    RobotAction(void);
    virtual ~RobotAction(void);
public:
    inline QString getName()const {return mName;};
    inline void setName(const QString& name) {mName = name;};
    inline QString getActionId() const {return mActionId;};
    inline void setActionId(const QString& actionId){mActionId = actionId;};
    inline void setPeerid(const QString& peerid){mPeerId = peerid;};
public:
    static QSharedPointer<RobotAction> CreateActions(QVariant info);
public:
    virtual void doAction() = 0;
protected:
    QString mName;
    QString mPeerId;
    QString mActionId;
};


class RobotActionOpenUrl : public RobotAction
{
public:
    RobotActionOpenUrl(const QString& url);
    ~RobotActionOpenUrl();
public:
    virtual void doAction();
private:
    QString mUrl;
};

class RobotActionSendMessage : public RobotAction
{
public:
    RobotActionSendMessage(const QString& message);
    ~RobotActionSendMessage();
public:
    virtual void doAction();
    QString mMessageBody;
};

class RobotActionQrcode : public RobotAction
{

    public:
    virtual void doAction();

};
class RobotActionBarcode : public RobotAction
{

    public:
    virtual void doAction();

};
class RobotActionPostbackcookie : public RobotAction
{
public:
     virtual void doAction();
};

class SubActionBtn : public QPushButton
{
public:
    SubActionBtn(QWidget* parent);
    ~SubActionBtn();
     inline void setAction(QSharedPointer<RobotAction> action){this->mAction = action;};
private:
     QSharedPointer<RobotAction> mAction;
};

class SubActionPtnPanal : public QWidget
{
public:
    SubActionPtnPanal(QWidget* parent);
    ~SubActionPtnPanal();
public:
    bool hasChild();
    void addSubActionBtn(SubActionBtn* btn);
public:
    QVBoxLayout* pLayout;
};

class MainActionBtn : public QPushButton
{
    Q_OBJECT;
public:
    MainActionBtn(QWidget* parent,QList<QPushButton*>* btnGroup);
    ~MainActionBtn();
public:
    inline void setAction(QSharedPointer<RobotAction> action){this->mAction = action;};
    inline void setName(const QString& text){this->setText(text);};
public:
    void addSubActionBtn(SubActionBtn* btn);
protected:
    virtual void resizeEvent(QResizeEvent *);
protected:
    void moveSubPanel();

public:
    QSharedPointer<SubActionPtnPanal> mSubActionPanel;
    QSharedPointer<RobotAction> mAction;
public slots:
       void onCheckStatusChange(bool check);


};