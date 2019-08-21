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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgClientUi
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *ImgClientUi)
    {
        if (ImgClientUi->objectName().isEmpty())
            ImgClientUi->setObjectName(QStringLiteral("ImgClientUi"));
        ImgClientUi->resize(600, 400);
        horizontalLayout = new QHBoxLayout(ImgClientUi);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ImgClientUi);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        retranslateUi(ImgClientUi);

        QMetaObject::connectSlotsByName(ImgClientUi);
    } // setupUi

    void retranslateUi(QWidget *ImgClientUi)
    {
        ImgClientUi->setWindowTitle(QApplication::translate("ImgClientUi", "ImgClient", Q_NULLPTR));
        label->setText(QApplication::translate("ImgClientUi", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImgClientUi: public Ui_ImgClientUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGCLIENT_H
