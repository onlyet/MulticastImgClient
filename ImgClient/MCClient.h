#pragma once
#include <QObject>
#include <QHostAddress>
#include <QPixmap>

class QUdpSocket;

class MCClient : public QObject
{
    Q_OBJECT

public:
    explicit MCClient(QObject* parent = Q_NULLPTR);
    ~MCClient();

signals:
    void error(const QString& error);
    void datagramReceived(const QByteArray& data);
    void imgReceived(const QPixmap& pixmap);


private slots:
    void bind(const QString& groupAddress, const unsigned short& port);
    void recvDatagram();
    void sendDatagram(const QByteArray& data);

private:
    QUdpSocket*     m_socket;
    QHostAddress    m_hostAddress;
    unsigned short  m_port;
    char*           m_recvBuf;
    char*           m_imgBuf;
    int             m_imgLen;           //当前图片长度
    int             m_receivedLen;      //当前图片已接收长度
};