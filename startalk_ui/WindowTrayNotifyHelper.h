#pragma once
#include "CoreObject.h"

class WindowTrayNotifyHelper
{
private:
    WindowTrayNotifyHelper(void);
    ~WindowTrayNotifyHelper(void);

    QRect findIconGeometry(const int);
public:
    static QRect FindMyIcon();
};

