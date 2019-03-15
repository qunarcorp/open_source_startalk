#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H
#include <QDebug>
#ifdef _WINDOWS
#ifdef _CODE_RUN
#define cDebug      qDebug
#define cWarning    qWarning
#define cCritical   qCritical
#define cFatal      qFatal
#endif // _CODE_RUN
#else
#  undef cDebug
#  undef cWarning
#  undef cCritical
#  undef cFatal
#define cDebug      QT_NO_QDEBUG_MACRO
#define cWarning    QT_NO_QDEBUG_MACRO
#define cCritical   QT_NO_QDEBUG_MACRO
#define cFatal      QT_NO_QDEBUG_MACRO
#endif // 


#endif // CONSOLEOUTPUT_H
