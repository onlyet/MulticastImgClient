#include "MCClient.h"
#include <QUdpSocket>
#include <QPixmap>


#define MC_RECV_BUF_LEN 4000
#define MC_MAX_BUF_LEN 5*1024*1024

MCClient::MCClient(QObject* parent)
{
    m_recvBuf = new char[MC_RECV_BUF_LEN];
    m_imgBuf = new char[MC_MAX_BUF_LEN];
}


MCClient::~MCClient()
{
    delete m_recvBuf;
    delete m_imgBuf;
}

void MCClient::bind(const QString& groupAddress, const unsigned short& port)
{
    m_socket = new QUdpSocket;
    if (!m_socket->bind(QHostAddress::AnyIPv4, port))
    {
        emit error("udp socket bind error");
        return;
    }

    m_hostAddress.setAddress(groupAddress);
    if (!m_socket->joinMulticastGroup(m_hostAddress))
    {
        emit error("joinMulticastGroup error");
        return;
    }

    connect(m_socket, &QUdpSocket::readyRead, this, &MCClient::recvDatagram);
}


void MCClient::recvDatagram()
{
    if (!m_socket->hasPendingDatagrams())
        return;

    int len = m_socket->readDatagram(m_recvBuf, MC_RECV_BUF_LEN);
    if (len < 0)
    {
        emit error("readDatagram error");
        return;
    }

    m_recvBuf[len] = 0;
    QByteArray ba(m_recvBuf, len);

    if (ba.contains("newImage:"))
    {
        int imgLen = atoi(m_recvBuf + ba.indexOf("newImage:") + 9);
        qDebug() << imgLen;
        m_receivedLen = 0;
        return;
    }

    memcpy_s(m_imgBuf + m_receivedLen, len, m_recvBuf, len);
    m_receivedLen += len;
    if (m_receivedLen >= m_imgLen)
    {
        QPixmap pixmap;
        pixmap.loadFromData(reinterpret_cast<const uchar *>(m_imgBuf), m_imgLen);
        emit imgReceived(pixmap);
    }

}

void MCClient::sendDatagram(const QByteArray& data)
{
}

