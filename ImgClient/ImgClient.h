#pragma once

#include <QtWidgets/QWidget>
#include "ui_ImgClient.h"

class ImgClient : public QWidget
{
    Q_OBJECT

public:
    ImgClient(QWidget *parent = Q_NULLPTR);

private:
    Ui::ImgClientClass ui;
};
