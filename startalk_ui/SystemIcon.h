#ifndef SYSTEMICON_H
#define SYSTEMICON_H

#include <QSystemTrayIcon>
#include <QTimeLine>

class SystemIcon : public QSystemTrayIcon
{
    Q_OBJECT

private:
    SystemIcon();
    ~SystemIcon();
public:
    static SystemIcon& instance();
    void release();
	void setTrayIconText(const QString& toolTip);
    void setMenuAndTooltip(QMenu* menu, const QString& toolTip);
    void clearMenuAndTooltip();
    void flashTrayIcon();
    void stopTrayIcon();
	void setdevicePixelRatio(int nRatio);
	void onDisconnect();
	void onConnected();
signals:
    void sgDoubleClick();
    void sgMouseHover(const QRect&);
    void sgMouseLeave();

    private slots:
        void onTrayIconActivation(QSystemTrayIcon::ActivationReason);
protected:
    virtual void timerEvent(QTimerEvent *);


private:
    QTimeLine m_flashTimer;
    QTimeLine m_hoveCheckTimer;
    bool hovered;
	int m_Ratio;
};

#endif // SYSTEMICON_H
