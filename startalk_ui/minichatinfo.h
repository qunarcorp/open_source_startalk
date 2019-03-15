#ifndef MINICHATINFO_H
#define MINICHATINFO_H

#include <QWidget>
#include "ui_minichatinfo.h"

class MiniChatInfo : public QWidget
{
    Q_OBJECT

public:
    MiniChatInfo(QWidget *parent = 0);
    ~MiniChatInfo();

    void setDisplayName(const QString& string);
    QString getDisplayName();
    void setDescription(const QString& string);
    void setUnReadCount(int count);
    void setHeaderIcon(const QPixmap& pixmap);
    void setLastTimeStamp(const QString timestr);

    inline void setIsGroupId(bool flag){isGroup = flag;};
    inline bool IsGroupId() { return isGroup; };

    inline void setID(const QString& id) {this->id = id;};
    inline QString Id() {return id;};

    inline bool IsSelected() { return isSelected;};
    inline void IsSelected(bool b) { this->isSelected = b;}; 
    
private:
    Ui::MiniChatInfo ui;
    bool isGroup;
    QString id;
    bool isSelected;
    public slots:
        void onRoomListNameReceived(const QMap<QString, QString>& mapData);
        void onChatDialogUnreadChange(const QString&,int);
};

#endif // MINICHATINFO_H
