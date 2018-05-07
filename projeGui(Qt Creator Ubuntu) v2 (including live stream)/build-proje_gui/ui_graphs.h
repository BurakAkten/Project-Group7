/********************************************************************************
** Form generated from reading UI file 'graphs.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHS_H
#define UI_GRAPHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graphs
{
public:
    QGridLayout *gridLayout_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Graphs)
    {
        if (Graphs->objectName().isEmpty())
            Graphs->setObjectName(QStringLiteral("Graphs"));
        Graphs->resize(674, 430);
        Graphs->setMinimumSize(QSize(396, 232));
        gridLayout_2 = new QGridLayout(Graphs);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        customPlot = new QCustomPlot(Graphs);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        gridLayout_2->addWidget(customPlot, 0, 0, 1, 1);


        retranslateUi(Graphs);

        QMetaObject::connectSlotsByName(Graphs);
    } // setupUi

    void retranslateUi(QDialog *Graphs)
    {
        Graphs->setWindowTitle(QApplication::translate("Graphs", "B\303\266lge Grafi\304\237i", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Graphs: public Ui_Graphs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHS_H
