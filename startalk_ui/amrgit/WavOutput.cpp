#include "WavOutput.h"
#include <QFile>

WavOutput::WavOutput(QByteArray*  pData)
{
    m_pBuffer = pData;
    m_pos = 0;    
    m_bufSize = m_pBuffer->size();
    open(QIODevice::ReadOnly);
}


WavOutput::~WavOutput(void)
{
}

qint64 WavOutput::readData(char *data, qint64 maxlen)
{
    qint64 total = 0;
    while (maxlen - total > 0) {
        const qint64 chunk = qMin((m_pBuffer->size() - m_pos), maxlen - total);
        if (chunk<=0)
        {
            emit sgFinish();
            return -1;
        }
        memset(data,0,maxlen);
        memcpy(data + total, m_pBuffer->constData() + m_pos, chunk);
        qint64 size = m_pBuffer->size();
        m_pos = (m_pos + chunk);
        total += chunk;
    }
   
    return total;
}
qint64 WavOutput::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);
    return 0;
}
qint64 WavOutput::bytesAvailable() const
{
    return m_pBuffer->size() + QIODevice::bytesAvailable();
}