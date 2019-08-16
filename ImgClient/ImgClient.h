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

signals:
    void bind(const QString& groupAddress, const unsigned short& port);

    private slots:
    void start();
    void imgReceived(const QPixmap& pixmap);

private:
    Ui::ImgClientClass  ui;
    MCClient*           m_imgClient;
};
