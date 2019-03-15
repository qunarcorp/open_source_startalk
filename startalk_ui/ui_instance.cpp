#include "ui_instance.h"
#include "CoreObject.h"
#include "imageviewer.h"
#include "UiHelper.h"

UIInstance* UIInstance::pInstance = NULL;

UIInstance::UIInstance(void)
{
    imageViewer = new ImageViewer();
    
}


UIInstance::~UIInstance(void)
{
}

UIInstance* UIInstance::getInstance()
{
    if (pInstance==NULL)
    {
        pInstance = new UIInstance();
    }
    return pInstance;
}
