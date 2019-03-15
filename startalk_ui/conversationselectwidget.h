#ifndef CONVERSATIONLISTWIDGET_H
#define CONVERSATIONLISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include "QIMLogicBaseView.h"
#include "UtilHelper.h"
#include "SearchUserListWidget.h"

namespace Ui{
    class ConversationSelectWidget;
}
namespace Biz {
    class ImSession;
}

class ConversationListWidget;

class ConversationSelectWidget : public QIMLogicDialog
{
    Q_OBJECT
        friend class Util::SingletonTemplete<ConversationSelectWidget>;
private:
    ConversationSelectWidget(QWidget *parent = 0);
    ~ConversationSelectWidget();
public:
    void setConversationDataList();
    inline void setExceptConversationIds(const QStringList& ids){this->m_exceptConversationIds = ids;};
    inline QString conversationId() {return m_selectedConversationId;};

private:
    QStringList m_exceptConversationIds;
    QString m_selectedConversationId;
    ConversationListWidget* m_conversationListWidget;
    Ui::ConversationSelectWidget* ui;
	SearchUserListWidget* m_pSearchUserListWidget;

public slots:
	void onSearchEditInputChange(const QString&input);
	void onSearchChatResult(const QString& conversationId);
	void onSearchGroupResult(const QString& conversationId);

};
typedef Util::SingletonTemplete<ConversationSelectWidget> ConversationSelectWidgetSingleton;

#endif // CONVERSATIONLISTWIDGET_H
