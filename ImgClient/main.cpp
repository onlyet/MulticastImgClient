#include "ImgClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgClient w;
    w.show();
    return a.exec();
}
