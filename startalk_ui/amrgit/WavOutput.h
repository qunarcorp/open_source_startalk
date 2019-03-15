#pragma once
#include <QAudioOutput>
#include <QByteArray>
#include <QComboBox>
#include <QIODevice>
class WavOutput : public QIODevice
{
    Q_OBJECT
public:
    WavOutput(QByteArray*);
    ~WavOutput(void);

    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
    qint64 bytesAvailable() const;
signals:
    void sgFinish();
private:
    QByteArray* m_pBuffer;
    qint64 m_pos;
    qint64 m_bufSize;
};

