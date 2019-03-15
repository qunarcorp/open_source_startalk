#pragma once
class ImageViewer;
class UIInstance
{
public:
    static UIInstance* getInstance();
private:
    static UIInstance* pInstance;

    UIInstance(void);
    ~UIInstance(void);
public:
    inline ImageViewer* getImageViewerDlg() { return imageViewer;};
private:
    ImageViewer* imageViewer;
};

