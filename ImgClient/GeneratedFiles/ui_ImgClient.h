/********************************************************************************
** Form generated from reading UI file 'ImgClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGCLIENT_H
#define UI_IMGCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgClientClass
{
public:

    void setupUi(QWidget *ImgClientClass)
    {
        if (ImgClientClass->objectName().isEmpty())
            ImgClientClass->setObjectName(QStringLiteral("ImgClientClass"));
        ImgClientClass->resize(600, 400);

        retranslateUi(ImgClientClass);

        QMetaObject::connectSlotsByName(ImgClientClass);
    } // setupUi

    void retranslateUi(QWidget *ImgClientClass)
    {
        ImgClientClass->setWindowTitle(QApplication::translate("ImgClientClass", "ImgClient", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImgClientClass: public Ui_ImgClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGCLIENT_H
