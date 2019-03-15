#ifndef CHATBUBBLECONTROLLER_H
#define CHATBUBBLECONTROLLER_H
#include "ControllerBase.h"
#include <QObject>

namespace MainApp
{
    class ChatBubbleConfigItem;
	class ChatBubbleController : public ControllerBase
	{
	    Q_OBJECT
	
	public:
	    ChatBubbleController();
	    ~ChatBubbleController();

    public:
        virtual void initController();
        virtual void unInitController();
    public:
        void updateBubble(const QString& jid,int color);
        void updateOtherDefault(int color, qreal alpha );
        void updateSelfDefault(int color, qreal alpha );
        void saveConfigeToRemote();
    private:
        void loadBubbleConfig();
        void saveBubbleConfig();
        QPixmap drawBubble(int color, qreal alpha);
        QPixmap drawSelfBubble(int color, qreal alpha);

    private:    

	private:
	    // 
        int mVersion;
        QMap<QString,ChatBubbleConfigItem> mBubbleConfigs;

        const static QString kChatColorInfo;
        const static QString kCurrentFontInfo;
signals:
        void sgChatBubbleQssChanged(const QString& configPath);
        public slots:
         void onPersonCfgChange(const QStringList& changedKeys);
	};

    
}

#endif // CHATBUBBLECONTROLLER_H
