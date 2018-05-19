/********************************************************************************
** Form generated from reading UI file 'editregion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITREGION_H
#define UI_EDITREGION_H

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

class Ui_EditRegion
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
    QLabel *label_X1;
    QLabel *label_X2;
    QLabel *label_Y;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_X1;
    QLineEdit *lineEdit_X2;
    QLineEdit *lineEdit_Y;
    QPushButton *edit;

    void setupUi(QDialog *EditRegion)
    {
        if (EditRegion->objectName().isEmpty())
            EditRegion->setObjectName(QStringLiteral("EditRegion"));
        EditRegion->resize(385, 286);
        gridLayout_3 = new QGridLayout(EditRegion);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame = new QFrame(EditRegion);
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

        frame_2 = new QFrame(EditRegion);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_X1 = new QLabel(frame_2);
        label_X1->setObjectName(QStringLiteral("label_X1"));
        label_X1->setMinimumSize(QSize(87, 25));
        label_X1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_X1);

        label_X2 = new QLabel(frame_2);
        label_X2->setObjectName(QStringLiteral("label_X2"));
        label_X2->setMinimumSize(QSize(87, 25));
        label_X2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_X2);

        label_Y = new QLabel(frame_2);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        label_Y->setMinimumSize(QSize(87, 25));
        label_Y->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Y);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_X1 = new QLineEdit(frame_2);
        lineEdit_X1->setObjectName(QStringLiteral("lineEdit_X1"));
        lineEdit_X1->setMinimumSize(QSize(142, 25));
        lineEdit_X1->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_X1);

        lineEdit_X2 = new QLineEdit(frame_2);
        lineEdit_X2->setObjectName(QStringLiteral("lineEdit_X2"));
        lineEdit_X2->setMinimumSize(QSize(142, 25));
        lineEdit_X2->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_X2);

        lineEdit_Y = new QLineEdit(frame_2);
        lineEdit_Y->setObjectName(QStringLiteral("lineEdit_Y"));
        lineEdit_Y->setMinimumSize(QSize(142, 25));
        lineEdit_Y->setMaxLength(15);

        verticalLayout_2->addWidget(lineEdit_Y);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_2);

        edit = new QPushButton(EditRegion);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setMinimumSize(QSize(241, 25));

        verticalLayout_3->addWidget(edit);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_X1->setBuddy(lineEdit_X1);
        label_X2->setBuddy(lineEdit_X2);
        label_Y->setBuddy(lineEdit_Y);
#endif // QT_NO_SHORTCUT

        retranslateUi(EditRegion);

        QMetaObject::connectSlotsByName(EditRegion);
    } // setupUi

    void retranslateUi(QDialog *EditRegion)
    {
        EditRegion->setWindowTitle(QApplication::translate("EditRegion", "Dialog", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditRegion", "<html><head/><body><p align=\"center\">X: Mesafe , Y:Derinlik</p></body></html>", Q_NULLPTR));
        label_X1->setText(QApplication::translate("EditRegion", "X1:", Q_NULLPTR));
        label_X2->setText(QApplication::translate("EditRegion", "X2:", Q_NULLPTR));
        label_Y->setText(QApplication::translate("EditRegion", "  Y:", Q_NULLPTR));
        edit->setText(QApplication::translate("EditRegion", "D\303\274zenle", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditRegion: public Ui_EditRegion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITREGION_H
