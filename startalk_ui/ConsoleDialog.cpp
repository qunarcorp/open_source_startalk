#include "ConsoleDialog.h"
#include "ui_ConsoleDialog.h"
#include "LanguageHelper.h"
#include <LogWriter.h>
#include <QtXml>
#include <QDesktopWidget>

static QString s_colorHexSent("#02aa3f");
static QString s_colorHexReceived("#aa0000");

ConsoleDialog::ConsoleDialog(QWidget *parent)
    : QDialog(parent),ui(new Ui::ConsoleDialog),mLogWriter(new LogWriter)
{
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = WindowMinMaxButtonsHint | FramelessWindowHint | WindowStaysOnTopHint;
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    ui->setupUi(this);

    ui->textLabel->setText(
        QString("<html><body><p><span style=\"color:%1\">%3</span><span> | </span><span style=\"color:%2\">%4</span></p></body></html>").arg(s_colorHexSent).arg(s_colorHexReceived).arg(T_("Console_TextSend")).arg(T_("Console_TextRecv")));

    ui->clear->setText(T_("Console_Clear"));
    ui->hidedialog->setText(T_("Console_Hide"));


    connect(mLogWriter, &LogWriter::sgDebug, this, &ConsoleDialog::onDebug);
    connect(mLogWriter, &LogWriter::sgError, this, &ConsoleDialog::onError);
    connect(mLogWriter, &LogWriter::sgInfo, this, &ConsoleDialog::onInfo);
    connect(mLogWriter, &LogWriter::sgWarn, this, &ConsoleDialog::onWarn);

    connect(mLogWriter, &LogWriter::sgXmpp, this, &ConsoleDialog::onXmpp);

    Log::registerWriter(mLogWriter);

    connect(ui->clear, &QPushButton::clicked, this, &ConsoleDialog::onClear);
    connect(ui->hidedialog, &QPushButton::clicked, this, &ConsoleDialog::onHide);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect deskRect = desktopWidget->availableGeometry();
    QRect screenRect = desktopWidget->screenGeometry();

    move(deskRect.width() - this->width(), deskRect.height() - this->height());
}

ConsoleDialog::~ConsoleDialog()
{
    delete ui;
    ui = NULL;
}

void ConsoleDialog::onClear()
{
    ui->allLogger->clear();
    ui->logLogger->clear();
    ui->xmppLogger->clear();
}

void ConsoleDialog::onHide()
{
    this->hide();
}


void ConsoleDialog::onDebug( const QString& val )
{
    ui->logLogger->append(val);
}

void ConsoleDialog::onError( const QString& val )
{
    ui->logLogger->append(val);
}

void ConsoleDialog::onInfo( const QString& val )
{
    ui->logLogger->append(val);
}

void ConsoleDialog::onWarn( const QString& val )
{
    ui->logLogger->append(val);
}

void ConsoleDialog::onXmpp( QXmppLogger::MessageType type, const QString& val )
{
    QColor color;
    switch(type){
    case QXmppLogger::ReceivedMessage:
        color = QColor(s_colorHexReceived);
        break;

    case QXmppLogger::SentMessage:
        color = QColor(s_colorHexSent);
        break;
    default:
        break;
    }
    QDomDocument doc;

    // Indent XML string
    bool isXml = doc.setContent(val);
    QString formattedText;
    QTextStream stream(&formattedText);
    doc.save(stream, 2);
    if(!isXml)
        return;

    ui->xmppLogger->setTextColor(color);
    ui->xmppLogger->append(formattedText);

    ui->allLogger->append(val);
}