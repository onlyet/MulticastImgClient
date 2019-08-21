#pragma once

#include <QtWidgets/QWidget>
#include <QPixmap>

#include "ui_ImgClient.h"

class MCClient;

class ImgClient : public QWidget
{
    Q_OBJECT

public:
    ImgClient(QWidget *parent = Q_NULLPTR);
    ~ImgClient();

signals:
    void bind(const QString& groupAddress, const unsigned short& port);

public slots:
    void start();
    void imgReceived(const QPixmap& pixmap);

private:
    Ui::ImgClientUi     ui;
    MCClient*           m_imgClient;
    QThread*            m_imgThread;
};
