#include "ImgClient.h"
#include "MCClient.h"

ImgClient::ImgClient(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

void ImgClient::start()
{
    m_imgClient = new MCClient(this);
    //connect(this, &ImgClient::bind, m_imgClient, &MCClient::bind);
    connect(this, SIGNAL(bind(const QString&, const unsigned short&)), m_imgClient, SLOT(bind(const QString&, const unsigned short&)));

    emit bind("224.55.55.55", 7777);
}

void ImgClient::imgReceived(const QPixmap& pixmap)
{

}
