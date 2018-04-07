/********************************************************************************
** Form generated from reading UI file 'bolgeekle.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOLGEEKLE_H
#define UI_BOLGEEKLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BolgeEkle
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;

    void setupUi(QDialog *BolgeEkle)
    {
        if (BolgeEkle->objectName().isEmpty())
            BolgeEkle->setObjectName(QStringLiteral("BolgeEkle"));
        BolgeEkle->resize(396, 232);
        BolgeEkle->setMinimumSize(QSize(396, 232));
        gridLayout_2 = new QGridLayout(BolgeEkle);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame = new QFrame(BolgeEkle);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(241, 37));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 17));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(BolgeEkle);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(87, 25));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(BolgeEkle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(87, 25));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(BolgeEkle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(87, 25));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(BolgeEkle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(87, 25));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit = new QLineEdit(BolgeEkle);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(142, 25));
        lineEdit->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(BolgeEkle);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(142, 25));
        lineEdit_2->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(BolgeEkle);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(142, 25));
        lineEdit_3->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(BolgeEkle);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(142, 25));
        lineEdit_4->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_4);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(BolgeEkle);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(241, 25));

        verticalLayout_3->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit_2);
        label_3->setBuddy(lineEdit_3);
        label_4->setBuddy(lineEdit_4);
#endif // QT_NO_SHORTCUT

        retranslateUi(BolgeEkle);

        QMetaObject::connectSlotsByName(BolgeEkle);
    } // setupUi

    void retranslateUi(QDialog *BolgeEkle)
    {
        BolgeEkle->setWindowTitle(QApplication::translate("BolgeEkle", "Dialog", 0));
        label_5->setText(QApplication::translate("BolgeEkle", "<html><head/><body><p align=\"center\">Kordinatlar\304\261 Gir</p></body></html>", 0));
        label->setText(QApplication::translate("BolgeEkle", "1. Koordinat:", 0));
        label_2->setText(QApplication::translate("BolgeEkle", "2. Koordinat:", 0));
        label_3->setText(QApplication::translate("BolgeEkle", "3. Koordinat:", 0));
        label_4->setText(QApplication::translate("BolgeEkle", "4. Koordinat:", 0));
        pushButton->setText(QApplication::translate("BolgeEkle", "Tamam", 0));
    } // retranslateUi

};

namespace Ui {
    class BolgeEkle: public Ui_BolgeEkle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOLGEEKLE_H
