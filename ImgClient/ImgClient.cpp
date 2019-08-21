#include "ImgClient.h"
#include "MCClient.h"
#include <QThread>
#include <QDesktopWidget>

ImgClient::ImgClient(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(QApplication::desktop()->availableGeometry().size());

    ui.setupUi(this);
    
    //ui.label->setFixedSize(size());
}

ImgClient::~ImgClient()
{
    m_imgThread->quit();
    m_imgThread->wait();
}

void ImgClient::start()
{
    m_imgThread = new QThread(this);
    m_imgClient = new MCClient(this);
    m_imgClient->moveToThread(m_imgThread);
    //connect(this, &ImgClient::bind, m_imgClient, &MCClient::bind);
    connect(m_imgThread, SIGNAL(finished()), m_imgClient, SLOT(deleteLater()));
    connect(this, SIGNAL(bind(const QString&, const unsigned short&)), m_imgClient, SLOT(bind(const QString&, const unsigned short&)));
    connect(m_imgClient, SIGNAL(imgReceived(const QPixmap&)), this, SLOT(imgReceived(const QPixmap&)));

    m_imgThread->start();

    emit bind("224.55.55.55", 7777);
}

void ImgClient::imgReceived(const QPixmap& pixmap)
{
    //pixmap.save("D:/1.jpg", "JPG");
    ui.label->setPixmap(pixmap);
}
