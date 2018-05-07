/********************************************************************************
** Form generated from reading UI file 'bolgeekle.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_Name;
    QLabel *label_X;
    QLabel *label_Y;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_X;
    QLineEdit *lineEdit_Y;
    QPushButton *ekle;

    void setupUi(QDialog *BolgeEkle)
    {
        if (BolgeEkle->objectName().isEmpty())
            BolgeEkle->setObjectName(QStringLiteral("BolgeEkle"));
        BolgeEkle->resize(396, 232);
        BolgeEkle->setMinimumSize(QSize(396, 232));
        gridLayout_3 = new QGridLayout(BolgeEkle);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame = new QFrame(BolgeEkle);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(241, 37));
        frame->setMaximumSize(QSize(16777215, 40));
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

        frame_2 = new QFrame(BolgeEkle);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Name = new QLabel(frame_2);
        label_Name->setObjectName(QStringLiteral("label_Name"));
        label_Name->setMinimumSize(QSize(87, 25));
        label_Name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Name);

        label_X = new QLabel(frame_2);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setMinimumSize(QSize(87, 25));
        label_X->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_X);

        label_Y = new QLabel(frame_2);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        label_Y->setMinimumSize(QSize(87, 25));
        label_Y->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Y);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_Name = new QLineEdit(frame_2);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));
        lineEdit_Name->setMinimumSize(QSize(142, 25));
        lineEdit_Name->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_Name);

        lineEdit_X = new QLineEdit(frame_2);
        lineEdit_X->setObjectName(QStringLiteral("lineEdit_X"));
        lineEdit_X->setMinimumSize(QSize(142, 25));
        lineEdit_X->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_X);

        lineEdit_Y = new QLineEdit(frame_2);
        lineEdit_Y->setObjectName(QStringLiteral("lineEdit_Y"));
        lineEdit_Y->setMinimumSize(QSize(142, 25));
        lineEdit_Y->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_Y);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_2);

        ekle = new QPushButton(BolgeEkle);
        ekle->setObjectName(QStringLiteral("ekle"));
        ekle->setMinimumSize(QSize(241, 25));

        verticalLayout_3->addWidget(ekle);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_Name->setBuddy(lineEdit_Name);
        label_X->setBuddy(lineEdit_X);
        label_Y->setBuddy(lineEdit_Y);
#endif // QT_NO_SHORTCUT

        retranslateUi(BolgeEkle);

        QMetaObject::connectSlotsByName(BolgeEkle);
    } // setupUi

    void retranslateUi(QDialog *BolgeEkle)
    {
        BolgeEkle->setWindowTitle(QApplication::translate("BolgeEkle", "B\303\266lge Ekle", Q_NULLPTR));
        label_5->setText(QApplication::translate("BolgeEkle", "<html><head/><body><p align=\"center\">X: Mesafe , Y:Derinlik</p></body></html>", Q_NULLPTR));
        label_Name->setText(QApplication::translate("BolgeEkle", "B\303\266lge Ad\304\261:", Q_NULLPTR));
        label_X->setText(QApplication::translate("BolgeEkle", "X:", Q_NULLPTR));
        label_Y->setText(QApplication::translate("BolgeEkle", "Y:", Q_NULLPTR));
        ekle->setText(QApplication::translate("BolgeEkle", "Ekle", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BolgeEkle: public Ui_BolgeEkle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOLGEEKLE_H
