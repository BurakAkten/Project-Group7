/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_4;
    QFrame *mainLabel;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *gtu;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QFrame *videoPart;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QFrame *videoFrame;
    QGridLayout *gridLayout_6;
    QLabel *video;
    QFrame *frame_6;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *play;
    QPushButton *stop;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *fullScreen;
    QFrame *managePart;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *detectedImage;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QPushButton *baslat;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *bolgeGrafigi;
    QPushButton *openDateGraph;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QPushButton *ekle;
    QPushButton *cikar;
    QVBoxLayout *_2;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *dikkat1;
    QLabel *label_2;
    QLabel *dikkat2;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QStringLiteral("SecondWindow"));
        SecondWindow->resize(1014, 741);
        SecondWindow->setMinimumSize(QSize(813, 0));
        centralwidget = new QWidget(SecondWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        mainLabel = new QFrame(centralwidget);
        mainLabel->setObjectName(QStringLiteral("mainLabel"));
        mainLabel->setFrameShape(QFrame::StyledPanel);
        mainLabel->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(mainLabel);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        gtu = new QLabel(mainLabel);
        gtu->setObjectName(QStringLiteral("gtu"));
        gtu->setMinimumSize(QSize(131, 81));

        horizontalLayout_4->addWidget(gtu);

        label = new QLabel(mainLabel);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(500, 0));
        label->setMaximumSize(QSize(741, 16777215));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        verticalLayout_4->addWidget(mainLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        videoPart = new QFrame(centralwidget);
        videoPart->setObjectName(QStringLiteral("videoPart"));
        videoPart->setMinimumSize(QSize(600, 311));
        videoPart->setMaximumSize(QSize(16777215, 16777215));
        videoPart->setFrameShape(QFrame::StyledPanel);
        videoPart->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(videoPart);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        videoFrame = new QFrame(videoPart);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setMinimumSize(QSize(491, 261));
        videoFrame->setFrameShape(QFrame::StyledPanel);
        videoFrame->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(videoFrame);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        video = new QLabel(videoFrame);
        video->setObjectName(QStringLiteral("video"));
        video->setMinimumSize(QSize(491, 261));

        gridLayout_6->addWidget(video, 0, 1, 1, 1);


        verticalLayout_3->addWidget(videoFrame);

        frame_6 = new QFrame(videoPart);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setMinimumSize(QSize(0, 41));
        frame_6->setMaximumSize(QSize(16777215, 41));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        play = new QPushButton(frame_6);
        play->setObjectName(QStringLiteral("play"));
        play->setMinimumSize(QSize(48, 19));
        play->setMaximumSize(QSize(48, 19));

        horizontalLayout_3->addWidget(play);

        stop = new QPushButton(frame_6);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setMinimumSize(QSize(48, 19));
        stop->setMaximumSize(QSize(48, 19));

        horizontalLayout_3->addWidget(stop);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        fullScreen = new QPushButton(frame_6);
        fullScreen->setObjectName(QStringLiteral("fullScreen"));
        fullScreen->setMinimumSize(QSize(48, 19));
        fullScreen->setMaximumSize(QSize(48, 19));

        horizontalLayout_3->addWidget(fullScreen);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_6);


        gridLayout_5->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(videoPart);

        managePart = new QFrame(centralwidget);
        managePart->setObjectName(QStringLiteral("managePart"));
        managePart->setMinimumSize(QSize(386, 352));
        managePart->setMaximumSize(QSize(500, 16777215));
        managePart->setFrameShape(QFrame::StyledPanel);
        managePart->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(managePart);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(managePart);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 17));

        verticalLayout->addWidget(label_3);

        detectedImage = new QLabel(managePart);
        detectedImage->setObjectName(QStringLiteral("detectedImage"));

        verticalLayout->addWidget(detectedImage);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(managePart);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(250, 200));
        listWidget->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_2->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        baslat = new QPushButton(managePart);
        baslat->setObjectName(QStringLiteral("baslat"));

        verticalLayout_2->addWidget(baslat);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        bolgeGrafigi = new QPushButton(managePart);
        bolgeGrafigi->setObjectName(QStringLiteral("bolgeGrafigi"));

        horizontalLayout_6->addWidget(bolgeGrafigi);

        openDateGraph = new QPushButton(managePart);
        openDateGraph->setObjectName(QStringLiteral("openDateGraph"));

        horizontalLayout_6->addWidget(openDateGraph);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        comboBox = new QComboBox(managePart);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        ekle = new QPushButton(managePart);
        ekle->setObjectName(QStringLiteral("ekle"));

        horizontalLayout_5->addWidget(ekle);

        cikar = new QPushButton(managePart);
        cikar->setObjectName(QStringLiteral("cikar"));

        horizontalLayout_5->addWidget(cikar);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(managePart);


        verticalLayout_4->addLayout(horizontalLayout_7);

        _2 = new QVBoxLayout();
        _2->setObjectName(QStringLiteral("_2"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dikkat1 = new QLabel(frame_4);
        dikkat1->setObjectName(QStringLiteral("dikkat1"));
        dikkat1->setMinimumSize(QSize(0, 31));

        horizontalLayout->addWidget(dikkat1);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 31));

        horizontalLayout->addWidget(label_2);

        dikkat2 = new QLabel(frame_4);
        dikkat2->setObjectName(QStringLiteral("dikkat2"));
        dikkat2->setMinimumSize(QSize(0, 31));

        horizontalLayout->addWidget(dikkat2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        _2->addWidget(frame_4);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(791, 0));

        _2->addWidget(tableWidget);


        verticalLayout_4->addLayout(_2);


        gridLayout_7->addLayout(verticalLayout_4, 0, 0, 1, 1);

        SecondWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecondWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1014, 22));
        SecondWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecondWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SecondWindow->setStatusBar(statusbar);

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "\304\260SG CABLE-CAM", Q_NULLPTR));
        gtu->setText(QString());
        label->setText(QApplication::translate("SecondWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\304\260SG CABLE-CAM</span></p><p align=\"center\">B\304\260L396 - Bilgisayar M\303\274hendisli\304\237i Proje Dersi Grup 7</p></body></html>", Q_NULLPTR));
        video->setText(QString());
        play->setText(QString());
        stop->setText(QString());
        fullScreen->setText(QString());
        label_3->setText(QApplication::translate("SecondWindow", "<html><head/><body><p align=\"center\">B\303\266lgeler</p></body></html>", Q_NULLPTR));
        detectedImage->setText(QApplication::translate("SecondWindow", "Detected Image", Q_NULLPTR));
        baslat->setText(QApplication::translate("SecondWindow", "Ba\305\237lat", Q_NULLPTR));
        bolgeGrafigi->setText(QApplication::translate("SecondWindow", "B\303\266lge Grafi\304\237i", Q_NULLPTR));
        openDateGraph->setText(QApplication::translate("SecondWindow", "Tarih Grafi\304\237i", Q_NULLPTR));
        comboBox->setCurrentText(QString());
        ekle->setText(QApplication::translate("SecondWindow", "Ekle", Q_NULLPTR));
        cikar->setText(QApplication::translate("SecondWindow", "\303\207\304\261kar", Q_NULLPTR));
        dikkat1->setText(QString());
        label_2->setText(QApplication::translate("SecondWindow", "<html><head/><body><p align=\"center\">TESP\304\260T L\304\260STES\304\260</p></body></html>", Q_NULLPTR));
        dikkat2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H