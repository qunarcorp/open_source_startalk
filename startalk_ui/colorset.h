#ifndef COLORSET_H
#define COLORSET_H

#include <QObject>
#include "../LocalManUtils/IJsonSerializeable.h"
#include "UtilHelper.h"
class ColorSet : public IJsonSerializeable
{
	Q_OBJECT
        friend class Util::SingletonTemplete<ColorSet>;
private:
    ColorSet():IJsonSerializeable(NULL){};
    ~ColorSet(){};

    JPROPERTY(QString,transparent);
    JPROPERTY(QString,recent_item_bk_hover);
    JPROPERTY(QString,recent_item_bk_checked);
    JPROPERTY(QString,recent_item_title_normal);
    JPROPERTY(QString,recent_item_title_checked);
    JPROPERTY(QString,recent_item_desc_normal);
    JPROPERTY(QString,recent_item_desc_checked);
    JPROPERTY(QString,main_theme_text_active);
    JPROPERTY(QString,main_theme_text_normal);
    JPROPERTY(QString,qchat_notice_promo_normal);
    JPROPERTY(QString,qchat_notice_promo_checked);
    JPROPERTY(QString,qchat_notice_option_normal);
    JPROPERTY(QString,qchat_notice_option_checked);

    JPROPERTY(QString,pinned_list_item_bk_checked);
    JPROPERTY(QString,pinned_list_item_bk_normal);
    JPROPERTY(QString,pinned_list_item_bk_hover);
    JPROPERTY(QString,pinned_list_group_bk_checked);
    JPROPERTY(QString,pinned_list_text_checked);
};

typedef Util::SingletonTemplete<ColorSet> ColorSetSingleton;

#endif // COLORSET_H
