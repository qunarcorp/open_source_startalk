#pragma once
#include <QByteArray>

class VoiceHelper
{
public:
    VoiceHelper(void);
    ~VoiceHelper(void);
    static bool amrFileToWavBuffer(const char* szAmrFileName, QByteArray& arrWavData);
    static bool amrBufferToWavBuffer(unsigned char* inBuffer, int inBufferLen,QByteArray& arrWavData);
    
    static bool WavBufferToAmrFile(const char* pArrWavData,  int wavDatalen, const char* szAmrFileName);
    static bool WavFileToAmrFile(const char* szWavFileName,  const char* szAmrFileName);
    static bool WavFileToAmrBuffer(const char* szWavFileName, QByteArray& arrAmrData);
};

