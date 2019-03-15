#pragma once
#include <QString>
namespace Util{
    class DumpHandle
    {
    public:
        virtual ~DumpHandle();
        static DumpHandle* GetInstance(){ static DumpHandle ins;return &ins;}
        static void Init(QString path);
    protected:
    private:
        DumpHandle();
        QString mstrSavePath;
    };
}

